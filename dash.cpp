#include "dash.h"
/**
Class that runs on start up.  Main method makes a new object of the main dashboard form.  It also starts a thread
to listen for HL7's from our mock HIE, a TCP listener.  Starts up the form on the main thread.
Jason Fiduk
*/
int main(array<System::String^> ^args)
{
	//array holds all the general starting off test info. General form of a test array is as follows:
	//{test name, default time range, current time range(manipulated later)} In the future have Test class that holds these values, then have array of Test objects
	array<Object^,2>^ TestArray = gcnew array<Object^,2>(5,2){{"Cat Scan",TimeSpan(7,0,0,0)},{"ER Visit",TimeSpan(7,0,0,0)},{"Hospitalization",TimeSpan(31,0,0,0)},{"Discharge", TimeSpan(7,0,0,0)}};
	GUIClass^ gui= gcnew GUIClass(TestArray);
	Thread^ oThread = gcnew Thread( gcnew ParameterizedThreadStart(&startConnection) );
	oThread->Start(gui);
	 Application::Run(gui);

}
/**
The parse method takes the HL7 data we recieved from the HIE and parses it for values.
Fills in an array as such:
{private name, public name, DOB, arrival time, test1, test2, test3, test4}
if another test is added in the future, it must be parsed here in the ZIX section.
Tara Crittenden and Jason Fiduk
*/
std::vector<std::string> parseData(string data)
{
	std::vector<std::string> patientData(8);
	smatch match;
		if(regex_search(data,match,regex("EVN"))){  //Find our EVN section of the HL7 to get arrival time
			int beg = match.position(0), last;

			for(int m = 0; m < 2; m++) { //go to second | to get start of arrival time
                 beg = data.find("|", beg+1); 
            }
			last = data.find("|", beg+1); //get the next | character
                string dob = data.substr(beg+1, last-beg-1);
				patientData[3] = data.substr(beg+1, last-beg-1);

		}
		//Find our PID section of the HL7 to get name and DOB. //Name is split up into public and private
        if(regex_search(data,match,regex("PID"))) {
           
			int beg = match.position(0), last;
            string name = "";
            string dob = "";
            for(int m = 0; m < 5; m++) { //Go five | in to get to name field
                 beg = data.find("|", beg+1); //get the first | character
               
            }
			 cout << "\n";
                last = data.find("|", beg+1); //get the next | character

                name = data.substr(beg+1, last-beg-1);
               int last_name= name.find("^");
			   int first_name = name.find("^",last_name+1);
				string newName = name.substr(0,last_name) + ", " + name.substr(last_name+1,first_name-last_name-1); //private
				string starredName = newName.substr(0,3) + "*, " + newName.substr(newName.find(" ")+1,3) +"*"; //public
            patientData[0] = starredName;
			patientData[1] = newName;
				beg = last;
            for(int m = 0; m < 1; m++) { //go another | over to get the start of the DOB
                 beg = data.find("|", beg+1);
                
            }
			last = data.find("|", beg+1); //get the next | character
                dob = data.substr(beg+1, last-beg-1);
                beg = last;
            patientData[2] = dob;
        }
		//This is where all the test dates are looked for, in the ZIX section
	if(regex_search(data, match,regex("ZIX"))){ 
			int beg =match.position(0), last;
		do{
			beg = data.find("|", beg+1);
			last = data.find(" ", beg);
			string test =data.substr(beg+1,last-beg-1);
			string date = data.substr(last+1,data.find("]",last)-last-1);
			if(test.compare("[CT")==0){ //Cat scan
			patientData[4] = date;
			}
			else if(test.compare("[ED")==0){ //ER
			patientData[5] = date;
			}
			else if(test.compare("[HSP")==0){//Hospitalization
			patientData[6] = date;
			}
			else if(test.compare("[DCS")==0){//Hospital discharge
			patientData[7] = date;
			}
		}while(beg != data.npos);
	}
	return patientData;
}
/**
Sets up a connection with our fake HIE currently.  Each time it recieves one on the stream it sends it to the parser,
and then uses a delegate to add the parsed array to the dashboard
Jason Fiduk
*/
static void startConnection(Object^ gui){
	array<Byte>^data =gcnew array<Byte>(2048);
	 TcpClient^ client = gcnew TcpClient("127.0.0.1", 13000);
	   NetworkStream^ stream = client->GetStream();
	   Int32 bytes;
		while( (bytes = stream->Read( data, 0, data->Length ) )>0)
		{
      String^ responseData = System::Text::Encoding::ASCII->GetString( data, 0, bytes );
	 array <String^>^ patientsData= gcnew array<String^>(8);
	 std::vector<std::string> unManagedData=parseData(marshal_as<std::string>(responseData));
	 for( int i =0; i< 8; i++){
		 patientsData[i] = gcnew String(unManagedData[i].c_str());
	 }
	 safe_cast<GUIClass^>(gui)->Invoke( safe_cast<GUIClass^>(gui)->myDelegate,safe_cast<Object^>(patientsData)); //delegate
		}

}

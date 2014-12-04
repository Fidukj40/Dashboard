#using <System.dll>
using namespace System;
using namespace System::IO;
using namespace System::Net;
using namespace System::Net::Sockets;
using namespace System::Text;
using namespace System::Threading;
/**
modified version of .NET example for TCPListener.
Sends out multiple HL7's to whoever connects.
Set to localhost, and closes connection once done for easy startup.
*/
void main()
{
   try
   {

      // Set the TcpListener on port 13000.
      Int32 port = 13000;
      IPAddress^ localAddr = IPAddress::Parse( "127.0.0.1" );

      TcpListener^ server = gcnew TcpListener( localAddr,port );

      // Start listening for client requests.
      server->Start();

      // Buffer for reading data 
      array<Byte>^bytes = gcnew array<Byte>(256);
      String^ data = nullptr;

      // Enter the listening loop. 
      while ( true )
      {
         Console::Write( "Waiting for a connection... " );

         // Perform a blocking call to accept requests. 
         // You could also user server.AcceptSocket() here.
         TcpClient^ client = server->AcceptTcpClient();
         Console::WriteLine( "Connected!" );
         data = nullptr;

         // Get a stream Object* for reading and writing
         NetworkStream^ stream = client->GetStream();
		    array<Byte>^ myWriteBuffer = Encoding::ASCII->GetBytes(
     "MSH|^~\&|IDX|HPA|CLOVERLEAF|HQ|201411130200||ADT^A03|63504_5_DA|T|2.3||||||ASCII|EVN|A03|201411130211||DA|$$SIU|PID|1||66661229||TESTING^PAV9EDONE^^^^||19520619|M||3|29 NEWTON DRIVE^^MOUNT LAUREL^NJ^08054|102|||000|M||0666612294316|999661229|||NON||||||||N|PD1||||212473^PHYSICIAN^NO PCP^^^^|||||||||NK1|1||||||NOK||||||||||||||||||||||||||||||||NK1|2||||||EC||||||||||||||||||||||||||||||||PV1|1|O|RADC|3|12663657||101335^GRANA^GENEROSA^^^^MD|101335^GRANA^GENEROSA^^^^MD||ONC||||1||||V|0666612294316|^S||||||||||||||||H^DIS HOME-ROUTINE|||RCC|||||201411122150|201411122359|||||0666612294316||||||||101335^GRANA^GENEROSA^^^^MD|PV2|||testing for TESS||||3|201411122150||||||||||1^*NA|GT1|1|66661229|TESTING^PAV9EDONE^^^^||29 NEWTON DRIVE^^MOUNT LAUREL^NJ^08054|||19520619|M||S|999661229|||||||||ACC||||ZPI|0324||||||NOEMAIL||||||||||||||SYS$$|||66661229|N|||62||IN1|1|^S||||||||||||||TESTING^PAV9EDONE^^^^||||||1|||||||||||||Z99|||||||||||||||||||||||||TEST||AUTO ASSIGNED SELF PAY||||IN2|1|||||||||||||||||IN3|1||ZPV|1|||||||||||||||||||212473^PHYSICIAN^NO PCP^^^^||||||||||3|1||||||||ONC|||||*NA||||||3|00165|UNIV HEM ONC|00165|UNIV HEM ONC|2|101335|201411122150||301035|||||||||12663657||20141116|N|N||ZIX|[CT 201411130200]|[ED 201311130200]|[HSP 201211130200]|[DCS 201111130200]" );
   stream->Write( myWriteBuffer, 0, myWriteBuffer->Length );
		Thread::Sleep(10000);
		myWriteBuffer = Encoding::ASCII->GetBytes("MSH|^~\&|IDX|HPA|CLOVERLEAF|HQ|201411130200||ADT^A03|63504_1_DA|T|2.3||||||ASCII|EVN|A03|201411130211||DA|$$SIU|PID|1||03003868||CARTER^CALVIN^^^^||19650512|M|CARTER^CALVIN^L^^^|2|1044 COLLINS AVE^^CAMDEN^NJ^08104|103|(856)962-6175||000|S|MUS^MUSLIM|0030038684316|196-50-9396|||NON||||||||N|PD1||||299982^GITLER^STEVEN^F^^^DO|||||||||NK1|1|CARTER^MARY^^^^|T||(856)962-6175^(856)966-6171||NOK||||||||||||||||||||||||||||||||NK1|2|CARTER^MARY^^^^|T||(856)962-6175^(856)966-6170||EC||||||||||||||||||||||||||||||||PV1|1|O|UCAU||12663652||102187^PHYSICIAN^EMERGENCY^^^^MD|212476^SELF^REFERRED^^^^||ER||||||||-|0030038684316|012^D^X^M101||||||||||||||||H^DIS HOME-ROUTINE||||||||201411121308|201411122359|||||0030038684316||||||||102187^PHYSICIAN^EMERGENCY^^^^MD|PV2|||BURN ON LEFT LEG||||3|||||||||||1^*NA|GT1|1|03003868,04085897|CARTER^CALVIN^^^^||1044 COLLINS AVE^^CAMDEN^NJ^08104|(856)962-6175||19650512|M||S|196-50-9396||||COOPER RIVER WEST|517 FRANKLIN AVE^^CHERRY HILL^NJ^08002||||ACC|||ZPI|0408|1|AG000|-NO SPECIFIC INSTITUTION|N|20121219|NOEMAIL|||||||COOPER RIVER WEST^517 FRANKLIN AVE^^CHERRY HILL^NJ^08002||ANALIST|||||SYS$$|||06108478|N|||49|856-962-6175|IN1|1|012^D^X^M101|MEDICAID NJ|MEDICAID|UNISYS^PO BOX 4806^TRENTON^NJ^08650||(800)776-6334|||||20140204||||CARTER^CALVIN^L^^^|S|||||1|||||||||||||M101|257001899401||||||||||||||||||||||||TEST|CARTER,CALVIN L|MEDICAID NJ|20140330|||IN2|1|||||||||||||||||IN3|1||||||||20140204|IN1|2|026^O^B^B25|HORIZON/BS OF NJ HOST (II)|HORIZON HOST BNK|PO BOX 247^DEPT V^NEWARK^NJ^07101-0247||(877)237-1840|||||20130101||||CARTER^CALVIN^^^^|S|||||2|||||||||||||B25|1111111||||||||||||||||||||||||TEST|CARTER,CALVIN|BLUE CROSS/SHIELD OTHER||||IN2|2|||||||||||||||||IN3|2||||||||20130101|ZPV|1|N||||||||||||||||||299982^GITLER^STEVEN^F^^^DO|||||||||||||||||||ER|||||*NA|||||Y|3|||||2|102187|201411121308|||||||||||||20141116|N|Y||ZIX|[CT 201411130200]|[ED 201311130200]|[DCS 201111130200]");
		stream->Write( myWriteBuffer, 0, myWriteBuffer->Length );
		Thread::Sleep(5000);
		myWriteBuffer = Encoding::ASCII->GetBytes("MSH|^~\&|IDX|HPA|CLOVERLEAF|HQ|201411130200||ADT^A03|63504_3_DA|T|2.3||||||ASCII|EVN|A03|201411130200||DA|$$SIU|PID|1||66660001||TEST^GREG^^^^||19750515|M||9|3 EXECUTIVE CAMPUS^STE 310^CHERRY HILL^NJ^08002|103|(999)999-9999|(888)888-8888^7777|000|||0666600014320|111-22-3333|||NON||||||||N|PD1||||212473^PHYSICIAN^NO PCP^^^^||||||||EM|NK1|1||||||NOK||||||||||||||||||||||||||||||||NK1|2||||||EC||||||||||||||||||||||||||||||||PV1|1|O|RCMA||12663655||213821^BUTLER NP^LISA^^^^|212476^SELF^REFERRED^^^^||ER||||||||-|0666600014320|012^D^X^M101||||||||||||||||H^DIS HOME-ROUTINE||||||||201411121408|201411122359|||||0666600014320||||||||213821^BUTLER NP^LISA^^^^|PV2|||TEST||||3|||||||||||1^*NA|GT1|1|66660001|TEST^GREG^^^^||3 EXECUTIVE CAMPUS^STE 310^CHERRY HILL^NJ^08002|(999)999-9999|(555)555-5555|19750515|M||S|111-22-3333||||||(555)555-5555|||ACC||||ZPI|0408||||||KELEMEN-GREG@COOPERHEALTH.EDU||||||||(555)555-5555||||||SYS$$|||66660001|N|N||39|666-666-6666|IN1|1|012^D^X^M101|MEDICAID NJ|MEDICAID|UNISYS^PO BOX 4806^TRENTON^NJ^08650|||||||20131201||||TEST^GREG^^^^|S|||||1|||||||||||||M101|991599999999||||||||||||||||||||||||TEST|TEST,GREG|MEDICAID NJ||||IN2|1|||||||||||||||||IN3|1||||||||20131201|IN1|2|015^B^P^M82|||PO BOX 890420^^CAMP HILL^PA^17089-0420|||||||||||TEST^GREG^^^^|S|||||2|||||||||||||M82|111223333B||||||||||||||||||||||||TEST|TEST,GREG|MEDICARE PART B||||IN2|2|||||||||||||||||IN3|2||ZPV|1|N||||||||||||||||||212473^PHYSICIAN^NO PCP^^^^|||||||||||||||||||ER|||||*NA|||||N|3|||||2|213821|201411121408|||||||||||||20141116|N|Y||ZIX|[CT 201412020200]|[ED 201411120200]|[HSP 201412040200]|");
         	stream->Write( myWriteBuffer, 0, myWriteBuffer->Length );
			myWriteBuffer = Encoding::ASCII->GetBytes("MSH|^~\&|IDX|HPA|CLOVERLEAF|HQ|201411130200||ADT^A03|63504_3_DA|T|2.3||||||ASCII|EVN|A03|201411130200||DA|$$SIU|PID|1||66660001||TEST^GREG^^^^||19750515|M||9|3 EXECUTIVE CAMPUS^STE 310^CHERRY HILL^NJ^08002|103|(999)999-9999|(888)888-8888^7777|000|||0666600014320|111-22-3333|||NON||||||||N|PD1||||212473^PHYSICIAN^NO PCP^^^^||||||||EM|NK1|1||||||NOK||||||||||||||||||||||||||||||||NK1|2||||||EC||||||||||||||||||||||||||||||||PV1|1|O|RCMA||12663655||213821^BUTLER NP^LISA^^^^|212476^SELF^REFERRED^^^^||ER||||||||-|0666600014320|012^D^X^M101||||||||||||||||H^DIS HOME-ROUTINE||||||||201411121408|201411122359|||||0666600014320||||||||213821^BUTLER NP^LISA^^^^|PV2|||TEST||||3|||||||||||1^*NA|GT1|1|66660001|TEST^GREG^^^^||3 EXECUTIVE CAMPUS^STE 310^CHERRY HILL^NJ^08002|(999)999-9999|(555)555-5555|19750515|M||S|111-22-3333||||||(555)555-5555|||ACC||||ZPI|0408||||||KELEMEN-GREG@COOPERHEALTH.EDU||||||||(555)555-5555||||||SYS$$|||66660001|N|N||39|666-666-6666|IN1|1|012^D^X^M101|MEDICAID NJ|MEDICAID|UNISYS^PO BOX 4806^TRENTON^NJ^08650|||||||20131201||||TEST^GREG^^^^|S|||||1|||||||||||||M101|991599999999||||||||||||||||||||||||TEST|TEST,GREG|MEDICAID NJ||||IN2|1|||||||||||||||||IN3|1||||||||20131201|IN1|2|015^B^P^M82|||PO BOX 890420^^CAMP HILL^PA^17089-0420|||||||||||TEST^GREG^^^^|S|||||2|||||||||||||M82|111223333B||||||||||||||||||||||||TEST|TEST,GREG|MEDICARE PART B||||IN2|2|||||||||||||||||IN3|2||ZPV|1|N||||||||||||||||||212473^PHYSICIAN^NO PCP^^^^|||||||||||||||||||ER|||||*NA|||||N|3|||||2|213821|201411121408|||||||||||||20141116|N|Y||ZIX|[CT 201412020200]|[ED 201411120200]|[HSP 201412010200]|");
         	stream->Write( myWriteBuffer, 0, myWriteBuffer->Length );
			myWriteBuffer = Encoding::ASCII->GetBytes("MSH|^~\&|IDX|HPA|CLOVERLEAF|HQ|201411130200||ADT^A03|63504_3_DA|T|2.3||||||ASCII|EVN|A03|201411130200||DA|$$SIU|PID|1||66660001||TEST^GREG^^^^||19750515|M||9|3 EXECUTIVE CAMPUS^STE 310^CHERRY HILL^NJ^08002|103|(999)999-9999|(888)888-8888^7777|000|||0666600014320|111-22-3333|||NON||||||||N|PD1||||212473^PHYSICIAN^NO PCP^^^^||||||||EM|NK1|1||||||NOK||||||||||||||||||||||||||||||||NK1|2||||||EC||||||||||||||||||||||||||||||||PV1|1|O|RCMA||12663655||213821^BUTLER NP^LISA^^^^|212476^SELF^REFERRED^^^^||ER||||||||-|0666600014320|012^D^X^M101||||||||||||||||H^DIS HOME-ROUTINE||||||||201411121408|201411122359|||||0666600014320||||||||213821^BUTLER NP^LISA^^^^|PV2|||TEST||||3|||||||||||1^*NA|GT1|1|66660001|TEST^GREG^^^^||3 EXECUTIVE CAMPUS^STE 310^CHERRY HILL^NJ^08002|(999)999-9999|(555)555-5555|19750515|M||S|111-22-3333||||||(555)555-5555|||ACC||||ZPI|0408||||||KELEMEN-GREG@COOPERHEALTH.EDU||||||||(555)555-5555||||||SYS$$|||66660001|N|N||39|666-666-6666|IN1|1|012^D^X^M101|MEDICAID NJ|MEDICAID|UNISYS^PO BOX 4806^TRENTON^NJ^08650|||||||20131201||||TEST^GREG^^^^|S|||||1|||||||||||||M101|991599999999||||||||||||||||||||||||TEST|TEST,GREG|MEDICAID NJ||||IN2|1|||||||||||||||||IN3|1||||||||20131201|IN1|2|015^B^P^M82|||PO BOX 890420^^CAMP HILL^PA^17089-0420|||||||||||TEST^GREG^^^^|S|||||2|||||||||||||M82|111223333B||||||||||||||||||||||||TEST|TEST,GREG|MEDICARE PART B||||IN2|2|||||||||||||||||IN3|2||ZPV|1|N||||||||||||||||||212473^PHYSICIAN^NO PCP^^^^|||||||||||||||||||ER|||||*NA|||||N|3|||||2|213821|201411121408|||||||||||||20141116|N|Y||ZIX|[CT 201412020200]|[ED 201411120200]|[HSP 201412020200]|");
         	stream->Write( myWriteBuffer, 0, myWriteBuffer->Length );
			myWriteBuffer = Encoding::ASCII->GetBytes("MSH|^~\&|IDX|HPA|CLOVERLEAF|HQ|201411130200||ADT^A03|63504_3_DA|T|2.3||||||ASCII|EVN|A03|201411130200||DA|$$SIU|PID|1||66660001||TEST^GREG^^^^||19750515|M||9|3 EXECUTIVE CAMPUS^STE 310^CHERRY HILL^NJ^08002|103|(999)999-9999|(888)888-8888^7777|000|||0666600014320|111-22-3333|||NON||||||||N|PD1||||212473^PHYSICIAN^NO PCP^^^^||||||||EM|NK1|1||||||NOK||||||||||||||||||||||||||||||||NK1|2||||||EC||||||||||||||||||||||||||||||||PV1|1|O|RCMA||12663655||213821^BUTLER NP^LISA^^^^|212476^SELF^REFERRED^^^^||ER||||||||-|0666600014320|012^D^X^M101||||||||||||||||H^DIS HOME-ROUTINE||||||||201411121408|201411122359|||||0666600014320||||||||213821^BUTLER NP^LISA^^^^|PV2|||TEST||||3|||||||||||1^*NA|GT1|1|66660001|TEST^GREG^^^^||3 EXECUTIVE CAMPUS^STE 310^CHERRY HILL^NJ^08002|(999)999-9999|(555)555-5555|19750515|M||S|111-22-3333||||||(555)555-5555|||ACC||||ZPI|0408||||||KELEMEN-GREG@COOPERHEALTH.EDU||||||||(555)555-5555||||||SYS$$|||66660001|N|N||39|666-666-6666|IN1|1|012^D^X^M101|MEDICAID NJ|MEDICAID|UNISYS^PO BOX 4806^TRENTON^NJ^08650|||||||20131201||||TEST^GREG^^^^|S|||||1|||||||||||||M101|991599999999||||||||||||||||||||||||TEST|TEST,GREG|MEDICAID NJ||||IN2|1|||||||||||||||||IN3|1||||||||20131201|IN1|2|015^B^P^M82|||PO BOX 890420^^CAMP HILL^PA^17089-0420|||||||||||TEST^GREG^^^^|S|||||2|||||||||||||M82|111223333B||||||||||||||||||||||||TEST|TEST,GREG|MEDICARE PART B||||IN2|2|||||||||||||||||IN3|2||ZPV|1|N||||||||||||||||||212473^PHYSICIAN^NO PCP^^^^|||||||||||||||||||ER|||||*NA|||||N|3|||||2|213821|201411121408|||||||||||||20141116|N|Y||ZIX|[CT 201412020200]|[ED 201411120200]|[HSP 201412040200]|");
         	stream->Write( myWriteBuffer, 0, myWriteBuffer->Length );
			Thread::Sleep(30000);
			myWriteBuffer = Encoding::ASCII->GetBytes("MSH|^~\&|IDX|HPA|CLOVERLEAF|HQ|201411130200||ADT^A03|63504_4_DA|T|2.3||||||ASCII|EVN|A03|201411130200||DA|$$SIU|PID|1||66660023||TEST^AETNA^^^^||19760702|F||1|1 COOPER PLAZA^^CAMDEN^NJ^08104|103|(856)342-2000||000|S|BAP^BAPTIST|0666600234316|152-11-2369|||NON||||||||N|PD1||||212473^PHYSICIAN^NO PCP^^^^|||||||||NK1|1||||||NOK||||||||||||||||||||||||||||||||NK1|2||||||EC||||||||||||||||||||||||||||||||PV1|1|O|RCMA||12663656||213821^BUTLER NP^LISA^^^^|212476^SELF^REFERRED^^^^||ER||||||||-|0666600234316|AP2^R^N^A876||||||||||||||||H^DIS HOME-ROUTINE||||||||201411121416|201411122359|||||0666600234316||||||||213821^BUTLER NP^LISA^^^^|PV2|||TEST||||3|||||||||||1^*NA|GT1|1|66660023|TEST^AETNA^^^^||1 COOPER PLAZA^^CAMDEN^NJ^08104|(856)342-2000||19760702|F||S|152-11-2369|||||||||ACC||||ZPI|0408||BP770|ST JOHN BAPTIST, CAMDEN|N|20131024|NOEMAIL||||||||||||||SYS$$|||66660023|N|||38||IN1|1|AP2^R^N^A876|AETNA EL PASO|AETNA POS II|PO BOX 981106^^EL PASO^TX^79998-1106|||||||||||TEST^AETNA^^^^|S|||||1|||||||||||||A876|123456||||||||||||||||||||||||TEST||AETNA POS II (NC)||||IN2|1|||||||||||||||||IN3|1||IN1|2|054^H^N^A881|AETNA EL PASO|AETNA/USHC HMO|PO BOX 981106^^EL PASO^TX^79998-1106|||||||||||TEST^AETNA^^^^|S|||||2|||||||||||||A881|12345647||||||||||||||||||||||||TEST||AETNA USHC HMO (NC)||||IN2|2|||||||||||||||||IN3|2||IN1|3|M12^V^C^M781|||PO BOX 7117^^LONDON^KY^40742|||||||||||TEST^AETNA^^^^|S|||||3|||||||||||||M781|6546512||||||||||||||||||||||||TEST||HORIZON NJ HEALTH (NC)||||IN2|3|||||||||||||||||IN3|3||ZPV|1|N||||||||||||||||||212473^PHYSICIAN^NO PCP^^^^|||||||||||||||||||ER|||||*NA|||||N|3|||||2|213821|201411121416|||||||||||||20141116|N|Y|ZIX||||");
stream->Write( myWriteBuffer, 0, myWriteBuffer->Length );

		// Shutdown and end connection
         client->Close();
      }
   }
   catch ( SocketException^ e ) 
   {
      Console::WriteLine( "SocketException: {0}", e );
   }
}

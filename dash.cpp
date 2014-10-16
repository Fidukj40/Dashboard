/* dash.cpp : main project file.
*Used to create and display the main window of the dashboard.
*Only displays a quick protoype of what the final app will look like.
*/
#include "Form1.h"
#include "Manager.h"

using namespace dash;

[STAThreadAttribute]
int main(array<System::String ^> ^args)
{
	// Enabling Windows XP visual effects before any controls are created
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false); 

	// Create the main window and run it
	Application::Run(gcnew Form1());
	return 0;
}

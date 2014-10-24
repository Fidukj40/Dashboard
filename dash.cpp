#include "GUIClass.cpp"
#include "Manager.cpp"
using  std::cout;
using namespace dash;
int main(array<System::String^> ^args)
{
	
	GUIClass^ gui= gcnew GUIClass();
Application::Run(gui);

}

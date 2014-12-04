#include <iostream>
#include <regex>
#include "GUIClass.cpp"
#include <msclr\marshal_cppstd.h>

using namespace msclr::interop;
using  std::cout;
using namespace System::Net;
using namespace System::Net::Sockets;
using namespace System::Threading;
using namespace System:: Text;
using namespace dash;

std::vector<std::string> parseData(string data);
static void startConnection(Object^ gui);
int main(array<System::String^> ^args);

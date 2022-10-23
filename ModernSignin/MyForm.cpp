#include "MyForm.h"
#include "RegisterForm.h"
#include "Main.h"

using namespace System;
using namespace System::Windows::Forms;
[STAThread]

void main(array<String^>^ args ) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	
	User^ user = nullptr;
	while (true)
	{
		ModernSignin::MyForm loginform;
		loginform.ShowDialog(); 

		if (loginform.switchtoRegister)
		{
			ModernSignin::RegisterForm registerform;
			registerform.ShowDialog();
			
			if (registerform.switchtoLogin)
			{
				continue;
			}
			else
			{
				user = registerform.user;
				break;
			}

		}
		else
		{
			user = loginform.user;
			break;
		}
	}


	if (user != nullptr)
	{
		/*MessageBox::Show("Successfull Authentication of " + user->username, "Success",
			MessageBoxButtons::OK, MessageBoxIcon::Information);*/
		
		ModernSignin::Main main;
		main.ShowDialog(); 
		
	}
	else
	{
		MessageBox::Show("Authentication Canceled", "Program", MessageBoxButtons::OK);
	}
}

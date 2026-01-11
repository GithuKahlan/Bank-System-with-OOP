#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsUser.h"
#include"clsMainScreen.h"
#include"Global.h"


class clsShowLoginScreen :protected clsScreen
{
private:

	static bool _Login()
	{

		bool LoginFaild = false;

		string UserName, Password;

		short FaildLogInCount = 0;
			do
			{

		if(LoginFaild)
		{
			FaildLogInCount++;
			
			cout << "\n Invalid UserName/Passwored!\n\n";
			cout << "\n You have " << (3-FaildLogInCount) << " trie(s) to login.\n\n";
		
		
		
		}

		if (FaildLogInCount==3)
		{
			cout << "\n You are locked after 3 faild trails\n\n";
			return false;

		}
	

			cout << "Enter UseName? ";
			cin >> UserName;
			cout << "Enter Password? ";
			cin >> Password;
		
			CurrentUser = clsUser::Find(UserName, Password);
		
			LoginFaild = CurrentUser.IsEmpty();
		
		} while (LoginFaild);
		CurrentUser.RegisterLogin();
		clsMainScreen::ShowMainMenue();
		return true;
		
	}

public:


	static bool ShowLoginScreen()
	{
		
		system("cls");
		_DrawScreenHeader("\t Login Screen");

		return _Login();

	}



};


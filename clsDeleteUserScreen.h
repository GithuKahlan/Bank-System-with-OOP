#pragma once

#include<iostream>
#include"clsScreen.h"
#include"clsUser.h"

class clsDeleteUserScreen:protected clsScreen
{

private:
	static void _PrintUser(clsUser User)
	{
		cout << "\nUser Card:";
		cout << "\n___________________";
		cout << "\nFirstName   : " << User.FirstName;
		cout << "\nLastName    : " << User.LastName;
		cout << "\nFull Name   : " << User.FullName();
		cout << "\nEmail       : " << User.Email;
		cout << "\nPhone       : " << User.Phone;
		cout << "\nUser Name   : " << User.UserName;
		cout << "\nPassword    : " << User.Password;
		cout << "\nPermissions : " << User.Permissions;
		cout << "\n___________________\n";

	}

	


public:

	static void ShowDeleteUserScreen()
	{

		_DrawScreenHeader("\t Delete User Screen");

		string UserName = "";
		cout << "\nPlease Enter UserName: ";
		UserName = clsInputValidate::ReadString();
		while (!clsUser::IsUserExist(UserName))
		{
			cout << "\nUserName Is not found, please try again: ";
			UserName = clsInputValidate::ReadString();
		}

		clsUser User1 = clsUser::Find(UserName);

		_PrintUser(User1);



		cout << "\n Are you sure you want to delete this User y/n?";
		char Answer = 'n';
		cin >> Answer;

		if (Answer == 'Y' || Answer == 'y')
		{

			if (User1.Delete())
			{
				cout << "\n User Deleted Successfully:-)\n";

				_PrintUser(User1);
			}
			
			else
			{
				cout << "\n Sorry, User was not deleted:-( \n ";
			}

		}



	}




};


#pragma once
#include<iostream>
#include "clsBankClient.h"
#include"clsInputValidate.h"

class clsDeleteClientScreen:protected clsScreen
{

private:


	static void _PrintClientCard(clsBankClient Client)
	{

		cout << "\Client Card:";
		cout << "\n-------------------------------";
		cout << "\nFirstName:" << Client.FirstName;
		cout << "\nLastName :" << Client.LastName;
		cout << "\nFull Name:" << Client.FullName();
		cout << "\nEmail    :" << Client.Email;
		cout << "\nPhone    :" << Client.Phone;
		cout << "\nAccountNum :" << Client.GetAccountNumber();
		cout << "\nPassword :" << Client.PinCode;
		cout << "\nBalance  :" << Client.AccountBalance;
		cout << "\n------------------\n";

	}

public:


	static void ShowDeleteClientScreen()
	{

		if (!CheckAccessRights(clsUser::enPermissions::pDeleteClient))
		{
			return;  // this will exit the function and it will not continue


		}



		_DrawScreenHeader("\t Delete Client Screen");

		string AccountNumber = "";
		cout << "\n Please Enter client Account Number: ";
		AccountNumber = clsInputValidate::ReadString();
		int Tries = 0;
		while (!clsBankClient::IsClientExist(AccountNumber))
		{
			Tries++;
			if (Tries == 3)
			{
				cout << "you are loged out";
				return;
				// I used a return instead of the break becacause if it reached 3 I want it go back to the main screen. but If used break; it will continue with code that comes after the while loop



			}
			cout << "\n Account Number is not found, choose another one: ";
			AccountNumber = clsInputValidate::ReadString();

		}


	
		
			clsBankClient Client1 = clsBankClient::Find(AccountNumber);
			_PrintClientCard(Client1);


			cout << "\n Are you sure you want to delete this client y/n?";
			char Answer = 'n';
			cin >> Answer;

			if (Answer == 'y' || Answer == 'Y')
			{

				if (Client1.Delete())
				{
					cout << "\n Client Deleted Successfully :-)\n";
					_PrintClientCard(Client1);

				}

				else
				{
					cout << "\n Error Client was not Deleted\n";

				}
			}

		
		
	}
	
	



};


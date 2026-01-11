#pragma once
#include<iostream>
#include"clsBankClient.h"
#include"clsPerson.h";
class clsFindClientScreen:protected clsScreen
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


	static void ShowFindClientScreen()
	{

		if (!CheckAccessRights(clsUser::enPermissions::pFindClient))
		{
			return;  // this will exit the function and it will not continue


		}



		string Title = "Find Client Screen";
		clsScreen::_DrawScreenHeader(Title);

		string AccountNumber = "";
		cout << "\n Please Enter client Account Number: ";
		AccountNumber = clsInputValidate::ReadString();
		while (!clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "\n Account Number is not found, choose another one: ";
			AccountNumber = clsInputValidate::ReadString();

		}

		clsBankClient Client1 = clsBankClient::Find(AccountNumber);


		if (!Client1.IsEmpty())
		{
			cout << "\nClient Found:-)\n";
		}
		else
		{
			cout << "\n Client is not found :-)\n";
		}

		_PrintClientCard(Client1);

	}




};


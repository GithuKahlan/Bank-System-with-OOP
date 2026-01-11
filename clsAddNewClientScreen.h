#pragma once
#include<iostream>
#include"clsBankClient.h"
#include"clsInputValidate.h"
#include<iomanip>

class clsAddNewClientScreen:protected clsScreen
{



private:
	// _


	static void _ReadClientInfo(clsBankClient& Client)
	{
		cout << "\n Enter FirstName: ";
		Client.FirstName = clsInputValidate::ReadString();

		cout << "\nEnter LastName :";
		Client.LastName = clsInputValidate::ReadString();

		cout << "\nEnter Email :";
		Client.Email = clsInputValidate::ReadString();

		cout << "\nEnter Phone :";
		Client.Phone = clsInputValidate::ReadString();

		cout << "\nEnter PinCode :";
		Client.PinCode = clsInputValidate::ReadString();

		cout << "\nEnter AccountBalance :";
		Client.AccountBalance = clsInputValidate::ReadFloatNumber();

	}




	static void _PrintClientCard(clsBankClient Client)
	{

		
				cout << "\Client Card:";
		cout << "\n-------------------------------";
		cout << "\nFirstName:" <<Client.FirstName;
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






	static void ShowAddNewClientScreen()
	{

		if (!CheckAccessRights(clsUser::enPermissions::pAddNewClient))
		{
			return;  // this will exit the function and it will not continue


		}



		string Title = "Add New CLient Screen";
		clsScreen::_DrawScreenHeader(Title);

		string AccountNumber = "";
		cout << "\n Please Enter client Account Number: ";
		AccountNumber = clsInputValidate::ReadString();
		while (clsBankClient::IsClientExist(AccountNumber))
		{


			cout << "Client Number is already used. Enter new account number:\n";
			AccountNumber = clsInputValidate::ReadString();


		}

		clsBankClient NewClient = clsBankClient::GetAddNewClientObject(AccountNumber);


		_ReadClientInfo(NewClient);


		clsBankClient::enSaveResult SaveResult;



		SaveResult = NewClient.Save();

		switch (SaveResult)
		{

		case clsBankClient::enSaveResult::svSucceeded:
		{
			cout << "\n Account Added Suv=ccessfully :-)\n";
			_PrintClientCard(NewClient);
			break;

		}

		case clsBankClient::enSaveResult::svFailEmptyObject:
		{
			cout << "\n Error account was not saved because it's empty";
			break;
		}

		case clsBankClient::enSaveResult::svFaildAccountNumberExists:
		{

			cout << "\n Error account was not saved because account number is used!\n";
			break;
		}

		}



    }



};


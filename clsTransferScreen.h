#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsBankClient.h"
#include"clsInputValidate.h"
class clsTransferScreen:protected clsScreen
{
private:

	static void _PrintClientCard(clsBankClient Client)
	{

		cout << "\Client Card:";
		cout << "\n-------------------------------";
		cout << "\nFull Name:" << Client.FullName();
		cout << "\nAccount Num :" << Client.GetAccountNumber();
		cout << "\nBalance  :" << Client.AccountBalance;
		cout << "\n------------------\n";

	}

	static string _ReadAccountNumber()
	{

		string AccountNumber;
	
		AccountNumber = clsInputValidate::ReadString();
		while (!clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "\nAccount number is not found, choose another one: ";
			AccountNumber = clsInputValidate::ReadString();

		}
		return AccountNumber;

	}

	static float _ReadAmount(clsBankClient SourceClient)
	{
		float Amount;
		cout << "\n Enter Transfer Amount? ";
		Amount = clsInputValidate::ReadFloatNumber();

		while (Amount > SourceClient.AccountBalance)
		{
			cout << "\n Amount Exceeds the available Balance, Enter another Amount? ";
			Amount = clsInputValidate::ReadFloatNumber();
		}
		return Amount;
	}

public:


	static void ShowTransferScreen()
	{

		_DrawScreenHeader("\t Transfer Screen");

		cout << "\n Please Enter Account Number To Transfer From :";
		clsBankClient SourceClient = clsBankClient::Find(_ReadAccountNumber());

		_PrintClientCard(SourceClient);


		cout << "\n Please Enter Account Number To Transfer To :";
		clsBankClient DestinationClient = clsBankClient::Find(_ReadAccountNumber());
		_PrintClientCard(DestinationClient);

		float Amount = _ReadAmount(SourceClient);


		cout << "\n Are you sure you want to perform this operation?y\n ";
		char Answer = 'n';
		cin >> Answer;

		if (Answer == 'Y' || Answer == 'y')
		{
			if (SourceClient.Transfer(Amount, DestinationClient, CurrentUser.UserName))
			{

				cout << "\n Transfer done Sucessfully\n";

			}
			
			else
			{
				cout << "\n Transfer failed\n";
			}
		}


		_PrintClientCard(SourceClient);
		_PrintClientCard(DestinationClient);

	}


};


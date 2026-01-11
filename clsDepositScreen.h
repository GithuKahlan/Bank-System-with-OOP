#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsBankClient.h"
#include"clsInputValidate.h"
using namespace std;
class clsDepositScreen:protected clsScreen
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

	static string _ReadAccountNumber()
	{

		string AccountNumber = "";
		cout << "\n Please Enter client Account Number: ";
		cin >> AccountNumber;
		return AccountNumber;

	}


public:

	static void ShowDepositScreen()
	{
		_DrawScreenHeader("\t Deposit Screen");

		string AccountNumber = _ReadAccountNumber();

		while (!clsBankClient::IsClientExist(AccountNumber))
		{

			cout << "\n Account Number is not found, choose another one: ";
			AccountNumber = clsInputValidate::ReadString();


		}

		clsBankClient Client1 = clsBankClient::Find(AccountNumber);

		_PrintClientCard(Client1);

		double Amount = 0;

		cout << "\n Please enter deposit amount\? ";
		
		Amount = clsInputValidate::ReadDblNumber();

		char Answer = 'n';
		cout << "\n Are you sure you want to deposit this amount[y/n]? ";
		cin >> Answer;

		if (Answer=='y'||Answer=='Y')
		{

				Client1.Deposit(Amount);
				
				cout << "Amount Deposited Successfully.\n";
				cout << "New Balance is: " << Client1.AccountBalance << endl;

		}

		else
		{
			cout << "\n Operation is Canceled.\n ";
		}





	}




};


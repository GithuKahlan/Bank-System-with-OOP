#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsBankClient.h"
#include"clsInputValidate.h"
class clsWithdrawScreen:protected clsScreen
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

	static void ShowWithdrawScreen()
	{
		_DrawScreenHeader("\t Withdraw Screen");

		string AccountNumber = _ReadAccountNumber();

		while (!clsBankClient::IsClientExist(AccountNumber))
		{

			cout << "\n Account Number is not found, choose another one: ";
			AccountNumber = clsInputValidate::ReadString();


		}

		clsBankClient Client1 = clsBankClient::Find(AccountNumber);

		_PrintClientCard(Client1);

		double Amount = 0;

		cout << "\n Please enter withdraw amount\? ";

		Amount = clsInputValidate::ReadDblNumber();

		
		short Tries = 0;
		while (Amount > Client1.AccountBalance)
		{
			Tries++;
			if (Tries >= 3 && Amount > Client1.AccountBalance)
			{
				cout << " Attempts finished. please be carefull next time. It may cause in blocking your bank account\n";
				break;
			}
			
			cout << "\nWarning !!!\n";
			cout << "Amount exeeds the balance. ";
			cout << "Amount to withdraw up to " << Client1.AccountBalance;
			cout << "\n still have " << 3 - Tries << " (Trie)s\n  Please Enter amount within your balance? ";
			Amount = clsInputValidate::ReadDblNumber();

		}

		if (Amount <= Client1.AccountBalance)
		{
			char Answer = 'n';
			cout << "\n Are you sure you want to withdraw this amount[y/n]? ";
			cin >> Answer;

			if (Answer == 'y' || Answer == 'Y')
			{
				Client1.Withdraw(Amount);


				cout << "Amount withdrawed Successfully.\n";
				cout << "New Balance is: " << Client1.AccountBalance << endl;
			}
			else
			{

			}

		}
		else
		{


		}

	}






};


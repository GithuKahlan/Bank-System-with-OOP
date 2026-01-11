#pragma once
#include <iostream>
#include"clsScreen.h"
#include"clsBankClient.h"
#include"clsUtility.h"
#include<iomanip>



class clsTotalBalancesScreen:protected clsScreen
{


private:


	static void _PrintClientRecordBalanceLine(clsBankClient Client)
	{


		cout << setw(25) << left << "" << "|"  << setw(15) << left << Client.GetAccountNumber();
		cout << "|" << left << setw(20) << Client.GetFullName();
		cout << "|" << left << setw(12) << Client.GetAccountBalance();


	}


public:





	static void ShowTotalBalanceScreen()
	{

		vector<clsBankClient>vClients = clsBankClient::GetClientList();


		string Title = "\t Balacne List Screen";
		string SubTitle = "\t   (" + to_string(vClients.size()) + ") (Client) s.";

		_DrawScreenHeader(Title, SubTitle);


		
		cout << setw(25) << left << "" << "\n\t\t---------------------------------------------";
		cout << "--------------------------------------------------\n\n";

		cout << setw(25) << left << "" << "|"  << setw(15) << left << "Account Number";
		cout << "|" << left << setw(20) << "Client Name";
		cout << "|" << left << setw(12) << "Balance";

		cout << setw(25) << left << "" << "\n\t\t---------------------------------------------";
		cout << "--------------------------------------------------\n\n";
		       
		double TotalBalances = clsBankClient::GetTotalBalances();

		if (vClients.size() == 0)
			cout << "\t\t\t No Client Availaable in the system!";

		else
		{
			for (clsBankClient Client : vClients)
			{
				_PrintClientRecordBalanceLine(Client);
				cout << endl;
			}
		}
		cout << setw(25) << left << "" << "\n\t\t---------------------------------------------";
		cout << "--------------------------------------------------\n\n";

		cout << "\t\t\t\t\t  Total Balance is= " << TotalBalances << endl;

		cout << "\t\t\t\t\t  (" << clsUtil::NumberToText(TotalBalances) <<")";
		cout << endl;
	}





};


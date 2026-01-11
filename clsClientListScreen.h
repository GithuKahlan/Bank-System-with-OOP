#pragma once
#include<iostream>
#include<iomanip>
#include"clsScreen.h"
#include"clsBankClient.h"
class clsClientListScreen :protected clsScreen
{

private:
  static void PrintClientRecordLine(clsBankClient Client)
  {

	  cout << setw(8) << left << "" << "|" << left << setw(15) << Client.GetAccountNumber();
	  cout << "|" << left << setw(20) << Client.GetFullName();
	  cout << "|" << left << setw(12) << Client.GetPhone();
	  cout << "|" << left << setw(20) << Client.GetEmail();
	  cout << "|" << left << setw(10) << Client.GetPinCode();
	  cout << "|" << left << setw(12) << Client.GetAccountBalance();

  }


public:

  static void ShowClientList()
  {

	  if (!CheckAccessRights(clsUser::enPermissions::pListClients))
	  {
		  return;  // this will exit the function and it will not continue


	  }

	  vector<clsBankClient>vClients = clsBankClient::GetClientList();

	  string Title = "\t Client List Screen";
	  string SubTitle = "\t   (" + to_string(vClients.size()) + ") (Client) s.";

	  _DrawScreenHeader(Title, SubTitle);


	  cout << setw(8) << left << "" << "\n \t---------------------------------------------------------------------------";
		  cout << "-------------------------------------------------------\n" << endl;


		  cout << setw(8) << left << "" << "|" << left << setw(15) << "Account Number";
	  cout << "|" << left << setw(20) << "Client Name";
	  cout << "|" << left << setw(12) << "Phone";
	  cout << "|" << left << setw(20) << "Email";
	  cout << "|" << left << setw(10) << "Pin Code";
	  cout << "|" << left << setw(12) << "Balance";


	  cout << setw(8) << left << "" << "\n \t---------------------------------------------------------------------------";
	  cout << "-------------------------------------------------------\n" << endl;


	  if (vClients.size() == 0)
		  cout << "\t\t\tNo Clients Available in the system!";

	  else
	  {
		  for (clsBankClient Client : vClients)
		  {

			  PrintClientRecordLine(Client);
			  cout << endl;

		  }

	  }

  }
 




};


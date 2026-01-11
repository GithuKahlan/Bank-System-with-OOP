#pragma once
#include<iostream>
#include"clsUser.h"
#include <string>
#include"clsString.h"
#include"clsScreen.h"
using namespace std;
class clsShowLoginRegisterScreen :protected clsScreen
{

private:
	static void _PrintLoginRegisterInfo(clsUser::stLoginRegisterRecord Record)
	{

		cout << setw(8) << left << "" << "|" << left << setw(35) << Record.DateTime;
		cout << "|" << left << setw(20) << Record.UserName;
		cout << "|" << left << setw(20) << Record.Password;
		cout << "|" << left << setw(10) << Record.Permission;
		
	}


public:


	static void ShowLoginResgisterScreen()
	{


		if (!CheckAccessRights(clsUser::enPermissions::pLoginRegister))
		{
			return;  // this will exit the function and it will not continue


		}


		vector<clsUser::stLoginRegisterRecord> vLoginRegisterRecord = clsUser::GetLogInRegisterList();

		string Tiltle = "\t Login Register List Screen";
		string SubTitle = "\t\t(" + to_string(vLoginRegisterRecord.size()) + ") Reocord(s).";
		_DrawScreenHeader(Tiltle, SubTitle);

		

		cout << setw(8) << left << "" << "\n \t---------------------------------------------------------------------------";
		cout << "-------------------------------------------------------\n" << endl;


		cout << setw(8) << left << "" << "|" << left << setw(35) << " Date and Time";
		cout << "|" << left << setw(20) << "User Name";
		cout << "|" << left << setw(20) << "Password";
		cout << "|" << left << setw(10) << "Permission";

		cout << setw(8) << left << "" << "\n \t---------------------------------------------------------------------------";
		cout << "-------------------------------------------------------\n" << endl;


		if (vLoginRegisterRecord.size() == 0)
			cout << "\t\t\tNo Login available in the system!";

		else

			for (clsUser::stLoginRegisterRecord Record : vLoginRegisterRecord)
			{

				_PrintLoginRegisterInfo(Record);
				cout << endl;

			}
		cout << setw(8) << left << "" << "\n \t---------------------------------------------------------------------------";
		cout << "-------------------------------------------------------\n" << endl;


	}




	

};


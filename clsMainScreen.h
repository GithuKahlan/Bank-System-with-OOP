#pragma once
#include<iostream>
#include"clsScreen.h";
#include"clsInputValidate.h"
#include"clsClientListScreen.h"
#include"clsAddNewClientScreen.h"
#include"clsDeleteClientScreen.h"
#include"clsUpdateClientScreen.h"
#include"clsFindClientScreen.h"
#include"clsTransactionScreen.h"
#include"clsManageUsersScreen.h"
#include"clsShowLoginScreen.h"
#include"Global.h"
#include"clsShowLoginScreen.h"
#include"clsLoginResgisterScreen.h"
#include"clsCurrencyMainScreen.h"

using namespace std;

class clsMainScreen:protected clsScreen
{
	// _

private:
	enum enMainMenueOptions{eListClients=1,eAddNewClient=2,
		eDeleteClient=3,eUpdateClient=4,eFindClient=5,eShowTransationMenue=6,
		eManageUsers=7,enLoginRegister=8,enCurrencyExchange=9,eExit=10 
	};

	static short _ReadMainMenueOption()
	{

		cout << setw(37) << left << "" << " Choose what do you want to do ?[1 to 10]? ";
		short Choice = clsInputValidate::ReadShortNumberBetween(1, 10, "Enter Number between 1 and 10? ");
		return Choice;

	}
	static void _GoBackToMainMenue()
	{

		cout << setw(37) << left << "" << "\n\t Press any key to go back to main Menue....\n";
		system("pause>0");
		ShowMainMenue();

	}

	static void _ShowAllClientsScreen()
	{
		clsClientListScreen ::ShowClientList();

	}
	static void _ShowAddNewClientScreen()
	{
		
		clsAddNewClientScreen::ShowAddNewClientScreen();
 
	}

	static void _ShowDeleteClientScreen()
	{
	
		clsDeleteClientScreen::ShowDeleteClientScreen();

	}

	static void _ShowUpdateClientScreen()
	{
	
		clsUpdateClientScreen::ShowUpdateClientScreen();

	}

	static void _ShowFindClientScree()
	{
		clsFindClientScreen::ShowFindClientScreen();

	}

	static void _ShowTransationsMenue()
	{
		clsTransactionScreen::ShowTransactionScreen();

	}

	static void _ShowManageUserMenue()
	{
		clsManageUsersScreen::ShowManageUsersMenue();

	}

	static void _ShowLoginRegisterMenue()
	{

		clsShowLoginRegisterScreen::ShowLoginResgisterScreen();

	}


	static void _ShowCurrencyExchangeMenue()
	{

		clsCurrecyMainScreen::ShowCurrencyExchangeScreen();

	}

	static void _Logout()
	{
		CurrentUser = clsUser::Find("", "");
	}

	static void _PerfomMainMenueOption(enMainMenueOptions MainMenueOption)
	{

		switch (MainMenueOption)
		{

		case enMainMenueOptions::eListClients:
		{
			system("cls");
			_ShowAllClientsScreen();
			_GoBackToMainMenue();

			break;
		}

		case enMainMenueOptions::eAddNewClient:
		{

			system("cls");
			_ShowAddNewClientScreen();
			_GoBackToMainMenue();

			break;
		}

		case enMainMenueOptions::eDeleteClient:
		{
			system("cls");
			_ShowDeleteClientScreen();
			_GoBackToMainMenue();


			break;
		}
		case enMainMenueOptions::eUpdateClient:
		{

			system("cls");
			_ShowUpdateClientScreen();
			_GoBackToMainMenue();

			break;
		}

		case enMainMenueOptions::eFindClient:
		{

			system("cls");
			_ShowFindClientScree();
			_GoBackToMainMenue();

			break; 
		}
		case enMainMenueOptions::eShowTransationMenue:
		{
			system("cls");
			_ShowTransationsMenue();
			_GoBackToMainMenue();
			break;
		}
		case enMainMenueOptions::eManageUsers:
		{
			system("cls");
			_ShowManageUserMenue();
			_GoBackToMainMenue();
			break;
		}

		case enMainMenueOptions::enLoginRegister:
		{
			system("cls");

			_ShowLoginRegisterMenue();
			_GoBackToMainMenue();

			break;

		}
		
		case enMainMenueOptions::enCurrencyExchange:
		{
			system("cls");
			_ShowCurrencyExchangeMenue();
			_GoBackToMainMenue();

			break;
		}

		case enMainMenueOptions::eExit:
		{

			system("cls");
			_Logout();
		
			break;
		}

		}

	}


public:

	static void ShowMainMenue()

	{

		system("cls");
		
		_DrawScreenHeader("\tMain Screen");

		cout <<setw(37)<<left<<"" << "========================================\n";
		cout <<setw(37) <<left <<""<<"\t\tMain Menue\n";
		cout <<setw(37) <<left <<""<<"========================================\n";

		cout << setw(37) << left <<""<< "\t[1] Show Client List.\n";
		cout << setw(37) << left <<""<< "\t[2] Add New Client.\n";
		cout << setw(37) << left <<""<< "\t[3] Delete Client.\n";
		cout << setw(37) << left <<""<< "\t[4] Update Client Info.\n";
		cout << setw(37) << left <<""<< "\t[5] Find Client.\n";
		cout << setw(37) << left <<""<< "\t[6] Transactions.\n";
		cout << setw(37) << left <<""<< "\t[7] Manage Users.\n";
		cout << setw(37) << left << "" << "\t[8] Login Resgister.\n";
		cout << setw(37) << left << "" << "\t[9] Currency Exchange.\n";
		cout << setw(37) << left <<""<< "\t[10] Logout.\n";
		cout << setw(37) << left << "" << "========================================\n";


		_PerfomMainMenueOption((enMainMenueOptions)_ReadMainMenueOption());


	}






};


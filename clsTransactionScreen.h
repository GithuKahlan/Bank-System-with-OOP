#pragma once
#include<iostream>
#include"clsInputValidate.h"
#include"clsMainScreen.h"
#include"clsScreen.h"
#include"clsDepositScreen.h"
#include"clsWithdrawScreen.h"
#include"clsTransferScreen.h"
#include"clsTransferLogScreen.h"
#include"clsTotalBalancesScreen.h"


#include<iomanip>
using namespace std;
class clsTransactionScreen:protected clsScreen
{
private:

	enum enTransationMainMenueOptions {
		eDeposit = 1, eWihtdraw = 2,
		eTotalBalance = 3,eTransfer=4,eTransferLog=5, eShowMainMenue = 6
	};



	static short _ReadTransactionMainMenueOption()
	{

		cout << setw(37) << left << "" << " Choose what do you want to do ?[1 to 6]? ";
		short Choice = clsInputValidate::ReadShortNumberBetween(1, 6, "Enter Number between 1 and 6? ");
		return Choice;
	}
	
	static void _GoBackToTransationMainMenue()
	{

		cout << setw(37) << left << "" << "\n\t Press any key to go back to main Menue....\n";
		system("pause>0");
		ShowTransactionScreen();

	}


	static void _ShowDepositScreen()
	{
		clsDepositScreen::ShowDepositScreen();

	}

	static void _ShowWithDrawScreen()
	{
        clsWithdrawScreen::ShowWithdrawScreen();

	}
	static void _ShowTransferScreen()
	{

		clsTransferScreen::ShowTransferScreen();

	}

	static void _ShowTranferLogScreen()
	{

		clsTransferLogScreen::ShowTransferLogScreen();

	}

	static void _ShowTotalBalanceScreen()
	{

		clsTotalBalancesScreen::ShowTotalBalanceScreen();

	}






	static void _PerfomTransactionMainMenueOption(enTransationMainMenueOptions TransactionMainMenueOption)
	{

		switch (TransactionMainMenueOption)
		{

		case enTransationMainMenueOptions::eDeposit:
		{
			system("cls");
			_ShowDepositScreen();
			_GoBackToTransationMainMenue();

			break;
		}

		case enTransationMainMenueOptions::eWihtdraw:
		{

			system("cls");
			_ShowWithDrawScreen();
			_GoBackToTransationMainMenue();

			break;
		}

		case enTransationMainMenueOptions::eTransfer:
		{
			system("cls");
			_ShowTransferScreen();
			_GoBackToTransationMainMenue();
			break;
		}

		case enTransationMainMenueOptions::eTotalBalance:
		{
			system("cls");
			_ShowTotalBalanceScreen();
			_GoBackToTransationMainMenue();
			break;
		}
		
		case enTransationMainMenueOptions::eTransferLog:
		{


			system("cls");
			_ShowTranferLogScreen();
			_GoBackToTransationMainMenue();
			break;

		}

		case enTransationMainMenueOptions::eShowMainMenue:
		{
          // do nothing here. The main screen will handle it:-);
		}

		}

	}




public:



	static void ShowTransactionScreen()

	{

		if (!CheckAccessRights(clsUser::enPermissions::pTranactions))
		{
			return;  // this will exit the function and it will not continue


		}


		system("cls");


		_DrawScreenHeader("\t Transactionhn Screen");


		cout << setw(37) << left << "" << "========================================\n";
		cout << setw(37) << left << "" << "\t\t Transation Menue\n";
		cout << setw(37) << left << "" << "========================================\n";

		cout << setw(37) << left << "" << "\t[1] Deposit.\n";
		cout << setw(37) << left << "" << "\t[2] Withdraw.\n";
		cout << setw(37) << left << "" << "\t[3] Total Balacne.\n";
		cout << setw(37) << left << "" << "\t[4] Transfer.\n";
		cout << setw(37) << left << "" << "\t[5] Transfer Log.\n";
		cout << setw(37) << left << "" << "\t[6] Main Menue.\n";
		cout << setw(37) << left << "" << "========================================\n";


		_PerfomTransactionMainMenueOption((enTransationMainMenueOptions)_ReadTransactionMainMenueOption());


	}


};


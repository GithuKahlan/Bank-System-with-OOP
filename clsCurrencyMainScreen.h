
#pragma once
#include<iostream>
#include<iomanip>
#include"clsScreen.h"
#include"clsInputValidate.h"
#include"clsCurrencyListScreen.h"
#include"clsFindCurrencyScreen.h"
#include"clsUpdateCurrencyRateScreen.h"
#include"clsCurrencyCalculatorScreen.h"


class clsCurrecyMainScreen :protected clsScreen
{

private:


	enum enMainMenueCurrencyExchangeOptions { enListCurrency = 1, enFindCurrency = 2, enUpdateCurrency = 3, enCalculateCurrency = 4, enExit = 5 };

	static short _ReadMainMenueOption()
	{


		cout << setw(37) << left << "Choose what do you want to do[1 to 5]?";

		short Choice = clsInputValidate::ReadIntNumberBetween(1, 5, "Enter Number between 1 and 5: ");

		return Choice;

	}


	static void _GoBackToMainMenue()
	{
		cout << setw(37) << left << "Press any Key to Go Back to Main Menue....\n";
		system("pause>0");


		ShowCurrencyExchangeScreen();
	}



	static void _ShowCurrencyList()
	{
	
		clsCurrencyListScreen::ShowCurrencyList();


	}


	static void _ShowFindCurrencyScreen()
	{
		cout << "Find will be here";

		clsFindCurrencyScreen::ShowFindCurrencyScreen();
	}

	static void _ShowUpdateCurrencyScreen()
	{

		
		clsUpdateCurrencyRateScreen::ShowUpdateCurrencyScreen();
	}

	static void _ShowCurrencyCalculatorScreen()
	{
	
		clsCurrencyCalculatorScreen::ShowCurrencyCalculatorScreen();

	}


	static void _ShowMainMenue()
	{



	}


	

	static void _PerfomCurrencyExchageMainMenueOption(enMainMenueCurrencyExchangeOptions MainCurrencyChoice)
	{

		switch (MainCurrencyChoice)
		{


		case enMainMenueCurrencyExchangeOptions::enListCurrency:
		{
			system("cls");

			_ShowCurrencyList();

			_GoBackToMainMenue();
			break;
		}




		case enMainMenueCurrencyExchangeOptions::enFindCurrency:
		{
			system("cls");
			_ShowFindCurrencyScreen();

			_GoBackToMainMenue();
			break;
		}


		case enMainMenueCurrencyExchangeOptions::enUpdateCurrency:
		{
			system("cls");
			_ShowUpdateCurrencyScreen();


			_GoBackToMainMenue();
			break;
		}

		case enMainMenueCurrencyExchangeOptions::enCalculateCurrency:
		{
			system("cls");

			_ShowCurrencyCalculatorScreen();

			_GoBackToMainMenue();
			break;
		}


		case enMainMenueCurrencyExchangeOptions::enExit:
		{

			
		}


		}
	}


public:


	static void ShowCurrencyExchangeScreen()
	{
		system("cls");

		_DrawScreenHeader("\t Currency Exhcange Main  Screen");


		cout << setw(37) << left << "" << "========================================\n";
		cout << setw(37) << left << "" << "\t\t Currency Exchange Menue\n";
		cout << setw(37) << left << "" << "========================================\n";

		cout << setw(37) << left << "" << "\t[1] List Currency.\n";
		cout << setw(37) << left << "" << "\t[2] Find Currency.\n";
		cout << setw(37) << left << "" << "\t[3] Update Rate.\n";
		cout << setw(37) << left << "" << "\t[4] Currency Calculator.\n";
		cout << setw(37) << left << "" << "\t[5] Main Menue.\n";

		cout << setw(37) << left << "" << "========================================\n";


		_PerfomCurrencyExchageMainMenueOption((enMainMenueCurrencyExchangeOptions)_ReadMainMenueOption());





	}


};


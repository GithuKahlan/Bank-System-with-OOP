#pragma once
#include<iostream>
#include<string>
#include"clsScreen.h"
#include"clsCurrency.h"
class clsCurrencyCalculatorScreen :protected clsScreen
{
private:

	static void _PrintCurrencyCard(clsCurrency Currency,string Title="Currecny Card:")
	{
		cout << "\n" << Title << endl;
		cout << "_____________________________\n";
		cout << "\nCountry    : " << Currency.Country();
		cout << "\nCode       : " << Currency.CurrencyCode();
		cout << "\nName       : " << Currency.CurrencyName();
		cout << "\nRate(1$) = : " << Currency.Rate();

		cout << "\n_____________________________\n";

	}

	

	static float _ReadAmount()
	{

		float Amount = 0;
		cout << "Enter Amount to Exchange:";
		Amount = clsInputValidate::ReadIntNumber();

		return Amount;

	}
	
	

	static clsCurrency _GetCurrency(string Message)
	{

		string CurrencyCode;
		cout << Message << endl;

		CurrencyCode = clsInputValidate::ReadString();

		while (!clsCurrency::IsCurrencyExist(CurrencyCode))
		{

			cout << "Enter Correct Currency Code: ";

			CurrencyCode = clsInputValidate::ReadString();

		}

		clsCurrency Currency = clsCurrency::FindByCode(CurrencyCode);
		return Currency;


	}


	static void _PrintCalculationsResults(float Amount, clsCurrency CurrencyFrom, clsCurrency CurrencyTo)
	{

		_PrintCurrencyCard(CurrencyFrom, "Covert From:");
		float AmountInUSD = CurrencyFrom.CovertToUSD(Amount);

		cout << Amount << " " << CurrencyFrom.CurrencyCode() << " = " << AmountInUSD << " USD\n ";

		if (CurrencyTo.CurrencyCode() == "USD")
		{
			return;
		}

		

		cout << "\n Converting From USD to:\n";
		_PrintCurrencyCard(CurrencyTo, "To:");


		float AmountInCurrencyTo = CurrencyFrom.ConvertToOtherCurrency(Amount, CurrencyTo);


		cout << Amount << " " << CurrencyFrom.CurrencyCode() << " = " << AmountInCurrencyTo <<" " << CurrencyTo.CurrencyCode();

		





	}




public:



	static void ShowCurrencyCalculatorScreen()
	{


		char Continue = 'Y';
		while (Continue == 'Y' || Continue == 'y')
		{
			_DrawScreenHeader("\tCurrency Calculator Screen");

			clsCurrency CurrencyFrom = _GetCurrency("Please Enter Currency Code of the Currency you want to transfer from :");
			clsCurrency CurrencyTo = _GetCurrency("Please Enter Currency Code of the Currency you want to transfer To:");


			float Amount = _ReadAmount();

			_PrintCalculationsResults(Amount, CurrencyFrom, CurrencyTo);

			cout << "\nDo you want to perform another calculation? y/n?\n";
			cin >> Continue;
		}


	}




};


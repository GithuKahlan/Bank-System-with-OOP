#pragma once
#include<iostream>
#include<string.h>
#include"clsCurrency.h"
#include"clsScreen.h"

class clsUpdateCurrencyRateScreen :protected clsScreen
{


private:

	static void _PrinCurrencyRecordLine(clsCurrency Currency)
	{


		cout << "Currency Card:\n";

		cout << "--------------------------------------\n";

		cout << "Country    :" << Currency.Country() << endl;
		cout << "Code      :" << Currency.CurrencyCode() << endl;
		cout << "Name      :" << Currency.CurrencyName() << endl;
		cout << "Rate(1$)  =" << Currency.Rate() << endl;

		cout << "--------------------------------------\n";

	}



	static float _ReadRate()
	{

		float NewRate=0;
		cout << "\nEnter New Rate: ";
		NewRate = clsInputValidate::ReadFloatNumber();
		
		return NewRate;

	}


public:




	static void ShowUpdateCurrencyScreen()
	{

		_DrawScreenHeader("\t Update Currency Screen");

		string CurrencyCode = "";
		cout << "Please Enter Currency Code: ";


		CurrencyCode = clsInputValidate::ReadString();

		vector<clsCurrency> vCurrency = clsCurrency::GetCurrenciesList();

		
		while (!clsCurrency::IsCurrencyExist(CurrencyCode))
		{

			cout << "Enter Correct Currency Code: ";

			CurrencyCode = clsInputValidate::ReadString();


		}
		clsCurrency Currency = clsCurrency::FindByCode(CurrencyCode);
		
			_PrinCurrencyRecordLine(Currency);

	
		char Answer = 'n';
		cout << "Are you sure you want to update the rate of this Currency y/n? ";
		cin >> Answer;

		if (Answer == 'Y' || Answer == 'y')
		{

			cout << "\n\nUpdate Currency Rate: ";
			cout << "\n------------------------";

			Currency.UpdateRate(_ReadRate());
			
			cout << "\nCurrenncy Rate Updated Sucessfully:-)";
			_PrinCurrencyRecordLine(Currency);
		

		}



	}




};


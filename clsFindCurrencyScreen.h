/*
#pragma once
#include<iostream>
#include<string>
#include"clsCurrency.h"
#include"clsScreen.h"
#include"clsInputValidate.h"

using namespace std;
class clsFindCurrencyScreen:protected clsScreen
{

private:
	static void _PrinCurrencyRecordLine(clsCurrency Currency)
	{
		
		
		cout << "Currency Card:\n";

		cout << "--------------------------------------\n";

		cout <<"Country    :"<< Currency.Country()<<endl;
		cout << "Code      :"<< Currency.CurrencyCode()<<endl; 
		cout << "Name      :" << Currency.CurrencyName() << endl;
		cout << "Rate(1$)  ="<< Currency.Rate()<<endl;

		cout << "--------------------------------------\n";

	}


	static void _ShowResult(clsCurrency Currency)
	{


		if (!Currency.IsEmpty())
		{

			cout << "\n Currency Found :-)\n";
			_PrinCurrencyRecordLine(Currency);

		}

		else
		{
			cout << "\nCurrency was not Found :-(\n";

		}




	}


public:


	static void SchowFindCurrencyScreen()
	{

		_DrawScreenHeader("\t Find Currency Screen");

		cout << "\nFind By:[1] Code Or [2] Counrty  ?";
		short Answer;

		cin >> Answer;

		vector<clsCurrency>vCurrency = clsCurrency::GetCurrenciesList();

		if (Answer == 1)

		{
			string CurrencyCode;
			cout << "\nPlease Enter CurrencyCode: ";
			CurrencyCode = clsInputValidate::ReadString();

			clsCurrency Currency = clsCurrency::FindByCode(CurrencyCode);

			for (clsCurrency C : vCurrency)
			{
			
				if (C.CurrencyCode() == clsString::UpperAllString(CurrencyCode))
				{
					_ShowResult(C);
				}


			}

		

		}



		else if(Answer==2)
		{
			string Country;
			cout << "\nPlease Enter Country: ";
			Country = clsInputValidate::ReadString();
			
			clsCurrency Currency = clsCurrency::FindByCountry(Country);

			for (clsCurrency C : vCurrency)
			{

				if (clsString::UpperAllString(C.Country()) == clsString::UpperAllString(Country))
				{

					_ShowResult(C);
				}
			}
		

		}

		//else
		//	cout << "Wrong Opeation.\n";


	}



};

*/


#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsCurrency.h"
#include "clsInputValidate.h"

class clsFindCurrencyScreen :protected clsScreen
{

private:
	static void _PrintCurrencyCard(clsCurrency Currency)
	{
		cout << "\nCurrency Card:\n";
		cout << "_____________________________\n";
		cout << "\nCountry    : " << Currency.Country();
		cout << "\nCode       : " << Currency.CurrencyCode();
		cout << "\nName       : " << Currency.CurrencyName();
		cout << "\nRate(1$) = : " << Currency.Rate();

		cout << "\n_____________________________\n";

	}

	static void _ShowResults(clsCurrency Currency)
	{
		if (!Currency.IsEmpty())
		{
			cout << "\nCurrency Found :-)\n";
			_PrintCurrencyCard(Currency);
		}
		else
		{
			cout << "\nCurrency Was not Found :-(\n";
		}
	}

public:

	static void ShowFindCurrencyScreen()
	{

		_DrawScreenHeader("\t  Find Currency Screen");

		cout << "\nFind By: [1] Code or [2] Country ? ";
		short Answer = 1;

		cin >> Answer;

		if (Answer == 1)
		{
			string CurrencyCode;
			cout << "\nPlease Enter CurrencyCode: ";
			CurrencyCode = clsInputValidate::ReadString();
			clsCurrency Currency = clsCurrency::FindByCode(CurrencyCode);
			_ShowResults(Currency);
		}
		else
		{
			string Country;
			cout << "\nPlease Enter Country Name: ";
			Country = clsInputValidate::ReadString();
			clsCurrency Currency = clsCurrency::FindByCountry(Country);
			_ShowResults(Currency);
		}






	}

};


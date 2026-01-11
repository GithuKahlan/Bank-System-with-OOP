#include <iostream>
#include"clsShowLoginScreen.h";
#include <iomanip>
#include"clsCurrency.h"

using namespace std;


/*
 static void _PrintCurrency(clsCurrency Currency)
 {

	cout << "\nCurrency Card:\n";
	cout << "-------------------------\n";
	cout << "\nCountry       :" << Currency.Country();
	cout << "\nCode          :" << Currency.CurrrencyCode();
	cout << "\nName          :" << Currency.CurrencyName();
	cout << "\nRate(1$)      :" << Currency.Rate();

	cout << "-------------------------\n";

 }

 */



int main()
{
   while (true)
   {
    	if (!clsShowLoginScreen::ShowLoginScreen())
   	      {
    		break;
    	  }
   }
   
   
   	system("pause>0");




	return 0;
}

/*







	clsCurrency Currency1 = Currency1.FindByCode("jod");
	if (Currency1.IsEmpty())
	{
		cout << "\nCurrency is not Found!\n";

	}

	else
	{
		_PrintCurrency(Currency1);

	}


	clsCurrency Currency2 = Currency2.FindByCountry("Egypt");

	if (Currency1.IsEmpty())
	{
		cout << "\nCurrency is not Found!\n";

	}

	else
	{
		_PrintCurrency(Currency2);

	}


	cout << "Currency after Updating Rate:\n";

	Currency1.UpdateRate(0.71);

	_PrintCurrency(Currency1);






*/
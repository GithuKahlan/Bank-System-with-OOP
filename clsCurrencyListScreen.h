
#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsCurrency.h"

using namespace std;
class clsCurrencyListScreen:protected clsScreen
{

private:

    static void _PrinCurrencyRecordLine(clsCurrency Currency)
    {

        cout << setw(8) << left << "" << "| " << left << setw(25) << Currency.Country();
        cout << "| " << left << setw(12) << Currency.CurrencyCode();
        cout << "| " << left << setw(41) << Currency.CurrencyName();
        cout << "| " << left << setw(20) << Currency.Rate();

       
    }




public:

    static	void ShowCurrencyList()
    {


        vector<clsCurrency>vCurrency = clsCurrency::GetCurrenciesList();


        string Title = "\t Currencies List Screen";
        string SubTitle = "\t   (" + to_string(vCurrency.size()) + ") Currency.";
        _DrawScreenHeader(Title, SubTitle);




        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "______________________________________________\n" << endl;

        cout << setw(8) << left << "" << "| " << left << setw(25) << "Country";
        cout << "| " << left << setw(12) << "Code";
        cout << "| " << left << setw(41) << "Currency Name";
        cout << "| " << left << setw(20) << "Rate/(1$)";

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "______________________________________________\n" << endl;

        if (vCurrency.size() == 0)
            cout << "\t\t\t\tNo Users Available In the System!";
        else
        {

            for (clsCurrency Currency : vCurrency)
            {

                _PrinCurrencyRecordLine(Currency);
                cout << endl;
            }

            cout << setw(8) << left << "" << "\n\t_______________________________________________________";
            cout << "______________________________________________\n" << endl;
        }
    }
};

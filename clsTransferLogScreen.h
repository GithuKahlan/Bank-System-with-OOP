#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsDate.h"
#include"clsTransactionScreen.h"
class clsTransferLogScreen:protected clsScreen
{

private:

 static	void _PrintTranferLogRecord(clsBankClient::stTransferLogRecord vTranferRecord)
	{


     cout << setw(8) << left << "" << "| " << left << setw(23) << vTranferRecord.DateAndTime;
     cout << "| " << left << setw(8) << vTranferRecord.SourceClient;
     cout << "| " << left << setw(8) << vTranferRecord.DestinClient2;
     cout << "| " << left << setw(8) << vTranferRecord.TransferAmount;
     cout << "| " << left << setw(10) << vTranferRecord.SourceBalance;
     cout << "| " << left << setw(10) << vTranferRecord.DestinBalance;
     cout << "| " << left << setw(8) << vTranferRecord.UserName;


	}


public:


	static void ShowTransferLogScreen()
	{
		vector<clsBankClient::stTransferLogRecord> vTransferLogRecord = clsBankClient::GetTransferLogRecord(); 


       
        string Title = "\t  Transfer Log List Screen";
        string SubTitle = "\t    (" + to_string(vTransferLogRecord.size()) + ") Record(s).";

        _DrawScreenHeader(Title, SubTitle);

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "______________________________________________\n" << endl;

        cout << setw(8) << left << "" << "| " << left << setw(23) << "Date/Time";
        cout << "| " << left << setw(8) << "s.Acct";
        cout << "| " << left << setw(8) << "d.Acct";
        cout << "| " << left << setw(8) << "Amount";
        cout << "| " << left << setw(10) << "s.Balance";
        cout << "| " << left << setw(10) << "d.Balance";
        cout << "| " << left << setw(8) << "User";

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "______________________________________________\n" << endl;

        if (vTransferLogRecord.size() == 0)
            cout << "\t\t\t\tNo Transfer Record Available In the System!";
        else

            for (clsBankClient::stTransferLogRecord TransferRecord : vTransferLogRecord)
            {

                _PrintTranferLogRecord(TransferRecord);
                cout << endl;
            }

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "______________________________________________\n" << endl;
    }





};


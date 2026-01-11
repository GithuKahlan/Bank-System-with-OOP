#pragma once
#include <iostream>
#include<string>
#include"clsPerson.h"
#include"clsString.h"
#include<vector>
#include<fstream>
#include"Global.h"
#include"clsDate.h"


class clsBankClient :public clsPerson
{
private:

	// _

	enum enMode { EmptyMode = 0, UpdateMode = 1, AddNewMode = 2 };
	enMode _Mode;
	string _AccountNumber;
	string _PinCode;
	float _AccountBalance;
	bool _MarkedForDeleted = false;

	static clsBankClient _ConvertLineToClientObject(string Line, string Seperator = "#//#")
	{
		vector<string>vClientData;
		vClientData = clsString::Split(Line, Seperator);


		return clsBankClient(enMode::UpdateMode, vClientData[0], vClientData[1], vClientData[2], vClientData[3], vClientData[4], vClientData[5], stod(vClientData[6]));


	}

	static string  _ConverClientObjectToLine(clsBankClient Client, string Seperator = "#//#")
	{
		string stClientRecord = "";
		stClientRecord += Client.FirstName + Seperator;
		stClientRecord += Client.LastName + Seperator;
		stClientRecord += Client.Email + Seperator;
		stClientRecord += Client.Phone + Seperator;
		stClientRecord += Client._AccountNumber + Seperator;
		stClientRecord += Client.PinCode + Seperator;
		stClientRecord += to_string(Client._AccountBalance);


		return stClientRecord;


	}


	 string  _PepareTransferRegister(clsBankClient DestinationClient, float Amount,string UserName, string Seperator = "#//#")
	{

		string TranferRegister = "";
		TranferRegister += clsDate::GetSystemDateTimeString()+Seperator;
		TranferRegister +=GetAccountNumber() + Seperator;
		TranferRegister += DestinationClient.GetAccountNumber() + Seperator;
		TranferRegister += to_string (Amount)+ Seperator;
		TranferRegister += to_string(AccountBalance) + Seperator;
		TranferRegister += to_string(DestinationClient.AccountBalance) + Seperator;
		TranferRegister += CurrentUser.UserName;
		
		return TranferRegister;

	}

	void  _RegisterTransfer(clsBankClient DestinationClient, float Amount, string UserName)
	{
		string DataLine = _PepareTransferRegister(DestinationClient, Amount, UserName);
		fstream MyFile;
		MyFile.open("TransferLog.txt", ios::out | ios::app);

		if (MyFile.is_open())
		{
			MyFile << DataLine << endl;
			MyFile.close();

		}


	}

	

	static vector<clsBankClient>_LoadClientDataFromFile() 
	{

		vector<clsBankClient>vClients;

		fstream MyFile;
		MyFile.open("Clients.txt", ios::in);
		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsBankClient Client = _ConvertLineToClientObject(Line);

				vClients.push_back(Client);
			}
			MyFile.close();

		}

		return vClients;

	}


	

	struct stTransferLogRecord;

	static stTransferLogRecord _ConvertLineToTransferLogRecord(string Line,string Seperator="#//#")
	{

		vector<string>vTransferLogRecord = clsString::Split(Line, Seperator);
		stTransferLogRecord TransferLogRecord;
		TransferLogRecord.DateAndTime = vTransferLogRecord[0];
		TransferLogRecord.SourceClient = vTransferLogRecord[1];
		TransferLogRecord.DestinClient2 = vTransferLogRecord[2];
		TransferLogRecord.TransferAmount = stod(vTransferLogRecord[3]);
		TransferLogRecord.SourceBalance = stod(vTransferLogRecord[4]);
		TransferLogRecord.DestinBalance = stod(vTransferLogRecord[5]);
		TransferLogRecord.UserName = (vTransferLogRecord[6]);

		return TransferLogRecord;

	}


	static void _SaveClientDataToFile(vector<clsBankClient> vClients)
	{

		fstream MyFile;
		MyFile.open("Clients.txt", ios::out); //  OverWrite


		string DataLine;


		if (MyFile.is_open())
		{

			for (clsBankClient C : vClients)
			{
				if (C.MarkedForDeleted() == false)
				{

					DataLine = _ConverClientObjectToLine(C);
					MyFile << DataLine << endl;
				}

			}

			MyFile.close();

		}

	}

	void _Update()
	{
		vector<clsBankClient> _Vclients;
		_Vclients = _LoadClientDataFromFile();

		for (clsBankClient& C : _Vclients)
		{

			if (C.GetAccountNumber() == GetAccountNumber())
			{
				C = *this;
				break;

			}



		}

		_SaveClientDataToFile(_Vclients);


	}
	void _AddDateLineToFile(string stDataLine)
	{
		fstream MyFile;
		MyFile.open("Clients.txt", ios::out | ios::app);

		if (MyFile.is_open())
		{


			MyFile << stDataLine << endl;
			MyFile.close();

		}




	}


	void _AddNew()
	{

		_AddDateLineToFile(_ConverClientObjectToLine(*this));


	}


	static clsBankClient _GetEmptyClientObject()
	{

		return clsBankClient(enMode::EmptyMode, "", "", "", "", "", "", 0);

	}

public:

	clsBankClient(enMode Mode, string FirstName, string LastName, string Email, string Phone, string AccountNumber, string PinCode, float AccountBalance) :clsPerson(FirstName, LastName, Email, Phone)
	{
		_Mode = Mode;
		_AccountNumber = AccountNumber;
		_PinCode = PinCode;
		_AccountBalance = AccountBalance;
	}


	struct stTransferLogRecord
	{

		string DateAndTime;
		string SourceClient;
		string DestinClient2;
		float TransferAmount;
		float SourceBalance;
		float DestinBalance;
		string UserName;




	};

	bool IsEmpty()
	{
		return(_Mode == enMode::EmptyMode);


	}

	bool MarkedForDeleted()
	{
		return _MarkedForDeleted;
	}

	string GetAccountNumber()
	{
		return _AccountNumber;
	}

	void SetPinCode(string PinCode)
	{
		_PinCode = PinCode;
	}

	string GetPinCode()
	{
		return _PinCode;
	}

	__declspec(property(get = GetPinCode, put = SetPinCode))string PinCode;

	void SetAccountBalance(float AccountBalance)
	{
		_AccountBalance = AccountBalance;

	}

	float GetAccountBalance()
	{
		return _AccountBalance;
	}
	__declspec(property(get = GetAccountBalance, put = SetAccountBalance))float AccountBalance;

	string GetFullName()
	{
		return clsPerson::GetFirstName() + "" + clsPerson::GetLastName();

	}


	/*

No UI Related Code inside the object.

void Print()
{

	cout << "\Client Card:";
	cout << "\n-------------------------------";
	cout << "\nFirstName:" << FirstName;
	cout << "\nLastName :" << LastName;
	cout << "\nFull Name:" << FullName();
	cout << "\nEmail    :" << Email;
	cout << "\nPhone    :" << Phone;
	cout << "\nAccountNum :" << _AccountNumber;
	cout << "\nPassword :" << _PinCode;
	cout << "\nBalance  :" << _AccountBalance;
	cout << "\n------------------\n";
}
*/


	static clsBankClient Find(string AccountNumber)
	{

		vector<clsBankClient>vClients;
		fstream MyFile;
		MyFile.open("Clients.txt", ios::in); //read Mode

		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsBankClient Client = _ConvertLineToClientObject(Line);
				if (Client.GetAccountNumber() == AccountNumber)
				{

					MyFile.close();
					return Client;

				}
				vClients.push_back(Client);
			}

			MyFile.close();

		}

		return _GetEmptyClientObject();
	}


	static clsBankClient Find(string AccountNumber, string PinCode)
	{
		vector<clsBankClient>vClients;

		fstream MyFile;
		MyFile.open("Clients.txt", ios::in);

		if (MyFile.is_open())
		{
			string Line;

			while (getline(MyFile, Line))
			{
				clsBankClient Client = _ConvertLineToClientObject(Line);

				if (Client.GetAccountNumber() == AccountNumber && Client.PinCode == PinCode)
				{
					MyFile.close();
					return Client;

				}
				vClients.push_back(Client);

			}

			MyFile.close();

		}

		return _GetEmptyClientObject();


	}

	enum enSaveResult {
		svFailEmptyObject = 0, svSucceeded = 1, svFaildAccountNumberExists
		= 2
	};


	enSaveResult Save()
	{
		switch (_Mode)
		{
		case enMode::EmptyMode:
		{

			return enSaveResult::svFailEmptyObject;
			break;
		}


		case enMode::UpdateMode:
		{

			_Update();

			return enSaveResult::svSucceeded;
			break;

		}

		case enMode::AddNewMode:
		{
			if (clsBankClient::IsClientExist(_AccountNumber))
			{
				return enSaveResult::svFaildAccountNumberExists;
			}
			else
			{
				_AddNew();
				_Mode = enMode::UpdateMode;
				return enSaveResult::svSucceeded;

			}
			break;
		}

		}
	}

	static clsBankClient GetAddNewClientObject(string AccountNumber)
	{
		return clsBankClient(enMode::AddNewMode, "", "", "", "", AccountNumber, "", 0);


	}


	bool Delete()
	{

		vector<clsBankClient> _vClients;
		_vClients = _LoadClientDataFromFile();

		for (clsBankClient& C : _vClients)
		{

			if (C.GetAccountNumber() == _AccountNumber)
			{

				C._MarkedForDeleted = true;
				break;

			}


		}

		_SaveClientDataToFile(_vClients);

		*this = _GetEmptyClientObject();

		return true;

	}

	static vector<clsBankClient>GetClientList()
	{

		return _LoadClientDataFromFile();

	}

	static bool IsClientExist(string AccountNumber)
	{
		clsBankClient Client1 = clsBankClient::Find(AccountNumber);

		return(!Client1.IsEmpty());

	}


	static double GetTotalBalances()
	{

		vector<clsBankClient>vClients = clsBankClient::GetClientList();


		double TotalBalances = 0.0;

		for (clsBankClient Client : vClients)
		{

			TotalBalances += Client.AccountBalance;

		}

		return TotalBalances;
	}


	void Deposit(double Amount)
	{
		_AccountBalance += Amount;

		Save();
		

	}


	void Withdraw(double Amount)
	{



		_AccountBalance -= Amount;
		Save();


	}



	bool Transfer(float Amount, clsBankClient& DestinationClient,string UserName)
	{

		if (Amount > AccountBalance)
		{
			return false;
		}
		
		Withdraw(Amount);
		DestinationClient.Deposit(Amount);
		_RegisterTransfer(DestinationClient,Amount,UserName);
		return true;

	}



	static vector <stTransferLogRecord> GetTransferLogRecord()
	{
		vector< stTransferLogRecord>vTransferRecord;
		fstream MyFile;
		MyFile.open("TransferLog.txt", ios::in);

		if (MyFile.is_open())
		{
			string Line;
			stTransferLogRecord TransferLogRecord;
			while (getline(MyFile, Line))
			{
				TransferLogRecord=  _ConvertLineToTransferLogRecord(Line);
				vTransferRecord.push_back(TransferLogRecord);
			
			}
			MyFile.close();
		
		}
		return vTransferRecord;
	}

	


};
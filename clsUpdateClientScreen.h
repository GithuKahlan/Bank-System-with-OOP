#pragma once
class clsUpdateClientScreen:protected clsScreen
{


private:

  static	void  _ReadClientInfo(clsBankClient& Client)
	{
		cout << "\n Enter FirstName: ";
		Client.FirstName = clsInputValidate::ReadString();

		cout << "\nEnter LastName :";
		Client.LastName = clsInputValidate::ReadString();

		cout << "\nEnter Email :";
		Client.Email = clsInputValidate::ReadString();

		cout << "\nEnter Phone :";
		Client.Phone = clsInputValidate::ReadString();

		cout << "\nEnter PinCode :";
		Client.PinCode = clsInputValidate::ReadString();

		cout << "\nEnter AccountBalance :";
		Client.AccountBalance = clsInputValidate::ReadFloatNumber();

	}

	static void _PrintClientCard(clsBankClient Client)
	{

		cout << "\Client Card:";
		cout << "\n-------------------------------";
		cout << "\nFirstName:" << Client.FirstName;
		cout << "\nLastName :" << Client.LastName;
		cout << "\nFull Name:" << Client.FullName();
		cout << "\nEmail    :" << Client.Email;
		cout << "\nPhone    :" << Client.Phone;
		cout << "\nAccountNum :" << Client.GetAccountNumber();
		cout << "\nPassword :" << Client.PinCode;
		cout << "\nBalance  :" << Client.AccountBalance;
		cout << "\n------------------\n";

	}

	 


public:

	static void ShowUpdateClientScreen()
	{

		if (!CheckAccessRights(clsUser::enPermissions::pUpdateClients))
		{
			return;  // this will exit the function and it will not continue


		}



		string Title = "Update Client Screen";
		clsScreen::_DrawScreenHeader(Title);

		string AccountNumber = "";
		cout << "\n Please Enter client Account Number: ";
		AccountNumber = clsInputValidate::ReadString();
		while (!clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "\n Account Number is not found, choose another one: ";
			AccountNumber = clsInputValidate::ReadString();

		}

		clsBankClient Client1 = clsBankClient::Find(AccountNumber);
		_PrintClientCard(Client1);

		cout << "\n\n Update Client Info:";
		cout << "\n --------------------\n";

		_ReadClientInfo(Client1);

		clsBankClient::enSaveResult SaveResult;

		SaveResult = Client1.Save();

		switch (SaveResult)
		{
		case clsBankClient::enSaveResult::svSucceeded:
		{
			cout << "\n Account Updated Successfully:-)\n";
			_PrintClientCard(Client1);
			break;
		}

		case clsBankClient::enSaveResult::svFailEmptyObject:
		{
			cout << "\n Error account was not saved because it's empty";
			break;
		}

		}

	}

};


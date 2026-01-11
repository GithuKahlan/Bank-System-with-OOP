#pragma once
#include<iostream>
#include<string>
using namespace std;


class InterfaceCommunication
{


public:

	void virtual SendEmail(string Title, string Boday) = 0;
	void virtual SendFax(string Title, string Boday) = 0;
	void virtual SendSMS(string Title, string Boday) = 0;


};


#ifndef CONTACT_H
#define CONTACT_H

#pragma once
#include <algorithm>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
using namespace std;

class Contact{
		friend ostream& operator<<(ostream& out, Contact &C);//done
		friend istream& operator>>(istream& in, Contact &C);
	public:
		Contact(string name1 = "", string email1="", string phone1="", string city1="", string relative1="");
		string getName();
		string getEmail();
		string getPhone();
		string getCity();
		string getRelative();
		void setName (string name);
		void setEmail (string email);
		void setPhone (string phone);
		void setCity (string city);
		void setRelative (string relative);
		void readLine(string line);
		void display();
		void addNewContact();
	private:
		string name;
		string email;
		string phone;
		string city;
		string relative;		
};

#endif
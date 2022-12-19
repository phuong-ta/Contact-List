#include "Contact.h"

Contact::Contact(string name1, string email1, string phone1, string city1, string relative1):name(name1), email(email1), phone(phone1), city(city1), relative(relative1){}

string Contact::getName(){
	return name;
}

string Contact::getEmail(){
	return email;
}
string Contact::getPhone(){
	return phone;
}
string Contact::getCity(){
	return city;
}
string Contact::getRelative(){
	return relative;
}
void Contact::setName(string name){
	this->name=name;
}
void Contact::setEmail (string email){
	this->email=email;
}
void Contact::setPhone (string phone){
	this->phone=phone;
}
void Contact::setCity (string city){
	this->city=city;
}
void Contact::setRelative (string relative){
	this->relative=relative;
}

ostream &operator << (ostream &out, Contact &C){
	out <<C.getName() << ':' << C.getEmail() << ':' << C.getPhone() << ':' << C.getCity()<< ':' << C.getRelative() <<'\n';
	return out;
}
istream &operator >> (istream& in, Contact &C){
	getline(in, C.name,':');
	getline(in, C.email,':');
	getline(in, C.phone,':');
	getline(in, C.city,':');
	getline(in, C.relative);
	return in;
}

void Contact::display(){
	cout.width(25); cout << left << name;
	cout.width(25); cout << left << email;
	cout.width(20); cout << left << phone;
	cout.width(20); cout << left << city;
	cout.width(20); cout << left << relative;
}

void Contact::addNewContact(){
	string tmp;
	cout << "Enter new contact"<<endl;
	
	cout << "Enter name:";
	getline(cin, name);
	
	cout << "Enter email:";
	getline(cin, email);
	
	cout << "Enter phone:";
	getline(cin, phone);
	
	cout << "Enter city:";
	getline(cin, city);
	
	cout << "Enter relative:";
	getline(cin, relative);
}

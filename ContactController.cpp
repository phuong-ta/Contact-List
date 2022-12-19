#include "ContactController.h"

ContactController::ContactController(){
	list.clear();
}

// each change from list will be saved to DB
void ContactController::saveToDB(){
	fstream file;
	file.open("database.txt", ios::out);
	if (!file){
		cout << "Can not open file" << endl;
	}else{
		if(!list.empty()){
			sort(list.begin(), list.end(),[]( Contact c1, Contact c2) {return c1.getName() < c2.getName();});
			for (auto& s : list){
				file<<s;
			}
		}
		file.close();
		list.clear();
	}
}

// clear list --> add data from DB to lsit via Contact class
void ContactController::readDB(){
	list.clear();
	Contact newContact;
  	string line, name, email, phone, city, relative;
	ifstream myfile ("database.txt");
	int counter =0;
	if (myfile.is_open()){
		while(getline (myfile,line)){
			istringstream ss(line);
			ss>>newContact;
	    	list.push_back (newContact);
		}
	    myfile.close();
	}else{
	  	std::cout << "Unable to open file"; 
	}
}

// ask user--> if yes --> clear list--> call savetoDB(). if no-> nothing change
void ContactController::createDB(){
	string choice;
	cout << "Create new database, all previous data will deleted" <<endl;
	cout << "Do you want to create new data base?" <<endl;
	cout << "1: yes" <<endl;
	cout << "Else: no" <<endl;
	getline(cin, choice);
	if(choice =="1"){
		list.clear();
		this->saveToDB();
	}else{
		cout << "can not create new db" <<endl;
	}
}

// call readDB()--> print results via method display of Contact class
void ContactController::printList(){
	cout.width(25); cout << left << "Name";
	cout.width(25); cout << left << "Email";
	cout.width(20); cout << left << "Phone number";
	cout.width(20); cout << left << "City";
	cout.width(20); cout << left << "Relative";
	cout<<endl;
	this->readDB();
	for (auto& s : list){
		s.display();
		cout<<endl;
	}
	list.clear();
}

// add new contact via method addNewContact() from Contact Class --> add data from DB to list--> add new contact to list--> save to DB
void ContactController::addContact(){
	Contact newContact;
	newContact.addNewContact();
	list.clear();
	this->readDB();
	list.push_back (newContact);
	this->saveToDB();
}

// clear Contact list-> read from DB--> remove--> save to DB
void ContactController::removeContact(){
	string name;
	cout << "Enter name: ";
	getline(cin, name);
	this->readDB();
	list.erase(remove_if(list.begin(), list.end(), [name](Contact& contact) {return contact.getName() == name;}), list.end());
	this->saveToDB();
}

// get data from database.txt -> check city-> clear list
void ContactController::checkCity(){
	string city;
	cout << "Enter city name: ";
	getline(cin, city);

	cout.width(25); cout << left << "Name";
	cout.width(25); cout << left << "Email";
	cout.width(20); cout << left << "Phone number";
	cout.width(20); cout << left << "City";
	cout.width(20); cout << left << "Relative";
	cout<<endl;
	this->readDB();
	for (auto& s : list){
		if(s.getCity()==city){
			s.display();
			cout<<endl;
		}
	}
	list.clear();
}
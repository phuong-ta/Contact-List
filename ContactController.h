#ifndef CONTACTCONTROLLER_H
#define CONTACTCONTROLLER_H
#include "Contact.h"
class ContactController{
	public:
		ContactController();
		void printList();
		void readDB();
		void createDB();
		void saveToDB();
		void addContact();
		void removeContact();
		void checkCity();
	private:
		vector<Contact> list;
};

#endif
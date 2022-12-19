#include <iostream>
#include "Contact.h"
#include "ContactController.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
void listChoice(){
	cout <<endl;
	cout << "1: Create new Data base" <<endl;
	cout << "2: Print contact list" <<endl;
	cout << "3: Add new person" <<endl;
	cout << "4: Remove person from list" <<endl;
	cout << "5: Find person from city" <<endl;
	cout << "Else: Quit" <<endl;
	cout<<endl;
}

int main(int argc, char** argv) {
	ContactController ctl;
	
	string choice ="1";
	while(choice != "0"){
		listChoice();
		cout << "Enter your choice:";
		getline(cin, choice);
		cout<<endl;
		if(choice=="1"){
			ctl.createDB();
		}else if(choice =="2"){
			ctl.printList();
		}else if(choice =="3"){
			ctl.addContact();
		}else if(choice =="4"){
			ctl.removeContact();
		}else if(choice =="5"){
			ctl.checkCity();
		}else{
			cout << "See you again!" <<endl;
			break;
		}
	}	
	return 0;
}
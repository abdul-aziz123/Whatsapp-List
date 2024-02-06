#include <iostream>
#include <unistd.h>
#include <fstream>
#include <queue>
#include <string>
#include <windows.h>
#include "Singlylist.h"
#include "Hashtable.h"
#include "stack.h"
#include <ctime>

using namespace std;


void addContacts(LinkedList &contactsList, HashTable &hashTable);
void searchContacts(HashTable &hashTable);
void deltContacts(LinkedList &contactsList);
void displayContacts(LinkedList &contactsList);
void updateContacts(LinkedList &contactsList);
void chatWithUsers(LinkedList &contactsList,string username,Stack &stack);
void disp_recentChats(Stack &stack);

int main() {
	cout<<"\n\n\n\n\n\n\n\t\t\t\t\t    WelCome To The WhatsApp List\n";
	cout<<"\t\t\t\t\t   ------------------------------";
	
	start:
	int choice;
	string username,usernumber;
	while(choice != 1 && choice != 2) {
		string line;
		sleep(2);
		system("cls");
		cout<<"1.Create account."<<endl;
		cout<<"2.Log in."<<endl;
		cout<<"0.Exit."<<endl;
		cout<<"Enter: ";
		cin>>choice;
		if(choice == 1) {
			bool flag = false;
			cout<<"Enter username: ";
			cin.ignore();
			getline(cin,username);
			cout<<"Enter number: ";
			cin>>usernumber;
			ifstream in("All Accounts.txt",ios::in);
			if(in.is_open()) {
				while(getline(in,line)) {
					if(line == username || line == usernumber) {
						flag = true;
						break;
					}
				}
			}
			in.close();
			if(!flag) {
				ofstream out("All Accounts.txt",ios::app);
				out<<username<<endl<<usernumber<<endl;
				out.close();
				system("cls");
				cout<<"\n\n\n\n\n\n\n\t\t\t\t     Your account has been created successfully!";
				sleep(3);
			} else {
				cout<<"Error: Already occupied username/number!"<<endl;
				choice = -1;
			}
		} else if(choice == 2) {
			bool found = false;
			cout<<"Enter username: ";
			cin.ignore();
			getline(cin,username);
			cout<<"Enter number: ";
			cin>>usernumber;
			ifstream in("All Accounts.txt",ios::in);
			if(in.is_open()) {
				while(getline(in,line)) {
					if(line == username) {
						getline(in,line);
						if(line == usernumber) {
							found = true;
							break;
						}
					}
				}
			}
			in.close();
			if(found) {
				goto main;
			} else {
				cout<<"Error: Invalid username/number!"<<endl;
				choice = -1;
			}
		} else if(choice == 0) {
			exit(0);
		} else {
			cout<<"Error: Invalid input!"<<endl;
		}
	}
main:

	string line1,line2;
	LinkedList contactsList;
	HashTable hashTable;
	Stack stack;
	string fileName = username + "Contacts.txt";
	ifstream in(fileName.c_str(),ios::in);
	if(in.is_open()) {
		while(getline(in,line1)) {
			getline(in,line2);
			contactsList.insertAtTail(line1,line2);
		}
	}
	in.close();

	string tempstring1,tempstring2,tempstring3;
	string stckFile = username + " Recent Chats.txt";
	node *temp = contactsList.getHead();
	while(temp != NULL) {
		hashTable.insertAtTable(temp->name, temp);
		temp = temp->next;
	}
	ifstream in2(stckFile.c_str(),ios::in);
	if(in2.is_open()) {
		while(getline(in2,line1)) {
			tempstring1 = line1;
			getline(in2,line1);
			tempstring2 = line1;
			getline(in2,line1);
			tempstring3 = line1;
			stack.push(tempstring1,tempstring2,tempstring3);
		}
	}
	in2.close();
	while(1) {
		system("cls");
		cout<<"\t\t\t\t\t   WelCome To The WhatsApp List\n\n";
		cout<<"1.Add Contacts.\n";
		cout<<"2.Search Contacts.\n";
		cout<<"3.Display Last Used Chat.\n";
		cout<<"4.Display saved contacts.\n";
		cout<<"5.Delete contacts.\n";
		cout<<"6.Update contacts.\n";
		cout<<"7.Chat with users.\n";
		cout<<"0.Exit.\n";
		cout<<"Enter your choice: ";
		cin>>choice;
		ofstream out(fileName.c_str(),ios::out);
		ofstream stackout(stckFile.c_str(),ios::out);
		switch(choice) {
			case 0:
				contactsList.saveInFile(out);
				out.close();
				goto start;
				break;
			case 1:
				addContacts(contactsList, hashTable);
				contactsList.saveInFile(out);
				out.close();
				break;
			case 2:
				searchContacts(hashTable);
				out.close();
				break;
			case 3:
				disp_recentChats(stack);
				break;
			case 4:
				displayContacts(contactsList);
				contactsList.saveInFile(out);
				out.close();
				break;
			case 5:
				deltContacts(contactsList);
				contactsList.saveInFile(out);
				out.close();
				break;
			case 6:
				updateContacts(contactsList);
				contactsList.saveInFile(out);
				out.close();
				break;
			case 7:
				chatWithUsers(contactsList,username,stack);
				stack.saveinFile(stackout);
				stackout.close();
				break;
			default:
				system("cls");
				cout<<"\n\n\n\n\n\n\n\t\t\t\t\t    Error: Invalid Input!\n";
				sleep(3);
				contactsList.saveInFile(out);
				out.close();
		}
	}
	return 0;
}


void addContacts(LinkedList &contactsList, HashTable &hashtable) {
	ofstream out("TempFile.txt",ios::app);   //Temporary file
	system("cls");
	cout<<"Add contacts:-"<<endl;
	cout<<"------------"<<endl;

	string number,name,line;
	bool flag = false;

	cout<<"Enter name: ";
	cin.ignore();
	getline(cin,name);
	cout<<"Enter number: ";
	cin>>number;
	ifstream in("All Accounts.txt",ios::in);
	while(getline(in,line)) {
		if(line == name) {
			getline(in,line);
			if(line == number) {
				flag = true;
				break;
			}
		}
	}
	in.close();
	if(flag) {
		if(contactsList.search(name,number)) {
			cout<<"Error: Same name/number of contacts cannot be saved more than twice"<<endl;
			system("pause");
		} else {
			contactsList.insertAtTail(name,number);
			node *newNode = contactsList.getTail();
			hashtable.insertAtTable(name, newNode);
			out<<name<<endl<<number<<endl;
			out.close();
			system("cls");
			cout<<"\n\n\n\n\n\n\n\t\t\t\t     This contact has been saved successfully!";
			sleep(3);
		}
	} else {
		cout<<"Error: This contact does not exist!"<<endl;
		system("pause");
	}
}

void deltContacts(LinkedList &contactsList) {
	system("cls");
	cout<<"Delete contacts:-"<<endl;
	cout<<"----------------"<<endl;
	cout<<"(Note: Enter exact name that is present in the saved contacts.)"<<endl;
	string name;
	cout<<"Enter name: ";
	cin.ignore();
	getline(cin,name);
	contactsList.deleteNode(name);
}

void displayContacts(LinkedList &contactsList) {
	system("cls");
	cout<<"Saved Contacts:-"<<endl;
	cout<<"---------------"<<endl;
	contactsList.display();
}

void updateContacts(LinkedList &contactsList) {
	string name,number;
	system("cls");
	cout<<"Update Contacts:-"<<endl;
	cout<<"---------------"<<endl;
	cout<<"(Note: Enter exact letters which are present in the saved contacts.)"<<endl;
	cout<<"Enter name: ";
	cin.ignore();
	getline(cin,name);
	cout<<"Enter number: ";
	cin>>number;
	contactsList.updateNode(name,number);
}


void searchContacts(HashTable &hashTable) {
	system("cls");
	cout << "Search Contacts:-" << endl;
	cout << "----------------" << endl;
	cout << "(Note: Enter exact letters which are present in the saved contacts.)" << endl;

	string name;
	cout << "Enter name: ";
	cin.ignore();
	getline(cin, name);

	node* result = hashTable.searchAtTable(name);

	if (result != NULL) {
		cout << "Contact Found!" << endl;
		cout << "Name: " << result->name << endl;
		cout << "Number: " << result->number << endl;
	} else {
		cout << "Contact not found." << endl;
	}

	system("pause");
}

void chatWithUsers(LinkedList &contactsList, string username, Stack &stack) {
	system("cls");
	cout << "Chat with users:-" << endl;
	cout << "----------------" << endl;

	string name, number;
	cout << "Enter name to whom you want to chat: ";
	cin.ignore();
	getline(cin, name);
	node* tempnode = contactsList.searchbyname(name);

	if (tempnode == NULL) {
		cout << "Error: This contact is not saved in your contacts list!" << endl;
	} else {
		system("cls");

		string msg;
		bool flag = false;
		cout << "Chat with " << name << ":- (Note: To exit chat, enter 'exit'.)" << endl;
		string fileName = username + " chat with " + name + ".txt";

		if (GetFileAttributes(fileName.c_str()) != INVALID_FILE_ATTRIBUTES) {
			flag = true;
		} else {
			fileName = name + " chat with " + username + ".txt";
			if (GetFileAttributes(fileName.c_str()) != INVALID_FILE_ATTRIBUTES) {
				flag = true;
			}
		}

		if (flag) {
			ifstream in(fileName.c_str(), ios::in);
			string line;
			while (getline(in, line)) {
				cout << line << endl;
			}
			in.close();
		}

		ofstream out(fileName.c_str(), ios::app);
		cout << "Start chatting:- " << endl;

		queue<string> chatQueue; // Queue to store chat messages

		stack.push(name, __DATE__, __TIME__);
		
		do {
			getline(cin, msg);
			if (msg != "exit" && msg != "Exit") {
				chatQueue.push(username + ": " + msg); // Enqueue chat message
			}
		} while (msg != "exit" && msg != "Exit");

		// Dequeue and write chat messages to the file
		while (!chatQueue.empty()) {
			out << chatQueue.front() << endl;
			chatQueue.pop();
		}

		out.close();
	}

	system("pause");
}

void disp_recentChats(Stack &stack) {
	if(stack.isEmpty()) {
		cout<<"No chats has been done!"<<endl;
	} else {
		system("cls");
		cout << "Last Chats:-" << endl;
		cout << "-------------" << endl;
		Stack tempstack = stack;
		stackNode* temp;
		while(!tempstack.isEmpty()) {
			temp = tempstack.getTop();
			cout<<temp->name<<" (date: "<<temp->date<<" , time: "<<temp->time<<")"<<endl;
			tempstack.pop();
		}
	}
	system("pause");
}
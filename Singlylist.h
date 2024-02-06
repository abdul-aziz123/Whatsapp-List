#include <iostream>
#include <unistd.h>
#include <fstream>
using namespace std;

class node
{
	public:
		string name;
		string number;
		node* next;
		node()
		{
			next = NULL;
		}
		node(string name,string number)
		{
			this->name = name;
			this->number = number;
			next = NULL;
		}
		node(string name,string number,node* nxt)
		{
			this->name = name;
			this->number = number;
			next = nxt;
		}
};

class LinkedList
{
	private:
		node* head;
		node* tail;
	public:
		LinkedList()
		{
			head = NULL;
			tail = NULL;
		}
		void addHeadNode(string name,string number)
		{
			if(head == NULL)
			{
				head = tail = new node(name,number);
			}
			else
			{
				node *temp = new node(name,number);
				temp->next = head;
				head  = temp;
			}
		}
		void insertAtTail(string name,string number)
		{
			if(head == NULL)
			{
				head = tail = new node(name,number);
			}
			else
			{
				tail->next = new node(name,number);
				tail = tail->next;
			}
		}
		void deleteNode(string nam)
		{
			if(head == NULL)
			{
				system("cls");
				cout<<"\n\n\n\n\n\n\n\t\t\t\t\t    None contacts are saved already!";
	            sleep(3);
			}
			else
			{
				bool found = false;
				node* temp = head;
				node* prev = NULL;
				while(temp!=NULL)
				{
					if(temp->name == nam)
					{
						if(temp == head)
						{
							head = head->next;
							delete temp;
							found = true;
						}
						else
						{
							prev->next = temp->next;
							delete temp;
							found = true;
						}
						system("cls");
				        cout<<"\n\n\n\n\n\n\n\t\t\t\t     This contact has been deleted successfully!";
	                    sleep(3);
						break;
					}
					prev = temp;
					temp = temp->next;
				}
				if(!found)
				{
					system("cls");
				    cout<<"\n\n\n\n\n\n\n\t\t\t\t     This contact is not present in the list!";
	                sleep(3);
				}
			}
		}
		void updateNode(string nam,string num)
		{
			if(head == NULL)
			{
				system("cls");
				cout<<"\n\n\n\n\n\n\n\t\t\t\t\t    No contacts are saved!";
	            sleep(3);
			}
			else
			{
				bool found = false;
				node* temp = head;
				while(temp!=NULL)
				{
					if(temp->name == nam && temp->number == num)
					{
						found = true;
						cout<<endl<<"Name: "<<temp->name<<". Number: "<<temp->number<<"."<<endl;
						cout<<"Re-enter the name: ";
						cin.ignore();
						getline(cin,temp->name);
						cout<<"Re-enter the number: ";
						cin>>temp->number;
						system("cls");
				        cout<<"\n\n\n\n\n\n\n\t\t\t\t     This contact has been updated successfully!";
	                    sleep(3);
						break;
					}
					temp = temp->next;
				}
				if(!found)
				{
					system("cls");
				    cout<<"\n\n\n\n\n\n\n\t\t\t\t     This contact is not present in the list!";
	                sleep(3);
				}
			}
		}
		void display()
		{
			if(head == NULL)
			{
				system("cls");
				cout<<"\n\n\n\n\n\n\n\t\t\t\t\t    No contacts are saved!";
	            sleep(3);
			}
			else
			{
				node* temp = head;
				while(temp!=NULL)
				{
					cout<<"Name: "<<temp->name<<endl<<"Number: "<<temp->number<<endl<<endl;
					temp = temp->next;
				}
				system("pause");
			}
		}
		void saveInFile(ofstream &out)
		{
			node* temp = head;
			while(temp!=NULL)
			{
				out<<temp->name<<endl<<temp->number<<endl;
				temp = temp->next;
			}
		}
		
		node *getTail()
		{
			node *temp = head;
			while(temp->next != NULL)
			{
				temp = temp->next;
			}
			return temp;
		}
		
		node *getHead()
		{
			return head;
		}
		
		node* search(string name,string number)
		{
			if(head == NULL)
			{
				return NULL;
			}
			else
			{
				node* temp = head;
				while(temp != NULL)
				{
					if(temp->name == name && temp->number == number)
					{
						return temp;
					}
					temp = temp->next;
				}
				return temp;
			}
		}
		node* searchbyname(string name)
		{
			if(head == NULL)
			{
				return NULL;
			}
			else
			{
				node* temp = head;
				while(temp!=NULL)
				{
					if(temp->name == name)
					{
						return temp;
						break;
					}
					temp = temp->next;
				}
				return NULL;
			}
		}
};


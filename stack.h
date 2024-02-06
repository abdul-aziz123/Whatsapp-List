#include<iostream>
#include <fstream>
using namespace std;

class stackNode
{
	public:
		string name,date,time;
		stackNode* next;
		stackNode()
		{
			next = NULL;
		}
		stackNode(string name)
		{
			this->name = name;
			next = NULL;
		}
		stackNode(string name,string date,string time)
		{
			this->name = name;
			this->date = date;
			this->time = time;
			next = NULL;
		}
		stackNode(string name,string date,string time,stackNode* next)
		{
			this->name = name;
			this->date = date;
			this->time = time;
			this->next = next;
		}
};

class Stack
{
	private:
		stackNode* top;
	public:
		Stack()
		{
			top = NULL;
		}
		void push(string name,string date,string time)
		{
			if(top = NULL)
			{
				top = new stackNode(name,date,time);
			}
			else
			{
				top = new stackNode(name,date,time,top);
			}
		}
		void pop()
		{
			stackNode* temp = top;
			top = top->next;
			delete temp;
		}
		bool isEmpty()
		{
			if(top == NULL)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		stackNode* getTop()
		{
			return top;
		}
		void saveinFile(ofstream &out)
		{
			if(top == NULL)
			{
				return;
			}
			else
			{
				stackNode* temp = top;
				while(temp != NULL)
				{
					out<<temp->name<<endl<<temp->date<<endl<<temp->time<<endl;
					temp = temp->next;
				}
			}
		}
};

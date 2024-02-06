#include <iostream>
#include <unistd.h>
#include <fstream>
using namespace std;


class HashNode
{
public:
	string name;
	node *data;
	HashNode *next;
	
	HashNode(string name , node *data)
	{
		this->name = name;
		this->data = data;
		this->next = NULL;
	}
};

const int hashTable_Size = 100;

class HashTable
{
	HashNode **table;
	int size;
	
	int HashFunc1(string& Name)
	{
		int hash = 0;
		for(int i=0 ; i<Name.length() ; i++)
		{
			char ch = Name[i];
			hash = (hash * 20 + ch) % size;	
		}
		
		return hash;
		
	}
	
	int HashFunc2(string& Name)
	{
		int hash = 0;
		for(int i=0 ; i<Name.length() ; i++)
		{
			char ch = Name[i];
			hash = (hash * 26 + ch) % size;	
		}
		if(hash == 0)
		{
			return 1;
		}
		
		return hash;
	}	
	
	int DoubleHashing(string& name , int i)		//i is how many time it had attemoted to get on index but it was filled already
	{
		return(HashFunc1(name) + i * HashFunc2(name)) % size;	
	} 
		
public:
	HashTable(int Size = hashTable_Size)
	{
		this->size = Size;
		table = new HashNode *[hashTable_Size];
	}
	
	void insertAtTable(string& name , node *data)
	{
		int index = HashFunc1(name);
		int attempt = 0;
		
		while(table[index] != NULL)		//if index is already Occupied , Collision Occurred
		{
			attempt++;
			index = DoubleHashing(name , attempt);
		}
		HashNode * newNode = new HashNode(name , data);
		table[index] = newNode;
	}
	
	node *searchAtTable(string &name)
	{
		int index = HashFunc1(name);
		int attempt = 0;
		
		HashNode *current = table[index];
		while(current != NULL)
		{
			if(current->name == name)
			{
				return current->data;
			}
			
			attempt++;
			index = DoubleHashing(name , attempt);
			
			if(attempt >= size)
			{
				cout<<"Unable to find the Contact"<<endl;
				return NULL;
			}
		}
		cout<<"Unable to find the Contact"<<endl;
		return NULL;
	}
		
};

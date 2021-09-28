#include <iostream>
using namespace std;



/*
Source code for singly linked list
*/


// represent single node of our list
struct node
{
	int key;
	node* next = NULL;
};

typedef struct node node;


class SinglyLinkedList{
public:
	node* root = new node;

	SinglyLinkedList(){   // default constructor, initializes data member
		root = NULL;
	}
	SinglyLinkedList(int val){  // parameterised constructor 
		root->key = val;
	}
	
	// inserts node at the end of the list
	void insert(int val){   
		if (!root){
			root = new node;
			root->key = val;
		}
		else{
			node* thisnode = root;
			while(thisnode->next){
				thisnode = thisnode->next;
			}
			thisnode->next = new node;
			thisnode->next->key = val;
		}
	}

	//remove node with given key, if exists
	void remove(int val){
		node* thisnode = root, *prevnode = NULL;
		while (thisnode){
			if (thisnode->key == val){
				if (prevnode){
					prevnode->next = thisnode->next;
				}
				else
					root = thisnode->next;
				return;
			}
			prevnode = thisnode;
			thisnode = thisnode->next;
		}
		cout<<"Value not found"<<endl;
	}

	//display the list
	void display(){
		node* thisnode = root;
		while(thisnode){
			cout<<thisnode->key<<"->";
			thisnode = thisnode->next;
		}
		cout<<"NULL"<<endl;
	}	
};

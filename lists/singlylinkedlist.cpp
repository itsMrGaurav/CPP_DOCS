/*
Source code for singly linked list
*/

#include <iostream>
using namespace std;



struct Node 															// represents a single node 
{
	int key;
	Node* next = NULL;
	Node(){
		key = -1;
	}
	Node(int val){
		key = val;
	}
};

typedef struct Node Node;


class SinglyLinkedList{
public:
	Node* root = new Node;

	SinglyLinkedList(){   
		root = NULL;
	}
	SinglyLinkedList(int key){  
		root = new Node(key);
	}
	

	void insert(int key){   											// to insert a new node
		if (!root){														// creates root if non existant
			root = new Node(key);
		}
		else{															// else insert after root
			Node* node = new Node(key);
			node->next = root->next;
			root->next = node;
		}
	}

	
	void remove(int key){ 												// remove node with given key, if exists
		Node* thisnode = root, *prevnode = NULL;
		while (thisnode){
			if (thisnode->key == key){
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
		cout<<"Node not found"<<endl;
	}

	void display(){														// display the list
		Node* thisnode = root;
		while(thisnode){
			cout<<thisnode->key<<"->";
			thisnode = thisnode->next;
		}
		cout<<"NULL"<<endl;
	}	
};


int main(int argc, char const *argv[])
{
	SinglyLinkedList ls;
	ls.insert(12);
	ls.insert(13);
	for (int i = 14; i < 20; ++i)
	{
		ls.insert(i);
	}
	ls.remove(12);
	ls.remove(15);
	ls.display();
	return 0;
}
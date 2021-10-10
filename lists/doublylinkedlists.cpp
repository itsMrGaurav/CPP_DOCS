/*
	Source code to create a doubly linked list
*/

# include <iostream>
using namespace std;


struct Node{														// represents single node in the list
	int key;
	Node *next = NULL, *prev = NULL;
	Node(){
		key = -1;
	}
	Node(int val){
		key = val;
	} 
};

typedef struct Node Node;

class DoublyLinkedList{     										// creates a doubly linked list object
public:
	Node* root = new Node;
	DoublyLinkedList(){
		root = NULL;
	}
	DoublyLinkedList(int key){
		root = new Node(key);
	}

	void insert(int key){                                         	// to insert a new node
		
		if (!root){													// creates a root if it dosen't exist                        
			root = new Node(key); 
		}

		else {                                                    	// else add a new node right after root 
			Node *nextnode = new Node, *node = new Node(key);       
			node->next = root->next;
			root->next = node;
			node->prev = root;
			if (node->next)
				node->next->prev = node;
		}
	}

	void remove(int key){ 											// removes node if it exists in the list
		Node* thisnode = root, *prevnode = NULL;
		while (thisnode){
			if (thisnode->key == key){
				if (prevnode){
					prevnode->next = thisnode->next;
					if (thisnode->next)	
						thisnode->next->prev = prevnode;
				}
				else{
					root->next->prev = NULL;
					root = root->next;
				}
				return;
			}
			prevnode = thisnode;
			thisnode = thisnode->next;
		}
		cout<<"Node not found"<<endl;
	}

	void display(){													// displays the list
		Node* thisnode = root;
		cout<<"NULL";
		while (thisnode){
			cout<<"<-"<<thisnode->key<<"->";
			thisnode = thisnode->next;
		}
		cout<<"NULL"<<endl;
	}	
};



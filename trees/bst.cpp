/*
Binary search tree implementation in C++
*/


#include <iostream>
#include <math.h>
#include <cmath>
#include <string>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <map>
#include <iterator>


using namespace std;


class BST
{
public:
	int key;   // holds value of each node
	BST *left, *right;     // ptr for left and right nodes 
	int leftnodes, rightnodes;   // keeping track of number of nodes in left and right subtree
	BST(){                        // default constructor , initializes data members  
		key = -1;
		left = NULL;
		right = NULL;
		leftnodes = rightnodes = 0;
	} 
	BST(int val){                  // parameterised constructor
		key = val;
		left = NULL;
		right = NULL;
		leftnodes = rightnodes = 0;	
	}
};


// insert nodes into the tree
void insert(BST* &root, int val){
	
	BST *node = new BST(val);   //first create new node with value passed
	
	if (root == NULL){          // if head/root dosen't exist, create it
		root = node;
		return;
	}

	BST *thisnode = root;       // set a pointer to head and traverse the tree for suitable position 
								// to insert new node
	while(1){                   
		
		if (val <= thisnode->key){    
			thisnode->leftnodes += 1;
			if (thisnode->left) thisnode = thisnode->left;   // if left exists, look in left
			else {
				thisnode->left = node;                      // else set new node as thisnode
				return;
			}
		}
		else {
			thisnode->rightnodes += 1;                     // if right exists, look into right else
			if (thisnode->right) thisnode = thisnode->right;
			else {
				thisnode->right = node;                    // else insert new node right there
				return;
			}
		}
	}
}

// traversing root in increasing order
void inOrderTraversal(BST* &root){

	// if reached to the end, return
	if (root->left == NULL && root->right == NULL) {
		cout<<root->key<<' ';
		return;
	}

	// if left exists, keeep looking into left
	if (root->left != NULL){
		inOrderTraversal(root->left);
	}

	//print head key
	cout<<root->key<<' ';

	// if right exists, keep looking into right
	if (root->right != NULL){
		inOrderTraversal(root->right);
	}
	return; 
}


// get the height of the tree
int getHeight(BST* &root){
	int height = 0;

	// if root has left or right child, increase height
	if (root->left || root->right){
		height++;
	}
	int h1 = 0, h2 = 0;

	// ask for height from left and right subtree 
	if (root->left)
		h1 = getHeight(root->left);

	if (root->right)
		h2 = getHeight(root->right);

	// add the maximum of those two and return the result
	height += (h1>=h2?h1:h2);
	return height;
}



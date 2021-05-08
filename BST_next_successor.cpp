// BST_next_successor.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
using namespace std;

struct Node{
	int val;
	struct Node* left;
	struct Node* right;
};


class solution {
public:

	Node* findNode(Node* node, int data) {

		if (node->val < data) findNode(node->right, data);
		else if(node->val > data) findNode(node->left, data);
		else return node;
	}

	Node* findMin(Node* node) {
		//if (!node) return NULL;
		while (node->left) node = node->left;
		return node;
	}

	Node* getSuccessor(Node* root, int data) {
		Node* curr = findNode(root, data);
		if (!curr) return NULL;
		if (curr->right) {
			return findMin(curr->right);
		}
		else {
			Node* successor = NULL;
			Node* ancestor = root;
			while (ancestor != curr) {
				if (ancestor->val > curr->val) {
					successor = ancestor;
					ancestor = ancestor->left;
				}
				else ancestor = ancestor->right;
			}
			return successor;
		}
	}

	void inOrder(Node* root) {
		if(!root) return;
		inOrder(root->left);
		printf("%d ", root->val);
		inOrder(root->right);
	}

	Node* Insert(Node *root, int data) {
		if (root == NULL) {
			root = new Node();
			root->val = data;
			root->left = root->right = NULL;
		}
		else if (data <= root->val)
			root->left = Insert(root->left, data);
		else
			root->right = Insert(root->right, data);
		return root;
	}
};

int main()
{
	/*Test code
				5
			   / \
			  4   10
			 /    /\
			1    9  11
			 \	 \
			  2   12

	*/
	solution sol;

	Node* root = NULL;
	root = sol.Insert(root, 5);	cout << root->val << "\n";
	root = sol.Insert(root, 4);
	root = sol.Insert(root, 10); 
	root = sol.Insert(root, 1);
    root = sol.Insert(root, 11); 
	root = sol.Insert(root, 2);
	root = sol.Insert(root, 9); 
	root = sol.Insert(root, 12);

	// Print nodes using inorder traversal
	cout << "inorder traversal: ";
	sol.inOrder(root);
	cout << "\n";

	// Find inorder successor of some node. 
	int search_node = 9;
	struct Node* successor = sol.getSuccessor(root, search_node);
	if (successor == NULL) cout << "No successor Found\n";
	else {
		cout << "Search node is " << search_node << "\n";
		cout << "Successor is " << successor->val << "\n";
	}
		
}


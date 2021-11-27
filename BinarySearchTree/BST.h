#pragma once

struct Node
{
	int key;
	Node* left;
	Node* right;
};

class BST
{
public:
	BST();
	~BST();

	void insert(int);
	void printPreorder();
	void printInorder();
	void printPostorder();
	void printLevelOrder();
	int getHeight();
	int countNodes();
	Node* search(int);
	void deleteNode(int);
	void deleteBST();
	int findHeight(int);
	bool isBST();

private:
	Node* root;

	void insert(Node*&, int);
	void printPreorder(Node*);
	void printInorder(Node*);
	void printPostorder(Node*);
	void printLevelOrder(Node*);
	void printCurrentLevel(Node*, int);
	int getHeight(Node*);
	int countNodes(Node*);
	Node* search(Node*, int);
	Node* deleteNode(Node*&, int);
	Node* minNode(Node*);
	void deleteBST(Node*);
	int findHeight(Node*, int);
	bool isBST(Node*, Node*, Node*);
};

Node* createNode(int key);
#include "BST.h"
#include <iostream>

BST::BST()
{
	root = nullptr;
}

BST::~BST()
{
	deleteBST();
}

void BST::insert(int key)
{
	insert(root, key);
}

void BST::printPreorder()
{
	printPreorder(root);
	std::cout << std::endl;
}

void BST::printInorder()
{
	printInorder(root);
	std::cout << std::endl;
}

void BST::printPostorder()
{
	printPostorder(root);
	std::cout << std::endl;
}

void BST::printLevelOrder()
{
	printLevelOrder(root);
	std::cout << std::endl;
}

int BST::getHeight()
{
	return getHeight(root);
}

int BST::countNodes()
{
	return countNodes(root);
}

Node* BST::search(int key)
{
	return search(root, key);
}

void BST::deleteNode(int key)
{
	root = deleteNode(root, key);
}

void BST::deleteBST()
{
	deleteBST(root);
}

int BST::findHeight(int key)
{
	return findHeight(root, key);
}

bool BST::isBST()
{
	return isBST(root, nullptr, nullptr);
}

void BST::insert(Node*& root, int key)
{
	if (!root)
	{
		root = createNode(key);
	}

	else if (key < root->key)
	{
		if (!root->left)
		{
			root->left = createNode(key);
		}
		else
		{
			insert(root->left, key);
		}
	}
	else if (key > root->key)
	{
		if (!root->right)
		{
			root->right = createNode(key);
		}
		else
		{
			insert(root->right, key);
		}
	}
}

void BST::printPreorder(Node* root)
{
	if (!root) return;

	std::cout << root->key << "\t";
	printPreorder(root->left);
	printPreorder(root->right);
}

void BST::printInorder(Node* root)
{
	if (!root) return;

	printInorder(root->left);
	std::cout << root->key << "\t";
	printInorder(root->right);
}

void BST::printPostorder(Node* root)
{
	if (!root) return;

	printPostorder(root->left);
	printPostorder(root->right);
	std::cout << root->key << "\t";
}

void BST::printLevelOrder(Node* root)
{
	int h = getHeight(root);

	for (int i = 1; i <= h; i++)
	{
		printCurrentLevel(root, i);
	}
}

void BST::printCurrentLevel(Node* root, int level)
{
	if (!root) return;

	if (level == 1)
	{
		std::cout << root->key << "\t";
	}
	else if (level > 1)
	{
		printCurrentLevel(root->left, level - 1);
		printCurrentLevel(root->right, level - 1);
	}
}

int BST::getHeight(Node* root)
{
	if (!root) return 0;

	return 1 + std::max(getHeight(root->left), getHeight(root->right));
}

int BST::countNodes(Node* root)
{
	if (!root) return 0;

	return 1 + countNodes(root->left) + countNodes(root->right);
}

Node* BST::search(Node* root, int key)
{
	if (!root) return nullptr;

	if (key == root->key) return root;
	if (key < root->key) return search(root->left, key);
	return search(root->right, key);
}

Node* BST::deleteNode(Node*& root, int key)
{
	if (!root) return nullptr;

	if (key < root->key) root->left = deleteNode(root->left, key);
	else if (key > root->key) root->right = deleteNode(root->right, key);

	else if (!root->left)
	{
		Node* temp = root->right;

		delete root;
		root = nullptr;
		return temp;
	}
	else if (!root->right)
	{
		Node* temp = root->left;

		delete root;
		root = nullptr;
		return temp;
	}
	else
	{
		Node* min = minNode(root->right);
		root->key = min->key;
		root->right = deleteNode(root->right, min->key);
	}
	return root;
}

Node* BST::minNode(Node* root)
{
	if (!root) return nullptr;

	if (!root->left) return root;

	return minNode(root->left);
}

void BST::deleteBST(Node* root)
{
	if (!root) return;

	Node* currentNode = root;
	Node* leftNode = root->left;
	Node* rightNode = root->right;

	delete currentNode;
	currentNode = nullptr;

	deleteBST(leftNode);
	deleteBST(rightNode);
}

int BST::findHeight(Node* root, int key)
{
	if (!root) return -1;

	if (key == root->key) return getHeight(root);

	if (key < root->key) return findHeight(root->left, key);

	return findHeight(root->right, key);
}

bool BST::isBST(Node* root, Node* min, Node* max)
{
	if (!root) return true;

	if (min && root->key <= min->key) return false;
	if (max && root->key >= max->key) return false;
	return isBST(root->left, min, root) && isBST(root->right, root, max);
}

Node* createNode(int key)
{
	Node* newNode = new Node{ key,nullptr,nullptr };

	return newNode;
}

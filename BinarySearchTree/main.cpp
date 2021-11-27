#include <iostream>
#include "BST.h"

using namespace std;

int main()
{
	BST tree;

	tree.insert(20);
	tree.insert(25);
	tree.insert(15);
	tree.insert(10);
	tree.insert(30);
	tree.insert(18);
	tree.insert(5);

	cout << "Preorder:\t";
	tree.printPreorder();

	cout << "\nInorder:\t";
	tree.printInorder();

	cout << "\nPostorder:\t";
	tree.printPostorder();

	cout << "\nLevel order:\t";
	tree.printLevelOrder();

	cout << "\nHeight of BST: " << tree.getHeight() << endl;

	cout << "Number of nodes: " << tree.countNodes() << endl;

	Node* node = tree.search(18);

	if (node)
	{
		cout << node->key << " is present in the BST." << endl;
	}
	//else 

	int key = 20;

	cout << "Height of " << key << ": " << tree.findHeight(key) << endl;

	cout << "The tree after " << key << " deleted:\nLevel Order:\t";
	tree.deleteNode(20);
	tree.printLevelOrder();
	cout << endl;

	int replaced = 10;
	int value = 17;

	cout << "The tree after replaced " << replaced << " with " << value << ":\nLevel Order:\t";
	tree.search(10)->key = value;
	tree.printLevelOrder();
	cout << endl;

	if (!tree.isBST())
	{
		cout << "The tree is not a BST.";
		cout << endl;
	}
	//else

	system("pause");
	return 0;
}
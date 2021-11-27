#include <iostream>
#include "BST.h"

using namespace std;

int main()
{
	BST tree;
	int key = 0;
	int deleted = 0;
	int value = 0;
	int replaced = 0;

	tree.insert(20);
	tree.insert(25);
	tree.insert(15);
	tree.insert(10);
	tree.insert(30);
	tree.insert(18);
	tree.insert(5);

	cout << "Preorder:\t";
	tree.printPreorder();

	cout << "Inorder:\t";
	tree.printInorder();

	cout << "Postorder:\t";
	tree.printPostorder();

	cout << "Level order:\t";
	tree.printLevelOrder();

	cout << "Height of BST: " << tree.getHeight() << endl;

	cout << "Number of nodes: " << tree.countNodes() << endl;

	Node* node = tree.search(18);

	if (node)
	{
		cout << node->key << " is present in the BST." << endl;
	}
	//else 

	key = 10;
	cout << "Height of " << key << ": " << tree.findHeight(key) << endl;

	deleted = 20;
	cout << "The tree after " << deleted << " deleted:\nLevel Order:\t";
	tree.deleteNode(deleted);
	tree.printLevelOrder();

	replaced = 10;
	value = 17;
	cout << "The tree after replaced " << replaced << " with " << value << ":\nLevel Order:\t";
	tree.search(10)->key = value;
	tree.printLevelOrder();

	if (!tree.isBST())
	{
		cout << "The tree is not a BST.";
		cout << endl;
	}
	//else

	system("pause");
	return 0;
}
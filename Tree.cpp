#include <iostream>
#include <string>
#include "Tree.h"

using namespace std;

Tree::Tree()
{
	root = NULL;
}

void Tree::insert(int v, Node* root)
{
	if (v < root->value)
	{
		if (root->left != NULL)
			insert(v, root->left);
		else
		{
			root->left = new Node;
			root->left->value = v;
			root->left->left = NULL;
			root->left->right = NULL;
		}
	}
	else
	{
		if ( v > root->value)
		{
			if (root->right != NULL)
				insert(v, root->right);
			else
			{
				root->right = new Node;
				root->right->value = v;
				root->right->left = NULL;
				root->right->right = NULL;
			}
		}
	}
}
	
void Tree::replace(Node* t)
{
	if (t->right != NULL)
		replace(t->right);
	else
	{
		root->value = t->value;
		root = t;
		t = t->left;
		free(root);
	}
}

void Tree::destroy_node(int v, Node* root)
{
	if (root == NULL)
		cout << "Node not in tree!";
	else if (v < root->value)
		destroy_node(v, root->left);
	else if (v > root->value)
		destroy_node(v, root->right);
	else
	{
		Node* node = root;
		if (root->left == NULL)
		{
			root = root->right;
			free(node);
		}
		else if (root->right == NULL)
		{
			root = root->left;
			free(node);
		}
		else replace(root->left);
	}
}

string Tree::inorder(Node* root)
{
	string str_right, str_left;
	if (root->left != NULL)
		str_left= inorder(root->left);
	else str_left = "";

	if (root->right != NULL)
		str_right = inorder(root->right);
	else str_right = "";

	return str_right + " " + to_string(root->value) + " " + str_left;
}
	
string Tree::preorder(Node* root)
{
	string str_right, str_left;
	if (root->left != NULL)
		str_left = preorder(root->left);
	else str_left = "";

	if (root->right != NULL)
		str_right = preorder(root->right);
	else str_right = "";

	return to_string(root->value) + " " + str_right + " " + str_left;
}

string Tree::postorder(Node* root)
{
	string str_right, str_left;
	if (root->left != NULL)
		str_left = postorder(root->left);
	else str_left = "";

	if (root->right != NULL)
		str_right = postorder(root->right);
	else str_right = "";

	return str_right + " " + str_left + " " + to_string(root->value);

int Tree::countNodes(int countN, Node* root)
{
	if (root != NULL)
	{
		countNodes(countN, root->left);
		countN++;
		countNodes(countN, root->right);
	}
	return countN;
}

int countEdges(int countE, Node* root)
{
	if (root != NULL)
	{
		countEdges(countE, root->left);
		countE++;
		countEdges(countE, root->right);
	}
	return countE - 1;
}

int Tree::height(Node* root)
{
	if (root == NULL)
		return 0;
	else
	{
		int lHeight = height(root->left);
		int rHeight = height(root->right);
		if (lHeight > rHeight)
			return(lHeight + 1);
		else return (rHeight + 1);
	}
}

int main()
{
	Node* n = new Node();
	Tree * bTree= new Tree();
	
	n->value = 8;
	n->left = NULL;
	n->right = NULL;

	bTree->insert(1,n);
	bTree->insert(2, n);
	bTree->insert(5, n);
	bTree->insert(6, n);
	bTree->insert(7,n);
	bTree->insert(9,n);
	bTree->insert(12, n); 
	bTree->insert(15, n); 
	bTree->insert(16, n);


	cout << bTree->preorder(n);
	return 0;
}

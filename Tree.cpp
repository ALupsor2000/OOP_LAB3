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
	string rightS, leftS;
	if (root->left != NULL)
		leftS = inorder(root->left);
	else leftS = "";

	if (root->right != NULL)
		rightS = inorder(root->right);
	else rightS = "";

	return leftS + " " + to_string(root->value) + " " + rightS;
	/*
	if (root != NULL)
	{
		inorder(root->left);
		string aux = to_string(root->value);
		return aux;
		inorder(root->right);
	}
	*/
}
	
string Tree::preorder(Node* root)
{
	if (root != NULL)
	{
		string aux = to_string(root->value);
		return aux;
		preorder(root->left);
		preorder(root->right);
	}
}

string Tree::postorder(Node* root)
{
	if (root != NULL)
	{
		postorder(root->left);
		postorder(root->right);
		string aux = to_string(root->value);
		return aux;
	}
}

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
	
	n->value = 20;
	n->left = NULL;
	n->right = NULL;

	bTree->insert(10,n);
	bTree->insert(12,n);
	bTree->insert(5,n);
	bTree->insert(30,n);

	cout << bTree->inorder(n);
	return 0;
}

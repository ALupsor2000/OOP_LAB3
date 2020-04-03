#pragma once

//Clasa Node pentru nodurile arboreului binar
class Node
{
public:
	int value;
	Node* left;
	Node* right;
};

//Clasa Tree pentru arborele binar
class Tree
{
public:
	Node* root;

	//Constructor pentru arbore binar
	Tree();

	/*
	 descr: Insereaza un nod nou in arbore, in cazul in care
			 valoarea acestuia nu se regaseste in arbore.
			 In functie de valoare insereaza in partea dreapta(right)
			 sau in partea stanga(left).
	 Input: int v: valoarea care urmeaza sa fie inserata;
			Node* root: radacina de la care pleaca
	 Output: adresa nodului creat, daca radacina e vida
	*/
	void insert(int v, Node* root);

	/*
	 descr: Cauta frunza din dreapta a arborelui
			si inlocuieste valoarea radacinii
			subarborelui cu aceasta. Valoarea
			radicinii urmand sa fie stearsa
	 Input: Node* t, radacina de la care pleaca cautarea
	 Output: Inlocuirea radacinii si dealocarea frunzei din memorie
	*/
	void replace(Node* t);

	/*
	 descr: Sterge un nod cu o valoare data,
			in cazul in care aceasta se afla in arbore.
	 Input: int v: valoarea care urmeaza sa fie eliminata
			Node* root: radacina de la care pleaca cautarea
	 Output: adresa radacinii
	*/
	void destroy_node(int v, Node* root);
	
	/*
	 descr: Parcurgere arbore stanga-radacina-dreapta
	 Input: Node* root: radacina de la care pleaca
	 Output: Afisare
	*/
	string inorder(Node* root);

	/*
	 descr: Parcurgere arbore radacina-stanga-dreapta
	 Input: Node* root: radacina de la care pleaca
	 Output: Afisare
	*/
	string preorder(Node* root);
	
	/*
	descr: Parcurgere arbore stanga-dreapta-radacina
	Input: Node* root: radacina de la care pleaca
	Output: Afisare
	*/
	string postorder(Node* root);

	/*
	 descr: Apeleaza recursiv deplasarea in arbore pentru a numara nodurile
	 Input: int countN = 0: contor pentru noduri
			Node* root: radacina de la care pleaca numerotarea
	 Output: Returneaza numarul de noduri
	*/
	int countNodes(int countN, Node* root);

	/*
	 descr: Apeleaza recursiv deplasarea in arbore pentru a numara muchiile
	 Input: int countN = 0: contor pentru muchii
			Node* root: radacina de la care pleaca numerotarea
	 Output: Returneaza numarul de muchii
	*/
	int countEdges(int countE, Node* root);

	/*
	 descr: Apeleaza recursiv deplasarea in arbore pentru a numara nivelurie
	 Input: Node* root: radacina de la care pleaca numerotarea
	 Output: Returneaza numarul de niveluri
	*/
	int height(Node* root);
};
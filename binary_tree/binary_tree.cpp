#include <iostream>
#include <cmath>
#include <fstream>
#include <string>
using namespace std;

struct Node
{
	int item;
	Node* left;
	Node* right;
};

Node* tree = NULL;
ifstream input("input.txt");
ofstream output("output.txt");

void pushItem(Node** tree, int item) {
	if (*tree) {
		if (item < (*tree)->item) {
			pushItem(&(*tree)->left, item);
		}
		if (item > (*tree)->item) {
			pushItem(&(*tree)->right, item);
		}
	}
	else {
		(*tree) = new Node;
		(*tree)->item = item;
		(*tree)->left = NULL;
		(*tree)->right = NULL;
	}
}

void print(Node* tree)
{
	if (tree) {
		output << tree->item << endl;
		print(tree->left);
		print(tree->right);
	}
}

int main()
{
	string line;
	if (input.is_open()) cout << "ooo" << endl;

	while (getline(input, line))
	{
		pushItem(&tree, stoi(line));
	}

	input.close();
	print(tree);
}
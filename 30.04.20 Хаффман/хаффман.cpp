#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <time.h>
#include <algorithm>
#include <limits.h>
#include <stdio.h>
#include <map>
#include <cmath>
#include <fstream>
#include <queue>
#include <sstream>

using namespace std;

struct Node
{
	char key;
	int val;
	Node* left;
	Node* right;
	Node(char key, int val) {
		this->key = key;
		this->left = NULL;
		this->right = NULL;
		this->val = val;
	}
};

bool Compare(Node* leftTree, Node* rightTree)
{
	return leftTree->val < rightTree->val ? true : false;
}

class Tree
{
public:
	Node* root;
	string* eTable;
	string str;
	string code;
	int count[1024]{ 0 };

	Tree(string str)
	{
		this->root = NULL;
		this->str = str;
		Build();
	}

	void Build()
	{

		int stCount = 0;
		Node** st = new Node * [1024];

		for (int i = 0; i < str.length(); i++)
			count[str[i]]++;

		for (int i = 0; i < 1024; i++)
		{
			if (count[i])
			{
				st[stCount++] = new Node(i, count[i]);
			}
		}

		int unic = stCount;

		while (stCount > 1)
		{
			sort(st, st + stCount, Compare);
			st[0] = Combine(st[0], st[1]);
			stCount--;
			st[1] = st[stCount];
		}

		root = st[0];
		MakeTree();
	}

	Node* Combine(Node* leftTree, Node* rightTree)
	{
		Node* temp = new Node('-', leftTree->val + rightTree->val);
		temp->left = leftTree;
		temp->right = rightTree;
		return temp;
	}

	void MakeTree()
	{
		eTable = new string[1024]{ "" };
		construct(root, "");
	}

	void construct(Node* node, string code)
	{
		if (node->key != '-')
			eTable[node->key] = code;

		if (node->left && node->right)
		{
			construct(node->left, code + '0');
			construct(node->right, code + '1');
		}
	}

	bool IsLeaf(string str)
	{
		return !GetNode(str)->left;
	}

	Node* GetNode(string str)
	{
		Node* node = root;
		for (int i = 0; i < str.length(); i++)
		{
			node = str[i] == '0' ? node->left : node->right;
		}
		return node;
	}

	string Encode()
	{
		for (int i = 0; i < str.length(); i++)
		{
			code += eTable[str[i]];
		}
		return code;
	}

	string Decode()
	{
		string temp = "";
		string result = "";
		for (int i = 0; i < code.length(); i++)
		{
			temp += code[i];
			if (IsLeaf(temp))
			{
				result += GetNode(temp)->key;
				temp = "";
			}
		}
		return result;
	}
};

int main()
{
	ifstream input("input.txt");

	string ABC = "";
	string word;

	while (true) {
		getline(input, word);
		ABC += word;

		if (input.eof())
			break;

		ABC += "\n";
	}

	Tree tree(ABC);

	for (int i = 0; i < 1024; i++)
		if (tree.count[i])
			cout << '"' << char(i) << '"' << "      " << tree.count[i] << '\n';

	cout << "\n\n\n";

	for (int i = 0; i < 1024; i++)
		if (tree.eTable[i] != "")
			cout << (char)i << " " << tree.eTable[i] << '\n';


	cout << "\n\n\n";

	cout << tree.Encode();
	cout << "\n\n\n";

	cout << "\n\n\n";

	cout << tree.Decode();

}
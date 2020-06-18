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
#include <sstream>
using namespace std;

struct tree
{

	tree* left;
	tree* right;
	int value;
	int height;

	tree(int value) {
		this->value = value;
		this->left = this->right = NULL;
		this->height = 1;
	}

};


int height(tree* root) {    //высота

	return root ? root->height : 0;


}

void correctHeight(tree* root)   
{
	int heightLeft = height(root->left);
	int heightRight = height(root->right);

	root->height = (heightLeft > heightRight ? heightLeft : heightRight) + 1;
}


int diff(tree* root) { //разница высот

	return height(root->right) - height(root->left);
}


tree* Left(tree* root) //левый поворот 
{
	tree* tmp  = root->right;
	root->right = tmp->left;
	tmp->left = root;
	correctHeight(root);
	correctHeight(tmp);
	return tmp;
}

tree* Right(tree* root) {  //правый поворот
	tree* tmp = root->left;
	root->left = tmp->right;
	tmp->right = root;
	correctHeight(root);
	correctHeight(tmp);
	return tmp;
}



tree* balance(tree* root)  //балансировка 
{
	correctHeight(root);
	int d = diff(root);

	if (d == 2)
	{
		if (diff(root->right) < 0)
			root->right = Right(root->right);
		return Left(root);
	}
	if (d == -2)
	{
		if (diff(root->left) > 0)
			root->left = Left(root->left);
		return Right(root);
	}
	return root;
}


tree* del_min(tree* root) { 
	if (root->left == NULL)
		return root->right;
	root->left = del_min(root->left);
	return balance(root);
}


tree* Minimum(tree* root)  
{

	return root->left ? Minimum(root->left) : root;

}

tree* Maximum(tree* root)
{

	return root->right ? Maximum(root->right) : root;

}



tree* search(tree* root, int value) {

	if (root == NULL)return 0;
	if (root->value == value) return root;
	return search(value < root->value ? root->left : root->right, value);
	

}

tree* addTree(tree *root, int value) { //добавить

	if (!root) return new tree(value);
	
	if (value > root->value) 
		root->right = addTree(root->right, value);
	

	else if(value < root->value)
		root->left = addTree(root->left, value);
	
	return balance(root);
}



tree* del(tree* root, int value) {

	if (!root)return NULL;
	if (value < root->value)
		root->left = del(root->left, value);
	else if (value > root->value)
		root->right = del(root->right, value);
	else {
		tree* l = root->left;
		tree* r = root->right;
		delete root;
		if (!r)return l;
		tree* min = Minimum(r);
		min->right = del_min(r);
		min->left = l;
		return balance(min);
	}
	return balance(root);

}

// void print_LRR(tree* root)
// {
// 	if (root != NULL)
// 	{
// 		print_LRR(root->left);
// 		cout << root->value << endl;
// 		print_LRR(root->right);
// 	}
// }


void Print(tree* root, int r = 0)
{
	if (root == NULL) return;
	
		Print(root->right, r + 3);

		for (int i = 0; i < r; ++i)
		{
			cout << " ";
		}

		cout << "  " << root->value << endl;

		Print(root->left, r + 3);
	
}


//void print_RLR(tree* root)
//{
//	if (root != NULL)
//	{
//		cout << root->value << endl;
//		print_LRR(root->left);
//		
//		print_LRR(root->right);
//		
//	
//	}
//}
//
//void print_LRR(tree* root)
//{
//	if (root != NULL)
//	{
//		print_LRR(root->left);
//		print_LRR(root->right);
//		cout << root->value << endl;
//	}
//}

 
int main() {
	ifstream fin("input.txt");
	tree* root = NULL;
	int k;

	while (fin >> k) 
		root = addTree(root, k);

	Print(root);
	cout << endl << endl;


	cout << Minimum(root)->value << " " << Maximum(root)->value << endl;
	
	del(root, 5);
	Print(root);
	cout << endl << endl;

	del(root, 35);
	Print(root);
	cout << endl << endl;

	del(root, 65);
	Print(root);
	cout << endl << endl;

	del(root, 89);
	Print(root);
	cout << endl << endl;

	del(root, 43);
	Print(root);
	cout << endl << endl;

	del(root, 88);
	Print(root);
	cout << endl << endl;

	del(root, 20);
	Print(root);
	cout << endl << endl;;


	cout << Minimum(root)->value << " " << Maximum(root)->value << endl;

}
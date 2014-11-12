#include <fstream>
#include <iostream>
#include <stdlib.h>

using namespace std;

struct Node {
    int data_value;
    Node *left;
    Node *right;
};

Node insert(Node *x, Node *root)
{
    if (root == nullptr)
    {
        root = x;
        cout << "root is now " << root->data_value << '\n';
    }
    else if ( x->data_value > root->data_value)
    {
        insert(x, root->right);
        cout << "Inserted: " << x->data_value << '\n';
    }
    else if( x->data_value < root->data_value)
    {
        insert(x, root->left);
        cout << "Inserted: " << x->data_value << '\n';
    }

    return *root;

}

void print_actual(Node *x)
{

	cout << "(" << x->data_value << ")";	

}

void print_tree(Node *x)
{
	if(x != nullptr)
	{
		print_tree(x->left);			
		print_actual(x);			
		print_tree(x->right);
	}
}

int main()
{
    char str[100];
    int i;

    Node *root = new Node;
    root->left = nullptr;
    root->right = nullptr;

    ifstream b_file ( "data.txt" );    				

    while (!b_file.eof())               			
    {

        b_file>> str;
        i = atoi(str);                 			

    	Node *x = new Node;
        x->data_value = i;

        cout << "X is: " << x->data_value << '\n';
        cout << "Root is: " << root->data_value << '\n';

    	insert(x,root);
    	

    }

    print_tree(root);
}

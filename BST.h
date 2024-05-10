#pragma once
#include<iostream>
using namespace std;


struct Node {
	string team;
	float data;
	Node* left;
	Node* right;

	Node(float val,string t)
	{
		team = t;
		data = val;
		left = right = NULL;

	}
};


class BST
{
public:
	Node* root;
	void insert(float val,string t)
	{
		insert(val, t, root);

	}
	void inOrder()
	{
		inOrder(root);
	}


	void insert(float val,string t, Node* treeNode)

	{
		if (!treeNode)
		{
			treeNode = new Node(val,t);
			root = treeNode;
		}
		else
		{
			if (val < treeNode->data)
			{
				if (!treeNode->left)
				{
					Node* treeTemp = new Node(val,t);
					treeNode->left = treeTemp;
				}
				else
					insert(val,t, treeNode->left);
			}
			else
			{
				if (!treeNode->right)
				{
					Node* treeTemp = new Node(val,t);
					treeNode->right = treeTemp;
				}
				else
					insert(val,t, treeNode->right);

			}
		}


	}


	void inOrder(Node* treeNode)
	{
		if (treeNode == NULL)
		{
			return;
		}
		inOrder(treeNode->left);
		cout << treeNode->team <<" "<< treeNode->data << endl;
		inOrder(treeNode->right);

	}

public:
	BST()
	{
		root = NULL;
	}


	~BST()
	{
		delete root;
	}
};


/*
Given two binary trees, write a function to check if they are equal or not.

Two binary trees are considered equal if they are structurally identical and the nodes have the same value.
*/

#include <iostream>
#include <cstdlib>
#include <stack>
#include "Btree.h"
using namespace std;


class Solution {
public:
    bool isSameTree(TreeNode *p, TreeNode *q){

		if(p!=NULL && q!=NULL)
		{
			if(p->val==q->val)
				return isSameTree(p->left,q->left) && isSameTree(p->right, q->right);
			else
				return false;
		} 
		else if(p==NULL && q==NULL)
			return true;
		else 
			return false;
					
    }
	

};

TreeNode * Btree::contruct_tree()
{
	TreeNode *root=NULL;
	TreeNode *leaf=NULL;
	Btree btree;

	/*
	//Test case1:
	root=btree.insert(1);  //insert root
	leaf=btree.insert(2,root);
	*/
	
	//Test case2:
	root=btree.insert(5);  //insert root
	
	//left tree
	leaf=btree.insert(4,root);
	leaf=btree.insert_nocompare(11,leaf);
	btree.insert_nocompare(7,leaf);
	btree.insert_nocompare(2,leaf);
	
	//right tree
	leaf=btree.insert_nocompare(8,root);
	btree.insert_nocompare(13,leaf);
	leaf=btree.insert_nocompare(4,leaf);
	leaf=btree.insert_nocompare(1,leaf);
	
	return root;
	
}

int main()
{
	Solution solution;
	Btree btree;
	
	bool result=false;
	TreeNode *root;
	TreeNode *root2;
	

	root=btree.contruct_tree();
	root2=btree.contruct_tree();

	result=solution.isSameTree(root, root2);
	cout<<"result:"<<result<<endl;
	return 0;
}

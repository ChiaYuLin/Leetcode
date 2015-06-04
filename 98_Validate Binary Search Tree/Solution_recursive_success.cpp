/*
Given a binary tree, determine if it is a valid binary search tree (BST).

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.

*/
#include <iostream>
#include <cstdlib>
#include <stack>
#include <climits>
#include "Btree.h"
using namespace std;

/*
This is Method1:Deliver the min and max to the recusive.

There are three ways to sovle this problem:
<Method1>
Deliver the min and max to the recusive.
The max of left subtree is root.
The min of right subtree is root.

//Test case5:
root=btree.insert(-2147483648);  //insert root
btree.insert(2147483647,root);
=>But I think my code will fail in this case??


<Method2>
Use FindMax and FindMin funtion to find the max and min of subtree.
The max of left subtree should be smaller than root.
The min of right subtree should be bigger than root.

<Method3>Inorder Traversal
InorderTraversal first and check whether the value in the inordertraversal vector is increasing.

*/



class Solution {
public:
	bool Traversal(TreeNode *root,long int min,long int max)  
	{

		bool left_result=true;
		bool right_result=true;


		if(root!=head)   //We don't need to check root.
		{
			if(root->val <= min || root->val >= max)  
				return false;
		}


		if(root->left !=NULL)
			left_result=Traversal(root->left,min,root->val);  //The max of left subtree is root
		if(root->right !=NULL)
			right_result=Traversal(root->right,root->val,max);  //The min of right subtree is root.
	
		return left_result&&right_result;
	}

	bool isValidBST(TreeNode* root)
	{
		long int min=LONG_MIN;
		long int max=LONG_MAX;

		head=root;

		if(root==NULL)
			return true;
		else
			return Traversal(root,min,max);	
	}
private:
	TreeNode* head;

    

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
	
	/*
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
	btree.insert_nocompare(5,leaf);
	leaf=btree.insert_nocompare(1,leaf);*/

	/*
	//Test case3:
	root=btree.insert(10);  //insert root
	btree.insert(5,root);    
	leaf=btree.insert(15,root); 
	btree.insert_nocompare(6,leaf); 
	btree.insert_nocompare(20,leaf);*/

    /*
	//Test case4:
	root=btree.insert(2147483647);  //insert root
	btree.insert(-2147483648,root);   */

	//Test case5:
	root=btree.insert(-2147483648);  //insert root
	btree.insert(2147483647,root);   

	
	return root;
	
}

int main()
{
	Solution solution;
	Btree btree;
	
	bool result;
	TreeNode *root;
	

	root=btree.contruct_tree();
	result=solution.isValidBST(root);
	
	cout<<"result:"<<result<<endl;

	return 0;
}

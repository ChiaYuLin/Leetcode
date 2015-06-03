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
Use FindMax and FindMin funtion to find the max and min of subtree.
The max of left subtree should be smaller than root.
The min of right subtree should be bigger than root.

*/



class Solution {
public:
	long int  FindMax(TreeNode *root,long int max)
	{

		long int leftsubtreemax=LONG_MIN;
		long int rightsubtreemax=LONG_MIN;
		if(root->val > max)
			max=root->val;

		if(root->left !=NULL)
			leftsubtreemax=FindMax(root->left,max);
		
		if(root->right !=NULL)
			rightsubtreemax=FindMax(root->right,max);
	
		if(leftsubtreemax > max && leftsubtreemax > rightsubtreemax)
			max=leftsubtreemax;
		else if(rightsubtreemax  > max && rightsubtreemax > leftsubtreemax)
			max=rightsubtreemax;


		return max;


	}
	long int  FindMin(TreeNode *root,long int min)
	{
		long int leftsubtreemin=LONG_MAX;
		long int rightsubtreemin=LONG_MAX;
		
		if(root->val < min)
			min=root->val;

		if(root->left !=NULL)
			leftsubtreemin=FindMin(root->left,min);
		
		if(root->right !=NULL)
			rightsubtreemin=FindMin(root->right,min);

		if(leftsubtreemin < min && leftsubtreemin < rightsubtreemin)
			min=leftsubtreemin;
		else if(rightsubtreemin  < min && rightsubtreemin < leftsubtreemin)
			min=rightsubtreemin;

	
		return min;


	}
	bool Traversal(TreeNode *root)  
	{

		bool left_result=true;
		bool right_result=true;

		long int min=LONG_MAX;
		long int max=LONG_MIN;

		if(root==NULL)
			return true;

		 //Use FindMax to find the max of left subtree. The max of left subtree should be smaller than root.
		if(root->left !=NULL && FindMax(root->left,max) >= root->val) 
		    return false;

		//Use FindMin to find the min of right subtree. The min of left subtree should be bigger than root.
		if(root->right !=NULL && FindMin(root->right,min) <= root->val)
			return false;

		if(!Traversal(root->left) || !Traversal(root->right))
			return false;

	
		return true;
	}

	bool isValidBST(TreeNode* root)
	{
		if(root==NULL)
			return true;
		else
			return Traversal(root);	
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
    
    
	//Test case4:
	root=btree.insert(2147483647);  //insert root
	btree.insert(-2147483648,root); 

	/*
	//Test case5:
	root=btree.insert(-2147483648);  //insert root
	btree.insert_nocompare(2147483647,root);  */

	
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

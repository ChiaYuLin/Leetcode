/*Given a binary tree and a sum, determine if the tree has a root-to-leaf path such that adding up all the values along the path equals the given sum.

For example:
Given the below binary tree and sum = 22,
              5
             / \
            4   8
           /   / \
          11  13  4
         /  \      \
        7    2      1
return true, as there exist a root-to-leaf path 5->4->11->2 which sum is 22.

Check the complete path which the sum is equal to the given value.
*/

#include <iostream>
#include <cstdlib>
#include <stack>
#include "Btree.h"
using namespace std;


class Solution {
public:
    bool hasPathSum(TreeNode *root, int sum) {

		if(root==NULL) 
			return false;
		if(root->val==sum && root->left==NULL && root->right==NULL) 
			return true;

		return hasPathSum(root->left, sum-root->val)||hasPathSum(root->right, sum-root->val);
			
		/*
		//This will fail. In the end of leaf, root->left==NULL, no calling hasPathSum.
		//No return	
		else if(root->left!=NULL)
			return hasPathSum(root->left, sum-root->val);
		else if(root->right!=NULL)
		    return hasPathSum(root->right, sum-root->val);
		    
		
		//This will fail. The recursive will be end when enter the last else if. 
		//Only return false. No recursive   
		//The tree only execute one time 
		else if(root->left!=NULL)
			return hasPathSum(root->left, sum-root->val);
		else if(root->right!=NULL)
		    return hasPathSum(root->right, sum-root->val);
		else if(root->left==NULL && root->right==NULL)
			return false;   
	    */
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
	
	bool result;
	TreeNode *root;
	

	root=btree.contruct_tree();
	result=solution.hasPathSum(root, 22);
	cout<<"result:"<<result<<endl;
	return 0;
}

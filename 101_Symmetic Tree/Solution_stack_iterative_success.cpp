/*Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

For example, this binary tree is symmetric:

    1
   / \
  2   2
 / \ / \
3  4 4  3
But the following is not:
    1
   / \
  2   2
   \   \
   3    3
*/

#include <iostream>
#include <cstdlib>
#include <stack>
#include "Btree.h"
using namespace std;

/*
Method2 will fail when input is {1,2,2,#,3,#,3}. The answer is false.
I think '#' is not existed. If it NULL, the left stack will push '3' and the right stack will push '3' too.
Therefore, the result will return true.
*/
class Solution {
public:
    bool isSymmetric(TreeNode *root) {

		stack<TreeNode*> treestack_left;
		stack<TreeNode*> treestack_right;
		TreeNode *leaf_left;
		TreeNode *leaf_right;

		
		if(root!=NULL)
		{
			if(root->left!=NULL)
				treestack_left.push(root->left);
			if(root->right!=NULL)
				treestack_right.push(root->right);

			while(!treestack_left.empty() && !treestack_right.empty())
			{
				leaf_left=treestack_left.top();
				leaf_right=treestack_right.top();
				
	
				treestack_left.pop();
				treestack_right.pop();
				
				
				//Method1:Check whether the node is NUll after pop
				if(leaf_left!=NULL && leaf_right!=NULL)
				{
				    if(leaf_left->val!=leaf_right->val)
					    return false;
					else
    				{
    					treestack_left.push(leaf_left->right);	//Put the right leaf into the stack
    					treestack_left.push(leaf_left->left);    //Put the left leaf into the stack
    					treestack_right.push(leaf_right->left);    //Put the left leaf into the stack
    					treestack_right.push(leaf_right->right);	//Put the right leaf into the stack
    				}
				}
				else if(leaf_left!=NULL && leaf_right==NULL)
					return false;   
				else if(leaf_left==NULL && leaf_right!=NULL)
					return false;


				
				//Mehtod2: If it is NULL node, we don't push it into stack
				/*if(leaf_left->val!=leaf_right->val)
					return false;
				else
				{
					if(leaf_left->right!=NULL)
						treestack_left.push(leaf_left->right);	//Put the right leaf into the stack
						
					if(leaf_left->left!=NULL)
						treestack_left.push(leaf_left->left);    //Put the left leaf into the stack
					
					if(leaf_right->left!=NULL)
						treestack_right.push(leaf_right->left);    //Put the left leaf into the stack

					if(leaf_right->right!=NULL)
						treestack_right.push(leaf_right->right);	//Put the right leaf into the stack
						
					
				}*/
					
			}
			if(!treestack_left.empty()||!treestack_right.empty())
				return false;
			else
				return true;
		}
		else
			return true;
		
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
	
	/*//Test case2:
	root=btree.insert(1);  //insert root
	
	//left tree
	leaf=btree.insert(2,root);
	btree.insert_nocompare(3,leaf);
	btree.insert_nocompare(4,leaf);
	
	//right tree
	leaf=btree.insert_nocompare(2,root);
	btree.insert_nocompare(4,leaf);
	btree.insert_nocompare(3,leaf);*/

	/*//Test case3:
	root=btree.insert(1);  //insert root
	
	//left tree
	leaf=btree.insert_nocompare(2,root);
	btree.insert_nocompare('#'-'0',leaf);
	btree.insert_nocompare(3,leaf);
	
	//right tree
	leaf=btree.insert_nocompare(2,root);
	btree.insert_nocompare('#'-'0',leaf);
	btree.insert_nocompare(3,leaf);*/

	
	//Test case3:
	root=btree.insert(2);  //insert root
	
	//left tree
	leaf=btree.insert_nocompare(3,root);
	btree.insert_nocompare(4,leaf);
	btree.insert_nocompare(5,leaf);
	
	//right tree
	leaf=btree.insert_nocompare(3,root);
	btree.insert_nocompare('#'-'0',leaf);
	btree.insert_nocompare(4,leaf);
	
	return root;
	
}

int main()
{
	Solution solution;
	Btree btree;
	
	bool result;
	TreeNode *root;
	

	root=btree.contruct_tree();
	result=solution.isSymmetric(root);
	cout<<"result:"<<result<<endl;
	return 0;
}

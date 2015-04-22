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

/*
Method:
(1)treestack is used to record the order of the path.
Pop a node and put the left and right child of this node.
*/
class Solution {
public:
    bool hasPathSum(TreeNode *root, int sum) {
		int finalresult=0;
		stack<TreeNode*> treestack;
		TreeNode *leaf;
		
		if(root!=NULL)
		{
			treestack.push(root);
		    
			while(!treestack.empty())
			{
				leaf=treestack.top();
				finalresult=leaf->val;
	
				treestack.pop();
				
				
				if(leaf->right==NULL && leaf->left==NULL)  //One path to end
				{
					if(finalresult==sum)
						return true;
				}
				else
				{
					if(leaf->right!=NULL)
					{
						leaf->right->val=finalresult+leaf->right->val;
						treestack.push(leaf->right);	//Put the right leaf into the stack
						
					}
					if(leaf->left!=NULL)
					{
						leaf->left->val=finalresult+leaf->left->val;
						treestack.push(leaf->left);    //Put the left leaf into the stack
					}
				}
				
				
					
			}
		}
		
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
	
	bool result;
	TreeNode *root;
	

	root=btree.contruct_tree();
	result=solution.hasPathSum(root, 22);
	cout<<"result:"<<result<<endl;
	return 0;
}

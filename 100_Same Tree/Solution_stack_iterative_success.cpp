/*
Given two binary trees, write a function to check if they are equal or not.

Two binary trees are considered equal if they are structurally identical and the nodes have the same value.
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
    bool isSameTree(TreeNode *p, TreeNode *q){
		stack<TreeNode*> treestack1;
		stack<TreeNode*> treestack2;
		TreeNode *leaf1;
		TreeNode *leaf2;
		
		if(p!=NULL && q!=NULL)
		{
			treestack1.push(p);
			treestack2.push(q);
		    
			while(!treestack1.empty() && !treestack2.empty())
			{
				leaf1=treestack1.top();
				leaf2=treestack2.top();


				if(leaf1->val!=leaf2->val)
					return false;
	
				treestack1.pop();
				treestack2.pop();
				
				
				if(leaf1->left!=NULL && leaf2->left!=NULL)
				{
					treestack1.push(leaf1->left);    //Put the left leaf into the stack
					treestack2.push(leaf2->left);    //Put the left leaf into the stack
				}
				else if(leaf1->left==NULL && leaf2->left==NULL)
					;
				else
					return false;  //structure is not the same


				if(leaf1->right!=NULL && leaf2->right!=NULL)
				{
					treestack1.push(leaf1->right);	//Put the right leaf into the stack
					treestack2.push(leaf2->right);	//Put the right leaf into the stack
						
				}
				else if(leaf1->right==NULL && leaf2->right==NULL)
					;
				else
					return false;  //structure is not the same
					

				
					
					
					
			}
			if(!treestack1.empty() || !treestack2.empty())
				return false;	
			else
				return true;
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

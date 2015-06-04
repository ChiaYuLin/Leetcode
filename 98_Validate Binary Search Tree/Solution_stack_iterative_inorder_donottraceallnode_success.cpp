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
#include <vector>
#include "Btree.h"
using namespace std;

/*
InorderTraversal:
When put the value into the vector, check whether the value is bigger than the last value in the inordertraversal vector. 

*/



class Solution {
public:

	bool isValidBST(TreeNode *root)  
	{
		stack<TreeNode*> treestack;

		vector<int>  finalresult;

		TreeNode* current;
		TreeNode* top;

		if(root!=NULL)
		{
			current=root;

			treestack.push(current);

			current=current->left;

			while(!treestack.empty())
			{
				while(current!=NULL)   
				{
					treestack.push(current);
					current=current->left;
				}


				top=treestack.top();
				if(!finalresult.empty())
				{
					if(top->val <= finalresult.back()) //When put the value into the vector, check whether the value is bigger than the last value in the inordertraversal vector. 
						return false;
					else
						finalresult.push_back(top->val);
				}
				else
					finalresult.push_back(top->val);
				
				current=top->right;
				treestack.pop();


				if(treestack.size()==0 && top->right!=NULL)  //push right leaf of root into stack
				{
					treestack.push(top->right);
					current=top->right->left;
				}
				
			}

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
	
	//Test case3:
	root=btree.insert(10);  //insert root
	btree.insert(5,root);    
	leaf=btree.insert(15,root); 
	btree.insert_nocompare(6,leaf); 
	btree.insert_nocompare(20,leaf);

    /*
	//Test case4:
	root=btree.insert(2147483647);  //insert root
	btree.insert(-2147483648,root);   */

	/*//Test case5:
	root=btree.insert(-2147483648);  //insert root
	btree.insert(2147483647,root); */
	
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

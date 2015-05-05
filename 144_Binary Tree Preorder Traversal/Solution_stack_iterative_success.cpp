/*Given a binary tree, return the preorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},
   1
    \
     2
    /
   3
return [1,2,3].
*/

#include <iostream>
#include <cstdlib>
#include <stack>
#include <vector>
#include "Btree.h"
using namespace std;




class Solution {
public:

	vector<int> preorderTraversal(TreeNode *root)  
	{
		stack<TreeNode*> treestack;

		vector<int>  finalresult;

		TreeNode* current;
		TreeNode* top;

		if(root!=NULL)
		{
			
			treestack.push(root);


			while(!treestack.empty())
			{
				
				top=treestack.top();
				finalresult.push_back(top->val);
				treestack.pop();

				if(top->right!=NULL)
					treestack.push(top->right);
				if(top->left!=NULL)
					treestack.push(top->left);
				
			}

			return finalresult;
		}
		else
			return finalresult;
		
		
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
	btree.insert_nocompare(5,leaf);
	leaf=btree.insert_nocompare(1,leaf);
	
	return root;
	
}

int main()
{
	Solution solution;
	Btree btree;
	
	vector<int> result;
	TreeNode *root;
	

	root=btree.contruct_tree();
	result=solution.preorderTraversal(root);
	
	for(vector<int>::iterator it2=result.begin();it2!=result.end();it2++)
	{
		cout<<*it2<<",";
	}

	return 0;
}

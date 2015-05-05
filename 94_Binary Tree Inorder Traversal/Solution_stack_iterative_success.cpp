/*Given a binary tree, return the inorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},
   1
    \
     2
    /
   3
return [1,3,2].
*/
#include <iostream>
#include <cstdlib>
#include <stack>
#include <vector>
#include "Btree.h"
using namespace std;

/*
//Go left subtree all the way down.

And go back to the parent. 

Go the right subtree.

And repeat to left subtree tracing again.


*/



class Solution {
public:

	vector<int> inorderTraversal(TreeNode *root)  
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
				finalresult.push_back(top->val);
				current=top->right;
				treestack.pop();


				if(treestack.size()==0 && top->right!=NULL)  //push right leaf of root into stack
				{
					treestack.push(top->right);
					current=top->right->left;
				}
				
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
	result=solution.inorderTraversal(root);
	
	for(vector<int>::iterator it2=result.begin();it2!=result.end();it2++)
	{
		cout<<*it2<<",";
	}

	return 0;
}

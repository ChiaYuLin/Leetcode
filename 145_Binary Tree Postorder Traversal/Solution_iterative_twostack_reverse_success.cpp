/*Given a binary tree, return the postorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},
   1
    \
     2
    /
   3
return [3,2,1].
*/
#include <iostream>
#include <cstdlib>
#include <stack>
#include <vector>
#include "Btree.h"
using namespace std;

/*
Use two stack: treestack and resultstack.
Treestack is the order of tree traversal. 
We put middle node into treestack . Pop middle node and put left->right.
So the pop order will be middle->right->left. (The reverse order of postorder.) 
The node pop from treestack is put into Resultstack.
The finalresult is the pop of resultstack. 
(Since the push order of resultstack is the reverse order of postorder, the pop order will be the postorder.)
*/



class Solution {
public:

	vector<int> postorderTraversal(TreeNode *root)  
	{
		stack<TreeNode*> treestack;
		stack<TreeNode*> resultstack;

		vector<int>  finalresult;

		TreeNode* current;
		TreeNode* top;

		if(root!=NULL)
		{

			treestack.push(root);


			while(!treestack.empty())
			{
				top=treestack.top();
				treestack.pop();
				resultstack.push(top);
				if(top->left!=NULL)
					treestack.push(top->left);
				if(top->right!=NULL)
					treestack.push(top->right);
				
			}

			while(!resultstack.empty())
			{
				finalresult.push_back(resultstack.top()->val);
				resultstack.pop();
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
	btree.insert_nocompare(9,leaf);
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
	result=solution.postorderTraversal(root);
	
	for(vector<int>::iterator it2=result.begin();it2!=result.end();it2++)
	{
		cout<<*it2<<",";
	}

	return 0;
}

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
Use one stack: treestack.
Treestack is the order of tree traversal. 


Go left subtree all the way down.

Go to the right child.

If the right child is not NULL, go to the left subtree trace again.

If the right child is NULL or the right node is same with the lastnode put in the finaluresult, 
put the node into the finalresult.
(When the the right node is same with the lastnode put in the finaluresult, it means the rightnode is finished.)



*/



class Solution {
public:

	vector<int> postorderTraversal(TreeNode *root)  
	{
		stack<TreeNode*> treestack;

		vector<int>  finalresult;

		TreeNode* current;
		TreeNode* lastpushnode;

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


				current=treestack.top()->right;  //Go to the right subtree.

				//current==NULL means the right child is NULL.	
				//current==lastnode means the right node has push in finalresult
				if(current==NULL || current==lastpushnode)   
				{
					finalresult.push_back(treestack.top()->val);
					lastpushnode=treestack.top();
					treestack.pop();
					current=NULL;   //If current==lastnode
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

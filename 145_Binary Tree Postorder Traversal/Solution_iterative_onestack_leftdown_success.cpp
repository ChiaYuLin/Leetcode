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
Reference:http://www.geeksforgeeks.org/iterative-postorder-traversal-using-stack/

Use one stack: treestack.

Go left subtree all the way down.

During tracing, put parent and right child into stack.

Pop a node. If the right child of this node is smae with the top of stack. 
That is, we will go to trace the right child of this node.
Pop this right child from the stack.
And push the node back. The current node becomes the right child.


Pop a node. If the right child of this node is not smae with the top of stack. 
That is, we have finished the trace of the right child.
Put the node info finalresult.


*/



class Solution {
public:

	vector<int> postorderTraversal(TreeNode *root)  
	{
		stack<TreeNode*> treestack;
		vector<int>  finalresult;

		TreeNode* current;
		TreeNode* tmp;
		TreeNode* top;

		if(root!=NULL)
		{
			current=root;

			if(current->right!=NULL)
				treestack.push(current->right);
			treestack.push(current);
			

			current=current->left;

			while(!treestack.empty())
			{
				while(current!=NULL)   
				{
					if(current->right!=NULL)
						treestack.push(current->right);
					treestack.push(current);
					
					current=current->left;
				}

				tmp=current;  
				while(tmp==current && !treestack.empty())
				{
					top=treestack.top();
					treestack.pop();
					if(top->right!=NULL)
					{
						if(!treestack.empty())
						{
							if(top->right!=treestack.top()) //The right subtree is finished.
								finalresult.push_back(top->val);
							else  //Go to the right subtree traversal
							{
								treestack.pop();  //pop the right child
								treestack.push(top); //push the parent back
								current=top->right;  //Go to the right subtree.
							}
						}
						else  //For the last node.
							finalresult.push_back(top->val);
						
					}	
					else
						finalresult.push_back(top->val);
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

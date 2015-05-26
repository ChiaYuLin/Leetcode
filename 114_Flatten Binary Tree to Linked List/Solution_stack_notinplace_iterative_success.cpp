/*
Given a binary tree, flatten it to a linked list in-place.

For example,
Given

         1
        / \
       2   5
      / \   \
     3   4   6
The flattened tree should look like:
   1
    \
     2
      \
       3
        \
         4
          \
           5
            \
             6

Hints:
If you notice carefully in the flattened tree, each node's right child points to the next node of a pre-order traversal.
*/

#include <iostream>
#include <cstdlib>
#include <stack>
#include <vector>
#include "Btree.h"
using namespace std;

/*
We use stack to record the order of preorder tracing.
When we pop the node out, we connect the node to the right of new list.
Since we use a new list, this method is not in place.

*/



class Solution {
public:

	void flatten(TreeNode *root)  
	{
		stack<TreeNode*> treestack;

		vector<int>  finalresult;

		TreeNode* top;
		TreeNode * newroot;  //The head of new list.
		TreeNode* current;  //The lastnode on new list.

		if(root!=NULL)
		{
			
			treestack.push(root);


			while(!treestack.empty())
			{
				
				top=treestack.top();
				if(top==root)
				{
					newroot=root;
					current=root;
				}
					
				else  //Connect the node the right node of current.
				{
					current->right=top;
					current=current->right;
				}
					

				treestack.pop();

				if(top->right!=NULL)
					treestack.push(top->right);
				if(top->left!=NULL)
					treestack.push(top->left);
				
			}

			root=newroot;
			return;
		}
		else
			return;
		
		
	}


    

};

TreeNode * Btree::contruct_tree()
{
	TreeNode *root=NULL;
	TreeNode *leaf=NULL;
	Btree btree;

	
	//Test case1:
	root=btree.insert(1);  //insert root
	leaf=btree.insert(2,root);
	
	
	/*
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
	*/
	
	return root;
	
}

int main()
{
	Solution solution;
	Btree btree;
	
	TreeNode *root;
	

	root=btree.contruct_tree();
	solution.flatten(root);


	while(root!=NULL)
	{
		cout<<"root->right"<<root->val<<endl;
		root=root->right;
	}


	return 0;
}

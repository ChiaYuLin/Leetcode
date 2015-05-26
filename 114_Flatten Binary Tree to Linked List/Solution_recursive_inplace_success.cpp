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
We have to flatten tree in-plcae. Thus, we should execute recursively.
Since we have put the left node to the right subtree, we have to trace right subtree first.
After the left subtree tracing return, we put the left subtree be the next of root and the previous of root->right.

*/



class Solution {
public:
	void flatten(TreeNode *root)  
	{
		TreeNode * tmp;

		if(root!=NULL)
		{
			if(root->right !=NULL)
				flatten(root->right);
			if(root->left !=NULL)
			{
				flatten(root->left);

				tmp=root->left;
				while(tmp->right!=NULL)   //Use loop to find the tail of subtree.
					tmp=tmp->right;

				tmp->right=root->right;  //We connect the root->right to the right node of tail.
				root->right=root->left;  //root->right becomes root->left
				root->left=NULL;   
			}
		}
			
		return;
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
	

	/*
	//Test case1:
	root=btree.insert(1);  //insert root
	leaf=btree.insert(2,root); */

	
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

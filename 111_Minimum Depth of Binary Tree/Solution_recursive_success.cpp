/*Given a binary tree, find its minimum depth.

The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.
*/
#include <iostream>
#include <cstdlib>
#include <stack>
#include <vector>
#include "Btree.h"
using namespace std;




class Solution {
public:
	void Depth(TreeNode *root,int &depth,int &finalresult)  //Use call by reference to access the same variable: depth and finalresult
	{

		depth++;
		
		if(root->left==NULL && root->right==NULL) //Check the depth when we arrive the end of path
		{
			if(depth<finalresult)
				finalresult=depth;
		}	

		

		if(root->left!=NULL)
			Depth(root->left,depth,finalresult);  

		if(root->right!=NULL)
			Depth(root->right,depth,finalresult);

		depth--;

	
		return;
	}

	
    int minDepth(TreeNode *root) {
		int finalresult=1000000;
		int depth=0;

		if(root!=NULL)
			Depth(root,depth,finalresult);
		else
			finalresult=0;

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
	
	int result;
	TreeNode *root;
	

	root=btree.contruct_tree();
	result=solution.minDepth(root);
	
	
	cout<<"result:"<<result<<endl;


	return 0;
}

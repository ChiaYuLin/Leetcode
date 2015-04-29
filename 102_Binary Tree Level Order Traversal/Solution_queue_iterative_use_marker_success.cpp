/*Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).

For example:
Given binary tree {3,9,20,#,#,15,7},
    3
   / \
  9  20
    /  \
   15   7
return its level order traversal as:
[
  [3],
  [9,20],
  [15,7]
]


*/

#include <iostream>
#include <cstdlib>
#include <queue>
#include <cmath>
#include "Btree.h"
using namespace std;

/*
Notice:'#' in Leetcode test data is existed. That is,'#' is not NULL. Therefore, we can use 'NULL' as a marker.


treequeue is a queue to records the order of node.

Use a NULL as a marker to record the level complete point.

When a level finish, we push the vector treenode into the result vector treelevelorder. 

When a level is finish, the leaf of this level has already push into the queue.

Therefore, we put a marker NULL at the end of queue.

When we read NULL, we can know that a level is finished and push the vector treenode into the result vector treelevelorder.
*/

class Solution {
public:
    vector<vector<int> > levelOrder(TreeNode *root) {
		queue<TreeNode*> treequeue;
		TreeNode *leaf;
		vector<int> treenode;
		vector<vector<int> >treelevelorder;
		
		if(root!=NULL)
		{
			treequeue.push(root);
			treequeue.push(NULL);

		    
			while(!treequeue.empty())
			{
				leaf=treequeue.front();
		
				treequeue.pop();

				if(leaf==NULL)
				{
					treelevelorder.push_back(treenode);
					treenode.clear();

					/*When a level is finish, the leaf of this level has already push into the queue.
					  Therefore, we put a marker.*/
					if(!treequeue.empty())   
						treequeue.push(NULL);
				}
				else
				{
					treenode.push_back(leaf->val);

					if(leaf->left!=NULL)  //'#' is existed not NULL.
						treequeue.push(leaf->left);    //Put the left leaf into the queue
					if(leaf->right!=NULL)
						treequeue.push(leaf->right);	//Put the right leaf into the queue
				}
	
			}
		}
		
        return treelevelorder;
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
	/*root=btree.insert(5);  //insert root
	
	//left tree
	leaf=btree.insert(4,root);
	leaf=btree.insert_nocompare(11,leaf);
	btree.insert_nocompare(7,leaf);
	btree.insert_nocompare(2,leaf);
	
	//right tree
	leaf=btree.insert_nocompare(8,root);
	btree.insert_nocompare(13,leaf);
	leaf=btree.insert_nocompare(4,leaf);
	leaf=btree.insert_nocompare(1,leaf);*/
	
	
	
	//Test case3:Only left tree
	root=btree.insert(1);  //insert root
	
	//left tree
	btree.insert_nocompare('#'-'0',root);
	leaf=btree.insert_nocompare(2,root);
	btree.insert_nocompare('#'-'0',leaf);
	leaf=btree.insert_nocompare(3,leaf);
	btree.insert_nocompare('#'-'0',leaf);
	leaf=btree.insert_nocompare(4,leaf);
	btree.insert_nocompare(5,leaf);
	

	/*//Test case4:
	root=btree.insert(-8);  //insert root
	
	//left tree
	btree.insert_nocompare(0,root);
	leaf=btree.insert_nocompare(3,root);
	leaf=btree.insert_nocompare(-8,leaf);
	leaf=btree.insert_nocompare(-1,leaf);
	btree.insert_nocompare(8,leaf);*/

	
	
	return root;
	
}

int main()
{
	Solution solution;
	Btree btree;
	
	vector<vector<int> > result;
	TreeNode *root;
	

	root=btree.contruct_tree();
	result=solution.levelOrder(root);
	
	for(vector<vector<int> >::iterator it=result.begin();it!=result.end();it++)
	{
		cout<<"[";
		for(vector<int>::iterator it2=it->begin();it2!=it->end();it2++)
		{
			cout<<*it2<<",";
		}
		cout<<"]"<<endl;
	}
	
	
	return 0;
}

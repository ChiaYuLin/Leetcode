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
treequeue is a queue to records the order of node.

Use nullnodearray to record how many '#' in one level. The root is level 0. The leaf of root is level 1.
If there is one '#' in the level 1, nullnodearray[1]++.
levelnumber records how many nodes in the level. 
If it is in level 3, the levelnumber is pow(2,3)-pow(2,2)*nullnodearray[1]-pow(2,1)*nullnodearray[2]
But this methods will overflow by  pow(2,levelorder) if there are two many level.
*/

class Solution {
public:
    vector<vector<int> > levelOrder(TreeNode *root) {
		int levelorder=0;
		int levelcount=0;
		int levelnumber=1;
		int nullnodearray[100]={0};
		queue<TreeNode*> treequeue;
		TreeNode *leaf;
		vector<int> treenode;
		vector<vector<int> >treelevelorder;
		
		if(root!=NULL)
		{
			treequeue.push(root);

		    
			while(!treequeue.empty())
			{
				leaf=treequeue.front();
		
				treequeue.pop();
				
				

				if(leaf!=NULL)
				{
					treenode.push_back(leaf->val);

					treequeue.push(leaf->left);    //Put the left leaf into the queue

					treequeue.push(leaf->right);	//Put the right leaf into the queue
				}
				else  //leaf=NULL
					nullnodearray[levelorder]++;
						

				
				levelcount++;
				
				
				if(levelcount==levelnumber)
				{
					if(!treenode.empty())
					{
						treelevelorder.push_back(treenode);
						treenode.clear();
					}	
		    			
		    		

					levelorder++;
					levelcount=0;

					int i=1;
					levelnumber=0;
					while(i<levelorder)
					{
						levelnumber=levelnumber+(int)pow(2,levelorder-i)*nullnodearray[i];
						i++;
					}
					levelnumber=(int)pow(2,levelorder)-levelnumber;
				}
				
				
				
					
			}
			if(!treenode.empty())
				treelevelorder.push_back(treenode);
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
	
	
	
	/*//Test case3:Only left tree
	root=btree.insert(1);  //insert root
	
	//left tree
	leaf=btree.insert(2,root);
	leaf=btree.insert_nocompare(3,leaf);
	leaf=btree.insert_nocompare(4,leaf);
	btree.insert_nocompare(5,leaf);*/
	

	//Test case4:
	root=btree.insert(-8);  //insert root
	
	/*//left tree
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

/*Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).

For example:
Given binary tree {3,9,20,#,#,15,7},
    3
   / \
  9  20
    /  \
   15   7
return its bottom-up level order traversal as:
[
  [15,7],
  [9,20],
  [3]
]


*/

#include <iostream>
#include <cstdlib>
#include <cmath>
#include <vector>
#include "Btree.h"
using namespace std;



class Solution {
public:
	void levelTrace(TreeNode *root,int currentlevel)
	{
		vector<int> tmp;

		if(root==NULL)
			return;

		if(currentlevel>=finalresult.size())  
			finalresult.insert(finalresult.begin(),tmp);  //The new vector should be inserted in the head

			

		//Go the next level, currentlevel++
		currentlevel++;

		levelTrace(root->left,currentlevel);
		levelTrace(root->right,currentlevel);

		//The currentlevel is increased so we --.
		currentlevel--;

 		//When left and right leaf tracing of a node is finished, we push the node into the vector.
 		//Use "finalresult.size()-currentlevel-1" to record the position of the vector in the finalresult
		tmp=finalresult[finalresult.size()-currentlevel-1];
		tmp.push_back(root->val);
		finalresult[finalresult.size()-currentlevel-1]=tmp;

		return;
	}
    vector<vector<int> > levelOrderBottom(TreeNode *root) {
		levelTrace(root,0);

		return finalresult;
    }

private:
	vector<vector<int> > finalresult;

	

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
	

	//Test case3:
	root=btree.insert(3);  //insert root
	
	//left tree
	leaf=btree.insert_nocompare(9,root);
	//btree.insert_nocompare('#'-'0',leaf);
	//btree.insert_nocompare('#'-'0',leaf);

	
	//right tree
	leaf=btree.insert_nocompare(20,root);
	btree.insert_nocompare(15,leaf);
	btree.insert_nocompare(7,leaf);

	
	
	/*//Test case3:Only left tree
	root=btree.insert(1);  //insert root
	
	//left tree
	btree.insert_nocompare('#'-'0',root);
	leaf=btree.insert_nocompare(2,root);
	btree.insert_nocompare('#'-'0',leaf);
	leaf=btree.insert_nocompare(3,leaf);
	btree.insert_nocompare('#'-'0',leaf);
	leaf=btree.insert_nocompare(4,leaf);
	btree.insert_nocompare(5,leaf);*/
	

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
	result=solution.levelOrderBottom(root);
	
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

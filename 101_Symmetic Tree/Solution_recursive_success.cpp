/*Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

For example, this binary tree is symmetric:

    1
   / \
  2   2
 / \ / \
3  4 4  3
But the following is not:
    1
   / \
  2   2
   \   \
   3    3
*/

#include <iostream>
#include <cstdlib>
#include <stack>
#include "Btree.h"
using namespace std;


class Solution {
public:
    bool Compare(TreeNode *p, TreeNode *q)
    {
    	if(p!=NULL && q!=NULL)
		{
			if(p->val==q->val)
				return Compare(p->left,q->right) && Compare(p->right, q->left);
			else
				return false;
		} 
		else if(p==NULL && q==NULL)
			return true;
		else 
			return false;
    } 
    bool isSymmetric(TreeNode *root){
    	bool result=true;
		
		if(root!=NULL)
			result=Compare(root->left,root->right);
		
		return result;
					
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
	root=btree.insert(1);  //insert root
	
	//left tree
	leaf=btree.insert(2,root);
	btree.insert_nocompare(3,leaf);
	btree.insert_nocompare(4,leaf);
	
	//right tree
	leaf=btree.insert_nocompare(2,root);
	btree.insert_nocompare(4,leaf);
	btree.insert_nocompare(3,leaf);

	/*//Test case3:
	root=btree.insert(1);  //insert root
	
	//left tree
	leaf=btree.insert_nocompare(2,root);
	btree.insert_nocompare('#'-'0',leaf);
	btree.insert_nocompare(3,leaf);
	
	//right tree
	leaf=btree.insert_nocompare(2,root);
	btree.insert_nocompare('#'-'0',leaf);
	btree.insert_nocompare(3,leaf);*/

	
	/*//Test case3:
	root=btree.insert(2);  //insert root
	
	//left tree
	leaf=btree.insert_nocompare(3,root);
	btree.insert_nocompare(4,leaf);
	btree.insert_nocompare(5,leaf);
	
	//right tree
	leaf=btree.insert_nocompare(3,root);
	btree.insert_nocompare('#'-'0',leaf);
	btree.insert_nocompare(4,leaf);*/
	
	return root;
	
}

int main()
{
	Solution solution;
	Btree btree;
	
	bool result=false;
	TreeNode *root;
	TreeNode *root2;
	

	root=btree.contruct_tree();

	result=solution.isSymmetric(root);
	cout<<"result:"<<result<<endl;
	return 0;
}

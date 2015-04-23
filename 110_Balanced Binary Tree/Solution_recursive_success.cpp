#include <iostream>
#include <cstdlib>
#include <stack>
#include <vector>
#include <cmath>
#include <algorithm>
#include "Btree.h"
using namespace std;

/*      
The compariosn of depth is in isBalanced. Comparison is from top to down:
1.Compare from the treeroot
(abs(leftdepth-rightdepth)<=1  compares the subtree of treeroot
2.Use the leaf of tree root to recursive calling isBalanced to find the 
whether the following subtree is balanced
=>The depth of everynode is recaculated.
*/
class Solution {
public:
	int TreeDepth(TreeNode *root) {  
		int node_leftdepth;
		int node_rightdepth;
	    if(root!=NULL) {  
	        
			return 1+max(TreeDepth(root->left),TreeDepth(root->right));
			
		} 
		else	
			return 0; 
	    	
	}  
  
    bool isBalanced(TreeNode *root) {
		
		
		int leftdepth=0;
		int rightdepth=0;

		bool result=true;
		
		if(root!=NULL)
		{
			leftdepth=TreeDepth(root->left);
			rightdepth=TreeDepth(root->right);
			
			if(abs(leftdepth-rightdepth)<=1 && isBalanced(root->left) && isBalanced(root->right))
				return true;
			else
				return false;	
		}
		else
			return true;
			
		

		
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
	leaf=btree.insert_nocompare(11,leaf);
	
	leaf=btree.insert_nocompare(8,root);
	
	/*//Test case2:
	root=btree.insert(5);  //insert root
	
	//left tree
	leaf=btree.insert(4,root);
	btree.insert_nocompare(12,leaf);
	leaf=btree.insert_nocompare(11,leaf);
	btree.insert_nocompare(7,leaf);
	btree.insert_nocompare(2,leaf);
	
	//right tree
	leaf=btree.insert_nocompare(8,root);
	btree.insert_nocompare(13,leaf);
	leaf=btree.insert_nocompare(4,leaf);
	btree.insert_nocompare(1,leaf);
	btree.insert_nocompare(5,leaf);*/
	
	return root;
	
}

int main()
{
	Solution solution;
	Btree btree;
	
	bool result;
	TreeNode *root;
	

	root=btree.contruct_tree();
	result=solution.isBalanced(root);
	
	cout<<"result:"<<result<<endl;
	return 0;
}

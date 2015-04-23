#include <iostream>
#include <cstdlib>
#include <stack>
#include <vector>
#include <cmath>
#include <algorithm>
#include "Btree.h"
using namespace std;

/*      
The compariosn of depth is in TreeDepth. Comparison is from bottom to up:
1.Tree will go down to the end and find the depth of the end of the tree.
Then bottom up to the parent of the leaf to compare length depth and right depth from the treeroot
*/

class Solution {
public:
	
	
	
	int TreeDepth(TreeNode *root) {  
		int leftdepth=0;
		int rightdepth=0;
	    if(root!=NULL) {  
	        
			leftdepth=TreeDepth(root->left);
			rightdepth=TreeDepth(root->right);
			
			if(abs(leftdepth-rightdepth)>1)
				result= false;    //Record the isBalanced result is false
				//Tree is still continued tracing
				
			return 1+max(leftdepth,rightdepth);
			
		} 
		else	
			return 0; 
	    	
	}  
  
    bool isBalanced(TreeNode *root) {
		
		result=true;
		
		if(root!=NULL)
		{
			TreeDepth(root);
			return result;	
		}
		else
			return true;
			
		

		
    }
	private: 
		bool result; //result is class private variable

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

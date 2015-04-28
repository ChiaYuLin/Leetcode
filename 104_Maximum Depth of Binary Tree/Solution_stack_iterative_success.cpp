/*Given a binary tree, find its maximum depth.

The maximum depth is the number of nodes along the longest path from the 

root node down to the farthest leaf node.
*/

#include <iostream>
#include <cstdlib>
#include <stack>
#include <vector>
//#include <limits> 
#include "Btree.h"
using namespace std;

/*
Method:
(1)treestack is used to record the order of the path.
Pop a node and put the left and right child of this node.
(2)mirrorstack records same node with the treestack. But it only pop out when one path is end.
mirrorstack is used to find the node which is going to start next path.
(3)depth records the depth of one subtree.
finaldepth records the minimum depth of the whole tree.
When we arrive the end node of the tree, we compare depth and finaldetph.
If depth is larger, finaldepth is changed to the value of depth.


*/
class Solution {
public:
    int maxDepth(TreeNode *root) {
		int finaldepth=0;  
		int depth=0;
		stack<TreeNode*> mirrorstack; 
		stack<TreeNode*> treestack;
		TreeNode *leaf;
		
		if(root!=NULL)
		{
			treestack.push(root);
		   
			while(!treestack.empty())
			{
				leaf=treestack.top();

				//Back to the leaf which is same with treestack
				//The difference means that the value is still in mirrostack 
				//but has already be pop in treestack
				if(mirrorstack.size()!=0)
				{		
					while(mirrorstack.top()!=leaf)
					{
						depth--;
						mirrorstack.pop();
					}
				}
				
				
				depth++;
		      
		       
				//The pop node is the node which is in current path
				treestack.pop();
				
				
				
				if(leaf->right==NULL && leaf->left==NULL)  //One path to end
				{
					if(depth>finaldepth)
						finaldepth=depth;


					mirrorstack.pop();  //pop out the current node to get back
						
					depth--;

				}
				else
				{
					if(leaf->right!=NULL)
					{
						mirrorstack.push(leaf->right);
						treestack.push(leaf->right);	//Put the right leaf into the stack
					}	

					if(leaf->left!=NULL)
					{
						mirrorstack.push(leaf->left);
						treestack.push(leaf->left);    //Put the left leaf into the stack
					}
						
				}
				
				
					
			}
		}
		else
		{
			finaldepth=0;
		}
		
        return finaldepth;
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
	btree.insert_nocompare(1,leaf);
	leaf=btree.insert_nocompare(5,leaf);
	leaf=btree.insert_nocompare(6,leaf);
	
	return root;
	
}

int main()
{
	Solution solution;
	Btree btree;
	
	int result;
	TreeNode *root;
	

	root=btree.contruct_tree();
	result=solution.maxDepth(root);
	
	cout<<"result:"<<result<<endl;
	return 0;
}

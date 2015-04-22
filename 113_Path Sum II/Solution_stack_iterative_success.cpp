/*Given a binary tree and a sum, determine if the tree has a root-to-leaf path such that adding up all the values along the path equals the given sum.

For example:
Given the below binary tree and sum = 22,
              5
             / \
            4   8
           /   / \
          11  13  4
         /  \      \
        7    2      1
return true, as there exist a root-to-leaf path 5->4->11->2 which sum is 22.

Check the complete path which the sum is equal to the given value.
*/

#include <iostream>
#include <cstdlib>
#include <stack>
#include <vector>
#include "Btree.h"
using namespace std;

/*
Method:
(1)treestack is used to record the order of the path.
Pop a node and put the left and right child of this node.
(2)tmpvector(finalresult) is record the value which is pop out from the treestack. 
That is, tempvector(finalresult) is record the current path.
(3)mirrorstack records same node with the treestack. But it only pop out when one path is end.
mirrorstack is used to find the node which is going to start next path.

*/
class Solution {
public:
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
		int finalresult=0;
		vector<int>tmpvector;
		vector<vector<int> > finalvector;
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
						finalresult=finalresult-mirrorstack.top()->val;
						mirrorstack.pop();
						tmpvector.pop_back();
					}
				}
				
				//Only record the pop value
				tmpvector.push_back(leaf->val);
				finalresult=finalresult+leaf->val;
		      
		       
				//The pop node is the node which is in current path
				treestack.pop();
				
				
				
				if(leaf->right==NULL && leaf->left==NULL)  //One path to end
				{
					if(finalresult==sum)
						finalvector.push_back(tmpvector);


					mirrorstack.pop();  //pop out the current node to get back
						
					tmpvector.pop_back(); //pop out the current value
					finalresult=finalresult-leaf->val;

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
		
        return finalvector;
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
	btree.insert_nocompare(5,leaf);
	
	return root;
	
}

int main()
{
	Solution solution;
	Btree btree;
	
	vector<vector<int> > result;
	TreeNode *root;
	

	root=btree.contruct_tree();
	result=solution.pathSum(root, 22);
	
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

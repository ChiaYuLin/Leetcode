/*Given an array where elements are sorted in ascending order, convert it to a height balanced BST.

*/

#include <iostream>
#include <cstdlib>
#include <queue>
#include <cmath>
#include <vector>
using namespace std;

/*
Chosse the middle of array to be the root.
Use the middle-1 be the left leaf of root, middle+1 be the right leaf of root.
middle-2 be the left leaf of the left leaf of root. middle+2 be the right leaf of the left leaf of root.
This will violate the decipline of BST. The subtree value has to be larger than the right leaf of root.
Therefore, we modify to 

middle-2 be the left leaf of the left leaf of root. middle+2 be the right leaf of the "right" leaf of root.

This will cause unbalanced. The tree will become
   

     10
     / \
    9  11
   /     \
  8      12
 /         \ 
7          13

The subtree of 9 is unbalanced.


*/

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
    TreeNode *sortedArrayToBST(vector<int> &num){
    	int middle=0;
    	TreeNode * root;
    	TreeNode * leaf;
    	queue<TreeNode*> treequeue;
    	int i;

    	if(!num.empty())
    	{
    		middle=num.size()/2;

	    	root=new TreeNode(num[middle]);
			
			treequeue.push(root);

			i=1;
			while(!treequeue.empty())
			{
				leaf=treequeue.front();
				treequeue.pop();

				if((middle-i)>=0)
				{
					insert(num[middle-i],leaf);
					treequeue.push(leaf->left);
				}	
				if((middle+i)<num.size())
				{
					insert(num[middle+i],leaf);
					treequeue.push(leaf->right);
				}

				i++;

			}
    	}

    	


        return root;
    }
	
	void insert(int key, TreeNode *leaf)
	{
		if(key<leaf->val)
		{
			if(leaf->left!=NULL)
				insert(key,leaf->left);
			else
			{
				leaf->left=new TreeNode(key);
			}
		}
		else if(key>=leaf->val)
		{
			if(leaf->right!=NULL)
				insert(key,leaf->right);
			else
			{
				leaf->right=new TreeNode(key);
			}
		}

		return;
	}

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



int main()
{
	Solution solution;
	vector<int> input;
	TreeNode * resulttree;
	vector<vector<int> > result;

	for(int i=0;i<10;i++)
		input.push_back(i);

	resulttree=solution.sortedArrayToBST(input);
	result=solution.levelOrder(resulttree);

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

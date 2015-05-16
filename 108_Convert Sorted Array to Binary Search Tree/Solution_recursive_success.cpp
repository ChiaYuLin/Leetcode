/*Given an array where elements are sorted in ascending order, convert it to a height balanced BST.

*/

#include <iostream>
#include <cstdlib>
#include <queue>
#include <cmath>
#include <vector>
using namespace std;

/*
Use the concept of divide and conquer.

First, pick the middle element as the root of BST.

Second, separate array to 0~middle-1 and middle+1~end and execute recursive to constrcut the tree.


*/



struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	TreeNode *ConstructTree(vector<int> &num,int start,int end){
		TreeNode * root;
		int middle=0;

		if(start==end)
		{
			root=new TreeNode(num[start]);
		   
		}
		else
		{
			if(start==0)
				middle=(end-start)/2;
			else
				middle=(end-start)/2+start;


			root=new TreeNode(num[middle]);


			if(start!=middle)
				root->left=ConstructTree(num,start,middle-1);   //start=middle means there is no element in the left

			root->right=ConstructTree(num,middle+1,end);
		}	
		return root;
	}
    TreeNode *sortedArrayToBST(vector<int> &num){
    	TreeNode * finalresultroot;

    	if(!num.empty())
		    finalresultroot=ConstructTree(num,0,num.size()-1);
		else
			finalresultroot=NULL;

        return finalresultroot;
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

	/*for(int i=0;i<10;i++)
		input.push_back(i);*/

	input.push_back(1);
	input.push_back(3);

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

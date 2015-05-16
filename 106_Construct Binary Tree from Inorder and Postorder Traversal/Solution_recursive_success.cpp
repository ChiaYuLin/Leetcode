/*
Given inorder and postorder traversal of a tree, construct the binary tree.
*/
#include <iostream>
#include <cstdlib>
#include <stack>
#include <vector>
using namespace std;

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/*
The last node of postorder is the tree root. And then the right subtree and. And then the left subtree.
So Find the tree root in "Inorder." Creat the parent node.
And go right subtree first. When the right subtree, go left subtree.


*/


class Solution {
public:
	TreeNode* build(vector<int>& postorder, vector<int>& inorder,int inorder_start,int inorder_end){

		TreeNode* root;


		if(inorder_start==inorder_end)
		{
			root=new TreeNode(postorder[root_position]);
			return root;
		}
		else
		{
			for(int j=inorder_start;j<=inorder_end;j++)
			{
				if(inorder[j]==postorder[root_position])  //The position of parent
				{
					root=new TreeNode(postorder[root_position]);
					if(root_position-1>=0)
					{
						if(j+1<=inorder_end)
						{
							root_position--;
							root->right=build(postorder,inorder,j+1,inorder_end);
						}
						
					}

						
					if(root_position-1>=0)
					{
						if(inorder_start<=j-1)
						{
							root_position--;
							root->left=build(postorder,inorder,inorder_start,j-1);
						}
						
					}	

					break;
						

				}
					
			}

			
			return root;
		}
		
	}
	TreeNode* buildTree(vector<int>& inorder,vector<int>& postorder)  {
		TreeNode* root;

		root_position=postorder.size()-1;

		root=build(postorder,inorder,0,inorder.size()-1);	

		return root;
	}



	vector<int> postorderTraversal(TreeNode *root)  
	{
		stack<TreeNode*> treestack;

		vector<int>  finalresult;

		TreeNode* current;
		TreeNode* lastpushnode;

		if(root!=NULL)
		{
			current=root;

			treestack.push(current);

			current=current->left;

			while(!treestack.empty())
			{
				while(current!=NULL)   
				{
					treestack.push(current);
					current=current->left;
				}


				current=treestack.top()->right;  //Go to the right subtree.

				//current==NULL means the right child is NULL.	
				//current==lastnode means the right node has push in finalresult
				if(current==NULL || current==lastpushnode)   
				{
					finalresult.push_back(treestack.top()->val);
					lastpushnode=treestack.top();
					treestack.pop();
					current=NULL;   //If current==lastnode
				}
		
			}

			return finalresult;
		}
		else
			return finalresult;
		
		
	}
private:
	int root_position;
    

};



int main()
{
	Solution solution;
	TreeNode *resultroot;
	vector<int> result;
	
	/*//Testcase1:
	int myints[] = {8,10,11,9,4,5,2,6,7,3,1};
	int myints2[] = { 8,4,10,9,11,2,5,1,6,3,7};*/

	int myints[] = {1,2,3,4};
	int myints2[] = {3,4,2,1};

	//vector<int> preorder=(myints, myints + sizeof(myints) / sizeof(int));
	//vector<int> inorder=(myints2, myints2 + sizeof(myints2) / sizeof(int));
	vector<int> postorder;
	vector<int> inorder;

	inorder.insert(inorder.end(), &myints[0], &myints[sizeof(myints) / sizeof(int)]);
	postorder.insert(postorder.end(), &myints2[0], &myints2[sizeof(myints2) / sizeof(int)]);
	
	resultroot=solution.buildTree(inorder,postorder);
	
	result=solution.postorderTraversal(resultroot);
	for(vector<int>::iterator it2=result.begin();it2!=result.end();it2++)
	{
		cout<<*it2<<",";
	}
    cout<<endl;



	return 0;
}

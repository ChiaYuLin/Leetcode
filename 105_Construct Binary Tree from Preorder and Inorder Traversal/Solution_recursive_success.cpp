/*Given a binary tree, return the preorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},
   1
    \
     2
    /
   3
return [1,2,3].
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
The first node of preorder is the tree root. And then the left subtree and. And then the right subtree.
So Find the tree root in "Inorder." Creat the parent node.
And go left subtree first. When the left subtree, go right subtree.

*/


class Solution {
public:
	TreeNode* build(vector<int>& preorder, vector<int>& inorder,int inorder_start,int inorder_end){

		TreeNode* root;


		if(inorder_start==inorder_end)
		{
			root=new TreeNode(preorder[root_position]);
			return root;
		}
		else
		{
			for(int j=inorder_start;j<=inorder_end;j++)
			{
				if(inorder[j]==preorder[root_position])  //The position of parent
				{
					root=new TreeNode(preorder[root_position]);
					if(root_position+1<preorder.size())
					{
						if(inorder_start<=j-1)
						{
							root_position++;
							root->left=build(preorder,inorder,inorder_start,j-1);
						}
						
					}

						
					if(root_position+1<preorder.size())
					{
						if(j+1<=inorder_end)
						{
							root_position++;
							root->right=build(preorder,inorder,j+1,inorder_end);
						}
						
					}	

					break;
						

				}
					
			}

			
			return root;
		}
		
	}
	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder)  {
		TreeNode* root;

		root_position=0;

		root=build(preorder,inorder,0,inorder.size()-1);	

		return root;
	}

	vector<int> preorderTraversal(TreeNode *root)  
	{
		stack<TreeNode*> treestack;

		vector<int>  finalresult;

		TreeNode* current;
		TreeNode* top;

		if(root!=NULL)
		{
			
			treestack.push(root);


			while(!treestack.empty())
			{
				
				top=treestack.top();
				finalresult.push_back(top->val);
				treestack.pop();

				if(top->right!=NULL)
					treestack.push(top->right);
				if(top->left!=NULL)
					treestack.push(top->left);
				
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
	
	//Testcase1:
	/*int myints[] = {1,2,4,8,9,5,10,11,3,6,7};
	int myints2[] = {8,4,9,2,10,5,11,1,6,3,7};*/

	int myints[] = {1,2};
	int myints2[] = {1,2};

	//vector<int> preorder=(myints, myints + sizeof(myints) / sizeof(int));
	//vector<int> inorder=(myints2, myints2 + sizeof(myints2) / sizeof(int));
	vector<int> preorder;
	vector<int> inorder;

	preorder.insert(preorder.end(), &myints[0], &myints[sizeof(myints) / sizeof(int)]);
	inorder.insert(inorder.end(), &myints2[0], &myints2[sizeof(myints2) / sizeof(int)]);
	
	resultroot=solution.buildTree(preorder,inorder);
	
	result=solution.preorderTraversal(resultroot);

	for(vector<int>::iterator it2=result.begin();it2!=result.end();it2++)
	{
		cout<<*it2<<",";
	}


	return 0;
}

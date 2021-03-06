/*Given a binary tree, return the postorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},
   1
    \
     2
    /
   3
return [3,2,1].
*/
#include <iostream>
#include <cstdlib>
#include <stack>
#include <vector>
#include "Btree.h"
using namespace std;

/*
Use two stack: treestack and rootstack.
Treestack is the order of tree traversal. 
Rootstack stores the node pop from treestack. That is, stores the parent node.


Go left subtree all the way down.

And go back to the parent. Put parent to the rootstack.

Go the right subtree.

And repeat to left subtree tracing again.

After the right subtree is finished. 
(Compare the top of treestack and rootstack. If the node is same, it represents the right subtree traversal is finiahed.)
If the node is same, pop the node from treestack as well as rootstack and push it into finalresult.

We use the rootstack to check whether the traversal is finished the right subtree tracing.


*/



class Solution {
public:

	vector<int> postorderTraversal(TreeNode *root)  
	{
		stack<TreeNode*> treestack;
		stack<TreeNode*> rootstack;

		vector<int>  finalresult;

		TreeNode* current;
		TreeNode* top;

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

				top=treestack.top();


				while(!rootstack.empty())
				{
					if(top==rootstack.top())
					{
						finalresult.push_back(top->val);
						treestack.pop();
						rootstack.pop();

						if(!treestack.empty())
							top=treestack.top();
						else  //Whole tree traversal is finished. The root of the tree is pushed to finalresult.
							top=NULL;
					}
					else
						break;
				}	
				


				if(top==NULL)
					break;


				rootstack.push(top);  //If the top of treestack and rootstack is different, push the top of treestack into rootstack.

				current=top->right;  //Go to the right subtree.


				if(treestack.size()==0 && top->right!=NULL)  //push right leaf of root into stack
				{
					treestack.push(top->right);
					current=top->right->left;
				}
				
			}

			return finalresult;
		}
		else
			return finalresult;
		
		
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
	btree.insert_nocompare(9,leaf);
	leaf=btree.insert_nocompare(1,leaf);
	
	return root;
	
}

int main()
{
	Solution solution;
	Btree btree;
	
	vector<int> result;
	TreeNode *root;
	

	root=btree.contruct_tree();
	result=solution.postorderTraversal(root);
	
	for(vector<int>::iterator it2=result.begin();it2!=result.end();it2++)
	{
		cout<<*it2<<",";
	}

	return 0;
}

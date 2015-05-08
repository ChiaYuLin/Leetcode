/*Given a singly linked list where elements are sorted in ascending order, convert it to a height balanced BST..

*/

#include <iostream>
#include <cstdlib>
#include <vector>
#include <queue>
using namespace std;

/*
Bottom up:

We construct the node by the order of list.
Use the location of start and end to make the list become half. 
But we don't move the head during recursive.

After the left subtree finish, we construct the node,move the head to the next and start to constuct the right subtree.

The head of list should be set in general variable. Otherwise, it only moves in the recursive function.


Performance:
we don't have to iterate through half of list to find the middle element.
T(n) = 2T(n) + O(1) = O(n)!

Reference: http://n00tc0d3r.blogspot.com/2013/02/covert-sorted-arraylist-to-bst.html


*/

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	TreeNode *ConstructTree(int start,int end){
		TreeNode *left;
		TreeNode *right;
		TreeNode *root;
		int middle;


		if(start>end)
			return NULL;	
		else
		{
			middle=start+(end-start)/2;

    		left=ConstructTree(start,middle-1);  //head points to the first element
    		
    		root=new TreeNode(generalhead->val);

    		root->left=left;


    		generalhead=generalhead->next;

    		root->right=ConstructTree(middle+1,end);
	
		
		}	
		return root;
	}


    TreeNode *sortedListToBST(ListNode *head){
    	TreeNode *finalresultroot;
    	ListNode *count=head;
    	ListNode *lefthead=head;

    	int length=0;

    	while(count!=NULL)
    	{
    		length++;
    		count=count->next;
    	}

    	if(head!=NULL)
    	{
    		generalhead=head;
    		finalresultroot=ConstructTree(1,length);  //head points to the first element
    	}
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

    private:
    ListNode *generalhead;

};



int main()
{
	Solution solution;
	TreeNode * resulttree;
	vector<vector<int> >result;
	ListNode *input;
	ListNode *head;

	head=new ListNode(1);
	input=head;

	//head->next=new ListNode(5);
	//head->next->next=new ListNode(8);


	for(int i=2;i<=10;i++)
	{
		head->next=new ListNode(i);
		head=head->next;
	}
	


	resulttree=solution.sortedListToBST(input);
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

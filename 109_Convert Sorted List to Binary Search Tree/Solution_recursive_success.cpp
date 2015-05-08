/*Given a singly linked list where elements are sorted in ascending order, convert it to a height balanced BST..

*/

#include <iostream>
#include <cstdlib>
#include <vector>
#include <queue>
using namespace std;

/*
Top Down:

Find the middle of list. 
Move the head to the middle location.
Construct the node.
Go to the left tree. (The start node of left tree is the first node.)

head=head->next
Go to the right tree.(The start node of right tree is the next node of middle node.)


Performance:
we have to iterate through half of list to find the middle element.
To build up the BST, T(n) = 2T(n/2) + n/2 = O(nlogn). So, in total, O(nlogn).

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
	TreeNode *ConstructTree(ListNode *head,int length){
		TreeNode *root;
		ListNode *lefthead=head;


		if(length<=1)
			root=new TreeNode(head->val);	
		else
		{
			for(int i=0;i<length/2;i++)  //Move head to the middle
    			head=head->next; 

			root=new TreeNode(head->val);

			if(lefthead!=head)
    			root->left=ConstructTree(lefthead,length/2);  //head points to the first element
    		



    		head=head->next; 
    		if(length%2==0)
    		{
    			if(length/2-1!=0)  //If length is 2, only root->left has element
    				root->right=ConstructTree(head,length/2-1);  //head points to the first element
    		}	
    		else  //If length is 3, root->left has one element and root->right has one element
    			root->right=ConstructTree(head,length/2);  //head points to the first element

    		
		
		
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
    		finalresultroot=ConstructTree(head,length);  //head points to the first element

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
	TreeNode * resulttree;
	vector<vector<int> >result;
	ListNode *input;
	ListNode *head;

	head=new ListNode(1);
	input=head;

	//head->next=new ListNode(5);
	//head->next->next=new ListNode(8);


	for(int i=2;i<=9;i++)
	{
		head->next=new ListNode(i);
		head=head->next;
	}
	

    cout<<"input->next->val:"<<input->next->next->val<<endl;
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

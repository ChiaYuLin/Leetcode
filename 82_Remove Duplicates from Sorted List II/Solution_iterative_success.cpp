/*
Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.

For example,
Given 1->2->3->3->4->4->5, return 1->2->5.
Given 1->1->1->2->3, return 2->3.

*/
#include <iostream>
#include <cstdlib>

using namespace std;




struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

/*
We check whether the head and the next of head is the same.

If they are same, we check whether the next next of head is different.

If it is different, we can delete two nodes at a time.
If it is not different, delete one node at a time.

*/


 
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
    	bool duplicateflag=false;
    	ListNode* prev;   
    	ListNode* result;

    	if(head!=NULL)
    	{

    		result=head;

    		prev=head;
	    	while(head!=NULL && head->next!=NULL)    	
	    	{
	    		if(head->val==head->next->val)  //Check whether the node and next node is deuplicated
	    		{
	    			if(head->next->next!=NULL)
	    			{
	    				if(head->val!=head->next->next->val) //If the node is different from the next next node, we can delete two nodes at a time.
		    			{    				
		    				if(prev==head)  //The head value is duplicated. Prev points to head->next->next (Same with head)
		    				{	
		    					prev=head->next->next; //Make the starting point jump over two duplicated node.
		    					result=head->next->next;   
		    				}
		    				else
		    					prev->next=head->next->next;  //prev is still be the previous value.
		    				
		    				head=head->next->next;
		    			}
		    		    else  ////The head value is duplicated but the following is the same value node.
		    			{
		    				if(prev==head)  //Make the starting point jump over one duplicated node. 
		    				{
		    					prev=head->next;
		    					result=head->next;
		    					
		    				}
		    				else
		    					prev->next=head->next;   //go step by step to delete the node. Delete one node at a time.
 
		    				head=head->next;
		    			}
	    			}
	    			else
	    			{
	    				if(prev==head)  //The head value is duplicated. Prev points to head->next->next (Same with head)
		    			{	
		    				result=NULL;
		    				return result;   
		    			}
		    			else
		    			{
		    				prev->next=head->next->next;  //prev is still be the previous value.
		    				head=head->next->next;
	    				}
	    			}

	    				
	    				
	    		}
	    		else
	    		{
	    			prev=head;
	    			head=head->next;
	    		}
	    				    		
	    	}

	    	return result;
    	}
		else
			return NULL;
        
    }

    
};


int main()
{
	Solution solution;
	

    ListNode *result;
    ListNode *input1;
	ListNode *head1;
	
    /*
    //Testcase1:
	head1=new ListNode(1);
	input1=head1;

	head1->next=new ListNode(1);
	head1=head1->next;

	head1->next=new ListNode(2);
	head1=head1->next;

	head1->next=new ListNode(3);
	head1=head1->next;

	head1->next=new ListNode(3);
	head1=head1->next;*/

	//Testcase2:
	head1=new ListNode(1);
	input1=head1;

	head1->next=new ListNode(1);
	head1=head1->next;

	head1->next=new ListNode(1);
	head1=head1->next;

	head1->next=new ListNode(1);
	head1=head1->next;
	
	result=solution.deleteDuplicates(input1);

	while(result!=NULL)
  	{
    	cout<<result->val<<endl;
    	result=result->next;
    } 



}
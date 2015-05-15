/*
Given a sorted linked list, delete all duplicates such that each element appear only once.

For example,
Given 1->1->2, return 1->2.
Given 1->1->2->3->3, return 1->2->3.

*/
#include <iostream>
#include <cstdlib>

using namespace std;




struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
    	int duplicatevalue;
    	ListNode* prev;
    	ListNode* result;

    	if(head!=NULL)
    	{

    		result=head;

    		duplicatevalue=head->val;
    		prev=head;
    		head=head->next;
	    	while(head!=NULL)    	
	    	{
	    		if(head->val==duplicatevalue)
	    			prev->next=head->next;   //prev is still be the previous value.
	    		else
	    		{
	    			prev=head;
	    			duplicatevalue=head->val;
	    		}
	    			

	    		head=head->next;
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
	

	head1=new ListNode(1);
	input1=head1;

	head1->next=new ListNode(1);
	head1=head1->next;

	head1->next=new ListNode(2);
	head1=head1->next;

	head1->next=new ListNode(2);
	head1=head1->next;

	head1->next=new ListNode(3);
	head1=head1->next;

	head1->next=new ListNode(3);
	head1=head1->next;

	
	result=solution.deleteDuplicates(input1);

	while(result!=NULL)
  	{
    	cout<<result->val<<endl;
    	result=result->next;
    } 



}
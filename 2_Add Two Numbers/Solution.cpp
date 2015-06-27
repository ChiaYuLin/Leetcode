/*
You are given two linked lists reheadsenting two non-negative numbers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8

Notice: The result add from left to right.
2+5=7
4+6=10 =>10%10=0
3+4=7 7+1=8
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
Add the value of two lists.
If the sum is bigger than 10, the result list value become sum%10.
And set carry equal to sum/10.

*/

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* result;
        ListNode* head;
        int carry=0;
        
        
        if(l1!=NULL)
        {
        	
        	head=new ListNode(0);
        	head->next=new ListNode(0);
        	result=head->next;

	        while(l1!=NULL && l2!=NULL)
	        {
	        	if(head->next!=NULL)   //Only for the first time while loop since we put head->next=new ListNode(0)
	        		head->next->val=l1->val+l2->val+carry;
	        	else
	        		head->next=new ListNode(l1->val+l2->val+carry);
	        		
	        	if(head->next->val>=10)
	        	{
	        		carry=head->next->val/10;
	        		head->next->val=head->next->val%10;	        			
	        	}
	        	else
	        		carry=0;
	        		

	        	head=head->next;
	        	l1=l1->next;
	        	l2=l2->next;
	        }

	        if(l1!=NULL || l2!=NULL)
	        {
	        	if(l1!=NULL)
	        		head->next=l1;
	        	else if(l2!=NULL)
	        		head->next=l2;

	        	head->next->val=head->next->val+carry;
	        	
	        	if(head->next->val>=10)
	        	{
	        		carry=head->next->val/10;
	        		head->next->val=head->next->val%10;	        			
	        	}
	        	else
	        		carry=0;

	        	head=head->next;
	        	while(carry!=0)
	        	{
	        		if(head->next!=NULL)
	        		{
	        			head->next->val=head->next->val+carry;
			        	if(head->next->val>=10)
			        	{
			        		carry=head->next->val/10;
			        		head->next->val=head->next->val%10;	        			
			        	}
			        	else
			        		carry=0;
			        }
			        else
			       	{
			       		head->next=new ListNode(carry);
			       		carry=0;
			       	}
			       	head=head->next;
	        	}
	        }	        	
	        else if(carry!=0)
			    head->next=new ListNode(carry);


	        return result;
        }
        else 
        	return NULL;
        
    }
};

int main()
{
	Solution solution;
	ListNode* result;
	ListNode* input1;
	ListNode* input2;
	ListNode* head1;
	ListNode* head2;

	
	//Testcase1:
	head1=new ListNode(9);
	input1=head1;

	head1->next=new ListNode(8);
	head1=head1->next;

	head2=new ListNode(1);
	input2=head2;
	

	/*
	//Testcase2:
	head1=new ListNode(2);
	input1=head1;

	head1->next=new ListNode(4);
	head1=head1->next;

	head1->next=new ListNode(3);
	head1=head1->next;

	head2=new ListNode(5);
	input2=head2;

	head2->next=new ListNode(6);
	head2=head2->next;

	head2->next=new ListNode(4);
	head2=head2->next;
	*/
	
	head1=new ListNode(9);
	input1=head1;

	head1->next=new ListNode(8);
	head1=head1->next;
	
	head2=new ListNode(1); 
	input2=head2;
	//output:[0 9]
	
	result=solution.addTwoNumbers(input1,input2);
	while(result!=NULL)
  	{
    	cout<<result->val<<endl;
    	result=result->next;
    } 

}
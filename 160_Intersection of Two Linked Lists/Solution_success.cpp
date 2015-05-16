/*Write a program to find the node at which the intersection of two singly linked lists begins.


For example, the following two linked lists:

A:          a1 → a2
                   ↘
                     c1 → c2 → c3
                   ↗            
B:     b1 → b2 → b3
begin to intersect at node c1.


Notes:

If the two linked lists have no intersection at all, return null.
The linked lists must retain their original structure after the function returns.
You may assume there are no cycles anywhere in the entire linked structure.
Your code should preferably run in O(n) time and use only O(1) memory.
*/
#include <iostream>
#include <cstdlib>

using namespace std;

/*
Compute the length of listA and listB.
Make the larger one go first.
When the rest of length of two list is equal, compare the node of listA and listB.
O(n+m+n) running time, O(1) space
*/


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lengthA=0;
        int lengthB=0;
        int finalstep=0;
        ListNode *tmpA;
        ListNode *tmpB;

        if(headA!=NULL && headB!=NULL)
        {
        	tmpA=headA;
	        while(tmpA!=NULL)
	        {
	        	lengthA++;
	        	tmpA=tmpA->next;
	        }

	        tmpB=headB;
	        while(tmpB!=NULL)
	        {
	        	lengthB++;
	        	tmpB=tmpB->next;
	        }

	        if(lengthA>lengthB)
	        {
	        	for(int i=0;i<lengthA-lengthB;i++)
	        		headA=headA->next;

	        	finalstep=lengthB;
	        }
	        else if(lengthB>lengthA)
	        {
	        	for(int i=0;i<lengthB-lengthA;i++)
	        		headB=headB->next;

	        	finalstep=lengthA;
	        }
	        else //lengthA==lengthB
	        	finalstep=lengthA;

	        for(int i=0;i<finalstep;i++)
	        {
	        	if(headA==headB)
	        		return headA;
	        	else
	        	{
	        		headA=headA->next;
	        		headB=headB->next;
	        	}
	        }

	        //No intersection
	        return NULL;

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
	ListNode *input2;
	ListNode *head2;
	ListNode *intersect;

	head1=new ListNode(1);
	input1=head1;


	for(int i=2;i<=3;i++)
	{
		head1->next=new ListNode(i);
		head1=head1->next;
	}

	head2=new ListNode(6);
	input2=head2;


	for(int i=7;i<=10;i++)
	{
		head2->next=new ListNode(i);
		head2=head2->next;
	}
	
	for(int i=11;i<=15;i++)
	{
		intersect=new ListNode(i);
		head1->next=intersect;
		head1=head1->next;
		head2->next=intersect;
		head2=head2->next;
	}
	


	result=solution.getIntersectionNode(input1,input2);


	cout<<result->val<<endl;

}
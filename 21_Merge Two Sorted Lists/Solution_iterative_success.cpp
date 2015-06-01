/*
Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.
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
Newhead is the head of new combine list and newtail is the tail of new combine list.
We compare the value of l1 and l2. Put the smaller node into the next of newtail.

*/


class Solution {
public:
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		ListNode* newhead=NULL;
		ListNode* newtail=NULL;


		while(l1!=NULL || l2!=NULL)
		{
			
			if(l1==NULL) //push righthead
			{
				if(newhead==NULL)
					return l2;
				else
				{
					newtail->next=l2; //Connect the righthead to the next of newhead
					return newhead;
				}
			}
			else if(l2==NULL)
			{
				if(newhead==NULL)
					return l1;
				else
				{
					newtail->next=l1; //Connect the righthead to the next of newhead
					return newhead;
				}
			}
			else  //leafhead and righthead are not NULL
			{
				
				if(l1->val <= l2->val)
				{
					if(newhead==NULL)
					{
						newhead=l1;
						newtail=l1;
					}		
					else
					{
						newtail->next=l1;
						newtail=newtail->next;
					}

					l1=l1->next;

				}
				else  //righthead->val < lefthead->val
				{
					
					if(newhead==NULL)
					{
						newhead=l2;
						newtail=l2;
					}		
					else
					{
						newtail->next=l2;
						newtail=newtail->next;
					}

					l2=l2->next;
				}
				
			}
		}

		return newhead;
	}

};

int main()
{
	Solution solution;
	ListNode* result;
	ListNode* input1;
	ListNode* head1;
	ListNode* input2;
	ListNode* head2;

	
	/*
	//Testcase1:
	head1=new ListNode(3);
	input1=head1;

	head1->next=new ListNode(2);
	head1=head1->next;

	head1->next=new ListNode(8);
	head1=head1->next;

	head1->next=new ListNode(4);
	head1=head1->next;

	head1->next=new ListNode(7);
	head1=head1->next;

	head1->next=new ListNode(5);
	head1=head1->next; */
	

    
    //Testcase2:
	head1=new ListNode(1);
	input1=head1;

	head1->next=new ListNode(3);
	head1=head1->next;

	head1->next=new ListNode(5);
	head1=head1->next;

	head1->next=new ListNode(7);
	head1=head1->next;

	head2=new ListNode(2);
	input2=head2;

	head2->next=new ListNode(4);
	head2=head2->next;

	head2->next=new ListNode(6);
	head2=head2->next;

	head2->next=new ListNode(8);
	head2=head2->next;
	

	
	result=solution.mergeTwoLists(input1,input2);

	while(result!=NULL)
  	{
    	cout<<result->val<<endl;
    	result=result->next;
    } 

}

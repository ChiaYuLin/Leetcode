/*
Given a linked list, remove the nth node from the end of list and return its head.

For example,

   Given linked list: 1->2->3->4->5, and n = 2.

   After removing the second node from the end, the linked list becomes 1->2->3->5.

Note:
Given n will always be valid.
Try to do this in one pass.

*/



#include <iostream>
#include <cstdlib>

using namespace std;

/*
Use two pointers:fast and slow.
We set a variable (count) equal to n. 
Count will decrease one when fast go to next.
When count<=0, slow starts to move. 
By this method, the distance of slow and fast will be n.
Therefore, after the loop, the slow will point to the previous node of the removed node.

*/



struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *dummy;
        ListNode *fast;
        ListNode *slow;
        int count=0;

        if(head!=NULL)
        {
          
          dummy=new ListNode(0);
          dummy->next=head;
          count=n;
          fast=dummy;
          slow=dummy;
          while(fast->next!=NULL)
          {
            if(count<=0)
              slow=slow->next;

            fast=fast->next;

            count--;
          }

          //slow will pointer to the previous node of removed node.
          if(slow->next!=NULL)
            slow->next=slow->next->next;   //remove the nth node

          //If slow still points to dummy. That is, when jump out the loop, the count is not smaller or equal to 0.
         //Therefore, the original head is changed.
          if(slow==dummy)    
            head=slow->next;

          return head;
        }
        else
          return NULL;
        


    } 
};

int main()
{
	Solution solution;
  ListNode* result;
  ListNode* input;
	ListNode* head=new ListNode(1);
	input=head;

  head->next=new ListNode(2);
    head=head->next;

	/*for(int i=2;i<=5;i++)
	{
		head->next=new ListNode(i);
		head=head->next;
	}*/
	
 
	result=solution.removeNthFromEnd(input,2);

  while(result!=NULL)
  {
    cout<<result->val<<endl;
    result=result->next;
  } 


}
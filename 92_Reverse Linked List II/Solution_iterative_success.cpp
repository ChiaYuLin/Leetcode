/*Reverse a linked list from position m to n. Do it in-place and in one-pass.

For example:
Given 1->2->3->4->5->NULL, m = 2 and n = 4,

return 1->4->3->2->5->NULL.

Note:
Given m, n satisfy the following condition:
1 ≤ m ≤ n ≤ length of list.
*/

#include <iostream>
#include <cstdlib>

using namespace std;

/*
Cut sublist and put sublist into "reverse" function to reverse.
"Subhead" presents the previous node of sublist head.
"Subtail" presents the next node of sublist tail.


*/



struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };

class Solution {
public:
    ListNode* reverse(ListNode* head)
    {
        ListNode* prev;
        ListNode* prev2;

        if(head!=NULL)
        {
          prev=head;

          if(head->next!=NULL)
            prev2=head->next;
          else
            return head;

          head=head->next->next;


          prev->next=NULL;  //Make the next of first noed becomes NULL. Otherwise the first node and second node will become loop.

          while(head!=NULL)
          {
   
            prev2->next=prev;
            
            prev=prev2;
            prev2=head;

            head=head->next;

          }


          prev2->next=prev;
          return prev2;
        }
        else
          return head;
    }
    ListNode* reverseBetween(ListNode* head, int m, int n){
        ListNode* start=NULL;
        ListNode* subhead=NULL;
        ListNode* subtail=NULL;
        ListNode* newsubhead=NULL;

        if(head!=NULL)
        {
          start=head;
          
          if(m!=n)  //If m==n, don't need to reverse.
          {
            subhead=head;  //If m==1,subhead=head. Otherwise, the subhead will be modified in the for loop.
            for(int i=1;i<=n;i++)
            {
              if(i==m-1)  //"Subhead" presents the previous node of sublist head.
                subhead=head;
              else if(i==n) 
              {
                subtail=head->next;   //"Subtail" presents the next node of sublist tail.
                head->next=NULL;    //Cut the sublist
              }

              head=head->next;
            }

            if(m==1)  //The newsubhead is the head of list. We only need to change the next node of newtail
            {
              newsubhead=reverse(subhead);
              if(subtail!=NULL)   //Tail: After reverse, subhead becomes the tail. Thus, we change the subhead->next.
                subhead->next=subtail;  
            }
            else  
            {
              newsubhead=reverse(subhead->next);
              if(subtail!=NULL) //"subtail!=NULL" represents the tail of sublist is not the tail of list.
                subhead->next->next=subtail;   //Tail: The next node of tail of sublist is subtail.

                subhead->next=newsubhead;  //Head: The newhead becomes the next node of subhead.
            }


            if(m==1) //If m==1,the newsubhead becomes head.
              start=newsubhead;

          }

          return start;
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

  head->next=new ListNode(3);
  head=head->next;

	/*
  //Testcase1:
  for(int i=2;i<=5;i++)
	{
		head->next=new ListNode(i);
		head=head->next;
	}*/

  //Testcase2:
  //[5], 1, 1
	
 
  //Testcase3:
  //[3,5], 1, 1

  //Testcase4:
  //[3,5], 1, 2  

  //Testcase5:
  //[1,2,3], 1, 2  
	result=solution.reverseBetween(input,1,2);

  while(result!=NULL)
  {
    cout<<result->val<<endl;
    result=result->next;
  } 


}
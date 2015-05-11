#include <iostream>
#include <cstdlib>

using namespace std;

/*
prev is the first node.
prev2 is the second node.

prev goes after prev2. prev2 goes after head.

Thus, we change the next of prev2 to prev everytime.


*/


struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
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
};

int main()
{
	Solution solution;
  ListNode* result;
  ListNode* input;
	ListNode* head=new ListNode(1);
	input=head;


	for(int i=2;i<=3;i++)
	{
		head->next=new ListNode(i);
		head=head->next;
	}
	
 
	result=solution.reverseList(input);

  while(result!=NULL)
  {
    cout<<result->val<<endl;
    result=result->next;
  } 


}
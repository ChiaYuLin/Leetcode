/*
Given a singly linked list L: L0→L1→…→Ln-1→Ln,
reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…

You must do this in-place without altering the nodes' values.

For example,
Given {1,2,3,4}, reorder it to {1,4,2,3}.

*/



#include <iostream>
#include <cstdlib>

using namespace std;

/*
Use recursive function to find the tail of reorderlist.
If the length of original list is odd, the tail will be the last input head of recursive function.
If the length of original list is even, the tail will be the next of last input head of recursive function.
After find the tail, the tail->next is the node which is going to move.
The node will be moved to the next of head.

For example:
1->2->3->4->5->6
After recursive, return tail=4.
5 will be the node which is goin to move.
Now the head is 2.
Thus, we can get 1->2->5->3->4->6.

Next, tail is still 4.
The node which is going to move is 6.
Now the head is 1.
Thus, we can get 1->6->2->5->3->4.
*/



struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };

class Solution {
public:
    ListNode* reorder(ListNode* head,int length){
      ListNode* tail;
      ListNode* move;

      if(length==1)   //For odd length
        return head;
      else if(length==2)   //For even length
        return head->next;
      else
      {
        tail=reorder(head->next,length-2);  //length-2 represents take the head and the last node out.
        move=tail->next;
        tail->next=tail->next->next;    //The next of tail becomes tail->next->next.
        move->next=head->next;         //The next of move node is the next of head.
        head->next=move;              //The move node becomes the next of head.

        return tail;
      }

    }

    void reorderList(ListNode* head) {
        ListNode* tmp;
        int length=0;

        if(head!=NULL)
        {
          tmp=head;
          while(tmp!=NULL)
          {
            length++;
            tmp=tmp->next;
          }

          tmp=reorder(head,length);
  
        }
        
        return;
       
    }
};

int main()
{
	Solution solution;
  ListNode* result;
  ListNode* input;
	ListNode* head=new ListNode(1);
	input=head;


	
  //Testcase1:
  for(int i=2;i<=5;i++)
	{
		head->next=new ListNode(i);
		head=head->next;
	}

  /*
  //Testcase2:[1 2] 
  head->next=new ListNode(2);
  head=head->next;
	*/
 
	solution.reorderList(input);

  while(input!=NULL)
  {
    cout<<input->val<<endl;
    input=input->next;
  } 


}
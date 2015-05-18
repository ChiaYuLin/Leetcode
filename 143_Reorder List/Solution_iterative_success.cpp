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
Count the length first. 
Seperate the list to two. 
Put the second part list (length/2+1~end) to the reverseList function to reverse the list.
Use the original list and reversed list to execute reordering.

For example:
1->2->3->4->5->6
=>  1->2->3  and 6->5->4
=>  1->6->2->3 and 5->4
=>  1->6->2->5->3 and 4
=>  1->6->2->5->3->4

*/



struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };

class Solution {
public:
     ListNode* reverseList(ListNode* head) {
        ListNode* newhead;
        ListNode* node;

        if(head==NULL || head->next==NULL)  //The lastnode will fit in with "head->next==NULL" and return itself.
          return head;

        node=head->next;
        head->next=NULL;

        newhead=reverseList(node);   //Start from the second node. The newhead is the lastnode.

        node->next=head;


        return newhead;  //The newhead which is the lastnode will be returned every round.
       

    }
    void reorderList(ListNode* head) {
        ListNode* tmp;
        ListNode* reversehead;
        ListNode* nextreversehead;
        int length=0;

        if(head!=NULL)
        {
          tmp=head;
          while(tmp!=NULL)
          {
            length++;
            tmp=tmp->next;
          }

          tmp=head;
          if(length%2!=0) 
            length++;

          for(int i=0;i<length/2-1;i++)   //Find the start node which is goind to reverse
            tmp=tmp->next;

          
          reversehead=reverseList(tmp->next);
          tmp->next=NULL;

          for(int i=0;i<length/2;i++)   //Find the start node which is goind to reverse
          {
            if(reversehead!=NULL)
            {
              nextreversehead=reversehead->next;
              reversehead->next=head->next;
              head->next=reversehead;
              head=reversehead->next;
              reversehead=nextreversehead;  
            }
            
          }

          return;
        }
       
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
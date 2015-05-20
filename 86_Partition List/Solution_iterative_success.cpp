/*
Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.

You should preserve the original relative order of the nodes in each of the two partitions.

For example,
Given 1->4->3->2->5->2 and x = 3,
return 1->2->2->4->3->5.
*/

#include <iostream>
#include <cstdlib>

using namespace std;

/*
Smallhead is the tail of node which is smaller than target value.
Bighead is the head of node which is bigger than target value.
If the node is smaller than the target value, move the node to the next of smallhead.
The next of node is bighead and the node becomes smallhead.

For example:
1->4->3->2->5->2
1 is smallhead. 4 is bighead.
When current is in 3, continue.
When current is in 2, move 2 to the next of 1. The next of 2 is 4.
=>1->2->4->3->5->2

*/




struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };

class Solution {
public:
    ListNode* partition(ListNode* head, int x){
      ListNode* smallhead=NULL;
      ListNode* bighead=NULL;
      ListNode* current=NULL;


      if(head!=NULL)
      {

        //Decide the head is smallhead or bighead
        if(head->val < x)
          smallhead=head;
        else
          bighead=head;

        current=head;
        while(current->next!=NULL)   //Check the current->next
        {
          if(current->next->val < x)
          {
            if(smallhead==NULL)   //If we haven't assigned smallhead, the current->next is smallhead.
            {
              smallhead=current->next;    
              current->next=current->next->next;   //The node will be moved so the current->next becomes current->next->next.
              smallhead->next=bighead;
              head=smallhead;

              //Since the current->next is moved, the current pointer doesn't need to move.(We don't execute current=current->next)
              //So we can check the current->next, which is the current->next->next orginally.
            }
            else
            {
              if(smallhead->next!=current->next)  //Move the node to the next of smallhead and the previous node of bighead.
              { 
                smallhead->next=current->next;
                current->next=current->next->next;
                smallhead->next->next=bighead;
                smallhead=smallhead->next; 

                //Since the current->next is moved, the current pointer doesn't need to move.(We don't execute current=current->next)
               //So we can check the current->next, which is the current->next->next orginally. 
              }
              else  
              {
                //The pointer points to the nodes which are contiuously smaller than the target value.
                //There is no bighead in the middle.
                //For example: [1,1],2
                smallhead=smallhead->next; 
                current=current->next;
              }
  
            }
            
          }
          else
          {
            if(bighead==NULL)
              bighead=current->next;

            current=current->next;
          }  


          if(current==NULL)
            break;

            
        }
        
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
	ListNode* head=new ListNode(3);
	input=head;

  /*
  //Testcase1:[1 4 3 2 5 2],3
  head->next=new ListNode(4);
  head=head->next;

  head->next=new ListNode(3);
  head=head->next;

  head->next=new ListNode(2);
  head=head->next;

  head->next=new ListNode(5);
  head=head->next;

  head->next=new ListNode(2);
  head=head->next;*/
  

  /*
  //Testcase2:[1,1], 2
  head->next=new ListNode(1);
  head=head->next;*/

  
  /*
  //Testcase3:[1,2,3], 4
  head->next=new ListNode(2);
  head=head->next;

  head->next=new ListNode(3);
  head=head->next;*/

  
  //Testcase3:[3,1,2], 3

  head->next=new ListNode(1);
  head=head->next;

  head->next=new ListNode(2);
  head=head->next;

	
	result=solution.partition(input,3);

  while(result!=NULL)
  {
    cout<<result->val<<endl;
    result=result->next;
  } 


}
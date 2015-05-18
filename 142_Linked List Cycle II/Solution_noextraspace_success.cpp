/*
Given a linked list, return the node where the cycle begins. If there is no cycle, return null.

Follow up:
Can you solve it without using extra space?

*/



#include <iostream>
#include <cstdlib>
#include <set>

using namespace std;

/*
Use two pointers: first and second.
First trace a node at a time.
Second trace two nodes a time.
If there is cycle, first and second will point to the same node(meet node).
After points to the same node, use a pointer starts from head and another pointer starts from the meetnode.
When they points to the same node, the node is the start of circle.

Reference:
http://siddontang.gitbooks.io/leetcode-solution/content/linked_list/linked_list_cycle.html


*/



struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
      ListNode * first;
      ListNode * second;
      int step=0;


      
      if(head!=NULL)
      {
        first=head;
        second=head;

        
        while(second!=NULL)
        {
          
          first=first->next;

          if(second->next!=NULL)
            second=second->next->next;
          else
            return NULL;

          if(first==second && first!=NULL && second!=NULL)
          {
            while(head!=first)
            {
              head=head->next;
              first=first->next;
            }
            return first;
          }

        }
        return NULL;

      }
      else
        return NULL;
      
      

    }
};

int main()
{
	Solution solution;
  ListNode* circle;
  ListNode* result;
  ListNode* input;
	ListNode* head=new ListNode(3);
	input=head;

  head->next=new ListNode(2);
  circle=head->next;
  head=head->next;

  head->next=new ListNode(0);
  head=head->next;

  head->next=new ListNode(-4);
  head=head->next;
	/*for(int i=2;i<=5;i++)
	{
		head->next=new ListNode(i);
		head=head->next;
	}*/
	

  head->next=circle;

	result=solution.detectCycle(input);

  cout<<"result:"<<result->val<<endl;

}
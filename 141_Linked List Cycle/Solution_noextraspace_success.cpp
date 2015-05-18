/*
Given a linked list, determine if it has a cycle in it.

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
If there is cycle, first and second will point to the same node.

*/



struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };

class Solution {
public:
    bool hasCycle(ListNode *head) {
      ListNode * first;
      ListNode * second;

      
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
            return false;

          if(first==second && first!=NULL && second!=NULL)
            return true;

        }
        return false;

      }
      else
        return false;
      

    }

    /*
    bool hasCycle(ListNode *head) {
      ListNode * first;
      ListNode * second;

      
      if(head!=NULL)
      {
        first=head;
        if(head->next!=NULL)
          second=head->next->next;
        else
          second=NULL;


        while(second!=NULL)
        {
          if(first==second)
            return true;

          first=first->next;

          if(second->next!=NULL)
            second=second->next->next;
          else
            return false;

        }
        return false;

      }
      else
        return false;
      

    }*/


};

int main()
{
	Solution solution;
  bool result;
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
	
  //head->next=input;

	result=solution.hasCycle(input);

  cout<<"result:"<<result<<endl;

}
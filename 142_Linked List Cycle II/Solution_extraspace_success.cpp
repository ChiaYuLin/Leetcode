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
Put the node into a set. 
Compare whether the node is existed in the set. 
If it is existed in the set, there is a circle.
Return the node which is duplicated.

*/



struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
      set<ListNode *> nodeset;

      if(head!=NULL)
      {
        while(head!=NULL)
        {
          if(nodeset.find(head)!=nodeset.end())  
            return head;

          nodeset.insert(head);
          head=head->next;
          
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
  ListNode* result;
  ListNode* input;
	ListNode* head=new ListNode(1);
	input=head;


	for(int i=2;i<=5;i++)
	{
		head->next=new ListNode(i);
		head=head->next;
	}
	
  head->next=input;

	result=solution.detectCycle(input);

  cout<<"result:"<<result->val<<endl;

}
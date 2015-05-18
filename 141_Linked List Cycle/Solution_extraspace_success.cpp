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
Put the node into a set. 
Compare whether the node is existed in the set. 
If it is existed in the set, there is a circle.

*/



struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };

class Solution {
public:
    bool hasCycle(ListNode *head) {
      set<ListNode *> nodeset;

      if(head!=NULL)
      {
        while(head!=NULL)
        {
          if(nodeset.find(head)!=nodeset.end())  
            return true;

          nodeset.insert(head);
          head=head->next;
          
        }  
        return false; 
       
      }
      else
        return false;
      

    }
};

int main()
{
	Solution solution;
  bool result;
  ListNode* input;
	ListNode* head=new ListNode(1);
	input=head;


	for(int i=2;i<=5;i++)
	{
		head->next=new ListNode(i);
		head=head->next;
	}
	
  head->next=input;

	result=solution.hasCycle(input);

  cout<<"result:"<<result<<endl;

}
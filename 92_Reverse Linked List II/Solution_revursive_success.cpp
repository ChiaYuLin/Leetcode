/*
Given a linked list, determine if it has a cycle in it.

Follow up:
Can you solve it without using extra space?
*/

#include <iostream>
#include <cstdlib>

using namespace std;





struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };

class Solution {
public:
    bool hasCycle(ListNode *head)  {
        
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

  cout<<"head"<<head->val<<endl;
  

	/*result=solution.hasCycle(input);

  while(result!=NULL)
  {
    cout<<result->val<<endl;
    result=result->next;
  } */


}
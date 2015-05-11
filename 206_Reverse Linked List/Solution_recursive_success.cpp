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
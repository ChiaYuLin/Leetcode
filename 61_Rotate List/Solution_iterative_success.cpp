/*
Given a list, rotate the list to the right by k places, where k is non-negative.

For example:
Given 1->2->3->4->5->NULL and k = 2,
return 4->5->1->2->3->NULL.

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
    ListNode* rotateRight(ListNode* head, int k) {
        int length=1;
        ListNode* tmp;
        ListNode* current;
        ListNode* newhead;

        if(head!=NULL)
        {
          current=head;
          tmp=head;
          while(tmp->next!=NULL)
          {
            length++;
            tmp=tmp->next;
          }
          //Now, tmp points to the last node.

          if(k%length==0)
            return head;

          if(k>length)
            k=k%length;
          
          for(int i=1;i<=length-k;i++)
          {
            if(i==length-k)
            {
              newhead=current->next;
              current->next=NULL;  

            }
            current=current->next;
          }
          
          tmp->next=head;

          return newhead;  
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


  head->next=new ListNode(2);
  head=head->next;

	/*
  //Testcase1:
  for(int i=2;i<=5;i++)
	{
		head->next=new ListNode(i);
		head=head->next;
	}*/
	
  //Testcase2:
  //[1,2], 3
 
	result=solution.rotateRight(input,3);

  while(result!=NULL)
  {
    cout<<result->val<<endl;
    result=result->next;
  } 


}
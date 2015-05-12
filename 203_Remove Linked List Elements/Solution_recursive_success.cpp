/*
Remove all elements from a linked list of integers that have value val.

Example
Given: 1 --> 2 --> 6 --> 3 --> 4 --> 5 --> 6, val = 6
Return: 1 --> 2 --> 3 --> 4 --> 5

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
    ListNode* removeElements(ListNode* head, int val) {
    	ListNode* prev;
    	ListNode* result;

    	if(head==NULL)
    		return NULL;

    	if(head->val==val)  //replace itself
    		head=removeElements(head->next,val);
    	else
    		head->next=removeElements(head->next,val);

    	return head;
        
    }

    
};


int main()
{
	Solution solution;
	

    ListNode *result;
    ListNode *input1;
	ListNode *head1;
	

	head1=new ListNode(1);
	input1=head1;


	/*
	//Testcase1:
	for(int i=2;i<=10;i++)
	{
		head1->next=new ListNode(i);
		head1=head1->next;
	}

	head1->next=new ListNode(3);
		head1=head1->next;*/
	

	//Testcase2:
	head1->next=new ListNode(2);
	head1=head1->next;

	
	result=solution.removeElements(input1,1);

	while(result!=NULL)
  	{
    	cout<<result->val<<endl;
    	result=result->next;
    } 



}
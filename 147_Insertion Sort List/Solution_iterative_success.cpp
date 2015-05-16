/*
Sort a linked list using insertion sort.
*/

#include <iostream>
#include <cstdlib>

using namespace std;



struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

/*
Sort_first: Points to the first node of sorted value.
Sort_last: Points to the last node of sorted value.
Sort_move: The pointer which moves between sort_first and sort_last.
Sort_move_prev: The previous pointer of sort_move.
Current: Records the postion of head->next before moving head. After modfity the position of head, the next node which is going to sort is current.


*/

class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
    	ListNode* sort_first;
    	ListNode* sort_last;
    	ListNode* sort_move;
    	ListNode* sort_move_prev;
    	ListNode* current;


    	if(head!=NULL)
    	{
    		sort_first=head;
		    sort_last=head;
		    head=head->next;
	    	while(head!=NULL)
	    	{

	    		current=head->next;  //The current value

	    		if(head->val > sort_last->val) //head->val is bigger than sort_last. The head becomes sort_last
					sort_last=head;
				
	    		else if(head->val < sort_first->val)  //head->val is smaller than the first sorted value. Move the head become the first node.
	    		{

	    			if(sort_first==sort_last)
	    				sort_last=sort_first;

	    			sort_last->next=head->next; //before move the node

	    			//Put the node as first node.
	    			head->next=sort_first;

	    			sort_first=head;

	    			
	    		}	
	    		else if(head->val < sort_last->val)  //head->val is smaller than the last sorted vale. Compare from the start
	    		{
	    			sort_move=sort_first;
	    			sort_move_prev=sort_first;
	    			while(head->val >= sort_move->val)
	    			{
	    				sort_move_prev=sort_move;
	    				sort_move=sort_move->next;
	    			}

	    			//insert node
	    			if(sort_move==sort_last)
	    		    	sort_move->next=head->next;
	    		    else
	    		    	sort_last->next=head->next;

	    			sort_move_prev->next=head;
	    			head->next=sort_move;



	    		}
	    	    
	    		head=current;
	    	}

	    	return sort_first;
    	}
    	else
    		return NULL;
    	
        
    }
};

int main()
{
	Solution solution;
	ListNode* result;
	ListNode* input1;
	ListNode* head1;

	/*
	//Testcase1:
	head1=new ListNode(3);
	input1=head1;

	head1->next=new ListNode(2);
	head1=head1->next;

	head1->next=new ListNode(8);
	head1=head1->next;

	head1->next=new ListNode(4);
	head1=head1->next;

	head1->next=new ListNode(7);
	head1=head1->next;

	head1->next=new ListNode(5);
	head1=head1->next;
	*/

    //Testcase2:
	head1=new ListNode(4);
	input1=head1;

	head1->next=new ListNode(2);
	head1=head1->next;

	head1->next=new ListNode(1);
	head1=head1->next;

	head1->next=new ListNode(3);
	head1=head1->next;


	result=solution.insertionSortList(input1);

	while(result!=NULL)
  	{
    	cout<<result->val<<endl;
    	result=result->next;
    } 

}

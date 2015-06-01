/*
Sort a linked list in O(n log n) time using constant space complexity.
*/

#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;



struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

/*
O(n log n) sorts: Quick sort, Merge sort, Heap sort.
In linked list, the most difficult thing is to find the specific element.
If we want to find kth element, we have to trace the list from head to kth.
Therefore, using merge sort can avoid wasting the time on trace the list from head to specific node.

In Mergesort function, we seperate the list into two parts and execute recursively.
After return from Mergesort function, we execute Merge function to combine left and right list.
In Merge function, newhead is the head of new combine list and newtail is the tail of new combine list.
We compare the value of lefthead and righthead. Put the smaller node into the next of newtail.

*/


class Solution {
public:
	ListNode* Merge(vector<ListNode*>& lists) {
		ListNode* lefthead=NULL;
		ListNode* righthead=NULL;
		ListNode* newhead=NULL;
		ListNode* newtail=NULL;

		if(lists.size()>=2)
		{
			lefthead=lists.back();
			lists.pop_back();

			righthead=lists.back();
			lists.pop_back();
		}
		else
		{
			newhead=lists.back();
			lists.pop_back();

			return newhead;
		}
			

		while(lefthead!=NULL || righthead!=NULL)
		{
			if(lefthead==NULL) //push righthead
			{
				if(newhead==NULL)
					return righthead;
				else
				{
					newtail->next=righthead; //Connect the righthead to the next of newhead
					return newhead;
				}
			}
			else if(righthead==NULL)
			{
				if(newhead==NULL)
					return lefthead;
				else
				{
					newtail->next=lefthead; //Connect the righthead to the next of newhead
					return newhead;
				}
			}
			else  //leafhead and righthead are not NULL
			{
				if(lefthead->val <= righthead->val)
				{
					if(newhead==NULL)
					{
						newhead=lefthead;
						newtail=lefthead;
					}		
					else
					{
						newtail->next=lefthead;
						newtail=newtail->next;
					}

					lefthead=lefthead->next;

				}
				else  //righthead->val < lefthead->val
				{
					if(newhead==NULL)
					{
						newhead=righthead;
						newtail=righthead;
					}		
					else
					{
						newtail->next=righthead;
						newtail=newtail->next;
					}

					righthead=righthead->next;
				}
			}
		}

		return newhead;
	}

    ListNode* mergeKLists(vector<ListNode*>& lists) {
    	ListNode* result=NULL;


    	if(lists.size()>1)
    	{
    		while(lists.size()>1)
    		{
    			result=Merge(lists);
    			lists.insert(lists.begin(),result);
    		}
    		return result;
    	}
    	else if(lists.size()==1)
    	{
    		return lists.front();
    	}
    	else
    		return NULL;
    		

    	
    }

};

int main()
{
	Solution solution;
	vector<ListNode*> totalinput;
	ListNode* result;
	ListNode* input1;
	ListNode* head1;
	ListNode* input2;
	ListNode* head2;
	ListNode* input3;
	ListNode* head3;

	
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
	head1=head1->next; */
	

    
    //Testcase2:
	head1=new ListNode(1);
	input1=head1;

	head1->next=new ListNode(4);
	head1=head1->next;

	head1->next=new ListNode(7);
	head1=head1->next;

	head1->next=new ListNode(10);
	head1=head1->next;

	head2=new ListNode(2);
	input2=head2;

	head2->next=new ListNode(5);
	head2=head2->next;

	head2->next=new ListNode(8);
	head2=head2->next;

	head2->next=new ListNode(11);
	head2=head2->next;

	head3=new ListNode(3);
	input3=head3;

	head3->next=new ListNode(6);
	head3=head3->next;

	head3->next=new ListNode(9);
	head3=head3->next;

	head3->next=new ListNode(12);
	head3=head3->next;

	totalinput.push_back(input1);
	totalinput.push_back(input2);
	totalinput.push_back(input3);

	result=solution.mergeKLists(totalinput);

	while(result!=NULL)
  	{
    	cout<<result->val<<endl;
    	result=result->next;
    } 

}

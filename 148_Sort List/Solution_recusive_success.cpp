/*
Sort a linked list in O(n log n) time using constant space complexity.
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
	ListNode* Merge(ListNode* lefthead,ListNode* righthead) {
		ListNode* newhead=NULL;
		ListNode* newtail=NULL;


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
	ListNode* MergeSort(ListNode* head,int length) {
    	ListNode* tmp=NULL;
    	ListNode* left=NULL;
    	ListNode* right=NULL;
    	ListNode* newhead=NULL;


    	if(length>1)
    	{
    		tmp=head;
	    	left=head;
	    	for(int i=0;i<length/2-1;i++)
	    		tmp=tmp->next;
	    	
	    	left=head;
	    	right=tmp->next;

	    	tmp->next=NULL;

	    	//Seperate the list into two parts.
	    	left=MergeSort(left,length/2);  
	    	right=MergeSort(right,length-length/2);
	    	
	    	//Merge the left and right list.
	    	newhead=Merge(left,right);	

	    	return newhead; 
    	}
    	else
    		return head;
    

        
    }
    ListNode* sortList(ListNode* head) {
    	ListNode* tmp;
    	ListNode* result;
    	int length=0;

    	if(head!=NULL)
    	{
    		tmp=head;
    		while(tmp!=NULL)
    		{
    			length++;
    			tmp=tmp->next;
    		}

    		cout<<"length:"<<length<<endl;
    		result=MergeSort(head,length);

    		return result;
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
	head1=head1->next; */
	

    
    //Testcase2:
	head1=new ListNode(4);
	input1=head1;

	head1->next=new ListNode(2);
	head1=head1->next;

	head1->next=new ListNode(1);
	head1=head1->next;

	head1->next=new ListNode(3);
	head1=head1->next;
	

	result=solution.sortList(input1);

	while(result!=NULL)
  	{
    	cout<<result->val<<endl;
    	result=result->next;
    } 

}

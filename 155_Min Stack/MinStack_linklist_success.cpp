/*
Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

push(x) -- Push element x onto stack.
pop() -- Removes the element on top of the stack.
top() -- Get the top element.
getMin() -- Retrieve the minimum element in the stack.

*/

#include <iostream>
#include <cstdlib>

using namespace std;

/*
Use linked list to implement stack.
head stores the min of linked list.
head->next is the real first node.

Push:
When push, compare the head->val with x. If x is smaller than head->val, x becomes head->val.
Create a node be the next of head->next.

Pop:
If the head->val is same with head->next->val. That is, the min value will be poped.
We have to find the min value in the list again.

Top:
Return head->next->val.

getMin:
Return head->val.

*/

struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
};

class MinStack {
public:
    MinStack(){
        head=NULL;
    }
    void push(int x) {
       if(head==NULL)
       {
            head=new ListNode(x);   
            head->next=new ListNode(x);
       }
       else
       {
            ListNode *tmp;

            if(x < head->val)   //head stores the min value of list
                head->val=x;

            tmp=new ListNode(x);  //New a node and put the node to the next of head.
            tmp->next=head->next;
            head->next=tmp;   
       } 

        

       return;

    }

    void pop() { 

        if(head->next->val==head->val)  //If the pop value is the min, we have to find the min value again.
        {
            ListNode *tmp;
            int min;

            if(head->next->next!=NULL)
            {

                min=head->next->next->val;   //Set the value of 3rd node be the min.
                tmp=head->next->next->next; //The 4th node.
                while(tmp!=NULL)
                {
                    if(tmp->val < min)
                        min=tmp->val;

                    tmp=tmp->next;
                }

                head->val=min;

                
            }

            
        }

        //Pop the node
        head->next=head->next->next;

        if(head->next==NULL)  //If there is no node in the list, set head becomes NULL.
            head=NULL;

        return;

       
    }

    int top() {
        return head->next->val;
        
    }

    int getMin() {
        return head->val;

    
    }
private:
	ListNode *head;

};


int main()
{
	MinStack minstack;

	/*
    //Testcase1:
    minstack.push(3);
	minstack.pop();
	minstack.push(5);
	minstack.push(3);
	minstack.push(2);
	minstack.push(1);
	minstack.push(4);
	cout<<"minstack.top():"<<minstack.top()<<endl;
	cout<<"minstack.getMin():"<<minstack.getMin()<<endl;
    */
	
    //Testcase2:
    minstack.push(2147483646);
    minstack.push(2147483646);
    minstack.push(2147483647);
    cout<<"minstack.top():"<<minstack.top()<<endl;
    minstack.pop();
    cout<<"minstack.getMin():"<<minstack.getMin()<<endl;
    minstack.pop();
    cout<<"minstack.getMin():"<<minstack.getMin()<<endl;
    minstack.pop();
    minstack.push(2147483647);
    cout<<"minstack.top():"<<minstack.top()<<endl;
    cout<<"minstack.getMin():"<<minstack.getMin()<<endl;
    minstack.push(-2147483648);
    cout<<"minstack.top():"<<minstack.top()<<endl;
    cout<<"minstack.getMin():"<<minstack.getMin()<<endl;
    minstack.pop();
    cout<<"minstack.getMin():"<<minstack.getMin()<<endl;


	return 0;
}

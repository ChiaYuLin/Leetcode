/*
A linked list is given such that each node contains an additional random pointer which could point to any node in the list or null.

Return a deep copy of the list.

*/



#include <iostream>
#include <cstdlib>

using namespace std;

/*
Shallow copy vs. Deep copy: 
Shallow copy: New a pointer but points to the same data.
Deep copy: Create a new pointer and copy the data. That is, points to the copied data not the original data.

Reference: https://www.cs.utexas.edu/~scottm/cs307/handouts/deepCopying.htm


Since this problem has a random pointer. When we create a new node, we have to copy the random pointer too.
If we don't do nothing special, it's hard for us to find the matching of random pointer on the original list to the random pointer on the new list.
Therefore, we have two ways to find random pointer easily.

Method1: Hashtable
Create a matching of original node and copied node in hash table.

Mehotd2: Put the copied node be the next node of original node. 
Step1: Create the copied node and put the copied node be the next node of original node.
Step2: Copied the random pointer. The random pointer of copied node will be the next node of the original random pointer.
Step3: Seperate the original node and copied node.
Notice: When seperating the original node and copied node, the modification of copied node will affect the original node.
Thus, we have to modify the original node first.


*/





 struct RandomListNode {
      int label;
      RandomListNode *next, *random;
      RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 };

class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head){
      RandomListNode * newhead;
      RandomListNode * current;
      RandomListNode * result;
      RandomListNode * tmp;

      if(head!=NULL)
      {
        current=head;
        //Copy the node
        while(current!=NULL)
        {
          
          /*newhead=current;   //Wrong. This is shallow copy. The newhead and current points to the same object.*/
          newhead=new RandomListNode(current->label);

          //Put the copy node after the original node
          newhead->next=current->next;
          current->next=newhead;

          if(current->next!=NULL)
            current=current->next->next;

        }
         
        current=head;
        //Copy random pointer
        while(current!=NULL)
        {

          if(current->next!=NULL && current->random!=NULL)
            current->next->random=current->random->next;  //current->next is the copy node
   
          current=current->next->next;


        }



        current=head;
        //Seperate the node
        newhead=current->next;

        /*
        Becareful~When modify the next of tmp, the next of current will be modified too.
        Since the current is the previous node of tmp, modify the next of current first.
        */
        while(current!=NULL)
        {
          tmp=current->next;

          current->next=tmp->next;
          if(tmp->next!=NULL)
            tmp->next=tmp->next->next;


          current=current->next;

        }
        
        return newhead;
      }
      else
        return NULL;
      
    }
};

int main()
{
	Solution solution;
  RandomListNode * result;
  RandomListNode * input;
	RandomListNode * head=new RandomListNode(1);
  head->random=head;
	input=head;


	for(int i=2;i<=10;i++)
	{
		head->next=new RandomListNode(i);
    head->next->random=head;
		head=head->next;
	}

	
 
	result=solution.copyRandomList(input);

  cout<<"++++++++++++++++++++"<<endl;
  while(result!=NULL)
  {
    cout<<"result->label:"<<result->label<<endl;
    cout<<"@@result->random->label:"<<result->random->label<<endl;
    result=result->next;
  } 


}
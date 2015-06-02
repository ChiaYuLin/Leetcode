/*
A linked list is given such that each node contains an additional random pointer which could point to any node in the list or null.

Return a deep copy of the list.

*/



#include <iostream>
#include <cstdlib>
#include <map>

using namespace std;

/*
Use a hashtable. Key is original node. Value is new copied node.
Step1: Create a copied new node and connect the copied new node as a new copied list.
Step2: Use the hashtable to find the mapping of orignial random pointer to copy the random pointer.




*/





 struct RandomListNode {
      int label;
      RandomListNode *next, *random;
      RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 };

class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head){
      map<RandomListNode *,RandomListNode *> nodemapping;
      RandomListNode * current;
      RandomListNode * newpre;
      RandomListNode * newcurrent;
      RandomListNode * newhead;
      std::map<RandomListNode *, RandomListNode *>::iterator it;

      if(head!=NULL)
      {
        current=head;
        //Copy the node
        while(current!=NULL)
        {
          
          /*newhead=current;   //Wrong. This is shallow copy. The newhead and current points to the same object.*/
          newcurrent=new RandomListNode(current->label);

          //Put the original as a key, new copied node as a value.
          nodemapping[current]=newcurrent;

    
          if(current==head)
          {
            newhead=newcurrent;
            newpre=newcurrent;
          }
          else
          {
            newpre->next=newcurrent;   //Connect the new copied node to become a new copied list.
            newpre=newpre->next;
          }
            
          current=current->next;
        }
         

        current=head;
        newcurrent=newhead;
        //Copy random pointer
        while(current!=NULL)
        {

          if(current->random!=NULL)
          {
            it=nodemapping.find(current->random);
            if(it!=nodemapping.end())
              newcurrent->random=it->second;
          }
            
          current=current->next;
          newcurrent=newcurrent->next;

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
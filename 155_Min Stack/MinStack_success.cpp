/*
Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

push(x) -- Push element x onto stack.
pop() -- Removes the element on top of the stack.
top() -- Get the top element.
getMin() -- Retrieve the minimum element in the stack.

*/

#include <iostream>
#include <cstdlib>
#include <stack>

using namespace std;

/*
Use two stack: mainstack and minstack.
Mainstack stores the main value.
Minstack preservers the min value during the value in the top of mainstack.
While push the value into mainstack, we compare the value with the top of minstack.
If the value is smaller than the top of minstack, we push the value in the minstack.
If the value is bigger than the top of minstack, we push the top of minstack into minstack again.

When pop, we pop the value from mainstack and minstack.
When getMin, we return the top of minstack.

*/

class MinStack {
public:
    void push(int x) {
        if(!minstack.empty())
        {
            if(x<minstack.top())
                minstack.push(x);
            else
                minstack.push(minstack.top());   //minstack preserve the min value of the mainstack during the value in the top of mainstack.
        }
        else
            minstack.push(x);    //If minstack is empty, push the value into minstack directly.

        mainstack.push(x);
    }

    void pop() {  //Pop the value from mainstack and minstack.
        mainstack.pop();
        minstack.pop();
    }

    int top() {
        return mainstack.top();
    }

    int getMin() {

        return minstack.top();

    }
private:
	stack<int> mainstack;
    stack<int> minstack;

};


int main()
{
	MinStack minstack;

	minstack.push(3);
	minstack.pop();
	minstack.push(5);
	minstack.push(3);
	minstack.push(2);
	minstack.push(1);
	minstack.push(4);
	cout<<"minstack.top():"<<minstack.top()<<endl;
	cout<<"minstack.getMin():"<<minstack.getMin()<<endl;
	
	return 0;
}

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
#include <cmath>
#include <limits>

using namespace std;

/*
Mainstack stores the main value.
When getMin, we pop the value from mainstack and push into otherstack to  find min.
After finding min, we pop the value from otherstack and push into mainstack.
Since we push and pop the whole value from stack, this method will exceed the limitation time. 

*/


class MinStack {
public:
    void push(int x) {
        mainstack.push(x);
    }

    void pop() {
        mainstack.pop();
    }

    int top() {
        return mainstack.top();
    }

    int getMin() {
        int min=std::numeric_limits<int>::max();

        while(!mainstack.empty())
        {
        	if(mainstack.top() < min)
        		min=mainstack.top();

        	otherstack.push(mainstack.top());   //Pop the value from mainstack and put it into otherstack.
        	mainstack.pop();
        }

        while(!otherstack.empty())
        {
        	mainstack.push(otherstack.top());   //Pop the value from otherstack and put it into mainstack.
        	otherstack.pop();
        }

        return min;

    }
private:
	stack<int> mainstack;
	stack<int> otherstack;

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

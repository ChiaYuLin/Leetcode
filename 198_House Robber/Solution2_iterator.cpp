#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

class Solution {
public:
    int rob(vector<int> &num) {
  		int money=0;
  		int locate=0;
  		int it1_index=0;
  		int it2_index=0;
  		int vectorsize=0;

  		vector<int>::iterator it;
  		vector<int>::iterator it2;
  		
  		if(num.size()>1)
  		{
  		
	  		vectorsize=num.size();
			it=num.begin();
	  		it2=num.begin()+1;
			it1_index=std::distance(num.begin(),it)+1;
			it2_index=std::distance(num.begin(),it2)+1;
	  		
			while((it1_index <= vectorsize) && (it2_index <= vectorsize))
			{
	
				cout<<"*it:"<<*it<<endl;
				cout<<"*it2:"<<*it2<<endl;
				if(*it >= *it2)
				{
					money=money+*it;
					locate=std::distance(num.begin(),it)+1;
					cout<<"it1 locate"<<locate<<endl;
					
					if(it1_index<it2_index)
					{
						it+=2;
						it2+=2;
					}
					else
					{
						it+=2;
						it2+=4;
					}

					it1_index=std::distance(num.begin(),it)+1;
					it2_index=std::distance(num.begin(),it2)+1;
				}	
				else
				{
					money=money+*it2;
					locate=std::distance(num.begin(),it2)+1;
					cout<<"it2 locate"<<locate<<endl;
					if(it1_index<it2_index)
					{
						it+=4;
						it2+=2;
					}
					else
					{
						it+=2;
						it2+=2;
					}
					
				
					it1_index=std::distance(num.begin(),it)+1;
					it2_index=std::distance(num.begin(),it2)+1;
					
				}
			}
			
			if(it1_index <= vectorsize)
			{
				if(it1_index-locate!=1)
					money=money+*it;
			}
			else if(it2_index <= vectorsize)
			{
				if((it2_index-locate)!=1)
					money=money+*it2;
			}
			
			
			int vectorcount=0;
	  		int oddmoney=0;
	  		int evenmoney=0;
	  		
			for(vector<int>::iterator it=num.begin();it!=num.end();it++)
			{
				vectorcount++;
				if(vectorcount%2==1)  //odd
					oddmoney=oddmoney+*it;
				else
					evenmoney=evenmoney+*it;
			}
			
			cout<<"oddmoney"<<oddmoney<<endl;
			cout<<"evenmoney"<<evenmoney<<endl;
			cout<<"money"<<money<<endl;
			
			if(oddmoney>=evenmoney)
			{
				if(oddmoney>=money)
					return oddmoney;
				else
					return money;
			}
			else
			{
				if(evenmoney>=money)
					return evenmoney;
				else
					return money;
			}
		
			
		}
		else if(num.size()==1)
		{
			money=num.front();
			return money;
		}
			
			
			
			

    }
};

int main()
{
	vector<int> input;
	Solution solution;
	int result=0;
	

	input.push_back(8);
	input.push_back(9);
	input.push_back(9);
	input.push_back(4);
	input.push_back(10);
	input.push_back(5);
	input.push_back(6);
	input.push_back(9);
	input.push_back(7);
	input.push_back(9);

	
	result=solution.rob(input);
	
	cout<<result<<endl;
	
	return 0;
}

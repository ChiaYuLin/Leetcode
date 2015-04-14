/*
Given numRows, generate the first numRows of Pascal's triangle.

For example, given numRows = 5,
Return

[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]
*/

import java.io.*;
import java.util.*;

class Triangle {
    public List<Integer> trianglerow(List<Integer> input)
    {
    	List<Integer> result =new ArrayList<Integer>();;
    	int size=input.size();
    	int i;

    	result.add(1);
    	size--;

		
		i=0;
		while (i < input.size()) 
		{
			if(size==0)
				break;

			result.add(input.get(i)+input.get(i+1));

			i++;
			size--;
		}
		result.add(1);
		
    	return result;
    }
    public List<List<Integer>> generate(int numRows) {
        List<List<Integer>> finalresult =new ArrayList<List<Integer>>();
    	List<Integer> backresult =new ArrayList<Integer>();
    	int i=0;
    	
    	if(numRows<=0) return finalresult;
    	
    	backresult.add(1);
    	finalresult.add(backresult);
    	numRows--;
    	
    	while(i<numRows)
    	{
    		backresult=trianglerow(backresult);
    		finalresult.add(backresult);
			i++;
    	}
        
        return finalresult;  
    }
}


public class Pascals_Triangle{
	public static void main(String[] args){
		Triangle triangle=new Triangle ();
		List<List<Integer>> result =new ArrayList<List<Integer>>();

		result=triangle.generate(5);

		Iterator<List<Integer>> itforresult = result.iterator();
		while (itforresult.hasNext()) 
		{
			System.out.print("[");
			Iterator<Integer> output=itforresult.next().iterator();
			while(output.hasNext())
			{
				System.out.print(output.next()+",");
			}
			System.out.println("]");
		}
	}
} 
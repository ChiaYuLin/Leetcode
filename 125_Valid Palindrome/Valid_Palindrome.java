/*Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.*/

import java.io.*;

class Palindrome{
    public boolean isPalindrome(String s) {
        int i,j;

        s=s.toLowerCase();

        i=0;
        j=s.length()-1;
        while(i<=j)
        {
        	if(Character.isDigit(s.charAt(i)) || Character.isLetter(s.charAt(i)))
        	{
        		if(Character.isDigit(s.charAt(j)) || Character.isLetter(s.charAt(j)))
        		{
        			if(s.charAt(i)!=s.charAt(j))
        				return false;
        			else
        			{
        				i++;
        				j--;
        			}
        		}
        		else
        			j--;
        	}
        	else 
        		i++;
        }

        return true;

    }
}

public class Valid_Palindrome{
	public static void main(String[] args){
		Palindrome palindrome=new Palindrome();
		boolean s = palindrome.isPalindrome("race a car");
    	System.out.println(s);
	}

}
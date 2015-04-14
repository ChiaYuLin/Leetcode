import java.io.*;
import java.util.Stack;


class Parenthese {
    public boolean isValid(String s) {
       Stack<Character> st = new Stack<Character>();
      if (s==null || s.length()==0){
        return true;
      }

      for(int i = 0;i<s.length();i++)
      {
            char c = s.charAt(i);
            if(c=='(' || c=='[' || c=='{')
                st.push(c);
            else
            {
                if(!st.isEmpty())
                {
                    if(c==')' && st.peek()=='('  )
                        st.pop();
                    else if(c==']' && st.peek()=='[')
                        st.pop();
                    else if(c=='}' && st.peek()=='{')
                        st.pop();
                    else
                        return false;
                }
                else
                    return false;
            }
      }
      return st.isEmpty();
    }
}

public class Valid_Parenthese{
  public static void main(String[] args){
    Parenthese parenthese = new Parenthese();
    boolean s = parenthese.isValid("()[]{}");
    System.out.println(s);
  }
}
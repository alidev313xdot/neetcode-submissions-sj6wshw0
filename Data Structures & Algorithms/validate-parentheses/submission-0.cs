
public class Solution {
    public bool IsValid(string s) {
        Stack<char> stk = new Stack<char>(); 

        foreach (char c in s) {
            if (c == '{' || c == '[' || c == '(') {
                stk.Push(c); 
            }
            else {
                if (stk.Count > 0 && stk.Peek() == '(' && c == ')') stk.Pop(); 
                else if (stk.Count > 0 && stk.Peek() == '{' && c == '}') stk.Pop(); 
                else if (stk.Count > 0 && stk.Peek() == '[' && c == ']') stk.Pop(); 
                else return false; 
            }
        }

        return stk.Count == 0;       
    }
}

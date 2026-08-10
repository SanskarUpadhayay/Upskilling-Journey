/*
Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Every close bracket has a corresponding open bracket of the same type.
 

Example 1:

Input: s = "()"

Output: true

Example 2:

Input: s = "()[]{}"

Output: true

Example 3:

Input: s = "(]"

Output: false

Example 4:

Input: s = "([])"

Output: true

Example 5:

Input: s = "([)]"

Output: false

 

Constraints:

1 <= s.length <= 104
s consists of parentheses only '()[]{}'.
*/

//switch case

bool isValid(string s) {
        stack<char> brackets;
        for(int i=0;i<s.size();i++){
            if(s[i] == '(' || s[i] == '{' || s[i] == '['){
                brackets.push(s[i]);
            }
            else{
                switch(s[i]){
                    case '}':
                        if(brackets.size()>0 && brackets.top() == '{'){
                            brackets.pop();
                        }
                        else{
                            return false;
                        }
                        break;
                    case ')':
                        if(brackets.size()>0 && brackets.top() == '('){
                            brackets.pop();
                        }
                        else{
                            return false;
                        }
                        break;
                    case ']':
                    if(brackets.size()>0 && brackets.top() == '['){
                            brackets.pop();
                        }
                        else{
                            return false;
                        }
                        break;
                    default:
                        
                }

            }
        }
        if(brackets.size()>0){
            return false;
        }
        return true;
    }

//mapping

bool isValid(string s) {
        stack<char> brackets;
        unordered_map<char,char> match = {
            {'}', '{'},
            {')', '('},
            {']', '['}
        };
        for(int i=0;i<s.size();i++){
            if(s[i] == '(' || s[i] == '{' || s[i] == '['){
                brackets.push(s[i]);
            }
            else{
                if(brackets.empty() || brackets.top() != match[s[i]]){
                    return false;
                }
                brackets.pop();
            }
        }
        if(brackets.size()>0){
            return false;
        }
        return true;
    }

//optimized

bool isValid(string s) {
        stack<char> brackets;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                brackets.push(')');
            }
            else if(s[i] == '{'){
                brackets.push('}');
            }
            else if(s[i] == '['){
                brackets.push(']');
            }
            else {
                if(brackets.empty() || brackets.top()!=s[i]){
                    return false;
                }
                brackets.pop();
            }
        }
        if(brackets.size()>0){
            return false;
        }
        return true;
    }
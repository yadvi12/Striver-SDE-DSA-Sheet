// Link - https://leetcode.com/problems/valid-parentheses/
// Time Complexity - O(N)
// Space Complexity - O(N)

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
    for(int i=0; i<s.length(); i++)
    {
        // opening brackets
        if(s[i] == '[' || s[i] == '(' || s[i] == '{')
        {
            st.push(s[i]);
        }
        // closing brackets
        else
        {
            if(!st.empty())
            {
                // checking if it's balanced or not
                if((s[i] == ']' && st.top() == '[') || (s[i] == ')' && st.top() == '(') || (s[i] == '}' && st.top() == '{'))
                {
                    st.pop();
                }
                else
                {
                    return false;
                }
            }
            // when stack is empty
            else
            {
                return false;
            }
        }
    }
    
    if(st.empty())
    {
        return true;
    }
    else
    {
        return false;
    }
    }
};

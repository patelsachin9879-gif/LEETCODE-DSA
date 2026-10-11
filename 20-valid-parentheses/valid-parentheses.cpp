//valid parentheses
// L20: Valid Parentheses
// TC: O(n)
// SP: O(n)
class Solution {
public:
    bool isValid(string str) {
        stack<char> st;
        
        for (int i = 0; i < str.size(); i++) {
            // opening
            if (str[i] == '(' || str[i] == '{' || str[i] == '[') {
                st.push(str[i]);
            } 
            // closing
            else { 
                if (st.size() == 0) {
                    return false;
                }
                
                if ((st.top() == '(' && str[i] == ')') || 
                    (st.top() == '{' && str[i] == '}') || 
                    (st.top() == '[' && str[i] == ']')) {
                    st.pop();
                } 
                // no match
                else { 
                    return false;
                }
            }
        }
        
        return st.size() == 0;
    }
};
// Link - https://leetcode.com/problems/min-stack/
// Time Complexity - O(1) - Constant time
// Space Complexity - O(N) - using extra stack to store the ans

class MinStack {
public:
    stack<long> st;
    long mini;
    stack<long> ans;
    MinStack() {

    }
    
    void push(int val) {
        if(st.empty())
        {
            mini = INT_MAX;
        }
        else
        {
            mini = ans.top();
        }
        
        st.push(val);
        mini = min(st.top(), mini);
        ans.push(mini);
    }
    
    void pop() {
        st.pop();
        ans.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
      return ans.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

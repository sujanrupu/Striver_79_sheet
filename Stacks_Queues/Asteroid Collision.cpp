class Solution {
public:
    vector<int> asteroidCollision(vector<int>& at) {
        stack<int>st;
        for(int i = 0; i < at.size(); i++) {
            if(st.empty())  st.push(at[i]);
            else if((st.top()>0 && at[i]>0) || (st.top()<0 && at[i]<0))     st.push(at[i]);
            else if(abs(at[i]) >= abs(st.top())) {
                while(!st.empty() && abs(at[i]) >= abs(st.top()))    st.pop();
            }
        }
        vector<int>ans;
        while(!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

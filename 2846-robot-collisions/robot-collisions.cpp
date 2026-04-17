class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n = positions.size();
        
        vector<pair<int,int>> robots;
        for(int i = 0; i < n; i++) {
            robots.push_back({positions[i], i});
        }
        
        sort(robots.begin(), robots.end());
        
        stack<int> st; // stores indices
        
        for(auto &r : robots) {
            int i = r.second;
            
            while(!st.empty() && directions[st.top()] == 'R' && directions[i] == 'L') {
                
                if(healths[st.top()] == healths[i]) {
                    healths[st.top()] = 0;
                    healths[i] = 0;
                    st.pop();
                    break;
                }
                else if(healths[st.top()] > healths[i]) {
                    healths[st.top()]--;
                    healths[i] = 0;
                    break;
                }
                else {
                    healths[i]--;
                    healths[st.top()] = 0;
                    st.pop();
                }
            }
            
            if(healths[i] > 0) {
                st.push(i);
            }
        }
        
        vector<int> ans;
        for(int i = 0; i < n; i++) {
            if(healths[i] > 0) {
                ans.push_back(healths[i]);
            }
        }
        
        return ans;
    }
};
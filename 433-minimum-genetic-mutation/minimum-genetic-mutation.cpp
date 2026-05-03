class Solution {
public:
    int minMutation(string st, string e, vector<string>& bank) {
        set<string>s(bank.begin(),bank.end());
        set<string>vis;
        deque<pair<string,int>>q;
        q.push_back({st,0});
        if(!s.count(e))
        return -1;
        vis.insert(st);
        while(!q.empty()){
            string cc=q.front().first;
            int steps=q.front().second;
            q.pop_front();
            if(cc==e)
            return steps;
            for(char ch:"ACGT"){
            for(int i=0;i<st.size();i++){
            if(cc[i]==ch)
            continue;
            string n=cc;
            n[i]=ch;
            if(s.count(n) &&!vis.count(n)){
                vis.insert(n); 
                q.push_back({n,steps+1});
            }
            }
            }
        }
        return -1;
    }
};
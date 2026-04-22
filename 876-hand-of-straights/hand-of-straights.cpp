class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if(hand.size()%groupSize!=0)
        return false;
        map<int,int>m;
        for(int i=0;i<hand.size();i++){
            m[hand[i]]++;
        }
        int k=hand.size()/groupSize;
        while(k--){
            auto s=m.begin();
            int el=s->first;
            s->second--;
            if(s->second==0)
            m.erase(s->first);
            for(int i=1;i<groupSize;i++){
               if(m.find(el+i)==m.end())
               return false;
               m[el + i]--;
                if(m[el + i] == 0)
                 m.erase(el + i);
               
            }
        }
    return true;
    }
};
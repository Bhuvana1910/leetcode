class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int i=0,j=people.size()-1,b=0;
        sort(people.begin(),people.end());
        while(i<=j){
         if(i==j){
            b++;
            i++;
            j--;
         }
         else if(people[i]+people[j]<=limit)
         {
            b++;
            i++;
            j--;
         }
         else{
            b++;
            j--;
         }
        }
        return b;
    }
};
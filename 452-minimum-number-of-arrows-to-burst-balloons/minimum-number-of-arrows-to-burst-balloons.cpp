class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int c=1;
        sort(points.begin(),points.end());
        vector<int>v=points[0];
        for(int i=1;i<points.size();i++)
        {
           int  curst=points[i][0];
           int curend=points[i][1];
           if(curst>v[1])
           {
            c++;
            v=points[i];
           }
           else
           {
            //v[0]=max(v[0],curst);
            v[1]=min(v[1],curend);
           }

        }
        return c;
    }
};
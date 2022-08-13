class Solution {
public:
    static bool cmp(vector<int> vt1, vector<int> vt2){
        return vt1[0]<vt2[0];
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        //solution1: 这里的cmp其实不用 
        // // sort(intervals.begin(), intervals.end(), cmp);

        // sort(intervals.begin(), intervals.end(), [](auto &vt1, auto &vt2){
        //     return vt1[0]<vt2[0];
        // });
        // int i=0;
        // while (i<intervals.size()){
            /*
            我们不需要真正删除，而是做个标记就行了
            */
        //     if (i!=0 && intervals[i][0]<=intervals[i-1][1]){
        //         int l=intervals[i-1][0];
        //         int r=max(intervals[i-1][1], intervals[i][1]);
        //         intervals[i-1]={-1,-1};
        //         intervals[i]={l,r};
        //     }
        //     i++;
        // }
        // vector<vector<int>> ans;
        // for (const auto &vt:intervals){
        //     if (vt[0]==-1) continue;
        //     ans.push_back(vt);
        // }
        // return ans;

        //solution2:
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;
        ans.push_back(intervals[0]);
        for (const auto &interval:intervals){
            int l=interval[0];
            int r=interval[1];
            if (ans.back()[1]<l){
                ans.push_back(interval);
            }else {
                ans.back()[1]=max(ans.back()[1], r);
            }
        }
        return ans;
    }
};

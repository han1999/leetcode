class Solution {
public:

    bool notCover(vector<int> &vt1, vector<int> &vt2){
        return vt1[1]<vt2[0] || vt2[1]<vt1[0];
    }
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        //solution1:
        // vector<vector<int>> ans;
        // intervals.push_back(newInterval);
        // sort(intervals.begin(), intervals.end());
        // ans.push_back(intervals[0]);
        // cout<<"intervals.size():"<<intervals.size()<<endl;
        // // int n=intervals.size();
        // //一开始遇到死循环问题，在排除明显语法错误的情况下，最大的可能就是intervals.size()数值在变化
        // for (int i=0; i<intervals.size(); i++){
        //     // cout<<"intervals[i]:"<<intervals[i][0]<<" "<<intervals[i][1]<<endl;
        //     if (ans.back()[1]<intervals[i][0]){
        //         ans.push_back(intervals[i]);
        //     }else {
        //         ans.back()[1]=max(ans.back()[1], intervals[i][1]);
        //     }
        //     // cout<<i<<endl;
        // }
        // return ans;


        //solution2:
        vector<vector<int>> ans;
        int l=newInterval[0];
        int r=newInterval[1];
        bool placed=false;
        for (int i=0; i<intervals.size(); i++){
            if (intervals[i][1]<l){
                ans.push_back(intervals[i]);
            }else if (intervals[i][0]>r){
                if (!placed){
                    ans.push_back({l,r});
                    placed=true;
                }
                ans.push_back(intervals[i]);
            }else {
                /*
                合并区间这里有点巧妙
                */
                l=min(intervals[i][0], l);
                r=max(intervals[i][1], r);
            }
        }
        if (!placed){
            ans.push_back({l,r});
        }
        return ans;
    }
};

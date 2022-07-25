class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;

        unordered_set<int> st1, st2;
        for (int first=0; first<nums.size(); first++){
            // while (first<nums.size() && !st1.count(nums[first])){
            //     first++;
            // }
            // if (first==nums.size()) return ans;
            /*
            这种跳过方法，值得学习
            */
            // if (st1.count(nums[first])){
            //     continue;
            // }else {
            //     st1.insert(nums[first]);
            //     // cout<<"first=="<<nums[first]<<" "<<endl;
            // }
            if (first!=0 && nums[first]==nums[first-1]) continue;
            // int target=-nums[first];
            // cout<<"st2.size()=="<<st2.size()<<endl;
            // st2.clear();
            int third=nums.size()-1;
            for (int second=first+1; second<nums.size(); second++){
                // cout<<"nowSecondIndex=="<<second<<endl;
                // if (st2.count(nums[second])){
                //     continue;
                // }else {
                //     st2.insert(nums[second]);
                //     // cout<<"second=="<<nums[second]<<" ";
                // }
                /**
                如果是第一次写，second!=first+1这个真的很容易忽视！！！
                */
                if (second!=first+1 && nums[second]==nums[second-1]) continue;
                while (second<third){
                    // cout<<"third=="<<nums[third]<<" ";
                    int sum=nums[second]+nums[third]+nums[first];
                    // cout<<"sum=="<<sum<<endl;
                    if (sum>0){
                        third--;
                    }else if (sum==0){
                        ans.push_back({nums[first], nums[second], nums[third]});
                        break;
                    }else {
                        break;
                    }
                }
            }
        }
        return ans;
    }
};

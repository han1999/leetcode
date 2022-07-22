//class Solution {
//public:
//    vector<int> twoSum(vector<int>& nums, int target) {
//        map<int, int> mp;
//        for (int i=0; i<nums.size(); i++){
//            auto it=mp.find(target-nums[i]);
//            if(it!=mp.end()){
//                return {i, it->second};
//            }
//            mp[nums[i]]=i;
//        }
//        return {};
//    }
//};

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        multimap<int, int > mmp;
        for (int i=0; i<nums.size(); i++){
            mmp.insert(make_pair(nums[i], i));
        }    
        for (int i=0; i<nums.size(); i++){
            int num=nums[i];
            int otherNum=target-num;
            if (mmp.find(num)!=mmp.end() && mmp.find(otherNum)!=mmp.end()){
                if (num!=otherNum){
                    auto it1=mmp.find(num);
                    auto it2=mmp.find(otherNum);
                    ans.push_back(it1->second);
                    ans.push_back(it2->second);
                   break;
                }else {
                    if (mmp.count(num)==2){
                        auto it=mmp.find(num);
                        ans.push_back(it->second);
                        it++;
                        ans.push_back(it->second);
                        break;
                    }
                }
            }
        }
        return ans;
    }
};

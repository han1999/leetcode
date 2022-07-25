//2022.07.23
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        /**
        ���Ե�ʱ���ִ���ԭ����ûдsort()
        */
        sort(nums.begin(), nums.end());
        //��minDiff���ܸ���һ��
        int minClose=INT_MAX, ans;
        int n=nums.size();
        for (int first=0; first<n; first++){
            if (first!=0 && nums[first]==nums[first-1]){
                continue;
            }
            int third=n-1;
            for (int second=first+1; second<n; second++){
                if (second!=first+1 && nums[second]==nums[second-1]){
                    continue;
                }
                while (second<third){
                    /**
                    ������Ψһ��third--�����Ż��ĵط��������Ż��󷴶���ʱ�����
                    */
                    if (third!=n-1 && nums[third]==nums[third+1]){
                        third--;
                        continue;
                    }
                    int sum=nums[first]+nums[second]+nums[third];
                    // cout<<"sum=="<<sum<<" ";
                    if (sum>target){
                        if (minClose>sum-target){
                            minClose=sum-target;
                            ans=sum;
                        }
                        third--;
                    }else if (sum==target){
                        return target;
                    }else {
                        if(minClose>target-sum){
                            minClose=target-sum;
                            ans=sum;
                        }
                        break;
                    }
                }
            }
        }
        return ans;
    }
};

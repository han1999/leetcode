class Solution {
public:
    int ans=0;
    void merge(vector<int> &nums, vector<int> &temp, int l1, int r1, int l2, int r2){
        /*
        这里超时仅仅是因为创建了一个temp! 所以以后得直接传一个temp
        */
        // vector<int> temp(nums.size());
        int i=l1, j=l2;
        int pos=l1;
        while (i<=r1 && j<=r2){
            if (nums[i]<=nums[j]){
                ans+=j-l2;
                //这里应当是<=而不是<
                temp[pos++]=nums[i++];
            }else {
                // ans+=r1-l1;
                temp[pos++]=nums[j++];
            }
        }
        while (i<=r1){
            ans+=j-l2;
            temp[pos++]=nums[i++];
        }
        while (j<=r2){
            temp[pos++]=nums[j++];
        }
        for (int i=l1; i<=r2; i++){
            nums[i]=temp[i];
        }
    }
    int reversePairs(vector<int>& nums) {
        //暴力方法
        // int n=nums.size();
        // int cnt=0;
        // for (int i=0; i<n; i++){
        //     for (int j=i+1; j<n; j++){
        //         if (nums[i]>nums[j]){
        //             cnt++;
        //         }
        //     }
        // }
        // return cnt;

        int n=nums.size();
        vector<int> temp(n);
        for (int gap=1; gap<n; gap*=2){
            for (int i=0; i+gap-1<n-1; i+=2*gap){
                merge(nums, temp, i, i+gap-1, i+gap, min(i+2*gap-1, n-1));
                // cout<<ans<<" ";
            }
            // cout<<endl;
        }
        return ans;
    }
};

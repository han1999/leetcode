class Solution {
public:
    bool canJump(vector<int>& nums) {

        //solution1:
        // if (nums.size()==1) return true;
        // int now=0;
        // /*
        // 这里得用now!=nums.size()-1 不能用 now<nums.size()
        // 因为now 如果等于 nums.size()-1，它是小于nums.size()的，但是已经到终点了
        // */
        // while (now!=nums.size()-1){
        //     int nowHop=nums[now];
        //     if (nowHop==0) return false;
        //     int maxNext=now;
        //     int next=now;
        //     for (int i=0; i<nowHop; i++){
        //         int tempPos=now+1+i;
        //         if (tempPos==nums.size()-1) return true;
        //         int tempNext=tempPos+nums[tempPos];
        //         if (tempNext>maxNext){
        //             maxNext=tempNext;
        //             next=tempPos;
        //         }
        //     }
        //     /*
        //     这一步比较巧妙，说明已经跳不了了,也就是说nowHop==0
        //     */
        //     // if (now==next) return false;
        //     now=next;
        // }
        // return true;

        //solution2:
        int now = 0;
        int n=nums.size();
        int bound=now;
        for (int i=0; i<n; i++){
            if (i>bound) return false;//这里顺序很重要！
            bound=max(bound, i+nums[i]);
        }

        return true;
    }
};

class Solution {
public:
    int jump(vector<int>& nums) {
        //solution1:
        // int pos=0;
        // int cnt=0;
        // while (pos<nums.size()-1){
        //     int nowHop=nums[pos];
        //     int maxPos=pos;
        //     int nextPos=pos;
        //     for (int i=0; i<nowHop; i++){
        //         int tempPos=pos+1+i;
        //         /**
        //         不是很典型的贪心算法，注意边界情况
        //         */
        //         if (tempPos>=nums.size()-1) return cnt+1;
        //         int tempNext=tempPos+nums[tempPos];
        //         if (tempNext>maxPos){
        //             maxPos=tempNext;
        //             nextPos=tempPos;
        //         }
        //     }
        //     cnt++;
        //     pos=nextPos;
        // }
        // return cnt;

        //solution2:
        int cnt=0;
        int edge=0;
        int nextEdge=0;
        /**
        这个边界是最难控制的
        */
        for (int i=0; i<nums.size()-1; i++){
            /**
            这个方法的核心在于，不需要求出具体的跳跃路径
            */
            nextEdge=max(nextEdge, i+nums[i]);
            if (i==edge){
                edge=nextEdge;
                cnt++;
            }
        }
        return  cnt;
    }
};

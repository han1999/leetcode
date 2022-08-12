class Solution {
public:
    bool canJump(vector<int>& nums) {

        //solution1:
        // if (nums.size()==1) return true;
        // int now=0;
        // /*
        // �������now!=nums.size()-1 ������ now<nums.size()
        // ��Ϊnow ������� nums.size()-1������С��nums.size()�ģ������Ѿ����յ���
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
        //     ��һ���Ƚ����˵���Ѿ���������,Ҳ����˵nowHop==0
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
            if (i>bound) return false;//����˳�����Ҫ��
            bound=max(bound, i+nums[i]);
        }

        return true;
    }
};

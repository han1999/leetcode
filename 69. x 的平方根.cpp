class Solution {
public:
    int mySqrt(int x) {
        // //solution1: ����д������Ȼ��ͨ��
        // for (long long i=0; i<=x; i++){
        //     if (i*i<=x && (i+1)*(i+1)>x) return i;
        // }
        // return -1;

        int ans=-1;
        int l=0, r=x;
        while (l<=r){
            long long mid=l+(r-l)/2;
            if (mid*mid<=x){
                /**
                ���д���е�������upper_bound()��
                �ҵ����һ��С������mid
                */
                ans=mid;
                l=mid+1;
            }else {
                r=mid-1;
            }
        }
        return ans;
    }
};

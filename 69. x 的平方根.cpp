class Solution {
public:
    int mySqrt(int x) {
        // //solution1: 暴力写法，竟然能通过
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
                这个写法有点类似于upper_bound()了
                找到最后一个小于它的mid
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

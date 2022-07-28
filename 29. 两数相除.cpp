//2022.07.27
class Solution {
public:
    int divide(int dividend, int divisor) {
        // if (dividend==0) return 0;
        // if (dividend==INT_MIN){
        //     if (divisor==INT_MIN) return 1;
        //     if (divisor==1) return INT_MIN;
        //     if (divisor==-1) return INT_MAX;
        // }
        // bool aNeg=dividend<0;
        // bool bNeg=divisor<0;
        // dividend=abs(dividend);
        // divisor=abs(divisor);
        // // if (dividend<divisor) return 0;
        // int ans=0;
        // int nowNum=divisor;
        // while (nowNum<=dividend){
        //     ans++;
        //     if (INT_MAX-divisor>=nowNum) nowNum+=divisor;
        //     else {
        //         break;
        //     }
        //     // cout<<ans<<" "<<divisor<<endl;
        // }
        // if (aNeg^bNeg) return -ans;
        // else return ans;
        
        //这道题有点复杂
        //好家伙！！！！！！
        if (dividend==0) return 0;
        if (dividend==INT_MIN){
            if (divisor==-1) return INT_MAX;
            if (divisor==1) return INT_MIN;
        }
        if (divisor==1) return dividend;
        if (divisor==-1) return -dividend;
        bool rev=false;
        if (dividend>0){
            dividend=-dividend;
            rev=!rev;
        }
        if (divisor>0){
            divisor=-divisor;
            rev=!rev;
        }

        //检查 y*z 是否大于等于x x<0(被除数), y<0（除数）, z>0
        auto check=[](int x, int y, int z){
            int ans=0;
            int add= y;
            while (z){
                if (z&1){
                    if (ans<x-add) return false;
                    ans+=add;
                }
                /** z==1的时候，不需要这些操作了
                */
                if (z!=1){
                    //如果没有这个的话， 那么当y==INT_MAX/2的时候，如果divisor==3, 很快就溢出了
                    if (add<x-add) return false;
                    add+=add;
                }
                z>>=1;
            }
            return ans>=x;
        };

        int l=1, r=INT_MAX, ans;
        while (l<=r){
            int mid=l+((r-l)>>1);
            if (check(dividend, divisor, mid)){
                ans=mid;
                l=mid+1;
            }else {
                r=mid-1;
            }
        }
        /**
        这里返回r不严谨，只是每次l==r的时候，下一次check肯定是true， 那么只有l改变，r不改变
        很凑巧，我们的目标是找到最后一个check==true的那个mid
        */
        // return rev?-r:r;
        return rev?-ans:ans;

    }
};

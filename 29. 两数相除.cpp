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
        
        //������е㸴��
        //�üһ����������
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

        //��� y*z �Ƿ���ڵ���x x<0(������), y<0��������, z>0
        auto check=[](int x, int y, int z){
            int ans=0;
            int add= y;
            while (z){
                if (z&1){
                    if (ans<x-add) return false;
                    ans+=add;
                }
                /** z==1��ʱ�򣬲���Ҫ��Щ������
                */
                if (z!=1){
                    //���û������Ļ��� ��ô��y==INT_MAX/2��ʱ�����divisor==3, �ܿ�������
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
        ���ﷵ��r���Ͻ���ֻ��ÿ��l==r��ʱ����һ��check�϶���true�� ��ôֻ��l�ı䣬r���ı�
        �ܴ��ɣ����ǵ�Ŀ�����ҵ����һ��check==true���Ǹ�mid
        */
        // return rev?-r:r;
        return rev?-ans:ans;

    }
};

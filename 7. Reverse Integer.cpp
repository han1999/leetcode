class Solution {
public:
    int reverse(int x) {
        // string s=to_string(x);//变成字符串
        // std::reverse(s.begin(), s.end());//翻转字符串
        // int ans=0;
        // try{
        //     ans=stoi(s);//变回数字
        //     if (x<0) ans=-ans;//x是负数，加上负号
        // }catch(exception ex){}//溢出，啥也不做，返回零
        // return ans;

        int rev=0;
        while (x){
            if (rev<INT_MIN/10 || rev>INT_MAX/10) return 0;
            int temp=x%10;
            x/=10;
            rev=rev*10+temp;
        }
        return rev;
    }
};

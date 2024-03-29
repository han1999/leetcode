//2022.07.27
class Solution {
public:
    double myPow(double x, int n) {
        // return quickPow(x, n);
        //可以用 long long 来接受，解决n=INT_MIN的问题

        // //solution1:
        // if (x==1 || n==0) return 1.0;
        /*
        n&1判断奇数， 对负数仍然适用
        */
        // if (n & 1){
        //     if (n<0) return 1.0/x*myPow(x, n+1);
        //     else return x*myPow(x, n-1);
        // }else {
        //     double temp=myPow(x, n/2);
        //     return temp*temp;
        // }

        //solution2:
        // if (x==1) return 1.0;
        // return quickPow(x, n);

        //solution3:
        if (x==1) return 1.0;
        /**
        这个0LL-n有意思 0L-n就行了 这个编译器里面int 4字节， long 和 long long 都是8字节
        */
        cout<<sizeof(int)<<endl;
        cout<<sizeof(long long)<<endl;
        cout<<sizeof(long)<<endl;
        return n>0?quickPow1(x,n):1.0/quickPow1(x, 0L-n);
    }

    double quickPow(double x, long long n){
        if (n==0) return 1.0;
        if (n<0) return 1.0/quickPow(x, -n);
        if (n&1) return x*quickPow(x, n-1);
        double temp=quickPow(x, n/2);
        return temp*temp;
    }

    double quickPow1(double x, long long n){
        double ans=1.0;
        double temp=x;
        while (n>0){
            if (n&1){
                ans*=temp;
            }
            cout<<ans<<endl;
            temp*=temp;
            //是>>= 不是 >>
            n>>=1;
        }
        return ans;
    }
}; 

//2022.08.10
class Solution {
public:
    // /*
    // 单单形参是long long 不行，关键是实参需要是LL
    //solution1:
    // */
    // double quickPow(double x, long long n){
        /*
        终止条件不能使n==1 因为 n很可能等于0, 或者在quickPow之前特判n！=0
        */
    //     if (n==0) return 1.0;
    //     double temp=quickPow(x, n/2);
        /*
        n&1小技巧
        */
    //     if (n&1) return x*temp*temp;
    //     else return temp*temp;
    // }

    //solution2:
    double quickPow(double x, long long n){
        double ans=1.0;
        double mul=x;
        while (n){
            if (n&1){
                ans*=mul;
            }
            mul*=mul;
            n>>=1;
        }
        return ans;
    }
    double myPow(double x, int n) {
        if (x==0) return 0.0;
        if (n>0) return quickPow(x,n);
        else {
            //0LL技巧
            return 1.0/quickPow(x, 0LL-n);
        }
    }
};

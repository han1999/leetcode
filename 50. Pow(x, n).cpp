//2022.07.27
class Solution {
public:
    double myPow(double x, int n) {
        // return quickPow(x, n);
        //������ long long �����ܣ����n=INT_MIN������

        // //solution1:
        // if (x==1 || n==0) return 1.0;
        /*
        n&1�ж������� �Ը�����Ȼ����
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
        ���0LL-n����˼ 0L-n������ �������������int 4�ֽڣ� long �� long long ����8�ֽ�
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
            //��>>= ���� >>
            n>>=1;
        }
        return ans;
    }
}; 

//2022.08.10
class Solution {
public:
    // /*
    // �����β���long long ���У��ؼ���ʵ����Ҫ��LL
    //solution1:
    // */
    // double quickPow(double x, long long n){
        /*
        ��ֹ��������ʹn==1 ��Ϊ n�ܿ��ܵ���0, ������quickPow֮ǰ����n��=0
        */
    //     if (n==0) return 1.0;
    //     double temp=quickPow(x, n/2);
        /*
        n&1С����
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
            //0LL����
            return 1.0/quickPow(x, 0LL-n);
        }
    }
};

class Solution {
public:
    int reverse(int x) {
        // string s=to_string(x);//����ַ���
        // std::reverse(s.begin(), s.end());//��ת�ַ���
        // int ans=0;
        // try{
        //     ans=stoi(s);//�������
        //     if (x<0) ans=-ans;//x�Ǹ��������ϸ���
        // }catch(exception ex){}//�����ɶҲ������������
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

class Solution {
public:
    string addBinary(string a, string b) {
        //solution1:
        // int m=a.size()-1;
        // int n=b.size()-1;
        // string ans;
        // int carry=0;
        // while (m>=0 || n>=0){
        //     int aVal=m>=0?a[m]-'0':0;
        //     int bVal=n>=0?b[n]-'0':0;
        //     /*
        //     д���뾡����Ҫ�Ĵ���ṹ������������С�����ϳ���
        //     һ��ʼ��Ȼ����+carry��
        //     */
        //     int sum=aVal+bVal+carry;
        //     ans+=sum%2+'0';
        //     carry=sum/2;
        //     m--;
        //     n--;
        // }
        // if (carry) ans+=carry+'0';
        // reverse(ans.begin(), ans.end());
        // return ans;

        //solution2:�������λ���� ��python����ʵ�֣�c++������ʵ��
    }
};

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        //solution1:
        // int n=digits.size();
        // vector<int> ans;
        // int carry=1;
        // for (int i=n-1; i>=0; i--){
        //     int nowVal=digits[i]+carry;
        //     /*
        //     string��vector�����ƣ������ﲻ̫һ��
        //     string ���õ� insert(pos, len) ��vector��û��
        //     �����������е���insert(iter, val) ���뵥��Ԫ��
        //     */
        //     ans.insert(ans.begin(), nowVal%10);
        //     carry=nowVal/10;
        // }
        // if (carry) ans.insert(ans.begin(), carry);
        // return ans;

        //solution2:�ٷ����Ҳ��û���Ż�����
        //��������Ϊɶ��������ԭ�ز����أ���ȫ����Ҫ�½�һ������
        for (int i=digits.size()-1; i>=0; i--){
            if (digits[i]!=9){
                digits[i]++;
                return digits;
            }else {
                digits[i]=0;
            }
        }
        digits.insert(digits.begin(), 1);
        return digits;
    }
};

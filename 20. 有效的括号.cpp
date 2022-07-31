// 2022.07.26 �ܼ򵥵�һ���� 
class Solution {
public:
    bool isValid(string s) {
        /**
        ��stack��ʵ����Ϥ����vector�����һģһ���Ķ���
        */
        unordered_map<char, char> mp={
            {')', '('},
            {']','['},
            /**
            �������һ��Ԫ�أ�����������һ�����ţ�Ҳ�ܱ���ͨ��
            */
            {'}','{'},
        };
        stack<char> stk;
        /**
        ��Ϊ�����ʵ��̫�����ˣ�����д�����ٷ����Ҳ��һģһ��
        */
        for (auto const &ch:s){
            //���if������mp.count()����
            if (ch==')' || ch==']' || ch=='}'){
                if (stk.empty() || stk.top()!=mp[ch]) return false;
                stk.pop();
            }else {
                stk.push(ch);
            }
        }
        //�ȼ��� return stk.empty()
        if (stk.empty()) return true;
        return false; 
    }
};

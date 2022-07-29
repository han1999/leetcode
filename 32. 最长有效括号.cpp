class Solution {
public:
    int longestValidParentheses(string s) {
        // //solution1:
        // int ans=0;
        // stack<int> stk;
        // stk.push(-1);
        // //ջ�׵�)�±�������һ��û��ƥ���),�����±��ȥ�������ֻʣ������ʱ�򣩣�������Ч����,һ��ʼĬ�ϴ�-1��ʼ(���Ϊ-1λ��Ϊ)��
        // for (int i=0; i<s.size(); i++){
        //     if (s[i]=='('){
        //         stk.push(i);
        //     }else{
        //         /*
        //         �ܲ�����
        //         */
        //         stk.pop();
        //         if (stk.empty()){
        //             stk.push(i);
        //         }else {
        //             ans=max(ans, i-stk.top());
        //         }
        //     }
        // }
        // return ans;


        /**
        һ�����Ŵ���Ч:
        1. ����㿪ʼ�������Ӵ������� (���� ���� )���� �������õ������������Ƿ�Ϸ���
        2. ���յ������ʱ����������������ͬ
        */
        if (s=="") return 0;
        // �ֿ����㷽ʽ��
        auto getValid=[&](string s){
            int ans=0;
            int lCnt=0, rCnt=0;
            for (const auto &ch:s){
                if (ch=='('){
                    lCnt++;
                }else {
                    rCnt++;
                    if (rCnt==lCnt){
                        ans=max(ans, lCnt*2);
                    }else if (rCnt>lCnt){
                        lCnt=rCnt=0;
                    }
                }
            }
            return ans;
        };

        // //������: ���ⲻ���õ���������ΪҪ��¼cnt������
        // auto getValid=[&](string s){
        //     int validSize=0;
        //     int balance=0;
        //     for (const auto &ch:s){
        //         if (ch=='('){
        //             balance++;
        //         }else {
        //             balance--;
        //             if (balance==0){
        //                 validSize=max(validSize, 2)
        //             }
        //         }
        //     }
            
        // }


        int ans=getValid(s);
        reverse(s.begin(), s.end());
        for (auto &ch:s){
            if (ch=='(') ch=')';
            else ch='(';
        }
        ans=max(ans, getValid(s));
        return ans;
    }
};

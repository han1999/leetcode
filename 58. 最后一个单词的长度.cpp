class Solution {
public:
    int lengthOfLastWord(string s) {
        //�ܼ򵥵�һ����д�˺ܾã��߼���ʵ�����ж�
        //solution1:
        // int ans=0;
        // int lastAns=0;
        // for (int i=0; i<s.size(); i++){
        //     if (s[i]==' '){
        //         ans=lastAns==0?ans:lastAns;
        //         lastAns=0;
        //     }else {
        //         lastAns++;
        //     }
        // }
        // return lastAns?lastAns:ans;

        // //solution2: ���ַ������ǰ����õ㣬һ��ʼզû�뵽��
        // //����������ʱ�����ǿ����ȶ��ؽ��д���
        // int ans=0;
        // while (!s.empty() && s.back()==' '){
            /*
            string��vector��Ψ���Ŀ��ԶԵ��������мӼ�����������
            */
        //     s.erase(s.end()-1);
        // }
        // for (const auto &ch:s){
        //     if (ch==' '){
        //         ans=0;
        //     }else {
        //         ans++;
        //     }
        // }
        // return ans;

        //solution3:
        int ans=0;
        int i=s.size()-1;
        while (i>=0 && s[i]==' '){
            i--;
        }
        while (i>=0 && s[i]!=' '){
            ans++;
            i--;
        }
        return ans;
    }
};

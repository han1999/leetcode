//class Solution {
//public:
//    int reverse(int x) {
//        // string s=to_string(x);//����ַ���
//        // std::reverse(s.begin(), s.end());//��ת�ַ���
//        // int ans=0;
//        // try{
//        //     ans=stoi(s);//�������
//        //     if (x<0) ans=-ans;//x�Ǹ��������ϸ���
//        // }catch(exception ex){}//�����ɶҲ������������
//        // return ans;
//
//        int rev=0;
//        while (x){
//            if (rev<INT_MIN/10 || rev>INT_MAX/10) return 0;
//            int temp=x%10;
//            x/=10;
//            rev=rev*10+temp;
//        }
//        return rev;
//    }
//};


//2022.07.21
class Solution {
public:
    int reverse(int x) {
    	//solution1:
        // bool isNeg=x<0;
        // string s=to_string(x);
        // ::reverse(s.begin(), s.end());
        // int ans;
        // if (isNeg){
        //     s.erase(s.end()-1);
        //     s.insert(0, "-");
        // }
        // try{
        //     ans=stoi(s);
        // }catch (exception e){
        //     return 0;
        // }
        // return ans;
        
        /**
        �������ڲ��ܶ��������Ǹ�������Ĺ�����һ����
        */
        //solution2:
        int ans=0;
        while (x){
            if (ans>INT_MAX/10 || ans<INT_MIN/10){
                return 0;
            }
            int temp=x%10;
            ans=ans*10+temp;
            x/=10;
        }
        return ans;
    }
};

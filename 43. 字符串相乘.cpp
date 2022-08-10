class Solution {
public:
    string multi(string &s, int n){
        string ans;
        int carry=0;
        for (int i=s.size()-1; i>=0; i--){
            int val=(s[i]-'0')*n+carry;
            ans+=(val%10)+'0';
            carry=val/10;
        }
        if (carry) ans+=carry+'0';
        reverse(ans.begin(), ans.end());
        return ans;
    }

    string addTwoString(string &s1, string &s2){
        reverse(s1.begin(), s1.end());
        reverse(s2.begin(), s2.end());
        int carry=0;
        string ans;
        for (int i=0; i<max(s1.size(), s2.size()); i++){
            /**
            这里-'0'极容易错
            */
            int val1=i<s1.size()?s1[i]-'0':0;
            int val2=i<s2.size()?s2[i]-'0':0;
            int temp=val1+val2+carry;
            ans+=temp%10+'0';
            carry=temp/10;
        }
        if (carry) ans+=carry+'0';
        reverse(ans.begin(), ans.end());
        return ans;
    }

    string multiply(string num1, string num2) {
        if (num1[0]=='0' || num2[0]=='0') return "0";
        reverse(num2.begin(), num2.end());
        string ans;
        for (int i=0; i<num2.size(); i++){
            string tempAns=multi(num1, num2[i]-'0');
            for (int j=0; j<i; j++){
                tempAns+="0";
            }
            ans=addTwoString(ans, tempAns);
        }
        return ans;
    }
};

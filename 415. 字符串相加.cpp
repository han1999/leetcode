class Solution {
public:
    string addStrings(string num1, string num2) {
        // int zeroDiff=abs(num1.size()-num2.size());
        // string temp;
        // for (int i=0; i<zeroDiff; i++){
        //     temp+="0";
        // }
        // if (num1.size()<num2.size()){
        //     num1=temp+num1;
        // }
        
        //solution1:
        // reverse(num1.begin(), num1.end());
        // reverse(num2.begin(), num2.end());
        // int carry=0;
        // string ans;
        // for (int i=0; i<max(num1.size(), num2.size()); i++){
        //     /**
        //     就这个-'0' +'0' 特别容易错！
        //     */
        //     int val1=i>=num1.size()?0:num1[i]-'0';
        //     int val2=i>=num2.size()?0:num2[i]-'0';
        //     int nowVal=val1+val2+carry;
        //     ans+=nowVal%10+'0';
        //     carry=nowVal/10;
        // }
        // if (carry) ans+=carry+'0';
        // reverse(ans.begin(), ans.end());
        // return ans;

        //solution2:
        int i=num1.size()-1, j=num2.size()-1;
        int carry=0;
        string ans;
        while (i>=0 || j>=0){
            int val1=i>=0?num1[i]-'0':0;
            int val2=j>=0?num2[j]-'0':0;
            int sum=val1+val2+carry;
            /**
            完全用算术思维来模拟，很慢
            ans可以直接用+=， 最后倒过来， 但这样还不如直接num1, num2也倒过来
            */
            ans.insert(ans.begin(), sum%10+'0');
            carry=sum/10;
            i--;
            j--;
        }
        if (carry) ans.insert(ans.begin(), carry+'0');
        return ans;
    }
};

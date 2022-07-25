//2022.07.22 
class Solution {
public:
    string intToRoman(int num) {
        /*
        虽然有点笨拙，但是能通过
        */
        string ans;
        int thou=num/1000;
        for (int i=0; i<thou; i++){
            ans+="M";
        }
        /*
        %运算，小%大还是等于小
        %1000等于去掉千位，保留千位以后
        /1000等于去掉千位后面的所有位。 保留千位
        两个正好互补
        */
        /*if (thou)*/ num%=1000;
        int hun=num/100;
        if (hun==4){
            ans+="CD";
        }else if (hun==9){
            ans+="CM";
        }else {
            if (hun>=5){
                ans+="D";
            }
            for(int i=0; i<hun%5; i++){
                ans+="C";
            } 
        }
        /*if (hun)*/ num%=100;
        int ten=num/10;
        if (ten==4){
            ans+="XL";
        }else if (ten==9){
            ans+="XC";
        }else{
            if (ten>=5){
                ans+="L";
            }
            for (int i=0;i<ten%5; i++){
                ans+="X";
            }
        }

        num%=10;
        int dig=num;
        if (num==4) {
            ans+="IV";
        }else if (num==9){
            ans+="IX";
        }else {
            if (num>=5){
                ans+="V";
            }
            for (int i=0; i<num%5; i++){
                ans+="I";
            }
        }
        return ans;
    }
};

//solution 2,3:
class Solution {
public:
    string intToRoman(int num) {
        // const pair<int, string> valueSymbols[]={
        //     {1000, "M"},
        //     {900, "CM"},
        //     {500, "D"},
        //     {400, "CD"},
        //     {100, "C"},
        //     {90, "XC"},
        //     {50, "L"},
        //     {40, "XL"},
        //     {10, "X"},
        //     {9, "IX"},
        //     {5, "V"},
        //     {4, "IV"},
        //     {1, "I"},
        // };

        // string ans;
        // for (const auto &[value, symbol]:valueSymbols){
        //     while (num>=value){
        //         num-=value;
        //         ans+=symbol;
        //     }
        //     if (!num) break;
        // }
        // return ans;

        //ones这个数组名字起的好
        string thou[]={"", "M", "MM", "MMM"};
        string hun[]={"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
        string ten[]={"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
        string ones[]={"", "I", "II", "III", "IV","V", "VI", "VII", "VIII", "IX"};
        return thou[num/1000]+hun[num%1000/100]+ten[num%100/10]+ones[num%10];
        
    }
};

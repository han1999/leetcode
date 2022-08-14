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
        //     string和vector很相似，但这里不太一样
        //     string 常用的 insert(pos, len) 在vector中没有
        //     他们两个共有的是insert(iter, val) 插入单个元素
        //     */
        //     ans.insert(ans.begin(), nowVal%10);
        //     carry=nowVal/10;
        // }
        // if (carry) ans.insert(ans.begin(), carry);
        // return ans;

        //solution2:官方题解也并没有优化多少
        //这道题题解为啥不让我们原地操作呢，完全不需要新建一个变量
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

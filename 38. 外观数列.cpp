//2022.07.29 
class Solution {
public:
    string countAndSay(int n) {
        string ans[31];
        ans[1]="1";
        ans[2]="11";
        ans[3]="21";
        ans[4]="1211";
        ans[5]="111221";
        for (int i=6; i<=n; i++){
            string pre=ans[i-1];
            //string now要写成 string now="";吗 不写也行
            // string now="";
            string now="";
            int cnt=1;
            for (int j=1; j<pre.size(); j++){
                if (pre[j]==pre[j-1]){
                    cnt++;
                }else {
                    now+='0'+cnt;
                    now+=pre[j-1];
                    // now+=to_string(cnt)+pre[j-1];
                    cnt=1;
                }
            }
            /**
            我发现to_string的效率很低，直接用+=效率很高，+= == append >> +
            说明这个cnt<=9
            */
            now+='0'+cnt;
            now+=pre.back();
            // now+=to_string(cnt)+pre.back();
            ans[i]=now;
        }
        return ans[n];
    }
};





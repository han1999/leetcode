class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int l=0, r=0;
        int n=words.size();
        vector<string> ans;
        /*
        标准答案用while(true)，感觉很不规范，但是很香
        */
        while (r<n){
            int sumLen=words[l].size();//存放单词长度
            while (r+1<n && sumLen<=maxWidth){
                /*
                r+1-l是空格长度（每个单词之间一个空格）
                这里很容易出错
                */
                if (sumLen+words[r+1].size()+r+1-l<=maxWidth){
                    sumLen+=words[r+1].size();
                    r++;
                }else break;
            }
            /*
            这里的逻辑是单词可以取到l-r，其实用左闭右开可能更好一点
            */
            if (r==n-1){
                string lastLine=words[l];
                for (int i=l+1; i<=r; i++){
                    lastLine+=" "+words[i];
                }
                /*
                这里resize用的非常好
                */
                lastLine.resize(maxWidth, ' ');
                ans.push_back(lastLine);
                return ans;
            }else {
                if (l==r){
                    string temp=words[l];
                    temp.resize(maxWidth, ' ');
                    ans.push_back(temp);
                }else {
                    int spaceSum=maxWidth-sumLen;
                    /*
                    最难的就是放空格，这里挺巧妙的，从右边开始，每次放最少的
                    标准答案里面给的方法也很巧妙，比这个更进一步
                    */
                    vector<int> spaceNum(r-l);
                    int index=r-l-1;
                    while (spaceSum){
                        spaceNum[index]=spaceSum/(index+1);
                        spaceSum-=spaceNum[index--];
                    }
                    string temp=words[l];
                    index=0;
                    for (int i=l+1; i<=r; i++){
                        for (int j=0; j<spaceNum[index]; j++){
                            temp+=' ';
                        }
                        index++;
                        temp+=words[i];
                    }
                    ans.push_back(temp);
                }
            }
            l=++r;
        }
        return {};
        log()
    }
};

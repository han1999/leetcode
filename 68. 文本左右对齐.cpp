class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int l=0, r=0;
        int n=words.size();
        vector<string> ans;
        /*
        ��׼����while(true)���о��ܲ��淶�����Ǻ���
        */
        while (r<n){
            int sumLen=words[l].size();//��ŵ��ʳ���
            while (r+1<n && sumLen<=maxWidth){
                /*
                r+1-l�ǿո񳤶ȣ�ÿ������֮��һ���ո�
                ��������׳���
                */
                if (sumLen+words[r+1].size()+r+1-l<=maxWidth){
                    sumLen+=words[r+1].size();
                    r++;
                }else break;
            }
            /*
            ������߼��ǵ��ʿ���ȡ��l-r����ʵ������ҿ����ܸ���һ��
            */
            if (r==n-1){
                string lastLine=words[l];
                for (int i=l+1; i<=r; i++){
                    lastLine+=" "+words[i];
                }
                /*
                ����resize�õķǳ���
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
                    ���ѵľ��Ƿſո�����ͦ����ģ����ұ߿�ʼ��ÿ�η����ٵ�
                    ��׼��������ķ���Ҳ��������������һ��
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

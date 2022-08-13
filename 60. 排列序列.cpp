class Solution {
public:
    int cnt=0;
    string ans, temp;
    bool findAns=false;
    vector<int> vis;
    void trackback(int index,int n, int k){
        if (index==n){
            if (++cnt==k){
                ans=temp;
                findAns=true;
            }
            return;
        }
        for (int i=1; i<=n; i++){
            if (!vis[i]){
                vis[i]=1;
                temp+=i+'0';//temp.push_back()Ӧ��Ҳ�У� ������ȷʵ���ԣ�string��vector̫������
                trackback(index+1, n, k);
                if (findAns) return;
                temp.pop_back();
                vis[i]=0;
            }
        }
    }
    string getPermutation(int n, int k) {
        //solution1��
        // vis.resize(n+1,0);
        // trackback(0, n, k);
        // return ans;

        //solution2:
        /*
        ��ʵ������̰��
        */
        vector<int> fac(n+1);
        fac[0]=1;
        for(int i=1; i<=n; i++){
            fac[i]=i*fac[i-1];
        }
        vector<int> valid(n+1, 1);
        string ans;
        for (int i=1; i<=n; i++){
            /*
            ������ؼ����漰��һ����ŵ�����
            ��k��Ԫ���Ǵ�1��ŵģ�������Ǵ�0��ŵģ�
            ��1��ʼ�ĵ�k��Ԫ�أ��൱�ڴ�0��ʼ�ĵ�k-1��Ԫ��
            �����+1,��ת�������->��ʵ����1��ʼ��
            */
            int order=(k-1)/fac[n-i]+1;
            for (int j=1; j<=n; j++){
                /**
                �����order���Ԫ�صķ�����ֵ�ý��
                */
                order-=valid[j];
                if (order==0){
                    valid[j]=0;
                    ans+='0'+j;
                    break;
                }
            }
            k=(k-1)%fac[n-i]+1;
        }
        return ans;
    }
};

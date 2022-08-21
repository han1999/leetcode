class Solution {
public: 
    int getSteps(int now, long long  n){
        int step=0;
        long long  l=now, r=now;
        while (l<=n){
            step+=r-l+1;
            l=10*l;

            /*
            �����overflow���üһ�
            */
            r=min(10*r+9, n);
        }
        return step;
    }
    int findKthNumber(int n, int k) {
        // //solution0: ��ʱ����˵��
        // vector<string> vt(n);
        // for (int i=1; i<=n; i++){
        //     vt[i-1]=to_string(i);
        // }
        // sort(vt.begin(), vt.end());
        // return stoi(vt[k-1]);
        
        //��Ϊ֮ǰ����û�����������ݽṹ����ֻ��˵����
        int ans=1;
        k--;
        while (k){
            int steps=getSteps(ans, n);
            if (k>=steps){
                k-=steps;
                ans++;
            }else {
                k--;
                ans*=10;
            }
        }
        return ans;
    }
};

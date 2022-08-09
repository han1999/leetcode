class Solution {
public:
    int trap(vector<int>& height) {
        //solution1:
        // int n=height.size();
        // vector<int> lMax(n ,0);
        // vector<int> rMax(n,0);
        // lMax[0]=height[0];
        // for (int i=1; i<n; i++){
        //     lMax[i]=max(lMax[i-1], height[i]);
        // }
        // rMax[n-1]=height[n-1];
        // int ans=0;
        // for (int i=n-2; i>=0; i--){
        //     rMax[i]=max(rMax[i+1], height[i]);
        //     ans+=min(lMax[i], rMax[i])-height[i];
        // }
        // return ans;

        // //solution2:
        // stack<int> stk;
        // int n=height.size();
        // int ans=0;
        // /**
        // Ϊʲôstk�����i�� ����height[i]�� ��Ϊͨ��i���Եõ�height[i]
        // ����ͨ��Height[i]���ܵõ�i�����Ǵ浽һ��pair��, ��i��Ҫ����������
        // */
        // for (int i=0; i<n; i++){
        //     while (!stk.empty() && height[i]>height[stk.top()]){
        //         int preTop=stk.top();
        //         stk.pop();
        //         if (stk.empty()) break;
        //         int left=stk.top();
        //         /**
        //         ΪʲôҪ�п�ȣ���Ϊ����ջ��ջ����ͣ��������left�ڱ仯������ڱ仯
        //         �����vector��ģ�⣬˵����Ч�����ã���Ϊ�±�����ʱ�õ�
        //         */
        //         ans+=(i-left-1)*(min(height[i], height[left])-height[preTop]);
        //     }
        //     stk.push(i);
        // }
        // return ans;

        //solution3:
        int l=0, r=height.size()-1;
        int lMax=height[0], rMax=height.back();//front, back()
        int ans=0;
        while (l<r){
            lMax=max(height[l], lMax);
            rMax=max(rMax, height[r]);
            if (lMax<rMax){
                ans+=lMax-height[l++];
            }else{
                ans+=rMax-height[r--];
            }
        }
        return ans;
    }
};

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        /*
        ��Ϲд�ģ���Ȼֱ��ͨ����
        ��Ҫ���ʣ� 
        a^a=0
        a^0=a
        ���㽻���ɣ������
        */
        int ans=0;
        for(const auto &num:nums){
            ans^=num;
        }
        return ans;
    }
};

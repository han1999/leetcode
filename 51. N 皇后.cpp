class Solution {
public:

    unordered_set<int> col, dia1, dia2;
    void trackback(int index, vector<vector<string>> &ans, vector<int> &temp, int n){
        if (index==n){
            vector<string> vt;
            for (int i=0; i<n; i++){
                /*
                ���string�ĳ�ʼ����������һ����
                string��vector�ǳ����ƣ���������ʼ�����ǳ�����
                */
                string s(n, '.');
                s[temp[i]]='Q';
                vt.push_back(s);
            }
            ans.push_back(vt);
            return;
        }
        for (int i=0; i<n; i++){
            /**
            ��continue�ô����ڣ����Ա��⸴�ӵ��߼�Ƕ��
            */
            if (col.count(i)) continue;
            int dia1Index=index-i;
            if (dia1.count(dia1Index)) continue;
            int dia2Index=index+i;
            if (dia2.count(dia2Index)) continue;
            col.insert(i);
            dia1.insert(dia1Index);
            dia2.insert(dia2Index);
            temp.push_back(i);
            trackback(index+1, ans, temp, n);
            dia2.erase(dia2Index);
            dia1.erase(dia1Index);
            col.erase(i);
            temp.pop_back();
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<int> temp;
        trackback(0, ans, temp, n);
        return ans;
    }
};

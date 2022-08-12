class Solution {
public:
    int ans=0;
    unordered_set<int> col, dia1, dia2;
    void trackback(int index, int n){
        if (index==n){
            ans++;
            return;
        }
        for (int i=0; i<n; i++){
            if (col.count(i)) continue;
            int dia1Index=index-i;
            if (dia1.count(dia1Index)) continue;
            int dia2Index=index+i;
            if (dia2.count(dia2Index)) continue;

            col.insert(i);
            dia1.insert(dia1Index);
            dia2.insert(dia2Index);

            trackback(index+1,  n);

            dia2.erase(dia2Index);
            dia1.erase(dia1Index);
            col.erase(i);
            
        }
    }
    int totalNQueens(int n) {
        trackback(0, n);
        return ans;
    }
};

#include "vector"
#include "iostream"
using namespace std;
vector<int> temp;
vector<vector<int>> ans;
//子集树
void dfs(int index, int n){
    if (index == n) {
        ans.push_back(temp);
        return;
    }
    dfs(index + 1, n);
    temp.push_back(index);
    dfs(index+1, n);
    temp.pop_back();
}
//排列树 需要有一个初始的数组
void dfs1(int index, int n){
    if (index == n){
        ans.push_back(temp);
        return;
    }
    for (int i=index; i<n; i++){
        swap(temp[index], temp[i]);
        dfs1(index+1, n);
        swap(temp[index], temp[i]);
    }
}
//排列
vector<int> used;
void dfs2(int index, int n){
    if (index==n){
        ans.push_back(temp);
        return;
    }
    for (int i=0; i<n; i++){
        if (!used[i]){
            temp.push_back(i);
            used[i]=1;
            dfs2(index+1, n);
            used[i]=0;
            temp.pop_back();
        }
    }
}
int main(){
//    temp = {0,1,2,3,4};
//    dfs1(0,5);

    used.resize(5);
    dfs2(0, 5);
    for (auto vt:ans){
        for (auto num:vt){
            cout<<num<<" ";
        }
        cout<<endl;
    }
}

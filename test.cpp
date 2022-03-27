#include <vector>
#include <cstdio>
using namespace std;
vector<int> returnVector(){
	return {1,3,5};
}
void printVector(vector<int> &vt){
	for (auto num:vt){
		printf("%d ", num);
	}
}
int main(){
	vector<int> vt=returnVector();
	printVector(vt);
} 

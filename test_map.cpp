#include<cstdio>
#include <map>
#include <iostream>
#include <vector>
using namespace std;
//int main(){
//	map<string, int> mp;
//	cout<<mp["hello"]<<endl;
//}

/*
����map��ֵ��ʽ
*/ 
int main(){
	map<int, int> mp;
	cout<<"mp.size():"<<mp.size()<<endl;//mp.size():0
	
	if (mp[2]==0) cout<<"mp[2]==0"<<endl;//mp[2]==0
	cout<<"mp.size():"<<mp.size()<<endl;//mp.size():1
	//��ʹ���ж����������mp[2]����ʱ��mp�����Զ�����һ��pair �����ж�һ��Ԫ���Ƿ����ֻ����count/find
	
	map<int ,vector<int>> mp1;
	mp1[1]={1,2};
	for (auto &num:mp1[1]){
		cout<<num<<" ";
	}//1 2
	cout<<endl;
	mp1[1].emplace_back(3);
	
	for (auto &num:mp1[1]){
		cout<<num<<" ";
	}//1 2 3
	cout<<endl;
	
	
		
}

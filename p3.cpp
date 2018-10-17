#include <iostream>
#include <map>
#include <cstdlib>
#include <set>

using namespace std;

typedef long long int Int;

int main(){
	Int i, j, k;
	Int n, m, sum=0;
	Int arr[100001]={0};
	Int value[200001]={0};
	set<Int> myset;
	set<Int>::iterator it1;
	set<Int>::iterator it2;

	cin >> n;

	for(i=0;i<n;i++){
		cin >> k;
		arr[k]++;
		myset.insert(k);
	}
// constract table
	for(it1=myset.begin();it1!=myset.end();it1++){
		value[*it1+*it1] += arr[*it1]*(arr[*it1]-1)/2;
		it2=it1;
		it2++;
		for(;it2!=myset.end();it2++){
			value[*it1+*it2]+=arr[*it1]*arr[*it2];
		}
	}

	cin >> m;
	for(i=0;i<m;i++){
		cin >> k;
		if(k>200000){cout<<0<<" ";}
		else{cout<<value[k]<<" ";}
	}

	return 0;
}
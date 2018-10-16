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
	Int value[100001]={0};
	set<Int> myset;
	set<Int>::iterator it;
	cin >> n;
	Int *a = new Int[n];
	for(i=0;i<n;i++){
		cin >> a[i];
		arr[a[i]]++;
		myset.insert(a[i]);
	}

	for(i=0;i<myset.size();i++){
		it=myset.begin();
		it+=i;
		for(;(it+1)!=myset.end();it++){
			value+=
		}
	}
	cin >> m;
	//Int *b = new Int[m];
	for(i=0;i<m;i++){
		cin >> k;
	}

	delete [] a;
	//delete [] b;
	return 0;
}
#include <iostream>
#include <map>
#include <cstdlib>
#include <algorithm>

using namespace std;

typedef long long int Int;
Int value[200001]={0};
mulpoly(Int *a,Int *b){
	Int l = sizeof(a)/sizeof(*a);
	Int l1 = l/2;
	Int l2 = l-l1;
	Int K = sizeof(b)/sizeof(*b);
	Int K1 = K/2;
	Int K2 = K-K/2;

	if(K+l<=200){
		for(i=0;i<l1;i++){

			for(j=i+1;j<l;j++){

			}
		}
	}else{
		Int *c1 = new Int[l1];
		Int *d1 = new Int[l2];
		Int *c2 = new Int[K1];
		Int *d2 = new Int[K2];
		copy(a,a+l1-1,c1);
		copy(a+l1,a+l-1,d1);
		copy(b,b+K1-1,c2);
		copy(b+K1,b+K-1,d2);
		Int *ra = new Int[l1+l2-1];
		Int *rb = new Int[K1+K2-1];
		ra = mulpoly(c1,c2);
		rb = mulpoly(d1,d2);

		// deal with c
		for(i=0;i<l1;i++){
			d1[i]+=c1[i];
		}
		for(i=0;i<l2;i++){
			d2[i]+=c2[i];
		}
		rc = mulpoly(c2,d2);
		Int *r = new Int[l+K-1];
		copy(begin(ra),end(ra),r);
		for(i=0;i<)
		copy
	}
}

int main(){
	Int i, j, k;
	Int n, m, sum=0;
	Int arr[100001]={0};
	Int value[200001]={0};

	cin >> n;

	for(i=0;i<n;i++){
		cin >> k;
		arr[k]++;
		
	}
// constract table


	cin >> m;
	for(i=0;i<m;i++){
		cin >> k;
		if(k>200000){cout<<0<<" ";}
		else{cout<<value[k]<<" ";}
	}

	return 0;
}
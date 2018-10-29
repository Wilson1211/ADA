#include <iostream>
#include <map>
#include <cstdlib>
#include <algorithm>

using namespace std;

typedef long long int Int;
Int value[200001]={0};
Int* mulpoly(Int *a,Int *b, Int *cs){
	Int l = sizeof(a)/sizeof(*a);

	if(l<=200){
		Int *c = new Int[2*l-1];
		for(i=0;i<l;i++){
			c[i+i] = a[i]*(b[i]-1)/2;
			for(j=i+1;j<l;j++){
				c[i+j] = a[i]*b[j];
			}
		}
		delete [] a;
		delete [] b;
		return c;
	}else{
		Int *al = new Int[l/2];
		Int *ar = new Int[l-l/2];
		Int *bl = new Int[l/2];
		Int *br = new Int[l-l/2];
		i = l/2;
		j = l-l/2;
		copy(a,a+i-1,al);
		copy(a+i,end(a),ar);
		copy(b,b+i-1,bl);
		copy(b+i,end(b),br);
		// f1 = ac, f2 = bd, f3 = (a+b)(c+d) (ar+al)(br+bl)-f1-f2
		Int *f1 = new Int[2*i-1];
		Int *f2 = new Int[2*j-1];
		Int *f3 = new Int[2*j-1];
		f1 = mulpoly(al,bl);
		f2 = mulpoly(ar,br);
		for(k=0;k<i;k++){
			bl[k]+=al[k];
			br[k]+=ar[k];
		}
		f3 = mulpoly(bl,br);
		for(k=0;k<i;k++){
			f3[k]-=(f1[k]+f2[k]);
		}
		if(j>i){f3[j-1]-=f2[j-1];}
		Int *ret = new Int[2*l-1];

		Int fir=2*i-1;
		Int sec = 2*fir;
		copy(f1,f1+fir-1,ret);
		copy(f2,f2+)
		for(k=i;k<(i+2*j-1);k++){
			ret[k]+=f3[k-i];
		}
		for(k=sec;k<sec+2*j-1;k++){
			ret[k]+=f2[k-sec];
		}

		delete [] al;
		delete [] ar;
		delete [] bl;
		delete [] br;
		delete [] f1;
		delete [] f2;
		delete [] f3;
		return ret;
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
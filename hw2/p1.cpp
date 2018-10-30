#include <iostream>
using namespace std;

typedef long long int Int;
Int count=0;
const Int M = 1000001;
//const Int M1 = 10000001;
/*
void fism(Int *a){	// find closest smaller number
	Int i=1;
	Int b=1;
	Int tmp;
	while(*a>=b){
		tmp = b;
		b = b<<1;
		b+=1;
		count++;
	}
	*a -=tmp;
	while(*a>0){
		if((*a)&1==1){count++;}
		*a = (*a)>>1;
	}

}
*/
/*
void cnt(Int a){
	Int i, j, k;
	while(a>0){
		if(a&1==1){count++;}
		a = a>>1;
		//cout << a <<endl;
	}
}
*/

Int ff(Int *b,Int n){
	if(n<1000000){return b[n];}

//	if(b[n]!=0){return b[n];}
	if(n%2==0){return 1+ff(b,n-1);}
	else{return 1+ff(b,n/2);}
}

int main(){
	Int i=2, k,j,b=1,tmp;

	Int *a = new Int[M];
	a[0]=0;
	a[1]=1;
	
	while(i<=M){
		a[i]=a[i-1]+1;
		a[i+1]=1+a[i/2];
		i+=2;
	}

	cin >> k;
	while(k--){
		cin >> j;
		cout<<(ff(a,j))<<endl;
	}
/*
	for(i=0;i<k;i++){
		cin >> j;
		//fism(&j);
		while(j>=b){
			tmp = b;
			b = b<<1;
			b+=1;
			count++;
		}
		j -=tmp;
		while(j>0){
			if(j&1==1){count++;}
			j = j>>1;
		}
		cout<<count<<endl;
		count=0;
		b=1;
	}
	*/

	return 0 ;

}
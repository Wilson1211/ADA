#include <iostream>
using namespace std;

typedef long long int Int;
Int count=0;
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
int main(){
	Int i, k,j,b=1,tmp;
	cin >> k;
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
	return 0 ;

}
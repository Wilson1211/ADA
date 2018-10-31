#include <iostream>
using namespace std;

typedef long long int Int;

Int dist(Int**b,Int *ptr,Int *n){
	Int i, j, k=0;
	for(i=0;i<*n;i++){
		x = a[i][0]-a[*ptr][0];
		y = a[i][1]-a[*ptr][1];
		if(x<0){x*=-1;}
		if(y<0){y*=-1;}
		if(x>y){tmp=x;x=y;y=tmp;}
		if(y>=2*x){k+=y;}
		else if(y == x){k+=(x+1+(x-1)/3);}
		else{k+=(y+1+(2*x-y-1)/3);}


	}
	return k;
}

int main(){
	Int i, j, k,n;
	cin >> n;
	Int **b = new Int*[n];
	for(i=0;i<n;i++){
		b[i] = new Int[2];
		cin >>b[i][0] >> b[i][1];
	}
	for(i=0;i<n;i++){
		cout<<dist(b,&i,&n)<<endl;
	}
	for(i=0;i<n;i++){
		delete [] b[i];
	}
	delete [] b;
	return 0;
}
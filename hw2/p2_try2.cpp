#include <iostream>
using namespace std;

typedef long long int Int;

Int dist(Int**a,Int*ptr, Int *n){
	Int i, k=0,tmp,x,y;
	for(i=0;i<*n;i++){
		x = a[i][0]-a[*ptr][0];
		y = a[i][1]-a[*ptr][1];
		if(x<0){x*=-1;}
		if(y<0){y*=-1;}
		if(x>y){tmp=x;x=y;y=tmp;}
		tmp = y/2;
		if(tmp>x){k+=y;}
		else{
			k+=x+y-tmp;
			if((y-tmp*2==1)&&(x-tmp==2)){
				k-=1;
			}
		}
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
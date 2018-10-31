#include <iostream>
using namespace std;

typedef long long int Int;
const Int M=1000000;

Int dist(Int**a,Int**b,Int *m,Int *n){
	Int i, k=0,x,y;
	for(i=0;i<(*n);i++){
		x = b[*m][0]-b[i][0];
		y = b[*m][1]-b[i][1];
		if(x<0){x = -1*x;}
		if(y<0){y = -1*y;}
		k+=a[x][y];
	}
	return k;
}


int main(){
	Int i, j, k,n;
	Int **a = new Int*[M];//distance array
	for(i=0;i<M;i++){
		a[i]=new Int[M];
	}
	for(i=0;i<M;i++){
		a[0][i]=i;
		a[i][0]=i;
	}
	a[1][1]=2;
	// deal with second row and column
	for(i=2;i<M;i++){
		a[1][i] = (a[0][i]<a[1][i-1])?a[0][i]:a[1][i-1];	// one time
		a[1][i]++;
		if(a[1][i]>(a[0][i-2]+2)){a[1][i] = a[0][i-2]+2;}		// two times
		//a[i][1] = (a[i][0]<a[i-1][1])?a[i][0]:a[i-1][1];	// one time
		//a[i][1]++;
		//if(a[i][1]>(a[i-2][0]+2)){a[i][1] = a[i-2][0]+2;}		// two times
		a[i][1] = a[1][i]; // symmetry
	}
	for(i=2;i<M;i++){
		for(j=i;j<M;j++){
			a[i][j] = (a[i-1][j]<a[i][j-1])?a[i-1][j]:a[i][j-1];
			a[i][j]++;
			if(a[i][j]>(a[i-1][j-2]+2)){a[i][j]=a[i-1][j-2]+2;}
			if(a[i][j]>(a[i-2][j-1]+2)){a[i][j]=a[i-2][j-1]+2;}
		}
		a[j][i]=a[i][j];
	}
	cin >> n;
	Int **b = new Int*[n];
	for(i=0;i<n;i++){
		b[i] = new Int[2];
		cin >> b[i][0] >> b[i][1];
	}
	for(i=0;i<n;i++){
		cout<<dist(a,b,&i,&n)<<endl;
	}



	return 0;
}
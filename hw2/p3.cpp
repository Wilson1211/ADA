#include <iostream>
using namespace std;
typedef unsigned long long int Int;

const Int M = 1000000007;
int isillum(Int* a){
	int i, j, k;
	int thr=0,six=0,nine=0;
	if((*a)%33==0){
		while((*a)!=0){
			k=(*a)%10;
			if(k==3){
				thr++;
			}else if(k==6){
				six++;
			}else if(k==9){
				nine++;
			}
			(*a) /=10;
		}
		if(thr%3==0){
			if(six%3==0){
				if(nine%3==0){
					return 1;
				}
				return 0;
			}
			return 0;
		}
		return 0;
	}
	return 0;
}

int main(){
	int i, j,n,m;

	cin >> n >> m;
	Int **a = new Int*[n];
	// readin
	for(i=0;i<n;i++){
		a[i] = new Int[m];
		for(j=0;j<m;j++){
			cin >> a[i][j];
		}
	}
	// first row
	for(j=0;j<m;j++){
		if(isillum(&a[0][j])){
			//a[0][j]=0;
			for(;j<m;j++){a[0][j]=0;}
		}else{a[0][j]=1;}
	}
	// first column
	for(i=0;i<n;i++){
		if(isillum(&a[i][0])){
			//a[i][0]=0;
			for(;i<n;i++){
				a[i][0]=0;
			}
		}else{
			a[i][0]=1;
		}
	}

	for(i=1;i<n;i++){
		for(j=1;j<m;j++){
			if(isillum(&a[i][j])){
				a[i][j]=0;
			}else{a[i][j]= (a[i-1][j]+a[i][j-1])%M;}
		}
	}
	cout<<(a[i-1][j-1])<<endl;
	return 0;
}
#include <iostream>
using namespace std;
typedef unsigned long long int Int;

const Int M = 1000000007;
const Int K = 10000000000;
/*
int isillum(Int* a){
	int i, j=1, k,ele=0,the=0;
	int thr=0,six=0,nine=0;
	
	while((*a)!=0){
		k=(*a)%10;
		ele+=k*j;
		j*=(-1);
		the = (the+k)%3;
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
				if(the%3==0){
					ele=(ele>=0)?ele:(-1)*ele;
					if(ele%11==0){return 1;}
					return 0;
				}
				return 0;
			}
			return 0;
		}
		return 0;
	}
	return 0;
}
*/
int isillum(Int* a){
	int i, j=0, k;
	int thr=0,six=0,nine=0;
	Int rem,imit=*a;//imitate
	while(imit !=0){
		rem = imit%K;
		j+=(rem)%33;
		j%=33;
		imit /= K;
	}
	if(j!=0){return 0;}
	//if((*a)%33==0){
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
	//}
	//return 0;
}
int main(){
	Int i, j,n,m;

	cin >> n >> m;
	i=n;
	n=0;
	while(i<=m){
		j=i;
		if(isillum(&j)){
			n++;
			n%=(M);
		}
		i++;
	}
	cout<<n;
	return 0;
}
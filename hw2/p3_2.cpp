#include <iostream>
using namespace std;

typedef long long int Int;

int main(){
	Int n,m;
	Int i, j ,k1,k2,k3,rem,k;
	Int ******a = new Int*****[1000];//[10][1000][1000][1000][33];
	for(i=0;i<1000){
		*****a[i] = new Int****[10];
		for(j=0;j<10;j++){
			****a[i][j]=new Int***[1000];
			for(k1=0;k1<1000;k1++){
				***a[i][j][k1]=new **Int[1000];
				for(k2=0;k2<1000;k2++){
					**a[i][j][k1][k2] = new *Int[1000];
					for(k3=0;k3<1000;k3++){
						*a[i][j][k1][k2][k3] = new Int[33];
					}
				}
			}
		}
	}
	// first row
	for(j=0;j<10;j++){
		if(j==3){
			a[0][j][1][0][0][j] = 1;
		}else if(j==6){
			a[0][j][0][1][0][j] = 1;
		}else if(j==9){
			a[0][j][0][0][1][j] = 1;
		}else{
			a[0][j][0][0][0][j] = 1;
		}
	}


	for(i=1;i<1000;i++){
		for(j=0;j<i;j++){
			if(j==3){
				for(k1=1;k1<=i+1;k1++){
					for(k2=0;k2<=(i+1-k1);k2++){
						for(k3=0;k3<=(i+1-k1-k2);k3++){
							for(rem=0;rem<33;rem++){								
								for(k=0;k<10;k++){
									a[i][j][k1][k2][k3][(rem+j)%33] += a[i-1][k][k1-1][k2][k3][rem];
								}								
							}
						}
					}
				}
			}else if(j==6){
				for(k1=0;k1<=i+1;k1++){
					for(k2=1;k2<=(i+1-k1);k2++){
						for(k3=0;k3<=(i+1-k1-k2);k3++){
							for(rem=0;rem<33;rem++){			
								for(k=0;k<10;k++){
									a[i][j][k1][k2][k3][(rem+j)%33] += a[i-1][k][k1][k2-1][k3][rem];
								}
							}
						}
					}
				}
			}else if(j==9){
				for(k1=0;k1<=i+1;k1++){
					for(k2=0;k2<=(i+1-k1);k2++){
						for(k3=1;k3<=(i+1-k1-k2);k3++){
							for(rem=0;rem<33;rem++){
								for(k=0;k<10;k++){
									a[i][j][k1][k2][k3][(rem+j)%33] += a[i-1][k][k1][k2][k3-1][rem];
								}								
							}
						}
					}
				}
			}else{
				for(k1=0;k1<=i+1;k1++){
					for(k2=0;k2<=(i+1-k1);k2++){
						for(k3=0;k3<=(i+1-k1-k2);k3++){
							for(rem=0;rem<33;rem++){{
								for(k=0;k<10;k++){
									a[i][j][k1][k2][k3][(rem+j)%33] += a[i-1][k][k1][k2][k3][rem];
								}
							}
						}
					}
				}
			}
		}
	}

	cin >> n >> m;

	


}
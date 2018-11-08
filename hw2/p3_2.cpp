#include <iostream>
using namespace std;

typedef long long int Int;



int main(){
	Int n,m;
	Int i, j ,k1,k2,k3,rem,k;
	Int ******a = new Int*****[1000];//[10][1000][1000][1000][33]; [10][3][3][3][33]
	for(i=0;i<1000;i++){
		a[i] = new Int****[10];
		for(j=0;j<10;j++){
			a[i][j]=new Int***[3];//[1000];
			for(k1=0;k1<3;k1++){
				a[i][j][k1]=new Int**[3];//[1000];
				for(k2=0;k2<3;k2++){
					a[i][j][k1][k2] = new Int*[3];//[1000];
					for(k3=0;k3<3;k3++){
						a[i][j][k1][k2][k3] = new Int[33];
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
		for(j=0;j<10;j++){
			if(j==3){
				for(k1=0;k1<=2;k1++){
					for(k2=0;k2<=2;k2++){	// i+1-k1
						for(k3=0;k3<=2;k3++){	// i+1-k1-k2
							for(rem=0;rem<33;rem++){								
								for(k=0;k<10;k++){
									if(j==3){
										a[i][j][k1][k2][k3][rem] += a[i-1][k][(k1+2)%3][k2][k3][(rem+33-j)%33];
									}else if(j==6){
										a[i][j][k1][k2][k3][rem] += a[i-1][k][k1][(k2+2)%3][k3][(rem+33-j)%33];
									}else if(j==9){
										a[i][j][k1][k2][k3][rem] += a[i-1][k][k1][k2][(k3+2)%3][(rem+33-j)%33];
									}else{
										a[i][j][k1][k2][k3][rem] += a[i-1][k][k1][k2][k3][(rem+33-j)%33];
									}
								}
							}
						}
					}
				}
			}
		}
	}

/*


	for(i=1;i<1000;i++){
		for(j=0;j<10;j++){
			if(j==3){
				for(k1=0;k1<=2;k1++){
					for(k2=0;k2<=2;k2++){	// i+1-k1
						for(k3=0;k3<=2;k3++){	// i+1-k1-k2
							for(rem=0;rem<33;rem++){								
								for(k=0;k<10;k++){
									a[i][j][k1][k2][k3][rem] += a[i-1][k][(k1+2)%3][k2][k3][(rem+33-j)%33];
								}								
							}
						}
					}
				}
			}else if(j==6){
				for(k1=0;k1<=2;k1++){
					for(k2=0;k2<=2;k2++){	// i+1-k1
						for(k3=0;k3<=2;k3++){	// i+1-k1-k2
							for(rem=0;rem<33;rem++){			
								for(k=0;k<10;k++){
									a[i][j][k1][k2][k3][rem] += a[i-1][k][k1][(k2+2)%3][k3][(rem+33-j)%33];
								}
							}
						}
					}
				}
			}else if(j==9){
				for(k1=0;k1<=2;k1++){
					for(k2=0;k2<=2;k2++){
						for(k3=0;k3<=2;k3++){	// i+1-k1-k2
							for(rem=0;rem<33;rem++){
								for(k=0;k<10;k++){
									a[i][j][k1][k2][k3][rem] += a[i-1][k][k1][k2][(k3+2)%3][(rem+33-j)%33];
								}								
							}
						}
					}
				}
			}else{
				for(k1=0;k1<=2;k1++){
					for(k2=0;k2<=2;k2++){	// i+1-k1
						for(k3=0;k3<=2;k3++){	// i+1-k1-k2
							for(rem=0;rem<33;rem++){
								for(k=0;k<10;k++){
									a[i][j][k1][k2][k3][rem] += a[i-1][k][k1][k2][k3][(rem+33-j)%33];
								}
							}
						}
					}
				}
			}
		}
	}
*/
	cin >> n >> m;
	Int sum1=0,sum2=0;
	int size=0;
	rem=0;
	int b1[1000]={};
	int b2[1000]={};
	n--;// since l to r include l
	if(n>1){
		while(n!=0){
			k = n%10;
			b1[size]=k;
			size++;
			n/=10;
		}
		for(i=size-1;i>=0;i--){
			for(j=0;j<b1[i];j++){
				sum1+=a[i][j][0][0][0][0];
			}
		}
		sum1+=a[0][b1[0]][0][0][0][0];


	}
	size=0;
	while(m!=0){
		k=m%10;
		b2[size] = k;
		size++;
		m/=10;
	}
	for(i=size-1;i>=0;i--){
		for(j=0;j<b2[i];j++){
			sum2+=a[i][j][0][0][0][0];
		}
	}
	sum2+=a[0][b2[0]][0][0][0][0];

	cout<<sum2-sum1<<endl;

	return 0;

}
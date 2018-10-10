#include <iostream>
#include <cstdlib>

using namespace std;

long long int sum=0;
void sortx(int **b, begin,end,l){
	long long int tmp;
	if(l == 1){return;}
	if(l == 2){
		if(b[begin][0]>b[end][0]){
			tmp = b[end][0];
			b[end][0] = b[begin][0];
			b[begin][0] = tmp;
			tmp = b[end][1];
			b[end][1] = b[begin][1];
			b[begin][1] = tmp;
		}
	}else{
		sortx(**b,begin,begin+l/2-1,l/2);
		sortx(**b,begin+l/2,end,end-begin-l/2+1);
	}
	return ;
}

int** halfsum(long long int begin, long long int end, long long int length, int**a){
	int half = length/2;
	long long int l = length;
	if(length == 1){
		int **r = new int*[1];
		r[0] = new int[2];
		r[0][0] = a[begin][0];
		r[0][1] = a[end][0];
		return r;
	}

	int **le = new int*[length/2];
	int **ri = new int*[length - length/2];


	if(length % 2==0){
		le = halfsum(begin,begin+length/2-1,length/2);
		ri = halfsum(begin+length/2,end,length/2);

	}else{
		le = halfsum(begin,begin+length/2-1,length/2);
		ri = halfsum(begin+length/2,end,length/2+1);
	}

	// merge
	int **b1 = new int *[length];
	long long int middle = length/2+begin;
	long long int left=0,right=0;

	for(i=0;i<length;i++){
		b1[i] = new int[2];
		if(le[left][1] <= re[right][1]){
			b1[i][0] = le[left][0];
			b1[i][1] = le[left][1];
			left++;
		}else{
			b1[i][0] = re[right][0];
			b1[i][1] = re[right][1];
			right++;
		}
	}
	// calculate area sum
	long long int tmpsum=0;
	long long int leftsum=0,rightsum=0,middlesum=0;
	long long int sumla=0,sumlb=0,sumlab=0,sumra=0,sumrb=0,sumrab=0;
	long long int middlea=0,middleb=0,middleab=0;

	// first
	for(i=0;i<length;i++){
		if(b1[i][0]<middle){
			for(j=0;j<i;j++){
				if(b1[j][0]>=middle){
					sumla += b1[j][0];
					sumlb += b1[j][1];
					sumlab += b1[j][0]*b1[j][1];
				}
			}
			leftsum  = b1[i][1]*sumla-sumlab-(l-l/2)*b1[i][0]*b1[i][1]+b1[i][0]*sumlb;
			
			for(j=i+1;j<length;j++){
				if(b1[j][0]>=middle){
					sumra += b1[j][0];
					sumrb += b1[j][1];
					sumrab += b1[j][0]*b1[j][1];
				}
			}
			rightsum = sumrab + (l-l/2)*b1[i][0]*b1[i][1] - b1[i][0]*sumrb - b1[i][1]*sumra;
		}
		sum += (leftsum+rightsum);
		break;
	}

	// rest
	k=i;
	while(k<l){
		for(i=k+1;i<l;i++){
			if(b1[i][0]<middle){
				break;
			}
		}
		for(j=k;j<i;j++){
			if(b1[j][0]>=middle){
				middlea += b1[j][0];
				middleb += b1[j][1];
				middleab += b1[j][0]*b1[j][1];
			}
		}
		leftsum += ((b1[i][1]-b1[k][1])*sumla + (l-l/2)*(b1[k][0]*b1[k][1]-b1[i][0]*b1[i][1]) + (b1[i][0]-b1[k][0])*sumlb);
		rightsum -= ()

		k=i;
	}

	



	for(i=0;i<length/2;i++){
		delete [] le[i];
		delete [] re[i];
	}
	if(length % 2 == 1){delete[] re[length/2];}
	delete [] le;
	delete [] re;
}


int main(){
	long long int i ,j ,k, m, n;
	cin >> n;
	int **a = new int*[n];
	for(i=0;i<n;i++){
		a[i]=new int[2];
		cin >> a[i][0] >> a[i][1];
	}
	sortx(a);
	halfsum(0,n-1,n,a);




	return 0;
}

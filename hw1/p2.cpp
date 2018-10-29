#include <iostream>
#include <cstdlib>
#include <map>

using namespace std;

long long int sum=0;

void pp(long long int**c,long long int n){
	long long int i, j, k;
	for(i=0;i<n;i++){
		cout<<c[i][0]<<" "<<c[i][1]<<endl;
	}

}
/*void sortx(long long int **b, long long int begin,long long int end,long long int l){
	long long int tmp;
	long long int **a1 = new long long int*[l/2];
	long long int **a2 = new long long int*[l-l/2];
	long long int **a = new long long int*[l];
	long long int left=0,right=0;
	long long int i, j;

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
		sortx(b,begin,begin+l/2-1,l/2);
		sortx(b,begin+l/2,end,end-begin-l/2+1);
	}

	j = 0;
	for(i=begin;i<begin+l/2;i++){
		a1[j] = new long long int[2];
		a1[j][0] = b[i][0];
		a1[j][1] = b[i][1];
		j++;
	}
	j=0;
	for(i=begin+l/2;i<=end;i++){
		a2[j] = new long long int[2];
		a2[j][0] = b[i][0];
		a2[j][1] = b[i][1];
		j++;
	}

	for(i=0;i<l;i++){
		a[i] = new long long int[2];
		if(a1[left][0]>a2[right][0]){
			a[i][0] = a2[right][0];
			a[i][1] = a2[right][1];
			right++;
		}else{
			a[i][0] = a1[left][0];
			a[i][1] = a1[left][1];
			left++;
		}
		if(left == l/2){
			i++;
			for(;i<l;i++){
				a[i] = new long long int[2];
				a[i][0] = a2[right][0];
				a[i][1] = a2[right][1];
				right++;
			}
			break;
		}else if(right == l-l/2){
			i++;
			for(;i<l;i++){
				a[i] = new long long int[2];
				a[i][0] = a1[left][0];
				a[i][1] = a1[left][1];
				left++;
			}
			break;
		}
	}
	j=0;
	for(i=begin;i<=end;i++){
		b[i][0] = a[j][0];
		b[i][1] = a[j][1];
		j++;
	}

	// delete
	for(i=0;i<l/2;i++){
		delete [] a1[i];
		delete [] a2[i];
		delete [] a[i];
	}
	if(l%2==0){delete [] a2[i];delete [] a[i];i++;}
	for(;i<l;i++){
		delete [] a[i];
	}
	delete [] a1;
	delete [] a2;
	delete [] a;

	return ;
}*/

void sortx(long long int **b, long long int begin,long long int end,long long int l){
	long long int i, j, k;
	multimap<long long int,long long int> mymap;
	multimap<long long int,long long int>::iterator it;

	for(i=0;i<l;i++){
		mymap.insert(pair<long long int,long long int>(b[i][0],b[i][1]));
	}
	i=0;
	for(it=mymap.begin();it!=mymap.end();it++){
		b[i][0] = it->first;
		b[i][1] = it->second;
		i++;
	}
}

long long int** halfsum(long long int begin, long long int end, long long int length, long long int**a){
	
	long long int half = length/2;
	long long int l = length;
	long long int i, j,k;
	if(length == 2){
		long long int **r = new long long int*[2];
		r[0] = new long long int[2];
		r[1] = new long long int[2];
		if(a[begin][1]>a[end][1]){
			r[0][0] = a[end][0];
			r[0][1] = a[end][1];
			r[1][0] = a[begin][0];
			r[1][1] = a[begin][1];
			sum += (a[end][0]-a[begin][0])*(a[begin][1]-a[end][1]);
		}else{
			r[0][0] = a[begin][0];
			r[0][1] = a[begin][1];
			r[1][0] = a[end][0];
			r[1][1] = a[end][1];
			sum += (a[end][0]-a[begin][0])*(a[end][1]-a[begin][1]);
		}

		return r;
	}else if(length == 1){
		long long int **r = new long long int*[1];
		r[0] = new long long int[2];
		r[0][0] = a[begin][0];
		r[0][1] = a[end][1];
		return r;
	}

	long long int **le = new long long int*[length/2];
	long long int **ri = new long long int*[length - length/2];

	/*
	if(length % 2==0){
		le = halfsum(begin,begin+length/2-1,length/2,a);
		ri = halfsum(begin+length/2,end,length/2,a);

	}else{
		le = halfsum(begin,begin+length/2-1,length/2,a);
		ri = halfsum(begin+length/2,end,length/2+1,a);
	}
	*/
	le = halfsum(begin,begin+length/2-1,length/2,a);
	ri = halfsum(begin+length/2,end,(length+1)/2,a);


	// merge
	long long int **b1 = new long long int *[length];
	long long int middle = a[length/2+begin][0];
	long long int left=0,right=0;

	for(i=0;i<l;i++){
		b1[i] = new long long int[2];
		if(le[left][1] <= ri[right][1]){
			b1[i][0] = le[left][0];
			b1[i][1] = le[left][1];
			left++;
		}else{
			b1[i][0] = ri[right][0];
			b1[i][1] = ri[right][1];
			right++;
		}
		if(left == l/2){
			i++;
			for(;i<l;i++){
				b1[i] = new long long int[2];
				b1[i][0] = ri[right][0];
				b1[i][1] = ri[right][1];
				right++;
			}
			break;
		}else if(right == l-l/2){
			i++;
			for(;i<l;i++){
				b1[i] = new long long int[2];
				b1[i][0] = le[left][0];
				b1[i][1] = le[left][1];
				left++;
			}
			break;
		}
	}

	// calculate area sum
	long long int ptr1=-1,ptr2=-1,count=0;
	long long int tmpsum=0;
	long long int leftsum=0,rightsum=0,middlesum=0;
	long long int sumla=0,sumlb=0,sumlab=0,sumra=0,sumrb=0,sumrab=0;
	long long int middlea=0,middleb=0,middleab=0;

	// first
	for(i=0;i<l-l/2;i++){
		if(ri[i][1]<=le[0][1]){
			sumla += ri[i][0];
			sumlb += ri[i][1];
			sumlab += ri[i][0]*ri[i][1];
			ptr1 = i;
			count++;
		}else if(ri[i][1]>le[0][1]){
			sumra += ri[i][0];
			sumrb += ri[i][1];
			sumrab += ri[i][0]*ri[i][1];
		}
	}
	leftsum = le[0][1]*sumla-sumlab-count*le[0][0]*le[0][1]+le[0][0]*sumlb;
	rightsum = sumrab-le[0][1]*sumra-le[0][0]*sumrb+(l-l/2-count)*le[0][0]*le[0][1];
	sum += (leftsum+rightsum);


	//rest
	for(i=1;i<l/2;i++){
		middlea = 0;
		middleb = 0;
		middleab = 0;
		middlesum = 0;
		ptr2 = ptr1;
		for(j=ptr1+1;j<(l-l/2);j++){
			if(ri[j][1]<=le[i][1]){
				ptr2 = j;
				middlea += ri[j][0];
				middleb += ri[j][1];
				middleab += ri[j][0]*ri[j][1];
			}else{break;}
		}

		sumra -= middlea;
		sumrb -= middleb;
		sumrab -= middleab;

		middlesum = middleab - le[i-1][1]*middlea - le[i-1][0]*middleb + (ptr2-ptr1)*le[i-1][0]*le[i-1][1];
		rightsum -= middlesum;
		leftsum += (le[i][1]-le[i-1][1])*sumla + (ptr1+1)*(le[i-1][0]*le[i-1][1]-le[i][0]*le[i][1]) + (le[i][0]-le[i-1][0])*sumlb;
		leftsum += le[i][1]*middlea - middleab - (ptr2-ptr1)*le[i][0]*le[i][1] + le[i][0]*middleb;
		rightsum += (le[i-1][1]-le[i][1])*sumra+(le[i-1][0]-le[i][0])*sumrb+(l-l/2-ptr2-1)*(le[i][0]*le[i][1] - le[i-1][0]*le[i-1][1]);

		sum += (leftsum+rightsum);

		ptr1 = ptr2;
	}

	/*
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
			leftsum  = b1[i][1]*sumla-sumlab-i*b1[i][0]*b1[i][1]+b1[i][0]*sumlb;
			
			for(j=i+1;j<length;j++){
				if(b1[j][0]>=middle){
					sumra += b1[j][0];
					sumrb += b1[j][1];
					sumrab += b1[j][0]*b1[j][1];
				}
			}
			rightsum = sumrab + (l-l/2-i)*b1[i][0]*b1[i][1] - b1[i][0]*sumrb - b1[i][1]*sumra;
		}
		sum += (leftsum+rightsum);
		break;
	}

	// rest
	k=i;
	long long int count = 1;
	while(k<l){
		for(i=k+1;i<l;i++){
			if(b1[i][0]<middle){
				break;
			}
		}
		if(i>=l){break;}
		for(j=k;j<i;j++){
			if(b1[j][0]>=middle){
				middlea += b1[j][0];
				middleb += b1[j][1];
				middleab += b1[j][0]*b1[j][1];
			}
		}
		middlesum = b1[k][1]*middlea-middleab-(i-k-1)*b1[k][0]*b1[k][1]+b1[k][0]*middleb;
		rightsum -= middlesum;
		leftsum += ((b1[i][1]-b1[k][1])*sumla + (k-count+1)*(b1[k][0]*b1[k][1]-b1[i][0]*b1[i][1]) + (b1[i][0]-b1[k][0])*sumlb);
		leftsum += (b1[i][1]*middlea-middleab-(i-k-1)*b1[i][0]*b1[i][1]+b1[i][0]*middleb);
		rightsum += ((b1[k][1]-b1[i][1])*sumra+(b1[k][0]-b1[i][0])*sumrb+(i-k-1)*(b1[i][0]*b1[i][1]-b1[k][0]*b1[k][1]));
		sum += (leftsum+rightsum);

		middlea = 0;
		middleb = 0;
		middleab = 0;

		k=i;
		count++;
	}

	*/



	for(i=0;i<length/2;i++){
		delete [] le[i];
		delete [] ri[i];
	}
	if(length % 2 == 1){delete[] ri[length/2];}
	delete [] le;
	delete [] ri;

	return b1;
}


int main(){
	long long int i ,j ,k, m, n;
	cin >> n;
	long long int **a = new long long int*[n];

	for(i=0;i<n;i++){
		a[i]=new long long int[2];
		cin >> a[i][0] >> a[i][1];
	}
	sortx(a,0,n-1,n);
	
	long long int **b = new long long int*[n];
	b = halfsum(0,n-1,n,a);
	
	cout<<sum<<endl;
	return 0;
}

#include <iostream>
#include <map>
#include <cstdlib>
#include <set>

using namespace std;

typedef long long int Int;
void pp(Int*a,Int n){
	Int i;
	for(i=0;i<n;i++){
		cout<<a[i]<<" ";
	}
	cout<<endl;
}

int main(){
	Int i, j, k;
	Int n, m, sum=0;
	Int arr[100001]={0};
	set<Int> myset;
	set<Int>::iterator itset;
	cin >> n;
	Int *a = new Int[n];
	for(i=0;i<n;i++){
		cin >> a[i];
		arr[a[i]]++;
	}
	cin >> m;
	Int *b = new Int[m];
	for(i=0;i<m;i++){
		cin >> b[i];
	}
/*
	for(i=0;i<m;i++){
		sum=0;
		k=b[i]/2;
		if(b[i]>200000){cout<<0;continue;}
		for(it = myset.begin();it!=myset.end();it++){
			if(*it<=k){
				if(*it == b[i]-*it){
					sum += arr[*it]*(arr[*it]-1)/2;
				}else{
					sum += arr[*it]*arr[b[i]-*it];
				}
			}

		}
		cout<<sum<<" ";
	}
*/

		for(j=0;j<n;j++){
			if(!myset.count(a[j])){
				if(a[j]<= b[i]){
					if(b[i]%2!=0){
						sum += (arr[a[j]]*arr[b[i]-a[j]]);
					}else{
						if(k == a[j]){	
							sum += arr[a[j]]*(arr[a[j]]-1)/2;
						}else{
							sum += (arr[a[j]]*arr[b[i]-a[j]]);
						}
					}
					//sum;
				}	
				myset.insert(a[j]);
				myset.insert(b[i]-a[j]);
			}
		}
		cout<<sum<<" ";
		myset.clear();
	}

	delete [] a;
	delete [] b;
	return 0;
}
/*
int main(){
	Int i, j, k;
	Int n, m, sum=0;
	Int arr[100001]={0};
	set<Int> myset;
	cin >> n;
	Int *a = new Int[n];
	for(i=0;i<n;i++){
		cin >> a[i];
		arr[a[i]]++;
	}
	cin >> m;
	Int *b = new Int[m];
	for(i=0;i<m;i++){
		cin >> b[i];
	}
	for(i=0;i<m;i++){
		sum=0;
		k=b[i]/2;
		if(b[i]>200000){cout<<0;continue;}
		for(j=0;j<n;j++){
			if(!myset.count(a[j])){
				if(a[j]<= b[i]){
					if(b[i]%2!=0){
						sum += (arr[a[j]]*arr[b[i]-a[j]]);
					}else{
						if(k == a[j]){	
							sum += arr[a[j]]*(arr[a[j]]-1)/2;
						}else{
							sum += (arr[a[j]]*arr[b[i]-a[j]]);
						}
					}
					//sum;
				}	
				myset.insert(a[j]);
				myset.insert(b[i]-a[j]);
			}
		}
		cout<<sum;
		myset.clear();
	}

	delete [] a;
	delete [] b;
	return 0;
}
*/
/*int main(){
	Int i=0,j ,k ;
	Int n, m,sum;
	cin >> n;
	Int *a = new Int[n];
	multimap<Int,Int> mmap;
	multimap<Int,Int>::iterator it;
	multimap<Int,Int>::iterator ptr;
	set<Int> myset;
	set<Int>::iterator its;
	while(i<n){
		cin >> a[i];
		mmap.insert(pair<Int,Int>(a[i],i));
		i++;
	}
	cin >> m;
	Int *b = new Int[m];
	i=0;
	while(i<m){
		cin >> b[i++];
	}

	for(i=0;i<m;i++){
		sum = 0;
		if(b[i]>200000){
			sum = 0;
		}else{
			for(it=mmap.begin();it!=mmap.end();it++){
				its = myset.find(it->first);
				if(its!=myset.end()){continue;}
				else{myset.insert(it->first);}
				if(it->first == b[i]-it->first){	//	same
					sum += (mmap.count(it->first))*(mmap.count(it->first)-1)/2;
					myset.insert(it->first);
				}else{	//	different value
					ptr = mmap.find(b[i]-it->first);
					if(ptr!=mmap.end()){
						sum+=(mmap.count(it->first))*(mmap.count(ptr->first));
						myset.insert(ptr->first);
					}
				}
			}
			myset.clear();
		}
		cout<<sum<<" ";
	}
	cout<<endl;
	/*
	while(m--){
		cin >> k;
		sum=0;
		if(k>200000){
			cout<<0<<" ";
		}else{
			for(it=mmap.begin();it!=mmap.end();it++){
				its = myset.find(it->first);
				if(its!=myset.end()){continue;}
				else{myset.insert(it->first);}
				if(it->first == k-it->first){	//	same
					sum += (mmap.count(it->first))*(mmap.count(it->first)-1)/2;
					myset.insert(it->first);
				}else{	//	different value
					ptr = mmap.find(k-it->first);
					if(ptr!=mmap.end()){
						sum+=(mmap.count(it->first))*(mmap.count(ptr->first));
						myset.insert(ptr->first);
					}
				}
			}
			myset.clear();
			cout<<sum<<" ";
		}
	}
	cout<<endl;
	delete [] a;
	delete [] b;
	return 0;
}
*/
#include <iostream>
#include <queue>
#include <vector>

using namespace std;
typedef int Int;

/*
void call(vector<Int> *ss){
	Int sum=0;
	vector<Int>::iterator it = (*ss).begin();
	while(it!=(*ss).end()){
		sum += *it;
		//cout<<*it<<" ";
		it++;
	}
	//cout<<endl;
	cout<<sum<<endl;
}
*/

void call(vector<Int> *v){
	vector<Int>::iterator it = (*v).begin();
	Int sum=0;
	Int i;
	while(it!=(*v).end()){
		i = *(it+1)-(*it);
		//cout<<*it<<" ";
		sum += i*i;
		it+=2;
	}
	//cout<<endl;
	cout<<sum<<endl;
}
/*
//Int relax(Int k, vector<Int> *vv, vector<Int> *sum){//k is even number
void relax(Int k, vector<Int> *vv){//k is even number

	Int i=0, j=k, l=0,m=0,last_sum=0;
	vector<Int>::iterator it = (*vv).begin()+k;
	l = *it;
	it--;
	j--;
	while(it!=(*vv).begin()){
		if((*it)<l){
			if((*it)%2 == 0){//cout<<"klkl\n"; // left 
				(*vv).erase((*vv).begin()+j+1,(*vv).begin()+k+1);
				i = j + 1;// how many elements left
				//m = (k-j)/2;
				//(*sum).erase((*sum).end()-m,(*sum).end());
				//last_sum = (*vv)[j+1]-(*vv)[j];
				//(*sum).push_back(last_sum*last_sum);
			}else{ // right
				if(j+1 != k){//cout<<"kk\n";
					(*vv).erase((*vv).begin()+j+1,(*vv).begin()+k);
				
					i = j + 2;// k+1 - (k-j-1) = j+2;
					//m = (k-j)/2;
					//(*sum).erase((*sum).end()-m,(*sum).end());
				}
				//last_sum = (*vv)[j+2]-(*vv)[j+1];
				//(*sum).push_back(last_sum*last_sum);
			}
			//call(sum);
			call(vv);
			//return i;
		}
		j--;
		it--;
	}

	// if is out of while loop represent the leftest is k rightmost is k+1
	(*vv).erase((*vv).begin(),(*vv).begin()+k);
	//(*sum).clear();
	//last_sum = (*vv)[1]-(*vv)[0];
	//(*sum).push_back(last_sum*last_sum);
	//call(sum);
	call(vv);
	//return 2;

}
*/
int main(){
	Int i, j ,k=0,n,m;
	vector<Int> store;
	//vector<Int> num;
	cin >> n;

	// first time
	n--;
	cin >> i>>j;
	store.push_back(i);
	store.push_back(j);
	k++;
	//num.push_back((j-i)*(j-i));
	cout<<(j-i)*(j-i)<<endl;
	// rest
	while(n--){
		cin >> i >> j;
		k+=2;
		store.push_back(i);
		store.push_back(j);
		//m = relax(k-1,&store,&num);
		relax(k-1,&store);

	}
	return 0;
}
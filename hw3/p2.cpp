#include <iostream>
#include <stack>
using namespace std;
typedef long long int Int;


void call(stack<Int> st){
	//stack<Int>::iterator it 
	Int sum=0,k1,k2;
	while(!st.empty()){
		k1 = st.top();

		st.pop();
		k2 = st.top();
		st.pop();
		//cout<<k1<<" "<<k2<<" ";
		sum += (k1-k2)*(k1-k2);
	}
	//cout<<endl;
	cout<<sum<<endl;
}

int main(){
	Int i, j, k, n;
	bool flag=0;
	stack<Int> myst;
	cin >> n;
	cin >>i >> j;
	myst.push(i);
	myst.push(j);
	cout<< (j-i)*(j-i)<<endl;
	n--;
	while(n--){
		cin >> i >> j;
		k = myst.top(); // k is the right
		while(k>i){
			myst.pop();
			k = myst.top(); // k is the left
			if(k < i){
				myst.push(j);
				flag = 1;
				break;
			}else{
				myst.pop();
				if(myst.empty()){
					flag = 0;
					break;
				}
				k = myst.top(); // k is the right
			}
		}
		if(flag == 0){
			myst.push(i);
			myst.push(j);
		}
		call(myst);
		flag = 0;
	}

	return 0;
}
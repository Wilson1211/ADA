#include <iostream>
#include <queue>
#include <set>
using namespace std;
//typedef pair<int,int> pi;
typedef long long int Int;
int main(){
	Int i, j, k, n, k1,k2;
	//priority_queue<pi,vector<pi>,greater<pi> > pq;
	//pi top;
	set<Int> ss;
	cin >> n;
	while(n--){
		cin >> k1 >> k2;	// k1 is the str.length() k2 is the kind
		j = k2;
		//int *kind = new int[k2];
		Int *arra = new Int[k1]();
		//int *ord = new int[k1]; 
		Int *rank = new Int[k1]();
		Int *showed = new Int[k2]();
		for(i=0;i<k1;i++){
			cin >> arra[i];
		}
		for(i=0;i<k1;i++){
			//cin >> ord[i];
			//rank[ord[i]-1] = arra[i]; 
			cin >> k;
			rank[k-1] = arra[i];
			//pq.push(make_pair(ord[i],arra[i]));
			showed[arra[i]-1] = 1;
		}
		
		//top = pq.top();

		cout<<rank[0];
		ss.insert(rank[0]);
		for(i=1;i<=k1-1;i++){
			//cout<<rank[]
			if(ss.find(rank[i])==ss.end()){ //not cout prev
				cout<<" "<<rank[i];
				ss.insert(rank[i]);
			}
		}

		for(i=k2-1;i>=0;i--){
			if(showed[i]!=1){cout<<" "<<i+1;}
		}
		//ss.insert(top.second);
		//cout<<top.second;
/*
		while(!pq.empty()){
			pq.pop();
			top = pq.top();
			if(ss.find(top.second)==ss.end()){ // not showed previous
				cout<<" "<<top.second;
				ss.insert(top.second);
			}
		}
*/
		cout<<endl;
		ss.clear();
		//delete [] kind;
		delete [] arra;
		//delete [] ord;
		delete [] rank;
		delete [] showed;
	}

	return 0;
}
#include <iostream>
#include <queue>
#include <set>
using namespace std;
typedef pair<int,int> pi;

int main(){
	int i, j, k, n, k1,k2;
	priority_queue<pi,vector<pi>,greater<pi> > pq;
	pi top;
	set<int> ss;
	cin >> n;
	while(n--){
		cin >> k1 >> k2;	// k1 is the str.length() k2 is the kind
		j = k2;
		int *kind = new int[k2];
		int *arra = new int[k1];
		int *ord = new int[k1];
		int *rank = new int[k1];
		int *showed = new int[k2];
		for(i=0;i<k1;i++){
			cin >> arra[i];
		}
		for(i=0;i<k1;i++){
			cin >> ord[i];
			//rank[ord[i]-1] = arra[i]; 
			pq.push(make_pair(ord[i],arra[i]));
			showed[arra[i]-1] = 1;
		}
		for(i=k2-1;i>=0;i--){
			if(showed[i]!=1){cout<<i<<" ";}
		}
		top = pq.top();
		ss.insert(top.second);
		cout<<top.second;

		while(!pq.empty()){
			pq.pop();
			top = pq.top();
			if(ss.find(top.second)==ss.end()){ // not showed previous
				cout<<top.second<<" ";
			}
		}
		cout<<endl;
/*
		for(i=0;i<k1-1;i++){
			if(arra[i] != arra[i+1]){	
				if(ord[i]>ord[i+1]){

				}
				
			}
		}
*/

		delete [] kind;
		delete [] arra;
		delete [] ord;
		delete [] rank;
		delete [] showed;
	}





}
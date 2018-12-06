#include <iostream>
#include <vector>
#include <bits/stdc++.h> 
#include <algorithm>
#include <queue>
#include <set>
using namespace std;

//void print_pq(priority_queue<pair<int,int> > * pp){
//	cout<<(*pp).size()<<endl;
//}
/*class vertex(){
	public:
		vector<vertex> *neibor ;
		int distance;
		int num;// 1 black 
};

vertex* Extract_min(int *dd,int n){
	int i, j, k;

	priority_queue< int, vector<int>,greater<int> >mp;
	for(i=0;i<n-1;i++){
		mp.push(dd[i]);
	}

	return 

}

int mp[]{

}
*/
int main(){
	int i, j, k,n, m1, m2,max = 0, count;
	cin >> n >> m1;
	m2 = m1;
	int *dist = new int [n+1];// store distance from 1 to others
	vector<vector<int> > neib(n+1); 	// every node's neighbor
	vector<int>::iterator it;
	priority_queue<pair<int, int> > pq; // (distance,k)
	pair<int, int> top;
	set<int> ss; //	ss represent the finish teddy bear
	//int *check = new int[n+1];
	
	int **w = new int *[n+1];
	for(i=0;i<=n;i++){
		w[i]=new int [n+1];
	}
	while(m2--){
		cin >> i >> j >> k;
		w[i][j] = k;
		//i--;j--;
		//scin >> w[i][j];
		w[j][i]=w[i][j];
		// neighborhood
		neib[i].push_back(j);
		neib[j].push_back(i);
	}
	//vertex* = Extract_min(dist,n);
	count = 0;
	pq.push(make_pair(0,1));
	//check[1]=1;
	ss.insert(1); // insert the first teddy bear 1
	while(count < n){
		//k = Extract_min(count++);
		top = pq.top();
		k = top.second;
		for(it = neib[k].begin();it!=neib[k].end();it++){
			if(dist[*it]<=0){
				dist[*it] = dist[k]+w[k][*it];
				pq.push(make_pair(dist[*it],*it));
			//	cout<<"imhere"<<endl;
			}
			else if(dist[*it]>dist[k]+w[k][*it]){
				dist[*it] = dist[k]+w[k][*it];
				//update_mh(*it);
				pq.push(make_pair(dist[*it],*it));
			//	cout<<"here"<<endl;
			}
		}
		int cc = 0;
		while(cc<ss.size()){
			pq.pop();
			//cout<<pq.size()<<endl;
			top = pq.top();	// min element
			cc++;
		}
		//check[top.second] = 1;
		count++;
	}
	for(i=0;i<=n;i++){
		max = (dist[i] > max)? dist[i]:max;
	}
	cout<< max <<endl;
	return 0;
}
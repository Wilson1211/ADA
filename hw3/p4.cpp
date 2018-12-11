#include <iostream>
#include <queue>
#include <string>
#include <cstdlib>
using namespace std;
typedef long int Int;
void gcd(Int*,Int*);

class edge {
	public:
		Int cost;
		Int node[2];
		//edge(){cost = 0;node[0] = 0;node[1] = 0;}
		~edge(){};
};


class CompareDist
{
	public:
    	bool operator()(pair<Int,edge> n1,pair<int,edge> n2) {
        return n1.first>n2.first;
    }
};
typedef pair<Int,edge> pi;

int main(){
	Int i, j , k, n, m, sumcost=0;
	string inp;
	char inp_ch;
	priority_queue<pi, vector<pi>, CompareDist > pq; // (edge cost, edge)


	cin >> n;
	int **mat = new int *[n+1]();// n digits has n+1 cut, thus n+1 node
	int *nodeblack = new int[n+1]();
	edge tmp;
	//edge *tmp2;
	//vector<edge*> ee;
	pair<int, edge> top;
/*
	i = n*(n+1);
	m = i/2;
	while(m != i){
		cin >> k;
		m--;
	}
	*/

	cin.ignore();
	k = n;
	while(k--){
		getline(cin, inp);
	}
	cout<<"next\n";
	//k=n;
	//while(k--)
	for(i=0;i<n;i++){
		getline(cin, inp);
		mat[i] = new int[n];
		for(j=0;j<inp.size();j++){
			if(inp[j] != ' '){
				inp_ch = inp[j];
				mat[i][i+1+(j)/2] = atoi(inp_ch);//atoi(inp_ch.c_str());
				//cout<<inp_ch<<" "<<mat[i][(j+1)/2]<<" "<<(j+1)/2<<endl;
				edge *e = new edge;
				//ee.push_back(e);
				(*e).cost = mat[i][i+1+(j)/2];
				(*e).node[0] = i;
				(*e).node[1] = (j)/2;
				pq.push(make_pair(mat[i][i+1+(j)/2],*e));
			}
		}
	}
/*
	for(i=0;i<n;i++){
		mat[i] = new int [n+1]();
		for(j=i;j<n;j++){
			cin >> mat[i][j];
			edge *e = new edge;
			//ee.push_back(e);
			(*e).cost = mat[i][j];
			(*e).node[0] = i;
			(*e).node[1] = j;
			pq.push(make_pair(mat[i][j],*e));
		}
	}
*/
	j = 0;// represent count;
	while(j!=n+1){
		top = pq.top();
		tmp = top.second; // edge
		//*tmp2 = top.second;
		if(nodeblack[(tmp.node)[0]-1] == 0 || nodeblack[(tmp.node)[1]-1] == 0){
			nodeblack[(tmp.node)[0]-1] = 1;
			nodeblack[(tmp.node)[1]-1] = 1;
			sumcost+=tmp.cost;
			cout<<tmp.cost<<" "<< (tmp.node)[0] <<" "<<(tmp.node)[1]<<endl ;
			j++;
		}
		pq.pop();
		//cout<<j;
		//delete top.second;
		//delete tmp2;
	}
	while(!pq.empty()){
		pq.pop();
	}

	//vector<edge*>::iterator it = ee.begin();
	//for(;it!=ee.end();it++){
	//	delete *it;
	//}
	gcd (&n,&sumcost);
	return 0;
}


void gcd (Int *n,Int *sumcost){
	cout<<*n <<" "<<*sumcost<<endl;
	Int a = *sumcost, b = *n;
	Int remain, quotient;
	quotient = a/b;
	remain = a - b * quotient;
	while(remain != 0){
		a = remain;
		b = a^b;
		a = b^a;
		b = b^a;
		quotient = a/b;
		remain = a - b*quotient;
	}
	// b is now the gcd
	cout<< (*n)/b << " "<<(*sumcost)/b<<endl;
}
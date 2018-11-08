#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef double D;
typedef long double LD;
typedef long long LL;
typedef pair<int,int> PII;
typedef pair<LL,LL> PLL;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> opset;
#define SZ(X) ((int)X.size())
#define ALL(I) I.begin(), I.end()
#define PB push_back
#define F first
#define S second
#define MP make_pair
#define eps 1e-12
#define MXN 1005
#define REP(i, n) for(int i = 0; i < n; i ++)
#define IOS ios_base::sync_with_stdio(0); cin.tie(0)
const int mod = (int)1e9 + 7;

inline int add(int a, int b){
	return a + b >= mod ? a + b - mod : a + b;
}
char l[MXN], r[MXN];
int dp[MXN][35][5][5][5], ans, po[MXN], c[15]; //	dp[位數][餘數][#3][#6][#9]

void init(int n){
	po[0] = 1;
	for(int i = 1; i < MXN; i ++) po[i] = po[i - 1] * 10 % 33;
	dp[0][0][0][0][0] = 1;
	for(int i = 1; i <= n; i ++){
		for(int j = 0; j < 10; j ++){
			REP(k, 33) REP(c3, 3) REP(c6, 3) REP(c9, 3){
				int id = (k + j * po[i - 1]) % 33;
				int &now = dp[i][id][c3][c6][c9];
				if(j == 3) now = add(now, dp[i - 1][k][(c3 + 2) % 3][c6][c9]);
				else if(j == 6) now = add(now, dp[i - 1][k][c3][(c6 + 2) % 3][c9]);
				else if(j == 9) now = add(now, dp[i - 1][k][c3][c6][(c9 + 2) % 3]);
				else now = add(now, dp[i - 1][k][c3][c6][c9]);
			}
		}
	}
}
int sol(char *s, bool op){
	int res = 0, pre = 0;
	c[3] = c[6] = c[9] = 0;
	int n = strlen(s);
	for(int i = 0; s[i]; i ++){
		for(int j = 0; j < s[i] - '0'; j ++){
			int rem = ((-pre - j * po[n - i - 1]) % 33 + 33) % 33;
			if(j == 3) res = add(res, dp[n - i - 1][rem][(c[3] + 2) % 3][c[6]][c[9]]);
			else if(j == 6) res = add(res, dp[n - i - 1][rem][c[3]][(c[6] + 2) % 3][c[9]]);
			else if(j == 9) res = add(res, dp[n - i - 1][rem][c[3]][c[6]][(c[9] + 2) % 3]);
			else res = add(res, dp[n - i - 1][rem][c[3]][c[6]][c[9]]);
		}
		pre = (pre + (s[i] - '0') * po[n - i - 1]) % 33;
		c[s[i] - '0'] = (c[s[i] - '0'] + 2) % 3;
	}
	if(op) res = add(res, dp[0][pre][c[3]][c[6]][c[9]]);
	return res;
}

int main(){
	scanf("%s%s", l, r);
	init(strlen(r));
	assert(strlen(r) >= strlen(l));
	assert(!(strlen(l) == strlen(r) && strcmp(l, r) > 0));
	ans = (sol(r, 1) - sol(l, 0) + mod) % mod;
	printf("%d\n", ans);
}
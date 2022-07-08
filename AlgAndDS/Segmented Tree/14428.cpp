#include <iostream>
#include <algorithm>
#include <queue>
#include <string.h>
#include <limits.h>
#include <vector>
#include <math.h>
#include <stack>
#include <bitset>
#include <string>
typedef long long ll;
using namespace std;
int n, m;
vector<int> arr;
vector<pair<int, int> >  mintree;

void input() {
	cin >> n;
	arr.resize(n);
	mintree.resize(4 * n);
	for (int i = 0;i < n;i++) cin >> arr[i];
}

pair<int,int> mininit(int i, int S, int E) {
	if (S == E) return mintree[i] = { arr[S],S };
	else return mintree[i] = min(mininit(2 * i, S, (S + E) / 2),
		mininit(2 * i + 1, (S + E) / 2 + 1, E));
}

pair<int, int> update(int i, int S, int E, int idx, int val) {
	if (idx < S || E < idx) return mintree[i];
	if (S == E) return mintree[i] = { val,mintree[i].second };
	return mintree[i]=min(update(2 * i, S, (S + E) / 2, idx, val)
		,update(2 * i + 1, (S + E) / 2 + 1, E, idx, val));

}
pair<int, int> minquery(int i, int S, int E, int L, int R) {
	if (E < L || R < S) return { INT_MAX,0 };
	if (L <= S && E <= R) return mintree[i];
	return min(minquery(2 * i, S, (S + E) / 2, L, R)
		, minquery(2 * i + 1, (S + E) / 2 + 1, E, L, R));
}

void output() {
	cin >> m;
	int a, b, c;
	for (int i = 0;i < m;i++) {
		cin >> a >> b >> c;
		if (a == 1) {
			update(1, 0, n - 1, b - 1, c);
			arr[b - 1] = c;
		}
		else cout << minquery(1, 0, n - 1, b - 1, c - 1).second+1 << '\n';
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	input();
	mininit(1, 0, n - 1);
	output();
	return 0;
}
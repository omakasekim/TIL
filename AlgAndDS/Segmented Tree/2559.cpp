#include <iostream>
#include <algorithm>
using namespace std;
int n,k,tmp,ret = -1e9;

int psum[100001]; 

int main() {
	
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> tmp;
		psum[i] = psum[i - 1] + tmp;
	}
	for (int i = k; i <= n; i++) {
		ret = max(ret, psum[i] - psum[i - k]);
	}
	
	cout << ret;
}


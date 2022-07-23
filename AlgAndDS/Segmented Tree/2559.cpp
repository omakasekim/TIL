#include <iostream>
#include <algorithm>
using namespace std;
int n,k,tmp,ret = -1e9;
int psum[100001]; 
int max(int a, int b){
	if(a>b){
		return a;
	}else{
		return b;
	}
}
int main() {
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


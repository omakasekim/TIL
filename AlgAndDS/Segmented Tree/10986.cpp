#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;
int N, M, x;
long long cnt[1001];
long long sum, ans;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    cout.tie(NULL);
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		cin >> x;
		sum += x;
		cnt[sum % M]++;
	}
	for (int i = 0; i <= 1000; i++)
	{
		ans += cnt[i] * (cnt[i] - 1) / 2;
	}
	cout << cnt[0] + ans;
}

/*

5 3
1 2 3 1 2

Index              1 2 3 4 5
Value              1 2 3 1 2
prefixSum          1 3 6 7 9
prefixSum % Mod    1 0 0 1 0


1 2 3 1 2
 
(0) 9 3 6 1 2 3 1 2 
0   1 2 3 4 5 6 7 8 
(0~2), (0~3), (0~5)

(2~3), (2~5), (3~5)
(1~4)
(B mod N - A mod N) mod N  (holds iff)  B mod N = A mod N holds.
*/
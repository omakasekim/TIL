// Given an array A of size N, you are given an assignment that computes at most M times.

//? given a range l,r (where l <= r), calcualte A[l] + A[l+1]+...+A[r]

// This can be solved with Source 1, by adding all entries.

/* Source1.cpp

int ans = 0;
for (int i=l; i<=r; i++) {
    ans += a[i];
}

*/

//The time complexity of Source 1 is O(N), where the assignment computes at most M times, so total
//time complexity amounts to O(NM)

//? Prefix Sum
//The idea of prefix sum presupposes that array A does not change. Since the values dont change, neither does the partial sum. 
//Thus, we find the accumulated sum as we traverse the array.

//Define S[i] as A[0]+...+A[i], S[0] = 0
//the sum from range l to r can be represented as S[r] - S[r-1]

//the Partial Sum can be calculated with one subtraction operation, thus has the time complexity of O(1).
//We compute at most M times, so final time complexity becomes O(M).


/*Source2.cpp

for (int i=1; i<=n; i++) {
    s[i] = s[i-1] + a[i];
}

*/

//try solving 11659.

/*Ans
#include <iostream>
#include <vector>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<int> a(n+1);
    vector<int> s(n+1);
    for (int i=1; i<=n; i++) {
        cin >> a[i];
        s[i] = s[i-1] + a[i];
    }
    while (m--) {
        int x, y;
        cin >> x >> y;
        cout << s[y] - s[x-1] << '\n';
    }
    return 0;
}
*/
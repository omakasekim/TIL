/*
문제
황선자씨는 우주신과 교감을 할수 있는 채널러 이다. 하지만 우주신은 하나만 있는 것이 아니기때문에 황선자 씨는 매번 여럿의 우주신과 교감하느라 힘이 든다. 이러던 와중에 새로운 우주신들이 황선자씨를 이용하게 되었다.

하지만 위대한 우주신들은 바로 황선자씨와 연결될 필요가 없다. 이미 황선자씨와 혹은 이미 우주신끼리 교감할 수 있는 우주신들이 있기 때문에 새로운 우주신들은 그 우주신들을 거쳐서 황선자 씨와 교감을 할 수 있다.

우주신들과의 교감은 우주신들과 황선자씨 혹은 우주신들 끼리 이어진 정신적인 통로를 통해 이루어 진다. 하지만 우주신들과 교감하는 것은 힘든 일이기 때문에 황선자씨는 이런 통로들이 긴 것을  좋아하지 않는다. 왜냐하면 통로들이 길 수록 더 힘이 들기 때문이다.

또한 우리들은 3차원 좌표계로 나타낼 수 있는 세상에 살고 있지만 우주신들과 황선자씨는 2차원 좌표계로 나타낼 수 있는 세상에 살고 있다. 통로들의 길이는 2차원 좌표계상의 거리와 같다.

이미 황선자씨와 연결된, 혹은 우주신들과 연결된 통로들이 존재한다. 우리는 황선자 씨를 도와 아직 연결이 되지 않은 우주신들을 연결해 드려야 한다. 새로 만들어야 할 정신적인 통로의 길이들이 합이 최소가 되게 통로를 만들어 “빵상”을 외칠수 있게 도와주자.


*/

/*
입력
첫째 줄에 우주신들의 개수(N<=1,000) 이미 연결된 신들과의 통로의 개수(M<=1,000)가 주어진다.

두 번째 줄부터 N개의 줄에는 황선자를 포함하여 우주신들의 좌표가 (0<= X<=1,000,000), (0<=Y<=1,000,000)가 주어진다. 그 밑으로 M개의 줄에는 이미 연결된 통로가 주어진다. 번호는 위의 입력받은 좌표들의 순서라고 생각하면 된다. 좌표는 정수이다.

*/

/*
출력
첫째 줄에 만들어야 할 최소의 통로 길이를 출력하라. 출력은 소수점 둘째짜리까지 출력하여라.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
int N, M;

vector<pair<int, int>> V;
vector<int> parents;
vector<pair<double, pair<int, int>>> E;


inline double getDist(int a, int b) {
    return sqrt(powl(V[a].first - V[b].first, 2) + powl(V[a].second - V[b].second, 2));
}

int findParent(int x) {
    if(x == parents[x]) return x;
    return parents[x] = findParent(parents[x]);
}

bool unionParent(int a, int b) {
    a = findParent(a);
    b = findParent(b);
    if(a == b) return false;
    else if(a > b) parents[a] = b;
    else parents[b] = a;
    return true;
}

int main() {
    cin >> N >> M;

    int cnt = 0;
    double sum = 0.0;

    V.assign(N + 1, pair<int, int>());
    parents.assign(N + 1, 0);

    for(int i = 0; i<=N; i++) 
        parents[i] = i;

    for(int i=1; i<=N; i++)
        cin >> V[i].first >> V[i].second;
        
    
    for(int i=1; i<N; i++) {
        for(int j = i+1; j <= N; j++) {
            E.push_back({getDist(i, j), {i, j}});
        }
    }

    sort(E.begin(), E.end());

    int a, b;
    for(int i = 0; i<M; i++) {
        cin >> a >> b;
        if(unionParent(a, b)) {
            cnt++;
        }
    }

    for(int i = 0; i < E.size() && cnt != N-1; i++) {
        if(unionParent(E[i].second.first, E[i].second.second)) {
            cnt++;
            sum += E[i].first;
        }
    }

    cout << fixed;
    cout.precision(2);
    cout << sum;

    return 0;
}
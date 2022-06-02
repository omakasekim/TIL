/*
문제

때는 2040년, 이민혁은 우주에 자신만의 왕국을 만들었다. 왕국은 N개의 행성으로 이루어져 있다. 민혁이는 이 행성을 효율적으로 지배하기 위해서 행성을 연결하는 터널을 만들려고 한다.

행성은 3차원 좌표위의 한 점으로 생각하면 된다. 두 행성 A(xA, yA, zA)와 B(xB, yB, zB)를 터널로 연결할 때 드는 비용은 min(|xA-xB|, |yA-yB|, |zA-zB|)이다.

민혁이는 터널을 총 N-1개 건설해서 모든 행성이 서로 연결되게 하려고 한다. 이때, 모든 행성을 터널로 연결하는데 필요한 최소 비용을 구하는 프로그램을 작성하시오.
*/

/*
입력
첫째 줄에 행성의 개수 N이 주어진다. (1 ≤ N ≤ 100,000) 다음 N개 줄에는 각 행성의 x, y, z좌표가 주어진다. 좌표는 -109보다 크거나 같고, 109보다 작거나 같은 정수이다. 한 위치에 행성이 두 개 이상 있는 경우는 없다. 
*/

/*
출력
첫째 줄에 모든 행성을 터널로 연결하는데 필요한 최소 비용을 출력한다.
*/

#include<iostream>
#include<algorithm>
#include<vector>
#include<tuple>
using namespace std;

int N, x, y, z;
int parent[100001];
int rs;
vector<pair<int, int>> X;
vector<pair<int, int>> Y;
vector<pair<int, int>> Z;
vector<tuple<int, int, int>> planet;

int find(int u)
{
	if (parent[u] == u) return u;
	else return parent[u] = find(parent[u]);
}

bool union_node(int u, int v)
{
	u = find(u);
	v = find(v);

	if (u == v) return false;
	else
	{
		parent[u] = v;
		return true;
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;

	for (int i = 0; i < N; i++)
		parent[i] = i;

	// 행성 좌표 입력받기
	for (int i = 0; i < N; i++)
	{
		cin >> x >> y >> z;
		X.push_back({ x,i });
		Y.push_back({ y,i });
		Z.push_back({ z,i });
	}

	sort(X.begin(), X.end());
	sort(Y.begin(), Y.end());
	sort(Z.begin(), Z.end());

	for (int i = 0; i < N-1; i++)
	{
		planet.push_back({ X[i + 1].first - X[i].first,X[i].second,X[i + 1].second });
		planet.push_back({ Y[i + 1].first - Y[i].first,Y[i].second,Y[i + 1].second });
		planet.push_back({ Z[i + 1].first - Z[i].first,Z[i].second,Z[i + 1].second });
	}

	sort(planet.begin(), planet.end());

	for (int i = 0; i < planet.size(); i++)
	{
		int d = get<0>(planet[i]);
		int u = get<1>(planet[i]);
		int v = get<2>(planet[i]);
		
		if (union_node(u, v)) rs += d;
	}

	cout << rs;
}

/*

풀이 방법
planet<tuple<int, int, int>> : { 거리, 행성1, 행성2 } 저장하는 벡터

크루스칼 알고리즘은 모든 간선에 대해서 가중치가 작은 간선들부터 연결해주되 중간중간에 사이클이 생기게 된다면 건너뛰고 다음 간선을 연결하여 최소 스패닝 트리를 만들어가는 알고리즘입니다.

그러나 이 문제에서는 행성의 개수가 10만개 이므로 각각의 행성들의 거리를 벡터에 담으면 10만*10만으로 메모리 초과가 발생할 수 있습니다. 따라서 각각의 행성 X, Y, Z좌표의 차이들을 planet 벡터에 푸쉬하고 유니온 파인드를 하여 스패닝 트리를 찾을 수 있습니다.
*/

/*
문제
도현이는 우주의 신이다. 이제 도현이는 아무렇게나 널브러져 있는 n개의 별들을 이어서 별자리를 하나 만들 것이다. 별자리의 조건은 다음과 같다.

별자리를 이루는 선은 서로 다른 두 별을 일직선으로 이은 형태이다.
모든 별들은 별자리 위의 선을 통해 서로 직/간접적으로 이어져 있어야 한다.
별들이 2차원 평면 위에 놓여 있다. 선을 하나 이을 때마다 두 별 사이의 거리만큼의 비용이 든다고 할 때, 별자리를 만드는 최소 비용을 구하시오.
*/

/*
입력
첫째 줄에 별의 개수 n이 주어진다. (1 ≤ n ≤ 100)

둘째 줄부터 n개의 줄에 걸쳐 각 별의 x, y좌표가 실수 형태로 주어지며, 최대 소수점 둘째자리까지 주어진다. 좌표는 1000을 넘지 않는 양의 실수이다.
*/

/*
출력
첫째 줄에 정답을 출력한다. 절대/상대 오차는 10-2까지 허용한다.
*/

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
 
int N; // Number of stars
double x, y; //container for coordinates
int par[101]; //parent table
vector<pair<double, double>> stars; //x&y coordinates
vector<pair<double, pair<int, int>>> v; // cost (of),ith, jth star
double rs = 0; //result of MST
 
//recursive function to find parent 
int find(int x){
    if(par[x] == x)
        return x;
    return par[x] = find(par[x]);
}
 
double calcDist(double x1, double y1, double x2, double y2)
{
    return sqrt(pow(x2-x1, 2) + pow(y2-y1, 2));
}
 
 double Haversine(double x1, double y1, double x2, double y2){
    double distance;
    double radius = 6371; // 지구 반지름(km)
    double toRadian = M_PI / 180;
 
    double deltaLatitude = abs(x1 - x2) * toRadian;
    double deltaLongitude = abs(y1 - y2) * toRadian;

    double sinDeltaLat = sin(deltaLatitude / 2);
    double sinDeltaLng = sin(deltaLongitude / 2);
    double squareRoot = sqrt(
        sinDeltaLat * sinDeltaLat +
        cos(x1 * toRadian) * cos(x2 * toRadian) * sinDeltaLng * sinDeltaLng);

    distance = 2 * radius * asin(squareRoot);

    return distance;
}
 

int main()
{   
    cin >> N;
    for(int i=0; i<N; i++){
        cin>>x>>y;
        stars.push_back(make_pair(x, y));
    }
 
    // Calculate distance between two stars (calculating weight of edge)
    for(int i=0; i<stars.size(); i++){
        for(int j=i+1; j<stars.size(); j++){
            double cost = calcDist(stars[i].first, stars[i].second, stars[j].first, stars[j].second);
            v.push_back(make_pair(cost, make_pair(i, j)));
        }
    }
    //reset connect array so that ith element points to itslef (by default it is its own parent)
    for(int i=0; i<N; i++)
        par[i] = i;
    //sort weight of edges
    sort(v.begin(), v.end());
 
    for(int i=0; i<v.size(); i++){
        int x = v[i].second.first;
        int y = v[i].second.second;
        double cost = v[i].first;
 
        //find root parent of each x,y
        int a = find(x);
        int b = find(y);
        //if ancestors are different == not connected, connect them and add weight to result
        if(a!=b){
            par[a] = b;
            rs += cost;
        }
    }
 
    cout.precision(3);
    cout<<rs<<"\n";
    return 0;
}
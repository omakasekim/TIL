//? 세그먼트 트리란?

/*
여러 개의 데이터가 연속적으로 존재할 때  특정한 범위의 데이터의 합을 구하는 방법

보통은 N개의 데이터에 대해 N보다 크고 가장 가까운 제곱수에 2를 곱한 갯수만큼 만들지만,
4를 곱해도 모든 범위를 커버할 수 있다 .

*/

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
long long *tree;
long long arr[1000001];

long long init(int node, int start, int end){
    if(start == end) return tree[node] = arr[start];
    int mid = (start+end)/2;

    return tree[node] = init(2*node, start, mid) + init(2*node+1, mid+1, end);
}

long long sum(int node, int start, int end, int left, int right){
    if(left > end || right < start) return 0;
    if(left <= start && end<=right) return tree[node];

    int mid = (start+end)/2;
    return sum(node*2, start, mid, left, right) + sum(node*2+1, mid+1, end, left, right);
}

void update(int node, int start, int end, int idx, long long diff){
    if(idx < start || idx > end) return;
    tree[node] += diff;

    if(start == end) return;
    int mid = (start+end)/2;

    update(node*2,start, mid, idx, diff);
    update(node*2+1,mid+1,end,idx,diff);
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int num, m, k, a, b;
    long long c;
    cin>>num>>m>>k;
    int height = ceil(log2(num));
    tree = new long long[1<<(height+1)];

    for(int i = 0; i < num; i++)
        cin>>arr[i];
    
    init(1,0,num-1);

    for(int i = 0; i < m+k; i++){
        cin>>a>>b>>c;
        if(a == 1){ //b->c 로 변환
            long long diff = c-arr[b-1];
            arr[b-1] = c;
            update(1,0,num-1,b-1,diff);
        }
        else if(a==2)// b~c 합
            cout << sum(1,0,num-1,b-1,c-1)<<'\n';
    }
    return 0;
}
//https://blog.naver.com/PostView.naver?blogId=ndb796&logNo=221282210534&redirect=Dlog&widgetTypeCall=true&directAccess=false
#include <iostream>
#include <vector>
#include <cmath>
#include <cstdio>
#define MOD 1000000007
using namespace std;
vector<int> v;
vector<long long> tree;
long long init(int node,int start,int end){
    if(start == end){
        return tree[node] = v[start];
    }
    else{
    return tree[node] = init(node*2,start,(start+end)/2)*init(node*2+1,(start+end)/2+1,end)%1000000007;
    }
}
long long update(int node,int start,int end,int idx,int num){
    if(idx>end || idx<start){return tree[node];}
    if(start == end){return tree[node] = num;}
    return tree[node] = update(node*2,start,(start+end)/2,idx,num)*update(node*2+1,(start+end)/2+1,end,idx,num)%1000000007;
}
long long sum(int node,int start,int end,int left,int right){
    if(left>end || right<start){return 1;}
    if(left<=start && right>=end){
        return tree[node];
    }
    else{
    return sum(node*2,start,(start+end)/2,left,right)*sum(node*2+1,(start+end)/2+1,end,left,right)%1000000007;
    }
}
int main(void){
    int N,M,K;
    scanf("%d%d%d",&N,&M,&K);
    v.resize(N);
    int h = (int)ceil(log2(N));
    int vector_size = (1<<(h+1));
    tree.resize(vector_size);
    for(int i = 0;i<N;i++){
        scanf("%d",&v[i]);
    }
    init(1,0,N-1);
    for(int i =0;i<M+K;i++){
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        if(a == 1){
            update(1,0,N-1,b-1,c);
        }
        else if(a == 2){
            cout << sum(1,0,N-1,b-1,c-1)<<"\n";
        }
    }
}
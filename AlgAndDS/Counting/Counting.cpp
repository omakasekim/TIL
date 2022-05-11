#include <stdio.h>
#include <stdlib.h>

int main(void){
	int N,M,K;
	scanf("%d %d %d", &N, &M, &K);

	int A[N];
	int B[M];
	int query[K][2];
	
	for(int i = 0; i < N; i++) A[i] = 0;
	for(int i = 0; i < M; i++) B[i] = 0;
	for(int i = 0; i < K; i++) query[i][0] = 0;
	for(int i = 0; i < K; i++) query[i][1] = 0;
	
	
	int L,R;
	for(int i = 0; i<K; i++){
		scanf("%d %d",&L,&R);
		query[i][0] = L;
		query[i][1] = R;
	}	
	int val;
	for(int i =0; i<N;i++){
	scanf("%d", &val);
	A[i] = val;
	B[val-1]++;
	}
	int count;
	
	for(int i =0;i<K;i++){
	count = 0;
	if(query[i][0]<query[i][1]){
	
	for(int j = query[i][0]; j<=query[i][1];j++){
		count += B[j-1];
	}
}
	if(query[i][0]>query[i][1]){
	for(int j = query[i][1]; j<=query[i][0];j++){
		count += B[j-1];
	}
}
	printf("%d\n", count);
	}
}

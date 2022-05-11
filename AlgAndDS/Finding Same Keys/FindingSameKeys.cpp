#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
int N,M;
scanf("%d %d",&N,&M);
int A[N];
int B[M];


for(int i = 0; i<N; i++)scanf("%d",&A[i]);
for(int j = 0; j<M; j++)scanf("%d",&B[j]);
int cnt = 0;
for(int idx =0;idx<N;idx++){
for(int jdx =0;jdx<M;jdx++){
	if(A[idx]==B[jdx])cnt++;
}
}
printf("%d\n",cnt);


return 0;
}

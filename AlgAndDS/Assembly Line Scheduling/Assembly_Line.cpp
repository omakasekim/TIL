#include <stdio.h>
#include <stdlib.h>
#include <bits/stdc++.h>

using namespace std;

int min(int x, int y)
{
	return x < y ? x : y;
}

int compare(int j, int k)
{
	return j < k ? 1 : 2;
}

int AssemblyLine(int** a, int** t, int *e, int *x, int N, int** retrace)
{
	int T1[N], T2[N], idx;
	
	T1[0] = e[0] + a[0][0];
	T2[0] = e[1] + a[1][0];
	retrace[0][0] = 1;
	retrace[1][0] = 2;

	
	for(idx = 1; idx < N; idx++)
	{
		if(T1[idx-1] + a[0][idx] <= T2[idx-1] + t[1][idx-1] + a[0][idx]){
			T1[idx] = T1[idx-1] + a[0][idx];
			retrace[0][idx] = 1;
		}else{
			T1[idx] = T2[idx-1] + t[1][idx-1] + a[0][idx];
			retrace[0][idx] = 2;
		}
		if(T2[idx-1] + a[1][idx] <= T1[idx-1] + t[0][idx-1] + a[1][idx]){
			T2[idx] = T2[idx-1] + a[1][idx];
			retrace[1][idx] = 2;
		}else{
			T2[idx] = T1[idx-1] + t[0][idx-1] + a[1][idx];
			retrace[1][idx] = 1;
		}

		//T1[idx] = min(T1[idx-1] + a[0][idx], T2[idx-1] + t[1][idx-1] + a[0][idx]);
		//T2[idx] = min(T2[idx-1] + a[1][idx], T1[idx-1] + t[0][idx-1] + a[1][idx]);
		//printf(" T1idx = %d and T2idx = %d ", T1[idx], T2[idx]);
		//retrace[idx] = compare(T1[idx],T2[idx]);
	}	
	//return min(T1[N-1] + x[0], T2[N-1] + x[1]);
	int finalline;
	if(T1[N-1] + x[0] <= T2[N-1] + x[1]){
		printf("%d\n",T1[N-1] + x[0]);
		finalline = 0;
		//retrace[0][N-1] = 1;
		//retrace[1][N-1] = 1;
	}else{
		printf("%d\n",T2[N-1] + x[1]);
		finalline = 1;
		//retrace[0][N-1] = 2;
		//retrace[1][N-1] = 2;
	}

	int result[N];
	result[N-1] = finalline+1;
	for(int j = N-2;j>=0;j--){
		result[j] = retrace[finalline][j+1];
		finalline = result[j]-1;
	}
	for(int i = 0; i < N; i++)
		printf("%d %d\n", result[i], i+1);
		

}

int main()
{
	int N;
	scanf("%d", &N);
	
	
	int* e = (int*)malloc(sizeof(int)*2);
	int* x = (int*)malloc(sizeof(int)*2);
	
	for(int i = 0; i < 2; i++)
		scanf("%d", &e[i]);
	for(int i = 0; i < 2; i++)
		scanf("%d", &x[i]);
		
	int** a = (int**)malloc(2*sizeof(int*)*N);
	a[0] = (int*)malloc(sizeof(int)*N);
	a[1] = (int*)malloc(sizeof(int)*N);

	for(int i = 0; i < N; i++)
		scanf("%d", &a[0][i]);
	for(int i = 0; i < N; i++)
		scanf("%d", &a[1][i]);

	int** t = (int**)malloc(2*sizeof(int*)*N);
	t[0] = (int*)malloc(sizeof(int)*N);
	t[1] = (int*)malloc(sizeof(int)*N);

	for(int i = 0; i < N-1; i++)
		scanf("%d", &t[0][i]);
	for(int i = 0; i < N-1; i++)
		scanf("%d", &t[1][i]);

	int** retrace = (int**)malloc(2*sizeof(int*)*N);
	retrace[0] = (int*)malloc(sizeof(int)*N);
	retrace[1] = (int*)malloc(sizeof(int)*N);

    AssemblyLine(a,t,e,x,N,retrace);
}

#include <stdio.h>

void heapify(int arr[], int n, int i)
{
    int root = i;
    int l = 2*i+1;
    int r = 2*i+2;

    if(l < n && arr[l] < arr[root])
        root = l;
    if(r < n && arr[r] < arr[root])
        root = r;

    if(root != i)
    {
        int temp = arr[i];
        arr[i]=arr[root];
        arr[root] = temp;
        heapify(arr,n,root);
    }
}

void heapSort(int arr[], int n) 
{ 
    for (int i = n / 2 - 1; i >= 0; i--) 
        heapify(arr, n, i); 
  
    for (int i = n - 1; i >= 0; i--) { 

        int temp2 = arr[0];
        arr[0] = arr[i];
        arr[i] = temp2;
        heapify(arr, i, 0); 
    } 
} 

int main(){

    int N,K;
    scanf("%d %d",&N,&K);
    int arr[N];
    for(int i =0;i<N;i++)
        scanf("%d",&arr[i]);

    heapSort(arr,N);

    for(int i=0;i<N;++i)
        {
    	printf("%d ",arr[i]);
	    if(i==(K-1))printf("\n");
        }

    return 0;
}

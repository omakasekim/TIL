#include <stdio.h> 
#include <math.h> 
  
void Insertion(int arr[], int N) 
{ 
    int i, key, j;
    
    for (i = 1; i < N; i++) { 
        key = arr[i]; 
        j = i - 1; 
  
        while (j >= 0 && arr[j] < key) { 
            arr[j + 1] = arr[j]; 
            j = j - 1; 
        } 
        arr[j + 1] = key; 
    } 
    
    int idx; 
    for (idx = 0; idx < N; idx++) 
        printf("%d\n", arr[idx]); 
} 



int main() 
{ 
    int N;
    scanf("%d",&N);
    int arr[N];
    for(int cnt=0;cnt<N;cnt++){
        scanf("%d",&arr[cnt]);
    }
    Insertion(arr,N); 
    return 0; 
} 

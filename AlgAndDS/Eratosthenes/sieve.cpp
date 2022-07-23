#include <stdio.h>
int min(int a, int b){
   return a < b ? a : b; 
}
int a, b, sm, mn = 1e9;
int main() {
	scanf("%d %d", &a, &b);
	for (int i = 1; i*i <= b; i++) {
		if (i*i >= a && i*i <= b) {
			mn = min(mn, i*i);
			sm += i*i;
		}
	}
    if (!sm) printf("-1");
    else printf("%d\n%d", sm, mn);
	return 0;
}
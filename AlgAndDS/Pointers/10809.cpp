#pragma warning(disable : 4996)
#include <stdio.h>
#include <string.h>
#include <cstring>
/* BOJ 10809 */

int main()
{
    char str[100];
    int len;
    char ch = 'a';
    scanf("%s", str);
    len = strlen(str);
    char *p;
    int cnt = 0;
    p = str;
    for (ch = 'a'; ch <= 'z'; ch++)
    {
        cnt = 0;
        for (p = str; p < str + len; p++)
        {

            if (*p == ch)
            {
                printf("%d ", p - str);
                cnt++;
                break;
            }
        }
        if (cnt == 0)
            printf("-1 ");
    }
    return 0;
}


//Q1
#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
/* 문자열 1번 포인터로 풀어보기*/
int main() {
    char s1[30]=" ";
    char s2[30]=" ";
    int len1=0, len2 = 0;
    int max_len = 0;
    int* p=NULL;
    char* ps1, * ps2;
 
    scanf("%s", s1);
    scanf("%s", s2);
     len1 = strlen(s1);
    len2 = strlen(s2);
    
    if (len1 > len2) max_len = len1;
    else max_len = len2;
 
    ps1 = s1;
    ps2 = s2;
    int i = 0;
 
    for (i=0; i < max_len; i++) {
 
        if (*(ps1+i) == *(ps2+i)) printf("O");
        else printf("X");
    }
        return 0;
 
}

//Q2
#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
/* 문자열 2번 함수로 구현하기*/
void changestr(char* p, int len);
int main() {
    char s[30]="";
    int N;
    int len;
    scanf("%s", s);
    scanf("%d", &N);
    len = strlen(s);
    for (int i = 0; i < N; i++) {
        changestr(s, len);
    }
    printf("%s", s);
        return 0;
 
}
//simpson ==> changestr ==> impsons
void changestr(char * p,int len)
{
 
    for (int i = 0; i < len-1; i++) {
 
        char temp = *p;
        *p = *(p + 1);
        * (p + 1)=temp;
        p++;
    }
    
}


//FINAL Q2
#pragma warning(disable:4996)
#include <stdio.h>
void addArray(int* a, int* b, int* c, int n);
int main() {
    int N;
    int Num[3];
    int Num2[3];
    int sum_Num[3] = { 0 };
    int* a, * b, * c,*p1;
    scanf("%d", &N);
    for (a = Num; a < Num + N; a++) {
        scanf("%d", a);
    }
    for (b = Num2; b < Num2 + N; b++) {
        scanf("%d", b);
    }
    c = sum_Num;
    addArray(Num, Num2, sum_Num,N);
 
    for (p1=c;p1<c+N;p1++){
        printf("%d ",*p1);
    }
    return 0;
}

void addArray(int* a, int* b, int* c, int n)
{
    int* p;
 
    for (p = c; p < c + n; p++) {
 
        *p = *a + *(b+n-1);
        a++;
        b--;
 
    }
} 
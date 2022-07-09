    #include <stdio.h>

    int main()
    {
        int N;
        scanf("%d", &N);

        int Q,R;

        int T = N;
        int cnt = 0;
            R = T%26;
            int real = 0;
        while(T>=26){
            cnt++;
            R = T%26;
            T-=26;
        }
        while(cnt && cnt>1){
            printf("%c",'A');
            real = 1;
            cnt -= 1;
        }

        return 0;
    }
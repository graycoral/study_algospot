#include <stdio.h>
#include <stdlib.h>
#define MAXN ((int)1e5+10)

int N,M,L;

struct Q {
    int r,c,v;
};

struct Q s[MAXN*MAXN];
struct Q t[MAXN*MAXN];

void input()
{
    scanf("%d %d %d", &N, &M, &L);
    for(int i=0; i<N; i++){
        scanf("%d", &s[i].c);
        s[i].r = 0;
    }
    for(int i=0; i<M; i++){
        scanf("%d %d", &t[i].c, &t[i].r);
    }
}

int sol()
{
    int retCnt = 0;
    
    for(int i=0; i< M; i++){
        for(int j=0; j<N; j++){
            if(s[j].v == 1) continue;
            if(t[i].c > s[j].c){
                if(t[i].c - s[j].c + t[i].r  <= L) {
                    retCnt++;
                    s[j].v =1;
                    break;
                }
            } else {
                if(s[j].c - t[i].c + t[i].r  <= L) {
                    retCnt++;
                    s[j].v =1;
                    break;
                }
            } 
        }
    }

    return retCnt;
}

int main()
{
    input();
    printf("%d\n", sol());
    
    return 0;
}
//B0 : 사냥꾼(이진탐색 활용)
#include <stdio.h>
#include <stdlib.h>
#define MAXN ((int)1e5 + 10)
int M;//사대수
int N;//동물수
int L;//사정거리
int A[MAXN];//사대정보
struct DATA{
    int x, y;
} B[MAXN];
void InputData(void){
    int i;
    scanf("%d %d %d", &M, &N, &L);
    for (i = 0; i < M; i++){
        scanf("%d", &A[i]);
    }
    for (i = 0; i < N; i++){
        scanf("%d %d", &B[i].x, &B[i].y);
    }
}
int comp(const void *a, const void *b){
    return *(int*)a - *(int*)b;
}
int bslow(int s, int e, int d){//d값보다 크거나 같은 값중에 제일 작은 인덱스
    int m, sol = -1;
    while (s <= e){
        m = (s+e)/2;
        if (A[m] >= d){
            sol = m; e = m-1;
        }
        else{
            s = m+1;
        }
    }
    return sol;
}
int solve(void){
    int i, cnt = 0, low, hi, idx;
    qsort(A, M, sizeof(A[0]), comp);//사대 오름 차순 정렬
    for (i = 0; i < N; i++){//동물 기준O(N logM)
        if (B[i].y > L) continue;
        low = B[i].x + B[i].y - L;
        hi = L + B[i].x - B[i].y;
        idx = bslow(0, M-1, low);
        if ((idx >= 0) && (A[idx] <= hi)) cnt++;
    }
    return cnt;
}
int main(void){
    int ans;
    InputData();
    ans = solve();
    printf("%d\n", ans);
    return 0;
}
//B0 : 사냥꾼(그리디 적용)
#include <stdio.h>
#include <stdlib.h>
#define MAXN ((int)1e5 + 10)
int M;//사대수
int N;//동물수
int L;//사정거리
int A[MAXN];//사대정보
struct DATA{
    int x, y;
} B[MAXN];
void InputData(void){
    int i;
    scanf("%d %d %d", &M, &N, &L);
    for (i = 0; i < M; i++){
        scanf("%d", &A[i]);
    }
    for (i = 0; i < N; i++){
        scanf("%d %d", &B[i].x, &B[i].y);
    }
}
int compA(const void *a, const void *b){
    return *(int*)a - *(int*)b;
}
int compB(const void *a, const void *b){
    struct DATA *x = a, *y = b;
    return (x->x + x->y) - (y->x + y->y);
}
int ABS(int x){
    return (x < 0) ? -x : x;
}
int solve(void){
    int i = 0, j = 0, cnt = 0;
    qsort(A, M, sizeof(A[0]), compA);//사대 오름 차순 정렬
    qsort(B, N, sizeof(B[0]), compB);//동물 오름 차순 정렬
    while((i < N) && (j < M)){//O(N+M)
        if(B[i].y > L) i++;
        else if(ABS(A[j]-B[i].x) + B[i].y <= L){
            cnt++; i++;
        }
        else if(A[j] > B[i].x) i++;
        else j++;
    }
    return cnt;
}
int main(void){
    int ans;
    InputData();
    ans = solve();
    printf("%d\n", ans);
    return 0;
}


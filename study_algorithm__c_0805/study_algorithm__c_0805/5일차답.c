//C0 : 해밀턴순환회로
#include <stdio.h>
#define INF (100 * 12 + 10)
#define MAXN (12 + 10)
int N;//대회수
int cost[MAXN][MAXN];
int used[MAXN];
int sol;
void InputData(void){
    int i, j;
    scanf("%d", &N);
    for (i = 1; i <= N; i++){
        for (j = 1; j <= N; j++){
            scanf("%d", &cost[i][j]);
        }
    }
}
void DFS(int s, int n, int sum){
    int e;
    if (sol <= sum) return;
    if (n >= N){//종료조건
        if (cost[s][1] != 0){//마지막 도시에서 출발도시(1)에 갈수있어야 함
            if (sol > sum + cost[s][1]) sol = sum + cost[s][1];
        }
        return;
    }
    for (e = 2; e <= N; e++){
        if (cost[s][e] == 0) continue;//경로없음
        if (used[e] == 1) continue;
        used[e] = 1;
        DFS(e, n+1, sum+cost[s][e]);
        used[e] = 0;
    }
}
int solve(void){
    sol = INF;
    DFS(1, 1, 0);//출발도시, 들린도시수, 총비용
    return sol;
}
int main(void){
    int ans;
    InputData();
    ans = solve();
    printf("%d\n", ans);
    return 0;
}
//C1 : 거스름돈
#include <stdio.h>
int W;
int coin[]={500, 100, 50, 10};
int solve(void){
    int i, cnt = 0;
    for (i = 0; i < 4; i++){
        cnt += W / coin[i];
        W %= coin[i];
    }
    return cnt;
}
int main(void){
    int ans;
    scanf("%d", &W);
    ans = solve();
    printf("%d\n", ans);
    return 0;
}
//기출문제 : 공장운영
#include <stdio.h>
int N; //일
int S; //보관비용
int C[50010]; //가격
int Y[50010]; //용량
void Input_Data(void){
    int i;
    scanf("%d %d", &N, &S);
    for(i=0 ; i<N ; i++){
        scanf("%d %d", &C[i], &Y[i]);
    }
}
#define TEST 2
//(1:O(N^2), 2:O(N))
#if TEST == 1
long long solve(void){//O(N^2)
    long long sum = 0;
    int i, j, cost, save;
    for (i = 0; i < N; i++){
        cost = C[i];
        save = S;
        for (j = i-1; j >= 0; j--){
            if (cost > C[j]+save) cost = C[j]+save;
            save += S;
        }
        sum += Y[i] * cost;
    }
    return sum;
}
#else
long long solve(void){//O(N)
    long long sum = C[0] * Y[0];
    int i, j, cost = C[0];
    for (i = 1; i < N; i++){
        if (C[i] > cost + S) cost += S;//이전 가격이 좋은 경우(보관비 고려해야함)
        else cost = C[i];//이 번주 가격이 좋은 경우
        sum += Y[i] * cost;
    }
    return sum;
}
#endif
int main(void){
    long long ans = -1;
    Input_Data(); // 입력 함수
    ans = solve();
    printf("%lld\n", ans); // 정답 출력
    return 0;
}
//C2 : 피보나치수열
#include <stdio.h>
#define TEST 3
//(1:DFS, 2:memoization, 3:dynamic)
#if TEST == 1
int DFS(int n){//DFS
    if (n <= 2) return 1;
    return DFS(n-1) + DFS(n-2);
}
int solve(int n){
    return DFS(n);
}
#elif TEST == 2
int dp[50] = {0, 1, 1};//n번째 피보나치 수열 값
int memoi(int n){//dynamic memoization활용
    if (dp[n] == 0){
        dp[n] = memoi(n-1) + memoi(n-2);
    }
    return dp[n];
}
int solve(int n){
    return memoi(n);
}
#else
int dp[50] = {0, 1, 1};//n번째 피보나치 수열 값
int solve(int n){//dynamic 반복문활용
    int i;
    for (i = 3; i <= n; i++){
        dp[i] = dp[i-1] + dp[i-2];
    }
    return dp[n];
}
#endif // 1
int main(void){
    int N, ans;
    scanf("%d", &N);
    ans = solve(N);
    printf("%d\n", ans);
    return 0;
}
//C3 : 동전교환
#include <stdio.h>
#define INF ((int)1e5)
#define MAXN (10+2)
#define MAXW ((int)64e3 + 2)
#define TEST 4
//(1:DFS, 2:memoization, 3:dynamic(2차원배열), 4:dynamic(1차원배열))
int N;//동전 단계수
int coin[MAXN];//동전 단위
int W;//잔돈
#if TEST == 1
int sol;//최소 동전수
void DFS(int n, int w, int cnt){
    int i;
    if (sol <= cnt) return;//가지치기
    if (w == 0){//종료조건 완성
        sol = cnt;
        return;
    }
    if (n > N) return;//종료조건
    for (i = w/coin[n]; i >= 0; i--){
        DFS(n+1, w-i*coin[n], cnt+i);
    }
}
int solve(void){
    sol = INF;
    DFS(1, W, 0);//동전 인덱스, 잔돈, 필요한 동전 수
    return sol;
}
#elif TEST == 2
#define NOTSOLVED (-1)
int dp[MAXN][MAXW];//[동전단위][잔돈]
//i번째 동전을 포함해서 j잔돈을 만들때 사용되는 최소 동전 수
int memoi(int n, int w){
    int cnt;
    if (dp[n][w] == NOTSOLVED){
        dp[n][w] = memoi(n-1, w);
        if (w >= coin[n]){//n번째 동전보다 잔돈이 크거나 같아야 함
            cnt = memoi(n, w-coin[n]) + 1;
            if (dp[n][w] > cnt) dp[n][w] = cnt;
        }
    }
    return dp[n][w];
}
int solve(void){
    int i, j;
    //초기화 필요(dp배열)
    for (j = 1; j <= W; j++) dp[0][j] = INF;//동전없으면 만들수없음(불가능)
    for (i = 0; i <= N; i++) dp[i][0] = 0;//0원은 만들수있음(0개필요)
    for (i = 1; i <= N; i++){//동전 단위 인덱스
        for (j = 1; j <= W; j++){//잔돈 인덱스
            dp[i][j] = NOTSOLVED;//계산 안함으로 표시
        }
    }
    return memoi(N, W);
}
#elif TEST == 3
int dp[MAXN][MAXW];//[동전단위][잔돈]
//i번째 동전을 포함해서 j잔돈을 만들때 사용되는 최소 동전 수
int solve(void){
    int i, j;
    //초기화
    for (j = 1; j <= W; j++) dp[0][j] = INF;//동전없으면 만들수없음(불가능)
    for (i = 0; i <= N; i++) dp[i][0] = 0;//0원은 만들수있음(0개필요)
    for (i = 1; i <= N; i++){//동전 단위 인덱스
        for (j = 1; j <= W; j++){//잔돈 인덱스
            dp[i][j] = dp[i-1][j];
            if (j >= coin[i]){
                if (dp[i][j] > dp[i][j-coin[i]]+1){
                    dp[i][j] = dp[i][j-coin[i]]+1;
                }
            }
        }
    }
    return dp[N][W];
}
#else
int dp[MAXW];//[잔돈]
//i번째 동전을 포함해서 j잔돈을 만들때 사용되는 최소 동전 수
int solve(void){
    int i, j;
    //초기화
    for (j = 1; j <= W; j++) dp[j] = INF;//동전없으면 만들수없음(불가능)
    dp[0] = 0;//0원은 만들수있음(0개필요)
    for (i = 1; i <= N; i++){//동전 단위 인덱스
        for (j = coin[i]; j <= W; j++){//잔돈 인덱스
            if (dp[j] > dp[j-coin[i]]+1){
                dp[j] = dp[j-coin[i]]+1;
            }
        }
    }
    return dp[W];
}
#endif // TEST
void InputData(void){
    int i;
    scanf("%d", &N);
    for (i = 1; i <= N; i++){
        scanf("%d", &coin[i]);
    }
    scanf("%d", &W);
}
int main(void){
    int ans;
    InputData();
    ans = solve();
    if (ans == INF) printf("impossible\n");
    else printf("%d\n", ans);
    return 0;
}
int dp[N][W];//i번째 동전을 포함해서 j잔돈을 만들때 사용되는 최소 동전 수
dp[n][w] = min dp[n-1][w];//n번째 동전을 빼고 나머지 동전으로 w원을 만드는 수
dp[n-1][w-coin[n]* 1] + 1;//n번째 동전 1개 사용
dp[n-1][w-coin[n]* 2] + 2;//n번째 동전 2개 사용
dp[n-1][w-coin[n]* 3] + 3;//n번째 동전 3개 사용
...
dp[n-1][w-coin[n]* k] + k;//n번째 동전 k개 사용

dp[n-1][w] = min dp[n-2][w];//n-1번째 동전을 빼고 나머지 동전으로 w원을 만드는 수
dp[n-2][w-coin[n-1]* 1] + 1;//n-1번째 동전 1개 사용
dp[n-2][w-coin[n-1]* 2] + 2;//n-1번째 동전 2개 사용
dp[n-2][w-coin[n-1]* 3] + 3;//n-1번째 동전 3개 사용
...
dp[n-2][w-coin[n-1]* k] + k;//n-1번째 동전 k개 사용

최종 점화식
dp[n][w] = min dp[n-1][w];//n번째 동전 0개 사용
dp[n][w-coin[n]] + 1;//n번째 동전 1개더(?) 사용
//(실제로는 여러개 사용했을수도 있음)
//기출문제 : 연구원건강증진프로젝트
#include <stdio.h>
int N; // 계단의 개수
int P[310]; // P[i]: i 계단을 밟았을 때 얻는 점수
int sol; // 정답
int dp[310];//i번째 계단을 밟았을때 최대 점수
#define TEST 0
//(0:DFS, 1:memoi, 2:dynamic)
#if TEST == 0
int sol;//최고점수
void DFS(int idx, int conti, int sum){
    if (idx >= N) {
        if (sol < sum) sol = sum;
        return;
    }
    if (conti < 2) DFS(idx+1, conti+1, sum+P[idx+1]);//다음 계단 밟기(3개 연속 밟기 불가능)
    if (idx+2 <= N) DFS(idx+2, 1, sum+P[idx+2]);//다다음 계단 밟기(마지막 계단 넘어서는 것 불가능)
}
int solve(void){
    sol = 0;
    DFS(0, 0, 0);//계단인덱스, 연속개수, 총점
    return sol;
}
#elif TEST == 1
#define NOTSOLVED (-1)
int memoi(int n){
    int tmp;
    if (dp[n] == NOTSOLVED){
        dp[n] = memoi(n-2) + P[n];//전전계단 밟고 현재 계단 밟는 경우
        tmp = memoi(n-3) + P[n-1] + P[n];//전전전 계단 밟고 전계단과 현재 계단 밟는 경우
        if (dp[n] < tmp) dp[n] = tmp;
    }
    return dp[n];
}
int solve(void){
    int i;
    dp[0] = 0; dp[1] = P[1]; dp[2] = P[1]+P[2];
    for (i = 3; i<= N; i++) dp[i] = NOTSOLVED;
    return memoi(N);
}
#else
int solve(void){
    int i;
    dp[0] = 0; dp[1] = P[1]; dp[2] = P[1]+P[2];
    for (i = 3; i <= N; i++){
        if (dp[i-2] > dp[i-3]+P[i-1]) dp[i] = dp[i-2]+P[i];//전전계단 밟고 현재 계단 밟는 경우
        else dp[i] = dp[i-3]+P[i-1]+P[i];//전전전 계단 밟고 전계단과 현재 계단 밟는 경우
    }
    return dp[N];
}
#endif // TEST
int main(void){
    int i;
    scanf("%d", &N);
    for (i = 1; i <= N; i++) scanf("%d", &P[i]);
    sol = solve();
    printf("%d", sol); // 정답 출력
    return 0;
}
//C4 : 토마토(고)
#include <stdio.h>
#define MAXN ((int)1e3 + 10)
int M, N;//가로, 세로 크기
int map[MAXN][MAXN];//상자 내용
struct Q{
    int r, c, t;
};
struct Q queue[MAXN * MAXN];
int wp, rp;
int push(int r, int c, int t){
    if (map[r][c] != 1) return 0;//확산 실패
    map[r][c] = 0;
    queue[wp].r=r; queue[wp].c=c; queue[wp].t=t; wp++;
    return 1;//확산 성공
}
struct Q front(void) { return queue[rp]; }
void pop(void) { rp++; }
int size(void) { return wp-rp; }
int empty(void) { return wp==rp; }
void InputData(void){
    int i, j;
    scanf("%d %d", &M, &N);
    for (i = 1; i <= N; i++){
        for (j = 1; j <= M; j++){
            scanf("%d", &map[i][j]);
        }
    }
}
int BFS(void){
    struct Q cur;
    int i, j, alive = 0;//안 익은 개수(빈칸은 빼고 순수하게 안익은 토마토 개수)
    int dr[] = {-1, 1, 0, 0};
    int dc[] = {0, 0, -1, 1};
    alive = wp = rp = 0;//1.초기화
    //2.시작위치 큐에 저장
    for (i = 1; i <= N; i++){
        for (j = 1; j <= M; j++){
            if (map[i][j] == 1){//익은 토마토
                push(i, j, 0);
            }
            else if(map[i][j] == 0){//안 익은 토마토
                map[i][j] = 1;//안 익은 토마토를 1로 표시(범위 밖 값도 0이므로 수정필요)
                alive++;//안 익은 토마토 개수 파악
            }
        }
    }
    while (!empty()){//3.반복문
        cur = front(); pop();
        for (i = 0; i < 4; i++){
            if (push(cur.r+dr[i], cur.c+dc[i], cur.t+1) == 1){
                if (--alive == 0) return cur.t+1;//익힐때마 감소 0이면 다 익었음, 성공
            }
        }
    }
    return -1;//4.실패
}
int main(void){
    int ans;
    InputData();
    ans = BFS();
    printf("%d\n", ans);
    return 0;
}
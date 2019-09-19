//A1 : 스택 
#include <stdio.h>
#define MAXN ((int)1e4 + 10)
int stack[MAXN];//FA stack
int sp;
int N;
void push(int data){//저장
    stack[++sp] = data;
}
int top(void){//읽기
    return stack[sp];
}
void pop(void){//제거
    sp--;
}
int size(void){//저장된 개수
    return sp;
}
int empty(void){//비었으면 참(1), 아니면 거짓(0)
    return sp == 0;
}
int main()
{
    int i, cmd, data;
    //freopen("in.txt", "r", stdin);
    scanf("%d", &N);
    for(i=1; i<=N;i++){
        scanf("%d", &cmd);
        if(cmd == 1){//저장
            scanf("%d", &data);
            push(data);
        }
        else if(cmd == 0){//출력
            if(empty()) printf("E\n");
            else {
                printf("%d\n", top()); pop();
            }
        }
        else{//저장된 개수 출력
            printf("%d\n", size());
        }
    }
    return 0;
} 


//A2 : linear queue
#include <stdio.h>
#define MAXN ((int)1e4 + 10)
int queue[MAXN];
int rp, wp;
int N;
void push(int data){
    queue[wp++] = data;
}
int front(void){
    return queue[rp];
}
void pop(void){
    rp++;
}
int size(void){
    return wp - rp;
}
int empty(void){
    return rp == wp;
}
int main()
{
    int i, cmd, data;
    //freopen("in.txt", "r", stdin);
    scanf("%d", &N);
    for(i=1; i<=N;i++){
        scanf("%d", &cmd);
        if(cmd == 1){//저장
            scanf("%d", &data);
            push(data);
        }
        else if(cmd == 0){//출력
            if(empty()) printf("E\n");
            else{
                printf("%d\n", front()); pop();
            }
        }
        else{//저장된 개수 출력
            printf("%d\n", size());
        }
    }
    return 0;
}
//A2 : Circular queue
#include <stdio.h>
#define MAXN ((int)1e4 + 10)
int queue[MAXN];
int rp, wp, cnt;
int N;
void push(int data){
    queue[wp] = data;
    cnt++;//저장된 개수 증가
    if(wp+1 >= MAXN) wp = 0;
    else wp++;
}
int front(void){
    return queue[rp];
}
void pop(void){
    cnt--;
    if(rp+1 >= MAXN) rp = 0;
    else rp++;
}
int size(void){
    return cnt;
}
int empty(void){
    return cnt == 0;
}
int main()
{
    int i, cmd, data;
    //freopen("in.txt", "r", stdin);
    scanf("%d", &N);
    for(i=1; i<=N;i++){
        scanf("%d", &cmd);
        if(cmd == 1){//저장
            scanf("%d", &data);
            push(data);
        }
        else if(cmd == 0){//출력
            if(empty()) printf("E\n");
            else{
                printf("%d\n", front()); pop();
            }
        }
        else{//저장된 개수 출력
            printf("%d\n", size());
        }
    }
    return 0;
}
//A3 : 카드건네기 (linear queue)
#include <stdio.h>
#define MAXN (100 * 100 + 10)
int N;
int queue[MAXN];
int wp, rp;
void push(int data){
    queue[wp++] = data;
}
int front(void){//가장 먼저 추가된 데이터
    return queue[rp];
}
int back(void){//최근에 추가된 데이터
    return queue[wp - 1];
}
void pop(void){
    rp++;
}
int size(void){
    return wp - rp;
}
int empty(void){
    return wp == rp;
}
void InputData(void){
    scanf("%d", &N);
}
void solve(void){
    int i, j, n;
    wp = rp = 0;//queue initial
    for(i=1;i<=N;i++){
        push(i);
    }
    for(i=1;i<N;i++){//N-1회 반복 수행
        n = back() / 2;//마지막 카드 /2회 만큼 수행
        for(j=1;j<=n;j++){//n회 반복
            push(front()); pop();
        }
        printf("%d ", front()); pop();
    }
    printf("%d ", front()); pop();
}
int main(){
    InputData();
    solve();
    return 0;
}
//기출문제 : 산책(역탐색)
#include <stdio.h>
int N;//직원 수
int T;//산책 시간(분단위)
int P[100000 + 10];//직원 출발 위치
int S[100000 + 10];//직원 산책 속도(분당)
long long pos[100000 + 10];//T분후 예정위치
void Input_Data(void){
int i;
scanf("%d %d", &N, &T);
for (i = 0; i < N; i++){
scanf("%d %d", &P[i], &S[i]);
}
}
int solve(void){
    int i, group = 1, first = N-1;
    for(i=0;i<N;i++){
        pos[i] = P[i] + (long long)T * S[i];
    }
    for(i=N-2;i>=0;i--){//O(N)
        if(pos[first] > pos[i]){//새로운 그룹의 선두 직원임
            group++;//그룹 수 증가
            first = i;//새로운 그룹의 선두 직원
        }
    }
    return group;
}
int main(void){
int ans = -1;
Input_Data(); // 입력 함수
// 코드를 작성하세요
    ans = solve();
printf("%d\n", ans); // 정답 출력
return 0;
}
//기출문제 : 산책(stack 스택자료구조 활용)
#include <stdio.h>
int N;//직원 수
int T;//산책 시간(분단위)
int P[100000 + 10];//직원 출발 위치
int S[100000 + 10];//직원 산책 속도(분당)
long long stack[100000 + 10];
int sp;
void push(long long data){ stack[++sp] = data; }
long long top(void) { return stack[sp]; }
void pop(void) { sp--; }
int size(void) { return sp; }
int empty(void) { return sp == 0; }
void Input_Data(void){
int i;
scanf("%d %d", &N, &T);
for (i = 0; i < N; i++){
scanf("%d %d", &P[i], &S[i]);
}
}
int solve(void){
    long long pos;
    int i;
    sp = 0;
    for(i=0;i<N;i++){
        pos = P[i] + (long long)T * S[i];
        while(!empty() && top() >= pos) pop();//그룹의 선두만 저장하므로
        push(pos);
    }
    return size();
}
int main(void){
int ans = -1;
Input_Data(); // 입력 함수
// 코드를 작성하세요
    ans = solve();
printf("%d\n", ans); // 정답 출력
return 0;
}
#include <stdio.h>
int N;//건물 수
int H[80010];//건물 높이
int stack[80010];
int sp;
void push(int data){ stack[++sp] = data; }
int top(void) { return stack[sp]; }
void pop(void) { sp--; }
int size(void) { return sp; }
int empty(void) { return sp == 0; }
void Input_Data(void){
    int i;
    scanf("%d", &N);
    for(i = 0 ; i < N ; i++){
        scanf("%d", &H[i]);
    }
}
long long solve(void){
    int i;
    long long sum = 0;
    for(i=0;i<N;i++){
        while(!empty() && top() <= H[i]) pop();//현재 건물보다 낮거나 같은경우 제거
        sum += size();//i번째 건물을 볼수 있는 건물 수
        push(H[i]);//현재 가장 앞 건물이므로 저장
    }
    return sum;
}
int main(void){
    long long ans = -1;
    Input_Data(); // 입력 함수
    // 코드를 작성하세요
    ans = solve();
    printf("%lld\n", ans); // 정답 출력
    return 0;
}
#include <stdio.h>
#define MAXQ (100 * 100 + 10)
int N, M;//문서수, 원하는 문서 번호
struct Q{
    int n, p;//문서 번호, 우선 순위
};
struct Q queue[MAXQ];
int wp, rp;
int priocnt[10];//우선순위별 개수
void push(int n, int p){
    queue[wp].n=n; queue[wp].p=p; wp++;
}
struct Q front(void){
    return queue[rp];
}
void pop(void){
    rp++;
}
int size(void){
    return wp - rp;
}
int empty(void){
    return wp == rp;
}
void Initial(void){
    int i;
    wp = rp = 0;//큐 초기화
    for(i=1;i<=9;i++) priocnt[i]=0;//배열 초기화
}
void InputData(void){
    int i, p;
    scanf("%d %d", &N, &M);
    for(i=0;i<N;i++){
        scanf("%d", &p);
        priocnt[p]++;//각 우선순위 개수 파악
        push(i, p);
    }
}
int solve(void){
    int i, seq = 0;
    for(i=9;i>=1;i--){
        while(priocnt[i]){
            if(front().p != i){//낮은 우선순위 문서임
                push(front().n, front().p);//뒤로 보내기
            }
            else{//출력할 우선 순위 문서임
                seq++;
                priocnt[i]--;
                if(front().n == M) return seq;//끝
            }
            pop();
        }
    }
    return -1;//이런 경우 없음(디버깅을 위해)
}
int main(){
    int T, ans;
    scanf("%d", &T);
    while(T--){
        Initial();
        InputData();
        ans = solve();
        printf("%d\n", ans);
    }
    return 0;
}
//기출문제 : 장기자랑
#include <stdio.h>
#define MAXQ ((int)1e4 + 10)
int N;//직원 수
int S;//시작 직원 번호
int M;
int queue[MAXQ];
int wp, rp, cnt;
void push(int data){
    queue[wp] = data;
    cnt++;
    if(++wp >= MAXQ) wp = 0;
}
int front(void) { return queue[rp]; }
void pop(void) {
    cnt--;
    if(++rp >= MAXQ) rp = 0;
}
int size(void) { return cnt; }
int empty(void) { return cnt == 0; }
void InputData(){
    scanf("%d %d %d", &N, &S, &M);
}
void solve(void){
    int i, j;
    wp = rp = cnt = 0;//큐 초기화
    for(i=0;i<N;i++){
        push(S);
        if(++S > N) S = 1;
    }
    for(i=1;i<N;i++){//N-1회 반복
        for(j=1;j<M;j++){//M-1회 반복
            push(front()); pop();
        }
        printf("%d ", front()); pop();
    }
    printf("%d ", front());//N번째
}
int main(){
    InputData();// 입력 함수
    // 코드를 작성하세요
    solve();
    return 0;
}
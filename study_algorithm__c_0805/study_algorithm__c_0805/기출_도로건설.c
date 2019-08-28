//기출문제 : 도로건설
#include <stdio.h>
#define INF (100 * 100 * 10 + 10)
int N;//지도 크기
char map[110][110];//지도 정보
int visited[110][110];
struct Q{
    int r, c;
};
struct Q queue[110 * 110 * 50];
int wp, rp;
void push(int r, int c, int t){
    if (visited[r][c] <= t) return;
    visited[r][c] = t;
    queue[wp].r=r; queue[wp].c=c; wp++;
}
struct Q front(void){ return queue[rp]; }
void pop(void) { rp++; }
int size(void) { return wp-rp; }
int empty(void) { return wp==rp; }
void Input_Data(void){
    int i;
    scanf("%d", &N);
    for(i = 0 ; i < N ; i++){
        scanf("%s", map[i]);
    }
}
int BFS(void){
    struct Q cur;
    int i, j, nr, nc;
    int dr[] = {-1, 1,  0, 0};//상하좌우
    int dc[] = { 0, 0, -1, 1};
    wp = rp = 0;//1.초기화
    for (i = 0; i < N; i++){
        for (j = 0; j < N; j++){
            visited[i][j] = INF;
        }
    }
    push(0, 0, 0);//2.시작위치 큐에 저장
    while(!empty()){//3.반복문
        cur = front(); pop();
        for (i = 0; i < 4; i++){
            nr = cur.r+dr[i]; nc = cur.c+dc[i];
            if ((nr < 0) || (nr >= N) || (nc < 0) || (nc >= N)) continue;//범위 벗어남
            push(nr, nc, visited[cur.r][cur.c]+map[nr][nc]-'0');
        }
    }
    return visited[N-1][N-1];//4.결과리턴
}
int main(void){
    int ans = -1;
    Input_Data(); // 입력 함수
    // 코드를 작성하세요
    ans = BFS();
    printf("%d\n", ans); // 정답 출력
    return 0;
}

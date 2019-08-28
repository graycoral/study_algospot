#include <stdio.h>
#define MAXN (100 + 10)
int X, Y;//가로, 세로
int sx, sy, ex, ey;//출발 가로세로, 도착 가로세로
char map[MAXN][MAXN];//지도정보
int visited[MAXN][MAXN];//경험표시(중복방문 방지용)
struct Q{
    int r, c, t;//세로, 가로, 시간
};
struct Q queue[MAXN * MAXN];//크기는 경험개수(visited배열 크기) linear queue
int wp, rp;
void push(int r, int c, int t){
    if (map[r][c] != '0') return;//길이 아님(벽이거나 범위 벗어남)
    if (visited[r][c] == 1) return;//방문했었음(이미 경험했음)
    visited[r][c] = 1;//방문표시(경험표시)
    queue[wp].r=r; queue[wp].c=c; queue[wp].t=t; wp++;
}
struct Q front(void) { return queue[rp]; }
void pop(void) { rp++; }
int size(void) { return wp - rp; }
int empty(void) { return wp == rp; }
void InputData(void){
    int i;
    scanf("%d %d", &X, &Y);
    scanf("%d %d %d %d", &sx, &sy, &ex, &ey);
    for (i = 1; i <= Y; i++){//세로 인덱스
        scanf("%s", &map[i][1]);
    }
}
int BFS(void){
    struct Q cur;
    int dr[] = {-1, 1,  0, 0};//상하좌우
    int dc[] = { 0, 0, -1, 1};
    int i;
    wp = rp = 0;//1.필요시 초기화
    push(sy, sx, 0); //2.초기위치 큐에 저장
    while (!empty()){//3.반복문
        cur = front(); pop();
        if ((cur.r == ey) && (cur.c == ex)) return cur.t;//도착 성공
        for (i = 0; i < 4; i++){//상하좌우 4방향
            push(cur.r + dr[i], cur.c + dc[i], cur.t + 1);
        }
    }
    return -1;//4.도착실패(이 문제는 이런 경우 없음, 디버깅을 위해)
}
int main(void){
    int ans;
    InputData();
    ans = BFS();
    printf("%d\n", ans);
    return 0;
}
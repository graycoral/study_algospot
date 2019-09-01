//B2 : 저글링방사능오염(BFS)
#include <stdio.h>
#define MAXN (100 + 10)
int X, Y;//가로, 세로
int sx, sy;//출발 가로세로
int alive;//살아있는 저글링 수
char map[MAXN][MAXN];//지도정보
int visited[MAXN][MAXN];//경험표시(중복방문 방지용)
struct Q{
    int r, c, t;//세로, 가로, 시간
};
struct Q queue[MAXN * MAXN];//크기는 경험개수(visited배열 크기) linear queue
int wp, rp;
void push(int r, int c, int t){
    if (map[r][c] != '1') return;//저글링 아님(혹은 범위 벗어남)
    if (visited[r][c] > 0) return;//방문했었음(이미 경험했음)
    visited[r][c] = t;//방문표시(경험표시)
    alive--;//저글링 수 감소시키기
    queue[wp].r=r; queue[wp].c=c; queue[wp].t=t; wp++;
}
struct Q front(void) { return queue[rp]; }
void pop(void) { rp++; }
int size(void) { return wp - rp; }
int empty(void) { return wp == rp; }
void InputData(void){
    int i;
    scanf("%d %d", &X, &Y);
    for (i = 1; i <= Y; i++){//세로 인덱스
        scanf("%s", &map[i][1]);
    }
    scanf("%d %d", &sx, &sy);
}
int BFS(void){
    struct Q cur;
    int dr[] = {-1, 1,  0, 0};//상하좌우
    int dc[] = { 0, 0, -1, 1};
    int i, j;
    alive = wp = rp = 0;//1.필요시 초기화
    for (i = 1; i <= Y; i++){
        for (j = 1; j <= X; j++){
            if (map[i][j] == '1') alive++;
        }
    }
    push(sy, sx, 3); //2.초기위치 큐에 저장
    while (!empty()){//3.반복문
        cur = front(); pop();
        for (i = 0; i < 4; i++){//상하좌우 4방향
            push(cur.r + dr[i], cur.c + dc[i], cur.t + 1);
        }
    }
    return cur.t;//4.마지막에 확산된 저글링이 마지막에 죽은 저글링임
}

void print()
{
	for (int i = 0; i <= Y; i++) {
		for (int j = 0; j <= X; j++) {
			printf("%3d ", visited[i][j]);
		}
		printf("\n");
	}
}
int main(void){
    int ans;
    InputData();
    ans = BFS();
    printf("%d\n", ans);
    printf("%d\n", alive);
	//print();
    return 0;
}
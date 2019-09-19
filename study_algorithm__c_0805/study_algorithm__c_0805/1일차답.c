//A1 : ���� 
#include <stdio.h>
#define MAXN ((int)1e4 + 10)
int stack[MAXN];//FA stack
int sp;
int N;
void push(int data){//����
    stack[++sp] = data;
}
int top(void){//�б�
    return stack[sp];
}
void pop(void){//����
    sp--;
}
int size(void){//����� ����
    return sp;
}
int empty(void){//������� ��(1), �ƴϸ� ����(0)
    return sp == 0;
}
int main()
{
    int i, cmd, data;
    //freopen("in.txt", "r", stdin);
    scanf("%d", &N);
    for(i=1; i<=N;i++){
        scanf("%d", &cmd);
        if(cmd == 1){//����
            scanf("%d", &data);
            push(data);
        }
        else if(cmd == 0){//���
            if(empty()) printf("E\n");
            else {
                printf("%d\n", top()); pop();
            }
        }
        else{//����� ���� ���
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
        if(cmd == 1){//����
            scanf("%d", &data);
            push(data);
        }
        else if(cmd == 0){//���
            if(empty()) printf("E\n");
            else{
                printf("%d\n", front()); pop();
            }
        }
        else{//����� ���� ���
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
    cnt++;//����� ���� ����
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
        if(cmd == 1){//����
            scanf("%d", &data);
            push(data);
        }
        else if(cmd == 0){//���
            if(empty()) printf("E\n");
            else{
                printf("%d\n", front()); pop();
            }
        }
        else{//����� ���� ���
            printf("%d\n", size());
        }
    }
    return 0;
}
//A3 : ī��ǳױ� (linear queue)
#include <stdio.h>
#define MAXN (100 * 100 + 10)
int N;
int queue[MAXN];
int wp, rp;
void push(int data){
    queue[wp++] = data;
}
int front(void){//���� ���� �߰��� ������
    return queue[rp];
}
int back(void){//�ֱٿ� �߰��� ������
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
    for(i=1;i<N;i++){//N-1ȸ �ݺ� ����
        n = back() / 2;//������ ī�� /2ȸ ��ŭ ����
        for(j=1;j<=n;j++){//nȸ �ݺ�
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
//���⹮�� : ��å(��Ž��)
#include <stdio.h>
int N;//���� ��
int T;//��å �ð�(�д���)
int P[100000 + 10];//���� ��� ��ġ
int S[100000 + 10];//���� ��å �ӵ�(�д�)
long long pos[100000 + 10];//T���� ������ġ
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
        if(pos[first] > pos[i]){//���ο� �׷��� ���� ������
            group++;//�׷� �� ����
            first = i;//���ο� �׷��� ���� ����
        }
    }
    return group;
}
int main(void){
int ans = -1;
Input_Data(); // �Է� �Լ�
// �ڵ带 �ۼ��ϼ���
    ans = solve();
printf("%d\n", ans); // ���� ���
return 0;
}
//���⹮�� : ��å(stack �����ڷᱸ�� Ȱ��)
#include <stdio.h>
int N;//���� ��
int T;//��å �ð�(�д���)
int P[100000 + 10];//���� ��� ��ġ
int S[100000 + 10];//���� ��å �ӵ�(�д�)
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
        while(!empty() && top() >= pos) pop();//�׷��� ���θ� �����ϹǷ�
        push(pos);
    }
    return size();
}
int main(void){
int ans = -1;
Input_Data(); // �Է� �Լ�
// �ڵ带 �ۼ��ϼ���
    ans = solve();
printf("%d\n", ans); // ���� ���
return 0;
}
#include <stdio.h>
int N;//�ǹ� ��
int H[80010];//�ǹ� ����
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
        while(!empty() && top() <= H[i]) pop();//���� �ǹ����� ���ų� ������� ����
        sum += size();//i��° �ǹ��� ���� �ִ� �ǹ� ��
        push(H[i]);//���� ���� �� �ǹ��̹Ƿ� ����
    }
    return sum;
}
int main(void){
    long long ans = -1;
    Input_Data(); // �Է� �Լ�
    // �ڵ带 �ۼ��ϼ���
    ans = solve();
    printf("%lld\n", ans); // ���� ���
    return 0;
}
#include <stdio.h>
#define MAXQ (100 * 100 + 10)
int N, M;//������, ���ϴ� ���� ��ȣ
struct Q{
    int n, p;//���� ��ȣ, �켱 ����
};
struct Q queue[MAXQ];
int wp, rp;
int priocnt[10];//�켱������ ����
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
    wp = rp = 0;//ť �ʱ�ȭ
    for(i=1;i<=9;i++) priocnt[i]=0;//�迭 �ʱ�ȭ
}
void InputData(void){
    int i, p;
    scanf("%d %d", &N, &M);
    for(i=0;i<N;i++){
        scanf("%d", &p);
        priocnt[p]++;//�� �켱���� ���� �ľ�
        push(i, p);
    }
}
int solve(void){
    int i, seq = 0;
    for(i=9;i>=1;i--){
        while(priocnt[i]){
            if(front().p != i){//���� �켱���� ������
                push(front().n, front().p);//�ڷ� ������
            }
            else{//����� �켱 ���� ������
                seq++;
                priocnt[i]--;
                if(front().n == M) return seq;//��
            }
            pop();
        }
    }
    return -1;//�̷� ��� ����(������� ����)
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
//���⹮�� : ����ڶ�
#include <stdio.h>
#define MAXQ ((int)1e4 + 10)
int N;//���� ��
int S;//���� ���� ��ȣ
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
    wp = rp = cnt = 0;//ť �ʱ�ȭ
    for(i=0;i<N;i++){
        push(S);
        if(++S > N) S = 1;
    }
    for(i=1;i<N;i++){//N-1ȸ �ݺ�
        for(j=1;j<M;j++){//M-1ȸ �ݺ�
            push(front()); pop();
        }
        printf("%d ", front()); pop();
    }
    printf("%d ", front());//N��°
}
int main(){
    InputData();// �Է� �Լ�
    // �ڵ带 �ۼ��ϼ���
    solve();
    return 0;
}
#include <stdio.h>
#include <stdlib.h>
void resetBoard(char(*board)[3]); //盤面のリセット
void displayBoard(char(*board)[3]); //盤面の表示
void hand(char(*board)[3], char mb); //一手分の操作
void judge(char(*board)[3]);//判定
void triple(char, char, char);
//char board[3][3];
int nokori = 9;
int main(void)
{
    char board[3][3];

    resetBoard(board);
    printf("○×ゲーム\n");
    displayBoard(board);
    while (1) {
        printf("先手の番（横縦で入力してください）：");
        hand(board, 'O');
        printf("後手の番（横縦で入力してください）：");
        hand(board, 'X');
    }
}
void resetBoard(char(*board)[3])
{
    int  x, y = 0;
    for (x = 0; x < 3; x++)          //3以上の数字の要素はないので
        for (y = 0; y < 3; y++)
            board[x][y] = ' ';      //空白にしてリセットにする
}
void displayBoard(char(*board)[3]) //盤面の表示
{
    int math;
    printf("\n   0   1   2\n");
    printf(" -------------\n");
    for (math = 0; math < 3; math++) {
        printf("%1d| %c | %c | %c |\n", math, board[0][math], board[1][math],
            board[2][math]);
        printf(" -------------\n");
    }
}
void hand(char(*board)[3], char mb)
{
    int x, y = 0; //横　縦
    scanf("%d %d", &x, &y); //どこに入れるかを入力
    while (board[x][y] != ' ') {
        printf("%d,%dは埋まってるので再入力おねがいします", x, y); //埋まっていたので次へ
        scanf("%d %d", &x, &y); //再入力
    }
    board[x][y] = mb;
    nokori--;
    displayBoard(board);                    // 盤面を表示
    judge(board);
    if (!nokori) {
        printf("引き分け\n");
        exit(1);                      //プログラム終了
    }
}
void judge(char(*board)[3])                    // 勝敗判定
{
    int x, y;
    for (y = 0; y < 3; y++)
        triple(board[0][y], board[1][y], board[2][y]);
    for (x = 0; x < 3; x++)
        triple(board[x][0], board[x][1], board[x][2]);
    triple(board[0][0], board[1][1], board[2][2]);
    triple(board[2][0], board[1][1], board[0][2]);
}
void triple(
    char a,
    char b,
    char c)
{
    if (a == ' ') return;
    if (a == b && b == c) {
        if (a == 'O')
            printf("先手の勝ち^_^\n");
        else
            printf("後手の勝ち\n");
        exit(1);
    }
    return;
}
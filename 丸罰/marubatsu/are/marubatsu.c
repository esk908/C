#include <stdio.h>
#include <stdlib.h>
void resetBoard(char(*board)[3]); //�Ֆʂ̃��Z�b�g
void displayBoard(char(*board)[3]); //�Ֆʂ̕\��
void hand(char(*board)[3], char mb); //��蕪�̑���
void judge(char(*board)[3]);//����
void triple(char, char, char);
//char board[3][3];
int nokori = 9;
int main(void)
{
    char board[3][3];

    resetBoard(board);
    printf("���~�Q�[��\n");
    displayBoard(board);
    while (1) {
        printf("���̔ԁi���c�œ��͂��Ă��������j�F");
        hand(board, 'O');
        printf("���̔ԁi���c�œ��͂��Ă��������j�F");
        hand(board, 'X');
    }
}
void resetBoard(char(*board)[3])
{
    int  x, y = 0;
    for (x = 0; x < 3; x++)          //3�ȏ�̐����̗v�f�͂Ȃ��̂�
        for (y = 0; y < 3; y++)
            board[x][y] = ' ';      //�󔒂ɂ��ă��Z�b�g�ɂ���
}
void displayBoard(char(*board)[3]) //�Ֆʂ̕\��
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
    int x, y = 0; //���@�c
    scanf("%d %d", &x, &y); //�ǂ��ɓ���邩�����
    while (board[x][y] != ' ') {
        printf("%d,%d�͖��܂��Ă�̂ōē��͂��˂������܂�", x, y); //���܂��Ă����̂Ŏ���
        scanf("%d %d", &x, &y); //�ē���
    }
    board[x][y] = mb;
    nokori--;
    displayBoard(board);                    // �Ֆʂ�\��
    judge(board);
    if (!nokori) {
        printf("��������\n");
        exit(1);                      //�v���O�����I��
    }
}
void judge(char(*board)[3])                    // ���s����
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
            printf("���̏���^_^\n");
        else
            printf("���̏���\n");
        exit(1);
    }
    return;
}
#include <stdio.h>
#define MAX_STACK_SIZE 100
int maze[12][16] = {{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
                    {1,0,1,0,1,0,0,1,1,0,1,0,1,0,1,1},
                    {1,1,0,0,0,1,0,0,0,1,0,0,1,1,0,1},
                    {1,1,1,0,1,0,1,1,1,1,1,1,1,1,0,1},
                    {1,0,0,1,1,1,0,0,0,1,1,1,1,1,1,1},
                    {1,1,0,1,1,1,1,0,1,1,1,1,0,1,0,1},
                    {1,1,0,0,0,1,1,1,1,1,0,0,0,0,0,1},
                    {1,0,0,1,1,0,1,0,1,0,1,1,1,1,0,1},
                    {1,1,1,1,0,1,0,0,0,0,1,0,0,0,0,1},
                    {1,0,0,0,1,0,1,1,1,0,1,0,0,0,1,1},
                    {1,1,1,1,1,1,1,1,1,0,0,1,0,0,0,1},
                    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    }; 
typedef struct{
    short int vert;
    short int horiz;
}offsets;
typedef struct {
    short int row;
    short int col;
    short int dir;
}element;
element stack[MAX_STACK_SIZE];
offsets move[8] = {{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1}};

int empty(int a, int b, int c)
{
    if(a == 0 && b == 0 && c == 0)
        return 0;
    else
        return 1;
}
void setElement(element *a, const element b)
{
    a->row = b.row;
    a->col = b.col;
    a->dir = b.dir;
}
void freeElement(element *a)
{
    a->row = 0;
    a->col = 0;
    a->dir = 0;
}
int main()
{
    int start = maze[1][1];
    int end = maze[10][14];
    int flag = 0;
    int i = 0;
    stack[0].row = 1;
    stack[0].col = 1;
    stack[0].dir = 0;
    while(empty(stack[0].row,stack[0].col,stack[0].dir) && !flag){
        element temp;
        setElement(&temp,stack[i]);
        freeElement(&stack[i]);
        int dir = 0;
        while(dir < 8){
           element next = {
            temp.row + move[dir].vert, 
            temp.col + move[dir].horiz, 
            dir};
            if(next.row == 10 && next.col == 14){
                flag = 1;
                break;
            }
            if(maze[next.row][next.col] == 0){
                stack[i] = temp;
                stack[++i] = next;
                maze[next.row][next.col] = 1;
                break;
            }
            dir++;
        }
        if(dir == 8){
            // printf("i = %d, <x,y,dir> = <%d,%d,%d>\n",i-1,temp.row,temp.col,temp.dir);
            i--;
        }
    }
    for(int j = 0; j < i; j++){
        printf("i = %d, <x,y,dir> = <%d,%d,%d>\n",j-1,stack[j].row,stack[j].col,stack[j].dir);
    }
    return 0;
}
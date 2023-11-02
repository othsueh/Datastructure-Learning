#include "lib/base.h"
#include "lib/cursor.h"
#include "lib/erase.h"
#include "lib/color.h"
#include <unistd.h>
#define MAXSIZE 10000
#define Cur Color.pick(5,0,0,0)
#define OK 1
#define ERROR 0
typedef int Status;

typedef struct Unit* history;
typedef struct Unit{
    str text;
    u32 cursor;     
    history next;
}Unit;
typedef struct{
    history top;
    u32 count;
}historyStack;
void init(str *text, u32 *cursor)
{
    printf("Please enter an initial string consisting a/A-z/Z and space:\n");
    fgets(*text, MAXSIZE, stdin);
    *cursor = strlen(*text);
    (*text)[--(*cursor)] = '\0';
}
void historyInit(historyStack *stack)
{
    stack->top = (history)malloc(sizeof(Unit));
    stack->top = NULL;
    stack->count = 0;
    return;
}
Status historyEmpty(historyStack stack)
{
    if(stack.count == 0)
        return OK;
    else
        return ERROR;
}
void historyPush(historyStack *stack, str text, u32 cursor)
{
    history newUnit = (history)malloc(sizeof(Unit));
    newUnit->text = (str)malloc(MAXSIZE * sizeof(char));
    strcpy(newUnit->text, text);
    newUnit->cursor = cursor;
    newUnit->next = stack->top;
    stack->top = newUnit;
    stack->count++;
    return;
}
void historyPop(historyStack *stack, str *text, u32 *cursor)
{
    if(historyEmpty(*stack)) return;
    history temp = stack->top;
    stack->top = stack->top->next;
    strcpy(*text, temp->text);
    *cursor = temp->cursor;
    free(temp);
    stack->count--;
    return;
}
void historyErase(historyStack *stack)
{
    while(!historyEmpty(*stack)){
        history temp = stack->top;
        stack->top = stack->top->next;
        free(temp);
        stack->count--;
    }
    free(stack->top);
    return;
}
void commandList()
{
    printf("Please enter a command:\n");
    printf("a/A-z/Z or space: Insert\n");
    printf("0) Delete a character before the cursor\n");
    printf("1) Move the cursor to the left\n");
    printf("2) Move the cursor to the right\n");
    printf("3) undo\n");
    printf("4) redo\n");
    printf("Esc) exit the program\n");
}
void charDelete(str *text, u32 *cursor)
{
    u32 len = strlen(*text);
    if(*cursor == 0 || len == 0) return;
    if(len == *cursor) (*text)[--(*cursor)] = '\0';
    else{
        memmove(*text + *cursor - 1, *text + *cursor, len - *cursor);
        (*text)[len-1] = '\0';
        (*cursor)--;
    }
    return;
}
void charInsert(str *text, u32 *cursor, u8 c)
{
    u32 len = strlen(*text);
    if(len == MAXSIZE) return;
    memmove(*text + *cursor + 1, *text + *cursor, len - *cursor);
    (*text)[(*cursor)++] = c;
    (*text)[len + 1] = '\0';
    return;
}
void textPrint(str text, u32 cursor)
{
    u32 len = strlen(text);
    for(u32 i = 0; i < len; i++){
        if(i == cursor) printf("%s|%s", Cur,RES);
        printf("%c", text[i]);
    }
    if(len == cursor)   printf("%s|%s", Cur,RES);     
    printf("\n");
    return;
}
void cursorMove(str text,u32 *cursor, u8 c)
{
    u32 len = strlen(text);
    if(c == 1){
        if(*cursor == len) return;
        (*cursor)++;
    }else{
        if(*cursor == 0) return;
        (*cursor)--;
    }
    return;
}
int main()
{
    u8 c;
    u32 cursor=0;
    str text = (str)malloc(MAXSIZE * sizeof(char));
    historyStack undoStack, redoStack;
    historyInit(&undoStack);
    historyInit(&redoStack);
    init(&text, &cursor);
    Cursor.prev_line(1);
    Erase.line_entire();
    Cursor.prev_line(1);
    Erase.line_entire();
    commandList();
    while(1){
        textPrint(text, cursor);
        c = getchar();
        getchar();
        if(c == 27) break;
        switch(c){
            case '0':
                historyPush(&undoStack, text, cursor);
                charDelete(&text, &cursor);
                break;
            case '1':
                historyPush(&undoStack, text, cursor);
                cursorMove(text, &cursor, 1);
                break;
            case '2':
                historyPush(&undoStack, text, cursor);
                cursorMove(text, &cursor, 0);
                break;
            case '3':
                historyPush(&redoStack, text, cursor);
                historyPop(&undoStack, &text, &cursor);
                break;
            case '4':
                historyPush(&undoStack, text, cursor);
                historyPop(&redoStack, &text, &cursor);
                break;
            default:
                historyPush(&undoStack, text, cursor);
                charInsert(&text, &cursor, c);
                break;
        }
        Cursor.prev_line(1);
        Erase.line_entire();
        Cursor.prev_line(1);
        Erase.line_entire();
    }
    free(text);
    historyErase(&undoStack);
    historyErase(&redoStack);
}
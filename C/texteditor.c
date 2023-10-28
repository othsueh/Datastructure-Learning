#include "lib/base.h"
#include "lib/cursor.h"
#include "lib/erase.h"
#include <unistd.h>
#define MAXSIZE 10000

void init(str *text)
{
    printf("Please enter an initial string consisting a/A-z/Z and space:\n");
    fgets(*text, MAXSIZE, stdin);
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
int main()
{
    i8 c;
    str text = (str)malloc(MAXSIZE * sizeof(char));
    init(&text);
    Cursor.prev_line(1);
    Erase.line_entire();
    Cursor.prev_line(1);
    Erase.line_entire();
    commandList();
    while(1){
        printf("%s", text);
        c = getchar();
        getchar();
        if(c == 27) break;
        switch(c){
            case '0':
                break;
            case '1':
                break;
            case '2':
                break;
            case '3':
                break;
            case '4':
                break;
            default:
                break;
        }
        Cursor.prev_line(1);
        Erase.line_entire();
        Cursor.prev_line(1);
        Erase.line_entire();
    }
    free(text);
}
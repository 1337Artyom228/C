#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <unistd.h>
#include <stdlib.h>

void show(char array[])
{
    for(int i = 0; i < 9; i++)
    {
    printf("%c  ", array[i]);
    if(i%3 == 2)
    {
        printf("\n");
    }
    }
}

bool checkwin(char array[])
{
    if(array[0] == array[4] & array[4] == array[8] | array[2] == array[4] & array[6] == array[8])
    {
        return true;
    }
    for(int i = 0; i < 3; i++)
    {
        if(array[i*3] == array[i*3+1] & array[i*3+1] == array[i*3+2] | array[i] == array[i+3] & array[i+3] == array[i+6])
        {
            return true;
        }
    
    }
    return false;
}
// X - 88; O - 79
int main()
{
char arr[] = {49, 50, 51, 52, 53, 54, 55, 56, 57};
char turn = 79;
int where;
clock_t t0 = clock();

while(!checkwin(arr))
{
    turn = (turn == 79) ? 88 : 79;
    show(arr);
    printf("\nWhere do i put %c :", turn);
    scanf("%d", &where);
    if(arr[where-1] == 88 | arr[where-1] == 79)
    {
        printf("No turn for u lmao\n");
    }
    else
    {
        arr[where-1] = turn;
    }
}
system("cls");
show(arr);
printf("\n%c won\n", turn);
t0 = clock() - t0;
printf("\n%.2f sec taken\n", ((double)t0) / CLOCKS_PER_SEC);
sleep(99999999);
return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int cash =100;

void play(int bet)
{
    char *C=(char*)malloc(3000*sizeof(char));
    C[0]='J';C[1]='Q';C[2]='K';
    printf("Shuffeling.... \n");
    srand(time(NULL));
    for(int i=0;i<5;i++)
    {
        int x = rand() % 3;
        int y = rand() % 3;
        int tmp = C[x];
         C[x] = C[y];
         C[y] = tmp; //swaps characters atposiotion x and y
    }
int PlayerGuess;
printf("What's the position of Queen - 1,2 or 3 ? ");
scanf("%d",&PlayerGuess);
if(C[PlayerGuess - 1] == 'Q') {
    cash += 3*bet;
    printf("You Win !!!, Result = %c%c%c Total Cash = %d\n ",C[0],C[1],C[2],cash);
}
else {
    cash -= bet;
    printf(" You loose ! Result = %c%c%c Total Cash = %d\n ",C[0],C[1],C[2],cash);
}
free(C);
}
int main()
{
    int bet;
printf("Welcome to the Virtual Casino !\n");
printf("Total Cash is : %d\n",cash);
    while(cash > 0)
    {
        printf("what's your bet ?? ");
        printf("enter bet : ");
        scanf("%d",&bet);
        if (bet == 0 || bet > cash) {
            break;
        }
        play(bet);
    }

    return 0;
}

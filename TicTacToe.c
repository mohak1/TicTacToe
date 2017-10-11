#include<stdio.h>
#include<string.h>


void main(){
    char Board[3][3],p1,p2,name1[30],name2[30];
    int i,j,n,t,rem[3][3],flag=0,num=1;
    char res;

START:

    printf("Welcome to TicTacToe \n");
    printf("General Instructions: \nPlayer1 goes first, followed by Player2.\n\nNo player is allowed to change the position of symbol after the input.\n");
    printf("\nSpaces can be filled up only once and cannot be rewritten during the course of the game.\n");
    printf("\nThe Reference Board is provided to give you an idea about the positions on the GameBoard.\n");
    printf("\nOnce a position is used, it will be marked as 0 in the Reference Board.\n");

    printf("Player 1, Enter your name:\n");
    //scanf("%s",name1);
    gets(name1);
    printf("Player 2, Enter your name:\n");
    //scanf("%s",name2);
    gets(name2);

    printf("\nEnter your Symbol, %s: ", name1);
    //scanf("%c",&p1);
    p1 = getchar();
    printf("\nEnter your Symbol, %s: ", name2);
    //scanf("%c",&p2);
    p2 = getchar();

    scanf("%c",&p2);
    printf("\n Board for reference \n");


    //Preparing REM
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            rem[i][j]=(10*(i+1)+j+1);
        }
    }

    //Printing REM
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            printf("%d \t",rem[i][j]);
        }
        printf("\n");
    }

    //Preparing GameBoard
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            Board[i][j]='_';
        }
    }

    //Starting Game from Turn 1
    for(t=1;t<=9;t++){
        Y:

        //Player1's Turn

        printf("%s's turn\n",name1);
        printf("Enter the position where you want to place your Symbol\n");
        scanf("%d",&n);


        j=n%10;
        i=n/10;

        if(rem[i-1][j-1]==0){
            printf("Position occupied. Please try again.\n");
            goto Y;
        }else{
            flag=1;
        }

        if(flag==1){
            Board[i-1][j-1]=p1;
            rem[i-1][j-1]=0;
            printf("\n\n");

            //Printing GameBoard
            printf("GameBoard:\n");
            for(i=0;i<3;i++){
                for(j=0;j<3;j++){
                    printf("%c \t",Board[i][j]);
                }
                printf("\n");
            }

             //Printing REM
             printf("\nReference Board:\n");
        for(i=0;i<3;i++){
            for(j=0;j<3;j++){
                printf("%d \t",rem[i][j]);
            }
            printf("\n");
        }
        printf("\n\n");
        //Player1's Turn Over

        //Checking for Result
        j=0;
        for(i=0;i<3;i++){
            if(Board[i][j]==p1 && Board[i][j+1]==p1 && Board[i][j+2]==p1){
                goto A;

            }else if(Board[j][i]==p1 && Board[j+1][i]==p1 && Board[j+2][i]==p1){
                goto A;

            }
        }

        if(Board[0][0]==p1 && Board[1][1]==p1 && Board[2][2]==p1){
            goto A;

        }else if(Board[0][2]==p1 && Board[1][1]==p1 && Board[2][0]==p1){
            goto A;

        }

        }

        //Checking if REM ran out of free positions
        num=0;
        for(i=0;i<3;i++){
            for(j=0;j<3;j++){
                if(rem[i][j]==0){
                    num++;
                }
            }
        }
        if(num>=9){
            goto C;
        }


        //Starting with Player2's Turn
        X:
        printf("%s's turn\n",name2);
        printf("Enter the position where you want to place your Symbol\n");
        scanf("%d",&n);

        //Checking REM for position
        j=n%10;
        i=n/10;
        if(rem[i-1][j-1]==0){
            printf("Position already occupied. Please try again.\n");
            goto X;
        }else{
            flag=1;
            }

        if(flag==1){
            Board[i-1][j-1]=p2;
            rem[i-1][j-1]=0;


            //Printing GameBoard
            for(i=0;i<3;i++){
                for(j=0;j<3;j++){
                    printf("%c \t",Board[i][j]);
                }
                printf("\n");
            }
            printf("\n\n");


            //Printing REM
             printf("\nReference Board:\n");
        for(i=0;i<3;i++){
            for(j=0;j<3;j++){
                printf("%d \t",rem[i][j]);
            }
            printf("\n");
        }
        printf("\n\n");
        }else{
            printf("Position already occupied. Please try again.\n");
            goto X;

            }

        //Player2's Turn Over
        //Checking for Result
        j=0;
        for(i=0;i<3;i++){
            if(Board[i][j]==p2 && Board[i][j+1]==p2 && Board[i][j+2]==p2){
                goto B;

            }else if(Board[j][i]==p2 && Board[j+1][i]==p2 && Board[j+2][i]==p2){
                goto B;

            }
        }

        if(Board[0][0]==p2 && Board[1][1]==p2 && Board[2][2]==p2){
            goto B;

        }else if(Board[0][2]==p2 && Board[1][1]==p2 && Board[2][0]==p2){
            goto B;

        }


        //Checking if REM ran out of free positions
        num=0;
        for(i=0;i<3;i++){
            for(j=0;j<3;j++){
                if(rem[i][j]==0){
                    num++;
                }
            }
        }
        if(num>=9){
            goto C;
        }


}
 A:  //print GameBoard
     printf("\n Game Over! \n");
        for(i=0;i<3;i++){
            for(j=0;j<3;j++){
                printf("%c \t",Board[i][j]);
            }
            printf("\n");
        }

        printf("\n%s Wins!!! \n",name1);
        printf("Thank you for playing!\n");

        printf("That was a good one! How about another match?\n");
        printf("Press 1 to play again, press any other key to exit.\n");
        //scanf("%d",&res);
        res=getch();
        if(res=='1'){
            goto START;
        }else{
            exit(0);
        }

    B:  //printing GameBoard
        printf("\n Game Over! \n");
        for(i=0;i<3;i++){
            for(j=0;j<3;j++){
                printf("%c \t",Board[i][j]);
            }
            printf("\n");
        }

        printf("\n%s Wins!!! \n",name2);
        printf("Thank you for playing!\n");

        printf("That was a good one! How about another match?\n");
        printf("Press 1 to play again, press any other key to exit.\n");
        //scanf("%d",&res);
        res=getch();
        if(res=='1'){
            goto START;
        }else{
            exit(0);
        }

    C: //When no winner can be declared
        printf("Game Over\n");
        printf("It is a DRAW \n");
        printf("You both played well!");
        printf("Thank you for playing!\n");

        printf("Wanna play again!?\n");
        printf("Press 1 to play again, press any other key to exit.\n");
        //scanf("%d",&res);
        res=getch();
        if(res=='1'){
            goto START;
        }else{
            exit(0);
        }



}

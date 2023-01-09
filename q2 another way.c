#include<stdio.h>
// the game coordinating loop
int gameplay1()
{
    int r=rowcolenter();
    int c=2*r+1;
    int counter[c];
    arrayinitialize(counter,r,c);

    char a[r][c];

    int i=0;
    int j=0;
    for (i=0;i<r;i++)
    {
        for (i=0;i<r;i++)
            {
                for (j=0;j<c;j++)
                {

                    if (j%2!=0)
                    {
                        a[i][j]='_';
                    }

                    if (j%2==0)
                        a[i][j]='|';
                }
            }

            // printing of initial board board
            printf("\n\n THE BOARD IS SET\n");
            for (i=0;i<r;i++)
            {
                for (j=0;j<c;j++)
                {
                    printf("%c",a[i][j]);
                }
                printf("\n");
            }
    }


    int turncount=0,colno;

    // turncounrt counts the no of turns passed

    while (turncount<r*r)
    {

        // for player1
        if (turncount%2==0)
        {
            printf("\n\nPLAYER 1 turn \n");

            colno=playturn();

            int j1=colno,r1=r-1;
            if (counter[j1]>=0)
            {

            }
            while (counter[j1]>=0)
            {

                if (a[r1][j1]!='X')
                {
                    r1--;
                }

                else if (a[r1][j1]!='O')
                {
                    r1--;
                }

                else if (a[r1][j1]=='_')
                {
                    a[r1][j1]='O';
                    counter[j1]--;
                }

            }

            printf("THE UPDATED BOARD IS :- \n");

            for (i=0;i<r;i++)
            {
                for (j=0;j<c;j++)
                {
                    printf("%c",a[i][j]);
                }
                printf("\n");
            }
        }
        a[r-1][j-1]='O';

        // for player2
        if (turncount%2!=0)
        {
            printf("\n\nPLAYER 2 turn \n");

            colno=playturn();

            int j1=colno,r1=r-1;

            while (r1>=0)
            {

                if (a[r1][j1]!='X')
                {
                    r1--;
                }

                if (a[r1][j1]!='O')
                {
                    r1--;
                }

                if (a[r1][j1]=='_')
                {
                    a[r1][j]='X';
                    break;
                }

            }

            printf("THE UPDATED BOARD IS :- \n");

            for (i=0;i<r;i++)
            {
                for (j=0;j<c;j++)
                {
                    printf("%c",a[i][j]);
                }
                printf("\n");
            }
        }


        turncount++;
    }

    return 0;
}

//asks for no of rows
int rowcolenter()
{
    int rowsandcol;
    printf("Enter the no of rows -> ");
    scanf("%d",&rowsandcol);
    return rowsandcol;
}

int playturn()
{
    int choice;
    printf("Enter the column no where you wish to put the peice \n");
    printf("Remember that no of columns begin from 1 and are only odd nos \n(for eg if you enter 4 columns then the column nos will be 1,3,5,7 i.e first 4 odd nos)\n -> ");
    scanf("%d",&choice);
    return choice;
}

int arrayinitialize(int a[],int no,int size)
{
    for (int i=0;i<size;i++)
        a[i]=no;
}

void main()
{
    // Declarations
    char choice;
    // instructions
    printf("WELCOME TO THE GAME -_-\n");
    printf("Rules are as folllows\n1. maximum of 2 players");
    printf("\n2. player 1 has a symbol of O and player 2 has a symbol X \n");
    printf("\n3. each player has to play turn by turn");
    printf("\n4. The user has to enter the row number where the the parcel is to be placed");
    printf("\n5. the row nos begin from 0 to n");

    printf("\n\n THE PLAYER WINS WHEN THE 4 PARCELS ARE CONNECTED IN A ROW OR COLUMN OR DIAGONAL \n\n");
    printf("ARE YOU READY ??\n");
    printf("Y or y for yes and N or n for no -> ");
    scanf("%c",&choice);
    int r=0;// no of rows
    int c=0;// no of columns
    int ic=0;//ic -> internal choice
    int x=0;

    while(choice=='Y'|| choice=='y')
    {
        x=gameplay();
        if (x==0)
        {
            printf("Do you want to continue \n");
            printf("Y or y for yes and N or n for no -> ");
            scanf("%c",&choice);
        }

    }

}

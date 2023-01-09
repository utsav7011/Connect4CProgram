#include<stdio.h>

// the function forms a board
/* NOT WORKING
int formboard(int r,int c, int arrayh[][])
{
    int i=0,j=0;

    for (i=0;i<r;i++)
    {
        for (j=0;j<c;j++)
        {
            if (i%2==0)
            {
                a[i][j]='|';
            }
            else if (i%2!=0)
                a[i][j]='_';
        }
    }
}
*/
void play (char a[][],int r,int c);

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

    while(choice=='Y'||choice=='y')
    {
        printf("\n\nEnter the size of the board \n");
        printf("1. for 4*4\n2. for 5*5\n3. for 6*6");
        scanf("%d",&ic);

        // for 4*4 board
        if (ic==1)
        {
            r=4;
            c=9;
            char a[r][c];
            int i=0,j=0;
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

            // printing of board
            printf("\n\n THE BOARD IS SET\n");
            for (i=0;i<r;i++)
            {
                for (j=0;j<c;j++)
                {
                    printf("%c",a[i][j]);
                }
                printf("\n");
            }

            paly(a,r,c);
        }

        // for 5*5 board
        if (ic==2)
        {
            r=5;
            c=11;
            char a[r][c];
            int i=0,j=0;
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

            // printing of board
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


        // for 6*6 board
        if (ic==3)
        {
            r=6;
            c=13;
            char a[r][c];
            int i=0,j=0;
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

            // printing of board
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
    }
}

#include<stdio.h>

// calls for different functions fro game play

void gamplay();

// helps user enter the no of rows

int rowenter();

// initialise a counter to no of rows of size no of columns

void arrinitialize(int couter[],int cols,int rows);

//checks for the current entered position for vacancy

int check(int a,int row,int col);

// tells the user to enter the column no where the piece is to be placed

int playturn();

void main()
{
    // instructions
    printf("WELCOME TO THE GAME -_-\n");
    printf("Rules are as folllows\n1. maximum of 2 players");
    printf("\n2. player 1 has a symbol of O and player 2 has a symbol X \n");
    printf("\n3. each player has to play turn by turn");
    printf("\n4. The user has to enter the row number where the the parcel is to be placed");
    printf("\n5. the row nos begin from 0 to n");

    printf("\n\n THE PLAYER WINS WHEN THE 4 PARCELS ARE CONNECTED IN A ROW OR COLUMN OR DIAGONAL \n\n");
    int x=1;
    printf("ARE YOU READY ??\n");
    printf("1 for yes and 0 for no -> ");
    scanf("%d",&x);

    while (x==1)
    {
        gamplay();

        printf("Do you want to continue\n 1 to play again and  0 to end \n ->  ");
        scanf("%d",&x);
    }


}

void gamplay()
{
    int r,c;
    r=rowenter();
    c=2*r+1;

    int i=0,j=0;
    char a[r][c];

    // formation of board

    for (i=0;i<r;i++)
    {
        for (j=0;j<c;j++)
        {
            if (j%2==0)
            {
                a[i][j]='|';
            }
            else if (j%2!=0)
            {
                a[i][j]='_';
            }
        }
    }

    printf("\n********* THE BOARD IS ALL SET *********\n");

    for (i=0;i<r;i++)
    {
        for (j=0;j<c;j++)
        {
            printf("%c",a[i][j]);
        }
        printf("\n");
    }
    // to count the no of rows left empty in a row
    int counter[c];

    arrinitialize(counter,c,r);

    int turncounter=0; // ountes for the no of turns

    int c1=playturn(); // accepts the row no where the parcel is to be placed
    int totalchance=r*r;
    while (turncounter<totalchance)
    {
        placing_the_parcel(counter,r,c,a,c1,turncounter);


        printf("\n********* THE UPDATED BOARD IS *********\n");

        for (i=0;i<r;i++)
        {
            for (j=0;j<c;j++)
            {
                printf("%c",a[i][j]);
            }
            printf("\n");
        }

        turncounter++;
    }


    // now the piece is placed in the board


}

int rowenter()
{
    int r=0;
    printf("Enter the no of rows in the game -> ");
    scanf("%d",&r);

    return r;
}


void arrinitialize(int counter[],int c,int r)
{
    int i=0;

    for (i=0;i<c;i++)
    {
        counter[i]=r;
    }
}

int playturn ()
{
    int choice;
    printf("Enter the column no where you want to put the piece\n ");
    printf("Remember that no of columns begin from 1 and are only odd nos \n(for eg if you enter 4 columns then the column nos will be 1,3,5,7 i.e first 4 odd nos)\n -> ");
    scanf("%d",&choice);
    return choice;
}

void placing_the_parcel(int counter[],int r,int col,char a[][col],int r1,int c1,int playerturn)
{
    int i=0,j=0,checkresult=0;

    if (playerturn%2==0)
    {
        r1=r-1;
        while (r1>=0)


        {
            if (r1<0)
            {
                printf("\n\nInvalid move you skipped your tturn");
            }

            else
            {
                checkresult = checkpos(r1,c1,r,col,a);
                if (checkresult==1 || counter[c1]>=0)
                {
                    a[r1][c1]='O';
                    counter[c1]--;
                }
                r1--;
            }

        }


    }

    if (playerturn%2!=0)
    {
        r1=r-1;
        while (r1>=0)
        {
            checkresult=checkpos(r1,c1,r,col,a);
            if (checkresult==1)
            {
                a[r1][c1]='O';
            }
            else
            r1--;
        }

        if (r1<0)
        {
            printf("\n\nInvalid move you skipped your tturn");
        }
    }

}


int checkpos(int r1,int c1,int r,int col,char a[][col])
{
    if (a[r1][c1]=='O')
    {
        return 0;
    }
    else if (a[r1][c1]=='X')
    {
        return 0;
    }
    else if (a[r1][c1]=='_')
    {
        return 1;
    }
}

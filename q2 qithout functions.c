/*
    Code by : UTSAV JAIN
    last modified : 21-11-2020
    Enrolment no. : NBTX10741
*/

/*
    youtube to change the color of the background of output window
*/

#include<stdio.h>
void main()
{
     // instructions
    printf("WELCOME TO THE GAME -_-\n");
    printf("Rules are as folllows\n1. maximum of 2 players");
    printf("\n2. player 1 has a symbol of O and player 2 has a symbol X \n");
    printf("\n3. each player has to play turn by turn");
    printf("\n4. The user has to enter the row number where the the parcel is to be placed");
    printf("\n5. the row nos begin from 0 to n");
    printf("\n6. The no of rows can be either 4 or 5 or 6");
    printf("\n\n THE PLAYER WINS WHEN THE 4 PARCELS ARE CONNECTED IN A ROW OR COLUMN OR DIAGONAL \n\n");
    int x=1;
    printf("ARE YOU READY ??\n");
    printf("1 for yes and 0 for no -> ");
    scanf("%d",&x);


    int flag=0,turncounter=0;

    while (x==1)
    {
        int r=0;
        printf("\nEnter the no of rows -> ");
        scanf("%d",&r);
        int c= 2*r+1;
        int i=0,j=0;

        char a[r][c];
        // board formation
        for (i=0;i<r;i++)
        {
            for (j=0;j<c;j++)
            {
                if (j%2==0)
                {
                    a[i][j]='|';
                }

                if (j%2!=0)
                {
                    a[i][j]='_';
                }
            }
        }

        // printing of board

        for (i=0;i<r;i++)
        {
            for (j=0;j<c;j++)
            {
                printf("%c",a[i][j]);
            }
            printf("\n");
        }

        int colno=0;
        int totalturns=r*r;

        while(turncounter<totalturns)
        {
            // for player 1

            if (turncounter%2==0)
            {
                printf("\n PLAYER 1 Turn \n");
                system("color 0E");
                printf("Enter the column no where you want to put the piece\n ");
                printf("Remember that no of columns begin from 1 and are only odd nos \n(for eg if you enter 4 columns then the column nos will be 1,3,5,7 i.e first 4 odd nos)\n -> ");
                scanf("%d",&colno);

                for (i=r-1;i>=0;i--)
                {
                    // checkes if the row is completely filled or not
                    if ( a[0][colno]=='O'||a[0][colno]=='X' )
                    {
                        printf("The row is filled and you skipped your chance \n");
                        break;
                    }
                    // places a O for the player 1 in the entered column no
                    else if (a[i][colno]=='_')
                    {
                        a[i][colno]='O';
                        break;
                    }
                }


                // printS updated board after each go
                printf("\n********* THE UPDATED BOARD IS *********\n");
                for (i=0;i<r;i++)
                {
                    for (j=0;j<c;j++)
                    {
                        printf("%c",a[i][j]);
                    }
                    printf("\n");
                }

                // checking for winning condition for player 1




                if (r==4)
                {
                        //horizontal row check
                        for(i=r-1;i>=0;i--)
                        {
                            j=1;
                            if (a[i][j]=='O' && a[i][j]==a[i][j+2] && a[i][j]==a[i][j+4] && a[i][j]==a[i][j+6])
                            {
                                flag=1;
                            }
                        }

                    // vertical check

                    for (j=1;j<c;j+=2)
                        {
                                i=r-1;
                                if (a[i][j]=='O' && a[i][j]==a[i-1][j] && a[i][j] == a[i-2][j] && a[i][j] == a[i-3][j])
                                {
                                    flag=1;
                                }
                        }

                        // left to right diagonal check
                        if ( a[0][1]=='O' && a[0][1]==a[1][3] && a[0][1]==a[2][5] && a[0][1] == a[3][7] )
                        {
                            flag==1;
                        }

                        // right to left diagonal check
                        else if (a[0][7]=='O'&& a[0][7]==a[1][5]&& a[0][7]==a[2][3] && a[0][7]==a[3][1])
                        {
                            flag==1;
                        }

                        if (flag==1)
                        {
                            printf("\n\n*********** CONGRACTULATIONS PLAYER 1 WON  *********** \n\n");
                            break;
                        }


                }

                if (r==5)
                {
                        //horizontal row check
                        for (i=r-1;i>=0;i--)
                        {
                            j=1;
                            if (a[i][j]=='O' && a[i][j]==a[i][j+2] && a[i][j]==a[i][j+4] && a[i][j]==a[i][j+6])
                            {
                                flag=1;
                            }

                            if (a[i][j+2]=='O' && a[i][j+2]==a[i][j+4] && a[i][j+2]==a[i][j+6] && a[i][j+2]==a[i][j+8])

                               flag=1;
                        }



                    // vertical check

                        for (j=1;j<c;j+=2)
                        {

                            i=r-1;
                            if (a[i][j]=='O'&& a[i][j] == a[i-1][j] && a[i][j] == a[i-2][j] && a[i][j] == a[i-3][j] )
                                flag=1;

                            i=r-2;
                            if (a[i][j]=='O'&& a[i][j] == a[i-1][j] && a[i][j] == a[i-2][j] && a[i][j] == a[i-3][j])
                                flag=1;
                        }

                        /*
                        if (a[3][1]=='O'&& a[3][1]==a[2][1]&& a[3][1]==a[1][1]&& a[3][1]==a[0][1])
                            flag=1;

                        if (a[3][3]=='O'&& a[3][3]==a[2][3]&& a[3][3]==a[1][3]&& a[3][3]==a[0][3])
                            flag=1;

                        if (a[3][5]=='O'&& a[3][5]==a[2][5]&& a[3][5]==a[1][5]&& a[3][5]==a[0][5])
                            flag=1;

                        if (a[3][7]=='O'&& a[3][7]==a[2][7]&& a[3][7]==a[1][7]&& a[3][7]==a[0][7])
                            flag=1;

                        */
                        // right to left diagonal
                        if (a[0][9]=='O' && a[0][9]==a[1][7] && a[0][9]==a[2][5] && a[0][9]==a[3][3])
                        {
                            flag=1;
                        }

                        if (a[1][7]=='O' && a[1][7]==a[2][5] && a[1][7]==a[3][3] && a[1][7]==a[4][1])
                        {
                            flag=1;
                        }

                        if (a[0][7]=='O'&& a[0][7]==a[1][5]&& a[0][7]==a[2][3] && a[0][7]==a[3][1])
                        {
                            flag==1;
                        }

                        if (a[1][9]=='O'&& a[1][9]==a[2][7]&& a[1][9]==a[3][5] && a[1][9]==a[4][3])
                        {
                            flag==1;
                        }

                        // left to right diagonal check

                        if (a[0][1]=='O' && a[0][1]==a[1][3] && a[0][1]==a[2][5] && a[0][1]==a[3][7])
                        {
                            flag=1;
                        }

                        if (a[1][3]=='O' && a[1][3]==a[2][5] && a[1][3]==a[3][7] && a[1][3]==a[4][9])
                        {
                            flag=1;
                        }

                        if ( a[0][3]=='O' && a[0][3]==a[1][5] && a[0][3]==a[2][7] && a[0][3] == a[3][9] )
                        {
                            flag==1;
                        }

                        if ( a[1][1]=='O' && a[1][1]==a[2][3] && a[1][1]==a[3][5] && a[1][1] == a[4][7] )
                        {
                            flag==1;
                        }



                        if (flag==1)
                        {
                            printf("\n\n*********** CONGRACTULATIONS PLAYER 1 WON *********** \n\n");
                            break;
                        }


                }

                if (r==6)
                {
                      //horizontal row check
                        for (i=r-1;i>=0;i--)
                        {
                            j=1;
                            if (a[i][j]=='O' && a[i][j]==a[i][j+2] && a[i][j]==a[i][j+4] && a[i][j]==a[i][j+6])
                            {
                               flag=1;
                            }

                            if (a[i][j+2]=='O' && a[i][j+2]==a[i][j+4] && a[i][j+2]==a[i][j+6] && a[i][j+2]==a[i][j+8])
                            {
                                flag=1;
                            }

                            if (a[i][j+4]=='O' && a[i][j+4]==a[i][j+6] && a[i][j+4]==a[i][j+8] && a[i][j+4]==a[i][j+10])
                            {
                                flag=1;
                            }

                        }

                        // vertical check

                        for (j=1;j<c;j+=2)
                        {

                            i=r-1;
                            if (a[i][j]=='O'&& a[i][j] == a[i-1][j] && a[i][j] == a[i-2][j] && a[i][j] == a[i-3][j] )
                                flag=1;

                            i=r-2;
                            if (a[i][j]=='O'&& a[i][j] == a[i-1][j] && a[i][j] == a[i-2][j] && a[i][j] == a[i-3][j])
                                flag=1;

                            i=r-3;
                            if (a[i][j]=='O'&& a[i][j] == a[i-1][j] && a[i][j] == a[i-2][j] && a[i][j] == a[i-3][j])
                                flag=1;
                        }

                        // left to right diagonal

                        if (a[0][1]=='O' && a[0][1]==a[1][3] && a[0][1]==a[2][5] && a[0][1]==a[3][7])
                        {
                            flag=1;
                        }

                        if (a[1][3]=='O' && a[1][3]==a[2][5] && a[1][3]==a[3][7] && a[1][3]==a[4][9])
                        {
                            flag=1;
                        }

                        if (a[2][5]=='O' && a[2][5]==a[3][7] && a[2][5]==a[4][9] && a[2][5]==a[5][11])
                        {
                            flag=1;
                        }

                        if ( a[0][3]=='O' && a[0][3]==a[1][5] && a[0][3]==a[2][7] && a[0][3] == a[3][9] )
                        {
                            flag==1;
                        }

                        if ( a[1][5]=='O' && a[1][5]==a[2][7] && a[1][5]==a[3][9] && a[1][5] == a[4][11] )
                        {
                            flag==1;
                        }

                        if ( a[0][5]=='O' && a[0][5]==a[1][7] && a[0][5]==a[2][9] && a[0][5] == a[3][11] )
                        {
                            flag==1;
                        }

                        if ( a[1][1]=='O' && a[1][1]==a[2][3] && a[1][1]==a[3][5] && a[1][1] == a[4][7] )
                        {
                            flag==1;
                        }

                        if ( a[2][3]=='O' && a[2][3]==a[3][5] && a[2][3]==a[4][7] && a[2][3] == a[5][9] )
                        {
                            flag==1;
                        }

                        if ( a[2][1]=='O' && a[2][1]==a[3][3] && a[2][1]==a[4][5] && a[2][1] == a[5][7] )
                        {
                            flag==1;
                        }

                        // right to left diagonal
                        if (a[0][11]=='O' && a[0][11]==a[1][9] && a[0][11]== a[2][7] && a[0][11]==a[3][5])
                        {
                            flag=1;
                        }

                        if (a[1][9]=='O' && a[1][9]==a[2][7] && a[1][9]== a[3][5] && a[1][9]==a[4][3])
                        {
                            flag=1;
                        }

                        if (a[2][7]=='O' && a[2][7]==a[3][5] && a[2][7]== a[4][3] && a[2][7]==a[5][1])
                        {
                            flag=1;
                        }



                        if (a[0][9]=='O' && a[0][9]==a[1][7] && a[0][9]==a[2][5] && a[0][9]==a[3][3])
                        {
                            flag=1;
                        }

                        if (a[1][7]=='O' && a[1][7]==a[2][5] && a[1][7]==a[3][3] && a[1][7]==a[4][1])
                        {
                            flag=1;
                        }

                        if (a[0][7]=='O'&& a[0][7]==a[1][5]&& a[0][7]==a[2][3] && a[0][7]==a[3][1])
                        {
                            flag==1;
                        }

                        if (a[1][11]=='O' && a[1][11]==a[2][9] && a[1][11]== a[3][7] && a[1][11]==a[4][5])
                        {
                            flag=1;
                        }

                        if (a[2][9]=='O' && a[2][9]== a[3][7] && a[2][9]==a[4][5] && a[2][9]==a[5][3])
                        {
                            flag=1;
                        }

                        if (a[2][11]=='O' && a[2][11]==a[3][9] && a[2][11]==a[4][7] && a[2][11]==a[5][5])
                        {
                            flag=1;
                        }

                        if (flag==1)
                        {
                            printf("\n\n*********** CONGRACTULATIONS PLAYER 1 WON *********** \n\n");
                            break;
                        }
                }

            }// end for player 1

            // for player 2

            if (turncounter%2!=0)
            {
                printf("\n PLAYER 2 Turn \n");
                system("color 01");
                printf("Enter the column no where you want to put the piece\n ");
                printf("Remember that no of columns begin from 1 and are only odd nos \n(for eg if you enter 4 columns then the column nos will be 1,3,5,7 i.e first 4 odd nos)\n -> ");
                scanf("%d",&colno);

                for (i=r-1;i>=0;i--)
                {
                    // checkes if the row is completely filled or not
                    if (a[0][colno]=='O'||a[0][colno]=='X')
                    {
                        printf("The row is filled and you skipped your chance \n");
                        break;
                    }
                    // places a O for the player 1 in the entered column no
                    else if (a[i][colno]=='_')
                    {
                        a[i][colno]='X';
                        break;
                    }
                }

                // printS updated board after each go
                printf("\n********* THE UPDATED BOARD IS *********\n");
                for (i=0;i<r;i++)
                {
                    for (j=0;j<c;j++)
                    {
                        printf("%c",a[i][j]);
                    }
                    printf("\n");
                }



                // checking for winning condition for player 2




                if (r==4)
                {
                        //horizontal row check
                        for(i=r-1;i>=0;i--)
                        {
                            j=1;
                            if (a[i][j]=='X' && a[i][j]==a[i][j+2] && a[i][j]==a[i][j+4] && a[i][j]==a[i][j+6])
                            {
                                flag=1;
                            }
                        }

                    // vertical check

                    for (j=1;j<c;j+=2)
                        {
                                i=r-1;
                                if (a[i][j]=='X' && a[i][j]==a[i-1][j] && a[i][j] == a[i-2][j] && a[i][j] == a[i-3][j])
                                {
                                    flag=1;
                                }
                        }

                        // left to right diagonal check
                        if ( a[0][1]=='X' && a[0][1]==a[1][3] && a[0][1]==a[2][5] && a[0][1] == a[3][7])
                        {
                            flag=1;
                        }

                        // right to left diagonal check
                        else if (a[0][7]=='X'&& a[0][7]==a[1][5]&& a[0][7]==a[2][3] && a[0][7]==a[3][1])
                        {
                            flag=1;
                        }

                        if (flag==1)
                        {
                            printf("\n\n*********** CONGRACTULATIONS PLAYER 2 WON  *********** \n\n");
                            break;
                        }

                }

                if (r==5)
                {
                        //horizontal row check
                        for (i=r-1;i>=0;i--)
                        {
                            j=1;
                            if (a[i][j]=='X' && a[i][j]==a[i][j+2] && a[i][j]==a[i][j+4] && a[i][j]==a[i][j+6])
                            {
                                flag=1;
                            }

                            if (a[i][j+2]=='X' && a[i][j+2]==a[i][j+4] && a[i][j+2]==a[i][j+6] && a[i][j+2]==a[i][j+8])

                               flag=1;
                        }

                    // vertical check

                        for (j=1;j<c;j+=2)
                        {

                            i=r-1;
                            if (a[i][j]=='X'&& a[i][j] == a[i-1][j] && a[i][j] == a[i-2][j] && a[i][j] == a[i-3][j] )
                                flag=1;

                            i=r-2;
                            if (a[i][j]=='X'&& a[i][j] == a[i-1][j] && a[i][j] == a[i-2][j] && a[i][j] == a[i-3][j])
                                flag=1;
                        }

                        // right to left diagonal

                        if (a[0][9]=='X' && a[0][9]==a[1][7] && a[0][9]==a[2][5] && a[0][9]==a[3][3])
                        {
                            flag=1;
                        }

                        if (a[1][7]=='X' && a[1][7]==a[2][5] && a[1][7]==a[3][3] && a[1][7]==a[4][1])
                        {
                            flag=1;
                        }

                        if (a[0][7]=='X'&& a[0][7]==a[1][5]&& a[0][7]==a[2][3] && a[0][7]==a[3][1])
                        {
                            flag==1;
                        }

                        if (a[1][9]=='X'&& a[1][9]==a[2][7]&& a[1][9]==a[3][5] && a[1][9]==a[4][3])
                        {
                            flag==1;
                        }

                        // left to right diagonal check

                        if (a[0][1]=='X' && a[0][1]==a[1][3] && a[0][1]==a[2][5] && a[0][1]==a[3][7])
                        {
                            flag=1;
                        }

                        if (a[1][3]=='X' && a[1][3]==a[2][5] && a[1][3]==a[3][7] && a[1][3]==a[4][9])
                        {
                            flag=1;
                        }

                        if ( a[0][3]=='X' && a[0][3]==a[1][5] && a[0][3]==a[2][7] && a[0][3] == a[3][9] )
                        {
                            flag==1;
                        }

                        if ( a[1][1]=='X' && a[1][1]==a[2][3] && a[1][1]==a[3][5] && a[1][1] == a[4][7] )
                        {
                            flag==1;
                        }



                        if (flag==1)
                        {
                            printf("\n\n*********** CONGRACTULATIONS PLAYER 2 WON *********** \n\n");
                            break;
                        }


                }

                if (r==6)
                {
                      //horizontal row check
                        for (i=r-1;i>=0;i--)
                        {
                            j=1;
                            if (a[i][j]=='X' && a[i][j]==a[i][j+2] && a[i][j]==a[i][j+4] && a[i][j]==a[i][j+6])
                            {
                               flag=1;
                            }

                            if (a[i][j+2]=='X' && a[i][j+2]==a[i][j+4] && a[i][j+2]==a[i][j+6] && a[i][j+2]==a[i][j+8])
                            {
                                flag=1;
                            }

                            if (a[i][j+4]=='X' && a[i][j+4]==a[i][j+6] && a[i][j+4]==a[i][j+8] && a[i][j+4]==a[i][j+10])
                            {
                                flag=1;
                            }

                        }

                        // vertical check

                        for (j=1;j<c;j+=2)
                        {

                            i=r-1;
                            if (a[i][j]=='X'&& a[i][j] == a[i-1][j] && a[i][j] == a[i-2][j] && a[i][j] == a[i-3][j] )
                                flag=1;

                            i=r-2;
                            if (a[i][j]=='X'&& a[i][j] == a[i-1][j] && a[i][j] == a[i-2][j] && a[i][j] == a[i-3][j])
                                flag=1;

                            i=r-3;
                            if (a[i][j]=='X'&& a[i][j] == a[i-1][j] && a[i][j] == a[i-2][j] && a[i][j] == a[i-3][j])
                                flag=1;
                        }

                        // left to right diagonal

                        if (a[0][1]=='X' && a[0][1]==a[1][3] && a[0][1]==a[2][5] && a[0][1]==a[3][7])
                        {
                            flag=1;
                        }

                        if (a[1][3]=='X' && a[1][3]==a[2][5] && a[1][3]==a[3][7] && a[1][3]==a[4][9])
                        {
                            flag=1;
                        }

                        if (a[2][5]=='X' && a[2][5]==a[3][7] && a[2][5]==a[4][9] && a[2][5]==a[5][11])
                        {
                            flag=1;
                        }

                        if ( a[0][3]=='X' && a[0][3]==a[1][5] && a[0][3]==a[2][7] && a[0][3] == a[3][9] )
                        {
                            flag==1;
                        }

                        if ( a[1][5]=='X' && a[1][5]==a[2][7] && a[1][5]==a[3][9] && a[1][5] == a[4][11] )
                        {
                            flag==1;
                        }

                        if ( a[0][5]=='X' && a[0][5]==a[1][7] && a[0][5]==a[2][9] && a[0][5] == a[3][11] )
                        {
                            flag==1;
                        }

                        if ( a[1][1]=='X' && a[1][1]==a[2][3] && a[1][1]==a[3][5] && a[1][1] == a[4][7] )
                        {
                            flag==1;
                        }

                        if ( a[2][3]=='X' && a[2][3]==a[3][5] && a[2][3]==a[4][7] && a[2][3] == a[5][9] )
                        {
                            flag==1;
                        }

                        if ( a[2][1]=='X' && a[2][1]==a[3][3] && a[2][1]==a[4][5] && a[2][1] == a[5][7] )
                        {
                            flag==1;
                        }

                        // right to left diagonal
                        if (a[0][11]=='X' && a[0][11]==a[1][9] && a[0][11]== a[2][7] && a[0][11]==a[3][5])
                        {
                            flag=1;
                        }

                        if (a[1][9]=='X' && a[1][9]==a[2][7] && a[1][9]== a[3][5] && a[1][9]==a[4][3])
                        {
                            flag=1;
                        }

                        if (a[2][7]=='X' && a[2][7]==a[3][5] && a[2][7]== a[4][3] && a[2][7]==a[5][1])
                        {
                            flag=1;
                        }



                        if (a[0][9]=='X' && a[0][9]==a[1][7] && a[0][9]==a[2][5] && a[0][9]==a[3][3])
                        {
                            flag=1;
                        }

                        if (a[1][7]=='X' && a[1][7]==a[2][5] && a[1][7]==a[3][3] && a[1][7]==a[4][1])
                        {
                            flag=1;
                        }

                        if (a[0][7]=='X'&& a[0][7]==a[1][5]&& a[0][7]==a[2][3] && a[0][7]==a[3][1])
                        {
                            flag==1;
                        }

                        if (a[1][11]=='X' && a[1][11]==a[2][9] && a[1][11]== a[3][7] && a[1][11]==a[4][5])
                        {
                            flag=1;
                        }

                        if (a[2][9]=='X' && a[2][9]== a[3][7] && a[2][9]==a[4][5] && a[2][9]==a[5][3])
                        {
                            flag=1;
                        }

                        if (a[2][11]=='X' && a[2][11]==a[3][9] && a[2][11]==a[4][7] && a[2][11]==a[5][5])
                        {
                            flag=1;
                        }

                        if (flag==1)
                        {
                            printf("\n\n*********** CONGRACTULATIONS PLSYER 2 WON *********** \n\n");
                            break;
                        }
                }
            }



            turncounter++;
            if (flag==0 && turncounter == totalturns)
            {
                printf(" \n\nIT's A DRAW -_- \n\n");
            }
        }

        x=0;// to terminate loop
    }




}

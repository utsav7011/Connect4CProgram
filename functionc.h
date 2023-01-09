void formboard(char a[][] , int r,int c )
{
    int i=0,j=0;
    for (i=0;i<r;i++)
    {
        for (j=0;j<c;j++)
        {
            if (j%2==0)
                a[i][j]='|';
        }
        else if (j%2!=0)
        {
            a[i][j]='_';
        }
    }
}

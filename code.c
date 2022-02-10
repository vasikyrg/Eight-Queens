#include <stdio.h>
#include <stdlib.h>
int queens (int** pin, int n);

int main()
{
    int row ,col;
    int N=8;
    int** pin=calloc(N,sizeof(int*));
    if(!pin)
    {
        printf("Adynamia desmeusis mnimis");
        exit(0);
    }
     for(unsigned int i=0;i<8;i++)
    {
        pin[i]=calloc(N,sizeof(int));
        if(!pin[i])
        {
            printf("Adynamia desmeusis mnimis");
            exit(0);
        }
    }
    for(unsigned int i=1;i<=N;i++)
    {
        printf("Pou thes na einai h Vasilissa %d?\n", i);
        printf("Row: ");
        scanf("%d", &row);
        printf("Column: ");
        scanf("%d", &col);
        if(pin[row-1][col-1]==1)
        {
            do
            {
                printf("Dwse allh thesh gia thn Vasilissa %d?\n", i);
                printf("Row: ");
                scanf("%d", &row);
                printf("Column: ");
                scanf("%d", &col);
            }while(pin[row-1][col-1]==1);
        }
        pin[row-1][col-1]=1;
    }
    int result = queens(pin, N);
    if (result==0)
        printf("Oi theseis pou proteinete den epalithevoun kapoia lysh.\n");
    else if(result==1)
        printf("Oi theseis pou proteinete epalithevoun kapoia lysh.\n");
    for(unsigned int i=0;i<N;i++)
        free(pin[i]);
    free(pin);
    return 0;
}

int queens (int** pin, int n)
{
    int sum_row, sum_col, sum_diag;
    int i, j, d;
    for (i=0;i<n;++i)
    {
        sum_row=0;
        sum_col=0;
        for (j=0;j<n;++j)
        {
            sum_row+=pin[i][j];
            sum_col+=pin[j][i];
        }
        if (sum_row>1 || sum_col>1)
            return 0;
    }
    for (d=1;d<n;++d)
    {
        sum_diag=0;
        j=0;
        for (i=d;i>=0;--i)
        {
            sum_diag+=pin[i][j];
            j++;
        }
        if (sum_diag>1)
            return 0;
    }
    for (d=0;d<n-2;++d)
    {
        sum_diag=0;
        j=n-1;
        for (i=1+d;i<n;++i)
        {
            sum_diag+=pin[j][i];
            j--;
        }
        if (sum_diag>1)
            return 0;
    }
    for (d=n-2;d>=0;--d)
    {
        sum_diag=0;
        j=0;
        for (i=d;i<n;++i)
        {
            sum_diag+=pin[i][j];
            j++;
        }
        if (sum_diag>1)
            return 0;
    }
    for (d=0;d<n-2;++d)
    {
        sum_diag=0;
        j=0;
        for (i=1+d;i<n;++i)
        {
            sum_diag+=pin[j][i];
            j++;
        }
        if (sum_diag>1)
            return 0;
    }
    return 1;
}



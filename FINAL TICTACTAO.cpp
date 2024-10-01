#include<stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>

bool win_condition(char a[3][3], char x)
{
    for (int i=0;i<3;i++)
        {
            if (a[i][0]==x&&a[i][1]==x&&a[i][2]==x)
                {
                return true;
                }
        }
        for (int j=0;j<3;j++)
        {
            if (a[0][j] == x && a[1][j] == x && a[2][j] == x)
            {
                return true;
            }
        }
        if ((a[0][0] == x && a[1][1] == x && a[2][2]==x)||(a[0][2] == x && a[1][1] == x && a[2][0]==x))
        {
            return true;
        }
        return false;
}

void print_array(char a[3][3])
{
    for (int i=0;i<3;i++)
    {
        for (int j=0;j<3;j++)
        {
            printf("%c ",a[i][j]);
        }
        printf("\n");
    }
}

int main(){
	char z[3][3],A[10],B[10];

	for(int a=0;a<3;a++)
	{
		for(int b=0;b<3;b++)
		{
			z[a][b]='_';
		}
	}
	printf("ENTER THE NAME OF PLAYER 1 ");
	gets(A);
	printf("\nENTER THE NAME OF PLAYER 2 ");
	gets(B);
	system("cls");
	print_array(z);
	int i=1;
	while(i<=8)
	{
	    int i,j,k,l;
	   	puts(A);
	   	do{
			printf("ENTER THE COORDINATE ");
			scanf("%d %d",&i,&j);
			if(z[i][j]=='x' || z[i][j]=='o')
			{
				printf("place already filled \n");
			}	
			else if(i>2 || j>2)
			{
				printf("ENTER CORRECT COORDINATE\n");
			}		
		}while(z[i][j]=='x' || z[i][j]=='o');
		z[i][j]='x';
		system("cls");
		print_array(z);
		printf("\n\n\n\n\n");
		if (win_condition(z,'x'))
            {
                printf("Player 1 wins!\n");
                return 0;
            }
		puts(B);            
		do{
			printf("ENTER THE COORDINATE ");
			scanf("%d %d",&k,&l);
			if(z[k][l]=='x' || z[k][l]=='o')
			{
				printf("place already filled \n");
			}
			else if(k>2 || l>2)
			{
				printf("ENTER CORRECT COORDINATE\n");
			}		
		}while(z[k][l]=='x' || z[k][l]=='o');
		z[k][l]='o';
		system("cls");
		print_array(z);
		printf("\n\n\n\n\n");
		if (win_condition(z,'o'))
            {
                printf("Player 2 wins!\n");
                return 0;
            }
        i++;
	}
	return 0;
}

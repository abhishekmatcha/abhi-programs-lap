#include<stdio.h>
void down();
void cold(int );
void dpush(int);
void rowl(int );
void rowr(int );
void rpush(int);
void lpush(int );
void upush(int);

int a[4][4];
void column(int);
void upush();
void left()
	{
	column(0);
	column(1);
	column(2);
	column(3);
	}
	void column(int j)
	{
	int i,k;
		upush(j);
		for(i=0;i<3;)
		{
		k=i+1;
		if(a[j][i]==a[j][k])
			{
			a[j][i]=2*a[j][k];
			a[j][k]=0;
			i+=2;
			}
		else
			i++;
		}
		upush(j);
	}
	void right()
	{
	 cold(0);
	 cold(1);
	 cold(2);
	 cold(3);
	}
	void cold(int j)
	{
	int i,k;
	dpush(j);
	for(i=3;i>0;)
	{
	       k=i-1;
		if(a[j][i]==a[j][k])
		{
		a[j][i]=2*a[j][k];
		a[j][k]=0;
		i=i-2;
		}
		else
		i--;
	}
	dpush(j);
	}
	void up()
	{
	rowl(0);
	rowl(1);
	rowl(2);
	rowl(3);
	}
	void rowl(int j)
	{
	int i,k;
	lpush(j);
	for(i=0;i<3;)
	{
		k=i+1;
		if(a[i][j]==a[k][j])
		{
		a[i][j]=2*a[i][j];
		a[k][j]=0;
		i=i+2;
		}
		else
		i++;
	}
	lpush(j);
	}

		
	void upush(int j)
	{
	int i,h=0;
	for(i=0;i<=3;i++)
	{
		if(a[j][i]!=0)
			a[j][h++]=a[j][i];
	}
	while(h<=3)
	a[j][h++]=0;
	}
	void dpush(int j)
	{
	int i,h=3;
	for(i=3;i>=0;i--)
	{
		if(a[j][i]!=0)
			a[j][h--]=a[j][i];
	}
	while(h>=0)
	a[j][h--]=0;
	}
	void lpush(int j)
	{
	int i,h=0;
	for(i=0;i<=3;i++)
	{
		if(a[i][j]!=0)
			a[h++][j]=a[i][j];
	}
	while(h<=3)
	a[h++][j]=0;
	}
	void down()
	{
	rowr(0);
	rowr(1);
	rowr(2);
	rowr(3);
	}
	void rowr(int j)
	{
	int i,k;
	rpush(j);
	for(i=3;i>0;)
	{
	k=i-1;
		if(a[i][j]==a[k][j])
		{
		a[i][j]=2*a[k][j];
		a[k][j]=0;
		i=i-2;
		}
		else
		i--;
	}
	rpush(j);
	}
	void rpush(int j)
	{
	int i,h=3;
	for(i=3;i>=0;i--)
	{
		if(a[i][j]!=0)
		a[h--][j]=a[i][j];
	}
	while(h>=0)
	a[h--][j]=0;
	}
int main()
{
    int i,j,arrow;
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    scanf("%d",&arrow);
    switch(arrow)
    {
        case 0:up();break;
        case 1: left();break;
        case 2:down();break;
        case 3: right();break;
    }
     for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            printf("%d ",a[i][j]);
        }printf("\n");
    }
    return 0;
}


#include<iostream>
#include<conio.h>
using namespace std;
char a[3][3]={'1','2','3','4','5','6','7','8','9'};
int check(char c)				// Function to check whether any player have won.
{
	int i,j,k;
	for(i=0;i<3;i++)			//HORIZONTAL
	{
		k=0;
		for(j=0;j<3;j++)
		{
			if(a[i][j]==c)
				k++;
		}
		if(k==3)
			return 1;
	}
	for(i=0;i<3;i++)			//VERTICAL
	{
		k=0;
		for(j=0;j<3;j++)
		{
			if(a[j][i]==c)
				k++;
		}
		if(k==3)
			return 1;
	}
	k=0;
	for(i=0;i<3;i++)			//MAIN DIAGONAL
	{
		if(a[i][i]==c)
			k++;
	}
	if(k==3)
		return 1;
	k=0;
	for(i=0;i<3;i++)			//SIDE DIAGONAL
	{
		if(a[i][2-i]==c)
			k++;
	}
	if(k==3)
		return 1;
}
int main()
{
	
	int i,j,k,p=1,f=0;
	do
	{
		system("cls");
		cout<<"\t\t\tTIC-TAC-TOE\n";
		cout<<"\n\nPLAYER 1- \'X' \t\t PLAYER 2- \'O'\n\n";
		for(i=0;i<3;i++)
		{
			cout<<"   |   |\n";
			for(j=0;j<3;j++)
			{
				cout<<" "<<i*3+j+1<<" ";
				if(j<2)
				{
					cout<<"|";
				}
			}
			cout<<"\n";
			if(i<2)
			{
				cout<<"___|___|___\n";
			}
		}
		cout<<"\n";
		for(i=0;i<3;i++)
		{
			cout<<"   |   |\n";
			for(j=0;j<3;j++)
			{
				if(a[i][j]=='X'||a[i][j]=='O')
					cout<<" "<<a[i][j]<<" ";
				else
					cout<<"   ";
				if(j<2)
				{
					cout<<"|";
				}
			}
			cout<<"\n";
			if(i<2)
			{
				cout<<"___|___|___\n";
			}
		}
		cout<<"   |   |\n";
		if(f!=0)
			break;
		cout<<"\nEnter a number player "<<p<<":";
		cin>>k;
		if(k>9||a[(k-1)/3][(k-1)%3]=='X'||a[(k-1)/3][(k-1)%3]=='O')
		{
			cout<<"INVALID NUMBER!!\a";
			continue;
		}
		if(p==1)
		{
			a[(k-1)/3][(k-1)%3]='X';
			p=2;
		}
		else
		{
			a[(k-1)/3][(k-1)%3]='O';
			p=1;
		}
		if(check('X')==1)
		{
			f=1;
		}
		if(check('O')==1)
		{
			f=2;
		}
		k=0;
		for(i=0;i<3;i++)
		{
			for(j=0;j<3;j++)
			{
				if(a[i][j]=='X'||a[i][j]=='O')
					k++;
			}
		}
		if(k==9&&f==0)
		{
			f=3;
		}
	}while(1);
	cout<<"\n\nGAME OVER!!\n";
	if(f==1)
		cout<<"PLAYER 1 WON THE GAME!!!";
	else if(f==2)
		cout<<"PLAYER 2 WON THE GAME!!!";
	else
		cout<<"GAME DRAW!!!";
}

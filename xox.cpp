#include<iostream>
using namespace std;

int grid[3][3]={0},n_of_games, xwin=0,ywin=0;

void cleargrid()
{
  for(int i=0;3>i;i++)
    for(int j=0;3>j;j++)
      grid[i][j]=0;
}

bool solved(int x)
{
  for (int i=0;3>i;i++)
  {
    int count=0;
    for(int j=0;3>j;j++)
    {
      if(x==grid[i][j])
        count++; 
    }
    if (count==3)
      return true;
  }
  for (int i=0;3>i;i++)
  {
    int count=0;
    for(int j=0;3>j;j++)
    {
      if(x==grid[i][j])
        count++; 
    }
    if (count==3)
      return true;
  }
  int count=0;
  for(int i=0;3>i;i++)
    if(x==grid[i][i])
        count++;
    if (count==3)
      return true; 
    else
      count=0; 
  for(int i=0;3>i;i++)
      if(x==grid[i][i])
        count++;
  if (count==3)
      return true; 
    else
      return false;
}

void printgrid()
{
  for(int i=0;3>i;i++)
  {
    for (int j = 0; j < 3; j++)
    {
      cout<<"|";
      if(grid[i][j]==0)
        cout<<" ";
      else if(grid[i][j]==1)
        cout<<"x";
      else
        cout<<"o";
      cout<<"|";
    }
    cout<<endl;
  }
}

int main(int argc, char const *argv[])
{
  cout<<"enter the number fo games\t";
  cin>>n_of_games;
  for(int i=0;n_of_games>i;i++)
  {
    cleargrid();
    cout<<endl<<"game\t"<<i+1<<endl<<endl;
    for(int j=0;9>j;j++)
    {
      printgrid();
      int x_ax,y_ax;
      cout<<"enter the location of x,y";
      cin>>x_ax>>y_ax;
      if(grid[x_ax][y_ax]==0){
        if(j%2==0)
        {
        grid[x_ax][y_ax]=1;
        if(solved(1))
        {
          cout<<"X won this game"<<endl;
          printgrid();
          xwin++;
          break;
        }
      }
      else{
        grid[x_ax][y_ax]=2;
        if(solved(2))
        {
          cout<<"o won this game"<<endl;
          printgrid();
          ywin++;
          break;
        }
      }
    }
      else
      {
        cout<<"enter a valid location"<<endl;
        j-=1;
        continue;
      }
    }
  }
  cout<<"games won by x : "<<xwin<<endl;
  cout<<"games won by y : "<<ywin<<endl;
  return 0;
}

// Program to implement and solve n-queens problems using the back tracking algorithm.
#include<iostream>
#include<math.h>
using namespace std;
int place(int row,int column);
void print(int n); 
int board[30],count;
void queen(int row,int n);


int main()
{
 int n,i,j;
 cout<<" - N Queens Problem Using Backtracking -";
 cout<<"\n\nEnter number of Queens:";
 cin>>n;
 queen(1,n);
 return 0;
}
 
void print(int n)  
//function for printing the optimal solution 
{
 int i,j;
 cout<<"\n\nSolution %d:\n\n"<<++count;
 for(i=1;i<=n;++i)
 {
 	 cout<<i<"  ";
 }
 
 for(i=1;i<=n;++i)
 {
    cout<<"\n\n"<<i<<"  ";
    for(j=1;j<=n;++j) //for nxn board
    {
      if(board[i]==j)
      {
      	cout<<"\tQ"; //queen at i,j position
	  }
      else
      {
      	cout<<"\t-"; //empty slot
	  }
  }
 }
}
 
/*funtion to check conflicts
If no conflict for desired postion returns 1 otherwise returns 0*/
int place(int row,int column)
{
 int i;
 for(i=1;i<=row-1;++i)
 {
  //checking column and digonal conflicts
  if(board[i]==column)
   return 0;
  else
   if(abs(board[i]-column)==abs(i-row))
    return 0;
 }
 
 return 1; //no conflicts
}
 
//function to check for proper positioning of queen
void queen(int row,int n)
{
 int column;
 for(column=1;column<=n;++column)
 {
  if(place(row,column))
  {
   board[row]=column; //no conflicts so place queen
   if(row==n) //dead end
    print(n); //printing the board configuration
   else //try queen with next position
    queen(row+1,n);
  }
 }
}

// Program to perfrom matrix multiplication ( of size n ) and finding the minimum cost for the same.


#include<iostream>
#include<conio.h>

using namespace std;

void print(int *s,int i,int j,int n)
//to print the optimal cost for multiplying matrix of size n
{
if (i == j)
cout<<"A"<<i;
else
   {
      cout<<"( ";
      print((int *)s,i, *((s+i*n) + j),n);
      print((int *)s,*((s+i*n) + j) + 1, j,n);
      cout<<" )";
   }
}
  
void matrixChainMultiplication(int array[],int n)
// tp perform the matrix multiplication
{
   int m[n+1][n+1];
   int s[n+1][n+1];
   for(int a=0;a<n+1;a++)
   {
   	  for(int b=0;b<n+1;b++)
   	  {
   	  	m[a][b]=0;
	  }
   }

   for(int a=0;a<n+1;a++)
   {
   	  for(int b=0;b<n+1;b++)
   	  {
   	  	s[a][b]=0;
	  }
   }
   int j,q;
 
    for (int d=1; d<n; d++)
    {
        for (int i=1; i<n+1-d; i++)
        {
            j = i+d;
            m[i][j] = 32767;  //infinity
 
            for (int k=i; k<=j-1; k++)
            {
                q = m[i][k] + m[k+1][j] + (array[i-1]) * (array[k] ) * (array[j]);
                if (q < m[i][j])
                {
                    m[i][j] = q;
		            s[i][j] =k;   
                }
            }
        }
    }
 
    cout<<"Cost Matrix of Multiplication :"<<endl;
    
	for(int a=0;a<n+1;a++)
   {
   	  cout<<endl;
   	  for(int b=0;b<n+1;b++)
   	  {
   	  	cout<<m[a][b]<<"  ";
	  }
   }    
    cout<<endl;
    cout<<"Minimum Cost Required : "<<m[1][n]<<endl;
    cout<<"Sequence of multiplication is : ";
    print((int *)s,1,n,n+1);   
   
}


int main()
{
	int n,row,coloumn;
	cout<<"Enter no. of matrix you want to multiply : ";
	cin>>n;
	cout<<endl;
    int array[n+1];
	cout<<"Enter the size of 1 matrix "<<endl;
	cout<<"row : ";
	cin>>row;
	cout<<"coloumn : ";
	cin>>coloumn;
	cout<<endl;
	array[0]=row;
	array[1]=coloumn;
	
	for(int i=2;i<n+1;i++)
	{
	  cout<<"Enter the size of "<<i<<" matrix "<<endl;
	  cout<<"row : ";
	  cin>>row;
	  cout<<"coloumn : ";
	  cin>>coloumn;
	  if(row != array[i-1])
	  {
	  	cout<<"matrix multiplication is not possible because coloumn of first matrix is not equal to row of first matrix !, ended operation!!";
	  	cout<<endl;
	  	return 0;
	  }
	  array[i]=coloumn;
	}
	cout<<"you enter following matrix ----->"<<endl;
	for(int i=0;i<n;i++)
	{
		cout<<i+1<<" : matrix is "<<array[i]<<" X "<<array[i+1]<<endl;
	}
	matrixChainMultiplication(array,n);
	return 0 ;
}

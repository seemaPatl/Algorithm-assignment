//Program to check if the sequence is present the present string.
using namespace std;
#include<string>
#include<iostream>
#include<vector>


bool check_sbseq(vector<string> A,vector<string> B)  
{ // function to check if the sequnce is present in the string or not
    int m=A.size();
    int n=B.size();
    if(m<n)
        return false;
    int i=0;
    int j=0;
    while(i<m&&j<n)
    {
        if(!B[j].compare(A[i]))
        {
            i++;
            j++;
        }
        else
        i++;
    }
    if (j==n)
    {
        return 1;
    }
    else
    return 0;
}


int main()
{
    vector<string> a;
    vector<string> b;
    cout<<"Enter events A:";
    bool acontinue=true;
    do
    {  // to ask for the sequence by the user
        string atemp;
        getline(cin,atemp);
        if(!atemp.compare("exit"))
        {
            acontinue=false;
        }
        else
            a.push_back(atemp);
    }while(acontinue);
   
    cout<<"Enter events B:";
    bool bcontinue=true;
    do                                       
    { // to ask for the sequence by the user
        string btemp;
        getline(cin,btemp);
        if(!btemp.compare("exit"))
        {
            bcontinue=false;
        }
        else
            b.push_back(btemp);
    }while(bcontinue);
   
    if(check_sbseq(a,b))
    cout<<"\nyes,list of events b is a subsequence of events a";
    else
    cout<<"no";

    return 0;
}

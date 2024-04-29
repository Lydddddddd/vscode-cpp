#include<iostream>
#include "SeqStack.h"

using namespace std;

void test(int &sum)
{
    int x;
    cin>>x;
    if(x==0)
    {
        sum=0;
    }
    else
    {
        test(sum);
        sum+=x;
    }
    cout<<sum;
}

void test()
{
    SeqStack<int> l;
    int x=1;
    int sum=0;
    int e;
    while(x!=0)
    {
        cin>>x;
        l.Push(x);
    }
    while(!l.IsEmpty())
    {
        l.Pop(e);
        sum+=e;
        cout<<sum;
    }
}

int main()
{
    int sum;
    test(sum);
    return 0;
}
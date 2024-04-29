#include<iostream>
#include "LinkQueue.h"

using namespace std;

void yanghui(int n)
{
    LinkQueue<int> l;
    int s,t=0;  //t为s的前一位
    l.EnQueue(1); l.EnQueue(1); l.EnQueue(0);
    cout<<"1"<<"\t"<<"1";
    for(int i=2;i<=n;i++)
    {
        cout<<endl;
        for(int j=1;j<=i+1;j++)
        {
            l.DelQueue(s);
            l.EnQueue(t+s);
            cout<<t+s<<"\t";
            t=s;
        }
        l.EnQueue(0);
    }
}

int main()
{
    int n;
    cin>>n;
    yanghui(n);
    return 0;
}
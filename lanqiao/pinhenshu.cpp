#include<iostream>
#include<vector>

using namespace std;

int main()
{
    int n,m;
    long x,a[100010],b[100010];
    cin>>n>>m>>x;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=n;i++)
    {
        bool flag=false;
        for(int j=i+1;j<=n;j++)
        {
            if((a[i]^a[j])==x)
            {
                flag=true;
                b[i]=j;
            }
            break;
        }
        if(!flag)
        {
            b[i]=-1;
        }
    }
    for(int i=1;i<=m;i++)
    {
        int l,r;
        cin>>l>>r;
        bool flag=false;
        for(int j=l;j<=r;j++)
        {
            if(b[j]!=-1 && b[j]<=r)
            {
                flag=true;
                cout<<"yes"<<endl;
                break;
            }
        }
        if(!flag)
        {
           cout<<"no"<<endl; 
        }
    }
    return 0;
}
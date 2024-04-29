#include<iostream>
#include<string>

using namespace std;

int main()
{
    int n;
    cin>>n;
    while(n--)
    {
        int x,y;
        string s;
        cin>>x>>s>>y;
        if(s=="KB")
        {
            x*=1024;
        }
        else if(s=="MB")
        {
            x*=1024;
            x*=1024;
        }
        int ans;
        ans=x/y;
        cout<<ans<<endl;
    }
    return 0;
}
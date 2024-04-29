#include<iostream>

using namespace std;

int main()
{
    long long aa;
    long long ans=0;
    for(long long a=11;a<1e8;a++)
    {
        string str=to_string(a);
        int num=str.length();
        int num1=0;
        int num2=0;
        if(num%2!=0)
        {
            continue;
        }
        else
        {
            for(int i=1;i<=num/2;i++)
            {
                num1+=str[i-1]-'0';
            }
            for(int i=num/2+1;i<=num;i++)
            {
                num2+=str[i-1]-'0';                
            }
        }
        if(num1==num2)
        {
            ans++;
        }
    }
    cout<<ans;
    return 0;
}
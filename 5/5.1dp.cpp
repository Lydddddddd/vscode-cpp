//dp 求最大公共子串 O(n^2)
#include<iostream>
#include<vector>

using namespace std;

string find_max_sub_string(const string& S,const string& T)
{
    vector<vector<int>> dp(S.length()+1,vector<int>(T.length()+1));  //储存以i，j结尾的最大公共子串长度
    int maxlength;  //最大长度
    int pos;  //当前位置
    string ans;  //答案
    for(int i=0;i<=S.length();i++)  //初始化dp
    {
        if(S[i]==T[0])
        {
            dp[i][0]=1;
            maxlength=1;
            pos=i;
        }
        else
        {
            dp[i][0]=0;
        }
    }
    for(int i=0;i<=T.length();i++)
    {
        if(S[0]==T[i])
        {
            dp[0][i]=1;
            maxlength=1;
            pos=0;
        }
        else
        {
            dp[0][i]=0;
        }
    }

    for(int i=1;i<=S.length();i++)
    {
        for(int j=1;j<=T.length();j++)
        {
            if(S[i]==T[j])
            {
                dp[i][j]=dp[i-1][j-1]+1;
                if(dp[i][j]>maxlength)
                {
                    maxlength=dp[i][j];
                    pos=i;
                }
            }
            else
            {
                dp[i][j]=0;
            }
        }
    }
    ans=S.substr(pos-maxlength+1,maxlength);
    return ans;
}

int main()
{
    string S,T,ans;
    cin>>S>>T;
    //S="a";
    //T="eacsdd";
    ans=find_max_sub_string(S,T);
    cout<<"最长公共子串："<<ans<<endl;
    return 0;
}
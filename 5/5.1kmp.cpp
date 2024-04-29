//KMP
#include<iostream>

using namespace std;

// KMP匹配算法
void GetFailure(const string &pat, int f[],int ff[])
// 操作结果: 求模式串pat的失效函数值
{
	f[0]=-1;				             // 初始f[0]的值为-1
	int j = 0, k = -1;		
	while (j < pat.length() - 1)
		if (k == -1 || pat[k] == pat[j])	
			f[++j]=++k;
		else		                     // pat[k]与pat[j]不匹配
			k = f[k];		             // 寻求新的匹配字符
	j=1;
	ff[0]=-1;
	k=0; 
	while(j<pat.length()-1)
	{	
		if(k==-1||pat[k]!=pat[j])
		{
			ff[j++]=k;
			k=f[j];
		}
		else
		{
			k=f[k];
		}
	}
}

string find_max_sub_string(const string& S,const string& T)
{
    string pat,ob,ans;
    int t=0;
    int maxm=-1;
    int pos;
	int *f = new int[pat.length()];      // 为失效函数值数组f分配空间
	int *ff = new int[pat.length()];      // 优化后的失效函数
    while(S.length()-t>maxm)
    {
        pat=S.substr(t);
	    GetFailure(pat, f, ff);				     // 求模式串pat的f数组的元素值
	    int i = 0, j = 0;			
	    while (i < ob.length() && j < pat.length() && pat.length() - j <= ob.length() - i)
        {
            if (j == -1 || pat[j] == ob[i])		
            {
		        i++; j++;			             // 模式串pat与目标串ob的当前位置向后移
	        }
	        else    // pat[j]与ob[i]不匹配
            {
                if(j > maxm)
                {
                    maxm = j;
                    pos=j+t;
                }
                j = ff[j];		                 // 寻找新的模式串pat的匹配字符位置
            }	
        }
        t++;
    }                        
    delete []f;				             // 释f所占用的存储空间
	delete []ff;
    ans=S.substr(pos,maxm);
    return ans;
}

int main()
{
    string S,T,ans;
    S="acs";
    T="eacsdd";
    ans=S.length() > T.length() ? find_max_sub_string(T,S) : find_max_sub_string(S,T);
    cout<<"最长公共子串："<<ans<<endl;
    return 0;
}
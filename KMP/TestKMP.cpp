#include "KMP.h"		      // KMP算法
#include "String.h"

int main(void)
{	// 测式KMP字符串模式匹配算法
	String ob("");
	String pat("abcaabbabcabaacbacba");
//	cout<<ob.GetLength()<<" "<<pat.GetLength()<<endl;
	cout << "主串为：" ;
	Write(ob);
	cout << "模式串为：" ;
	Write(pat);
	KMP_find(ob,pat);

	return 0;               // 返回值0, 返回操作系统
}

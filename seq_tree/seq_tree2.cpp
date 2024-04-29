#include<iostream>
#include<vector>

using namespace std;

template<typename T>
struct node
{
    T data;
    int parent;

    node(T d,int p=-1):data(d),parent(p){}
};

template<typename T>
class Tree
{
private:
    vector<node<T>> nodes;
    vector<int> degrees;

public:
    Tree(){}

    int Find(const T& val) const
    //查找val的节点，返回节点在nodes中的下标
    //如果val不存在，返回-1
    {
        for(int i=0;i<nodes.size();i++)
        {
            if(nodes[i].data==val)
            {
                return i;
            }
        }
        return -1;
    }

    void Insert(const T& parent,const T& child)
    //插入元素
    {
        int parentindex=Find(parent);
        nodes.push_back(node<T>(child,parentindex));
    }
    void Insert(const T& val)
    //插入元素重载 建根节点 parent默认为-1
    {
        nodes.push_back(node<T>(val));
    }

    void Degree()
    //求个节点的度 存在degrees数组中方便后续调用
    {
        int maxdegree=0;
        degrees.resize(nodes.size());
        degrees.assign(degrees.size(),0);
        for(int i=1;i<nodes.size();i++)
        {
            degrees[nodes[i].parent]++;
            maxdegree=max(maxdegree,degrees[nodes[i].parent]);
        }
        cout<<"degree is "<<maxdegree<<endl;
    }
    
    void Height()
    //求树的高度
    {
        int maxd=0;
        for(int i=0;i<nodes.size();i++)
        {
            int p=i;
            int d=0;
            while(p!=-1)
            {
                p=nodes[p].parent;
                d++;
            }
            maxd=max(maxd,d);
        }
        cout<<"height is "<<maxd<<endl;
    }

    void Leaf()
    //求叶子节点个数
    {
        int leaf=0;
        for(int i=0;i<nodes.size();i++)
        {
            if(degrees[i]==0)
            {
                leaf++;
            }
        }
        cout<<"leaf is "<<leaf<<endl;
    }
};

int main()
{
    Tree<int> tree;
    tree.Insert(1);
    tree.Insert(1,2);
    tree.Insert(1,3);
    tree.Insert(2,4);
    tree.Insert(2,5);
    tree.Insert(3,6);
    tree.Insert(5,7);
    tree.Insert(2,8);
    tree.Insert(2,9);

    tree.Degree();
    tree.Height();
    tree.Leaf();
    return 0;
}
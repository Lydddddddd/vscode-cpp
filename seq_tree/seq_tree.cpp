#include<iostream>
#include<vector>

using namespace std;

template<typename T>
struct TreeNode
{
    T val;
    int parent;
    int firstchild;
    int nextsibling;
    TreeNode(T v,int p=-1,int fc=-1,int ns=-1):val(v),parent(p),firstchild(fc),nextsibling(ns){}
};

template<typename T>
class Tree
{
private:
    vector<TreeNode<T>> nodes;

public:
    Tree(){}
    
    void Insert(const T& parentval, const T& childval)
    //通过插入建树
    //parentval是父节点的值，childval是子节点的值
    {
       if(nodes.empty())
       {
           nodes.push_back(TreeNode<T>(childval));
       }
       else
       {
           int parentindex=Find(parentval);
           if(parentindex != -1)
           {
               nodes.push_back(TreeNode<T>(childval,parentindex));
               if(nodes[parentindex].firstchild==-1)
               {
                   nodes[parentindex].firstchild=nodes.size()-1;
               }
               else
               {
                   int nextsiblingindex=nodes[parentindex].firstchild;
                   while(nodes[nextsiblingindex].nextsibling!=-1)
                   {
                       nextsiblingindex=nodes[nextsiblingindex].nextsibling;
                   }
                   nodes[nextsiblingindex].nextsibling=nodes.size()-1;
               }
           }
           else
           {
               cout<<"parent not found!"<<endl;
           }
       }
    }

    int Find(const T& val) const
    //查找val的节点，返回节点在nodes中的下标
    //如果val不存在，返回-1
    {
        for(int i=0;i<nodes.size();i++)
        {
            if(nodes[i].val==val)
            {
                return i;
            }
        }
        return -1;
    }

    int Degree(int t) const
    //返回以t为根的子树的度
    {
        if(t>=nodes.size()||nodes[t].firstchild==-1)
        {
            return 0;
        }
        int degree=0;
        int maxsubdegree=0;
        for(int p=nodes[t].firstchild;p!=-1;p=nodes[p].nextsibling)
        {
            degree++;
            maxsubdegree=max(maxsubdegree,Degree(p));
        }
        return max(degree,maxsubdegree);
    }

    int Treedegree() const
    //返回整棵树的度
    {
        return Degree(0);
    }

    int Hight(int t) const
    //返回以t为根的子树的树高
    {
        if(t>=nodes.size())
        {
            return 0;
        }
        else if(nodes[t].firstchild==-1)
        {
            return 1;
        }
        int hight=0;
        for(int p=nodes[t].firstchild;p!=-1;p=nodes[p].nextsibling)
        {
            hight=max(hight,Hight(p));
        }
        return hight+1;
    }

    int Treeheight() const
    //返回整棵树的树高
    {
        return Hight(0);
    }

    int Leaf(int t) const
    //返回以t为根的子树的叶子数
    {
        if(t>=nodes.size())
        {
            return 0;
        }
        else if(nodes[t].firstchild==-1)
        {
            return 1;
        }
        int leaf=0;
        for(int p=nodes[t].firstchild;p!=-1;p=nodes[p].nextsibling)
        {
            leaf+=Leaf(p);
        }
        return leaf;
    }

    int Treeleaf() const
    //返回整棵树的叶子数
    {
        return Leaf(0);
    }
};

int main() {
    Tree<int> tree;
    tree.Insert(0, 1);
    tree.Insert(1, 2);
    tree.Insert(1, 3);
    tree.Insert(2, 4);
    tree.Insert(2, 5);
    tree.Insert(2, 7);
    tree.Insert(3, 6);
    tree.Insert(6, 8);

    cout << "The degree of the tree is: " << tree.Treedegree() << endl;
    cout << "The height of the tree is: " << tree.Treeheight() << endl;
    cout << "The number of leaf nodes in the tree is: " << tree.Treeleaf() << endl;

    return 0;
}
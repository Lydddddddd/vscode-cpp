#include <iostream>
#include <queue>

using namespace std;

template <class T>
struct TreeNode {
    T data;
    TreeNode<T> *firstChild;
    TreeNode<T> *nextSibling;

    TreeNode(const T& value) : data(value), firstChild(NULL), nextSibling(NULL) {}
};

template <class T>
class Tree {
private:
    TreeNode<T> *root;

public:
    Tree() : root(NULL) {}

    // 插入节点
    void insert(const T& parentValue, const T& value) {
        if (root == NULL) {
            root = new TreeNode<T>(value);
            return;
        }
        TreeNode<T> *parent = findNode(root, parentValue);
        if (parent != NULL) {
            if (parent->firstChild == NULL) {
                parent->firstChild = new TreeNode<T>(value);
            } else {
                TreeNode<T> *sibling = parent->firstChild;
                while (sibling->nextSibling != NULL) {
                    sibling = sibling->nextSibling;
                }
                sibling->nextSibling = new TreeNode<T>(value);
            }
        } else {
            cout << "Parent not found." << endl;
        }
    }

    // 在树中查找节点
    TreeNode<T>* findNode(TreeNode<T> *start, const T& value) const {
        if (start == NULL) {
            return NULL;
        }
        if (start->data == value) {
            return start;
        }
        TreeNode<T> *found = findNode(start->firstChild, value);
        if (found == NULL) {
            found = findNode(start->nextSibling, value);
        }
        return found;
    }

    // 求以r为根的子树的度
    int Degree(TreeNode<T> *r) const {
        if(r == NULL || r->firstChild == NULL){
            return 0;
        }
        int degree = 0;
        int maxsubdegree = 0;
        for(TreeNode<T> *p = r->firstChild;p != NULL;p = p->nextSibling){
            degree++;
            maxsubdegree = max(maxsubdegree, Degree(p));
        }
        degree = max(degree, maxsubdegree);
        return degree;
    }

    // 求树的度
    int Treedegree() const {
        return Degree(root);
    }

    // 求以r为根的子树的高度
    int Height(TreeNode<T>* r) const {
        if(r == NULL){
            return 0;   
        }
        else if(r->firstChild == NULL){
            return 1;
        }
        int maxsubheight = 0;
        int height = 1;
        for(TreeNode<T>* p = r->firstChild;p != NULL;p = p->nextSibling)
        {
            maxsubheight = max(maxsubheight, Height(p));
        }
        height = maxsubheight + 1;
        return height;
    }

    // 求树的高度
    int Treeheight() const {
        return Height(root);
    }

    // 求以r为根的子树的叶子结点个数
    int Leaf(TreeNode<T>* r) const {
        if(r == NULL){
            return 0;
        }
        else if(r->firstChild == NULL){
            return 1;
        }
        else{
            int sum = 0;
            for(TreeNode<T>* p = r->firstChild;p != NULL;p = p->nextSibling){
                sum += Leaf(p);
            }
            return sum;
        }
    }

    // 求树的叶子结点个数
    int Treeleaf() const {
        return Leaf(root);
    }
};

int main() {
    Tree<int> tree;
    tree.insert(0, 1);
    tree.insert(1, 2);
    tree.insert(1, 3);
    tree.insert(2, 4);
    tree.insert(2, 5);
    tree.insert(2, 7);
    tree.insert(3, 6);
    tree.insert(6, 8);

    cout << "The degree of the tree is: " << tree.Treedegree() << endl;
    cout << "The height of the tree is: " << tree.Treeheight() << endl;
    cout << "The number of leaf nodes in the tree is: " << tree.Treeleaf() << endl;

    return 0;
}
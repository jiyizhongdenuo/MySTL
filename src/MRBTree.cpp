#include"MRBTree.h"
#include<iostream>
#include<vector>
#include<assert.h>
#include<utility>
#include<assert.h>
#include<cstring>
#include"MTest.h"
#include"MTest.cpp"
using namespace std;
// using std::pair;

//使用指针可以方便判断相等（不需要基类给出==操作符），便于赋值操作；
template<class Key, class Value>
void MRBTree<Key,Value>::RightRotate(MRBTreeNode<Key,Value>* n)
{
    rbn nr=n->left;
    if(n!=Nil)
    {
        n->left=nr->right;
        if(nr->right!=Nil)
            nr->right->parent=n;
        nr->parent=n->parent;
        if(n->parent==Nil)
            root=nr;
        else if(n==n->parent->left)
            n->parent->left=nr;
        else 
            n->parent->right=nr;
        nr->right=n;
        n->parent=nr;
    }
}

template<class Key, class Value>
void MRBTree<Key,Value>::LeftRotate(MRBTreeNode<Key,Value>* n)
{
    rbn nl=n->right;
    if(n!=Nil)
    {
        n->right=nl->left;
        if(nl->left!=Nil)
            nl->left->parent=n;
        nl->parent=n->parent;
        if(n->parent==Nil)
            root=nl;
        else if(n==n->parent->left)
            n->parent->left=nl;
        else 
            n->parent->right=nl;
        n->parent=nl;
        nl->left=n;
    }
}

template<class Key,class Value>
void MRBTree<Key,Value>::InsertFixup(MRBTreeNode<Key,Value>* n)
{
    rbn uncle;
    while(n->parent->color==red)
    {
        if(n->parent==n->parent->parent->left)
        {
            uncle=n->parent->parent->right;
            if(uncle->color==red)
            {
                n->parent->color==black;
                uncle->color==black;
                n->parent->parent->color=red;
                n=n->parent->parent;
            }
            else
            {
                if(n==n->parent->right)
                {
                    n=n->parent;
                    LeftRotate(n);
                }
                n->parent->color=black;
                n->parent->parent->color=red;
                RightRotate(n->parent->parent);
            }
        }
        else
        {
            uncle=n->parent->parent->left;
            if(uncle->color==red)
            {
                n->parent->color=black;
                uncle->color=black;
                n->parent->parent->color=red;
                n=n->parent->parent;
            }
            else
            {
                if(n==n->parent->left)
                {
                    n=n->parent;
                    RightRotate(n);
                }
                n->parent->color=black;
                n->parent->parent->color=red;
                LeftRotate(n->parent->parent);
            }
        }
    }
    root->color=black;
}

template<class Key,class Value>
MRBTreeNode<Key,Value>* MRBTree<Key,Value>::NInsert(MRBTreeNode<Key,Value>* n)
{
    MRBTreeNode<Key,Value>* IS=root;
    if(root==Nil)
    {
        root=n;
        return root;
    }
    rbn parent;
    while(IS!=Nil)
    {
        parent=IS;
        if(n->key<IS->key)
            IS=IS->left;
        else if(n->key>IS->key)
            IS=IS->right;
        else 
        {
            IS->value=n->value;
            return IS;
        }
    }
    if(n->key<parent->key)
        parent->left=n;
    else
        parent->right=n;
    n->parent=parent;
    InsertFixup(n);
    return n;
}


template<class Key,class Value>
void MRBTree<Key,Value>::InOrder(MRBTreeNode<Key,Value>* root)
{
    if(root!=Nil)
    {
        InOrder(root->left);
        std::cout<<root->key<<"\t";
        InOrder(root->right);
    }
}
template<class Key,class Value>
MRBTreeNode<Key,Value>* MRBTree<Key,Value>::Min(MRBTreeNode<Key,Value>*n)
{
    if(n->left==Nil)
    {
        return n;
    }
    return Min(n->left);
}

template<class Key,class Value>
MRBTreeNode<Key,Value>* MRBTree<Key,Value>::GetNode(Key k,Value v)//不能添加默认参数
{
    rbn n=new MRBTreeNode<Key,Value>(k,v);
    assert(n!=Nil);
    n->color=red;
    n->left=n->right=n->parent=Nil;
    return n;
}

template<class Key,class Value>
MRBTreeNode<Key,Value>* MRBTree<Key,Value>::Search(const Key& k)
{
    rbn c=root;
    while(c!=Nil)
    {
        if(c->key>k)
            c=c->left;
        else if(c->key<k) 
            c=c->right;
        else 
            return c;
    }
    return Nil;
}
template<class Key,class Value>
void MRBTree<Key,Value>::NDelete(MRBTreeNode<Key,Value>* n)
{
    delete n;
}

template<class Key,class Value>
void MRBTree<Key,Value>::NRemove(const Key& k)
{
    rbn n=Search(k);
    if(n==Nil)
    {
        cout<<"key not exist!";
    }
    else 
        NRemove(n);
}

template<class Key,class Value>
void MRBTree<Key,Value>::NRemove(MRBTreeNode<Key,Value>* n)
{
    _rb_tree_color cl=n->color;
    if(n->right!=Nil && n->left!=Nil)//当删除节点不是叶子或叶子的父节点时，寻找后继节点
    {
        rbn sn=Min(n->right);
        n->key=sn->key; n->value=sn->value;
        n=sn;
    }
    //此时的n为后继节点，n至多只有一个右子节点。因此else代表n为叶子节点（root也看做叶子节点。）
    rbn rn=n->left==Nil?n->right:n->left;
    if(rn!=Nil)
    {
        rn->parent=n->parent;
        if(n->parent==Nil)
            root=rn;
        else if(n==n->parent->left)
            n->parent->left=rn;
        else 
            n->parent->right=rn;
        delete n;
        if(cl==black)
            RemoveFixup(rn);
    }
    else if(n->parent==Nil)
    {
        // destroy(root);
    }
    else 
    {
        if(cl==black)
            RemoveFixup(n);
        if(n->parent!=Nil)
        {
            if(n==n->parent->right)
                n->parent->right=Nil;
            else if (n==n->parent->left)
                n->parent->left=Nil;
        }
        delete n;
    }   
}
template<class Key,class Value>
void MRBTree<Key,Value>::RemoveFixup(MRBTreeNode<Key,Value>*n)
{
    while(n!=root&&n->color==black)//这里需要循环，当rn->right 与rn->left都为叶子节点的时候 需要向上更改节点颜色。
    {
        if(n==n->parent->left)
        {       
            /*判断真正的兄弟节点。
            此处有两个作用1.确保在else有替补可以借出的情况下能够删除的是叶子节点。（因为在红黑树显示的兄弟节点是红色的，它的子树不止一层，无法借出（在234树中该节点与删除节点不在同一层。）
                        2.在没有替补节点的时候，在向上节点自损兄弟节点的时候，每次自损的兄弟节点是黑色节点。）第一个if的情况下。
            */
            rbn rn=n->parent->right;
            if(rn->color==red)
            {
                rn->color=black;
                n->parent->color=red;
                LeftRotate(n->parent);
            }
            rn=n->parent->right;
            //兄弟节点也没有替补,采用整个该半边的子树与父节点的另一半子树自损一个黑色节点，父节点（直到父节点为红色节点）变为黑色节点来保持平衡。
            if(rn->left==Nil&&rn->right==Nil)
            {
                rn->color=red; 
                n->parent->color=black;
                n=n->parent;
            }
            //兄弟节点有替补，一个或两个处理方法一样，？
            else 
            {
                //变为兄弟节点一定有右子节点，然后处理
                if(rn->right==Nil)
                {
                    rn->color=red;   rn->left->color=black;
                    RightRotate(rn);
                    rn=n->parent->right;
                }
                rn->color=n->parent->color;
                //这里一定是黑色是因为从2、3、4树来看这里在删除之前已经弄成3或4节点了，这一层一定是黑色，所以现在删除之后保证平衡旋转后也要变成黑色。
                n->parent->color=black;  rn->right->color=black;
                LeftRotate(n->parent);
                n=root;
            }
        }
        else
        {
                        /*判断真正的兄弟节点。
            此处有两个作用1.确保在else有替补可以借出的情况下能够删除的是叶子节点。（因为在红黑树显示的兄弟节点是红色的，它的子树不止一层，无法借出（在234树中该节点与删除节点不在同一层。）
                        2.在没有替补节点的时候，在向上节点自损兄弟节点的时候，每次自损的兄弟节点是黑色节点。）第一个if的情况下。
            */
            rbn rn=n->parent->left;
            if(rn->color==red)
            {
                rn->color=black;
                n->parent->color=red;
                RightRotate(n->parent);
            }
            rn=n->parent->left;
            //兄弟节点也没有替补,采用整个该半边的子树与父节点的另一半子树自损一个黑色节点，父节点（直到父节点为红色节点）变为黑色节点来保持平衡。
            if(rn->left==Nil&&rn->right==Nil)
            {
                rn->color=red; 
                n->parent->color=black;
                n=n->parent;
            }
            //兄弟节点有替补，一个或两个处理方法一样，？
            else 
            {
                //变为兄弟节点一定有右子节点，然后处理
                if(rn->left==Nil)
                {
                    rn->color=red;   rn->right->color=black;
                    LeftRotate(rn);
                    rn=n->parent->left;
                }
                rn->color=n->parent->color;
                //这里一定是黑色是因为从2、3、4树来看这里在删除之前已经弄成3或4节点了，这一层一定是黑色，所以现在删除之后保证平衡旋转后也要变成黑色。
                n->parent->color=black;  rn->left->color=black;
                RightRotate(n->parent);
                n=root;
            }
        }   
    }
    n->color=black;
}

template<class Key,class Value>
void MRBTree<Key,Value>::destroy(MRBTreeNode<Key,Value>*n)
{
    if(n!=Nil)
    {
        destroy(n->left);
        destroy(n->right);
        delete n; 
    }
}
int main() {

    MRBTree<string,int> rb("abc",10);
    string ab("bcd");
    MRBTreeNode<string,int> rrb(ab,11);
    rb.NInsert(ab,10);
    rb.NInsert("abb",20);
    rb.InOrder();
    rb.NRemove("ab");
    rb.InOrder();
    return 0;
}
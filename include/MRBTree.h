#ifndef _MMRBTree_N
#define _MMRBTree_N
#include<utility>
#include<assert.h>
typedef bool _rb_tree_color;
const _rb_tree_color black=true;
const _rb_tree_color red=false;

using std::pair;

template<class Key,class Value>
struct MRBTreeNode{
public:
    MRBTreeNode():parent(nullptr),left(nullptr),right(nullptr),color(red){}
    // MRBTreeNode()=default;
    MRBTreeNode(Key k,Value v,bool cl=red):parent(nullptr),left(nullptr),right(nullptr),key(k),value(v),color(cl){}
    bool color;
    MRBTreeNode<Key,Value> * parent;
    MRBTreeNode<Key,Value> * left;
    MRBTreeNode<Key,Value> * right;
    Key key;
    Value value;
};

template<class Key, class Value>
class MRBTree
{
public:
    typedef MRBTreeNode<Key,Value>* rbn;
    MRBTree(){Nil=GetNode();root=Nil;Nil->color=black;}
    MRBTree(Key k,Value v){root=GetNode(k,v);Nil=GetNode();Nil->color=black;root->color=black;root->right=root->parent=root->left=Nil;}//root是指针，不能用初始化构造。
    ~MRBTree(){destroy(root);}
    MRBTreeNode<Key,Value>* NInsert(MRBTreeNode<Key,Value>* n);
    MRBTreeNode<Key,Value>* NInsert(const Key &key,const Value &value){return NInsert(GetNode(key,value));}
    void NDelete(MRBTreeNode<Key,Value>* n);
    void NRemove(const Key& k);
    void NRemove(MRBTreeNode<Key,Value>* n);
    MRBTreeNode<Key,Value>* Search(const Key& k);
    MRBTreeNode<Key,Value>* Min(MRBTreeNode<Key,Value>*n);
    void InOrder(MRBTreeNode<Key,Value>* rt);//不能使用类的成员变量作为默认参数，因为类的成员变量在类实例化的之前（函数编译的时候）并未确定？/类成员函数不也是实例化的时候编译的？
    void InOrder(){InOrder(root);}
protected:    
    void destroy(MRBTreeNode<Key,Value>* n);
    MRBTreeNode<Key,Value>* GetNode(Key k=Key(),Value v=Value());
    void LeftRotate(MRBTreeNode<Key,Value>* r);
    void RightRotate(MRBTreeNode<Key,Value>* r);
    void InsertFixup(MRBTreeNode<Key,Value>* n);
    void RemoveFixup(MRBTreeNode<Key,Value>*n);
    // MRBTreeNode<Key,Value>* GetNode(Key k=Key(),Value v=Value())
    // {
    //     rbn n=new MRBTreeNode<Key,Value>(k,v);
    //     assert(n!=nullptr);
    //     n->color=red;
    //     n->left=n->right=n->parent=Nil;
    //     return n;
    // }
private: 
    MRBTreeNode<Key,Value>* root;
    MRBTreeNode<Key,Value>* Nil;
};


#endif
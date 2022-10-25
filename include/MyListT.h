#ifndef MYLISTT
#define MYLISTT

#include<iostream>
#include<stdexcept>

using namespace std;
template<class T>
class MyListT
{
public:
    //缺省构造
    MyListT():m_head(nullptr),m_tail(nullptr){}
    MyListT(MyListT const& that):m_head(nullptr),m_tail(nullptr)//创建空间的时候可能有初值。
    {
        for(node* pnode=that.m_head;pnode;pnode=pnode->m_next)
        {
            push_back(pnode->m_data);
        }
    }
    ~MyListT()
    {
        clear();
    }
    //链表判空
    bool empty(){return nullptr==m_head && nullptr==m_tail;}
    //添加头节点
    void push_front(T const &data)
    {
        m_head=new node(nullptr,data,m_head); 
        if(m_head->m_next) 
            {m_head->m_next->m_prev=m_head;}
        else
            m_tail=m_head;
    }
    //删除头节点
    void pop_front()
    {
        if(empty())
            return ;
        node * pnode=m_head->m_next;
        delete m_head;
        m_head=pnode;
        if(pnode)
            pnode->m_prev=nullptr;
        else
            m_tail=nullptr;
        
    }
    //获取头节点数据
    T& front()
    {
        if (empty())
            throw underflow_error("null error!");
        return m_head->m_date;
    }
    T const& front() const
    {
        return const_cast<MyListT*>(this)->front();
    }
    //添加尾节点
    void push_back(T const &data)
    {
        m_tail=new node(m_tail,data,nullptr);
        if(m_tail->m_prev)
        {
            m_tail->m_prev->m_next=m_tail;
        }
        else
            m_head=m_tail;
    }
    //删除尾节点
    void pop_back()
    {
        if(empty())
            return ;
        node * pnode=m_tail->m_prev;
        delete m_tail; 
        m_tail=pnode;
        if(pnode)
        {   
            pnode->m_next=nullptr;
        }
        else
        {
            m_head=nullptr;   
        }
        // if(m_tail->m_prev)
        // {
        //     m_head=nullptr;m_tail=nullptr;
        // }
        // else
        // {
        //     m_tail->m_prev->m_next=nullptr;
        //     m_tail=m_tail->m_prev;
        // }

    }
    //获取尾节点
    T& back()
    {
        if(empty())
            throw underflow_error("null node!");
        return m_tail->data;
    }
    T const& back() const
    {
        return const_cast<MyListT*>(this)->back;
    }
    //清空链表
    void clear()
    {
        if(!empty())
        {
            pop_front();
        }
    }
    //获取链表大小
    size_t size()
    {
        size_t i=0;
        for(node* pnode=m_head;pnode;pnode=pnode->m_next)
            i++;
        return i;
    }
    friend ostream& operator<<(ostream& os,MyListT<int>& l);
private:
// 链表成员变量
    class node
    {
    public:
        node* m_prev;
        T m_data;
        node* m_next;
        node(node* prev,T data,node* next):m_prev(prev),m_data(data),m_next(next){}
    private:
    };
    node* m_head;
    node* m_tail;
public:
//链表的迭代器
    class iterator
    {
    public:
        iterator(node* start,node* cur,node* end):m_start(start),m_cur(cur),m_end(end){}
        iterator& operator++()
        {
            if(nullptr==m_cur)
                m_cur=m_start;
            else    
                m_cur=m_cur->m_next;
            return *this;
        }
        iterator& operator--()
        {
            if(m_cur==nullptr)
                m_cur=m_end;
            else    
                m_cur=m_cur->prev;
            return *this;
        }
        T& operator*()
        {
            if(nullptr==m_cur)
                throw underflow_error("null node!");
            return m_cur->m_data;
        }
        bool operator==(iterator const& that)const
        {
            return m_cur==that.m_cur && m_start==that.m_start && m_end==that.m_end;
        }
        bool operator!=(iterator const& that)const
        {
            return !(*this==that);
        }
    private:
        node* m_start;
        node* m_cur;
        node* m_end;
        friend class MyListT;
    };
//迭代器对象
    //起始迭代器：遍历链表
    iterator begin()//不能返回引用因为是再函数内部生成的类对象
    {
        return iterator(m_head,m_head,m_tail);
    }
    //终止迭代器：结束标志
    iterator end()
    {
        return iterator(m_head,nullptr,m_tail);
    }
//通过迭代器添加或删减成员
    void erase(iterator const& l)//这里传入的end()返回的值是右值（在函数调用完之后会消失），没有存储空间，必须加上const，系统会为这个返回值传教临时变量
    {
        if(end()==l)
            return ;
        if(l.m_cur->m_prev)
            l.m_cur->m_prev->m_next=l.m_cur->m_next;
        else 
            m_head=l.m_cur->m_next;
        if(l.m_cur->m_next)
            l.m_cur->m_next->m_prev=l.m_cur->m_prev;
        else
            m_tail=l.m_cur->m_prev;
        delete l.m_cur;
    }
    void insert(iterator const& l,T const& data)
    {     
        if(l==end())
            push_back(data);
        else 
            {
                node* pnode=new node(l.m_cur->m_prev,data,l.m_cur);
                if(pnode->m_prev)
                    pnode->m_prev->m_next=pnode;
                else
                    m_head=pnode;
                l.m_cur->m_prev=pnode;
            }
        // l.m_cur->m_prev->m_next=pnode;结果正确，行为错误。
        // l.m_cur->m_next->m_prev=pnode;错误的。这里m_cur应该是pnode的next节点
    }
    class const_iterator
    {
    public:
        const_iterator(iterator const & it):m_it(it){}
        T const& operator*()
        {
            return *m_it;  
        }
        const_iterator& operator++()
        {
            ++m_it;
            return *this;
        }
        const_iterator& operator--()
        {
            --m_it;
            return *this;
        }
        bool operator==(const_iterator const & that)
        {
            return m_it==that.m_it;
        }
        bool operator!=(const_iterator const& that)
        {
            return !(*this==that);
        }
    private:
        iterator m_it;
    };
    //获取起始迭代器
    const_iterator begin()const
    {
        return iterator(m_head,m_head,m_tail);   
    }
    //获取终止迭代器
    const_iterator end()const
    {
        return iterator(m_head,nullptr,m_tail);
    }
};


#endif
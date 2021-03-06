//
// Created by jinqiu on 19-4-21.
//

#ifndef TESK_SEARCH_TREE_H
#define TESK_SEARCH_TREE_H

#include <iostream>

#include "utils.h"


using namespace std;

template<class K,class E>
class BSTree:public Dictionary<K,E>
{
public:
    //关键字按升序输出
    virtual void ascend()=0;
};

/*******************************************
*                二叉搜索树的实现              *
/*******************************************/
template <class K,class E>
class BinarySearchTree
{
public:
    BinarySearchTree():phead_(nullptr),size_(0){}
    ~BinarySearchTree();

    //判断字典是否为空
    bool empty() const{return size_==0;}
    //返回字典的大小
    int size() const{return size_;}
    //返回根节点
    BTreeNode<pair<const K,E>> *get_root(){return phead_;}

    // 搜索字典
    pair<const K, E>* find(const K&);

    //删除字典
    void erase(const K&);

    //插入字典
    void insert(const pair<const K, E>&);

    //关键字按升序输出
    void ascend();
private:
    void delete_(BTreeNode<pair<const K,E>> *node);//删除搜索二叉树
    void inorder_(BTreeNode<pair<const K,E>> *node);//中序遍历
private:
    BTreeNode<pair<const K,E>> *phead_;
    size_t  size_;
};

template <class K,class E>
void BinarySearchTree<K,E>::delete_(BTreeNode<pair<const K, E>> *node)
{
    if(node!= nullptr){
        BTreeNode<pair<const K,E>> *cur=node;
        delete_(node->left_);
        delete_(node->right_);
        delete cur;
        cur= nullptr;
    }
}

template <class K,class E>
BinarySearchTree<K,E>::~BinarySearchTree()
{
    if(phead_!= nullptr){
        delete_(phead_);
        size_=0;
    }
}

template <class K,class E>
pair<const K, E>* BinarySearchTree<K,E>::find(const K &theKey)
{
    BTreeNode<pair<const K,E>> *p= phead_;

    while(p!= nullptr){
        if(theKey<p->element_.first){
            p=p->left_;
        }else if(theKey > p->element_.first){
            p=p->right_;
        }else{
            return &p->element_;
        }
    }

    return nullptr;
}

template <class K,class E>
void BinarySearchTree<K,E>::insert(const pair<const K, E> &theValue)
{
    //获取根节点
    BTreeNode<pair<const K,E>> *p=phead_,*pp= nullptr;

    //在搜索树中搜索吧该节点
    while(p!= nullptr){
        //保存当前节点父节点
        pp=p;
        if(theValue.first < p->element_.first){
            p=p->left_;
        }else if(theValue.first > p->element_.first){
            p=p->right_;
        }else{//如果存在搜索树种，直接替换
            p->element_.second=theValue.second;
            return ;
        }
    }

    //创建节点
    BTreeNode<pair<const K,E>> *newNode=
            new BTreeNode<pair<const K,E>>(theValue);

    //插入节点
    if(phead_!= nullptr){//获取当前节点的子节点，并插入节点
        if(theValue.first<pp->element_.first){
            pp->left_=newNode;
        }else{
            pp->right_=newNode;
        }
    }else{//如果根节点为空，直接在根节点插入节点
        phead_=newNode;
    }

    ++size_;
}

template <class K,class E>
void BinarySearchTree<K,E>::erase(const K &theKey)
{
    //查找关键字
    BTreeNode<pair<const K,E>> *p=phead_,
            *pp= nullptr;

    while(p!= nullptr && p->element_.first!=theKey){
        pp=p;
        if(theKey < p->element_.first){
            p=p->left_;
        } else{
            p=p->right_;
        }
    }
    //如果不存在关键字thekey
    if(p== nullptr){
        return ;
    }

    //如果p有两个非空子树
    if(p->left_!= nullptr && p->right_!= nullptr){
        //搜索p的走左子树最大节点
        BTreeNode<pair<const K,E>> *max_child=p->left_,
                *p_max= p;
        while(max_child->right_!= nullptr){
            p_max=max_child;
            max_child=max_child->right_;
        }

        //将最大元素移动到p(注意key为const，不能直接赋值)
        BTreeNode<pair<const K,E>> *q=new BTreeNode<pair<const K,E>>
                (max_child->element_,p->left_,p->right_);

        if(pp== nullptr){
            phead_=q;
        }else if(p==pp->left_){
            pp->left_=q;
        }else{
            pp->right_=q;
        }
        if(p_max==p) pp=q;
        else pp=p_max;

        delete p;
        p=max_child;
    }

    //如果p最多只有一个孩子
    BTreeNode<pair<const K,E>> *c;
    if(p->left_!= nullptr){
        c=p->left_;
    } else{
        c=p->right_;
    }

    //删除p
    if(p==phead_){
        phead_=c;
    } else{
        if(p==pp->left_){
            pp->left_=c;
        } else{
            pp->right_=c;
        }
    }

    --size_;
    delete p;
}

template<class K,class E>
void BinarySearchTree<K,E>::inorder_(BTreeNode<pair<const K, E>> *node)
{
    if(node== nullptr) {
        return;
    }

    inorder_(node->left_);
    cout<<node->element_.first<<"->"<<node->element_.second<<endl;
    inorder_(node->right_);
}

template<class K,class E>
void BinarySearchTree<K,E>::ascend()
{
    if(phead_== nullptr) {
        return;
    }

    inorder_(phead_);
}

/*******************************************
*              索引二叉搜索树的实现           *
/*******************************************/
template <class K,class E>
class IndexBinarySearchTree
{
public:
    IndexBinarySearchTree():phead_(nullptr),size_(0){}
    ~IndexBinarySearchTree();

    //判断字典是否为空
    bool empty() const{return size_==0;}
    //返回字典的大小
    int size() const{return size_;}
    //返回根节点
    IndexBTreeNode<pair<const K,E>> *get_root(){return phead_;}

    // 搜索字典
    pair<const K, E>* find(const K&);

    //删除字典
    void erase(const K&);

    //插入字典
    void insert(const pair<const K, E>&);

    //关键字按升序输出
    void ascend();
private:
    void delete_(IndexBTreeNode<pair<const K,E>> *);//删除树
    void inorder_(IndexBTreeNode<pair<const K,E>> *);//中序遍历
private:
    IndexBTreeNode<pair<const K,E>> *phead_;
    size_t size_;
};

template <class K,class E>
void IndexBinarySearchTree<K,E>::delete_(IndexBTreeNode<pair<const K, E>> *p)
{
    if(p!= nullptr){
        IndexBTreeNode<pair<const K,E>> *cur=p;
        delete(p->left_);
        delete(p->right_);
        delete cur;
        cur= nullptr;
    }
}

template <class K,class E>
IndexBinarySearchTree<K,E>::~IndexBinarySearchTree()
{
    if(phead_!= nullptr){
        if(phead_!= nullptr){
            delete_(phead_);
            size_=0;
        }
    }
}

template <class K,class E>
pair<const K, E>* IndexBinarySearchTree<K,E>::find(const K &theKey)
{
    IndexBTreeNode<pair<const K,E>> *p=phead_;
    while(p!=nullptr){
        if(theKey< p->element_.first){
            p=p->left_;
        }else if(theKey>p->element_.first){
            p=p->right_;
        }else{
            return &p->element_;
        }
    }

    return nullptr;
}

template<class K,class E>
void IndexBinarySearchTree<K,E>::insert(const pair<const K, E> &thePair)
{
    IndexBTreeNode<pair<const K,E>> *p=phead_, *pp= nullptr;
    while(p!= nullptr){
        pp=p;
        if(thePair.first<p->element_.first){
            ++p->left_size_;
            p=p->left_;
        }else if(thePair.first>p->element_.first){
            p=p->right_;
        }else{
            p->element_.second=thePair.second;
            return;
        }
    }

    IndexBTreeNode<pair<const K,E>> *node=new IndexBTreeNode<pair<const K,E>>(thePair);
    if(phead_!= nullptr){
        if(thePair.first<pp->element_.first){
            pp->left_=node;
            node->parent_=pp;
        }else{
            pp->right_=node;
            node->parent_=pp;
        }
    }else{
        phead_=node;
    }

    ++size_;
}

template <class K,class E>
void IndexBinarySearchTree<K,E>::erase(const K &theKey)
{
    IndexBTreeNode<pair<const K,E>> *p=phead_,
            *pp= nullptr;

    while(p!= nullptr && p->element_.first!=theKey){
        pp=p;
        if(theKey<p->element_.first){
            --p->left_size_;
            p=p->left_;
        }else if(theKey>p->element_.first){
            p=p->right_;
        }
    }

    if(p== nullptr){
        return ;
    }

    //对树进行重构
    //处理p只有两个孩子的情况
    if(p->left_!= nullptr && p->right_!= nullptr){
        //寻找左子树中的最大元素
        IndexBTreeNode<pair<const K,E>> *s=p->left_,*ps= nullptr;
        while(s->right_!= nullptr){
            ps=s;
            s=s->right_;
        }

        int left_size=p->left_size_-1;//获取修改后所删除元素位置的索引值
        //将最大元素移到p位置
        IndexBTreeNode<pair<const K,E>> *q=new IndexBTreeNode<pair<const K,E>>
                (s->element_,p->left_,p->right_,p->parent_,left_size);

        if(pp== nullptr){
            phead_=q;
        } else if(pp->left_==p) {
            pp->left_ = q;
        }else{
            pp->right_=q;
        }

        delete p;
        p=s;
    }

    //如果p最多只有一个孩子
    IndexBTreeNode<pair<const K,E>> *c;
    if(p->left_!= nullptr){
        c=p->left_;
    }else{
        c=p->right_;
    }

    if(phead_==p){
        phead_=c;
    }else{
        if(p==pp->left_){
            pp->left_=c;
        }else{
            pp->right_=c;
        }
    }

    --size_;
    delete p;
}

template<class K,class E>
void IndexBinarySearchTree<K,E>::inorder_(IndexBTreeNode<pair<const K, E>> *p)
{
    if(p == nullptr){
        return ;
    }

    inorder_(p->left_);
    cout<<p->element_.first<<"->"<<p->element_.second<<"<"<<p->left_size_<<">"<<endl;
    inorder_(p->right_);
}

template <class K,class E>
void IndexBinarySearchTree<K,E>::ascend()
{
    if(phead_== nullptr) {
        return;
    }

    inorder_(phead_);
}

#endif //TESK_SEARCH_TREE_H

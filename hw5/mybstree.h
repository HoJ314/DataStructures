/*
Name: Jeremy Ho
Date: 11/8/17
Class: 1B
Purpose: Tree Class Functions
*/

#ifndef MYBSTREE_H
#define MYBSTREE_H

#include <iostream>
#include <string>
#include "abstractbstree.h"

using namespace std;

template <typename T>
class TreeNode
{
  public:
  T m_data;
  TreeNode *m_left;
  TreeNode *m_right;
  //Constructor for tree node for initialization in insert function
  TreeNode<T>(T x, TreeNode* l  , TreeNode* r)
  {
    m_data = x;
    m_left = l;
    m_right = r;
  }
};

template <typename T>
class MyBSTree: public AbstractBSTree<T>
{
  private:
    TreeNode<T>* m_root;
    int m_size;

  public:
    MyBSTree(){m_root = NULL;}
    MyBSTree(const MyBSTree<T>& rhs);

    ~MyBSTree(){clear();};

    int size() const;
    int size(TreeNode<T>* t) const;

    bool isEmpty() const;

    int height() const;
    int height(TreeNode<T>* t) const;

    const T& getMax() const throw (Oops);
    const T& getMax(TreeNode<T>* t) const;

    const T& getMin() const throw (Oops);
    const T& getMin(TreeNode<T>* t) const;

    int find(const T& x) const;
    int find(TreeNode<T>* t, const T& x) const;

    void clear();
    void clear(TreeNode<T>* &t);

    void insert(TreeNode<T>* &t, const T& x);
    void insert(const T& x);

    void remove(const T& x);
    void remove(TreeNode<T>* &t, const T& x);

    void printPreOrder() const;
    void printPreOrder(TreeNode<T>* t) const;

    void printPostOrder() const;
    void printPostOrder(TreeNode<T>* t) const;

    void print() const;

    MyBSTree& operator = (const MyBSTree& rhs);

};

#include "mybstree.hpp"
#endif //MYBSTREE_H

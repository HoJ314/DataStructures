/*
Name: Jeremy Ho
Date: 11/8/17
Class: 1B
Purpose: Function Definitions
*/

#include <iostream>
using namespace std;

//**********************************************
template <typename T>
int MyBSTree<T> :: size() const
{
  return size(m_root);
}

template <typename T>
int MyBSTree<T> :: size(TreeNode<T>* t) const
{
  if(t == NULL)
  {
    return 0;
  }
  // Add both sides + starting layer
  return size(t->m_left) + size(t->m_right) + 1;
}
//***************************************************

template <typename T>
bool MyBSTree<T> :: isEmpty() const
{
  return (m_root == 0); //Checks if there's anything in it
}

//************************************************************
template <typename T>
void MyBSTree<T>::insert(const T& x)
{
  insert(m_root, x);
}

template <typename T>
void MyBSTree<T>::insert(TreeNode<T>* &t, const T& x)
{
  if(t == NULL)
  {
    t = new TreeNode<T>(x, NULL, NULL); //Checks if empty and create new one

    return;
  }

  if(x < t->m_data)
  {
    insert(t->m_left, x); //Branches to left until x=m_data
  }
  else if(x > t->m_data)
  {
    insert(t->m_right, x); //Branches to right until x=m_data
  }
}
//**************************************************************

template <typename T>
void MyBSTree<T> :: clear()
{
  clear(m_root);
}

template <typename T>
void MyBSTree<T>::clear(TreeNode<T>* &t)
{
  if(t != NULL) // Already empty if NULL
  {
    clear(t->m_left);
    clear(t->m_right);
    delete t;
  }
}


//********************************************************
template <typename T>
int MyBSTree<T> :: height() const
{
  return height(m_root);
}

template <typename T>
int MyBSTree<T> :: height(TreeNode<T>* t) const
{
  int left, right, highest;
  if(t == NULL) //Empty so 0
  {
    return 0;
  }
  left = height(t->m_left);
  right = height(t->m_right);

  if (left > right) //Checks whether left or right has the most layers
  {
    highest = left;
  }
  else
  {
    highest = right;
  }

  return highest + 1;
}
//*******************************************************

template <typename T>
const T& MyBSTree<T> :: getMax() const throw (Oops)
{
  return getMax(m_root);
}

template <typename T>
const T& MyBSTree<T>::getMax(TreeNode<T>* t) const
{
  if(t == NULL)
  {
    throw Oops("OOPS! : Tree is Empty!!");
  }
  if(t->m_right == NULL)
  {
    return t->m_data;
  }
  return getMax(t->m_right);
}

//******************************************************

template <typename T>
const T& MyBSTree<T>::getMin() const throw (Oops)
{
  return getMin(m_root);
}

template <typename T>
const T& MyBSTree<T>::getMin(TreeNode<T>* t) const
{
  if(t == NULL)
  {
    throw Oops("OOPS! : Tree is Empty!!");
  }
  if(t->m_left == NULL)
  {
    return t->m_data;
  }
  return getMin(t->m_left);
}

//*********************************************

template <typename T>
int MyBSTree<T> :: find(const T& x) const
{
  int result = find(m_root, x);
  if (result >= 0)
  {
    result++;
  }
  return result;
}

template <typename T>
int MyBSTree<T>::find(TreeNode<T>* t, const T& x) const
{
  int level;
  if(t == NULL)
  {
    return -1;
  }
  if(t->m_data == x) //Finds data and starts incrementing
  {
    return 0;
  }
  if(x < t->m_data) //Checks if left or right side
  {
    level = find(t->m_left, x);
  }
  else if(x > t->m_data)
  {
    level = find(t->m_right, x);
  }
  if (level < 0)
  {
    level--; //Get rid of unneeded counts
  }
  else
  {
    level++; //Increments once data is found
  }

  return (level);
}



//*********************************************
template <typename T>
void MyBSTree<T> :: remove(const T& x)
{
  return remove(m_root,x);
}

template <typename T>
void MyBSTree<T>::remove(TreeNode<T>* &t, const T& x)
{
  if(t == NULL)
  {
    return;
  }
  if(x > t->m_data) //Checks for x location before removal
  {
    remove(t->m_right, x);
  }
  else if(x < t->m_data)
  {
    remove(t->m_left, x);
  }
  else
  {
    if(t->m_left != NULL && t->m_right != NULL)
    {
      t->m_data = getMax(t->m_left);
      remove(t->m_left, t->m_data);
    }
    else
    {
      TreeNode<T>* temp = t; //creates new tree
      t = temp->m_left;
      if(t == NULL)
      {
        t = temp->m_right;
      }

      delete temp;
    }
  }
}

//*********************************************
template <typename T>
void MyBSTree<T> :: printPreOrder() const
{
  printPreOrder(m_root);
}

template <typename T>
void MyBSTree<T>::printPreOrder(TreeNode<T>* t) const
{
  if(t != NULL) //Make sure it's not empty
  {
    std::cout << t->m_data << " ";

    printPreOrder(t->m_left);
    printPreOrder(t->m_right);
  }
}
//********************************************

template <typename T>
void MyBSTree<T> :: printPostOrder() const
{
  printPostOrder(m_root);
}


template <typename T>
void MyBSTree<T>::printPostOrder(TreeNode<T>* t) const
{
  if(t != NULL) //Make sure it's not empty
  {
    printPostOrder(t->m_left);
    printPostOrder(t->m_right);

    std::cout << t->m_data << " ";
  }
}

//**********************************************
template <typename T>
void MyBSTree<T> :: print() const
{
  prettyPrint(m_root, 0); //Uses given function
}

template <typename T>
void prettyPrint(TreeNode<T>* t, int pad)
{
  std::string s(pad, ' ');
  if(t == NULL)
  {
    std::cout << std::endl;
  }
  else
  {
    prettyPrint(t->m_right, pad + 4);
    std::cout << s << t->m_data << std::endl;
    prettyPrint(t->m_left, pad + 4);
  }
}

//************************
template <typename T>
MyBSTree<T>& MyBSTree<T>::operator = (const MyBSTree<T>& rhs)
{
  if(this != &rhs)
  {
    clear(); //Clears m_root if not equal to rhs
    m_root = clone(rhs.m_root); //Copies rhs to m_root
  }

  return *this;
}

template <typename T>
TreeNode<T>* clone(const TreeNode<T>* t)
{
  if (t == NULL)
      return NULL;
  else
  {
    return new TreeNode<T>(t->m_data, clone(t->m_left),clone(t->m_right));
  }
}

template <typename T>
MyBSTree<T>::MyBSTree(const MyBSTree<T>& rhs)
{
  m_root = NULL; //create and copy
  *this = rhs;
}



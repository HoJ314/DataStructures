/*
Programmer: Jeremy Ho
Date:   11/17/2017
Class : 1B
Purpose : linkedlist functions for stringmap
*/

template <typename T>
LinkedList<T>::LinkedList()
{
	m_head = m_back = NULL;
	m_size = 0;
}

template <typename T>
LinkedList<T>::~LinkedList()
{
	clear();
}

template<typename T>
const LinkedList<T>& LinkedList<T>::operator= (const LinkedList<T>& rhs)
{
  if(this != &rhs)
  {
    clear();
    for(Node<T> *tmp = rhs.m_head; tmp != NULL; tmp = tmp -> m_next)
      insert_back(tmp->m_data);
  }

  return *this;

}

template <typename T>
LinkedList<T>::LinkedList(const LinkedList<T>& rhs)
:m_size(0), m_head(NULL), m_back(NULL)
{
    *this = rhs;
}

template <typename T>
int LinkedList<T>::size() const
{
	return m_size;
}

template <typename T>
bool LinkedList<T>::isEmpty() const
{
  return m_size == 0;
}

template <typename T>
Node<T>* LinkedList<T>::getFirstPtr()
{
  return m_head;
}

template <typename T>
const Node<T>* LinkedList<T>::getFirstPtr() const
{
  return m_head;
}

template <typename T>
Node<T>* LinkedList<T>::getLastPtr()
{
  return m_back;
}

template <typename T>
Node<T>* LinkedList<T>::getAtPtr(int i)
{
  if(i < 0)
    return NULL;
  else
  {
    Node<T> *tmp = m_head;
    for(int k = 0; k < i; k++)
      tmp = tmp->m_next;

    return tmp;
  }
}


template<typename T>
void LinkedList<T>::clear()
{
    while(!isEmpty())
      remove_front();
}

template <typename T>
void LinkedList<T>::insert_front(const T& x)
{
  m_head = new Node<T>(x, m_head);
  if(isEmpty())
    m_back = m_head;

  m_size++;
}

template <typename T>
void LinkedList<T>::insert_back(const T& x)
{
  if(m_back == NULL)
  {
    m_back = m_head = new Node<T>(x, NULL);
    m_size++;
  }
  else
  {
    insert(x, m_back);
  }
}

template <typename T>
void LinkedList<T>::insert(const T& x, Node<T>* pos)
{
  if(pos == NULL)
  {
    std::cout << "insert() failed. Pos is a null." << std::endl;
  }
  else
  {
    Node<T>* tmp;
    tmp = new Node<T>(x, pos->m_next);

    pos->m_next = tmp;

    m_size++;

    if(pos == m_back)
      m_back = m_back->m_next;
  }
}

template <typename T>
void LinkedList<T>::remove_front()
{
  if(isEmpty())
  {
    std::cout << "ERROR! List is empty." << std::endl;
  }
  else
  {
    Node<T>* tmp = m_head;
    m_head = m_head->m_next;
    delete tmp;
    m_size--;
    if(isEmpty())
       m_back = NULL;
  }
}

template <typename T>
void LinkedList<T>::remove_back()
{
  if(isEmpty())
  {
    std::cout << "ERROR! List is empty." << std::endl;
  }
  else if(m_size == 1)
  {
    remove_front();
  }
  else
  {
    Node<T>* tmp = m_head;
    for(; tmp != NULL; tmp = tmp->m_next)
    {
      if(tmp->m_next == m_back)
        m_back = tmp;
    }

    delete m_back->m_next;
    m_back->m_next = NULL;
    m_size--;
  }

}

template <typename T>
void LinkedList<T>::remove(Node<T>* pos)
{
  if(pos == NULL)
  {
    std::cout << "remove() failed. pos is a null" << std::endl;
  }
  else if(pos == m_head)
    remove_front();
  else if(pos == m_back)
  {
    remove_back();
  }
  else
  {
    Node<T>* tmp = m_head;
    for(; tmp->m_next != pos; tmp = tmp->m_next)
    {
      //to keep the tmp node for move through the list
    }

    tmp->m_next = pos->m_next;
    delete pos;
    m_size--;
  }

}

template <typename T>
bool LinkedList<T>::operator== (const LinkedList<T>& rhs) const
{
  Node<T>* a = m_head;
  Node<T>* b = rhs.m_head;
  while(a != NULL && b != NULL)
  {
    if(a->m_data != b->m_data)
      return false;

    a = a->m_next;
    b = b->m_next;
  }

  return (a == NULL && b == NULL);
}

template <typename T>
std::ostream& operator<< (std::ostream& out, const LinkedList<T>& list)
{
  const Node<T>* tmp = list.getFirstPtr();
  while(tmp != NULL)
  {
    std::cout << tmp->m_data;
    tmp = tmp->m_next;
  }

  return out;
}

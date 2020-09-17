//Name: Jeremy Ho
//Section: 1B
//Date: 10/16/2017
//Purpose: Define functions in arraylist.h

//Did not know what to do with the dummy variable m_errobj




//Grow
template <typename T>
void ArrayList<T> :: grow()
{
  m_max *= 2;
  T* temp = new T[m_max];

  for(int j = 0; j < m_size; j++)
  {
    temp[j] = m_data[j];
  }

    delete [] m_data;
    m_data = temp;
    delete [] temp;
    temp = NULL;

  return;
}

//Shrink
 template <typename T>
void ArrayList<T> :: shrink()
{
 T* temp = new T[m_max / 2];

  for(int i = 0; i < m_size; i++)
  {
    temp[i] = m_data[i];
  }

  m_max /= 2;

  delete [] m_data;
  m_data = temp;
  delete [] temp;
  temp = NULL;

  return;
}

//Parameterized Constructor
template <typename T>
ArrayList<T> :: ArrayList(int s, const T& x)
{
  m_max = s;
  m_size = s;
  for(int i=0; i<s; i++)
  {
    m_data[i] = x;
  }
}

//Destructor
template <typename T>
ArrayList<T> :: ~ArrayList()
{
  m_size = 0;
  m_max = 0;
  delete []m_data;
  m_data = NULL;
}

//Assignment Operator
template <typename T>
ArrayList<T>& ArrayList<T> :: operator=(const ArrayList<T>& rhs)
{

  delete [] m_data;
  m_max = rhs.m_max;
  m_size = rhs.m_size;
  m_data = new T[m_max];

  for(int i = 0; i < m_size; i++)
  {
    m_data[i] = rhs.m_data[i];
  }
  return *this;
}

//Copy Constructor
template <typename T>
ArrayList<T> :: ArrayList(const ArrayList<T>& cpy)
{
  m_data = new T[0];
  *this = cpy;
}

//Size accessor
template <typename T>
int ArrayList<T> :: size() const
{
  return m_size;
}

//return first element
template <typename T>
const T& ArrayList<T> :: first() const
{
  if(m_size == 0)
  {
    std::cout << "!-- ERROR : PANIC in ARRAYLIST!!.first() (list is empty)" << std::endl;
    return m_errobj;
  }
  else
  {
  return m_data[0];
  }
}

//return read and write reference
template <typename T>
T& ArrayList<T> :: operator[](int i)
{
  if(m_size == 0 || i < 0 || i >= m_size)
  {
    std::cout << "!-- ERROR : PANIC in ARRAYLIST!!.[]() (index out of bounds)" << std::endl;
    return m_errobj;
  }
  else
  {
  return m_data[i];
  }
}

//return read only reference
template <typename T>
const T& ArrayList<T> :: operator[](int i) const
{
  return m_data[i];
}

//find a value in the ArrayList
template <typename T>
int ArrayList<T> :: find(const T& x) const
{
  for(int i=0; i<m_size; i++)
  {
    if(m_data[i] == x)
    {
      return i;
    }
  }
  return -1;
}

//Clear an ArrayList
template <typename T>
void ArrayList<T> :: clear()
{
  delete[] m_data;
  m_data = NULL;
  m_size = 0;
  m_max = 0;

  return;
}

//Insert at Back
template <typename T>
void ArrayList<T>::insert_back(const T& x)
{
  insert(x, m_size);
}

//Insert
template <typename T>
void ArrayList<T>::insert(const T& x, int i)
{
  if(m_data == NULL)
  {
    m_max = 10;
    m_size = 0;
    m_data = new T[m_max];
  }

  if(i >= 0 && i <= m_size)
  {
    if(m_size < m_max)
    {
      for(int j = m_size - 1; j >= i; j--)
      {
        m_data[j + 1] = m_data[j];
      }

      m_data[i] = x;
      m_size++;
    }
    else
    {
      grow();
      insert(x, i);
    }
    return;
  }
  else
  {
    std::cout << "!-- ERROR : PANIC in ARRAYLIST!!.insert() (index out of bounds)" << std::endl;
  }
}

//Remove function
template <typename T>
void ArrayList<T> :: remove(int i)
{
  if (i >= 0 && i<m_size)
  {
    for(int j=i; j<m_size-1; j++)
    {
      m_data[j]=m_data[j+1];
    }
  }
  else
  {
    std::cout << "!-- ERROR : PANIC in ARRAYLIST!!.remove() (index out of bounds)" << std::endl;
  }

  if(m_size>0)
  {
    m_size--;
  }

  if(m_size < m_max / 4)
  {
    shrink();
  }


  return;
}


//Swap function
template <typename T>
void ArrayList<T> :: swap(int i, int k)
{
  if(i < m_size && k < m_size && i >= 0 && k >= 0)
  {
  T temp = m_data[i];
  m_data[i] = m_data[k];
  m_data[k] = temp;
  }
  else{
    std::cout << "!-- ERROR : PANIC in ARRAYLIST!!.swap() (index out of bounds)" << std::endl;
  }
  return;
}



//Append Function
template <typename T>
void ArrayList<T>::append(const ArrayList<T>& alist)
{
  if(alist.m_size != 0)
  {
    if(m_max >= m_size + alist.m_size)
    {
      int x = m_size;
      for(int i = 0; i < alist.m_size; i++)
      {
        m_data[i + x] = alist[i];
        m_size++;
      }
    }
    else
    {
      grow();
      append(alist);
    }
  }

}

template <typename T>
void ArrayList<T>::purge()
{
  T pos;
  for(int i = 0; i < m_size; i++)
  {
    pos = m_data[i];
    for(int j = i + 1; j < m_size; j++)
    {
      if(m_data[j] == pos)
      {
        remove(j);
        j--;
      }
    }
  }
}


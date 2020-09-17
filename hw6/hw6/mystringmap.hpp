/*
Programmer: Jeremy Ho
Date:   11/17/2017
Class : 1B
Purpose : mystringmap function definitions
*/

#include "mystringmap.h"

template <typename T>
const T& MyStringMap<T>::valueOf(const string& key) const throw (Oops)
{
  int home;              // Home position for k
  int pos = home = hash(key); // Initial position is home slot

  for(int i=1; (key != HT[pos].key()) && (EMPTYKEY != HT[pos].key()); i++)
  {
    pos = (home + i) % m_max; // Next on probe sequence
  }

  if(key == HT[pos].key())     // Found it
  {
    return HT[pos].value();
  }
  else
  {
    throw Oops("Key Not Found!!");  // key not in hash table
  }

}

template <typename T>
void MyStringMap<T>::clear()
{
  if(!isEmpty())
  {
    for(int i=0; i<m_max; i++)
    {
      HT[i].setKey(EMPTYKEY);
    }
    m_size = 0;
  }
}

template <typename T>
void MyStringMap<T>::insert(const string& key, const T& val)
{


  int home;                     // Home position for e
  int pos = home = hash(key);    // Init probe sequence

  for(int i=1; EMPTYKEY != HT[pos].key(); i++)
  {
   if (HT[pos].key() == key)
   {
      HT[pos].setValue(val);
      return;
   }
    pos = (home + i) % m_max; // probe
  }


  KVpair<string,T> temp(key, val);
  HT[pos] = temp;
  m_size++;
  if(m_size == m_max/2)
  {
		grow();
  }
}

template <typename T>
void MyStringMap<T>::remove(const string &k)
{
    int home;                     // Home position for e
    int pos = home = hash(k);        // Init probe sequence
    int i = 1;
    while(k != HT[pos].key() && HT[pos].key() != EMPTYKEY)
    {
      pos = (home + i) % m_max; // probe
      i++;
    }
    HT[pos].setKey(TOMB);
    m_size--;
}

template <typename T>
void MyStringMap<T>::print() const
{
	for(int i = 0; i < m_max; i++)
	{
    if (HT[i].key() != EMPTYKEY && HT[i].key() != TOMB)
    {
      cout << "< " << HT[i].key() << ", " << HT[i].value() << " >" << endl;
    }
	}
}

template <typename T>
int MyStringMap<T>::hash(const string &s) const
{

    unsigned int i, sum;
    for(sum=0, i=0; i<s.length(); i++)
    {
      sum += (int)s[i];
    }
    return sum % m_max;

}

template <typename T>
void MyStringMap<T>::grow()
{
	MyStringMap<T> temp(m_max, m_size); // Temp Hashtable with old max

  for (int i = 0; i < m_max; i++) // Hashtable data copied into temp
  {
    temp.HT[i] = HT[i];
  }

  m_max = m_max * 2; // Grows m_max by 2

	delete[] HT;
  HT = new KVpair<string, T>[m_max]; //Hashtable deleted and remade


	for(int k = 0; k < temp.m_max; k++)
	{
	  HT[k].setKey(EMPTYKEY);
		if(temp.HT[k].key() != EMPTYKEY && temp.HT[k].key() != TOMB)
		{
			insert(temp.HT[k].key(), temp.HT[k].value()); //Temp data moved back into new HT
			m_size--;
		}
	}
}

template <typename T>
MyStringMap<T>& MyStringMap<T>::operator = (const MyStringMap<T>& rhs)
{
    delete[] HT;
    m_max = rhs.m_max;
    m_size = rhs.m_size;
    EMPTYKEY = rhs.EMPTYKEY;
    TOMB = rhs.TOMB;
    for (int i = 0; i < m_max; i++)
    {
      HT[i] = rhs.HT[i];
    }
}

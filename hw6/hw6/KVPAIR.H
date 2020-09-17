// From the software distribution accompanying the textbook
// "A Practical Introduction to Data Structures and Algorithm Analysis,
// Third Edition (C++)" by Clifford A. Shaffer.
// Source code Copyright (C) 2007-2011 by Clifford A. Shaffer.

// Container for a key-value pair
template <typename Key, typename T>
class KVpair {
private:
  Key k;
  T e;

public:
  // Constructors
  KVpair(){}

  KVpair(Key kval, T eval)
  {
    k = kval;
    e = eval;
  }

  KVpair(const KVpair &o)  // Copy constructor
  {
    k = o.k;
    e = o.e;
  }

  void operator =(const KVpair &o) // Assignment operator
  {
    k = o.k;
    e = o.e;
  }

  // Data member access functions
  Key key()
  {
    return k;
  }

  void setKey(Key ink)
  {
    k = ink;
  }

  const T &value()
  {
    return e;
  }

  void setValue(T eval)
  {
    e = eval;
  }
};

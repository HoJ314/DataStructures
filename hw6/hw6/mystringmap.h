/*
Programmer: Jeremy Ho
Date:   11/17/2017
Class : 1B
Purpose : mystringmap functions
*/

#ifndef MYSTRINGMAP_H
#define MYSTRINGMAP_H
#include "abstractstringmap.h"
#include "KVpair.h"

#include <string>
#include <iostream>
using namespace std;



template <typename T>
class MyStringMap : public AbstractStringMap<T>
{
	private:
		int hash(const string &s) const;
    KVpair<string, T> *HT; //Hash table
		int m_max; // Size of HT
		int m_size; //Current # of elements in HT
		string EMPTYKEY; //User defined empty
		string TOMB; //Space

	public:
		MyStringMap()
		{
			m_size = 0;
			m_max = 8;
			EMPTYKEY = "";
			TOMB = " ";
      HT = new KVpair<string, T>[m_max]; // Make HT of m_max
      for(int i=0; i<m_max; i++)
      {
        HT[i].setKey(EMPTYKEY); // Initialize HT
      }
		}

    MyStringMap(int m, int s)
    {
			m_max = m;
			m_size = s;
			EMPTYKEY = "";
			TOMB = " ";
      HT = new KVpair<string, T>[m]; // Make HT of size m
      for(int i=0; i<m; i++)
      {
        HT[i].setKey(EMPTYKEY); // Initialize HT
      }
    }

		~MyStringMap()
		{
		  clear();
		  delete[] HT;
		}

		int size() const{return m_size;};

		int max() const{return m_max;};

		bool isEmpty() const{return m_size == 0;};

		const T& valueOf(const string& key) const throw (Oops);

		void clear();

		void insert(const string& key, const T& val);

		void remove(const string &k);

		void print() const;

		void grow();

    MyStringMap& operator = (const MyStringMap& rhs);

};


#include "mystringmap.hpp"
#endif

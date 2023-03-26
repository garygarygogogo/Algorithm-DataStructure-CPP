#pragma once
#include<iostream>
#include"map.h"


namespace gary
{
	template<class K>
	class set
	{
		struct KOft
		{
			const K& operator()(const K& k)
			{
				return k;
			}
		};
	private:
		RBTree<K, const K, KOft> _set;
	public:
		typedef typename RBTree<K, const K, KOft>::iterator iterator;
	public:
		iterator begin()
		{
			return _set.begin();
		}
		iterator end()
		{
			return _set.end();
		}
		pair<iterator,bool> insert(const K& key)
		{
			return _set.Insert(key);
		}
	};
}


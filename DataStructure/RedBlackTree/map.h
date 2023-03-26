#pragma once

#include<iostream>
#include"RBTree.h"
namespace gary
{
	template<class K,class V>
	class map
	{
		struct KOft
		{
			const K& operator()(const pair<const K,V>& kv)
			{
				return kv.first;
			}
		};
	private:
		RBTree<K, pair<const K,V>, KOft> _map;
	public:
		//typedef RBTreeIterator<K, V> iterator;
		//两种方式，但是下面这种由于模板没有实例化所以需要加typename
		typedef typename RBTree<K, pair<const K, V>, KOft>::iterator iterator;

	public:
		iterator begin()
		{
			return _map.begin();
		}
		iterator end()
		{
			return _map.end();
		}
		V& operator[](const K& key)
		{
			//找不到就插入
			//方法1：
			//iterator result = _map.find(key);
			//if(result == end())
			//{
			//	std::pair<iterator, bool> it = insert(std::make_pair( key,V()) );
			//	return it.first->second;
			//}
			//return result;
			//方法2：
			return (insert(make_pair(key,V())).first)->second;
		}
		
		pair<iterator,bool> insert(const pair<const K,V>& kv)
		{
			return _map.Insert(kv);
		}

	};
	void test_map()
	{
		map<string, string> dict;
		dict.insert(make_pair("sort", ""));
		dict.insert(make_pair("string", ""));
		dict.insert(make_pair("debug","a"));
		dict.insert(make_pair("set", ""));
		dict["make"];
		dict["debug"] = "x";
		dict["insert"] = "";

		map<string, string>::iterator it = dict.begin();
		while (it != dict.end())
		{
			cout << it->first << ":" << it->second << endl;
			++it;
		}
		cout << endl;
	}

}


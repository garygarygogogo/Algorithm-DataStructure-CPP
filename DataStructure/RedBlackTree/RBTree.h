#pragma once
#include<iostream>
#include<stack>
using std::stack;
using std::cout;
using std::endl;
#include<windows.h>
enum Color
{
	RED,
	BLACK
};
//T就是节点的值 pair<srting,int> string 之类的
template<class T>
class RBTreeNode
{
public:
	//const std::pair<const K, V>& data
	RBTreeNode(const T& data)
		:_col(RED)
		,_left(nullptr)
		,_right(nullptr)
		,_parent(nullptr)
		,_data(data)
	{
		//若加上了这个const K ，由于pair赋值 的时候是一个个赋值，由于const K不能被赋值，所以必须放在初始化列表处初始化，否则会报错
		//_data = data;
	}
	Color _col;
	RBTreeNode<T>* _left;
	RBTreeNode<T>* _right;
	RBTreeNode<T>* _parent;
	T _data;//std::pair<const K, V>
};

template<class T>
class RBTreeIterator
{
	typedef RBTreeNode<T> Node;
	typedef RBTreeIterator<T> Self;
private:
	Node* _node;
public:
	RBTreeIterator(Node* node)
		:_node(node)
	{}
	bool operator!=(const Self& it)
	{
		return _node != it._node;
	}
	bool operator==(const Self& it)
	{
		return _node == it._node;
	}
	T* operator->()
	{
		return &(_node->_data);
	}
	Self& operator++()
	{
		Increament();
		return *this;
	}
	Self& operator--()
	{
		DeIncreament();
		return *this;
	}

	void Increament()
	{
		if (_node->_right)
		{
			_node = _node->_right;
			while (_node->_left)
			{
				_node = _node->_left;
			}
		}
		else
		{
			
			Node* pre = _node;
			_node = _node->_parent;
			while (_node->_right == pre)
			{
				pre = _node;
				_node = _node->_parent;
			}
			//特殊情况分析，与内核实现不同，我是定义前指针，源代码是父指针，这种情况当头节点没有右孩子的时候，头节点会在同一个位置死循环
			//所以加上后面的条件解决这种情况。
			if (pre->_right == _node)
			{
				_node = pre;
			}
		}
	}
	void DeIncreament()
	{
		//通过虚拟头节点的颜色辨别是头节点还是虚拟节点，太优雅了。
		if (_node->_parent->_parent == _node && _node->_col == RED)
		{
			_node = _node->_right;
			return;
		}
		if (_node->_left)
		{
			_node = _node->_left;
			while (_node->_right)
			{
				_node = _node->_right;
			}
		}
		else
		{
			Node* pre = _node;
			_node = _node->_parent;
			while (_node->_left == pre)
			{
				pre = _node;
				_node = _node->_parent;
			}
		}
	}


	T& operator*()
	{
		return _node->_data;
	}
};


template<class K,class T,class KOfT>
class RBTree
{
	typedef RBTreeNode<T> Node;
public:
	typedef RBTreeIterator<T> iterator;
private:
	Node* _head;
private:

	bool isRRTree(Node* head)
	{
		if (head == nullptr)
			return true;
		if (head->_col == RED)
		{
			if (head->_left && head->_left->_col == RED)
			{
				cout << "红色与红色相连接" << endl;
				return false;
			}
			if (head->_right && head->_right->_col == RED)
			{
				cout << "红色与红色相连接" << endl;
				return false;
			}
		}
		return isRRTree(head->_left) && isRRTree(head->_right);
	}
		bool RBDistance(Node * head, int beach, int count)
		{
			if (head == nullptr)
			{
				if (count != beach)
				{
					cout << "每条路径的黑色节点不相同" << endl;
					return false;
				}
				return true;
			}
			return RBDistance(head->_left, beach, head->_col == BLACK ? count + 1 : count)
				&& RBDistance(head->_right, beach, head->_col == BLACK ? count + 1 : count);
		}
		bool rbOrder()
		{
			stack<Node*> st;
			Node* cur = GetHead();
			while (cur)
			{
				st.push(cur);
				cur = cur->_left;
			}
			Node* pre = nullptr;
			while (!st.empty())
			{
				Node* top = st.top();
				st.pop();
				if (pre && pre->_data.first > top->_data.first)
				{
					cout << "不是有序的" << endl;
					return false;
				}
				top = top->_right;
				while (top)
				{
					st.push(top);
					top = top->_left;
				}
			}
			return true;
		}
public:
	//构造函数，制造哨兵位的头节点
	RBTree()
	{
		_head = new Node(T());
		_head->_left = _head;
		_head->_right = _head;
		_head->_parent = nullptr;//通过_parent可以得知真正的头
	}
	Node* GetHead()
	{
		return _head->_parent;
	}
	iterator begin()
	{
		//开始是最左节点
		Node* cur = GetHead();
		while (cur && cur->_left)
		{
			cur = cur->_left;
		}
		return iterator(cur);
	}
	iterator end()
	{
		//结尾是哨兵位的头节点
		return iterator(_head);
	}

	//没有添加哨兵位头节点的做法
	//iterator begin2()
	//{
	//	Node* cur = _head;
	//	while (cur->_right)
	//	{
	//		cur = cur->_right;
	//	}
	//
	//	return iterator(cur);
	//}
	//iterator end2()
	//{
	//	//Node* cur = _head;
	//	//while (cur->_right)
	//	//{
	//	//	cur = cur->_right;
	//	//}
	//	//return iterator(cur);
	//	return iterator(nullptr);
	//}
	//void RotateR(Node* parent)
	//{
	//	Node* left = parent->_left;
	//	Node* lRight = left->_right;
	//	Node* pParent = parent->_parent;
	//	if (lRight)
	//	{
	//		lRight->_parent = parent;
	//	}
	//	parent->_left = left->_right;
	//	left->_right = parent;
	//	parent->_parent = left;
	//	if(lRight)
	//	lRight->_parent = parent;
	//	left->_parent = pParent;//指向父节点
	//	if (pParent)
	//	{
	//		if (pParent->_data.first > left->_data.first)
	//		{
	//			pParent->_left = left;
	//		}
	//		else
	//		{
	//			pParent->_right = left;
	//		}
	//	}
	//	else
	//	{
	//		_head->_parent = left;
	//	}

	//}
	void RotateR(Node* parent)
	{
		Node* left = parent->_left;
		Node* lRight = left->_right;
		Node* pParent = parent->_parent;
		bool isRight = pParent->_right == parent ? true : false;
		parent->_left = lRight;
		parent->_parent = left;
		left->_parent = pParent;
		if (lRight)
		{
			lRight->_parent = parent;
		}
		left->_right = parent;
		//由于根的变化，所以这里的逻辑需要改变
		if (pParent == _head)
		{
			pParent->_parent = left;
			return;
		}
		if (isRight)
		{
			pParent->_right = left;
		}
		else
		{
			pParent->_left = left;
		}
	}

	void RotateL(Node* parent)
	{
		Node* right = parent->_right;
		Node* rLeft = right->_left;
		Node* pParent = parent->_parent;
		bool isRight = pParent->_right == parent ? true : false;
		parent->_right = rLeft;
		if (rLeft)
		{
			rLeft->_parent = parent;
		}
		parent->_parent = right;
		right->_left = parent;
		right->_parent = pParent;
		//如果是哨兵位的头节点，此时左右不能用于连接
		if (pParent == _head)
		{
			pParent->_parent = right;
			return;
		}
		if (isRight)
		{
			pParent->_right = right;
		}
		else
		{
			pParent->_left = right;
		}
	}
	Node* LeftMost()
	{
		Node* cur = GetHead();
		while (cur && cur->_left)
		{
			cur = cur->_left;
		}
		return cur;
	}
	Node* RightMost()
	{
		Node* cur = GetHead();
		while (cur && cur->_right)
		{
			cur = cur->_right;
		}
		return cur;
	}

	bool IsRBTree()
	{
		bool rr = isRRTree(GetHead());
		int beach = 0;
		Node* cur = GetHead();
		while (cur)
		{
			if(cur->_col == BLACK)
			beach++;
			cur = cur->_left;
		}
		bool rbdistance = RBDistance(GetHead(),beach,0);
		bool order = rbOrder();

		return rr && rbdistance && order;
	}

	iterator find(const K& key)
	{
		Node* cur = _head->_parent;
		if (cur == nullptr)
			return iterator(_head);
		KOfT koft;
		while (cur)
		{
			if (koft(cur->_data) > key)
			{
				cur = cur->_left;
			}
			else if (koft(cur->_data) < key)
			{
				cur = cur->_right;
			}
			else
			{
				return cur;
			}
		}
		return iterator(_head);
	}

	pair<iterator,bool> Insert(const T& data)
	{
		KOfT koft;
		// 由于这个地方没法判断T的类型，所以要取key值需要仿函数的帮助
		const K& key = koft(data);
		Node* newNode = new Node(data);
		Node* trueHead = _head->_parent;
		if (trueHead == nullptr)
		{
			//头节点和虚拟节点的相互指向
			//newNode 就是下一次的trueHead,这个地方需要更新虚拟节点的左右节点
			_head->_parent = newNode;	
			newNode->_parent = _head;
			_head->_left = newNode;
			_head->_right = newNode;
			newNode->_col = BLACK;
			return pair<iterator,bool>(iterator(newNode),true);
		}
		//printf("%p\n", _head);
		Node* cur = trueHead;
		Node* parent = nullptr;
		while (cur)
		{
			parent = cur;
			if (koft(cur->_data) > key)
			{
				cur = cur->_left;
			}
			else if (koft(cur->_data) < key)
			{
				cur = cur->_right;
			}
			else
			{
				delete newNode;
				//已经存在的话直接返回即可
				return pair<iterator,bool>(iterator(cur),false);//键值冗余
			}
		}
		if (koft(parent->_data) > key)
		{
			parent->_left = newNode;
			newNode->_parent = parent;
		}
		else
		{
			parent->_right = newNode;
			newNode->_parent = parent;
		}

		//此时需要调整节点的颜色
		//parent此时是父亲节点
		while (parent->_col == RED && parent != _head )//parent->parent is bug,because i modify the struct.
		{
			if (parent->_col == BLACK)
			{
				break;
			}
			else if (parent->_col == RED)
			{
				Node* g = parent->_parent;
				Node* uncle = g->_left == parent ? g->_right : g->_left;
				if (uncle && uncle->_col == RED)
				{
					//情况一：优先判断，这种情况处理方式更简单
					uncle->_col = parent->_col = BLACK;
					g->_col = RED;
					//向上迭代，此时g相当于新插入节点
					parent = g->_parent;
					newNode = g;//这个很重要
					continue;
				}
				else
				{
					//第二种情况，需要翻转
					//要么uncle不存在，要么uncle为黑
					//需要判断是否是左右或者右左结构
					if (g->_left == parent)
					{
						if (parent->_left == newNode)
						{
							//右单旋
							RotateR(g);
							parent->_col = BLACK;
							g->_col = RED;
						}
						else
						{
							//左右双旋
							RotateL(parent);
							RotateR(g);
							newNode->_col = BLACK;
							g->_col = RED;
						}
					}
					else
					{
						if (parent->_right == newNode)
						{
							//左单旋
							RotateL(g);
							g->_col = RED;
							parent->_col = BLACK;
						}
						else
						{
							//右左双旋
							RotateR(parent);
							RotateL(g);
							newNode->_col = BLACK;
							g->_col = RED;
						}
					}
					break;
				}
			}
		}
		//这里的头会发生变化吗？
		trueHead = GetHead();
		trueHead->_col = BLACK;//旋转过后的结果需要将头部置成黑色。
		Node* leftMost = LeftMost();
		//cout << "leftMost" << leftMost << leftMost->_data.first << endl;
		//虚拟头节点的左右需要重新指向
		_head->_left = leftMost;//方便++ --
			
		Node* rightMost = RightMost();
		//cout << "rightMost" << rightMost << endl;
		_head->_right = rightMost;//方便++ --
		//Sleep(1000);
		return pair<iterator,bool>(iterator(newNode),true);
	}
	
};


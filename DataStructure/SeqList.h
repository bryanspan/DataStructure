#include<iostream>
using namespace std;

//顺序表
class SeqList
{
public:
	//构造函数，接受一个默认的列表大小
	SeqList(int size = MAX_LIST_SIZE);
	//析构函数，释放elems占用的内存空间
	~SeqList();
	//清空表
	void clear();
	//判断表是否为空
	bool isEmpty();
	//获得表的当前元素个数
	int getLength();
	//在第pos个元素位置之前插入一个新元素
	bool insertElem(int pos, int elem);
	//删除第pos个元素
	bool deleteElem(int pos);
	//打印表中元素
	void print();
	int *elems;//表元素，
private:
	static const int MAX_LIST_SIZE;
	int m_length;//表的元素个数
	int m_size;//表的当前最大长度
};

const int SeqList::MAX_LIST_SIZE = 100;

SeqList::SeqList(int size)
{
	//size不可以小于零，也不可以超过系统规定最大长度
	//否则做截断处理
	if (size > MAX_LIST_SIZE)
	{
		m_size = MAX_LIST_SIZE;
	}
	else if (size < 0)
	{
		m_size = 0;
	}
	else
	{
		m_size = size;
	}

	elems = new int[m_size];
	m_length = 0;


	if (!elems)
	{
		cout << "Space allocate failed!" << endl;
	}
}

SeqList :: ~SeqList()
{
	delete[]elems;
}

void SeqList::clear()
{
	m_length = 0;
}

bool SeqList::isEmpty()
{
	if (m_length == 0)
	{
		return  true;
	}
	else
	{
		return false;
	}
}

int SeqList::getLength()
{
	return m_length;
}

bool SeqList::insertElem(int pos, int elem)
{
	if (m_length == m_size)
	{
		cout << "List is Full" << endl;
		return false;
	}

	if (pos < 1 || pos > m_length + 1)
	{
		cout << "Over Bound!" << endl;
		return false;
	}

	//插入位置之后元素后移
	for (int i = m_length; i >= pos - 1; --i)
	{
		elems[i + 1] = elems[i];
	}

	elems[pos - 1] = elem;
	m_length++;
	return true;
}

bool SeqList::deleteElem(int pos)
{
	if (pos < 1 || pos > m_length)
	{
		return false;
	}

	for (int i = pos - 1; i <= m_length - 1; ++i)
	{
		elems[i] = elems[i + 1];
	}

	m_length--;
	return false;
}

void SeqList::print()
{
	for (int i = 0; i < m_length; ++i)
	{
		cout << elems[i] << " ";
	}
	cout << endl;
}

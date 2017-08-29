#include<iostream>
using namespace std;

//˳���
class SeqList
{
public:
	//���캯��������һ��Ĭ�ϵ��б��С
	SeqList(int size = MAX_LIST_SIZE);
	//�����������ͷ�elemsռ�õ��ڴ�ռ�
	~SeqList();
	//��ձ�
	void clear();
	//�жϱ��Ƿ�Ϊ��
	bool isEmpty();
	//��ñ�ĵ�ǰԪ�ظ���
	int getLength();
	//�ڵ�pos��Ԫ��λ��֮ǰ����һ����Ԫ��
	bool insertElem(int pos, int elem);
	//ɾ����pos��Ԫ��
	bool deleteElem(int pos);
	//��ӡ����Ԫ��
	void print();
	int *elems;//��Ԫ�أ�
private:
	static const int MAX_LIST_SIZE;
	int m_length;//���Ԫ�ظ���
	int m_size;//��ĵ�ǰ��󳤶�
};

const int SeqList::MAX_LIST_SIZE = 100;

SeqList::SeqList(int size)
{
	//size������С���㣬Ҳ�����Գ���ϵͳ�涨��󳤶�
	//�������ضϴ���
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

	//����λ��֮��Ԫ�غ���
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

#include<iostream>
#include"SeqList.h"

using namespace std;



int main()
{
	SeqList myList;

	for (int i = 1; i <= 10; ++i)
	{
		myList.insertElem(1, i);
	}

	myList.print();

	cout << "Length= " << myList.getLength() << endl;

	myList.deleteElem(5);

	myList.print();

	cout << "Length= " << myList.getLength() << endl;

	myList.clear();

	cout << myList.isEmpty() << endl;

	return 0;
}
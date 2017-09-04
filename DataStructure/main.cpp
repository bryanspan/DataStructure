#include<iostream>
#include<string>
#include"SeqList.h"
#include <vector>
using namespace std;

//二维数组中的查找
bool find(int, vector<vector<int>>);
//替换空格
char* replaceSpace(char *, int);
//从尾到头打印链表
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x):
		val(x), next(NULL){}
};
vector<int> printListFromTailToHead(ListNode* head);



int main()
{
	/*二维数组查找*/
	//vector<vector<int>> test = { {1,4,6,9}, {2,5,8,10}, {4,7,10,12} };
	//if (find(4, test))
	//	cout << "Finded" << endl;
	//else
	//	cout << "Not Find" << endl;
	//return 0;

	/*替换空格*/
	replaceSpace("hello world",14);
}



//  题目描述 二维数组中的查找
/*  在一个二维数组中，每一行都按照从左到右递增的顺序排序，
    每一列都按照从上到下递增的顺序排序。请完成一个函数，
	输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。
	{
	{1,3,6,9},
	{2,5,8,12},
	{3,8,12,34}
	}
	思路：输入的矩阵从左至右递增，从上到下递增，
		  从左下角开始查找，
		  当要查找的数字比左下角数字大时，向右移动继续查找
		  若小于当前的数字，则向上移动
*/
bool find(int target, vector<vector<int>> array)
{
	int rowCount = array.size();
	int colCount = array[0].size();
	int i, j;
	for (i = rowCount - 1, j = 0; i >= 0 && j < colCount;)
	{
		if (target == array[i][j])
			return true;
		if (target < array[i][j])
		{
			i--;
			continue;
		}
		if (target>array[i][j])
		{
			j++;
			continue;
		}
	}
	return false;

}

//
//题目描述
//请实现一个函数，将一个字符串中的空格替换成“%20”。
//例如，当字符串为We Are Happy.则经过替换之后的字符串为We%20Are%20Happy。
/*思路：先计算出有多少空格 需要多少的空间，然后从后往前移动字符 这样移动的
  次数比较少*/

//牛客过不了 懵逼 
//上Python         s = s.replace(' ','%20') done！！
char* replaceSpace(char *str, int length)
{
    int i = 0;
	int j = 0;
	int nSpace = 0;
	char *pStr = NULL;
	pStr = (char*)malloc(sizeof(char)*length * 3);
	for (i = 0, j = 0; i<length; i++, j++)
	{
		if (' ' == str[i])
		{
			pStr[j] = '\%';
			pStr[++j] = '2';
			pStr[++j] = '0';
		}
		else
		{
			pStr[j] = str[i];
		}

	}
	str = pStr;
	cout << str;
	free(pStr);
	return pStr;	
}

/*题目描述
输入一个链表，从尾到头打印链表每个节点的值。*/
vector<int> printListFromTailToHead(ListNode* head)
{

}
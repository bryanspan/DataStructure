#include<iostream>
#include<string>
#include"SeqList.h"
#include <vector>
using namespace std;

//��ά�����еĲ���
bool find(int, vector<vector<int>>);
//�滻�ո�
char* replaceSpace(char *, int);
//��β��ͷ��ӡ����
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x):
		val(x), next(NULL){}
};
vector<int> printListFromTailToHead(ListNode* head);



int main()
{
	/*��ά�������*/
	//vector<vector<int>> test = { {1,4,6,9}, {2,5,8,10}, {4,7,10,12} };
	//if (find(4, test))
	//	cout << "Finded" << endl;
	//else
	//	cout << "Not Find" << endl;
	//return 0;

	/*�滻�ո�*/
	replaceSpace("hello world",14);
}



//  ��Ŀ���� ��ά�����еĲ���
/*  ��һ����ά�����У�ÿһ�ж����մ����ҵ�����˳������
    ÿһ�ж����մ��ϵ��µ�����˳�����������һ��������
	����������һ����ά�����һ���������ж��������Ƿ��и�������
	{
	{1,3,6,9},
	{2,5,8,12},
	{3,8,12,34}
	}
	˼·������ľ���������ҵ��������ϵ��µ�����
		  �����½ǿ�ʼ���ң�
		  ��Ҫ���ҵ����ֱ����½����ִ�ʱ�������ƶ���������
		  ��С�ڵ�ǰ�����֣��������ƶ�
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
//��Ŀ����
//��ʵ��һ����������һ���ַ����еĿո��滻�ɡ�%20����
//���磬���ַ���ΪWe Are Happy.�򾭹��滻֮����ַ���ΪWe%20Are%20Happy��
/*˼·���ȼ�����ж��ٿո� ��Ҫ���ٵĿռ䣬Ȼ��Ӻ���ǰ�ƶ��ַ� �����ƶ���
  �����Ƚ���*/

//ţ�͹����� �±� 
//��Python         s = s.replace(' ','%20') done����
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

/*��Ŀ����
����һ��������β��ͷ��ӡ����ÿ���ڵ��ֵ��*/
vector<int> printListFromTailToHead(ListNode* head)
{

}
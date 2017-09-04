#include<iostream>
#include<string>
#include"SeqList.h"
#include <vector>
using namespace std;

//1����ά�����еĲ���
bool find(int, vector<vector<int>>);
//2���滻�ո�
char* replaceSpace(char *, int);
//3����β��ͷ��ӡ����
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x):
		val(x), next(NULL){}
};
vector<int> printListFromTailToHead(ListNode* head);
//4���ؽ�������
struct TreeNode{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) :val(x), left(NULL), right(NULL){}
};
TreeNode* reConstructBinaryTree(vector<int> pre, vector<int> vin);



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



//  1����Ŀ���� ��ά�����еĲ���
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
//2����Ŀ����
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

/*3����Ŀ����
����һ��������β��ͷ��ӡ����ÿ���ڵ��ֵ��
Solution 1
�����β��ͷ��������õݹ�ʵ�֣���ʹ�ÿ⺯��ֱ��printf�����ʹ�õݹ�ȽϺ�
Solution 2
�ÿ⺯����ÿ��ɨ��һ���ڵ㣬���ý�����ݴ���vector�У�����ýڵ�����һ����㣬����һ�����
����ֱ�Ӳ���vector��ǰ�棬ֱ�������꣬
Solution 3
���ߣ�ֱ�Ӽ������������reverse*/

//Solution 1 
vector<int> printListFromTailToHead(ListNode* head)
{
	vector<int> listVec;
	while (head != NULL)
	{
		listVec.insert(listVec.begin(), head->val);
		if (head->next != NULL)
		{
			vector<int> tempVec = printListFromTailToHead(head->next);
			if (tempVec.size() > 0)
				listVec.insert(listVec.begin(), tempVec.begin(), tempVec.end());
		}
	}
	return listVec;
}

//Solution 2  time:2ms space:620k
vector<int> printListFromTailToHead(ListNode* head)
{
	vector<int> listVec;
	while (head != NULL)
	{
		listVec.insert(listVec.begin(), head->val);
		head = head->next;
	}
	return listVec;
}


//Solution 3  time:1ms  space:500k
vector<int> printListFromTailToHead(ListNode* head)
{
	vector<int> listNodeVec;
	while (head != NULL)
	{
		listNodeVec.push_back(head->val);
		head = head -> next;
	}
	return vector<int>(listNodeVec.rbegin, listNodeVec.rend);

}

/*
4���ؽ�������
��Ŀ������
����ĳ��������ǰ���������������Ľ����
���ؽ����ö����������������ǰ���������������Ľ���ж������ظ������֡�
��������ǰ���������{1,2,4,7,3,5,6,8}
�������������{4,7,2,1,5,3,8,6}�����ؽ������������ء�
*/
TreeNode* reConstructBinaryTree(vector<int> pre, vector<int> vin)
{

}
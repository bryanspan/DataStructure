#include<iostream>
#include<string>
#include"SeqList.h"
#include <vector>
#include <stack>
#include<math.h>
using namespace std;

//1、二维数组中的查找
bool find(int, vector<vector<int>>);
//2、替换空格
char* replaceSpace(char *, int);
//3、从尾到头打印链表
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x):
		val(x), next(NULL){}
};
vector<int> printListFromTailToHead(ListNode* head);
//4、重建二叉树
struct TreeNode{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) :val(x), left(NULL), right(NULL){}
};
TreeNode* reConstructBinaryTree(vector<int> pre, vector<int> vin);

//5、用两个栈实现队列
stack<int> stack1;
stack<int> stack2;
void push(int);
int pop();

//6、旋转数组的最小数字
int minNumberInRotateArray(vector<int> rotateArray);

//7、斐波那契数列
int Fibonacci(int);

//8、跳台阶
int jumpFloor(int);

//9、变态跳台阶
int jumpFloorII(int);

//10、矩形覆盖
int rectCover(int number);

//11、二进制中1的个数
int  NumberOf1(int);

//12、数值的整数次方
double Power(double, int);

//13、调整数组顺序使奇数位于偶数前面
void reOrderArray(vector<int> &);

//14、链表中倒数第k各节点
//节点struct定义见3
ListNode* FindKthToTail(ListNode* , unsigned int);

//15、反转链表
ListNode* ReverseList(ListNode* );

//16、合并两个排序的链表
ListNode* Merge(ListNode* , ListNode* );

int main()
{
	/*1-二维数组查找*/
	//vector<vector<int>> test = { {1,4,6,9}, {2,5,8,10}, {4,7,10,12} };
	//if (find(4, test))
	//	cout << "Finded" << endl;
	//else
	//	cout << "Not Find" << endl;
	//return 0;

	/*2-替换空格*/
	//replaceSpace("hello world",14);

	/*4-重建二叉树*/
	//vector<int> pre = { 1, 2, 4, 7, 3, 5, 6, 8 };
	//vector<int> vin = { 4, 7, 2, 1, 5, 3, 8, 6 };
	//TreeNode *node  =  reConstructBinaryTree(pre, vin);

	/*5、用两个栈实现队列*/
	//push(5);
	//push(6);
	//push(7);
	//push(8);
	//cout << pop();
	//cout << pop();
	//cout << pop();
	//cout << pop();

	/*6 旋转数组的最小数字*/
	//vector<int> rotateArray = {3,4,5,6,1,2};
	//cout<<minNumberInRotateArray(rotateArray);

	/*7、斐波那契数列*/
	//cout << Fibonacci(39);


	/*11 二进制中1的个数*/
	cout<<NumberOf1(5);
}



//  1、题目描述 二维数组中的查找
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
//2、题目描述
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

/*3、题目描述
输入一个链表，从尾到头打印链表每个节点的值。
Solution 1
链表从尾到头输出，利用递归实现，不使用库函数直接printf输出，使用递归比较好
Solution 2
用库函数，每次扫描一个节点，将该结点数据存入vector中，如果该节点有下一个结点，将下一个结点
数据直接插入vector最前面，直至遍历完，
Solution 3
或者，直接加在最后最后调用reverse*/

//Solution 1 
//vector<int> printListFromTailToHead(ListNode* head)
//{
//	vector<int> listVec;
//	while (head != NULL)
//	{
//		listVec.insert(listVec.begin(), head->val);
//		if (head->next != NULL)
//		{
//			vector<int> tempVec = printListFromTailToHead(head->next);
//			if (tempVec.size() > 0)
//				listVec.insert(listVec.begin(), tempVec.begin(), tempVec.end());
//		}
//	}
//	return listVec;
//}

//Solution 2  time:2ms space:620k
//vector<int> printListFromTailToHead(ListNode* head)
//{
//	vector<int> listVec;
//	while (head != NULL)
//	{
//		listVec.insert(listVec.begin(), head->val);
//		head = head->next;
//	}
//	return listVec;
//}


//Solution 3  time:1ms  space:500k
//vector<int> printListFromTailToHead(ListNode* head)
//{
//	vector<int> listNodeVec;
//	while (head != NULL)
//	{
//		listNodeVec.push_back(head->val);
//		head = head -> next;
//	}
//	return vector<int>(listNodeVec.rbegin, listNodeVec.rend);
//
//}

/*
4、重建二叉树
题目描述：
输入某二叉树的前序遍历和中序遍历的结果，
请重建出该二叉树。假设输入的前序遍历和中序遍历的结果中都不含重复的数字。
例如输入前序遍历序列{1,2,4,7,3,5,6,8}
和中序遍历序列{4,7,2,1,5,3,8,6}，则重建二叉树并返回。

思路：先序遍历的第一个节点肯定是二叉树的根节点root，
中序遍历中根节点在中间位置M，
M左边的也就是root的左子树的中序遍历结果<left-in>，
M右边的就是root的右子树的中序遍历结果<right-in>，
另外，在先序遍历中，第二个位置到位置M,是root左子树的先序子数组<left-pre>，
剩下的位置M之后的就是root右子树的先序子数组<right-pre>，
找到这四个数组然后左右递归调用即可。
*/
TreeNode* reConstructBinaryTree(vector<int> pre, vector<int> vin)
{
	//节点数量
	int nodeSize = vin.size(); 
	if (nodeSize == 0)
		return NULL;

	//声明左右前序中序四个数租
	vector<int> left_in, left_pre, right_in, right_pre;

	//先序遍历的第一个节点就是二叉树的根节点
	int rootVal = pre[0];   

	// 构造树 以先序遍历的第一个节点为根节点
	TreeNode* node = new TreeNode(rootVal);

	int rootLocIIn = 0;

	//在中序遍历中找到根节点的位置 
	for (rootLocIIn; rootLocIIn < nodeSize; ++rootLocIIn){
		if (vin[rootLocIIn] == rootVal)
			break;
	}

	for (int i = 0; i < nodeSize; ++i){
		if (i < rootLocIIn){

			//中序遍历中位置p左边是root左子树的中序遍历结果
			left_in.push_back(vin[i]);
	
			//先序遍历中第二个位置到位置p是root左子树的先序遍历结果
			left_pre.push_back(pre[i + 1]);
		}

		else if (i > rootLocIIn){			
			//中序遍历中位置P之后的是root右子树的中序遍历结果
			right_in.push_back(vin[i]);

			//先序遍历中位置P之后的是root右子树的先序遍历结果
			right_pre.push_back(pre[i]);
		}
	}

	//递归调用构造根节点左右子树
	node->left = reConstructBinaryTree(left_pre, left_in);
	node->right = reConstructBinaryTree(right_pre, right_in);
	return node;
}

/*5、用两个栈实现队列
题目描述：
用两个栈来实现一个队列，完成队列的Push和Pop操作。 队列中的元素为int类型。
思路：
stack2作为中转栈，将已经push进stack1的元素push进stack2 当需要pop时直接从stack2的栈顶取值
*/
void push(int node)
{
	//if (stack2.empty())
	//{
		stack1.push(node);
	//}
	//else
	//{
	//	while (!stack2.empty())
	//	{
	//		stack1.push(stack2.top());
	//		stack2.pop();
	//	}
	//	stack1.push(node);
	//}

	//cout << stack1.size();
}
int pop()
{
	int temp = 0;
	if (!stack2.empty())
	{
		temp = stack2.top();
		stack2.pop();
		return temp;
	}
	else
	{
		while (!stack1.empty())
		{
			stack2.push(stack1.top());
			stack1.pop();
		}
		temp = stack2.top();
		stack2.pop();
		return temp;

	}
}

/*6、旋转数组的最小数字
题目描述：
把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。 
输入一个非递减排序的数组的一个旋转，输出旋转数组的最小元素。 
例如数组{3,4,5,1,2}为{1,2,3,4,5}的一个旋转，该数组的最小值为1。 
NOTE：给出的所有元素都大于0，若数组大小为0，请返回0。

思路：
1、顺序遍历，找最小值
2、顺序遍历vector，找到第一个大于下一个数的数
3、二分查找
*/
int minNumberInRotateArray(vector<int> rotateArray)
{
	if (rotateArray.size() == 0)
		return 0;
	//
	//else
	//{
	//	vector<int>::iterator it = rotateArray.begin();
	//	for (it; it != rotateArray.end(); it++)
	//	{
	//		if ((it + 1) != rotateArray.end() && *it > *(it + 1))
	//			return *(it + 1);
	//			
	//	}
	//	return rotateArray[0];

	//}
	else
	{
		int left = 0;
		int right = rotateArray.size()-1;
		int middle = 0;
		while (left < right)
		{
			middle = left + (right - left) / 2;
			if (rotateArray[middle] >rotateArray[right])
			{
				left = middle + 1;
			}
			else if (rotateArray[middle] == rotateArray[right])
			{
				right = right - 1;
			}
			else
			{
				right = middle;
			}
		}
		return rotateArray[left];


	}
}

/* 7、斐波那契数列
题目描述
大家都知道斐波那契数列，现在要求输入一个整数n，请你输出斐波那契数列的第n项。
n<=39
*/
int Fibonacci(int n)
{
	//菜鸡 太耗时 过不了
	//if (n == 1)
	//	return 1;
	//else if (n == 2)
	//	return 1;
	//else
	//	return Fibonacci(n-1) + Fibonacci(n - 2);
	
	//一般
	//if (n == 0)
	//	return 0;
	//else if(n == 1 || n == 2)
	//	return 1;
	//else if(n == 3)
	//	return 2;
	//else
	//	return 3*Fibonacci(n - 3) + 2 * Fibonacci(n - 4);

	//扫地僧
	int f = 0, g = 1;
	while (n-- > 0) {
		g += f;
		f = g - f;
	}
	return f;
}

/*8、跳台阶
题目描述
一只青蛙一次可以跳上1级台阶，也可以跳上2级。求该青蛙跳上一个n级的台阶总共有多少种跳法。
思路：又是递归
*/
int jumpFloor(int number) 
{
	if (number < 0)
		return -1;
	if (number == 1)
		return 1;
	if (number == 2)
		return 2;
	else
		return jumpFloor(number - 1) + jumpFloor(number - 2);
}

/*9、变态跳台阶
一只青蛙一次可以跳上1级台阶，也可以跳上2级……它也可以跳上n级。
求该青蛙跳上一个n级的台阶总共有多少种跳法。
思路：
2^(n-1)
*/
int jumpFloorII(int number)
{
	if (number<0)
		return -1;
	if (number == 1)
		return 1;
	int temp = 1;

	while (number>1)
	{
		temp = temp * 2;
		number--;
	}
	return temp;
}

/*10、矩形覆盖
题目描述
我们可以用2*1的小矩形横着或者竖着去覆盖更大的矩形。
请问用n个2*1的小矩形无重叠地覆盖一个2*n的大矩形，总共有多少种方法？
思路：递归 扫地僧
*/
int rectCover(int number)
{
	if (number == 0)
		return 0;
	int f = 1, g = 1;
	while (number-->0)
	{
		g = g + f;
		f = g - f;
	}
	return f;
}
/*11、二进制中1的个数
题目描述
输入一个整数，输出该数二进制表示中1的个数。其中负数用补码表示。
*/
int  NumberOf1(int n)
{
	int c = 0;
	for (c; n; ++c)
	{
		n &= (n - 1);
	}
	return c;

}
/*12、数值的整数次方
题目描述
给定一个double类型的浮点数base和int类型的整数exponent。
求base的exponent次方。
*/
double Power(double base, int exponent)
{
	if (exponent == 0)
		return 1;
	if (exponent < 0)
		return 1.0 / Power(base, exponent * (-1));
	else
	{
		double result = 1.0;
		while (exponent>0)
		{
			result = result * base;
			exponent--;
		}
		return result;
	}
}

/*13、调整数组顺序使奇数位于偶数前面
题目描述
输入一个整数数组，实现一个函数来调整该数组中数字的顺序，
使得所有的奇数位于数组的前半部分，所有的偶数位于位于数组的后半部分，
并保证奇数和奇数，偶数和偶数之间的相对位置不变。
思路：另外开辟一个数组
遍历两次原数组 先push_back奇数 再push_back偶数
*/
void reOrderArray(vector<int> &array)
{
	int length = array.size();
	vector<int> temp;
	for (int i = 0; i < length; i++)
	{
		if (array[i] % 2 != 0)
		{
			temp.push_back(array[i]);
		}
	}
	for (int j = 0; j < length - 1; j++)
	{
		if (array[j] % 2 == 0)
		{
			temp.push_back(array[j]);
		}
	}
	array = temp;
}
/*14、链表中倒数第k各节点
题目描述
输入一个链表，输出该链表中倒数第k个结点。
*/
ListNode* FindKthToTail(ListNode* pListHead, unsigned int k)
{
	//if (pListHead != NULL)
	//{
	//	int size = 0;
	//	ListNode* temp = new ListNode(0);
	//	temp = pListHead;
	//	while (temp != NULL)
	//	{
	//		++size;
	//		temp = temp->next;
	//	}
	//	int loc = size - k + 1;
	//	while (loc > 0)
	//	{
	//		pListHead = pListHead->next;
	//		loc--;
	//	}
	//	return pListHead;
	//}
	//else
	//	return NULL;
	ListNode* p, *q;
	p = q = pListHead;
	int i = 0;
	for (; p != NULL; i++)
	{
		if (i >= k)
			q = q->next;
		p = p->next;
	}
	return i < k ? NULL : q;

}
/*15、反转链表
题目描述
输入一个链表，反转链表后，输出链表的所有元素。
思路：
从第2个节点到第N个节点，依次逐节点插入到第1个节点(head节点)之后，最后将第一个节点挪到新表的表尾。
*/
ListNode* ReverseList(ListNode* pHead)
{
	ListNode* hNext;
	ListNode* temp;
	if (pHead == NULL || pHead->next == NULL)
		return pHead;
	hNext = pHead->next;
	while (hNext->next != NULL)
	{
		temp = hNext->next;
		hNext->next = temp->next;
		temp->next = pHead->next;
		pHead->next = temp;
	}

	hNext->next = pHead;
	pHead = hNext->next->next;
	hNext->next->next = NULL;
	return pHead;
}
/*16、合并两个排序的链表
题目描述
输入两个单调递增的链表，输出两个链表合成后的链表，当然我们需要合成后的链表满足单调不减规则

*/
ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
{
	//有链表为空
	if (pHead1 == NULL)
		return pHead2;
	if (pHead2 == NULL)
		return pHead1;

	//递归版本 
	if (pHead1->val <= pHead2->val)
	{
		pHead1->next = Merge(pHead1->next, pHead2);
		return pHead1;
	}
	else
	{
		pHead2->next = Merge(pHead1, pHead2->next);
		return pHead2;
	}


	//非递归版本
	//构造新链表的头结点和‘游标’ 比较两个链表中的数据 依次插入新的链表中
	ListNode* mergeHead = NULL;
	ListNode* current = NULL;
	while (pHead1 != NULL && pHead2 != NULL)
	{
		if (pHead1->val <= pHead2->val)
		{
			if (mergeHead == NULL)
				mergeHead = current = pHead1;
			else
			{
				current->next = pHead1;
				current = current->next;
			}
			pHead1 = pHead1->next;

		}
		else
		{
			if (mergeHead == NULL)
				mergeHead = current = pHead2;
			else
			{
				current->next = pHead2;
				current = current->next;
			}
			pHead2 = pHead2->next;
		}

		//某一链表已全部插入到了新链表中
		if (pHead1 == NULL)
			current->next = pHead2;
		else
			current->next = pHead1;

		return mergeHead;

	}

}
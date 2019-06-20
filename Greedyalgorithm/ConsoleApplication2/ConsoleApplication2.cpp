// ConsoleApplication2.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
	int n;//n堆石子
	cin >> n;
	int k;//最多可以有k组合并 2<=k<=n
	cin >> k;
	int t = 0;
	if((n - k) % (k - 1)!=0)//在使用贪心算法时，用于判定需要补几个零
	{
		t = k - 1 - ((n - k) % (k - 1));
	}
	
	priority_queue< int>maxx;//“每层中间商可挣得的差价最大值”
	priority_queue< int>minn;//“每层中间商可挣得的差价最小值”
	priority_queue< int, vector<int>, less<int> > max;//从大到小的排列
	priority_queue< int, vector<int>, greater<int> > min;//从小到大的排列
	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		max.push(x);//将石堆放入优先队列中，从大到小
		min.push(x);//将石堆放入优先队列中，从小到大
	}
	while (t > 0)
	{
		min.push(0);//补零
		t--;
	}
	while (max.size()>1)//计算每个非叶子结点的结点值
	{
		int sum = 0;
		for (int i = 0; i < 2; i++)
		{
			sum = max.top() + sum;
			max.pop();
		}
		max.push(sum);
		maxx.push(sum);
	}
	int summ=0;
	while (!maxx.empty())//计算最大值
	{
		summ = summ + maxx.top();
		maxx.pop();
	}
	while (min.size() > 1)
	{
		int sum = 0;
		
		for (int i = 0; i < k; i++)
		{
			
			sum = min.top() + sum;
			min.pop();
			if (min.empty()) break;
		} 
		min.push(sum);
		minn.push(sum);
	}
	int sums = 0;
	while (!minn.empty())//计算最小值
	{
		sums = sums + minn.top();
		minn.pop();
	}
	cout << summ<<" ";
	cout << sums;
	return 0;
}
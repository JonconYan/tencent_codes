#include <iostream>
#include<string>
using namespace std;
bool is_cycle(string s)
{
	bool flag = 0;
	int i = 0;
	for (; i < s.size(); i++)
	{
		if (s[i] == '[')
		{
			flag = 1;
			break;
		}
	}
	return flag;
}
int getinside_size(string s, int& index)
{
	int left = 0;
	int right = 0;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == '[')
			left = i;
		else if (s[i] == ']')
		{
			right = i;
			break;
		}
	}
	index = left;
	return right - left + 1;
}
string each(string s)
{
	int i = 1;//跳过【 开始计算解压多少次
	int num = 0;
	for (; i < 4; i++)
	{
		if (s[i] == '|')
			break;
		num = num * 10 + s[i] - '0';
	}
	int size = s.size() - i - 2;//可能存在问题
	string tem = s.substr(i + 1, size);
	string result = tem;
	for (int i = 0; i < num - 1; i++)
	{
		result += tem;
	}
	return result;
}
int main() {
	string s;
	cin >> s;
	while (is_cycle(s))
	{
		int index = 0;
		int size = getinside_size(s, index);//得到最内层的初始位置和大小
		string tmp = s.substr(index, size);//得到需要展开的第一个序列
		string result = each(tmp);//将此序列展开
		//更新s
		if (!index)
			s = result + s.substr(index + size);
		else
			s = s.substr(0, index) + result + s.substr(index + size);
	}
	cout << s;
	system("pause");
}
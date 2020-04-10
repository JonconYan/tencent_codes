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
	int i = 1;//������ ��ʼ�����ѹ���ٴ�
	int num = 0;
	for (; i < 4; i++)
	{
		if (s[i] == '|')
			break;
		num = num * 10 + s[i] - '0';
	}
	int size = s.size() - i - 2;//���ܴ�������
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
		int size = getinside_size(s, index);//�õ����ڲ�ĳ�ʼλ�úʹ�С
		string tmp = s.substr(index, size);//�õ���Ҫչ���ĵ�һ������
		string result = each(tmp);//��������չ��
		//����s
		if (!index)
			s = result + s.substr(index + size);
		else
			s = s.substr(0, index) + result + s.substr(index + size);
	}
	cout << s;
	system("pause");
}
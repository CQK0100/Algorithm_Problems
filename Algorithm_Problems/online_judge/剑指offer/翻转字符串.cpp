/*
 1.��ת����˳��
 ����һ��Ӣ�ľ��ӣ���ת�����е��ʵ�˳�򣬵������ڵ��ַ���˳�򲻱䡣
 ��һ����ת�ַ����������ַ����ڶ����ٷ�תÿ�������е�˳��
*/
#include<string>
#include<iostream>

using namespace std;

void Reverse(string& str) {
	// std::reverse(str.begin(),str.end());
	if (str.empty() || str.size() == 1)
		return;
	int start = 0, last = str.size() - 1;
	while (start < last) {
		std::swap(str[start], str[last]);
		++start;
		--last;
	}
}

string ReverseSentence(string str) {
	if (str.empty() || str.size() == 1)
		return std::move(str);
	std::reverse(str.begin(), str.end());
	auto start = str.begin(), last = str.end();
	auto internal_end = start;
	while (start != last && internal_end != last) {
		if (*start == ' ') {
			++start; ++internal_end;
		}
		else if (*internal_end == ' ' || internal_end == last) {
			std::reverse(start, (internal_end - 1));
			start = internal_end;
		}
		else
			++internal_end;
	}
	return std::move(str);
}

/*
 2.����ת�ַ���
 ���ַ���ǰ�����ɸ��ַ�ת�Ƶ��ַ�����β����
 ��"abcdefg"��2������������"cdefgab".
 ͨ��ǰ������������ǰ��ַ������2���֣�ab��cdefg���ֱ�ת�õ�bagfedc
 �ٰѷ�ת����ַ����ٴη�ת�������͵õ���"cdefgab"
*/
string LeftRotateString(string str, int n) {
	if (str.size() <= 1 || n <= 0 || n >= str.size())
		return std::move(str);
	auto start = str.begin(), last = str.end();
	auto mid = start + n;
	std::reverse(start, mid);
	std::reverse(mid, last);
	std::reverse(start, last);
	return std::move(str);
}


int main() {
	string s = "I am a student";
	cout << ReverseSentence(s) << endl;
	cout << LeftRotateString("abcdefg", 2) << endl;
	return 0;
}
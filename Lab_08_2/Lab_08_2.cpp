#include <iostream>
#include <string>

using namespace std;

size_t MinLength(const string s)
{
	int k = 0;
	size_t len = 0,
		min = 0;
	size_t start = 0,
		finish;
	while ((start = s.find_first_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ", start)) != -1)
	{
		finish = s.find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ", start + 1);
		if (finish == -1)
			finish = s.length();
		len = finish - start;
		if (k == 0)
			min = len;
		k++;
		if (len < min)
			min = len;
		start = finish + 1;
	}
	return min;
}
int main()
{
	string str;

	cout << "Enter string:" << endl;
	getline(cin, str);

	cout << "Length of min groups of words: " << MinLength(str) << endl;

	system("pause");
	return 0;
}
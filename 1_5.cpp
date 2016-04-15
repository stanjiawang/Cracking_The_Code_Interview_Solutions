/* Write a method to replace all spaces in a string with ‘%20’. */

#include <iostream>
#include <string>

using namespace std;

void replace(char * str)
{
	int len = strlen(str);
	int count = 0;
	for(int i = 0; i < len; i++)
	{
		if(' ' == str[i])
			count++;
	}

	int newLen = len + count * 2;	// new string length
	str[newLen] = '\0';	// set the last character of the new str;
	newLen--;
	for(int j = len -1; j >= 0; j--)
	{
		if(' ' == str[j])
		{
			str[newLen] = '0';
			str[newLen - 1] = '2';
			str[newLen - 2] = '%';
			newLen -= 2;
		}
		else
			str[newLen] = str[j];
			newLen--;
	}
}

int main()
{
	char str[50] = "I'am Stan Wang.";
	cout << str << endl;

	replace(str);

	cout << str << endl;

//	system("pause");
	return 0;
}
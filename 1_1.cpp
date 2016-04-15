/* Implement an algorithm to determine if a string has all unique characters. What if you can not use additional data structures? */

#include <iostream>
#include <string>

using namespace std;

bool isUnique(string str)
{
	bool arr[256];	//There are 2^8 characters in ASCII table
	memset(arr, 0, sizeof(arr));
	int len = str.length();

	for(int i = 0; i < len; i++)
	{
		int index = (int) str[i];	//transfer the char to int
		if(!arr[index])
		{
			arr[index] = true;	//if this is the first time the character appears, set it to true
		}
		else
			return false;
	}
	return true;
}

int main()
{
	string str1 = "abcdefghijklmn";
	string str2 = "abcdefghijklmm";

	cout << "str1 has all unique characters is " << isUnique(str1) << endl;
	cout << "str2 has all unique characters is " << isUnique(str2) << endl;

//	system("pause");
	return 0;
}
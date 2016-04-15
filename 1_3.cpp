/*Design an algorithm and write code to remove the duplicate characters in a string without using any additional buffer. NOTE: One or two additional variables are fine. An extra copy of the array is not.

FOLLOW UP

Write the test cases for this method. */

#include <iostream>
#include <string>

using namespace std;

void removeDuplicate(string &str)
{
	int len = str.length();
	int p = 0;
	for(int i = 0; i < len; i++)
	{
		if(str[i] != '\0')	// skip if the character was set to '\0'
		{
			str[p] = str[i];	// the new string is p
			p++;
			for(int j = i + 1; j < len; j++)
			{
				if(str[i] == str[j])
					str[j] = '\0';
			}
		}
	}
	str = str.substr(0, p);
}

int main()
{
	string str = "abbcccddddeeeeefg";
	cout << str << endl;

	removeDuplicate(str);
	cout << str << endl;

	system("pause");

	return 0;
}
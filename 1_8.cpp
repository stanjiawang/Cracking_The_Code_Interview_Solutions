/* Assume you have a method isSubstring which checks if one word is a substring of another. Given two strings, s1 and s2
write code to check if s2 is a rotation of s1 using only one call to isSubstring ( i.e., “waterbottle” is a rotation of “erbottlewat”). */

#include <iostream>
#include <string>

using namespace std;

bool isRotation(string str1, string str2)
{
	string str3 = str1 + str1;
	if(str3.find(str2) != string::npos)
		return true;
	else
		return false;
}

int main()
{
	string str1 = "abcdefghijklmn";
	string str2 = "efghijklmnabcd";

	bool result = isRotation(str1, str1);

	cout << "String 1 " << str1 << " is rotation of String 2 " << str2 << " is " << result << endl;

	system("pause");
	return 0;
}
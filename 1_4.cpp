/* Write a method to decide if two strings are anagrams or not. */

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool isAnagrams1(string str1, string str2)
{
	if(str1.length() != str2.length() || str1 == "" || str2 == "")
		return false;

	sort(&str1[0], (&str1[0] + str1.length()));
	sort(&str2[0], (&str2[0] + str2.length()));
	if(str1 == str2)
		return true;
	else
		return false;
}

bool isAnagrams2(string str1, string str2)
{
	if(str1.length() != str2.length() || str1 == "" || str2 == "")
		return false;

	int arr[256];	// There 2^8 characters in ASCII table
	memset(arr, 0, sizeof(arr));
	int len = str1.length();
	for(int i = 0; i < len; i++)
	{
		arr[(int) str1[i]]++;
		arr[(int) str2[i]]--;
	}
	for(int j = 0; j < len; j++)
	{
		if(0 != arr[j])
			return false;
	}
	return true;
}

int main()
{
	string str1 = "abcdefg";
	string str2 = "edcbafg";

	bool result1 = isAnagrams1(str1, str2);
	bool result2 = isAnagrams2(str1, str2);

	cout << "String 1: " << str1 << " and String 2: " << str2 << " is anagrams is " << result1 << endl;
	cout << "String 1: " << str1 << " and String 2: " << str2 << " is anagrams is " << result2 << endl;

//	system("pause");
	return 0;
}
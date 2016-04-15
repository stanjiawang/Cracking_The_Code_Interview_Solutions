/* Write code to reverse a C-Style String. (C-String means that “abcd” is represented as five characters, including the null character.) */

#include <iostream>

using namespace std;

void swap(char &a, char &b) // do not use this function when a is the same as b
{
	a = a^b;
	b = a^b;
	a = a^b;
}

void reverse(char * str)
{
	char * p = str;	// set point p and q point to the head of the string
	char * q = str;
	while(*q)	// detect the length of the string
	{
		q++;
	}
	q--;	// back one bit since we have a \n at the end of the string
	while(p < q)
	{
		swap(*p, *q);
		p++;
		q--;
	}
}

int main()
{
	char str[] = "abcdefg";
	cout << str << endl;

	reverse(str);
	cout << str << endl;

//	system("pause");

	return 0;
}

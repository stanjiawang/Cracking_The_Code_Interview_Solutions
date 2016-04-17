/* Implement an algorithm to find the nth to last element of a singly linked list. */

#include <iostream>

using namespace std;

typedef struct node
{
	int data;
	node * next;
}node;

node * init(int arr[], int n)
{
	node * head, *p;
	for(int i = 0; i < n; i++)
	{
		node * newNode = new node();
		newNode -> data = arr[i];
		if(0 == i)
		{
			head = p = newNode;
			continue;
		}
		p -> next = newNode;
		p = newNode;
	}
	p -> next = NULL;
	return head;
}

node * findNthToTheLast(node * head, int n)
{
	if(NULL == head || 1 > n)
		return NULL;
	node * p = head;
	node * q = head;
	while(0 < n && q)
	{
		q = q -> next;
		n--;
	}
	if(0 < n)
		return NULL;
	while(q)
	{
		p = p -> next;
		q = q -> next;
	}
	return p;
}

void print(node * head)
{
	while(head)
	{
		cout << head -> data << "->" ;
		head = head -> next;
	}
	cout << "NULL" << endl;
}

int main()
{
	int len = 10;
	int arr[] = {9, 2, 1, 3, 5, 6, 2, 6, 3, 1};
	node * head = init(arr, len);
	print(head);
	int nth = 6;
	node * p = findNthToTheLast(head, nth);
	if(p)
		cout << endl << "The " << nth << "th to the last element is "<< p -> data << endl;
	else
		cout << "The length of the linked list is not long enough." << endl;

	system("pause");
	return 0;
}

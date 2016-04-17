/*
You have two numbers represented by a linked list, where each node contains a single digit. The digits are stored in reverse order, such that the 1’s digit is at the head of the list. Write a function that adds the two numbers and returns the sum as a linked list.

EXAMPLE

Input: (3 -> 1 -> 5), (5 -> 9 -> 2)

Output: 8 -> 0 -> 8
*/

#include <iostream>

using namespace std;

typedef struct node
{
	int data;
	node * next;
}node;

node * init(int arr[], int n)
{
	node *head = NULL;
	node *p = NULL;

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

void print(node *head)
{
	node *p = head;
	while(p)
	{
		cout << p -> data << " -> ";
		p = p -> next;
	}
	cout << "NULL" << endl;
}

node * addLink(node * p, node * q)
{
	if(NULL == p)
		return q;
	if(NULL == q)
		return p;

	node * result = NULL;
	node * pre = NULL;
	int carrier = 0;
	while(p && q)
	{
		int temp = p->data + q->data + carrier;
		node *newNode = new node();
		newNode->data = temp % 10;
		if(NULL == pre)
		{
			pre = result = newNode;
		}
		else
		{
			pre -> next = newNode;
			pre = newNode;
		}
		carrier = temp / 10;
		p = p->next;
		q = q->next;
	}

	while(p)
	{
		int temp = p->data + carrier;
		node *newNode = new node();
		newNode->data = temp % 10;
		pre -> next = newNode;
		pre = newNode;
		carrier = temp / 10;
		p = p->next;
	}

	while(q)
	{
		int temp = q->data + carrier;
		node *newNode = new node();
		newNode->data = temp % 10;
		pre -> next = newNode;
		pre = newNode;
		carrier = temp / 10;
		q = q->next;
	}

	if(0 < carrier)
	{
		node *newNode = new node();
		newNode->data = carrier;
		pre -> next = newNode;
	}
	
	return result;
}

int main()
{
	int m = 4;
	int a[] = {1, 2, 9 ,3};
	int n = 3;
	int b[] = {9, 9, 2};

	node * p = init(a, m);
	print(p);
	node * q = init(b, n);
	print(q);

	node * r = addLink(p, q);
	if(r)
		print(r);

//	system("pause");
	return 0;
}
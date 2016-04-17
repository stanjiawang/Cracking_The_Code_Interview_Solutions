/* Write code to remove duplicates from an unsorted linked list.

FOLLOW UP

How would you solve this problem if a temporary buffer is not allowed? */

#include <iostream>

using namespace std;

typedef struct Node
{
	int data;
	Node * next;
}node;

bool hashTable[100];

node * init(int arr[], int n)
{
	node *head, *p;
	for(int i = 0; i < n; i++)
	{
		node *newNode = new node();
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

void removeDuplicate(node * head)
{
	if(NULL == head)
		return;
	node * p = head;
	node * q = head -> next;
	hashTable[head -> data] = true;
	while(q)
	{
		if(hashTable[q -> data])
		{
			node * t = q;
			p -> next = q -> next;
			q = p -> next;
			delete t;
		}
		else
		{
			hashTable[q -> data] = true;
			p = q;
			q = q -> next;
		}
	}
}

void print(node * head)
{
	while(head)
	{
		cout << head -> data << "->" ;
		head = head -> next;
	}
}

int main()
{
	int n = 10;
	int arr[] = {3, 2, 1, 3, 5, 6, 2, 6, 3, 1};
	memset(hashTable, false, sizeof(hashTable));
	node * head = init(arr, 10);
	removeDuplicate(head);
	print(head);

	system("pause");
	return 0;
}

/*
/*
Given a circular linked list, implement an algorithm which returns node at the beginning of the loop.

DEFINITION

Circular linked list: A (corrupt) linked list in which a node’s next pointer points to an earlier node, so as to make a loop in the linked list.

EXAMPLE

Input: A -> B -> C -> D -> E -> C [the same C as earlier]

Output: C
*/

#include <iostream>
#include <map>

using namespace std;

typedef struct node
{
	char data;
	node * next;
}node;

node * init(char c[], int n, int m)
{
	node *head = NULL;
	node *p = NULL;
	node *q = NULL;
	for(int i = 0; i < n; i++)
	{
		node * newNode = new node();
		newNode -> data = c[i];
		if(m == i)
			q =newNode;
		if(0 == i)
		{
			head = p = newNode;
			continue;
		}
		p -> next = newNode;
		p = newNode;
	}
	p -> next  = q;
	return head;
}


void print(node * head)
{
	node * p = head;
	while(p)
	{
		cout << p -> data << " -> ";
		p = p -> next;
	}
	cout << "NULL" << endl;
}

map<node*, bool> hashTable;

node * loopStart(node * head)
{
	while(head)
	{
		if(hashTable[head])
		{
			return head;
		}
		else
		{
			hashTable[head] = true;
			head = head -> next;
		}
	}
	return head;
}


int main()
{
	int n = 11, m = 3;
	char a[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K'};

	node * head = init(a, n, m);
//	print(head);	// will enter a endless loop

	node *p = loopStart(head);
	if(p)
		cout << p -> data  << endl;	//loop will start at 'D' since m = 3

	system("pause");
	return 0;

}

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
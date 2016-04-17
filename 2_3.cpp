/* Implement an algorithm to delete a node in the middle of a single linked list, given only access to that node. */

#include <iostream>

using namespace std;

typedef struct node
{
	int data;
	node * next;
}node;

node * init(int arr[], int n)
{
	node *head, *p;
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

bool removeNode(node * nodeRemoved)
{
	if(NULL == nodeRemoved || NULL == nodeRemoved -> next)
		return false;
	node *q = nodeRemoved -> next;
	nodeRemoved -> data = q -> data;
	nodeRemoved -> next = q -> next;
	delete q;
	return true;
}

void print(node *head)
{
	node * p = head;
	while(p)
	{
		cout << p -> data << "->";
		p = p -> next;
	}
	cout << "NULL" << endl;
}

int main()
{
	int len = 10;
	int arr[] = {9, 2, 1, 3, 5, 6, 2, 6, 3, 1};
	node *head = init(arr, len);
	print(head);
	node * nodeRemoved = head;
	int nodeIndex = 3;
	for(int i = 0; i < nodeIndex; i++)
		nodeRemoved = nodeRemoved -> next;
	if(removeNode(nodeRemoved))
		print(head);
	else
		cout << "Failed!" << endl;

	system("pause");
	return 0;
}
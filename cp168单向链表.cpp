//168单向链表
/*
1 2 3 4 5 6 7 8 9 10
1 2 3 4 12 5 6 7 8 9 10
1 2 3 12 5 6 7 8 9 10
10
*/
#include <iostream>
using namespace std;

struct Node {
	int data;
	Node *next;
};

void createNode(Node *r, int n) {
	Node *p;
	for (int i = 1; i <= n; i++) {
		p = new Node();
		p->data = i;
		p->next = NULL;
		r->next = p;
		r = p;
	}
}

void printNode(Node *head) {
	Node *p;
	p = head->next;
	while ((p != NULL)) {
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;
}

void insert(Node *head, int i, int x) { //i数据节点之后 插入新节点
	Node *p, *s;
	int j;
	p = head->next;
	j = 1;
	while ((p != NULL) && (j < i)) {
		p = p->next;
		j++;
	}
	if (p == NULL)
		cout << "no this position";
	else {
		s = new Node;
		s->data = x;
		s->next = p->next;
		p->next = s;
	}
}

void deleteNode(Node *head, int i) { //删除i数据
	Node *p, *s;
	int j;
	s = head;
	p = s->next;
	j = 1;
	while ((p != NULL) && (j < i)) {
		s = p;
		p = p->next;
		j++;
	}
	if (p == NULL)
		cout << "no this position";
	else {
		s->next = p->next;
		free(p);
	}
}

int len(Node *head) {
	Node *p;
	int count = 0;
	p = head->next;
	while (p != NULL) {
		count++;
		p = p->next;
	}
	return count;
}
int main(int argc, char **argv) {
	Node *head, *r;
	head = new Node;
	r = head;

	createNode(r, 10);
	printNode(head);
	insert(head, 4, 12);
	printNode(head);
	deleteNode(head, 4);
	printNode(head);
	cout << len(head);
	return 0;
}
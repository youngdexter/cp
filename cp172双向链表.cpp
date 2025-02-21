//cp172双向链表
/*
0 1 2 3 4 5
0 1 2 3 4
0 1 2 4
0 1 2 4 9
0 1 2 4 8 9
9 8 4 2 1 0
*/
#include <iostream>
using namespace std;

struct Node {
	int data;
	Node *pre, *next;
};

Node *create(Node *r, int n) {
	Node *p;
	int i;
	for (i = 1; i <= n; i++) {
		p = new Node;
		p->data = i;
		r->next = p;
		p->next = NULL;
		p->pre = r;
		r = p;
	}

	return r;
}

void printnext(Node *head) {
	Node *p;
	p = head;
	while (p != NULL) {
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;
}

void printpre(Node *r) {
	Node *p;
	p = r;
	while (p != NULL) {
		cout << p->data << " ";
		p = p->pre;
	}
	cout << endl;
}

Node *insertNext(Node *head, Node *r, int i, int x) { //在i之后插入，考虑i是不是最后一个结点
	Node *p, *s;
	p = head;

	int j = 0;
	while ((p != NULL) && (j < i)) {
		j++;
		p = p->next;
	}
	if (p == NULL) {
		cout << "no this position!";
	} else {
		if (p != r) {
			s = new Node;
			s->data = x;
			s->next = p->next;
			p->next = s;
			s->next->pre = s;
			s->pre = p;

		} else {
			s = new Node;
			s->data = x;
			s->next = NULL;
			p->next = s;
			s->pre = p;
			r = s;
		}

	}
	return r;

}

Node *deleteNode(Node *head, Node *r, int i) { //删除i位置的结点
	Node *p;
	int j;
	p = head;
	j = 0;
	while ((p != NULL) && (j < i)) {
		j++;
		p = p->next;
	}

	if (p == NULL) {
		cout << "no this position!";
	} else {
		if (p != r) {
			p->pre->next = p->next;
			p->next->pre = p->pre;

		} else {
			r = r->pre;
			r->next = NULL;
		}
		free(p);
		return r;
	}
}
int main(int argc, char **argv) {
	Node *head, *r;
	head = new Node;
	r = head;
	head->data = 0;
	head->pre = NULL;
	r->next = NULL;
	r = create(r, 5);
	printnext(head);

	r = deleteNode(head, r, 5);
	printnext(head);
	deleteNode(head, r, 3);//r没动
	printnext(head);

	r = insertNext(head, r, 3, 9);
	printnext(head);
	insertNext(head, r, 3, 8);//r没动
	printnext(head);

	printpre(r);
	return 0;
}
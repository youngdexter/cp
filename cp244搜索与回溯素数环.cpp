//cp244�������������������4����Ϊ����
/*
��const int n = 4��
<1>1 2 3 4
<2>1 4 3 2
<3>2 1 4 3
<4>2 3 4 1
<5>3 2 1 4
<6>3 4 1 2

<1> <4> <6> һ��  1 2 3 4
<2> <3> <5> һ��  4 3 2 1
1234 4321 ������Ҳһ��
��const int n = 20��
���̫��
*/
#include <iostream>
using namespace std;
#include <cmath>
const int n = 4;

int a[n + 1] = {0};  //a[i] ��i��ѡ��������
bool b[n + 1] = {0}; //b[i] ����i�Ƿ�ѡ����0 û��ѡ����1 ��ѡ��
int total = 0;  //�ܷ�����
void search(int t);
void print();
bool pd(int, int);

int main(int argc, char **argv) {
	search(1);

	return 0;
}

void search(int t) {
	int i;
	for (i = 1; i <= n; i++) {
		if ((!b[i]) && pd(a[t - 1], i)) {
			a[t] = i;
			b[i] = 1;
			if (t == n) {
				if (pd(a[n], a[1])) {
					print();
					//break;
				}
			} else
				search(t + 1);
			b[i] = 0;
		}
	}
}

void print() {
	int j;
	total++;
	cout << "<" << total << ">";

	for (j = 1; j <= n; j++) {
		cout << a[j] << " ";
	}
	cout << endl;
}

bool pd(int x, int y) {
	int k = 2, i = x + y;
	while (k <= sqrt(i) && i % k != 0) {
		k++;
	}
	if (k > sqrt(i))
		return 1;
	else
		return 0;
}
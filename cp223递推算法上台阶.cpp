//cp223�����㷨��̨��
/*
n:4
7
*/
#include <iostream>
using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
long long d[110] = {0};
int n;
int main(int argc, char **argv) {
	d[1] = 1;	//1��̨�� 1���߷�
	d[2] = 2;	//2��̨�� 2���߷�
	d[3] = 4;	//3��̨�� 4���߷�
	for (int i = 4; i <= 100; i++) {
		d[i] = d[i - 1] + d[i - 2] + d[i - 3];
	}

	cout << "n:";
	cin >> n;
	cout << d[n];
	return 0;
}
#include<stdio.h>
#include<malloc.h>
#include<fstream>
#include<cstring>
#include<set>
#include<ctype.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>
using namespace std;

char ch[10];
char Des[50][3];
int flag, m;
int count = 0;
char s[50], n = '1';

void A();
void B();
void C();
void T();
void E();
void F();
void G();
int Count(int x, int y);
int Set(int x, int y);

int main() {
	flag = 0;
	m = 0;
	int i;
	int j;
	j = Count(i, 10);
	int k = Set(i, 1000);
	scanf("%s", s);
	if (s[0] == '\0')
		return 0;
	A();
	return 0;
}


int letter(char a) {
	if (a >= 'a' && a <= 'z')
		return 1;
	return 0;
}
void A() {
	G();
	if (s[m] == ':' && s[m + 1] == '=') {
		m += 2;
		B();
		printf("%s:=%s", Des[count - 2], Des[count - 1]);
		printf("     (:=,%s,-,%s)\n", Des[count - 1], Des[count - 2]);
	}
	else {
		printf("error!\n");
		exit(0);
	}
}

void B() {
	T();
	C();
}
void C() {
	int c;
	if (s[m] == '+' || s[m] == '-') {
		c = m;
		m++;
		T();
		ch[0] = 'T';
		ch[1] = n;
		ch[2] = '\0';
		if (s[c] == '+') {
			printf("%s:=%s+%s", ch, Des[count - 2], Des[count - 1]);
			printf("     (+,%s,%s,%s)\n", Des[count - 2], Des[count - 1], ch);
		}
		else {
			printf("%s:=%s-%s", ch, Des[count - 2], Des[count - 1]);
			printf("     (-,%s,%s,%s)\n", Des[count - 2], Des[count - 1], ch);
		}
		strcpy(Des[count - 2], ch);
		count--;
		n++;
		C();
	}
}
void T() {
	F();
	E();
}

void E() {
	if (s[m] == '*' || s[m] == '/') {
		int c;
		c = m;
		m++;
		F();
		char ch[3];
		ch[0] = 'T';
		ch[1] = n;
		ch[2] = '\0';
		if (s[c] == '*') {
			printf("%s:=%s*%s", ch, Des[count - 2], Des[count - 1]);
			printf("     (*,%s,%s,%s)\n", Des[count - 2], Des[count - 1], ch);
		}
		else {
			printf("%s:=%s/%s", ch, Des[count - 2], Des[count - 1]);
			printf("     (/,%s,%s,%s)\n", Des[count - 2], Des[count - 1], ch);
		}
		strcpy(Des[count - 2], ch);
		count--;
		n++;
		E();
	}

}
void G() {
	if (letter(s[m])) {
		Des[count][0] = s[m];
		Des[count][1] = '\0';
		count++;
		m++;
	}
	else {
		printf("error\n");
		exit(0);
	}
}
void F() {
	if (s[m] == '(') {
		m++;
		B();
		if (s[m] == ')')
			m++;
		else {
			printf("ERROR!\n");
			exit(0);
		}
	}
	else if (letter(s[m]))
		G();
	else {
		printf("ERROR!\n");
		exit(0);
	}

}

int Count(int a, int b) {
	int c = a << b;
	return c;
}

int Set(int a, int b) {
	return a << b;
}


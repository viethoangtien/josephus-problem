#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct _Node {
	int data;
	struct _Node *next;
};

typedef struct _Node Node;

Node *NewNode(int data) {
	Node *TempNode;
	TempNode = (Node *)malloc(sizeof(Node));
	TempNode->next = TempNode;
	TempNode->data = data;
}

void Josephus(int m, int n) {
	int i;
	Node *head;
	Node *prev;
	head = NewNode(1);
	prev = head;
	for (i = 2; i <= n; i++) {
		prev->next = NewNode(i);
		prev = prev->next;//at n is prev=head->prev if circle
	}
	prev->next = head;//Circle
	Node *ptr1=head;
	Node *ptr2=head;
	while (ptr1->next != ptr1) {
		int count = 1;
		while (count != m) {
			ptr2 = ptr1;
			ptr1 = ptr1->next;
			count++;
		}
		//Delete player at ptr1->data;
		ptr2->next = ptr1->next;
		ptr1 = ptr2->next;
	}
	printf("\nWinner Player is: %d !", ptr1->data);
}
void main() {
	int n;//Number Player
	int m;//Ramdom
	printf("Enter the number of the player: ");
	scanf_s("%d", &n);
	printf("\nEnter Ramdom number: ");
	scanf_s("%d", &m);
	Josephus(m, n);//Function Josephus
	_getch();
}
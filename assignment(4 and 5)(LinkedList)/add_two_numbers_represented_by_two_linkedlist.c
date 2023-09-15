/*Author : Raj Roy*/

#include<stdio.h>
#include<stdlib.h>

struct Node{
	int data;
	struct Node* next;
};

void InsertAtLast(struct Node** head,int data){
	struct Node* current = (struct Node*)malloc(sizeof(struct Node));
	current->data = data;
	struct Node* temp = *head;
	if(*head == NULL){
		*head = current;
		current->next = NULL;
		return;
	}
	while(temp->next != NULL){
		temp = temp->next;
	}
	
	temp->next = current;
	current->next = NULL;
}
void PrintLinkedList(struct Node* head){
	printf("Head-->");
	while(head != NULL){
		printf("%d-->" ,head->data );
		head = head->next;
	}
	printf("NULL\n");

}

Node* add(struct Node** head1,struct Node** head2){
	struct Node* current1 = *head1;
	struct Node* current2 = *head2;
	
	long long int first = 0;
	long long int second = 0;
	
	while(current1 != NULL){
		int x = current1->data;
		first = first * 10 + x;
		current1 = current1->next;
	}
	while(current2 != NULL){
		int x = current2->data;
		second = second * 10 + x;
		current2 = current2->next;
	}
	
	long long int res = first + second;
	//count last zeroes;
	int count = 0;
	long long int temp = res;
	while(temp % 10 == 0){
		count++;
		temp = temp / 10;
	}
	//reverse the digit;
	long long int ans = 0;
	
	while(res != 0){
		int digit = res % 10;
		ans = ans * 10 + digit;
		res = res / 10;
	}
	
	//construct linked list by this number;
	struct Node* req = NULL;
	while(ans != 0){
		int digit = ans % 10;
		InsertAtLast(&req,digit);
		ans = ans / 10;
	}
	for(int i = 0; i < count; i++){
		InsertAtLast(&req,0);
	}
	return req;
	
}
int main(){
	struct Node* head1 = NULL;
	struct Node* head2 = NULL;
	struct Node* ans = NULL;
	int n;
	scanf("%d",&n);
	for(int i = 0; i < n; i++){
		int x;
		scanf("%d",&x);
		InsertAtLast(&head1,x);
	}
	
	int m;
	scanf("%d",&m);
	for(int i = 0; i < m; i++){
		int x;
		scanf("%d",&x);
		InsertAtLast(&head2,x);
	}
	
	printf("First linkedlist:\n");
	PrintLinkedList(head1);
	
	printf("second linkedlist:\n");
	PrintLinkedList(head2);	
	
	printf("Resultant linkedlist:\n");
	ans = add(&head1,&head2);
	PrintLinkedList(ans);
	return 0;
}

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

Node* multiply(struct Node** head1,struct Node** head2){
	struct Node* current1 = *head1;
	struct Node* current2 = *head2;
	struct Node* ans = NULL;
	
	long long int res = 0;
	long long int res1 = 0;
	
	while(current1 != NULL){
		int x = current1->data;
		res = res * 10 + x;
		current1 = current1->next;
	}
	while(current2 != NULL){
		int x = current2->data;
		res1 = res1 * 10 + x;
		current2 = current2->next;
	}
	
	long long int mul = res * res1;
	long long int temp = mul;
	int count = 0;
	while(temp % 10 == 0){
		count++;
		temp = temp / 10;
	}
	
	//reverse mul;
	long long int rev = 0;
	while(mul != 0){
		int digit = mul % 10;
		rev = rev * 10 + digit;
		mul = mul / 10;
	}
	
	while(rev != 0){
		int x = rev % 10;
		InsertAtLast(&ans,x);
		rev = rev / 10;
	}
	for(int i = 0; i < count; i++){
		InsertAtLast(&ans,0);
	}
	return ans;
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
	ans = multiply(&head1,&head2);
	PrintLinkedList(ans);
	return 0;
}

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

void MiddleOfLinkedList(struct Node** head){
	struct Node* current = *head;
	if(*head == NULL){
		printf("NOT POSSIBLE\n");
		return;
	}
	int count = 0;
	while(current != NULL){
		count++;
		current = current->next;
	}
	int temp = count;
	
	if(count % 2 == 0){
		count = count / 2;
	}
	else{
		count = (count / 2)  + 1;
	}
	
	current = *head;
	while(count != 1){
		count--;
		current = current->next;
	}
	if(temp % 2 == 0){
		printf("%d %d ", current->data,(current->next)->data);
	}
	else{
		printf("%d ",current->data);
	}
}


int main(){
	struct Node* head = NULL;
	
	int n;
	scanf("%d",&n);
	for(int i = 0; i < n; i++){
		int x;
		scanf("%d",&x);
		InsertAtLast(&head,x);
	}
	
	 PrintLinkedList(head);
	 //depending upon the even length case you can change the code
	 // above ,i have just printed both of the middle value in the even case;
	MiddleOfLinkedList(&head);
	return 0;
}

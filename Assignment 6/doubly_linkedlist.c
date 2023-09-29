/*Author : RAJ ROY*/


#include<stdio.h>
#include<stdlib.h>

struct Node{
	struct Node* prev;
	int data;
	struct Node* next;
};



/************************Insertion in doubly linked list**********************/
void Push_At_Front(struct Node** head,int data){
	struct Node* current = (struct Node*)malloc(sizeof(struct Node));
	current->data = data;
	current->next = *head;
	current->prev = NULL;
	
	if(*head != NULL){
		(*head)->prev = current;
	}
	*head = current;	
}

void Insert_At_Last(struct Node** head,int data){
	struct Node* current = (struct Node*)malloc(sizeof(struct Node));
	current->data = data;
	struct Node* temp = *head;
	if(*head == NULL){
		*head = current;
		current->next = NULL;
		current->prev = NULL;
		return;
	}
	while(temp->next != NULL){
		temp = temp->next;
	}
	
	temp->next = current;
	current->next = NULL;
	current->prev = temp;
	
}

void PrintLinkedList(struct Node* head){
	struct Node* temp =  head;
	printf("Head--> ");
	while(head != NULL){
		printf("%d--> ",head->data);
		head = head->next;
	}
	printf("NULL\n");
	
}

void Insert_After_Given_Number(struct Node** head, int data,int num){
	struct Node* current = (struct Node*)malloc(sizeof(struct Node));
	current->data = data;
	if(*head == NULL){
		return;
	}
	
	//assuming the given num is always present in the linked list;
	struct Node* temp = *head;
	while(temp->data != num){
		temp = temp->next;
	}
	
	if(temp->next == NULL){
		current->next = NULL;
		current->prev = temp;
		temp->next = current;
		return;
	}
	current->next = temp->next;
	temp->next->prev = current;
	current->prev = temp;
	temp->next = current;
	
}


void Insert_Before_A_Given_Number(struct Node** head,int data,int num){
	struct Node* current = (struct Node*)malloc(sizeof(struct Node));
	current->data = data;
	if(*head == NULL){
		return;
	}
	
	
	struct Node* temp = *head;
	
	while(temp->data != num){
		temp = temp->next;
	}
	if(temp == *head){
		temp->prev = current;
		current->next = temp;
		current->prev = NULL;
		*head = current;
		return;
	}
	current->next = temp;
	temp->prev->next = current;
	current->prev = temp->prev;
	temp->prev = current;
}




/**********************deletion of doubly linked list**************************/

void Delete_From_Front(struct Node** head){
	if(*head == NULL){
		return;
	}
	struct Node* temp = *head;
	if(temp->next == NULL){
		*head = NULL;
		free(temp);
		return;
	}
	*head = temp->next;
	(*head)->prev = NULL;
	free(temp);
	return;
}

void Delete_Last_Node(struct Node** head){
	if(*head == NULL){
		return;
	}
	struct Node* temp = *head;
	if(temp->next == NULL){
		temp->next = NULL;
		temp->prev = NULL;
		*head = NULL;
		free(temp);
		return;
	}
	temp = *head;
	struct Node* prev = temp;
	while(temp->next != NULL){
		prev = temp;
		temp = temp->next;
	}	
	prev->next = NULL;
	free(temp);
	return;
}


void Delete_any_given_Number(struct Node** head,int num){
	if(*head == NULL){
		return;
	}
	
	struct Node* prev = NULL;
	struct Node* temp = *head;
	while(temp->data != num){
		prev = temp;
		temp = temp->next;
	}
	
	if(temp == *head){
		temp->next->prev = NULL;
		*head = temp->next;
		free(temp);
		return;
	}
	if(temp->next == NULL){
		prev->next = NULL;
		free(temp);
		return;
	}
	prev->next = temp->next;
	temp->next->prev = prev;
}



void Print_The_Middle_Of_The_Linked_List(struct Node** head){
	struct Node* temp = *head;
	int count = 0;
	if(*head == NULL){
		return;
	}
	if(temp->next == NULL){
		printf("%d ",temp->data);
		return;
	}
	while(temp != NULL){
		temp = temp->next;
		count++;
	}
	
	temp = *head;
	if(count % 2 == 1){
		count = count / 2;
		while(count != 0){
			temp = temp->next;
			count--;	
		}
		printf("%d\n ",temp->data);
		return;
	}
	else{
		count = count / 2;
		temp = *head;
		while(count != 1){
			temp = temp->next;
			count--;
		}
		printf("%d ",temp->data);
		printf("%d ",temp->next->data);
		return;
	}	
}

void reverse(Node** head){
    Node* temp = NULL;
    Node* current = *head;
    while (current != NULL) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }
    if (temp != NULL){
    	*head = temp->prev;
    }
        
}

/************implementation of polynomial expression using singly linked list*************/

struct Node {
    int coeff;
    int pow;
    struct Node* next;
};

void create(int x, int y, struct Node** temp){
    struct Node *first, *second;
    second = *temp;
    if (second == NULL) {
        first = (struct Node*)malloc(sizeof(struct Node));
        first->coeff = x;
        first->pow = y;
        *temp = first;
        first->next = (struct Node*)malloc(sizeof(struct Node));
        first = first->next;
        first->next = NULL;
    }
    else {
        first->coeff = x;
        first->pow = y;
        first->next = (struct Node*)malloc(sizeof(struct Node));
        first = first->next;
        first->next = NULL;
    }
}



/********************************************************************************************/
/***program to add two polynomial expression that are represented using singly linked list****/



/****************************************************************************************/








int main(){
	struct Node* head = NULL;
	int n;
	scanf("%d",&n);
	for(int i = 0; i < n; i++){
		int x;
		scanf("%d",&x);
		Insert_At_Last(&head,x);
	}
	
	//Insert_Before_A_Given_Number(&head,3,1);
	reverse(&head);
	Delete_any_given_Number(&head, 2);
	PrintLinkedList(head);
	//Print_The_Middle_Of_The_Linked_List(&head);
	return 0;
}
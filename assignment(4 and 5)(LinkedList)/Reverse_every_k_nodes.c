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

struct Node* reverseAlternateKNodes(struct Node *node, int k, bool b);
struct Node* reverseAlternateKNodes(struct Node *head, int k){
  return reverseAlternateKNodes(head, k, true);
}
  

struct Node* reverseAlternateKNodes(struct Node *node, int k, bool b){
   if(node == NULL)
       return NULL;
 
   int count = 1;
   struct Node *prev = NULL;
   struct Node  *current = node;
   struct Node *next;
   while(current != NULL && count <= k){
       next = current->next;
       if(b == true)
          current->next = prev;
             
       prev = current;
       current = next;
       count++;
   }
   if(b == true){
        node->next = reverseAlternateKNodes(current,k,!b);
        return prev;       
   }
 
   else{
        prev->next = reverseAlternateKNodes(current, k, !b);
        return node;      
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
	 int k;
	 scanf("%d",&k);
	 struct Node* ans = NULL;
	 ans = reverseAlternateKNodes(head,k);
	 PrintLinkedList(ans);
	return 0;
}

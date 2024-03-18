#include<stdio.h>
#include<stdlib.h>

struct doublylist{
	struct doublylist* next;
	struct doublylist* prev;
	int val;
};

struct doublylist* initialize(int val){
	struct doublylist* ptr = (struct doublylist*)malloc(sizeof(struct doublylist));
	ptr->val=val;
	ptr->prev=NULL;
	ptr->next=NULL;
	return ptr;
}

struct doublylist* addnode_last(struct doublylist* tail,int val){
	struct doublylist* ptr = (struct doublylist*)malloc(sizeof(struct doublylist));
	ptr->val=val;
	ptr->prev = tail;
    tail->next=ptr;
	ptr->next=NULL;
	return ptr;
}

struct doublylist* addnode_start(struct doublylist* head,int val){
	struct doublylist* ptr = (struct doublylist*)malloc(sizeof(struct doublylist));
	ptr->val=val;
	ptr->prev=NULL;
	ptr->next=head;
	return ptr;
}

int delete_by_val(int val, struct doublylist** head_ref) {
    struct doublylist* temp = *head_ref;
    
    // Traverse the list to find the node with the given value
    while (temp != NULL) {
        if (temp->val == val) {
            // If the node to be deleted is the head node
            if (temp == *head_ref) {
                *head_ref = temp->next;
                if (*head_ref != NULL)
                    (*head_ref)->prev = NULL;
            } else {
                // Adjust pointers of previous and next nodes
                if (temp->prev != NULL)
                    temp->prev->next = temp->next;
                if (temp->next != NULL)
                    temp->next->prev = temp->prev;
            }
            
            // Free the memory of the node to be deleted
            free(temp);
            return 1;
        }
        temp = temp->next;
    }
    return 0;
}


void traversal(struct doublylist* head){
	struct doublylist* temp = head;
	do{
		printf("%d\n",temp->val);	
		temp=temp->next;
	}while(temp!=NULL);
}

int main(){
	struct doublylist* head = NULL;
	struct doublylist* tail = NULL;
	int val,choice;
	printf("Enter the value of first node :-");
	scanf("%d",&val);
	head=tail=initialize(val);
	while(1){
		printf("MENU :\n1. Add node at last\n2. Add node at beginning\n3.delete by value\n4.traverse doubly linkedlist\n5.Exit\nEnter your option:-");
		scanf("%d",&choice);
		switch(choice){
		case 1:
			printf("Enter the value of node :-");
			scanf("%d",&val);
			tail=addnode_last(tail,val);
			break;
		case 2:
			printf("Enter the value of node :-");
			scanf("%d",&val);
			head=addnode_start(head,val);
			break;
		
		case 3:
			printf("Enter the value of node to delete :-");
			scanf("%d",&val);
			if(!delete_by_val(val,&head)){
				printf("Node not found\n");
			}
            else{
                printf("Node deleted successfully.");
            }
			break;
		case 4:
			traversal(head);
			break;
		case 5:
			return 0;
			break;
		default:
			printf("Error\n");
		}
	}
	return 0;
	
}
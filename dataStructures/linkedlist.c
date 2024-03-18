#include<stdio.h>
#include<stdlib.h>

struct list{
    struct list* next;
    int val;
};

struct list* STARTNODE(int val){
    struct list* ptr = (struct list*)malloc(sizeof(struct list));
    ptr->val=val;
    ptr->next=NULL;
    return ptr;
}

struct list* createnode_atlast(struct list *last,int val){
    struct list* ptr = (struct list*)malloc(sizeof(struct list));
    ptr->val=val;
    last->next=ptr;
    ptr->next=NULL;
    last=ptr;
    return last;
}

struct list* createnode_atbeginning(struct list *start,int val){
    struct list* ptr = (struct list*)malloc(sizeof(struct list));
    ptr->val=val;
    ptr->next = start;
    return ptr;
}

struct list *traversal(struct list* start){
    struct list* ptr;
    ptr = start;
    while(ptr != NULL){
        printf("value = %d\n",ptr->val);
        ptr = ptr->next;
    }
    return ptr;
}

int main(){
    int val,choice;
    struct list* start = NULL;
    struct list *last = NULL;

    printf("enter the value of first node : ");
    scanf("%d",&val);
    start = STARTNODE(val);
    last = start;
    while(choice != 4) {
        printf("Choose one from the below options...\n");  
        printf("\n1. Create node at beginning\n2. Create node at last\n3. Traverse the linked list\n4. Exit\n");
        printf("\nEnter your choice: ");        
        scanf("%d",&choice);  
        switch(choice) {  
            case 1: {   
                printf("Enter the value to store in node added at beginning: ");
                scanf("%d",&val);
                start = createnode_atbeginning(start,val);
                break;  
            }  
            case 2: {  
                printf("Enter the value to store in node added at last: ");
                scanf("%d",&val);
                last = createnode_atlast(last,val);
                break;  
            }  
            case 3: {  
                traversal(start);
                break;  
            }  
            case 4: {  
                printf("Exiting....\n");  
                break;   
            }  
            default: {  
                printf("Please Enter valid choice ");  
            }   
        };  
    }
    return 0;
}

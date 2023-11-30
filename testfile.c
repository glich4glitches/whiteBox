#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* next;
    struct Node* prev;
};

struct Node* createNode(int data){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

//Display All Nodes
int display(struct Node* head){
    printf("\nData: ");
    while(head != NULL){
        printf("%d",head->data);
        head = head->next;
    }
}

//Insertion at the end
int insertionAtTheEnd(struct Node **head, int data){
    struct Node* generateNewNode = createNode(data);
    if(*head == NULL){
        *head = generateNewNode;
        return;
    }

    struct Node* tmp = *head;
    while(tmp->next != NULL){
        tmp = tmp->next;
    }
    tmp->next = generateNewNode;
}

//Insertion at start
int insertionAtStart(struct Node **head, int data){
    struct Node* newNode = createNode(data);
    if(*head == NULL){
        *head = newNode;
        return;
    }

    struct Node* tmp = *head;
    struct Node* prev = NULL;
    *head = newNode;
    prev = *head;
    prev->next = tmp;
}

//Insertion at specific position
int insertASP(struct Node **head, struct Node *position,int data){
    struct Node* newNode = createNode(data);
    if(position == NULL){
        printf("\nPosition-[%d]:",position);
        printf("Given location can't be null..!");
        return;
    }

    struct Node* tmp = *head;
    struct Node* prev2 = NULL;
    struct Node* tmp2 = NULL;
    int flag = 0;
    while(tmp != NULL){
        if(tmp->data == position){
            flag = 1;
            if(tmp->next == NULL){
                tmp->next = newNode;
                return;
            }
            //addition

            prev2 = tmp->next;
            //struct Node* next = tmp->next;
            tmp->data = newNode;
            //tmp2 = tmp->next;
            //tmp->prev = prev;
            //tmp->next = next;
            newNode->next = prev2;
            //tmp2->next = prev;
            
            printf("\n[%d:at:%d]:Node added successfully..!",data,position);
            //display(*head);
            //break;
        }
        tmp = tmp->next;

    }

    if(flag != 1){
        printf("\n[%d]:Position not found..!",position);
    }
}

int main(){
    printf("Hello! Linked List..");
    printf("\nnewNode: %d",*createNode(5));
    
    //create sample linked list
    struct Node* head = NULL;
    struct Node* one = createNode(1);
    struct Node* two = createNode(2);
    struct Node* three = createNode(3);
    struct Node* four = createNode(4);
    struct Node* five = createNode(5);
    struct Node* six = createNode(1);
    struct Node* seven = createNode(1);
    struct Node* eight = createNode(7);

    //struct Node* prev;

    one->next = two;
    two->next = three;
    three->next = four;
    four->next = five;
    five->next = six;
    six->next = seven;
    seven->next = eight;
    eight->next = NULL;

    two->prev = one;
    three->prev = two;
    four->prev = three;
    five->prev = four;
    six->prev = five;
    seven->prev = six;
    eight->prev = seven;
    
    

    head = one;
    
    // printf("\nByDefualt:-");
    // display(head);
    // printf("\n");

    // printf("\nAT-THE-END:-");
    // insertionAtTheEnd(&head,7);
    // insertionAtTheEnd(&head,9);
    // display(head);
    // printf("\n");

    // printf("\nAT-START:-");
    // insertionAtStart(&head,2);
    // insertionAtStart(&head,1);
    // insertionAtStart(&head,0);
    // display(head);
    // printf("\n");

    printf("\nDefault:-");
    display(head);
    //printf("\n");
    //printf("\nAT-SPECIFIC-POSITION:-");
    //struct Node* position = 1;
    //insertASP(&head,position, 9);
    display(head);
    printf("\n");
}

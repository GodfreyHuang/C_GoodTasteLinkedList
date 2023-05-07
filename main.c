//
//  main.c
//  C_GoodTasteLinkedList
//
//  Created by Godfrey on 2023/5/4.
//  Reference from https://hackmd.io/@Mes/The_mind_behind_Linux
//

#include <stdio.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

typedef struct List {
    Node *head;
} List;

Node **find(List *list, Node *target) {
    Node **indirect = &list->head;
    while(*indirect != NULL && *indirect != target)
        indirect = &(*indirect) -> next;
    return indirect;
}

void remove_node(List *list, Node *target) {
    Node **indirect = find(list, target);
    if(*indirect)
        *indirect = target->next;
}

void insert_before(List *list, Node *target, Node *item) {
    Node **indirect = find(list, target);
    item->next = *indirect;
    *indirect = item;
}

void output_list(List *list) {
    Node **indirect = &list->head;
    while(*indirect) {
        printf("%d ", (*indirect)->data);
        indirect = &(*indirect)->next;
    }
    printf("\n");
}

int main(int argc, const char * argv[]) {
    Node items[10];
    List list;
    for(int i = 0; i < 10; i++) {
        items[i].data = i+1;
        items[i].next = NULL;
    }
    list.head = NULL;
    
    remove_node(&list, &items[0]);
    output_list(&list);
    
    for(int i = 0; i < 10; i++) {
        insert_before(&list, &items[5], &items[i]);
        output_list(&list);
    }
    
    remove_node(&list, &items[5]);
    remove_node(&list, &items[5]);
    remove_node(&list, list.head);
    
    output_list(&list);
    return 0;
}

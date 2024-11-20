#include <stdlib.h>  
#include <stdio.h>  
#include "sll_node.h"

#define FALSE 0  
#define TRUE 1  


int sll_insert(Node** head, int new_value);

void print_list(Node* head);

int main() {
    Node* head = NULL; // 初始化链表头为空  
    int values[] = { 5, 3, 8, 1, 7 }; // 要插入的值  
    int num_values = sizeof(values) / sizeof(values[0]);

    // 插入值到链表  
    for (int i = 0; i < num_values; i++) {
        if (sll_insert(&head, values[i]) == FALSE) {
            printf("Failed to insert %d into the list.\n", values[i]);
        }
    }

    // 打印链表  
    printf("Sorted Linked List: ");
    print_list(head);

    // 释放链表内存  
    Node* current = head;
    while (current != NULL) {
        Node* temp = current;
        current = current->link;
        free(temp);
    }

    return 0;
}

int sll_insert(Node** head, int new_value) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    if (new_node == NULL) {
        return FALSE; // 内存分配失败  
    }
    new_node->value = new_value;
    new_node->link = NULL;

    // 如果链表为空，或者新值小于链表头节点的值，则插入到头部  
    if (*head == NULL || (*head)->value >= new_value) {
        new_node->link = *head;
        *head = new_node;
        return TRUE;
    }

    Node* current = *head;
    Node* previous = NULL;

    // 找到插入位置  
    while (current != NULL && current->value < new_value) {
        previous = current;
        current = current->link;
    }

    // 插入新节点  
    new_node->link = current;
    previous->link = new_node;
    return TRUE;
}

void print_list(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%d ", current->value);
        current = current->link;
    }
    printf("\n");
}
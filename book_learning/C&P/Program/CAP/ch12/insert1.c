#include <stdlib.h>  
#include <stdio.h>  
#include "sll_node.h"

#define FALSE 0  
#define TRUE 1  


int sll_insert(Node** head, int new_value);

void print_list(Node* head);

int main() {
    Node* head = NULL; // ��ʼ������ͷΪ��  
    int values[] = { 5, 3, 8, 1, 7 }; // Ҫ�����ֵ  
    int num_values = sizeof(values) / sizeof(values[0]);

    // ����ֵ������  
    for (int i = 0; i < num_values; i++) {
        if (sll_insert(&head, values[i]) == FALSE) {
            printf("Failed to insert %d into the list.\n", values[i]);
        }
    }

    // ��ӡ����  
    printf("Sorted Linked List: ");
    print_list(head);

    // �ͷ������ڴ�  
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
        return FALSE; // �ڴ����ʧ��  
    }
    new_node->value = new_value;
    new_node->link = NULL;

    // �������Ϊ�գ�������ֵС������ͷ�ڵ��ֵ������뵽ͷ��  
    if (*head == NULL || (*head)->value >= new_value) {
        new_node->link = *head;
        *head = new_node;
        return TRUE;
    }

    Node* current = *head;
    Node* previous = NULL;

    // �ҵ�����λ��  
    while (current != NULL && current->value < new_value) {
        previous = current;
        current = current->link;
    }

    // �����½ڵ�  
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
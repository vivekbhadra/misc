#include <stdio.h>
#include <stdlib.h>

/* define the linked list node */
typedef struct node {
    int val;
    struct node *next;
}node_t;

/* Prototype*/
void add_node(node_t **, int);
void del_node(node_t **, int);
void insert_node(node_t **, int);
void del_tree(node_t **);
void print_tree(node_t **);

void add_node(node_t **head, int val)
{
    if (*head == NULL) {
        *head = (node_t *)malloc(sizeof(node_t));
        (*head)->val = val;
        (*head)->next = NULL;
    }
    else {
        /*iterate over the list to reach the end node*/
        node_t *temp = *head;
        while((temp)->next)
        {
            (temp) = (temp)->next;
        }

        (temp)->next = (node_t *) malloc(sizeof(node_t));
        (temp)->next->val = val;
        (temp)->next->next = NULL;
    }
}

void del_node(node_t **head, int val)
{
    node_t *temp = *head;
    node_t *prev = temp;

    if (temp->val == val)
    {
        /* deleting the head node */
        *head = temp->next;
        free(temp);
    } else {

        while(temp != NULL)
        {
            if (temp->val == val) {
                prev->next = temp->next;
                free(temp);
                temp = NULL;
            } else {
                prev = temp;
                temp = temp->next;
            }
        }
    }
}

void insert_node(node_t **head, int val)
{
    node_t *temp = *head;
    node_t *prev = *head;

    if (temp->val > val)
    {
        /* insert at beginning */
        node_t *new_node = (node_t *) malloc(sizeof(node_t));
        new_node->val = val;
        new_node->next = *head;
        *head = new_node;
    } else {
        while(temp != NULL)
        {
            if (temp->val < val) {
                prev = temp;
                temp = temp->next;
            } else if (temp->val > val) {
                node_t *new_node = malloc(sizeof(node_t));
                new_node->val = val;
                new_node->next = temp;
                prev->next = new_node;
                break;
            }
        }
    }
}

void del_tree(node_t **head)
{
    node_t *temp;

    while((*head) != NULL)
    {
        temp = *head;
        (*head) = (*head)->next;
        printf("Deleting node with val = %d\n", temp->val);
        free(temp);
    }
}
void print_tree(node_t **head)
{
    node_t *temp = *head;
    while (temp != NULL)
    {
        printf("%d\n", (temp)->val);
        (temp) = (temp)->next;
    }
}

int main(int argc, char **argv)
{
    node_t *head = NULL;

    add_node(&head, 5);
    add_node(&head, 10);
    add_node(&head, 20);
    add_node(&head, 30);
    add_node(&head, 40);
    add_node(&head, 50);


    print_tree(&head);

    del_node(&head, 30);

    printf("=============\n");

    print_tree(&head);

    insert_node(&head, 25);

    printf("=============\n");

    print_tree(&head);

    insert_node(&head, 2);

    printf("=============\n");

    print_tree(&head);

    return 0;
}

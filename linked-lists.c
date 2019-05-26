#include <stdio.h>

#include "linked-lists.h"

/**
 * Searches for a number in a linked list.
 */
int listSearch(node *L, int k)
{
    // Move down the list until you find a node with key k
    while(L != NULL && L->key != k)
    {
        L = L->next;
    }
    
    return L;
}

/**
 * Inserts a number into a linked list.
 */
int listInsert(node **L, int k)
{
    // If new linked list, head will be NULL
    if ((*L)->key == NULL)
    {
        (*L)->key = k;
    }
    
    else
    {    
        // Create an instance of a new node
        node *newnode = malloc(sizeof(node));
        if (newnode == NULL)
        {
            return -1;
        }
        
        // printf("Created new node\n");
        newnode->key = k;
        newnode->next = (*L);
        
        if ((*L) != NULL)
        {
            (*L)->prev = newnode;
        }

        (*L) = newnode;
        newnode->prev = NULL;
    }

}

/**
 * Delete a number from a linked list.
 */
void listDelete(node **L, node *x)
{
    // If x is not the head node, set x's predecessor to point to x's successor
    if (x->prev != NULL)
    {
        x->prev->next = x->next;
    }
    
    // If x is the head node, set the head to point to x's successor
    else
    {
        *L = x->next;
    }
    
    // If x is not the tail node, set x's successor to point to x's predecessor
    if (x->next  != NULL)
    {
        x->next->prev = x->prev;
    }
    
    free(x);
}

/**
 * Traverses a linked list, printing its numbers.
 */
void traverse(node *L)
{
    while (L != NULL)
    {
        printf("%i,", L->key);
        L = L->next;
    }

    printf("\n\n");
}

int main(void)
{
    // Initialize array of values to insert into linked list
    int A[] = {5, 6, 4, 2, 4, 3, 10};
    size_t n = sizeof(A) / sizeof(A[0]);
    
    // Instantiate the head of the linked list
    node *head = malloc(sizeof(node));
    if (head == NULL)
    {
        return -1;
    }
    head->key = NULL;
    head->next = NULL;

    // Insert values into linked list
    for (int i = 0; i < n; i++)
    {
        listInsert(&head, A[i]);
    }

    // Print the values of the linked list
    traverse(head);

    // Search for a key in the list
    int x = listSearch(head, 6);
    printf("Key %i is located at %x\n", 6, x);

    // Delete a node from the linked list
    printf("Deleting %i at location %x\n", 6, x);
    listDelete(&head, x);

    traverse(head);

    // free list before quitting
	node *ptr = head;
	while (ptr != NULL)
	{
		node *predptr = ptr;
		ptr = ptr->next;
		free(predptr);
	}

    return 0;
}
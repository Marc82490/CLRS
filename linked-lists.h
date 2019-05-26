/**
 * Defines the structures for a linked list of integers
 */

typedef struct node
{
    struct node *prev;
    int key;
    struct node *next;

}
node;
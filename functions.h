#ifndef FUNCTIONS_H //check if this has been defined before
#define FUNCTIONS_H

#include <stdbool.h>
#include <stdlib.h>
#include <cs50.h>

#define CAPACITY 27

int word_counter;

typedef struct node
{
    struct node *children[CAPACITY];
    struct node *parent;
    bool is_word;
}
node;

static node *root = NULL;

static inline struct node *get_node(node *pointer)
{
    node *n = malloc(sizeof(node));
    if(!n)
    {
        return NULL;
    }

    for (int i = 0; i < CAPACITY; i++)
    {
        n->children[i] = NULL;
    }
    n->is_word = false;
    n->parent = pointer; // parent is the calee
    return n;
};

bool check_word(const char *ptr_word, node *root_ptr);
bool trie_load(const char *ptr_dictionary, node *ptr_node);
bool free_load(node *pointer);



#endif
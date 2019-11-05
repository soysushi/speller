
#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "functions.h"

// function to load a trie data structure
bool trie_load(const char *ptr_dictionary_word, node* ptr_node)
{
        node *traverse = ptr_node;
        // for each letter, turn it into the proper index to access until the end of the word
        for (int i = 0, j = strlen(ptr_dictionary_word); i < j; i++)
        {
            // casting all characters into integer for proper indexing
            int index = tolower(ptr_dictionary_word[i]) - 97;
            // special case if the character is an apostrophe
            if (ptr_dictionary_word[i] == '\'')
            {
                index = CAPACITY - 1;
            }

            if (traverse->children[index] == NULL)
            {
                traverse->children[index] = get_node(traverse->children[index]);
            }
            traverse = traverse->children[index];

            if (i == j - 1)
            {
                traverse->is_word = true;
                word_counter++;
            }

        }
        return true;
}

bool check_word(const char *ptr_word, node *root_ptr)
{
    node* traverse = root_ptr;
    for (int i = 0, j = strlen(ptr_word); i < j; i++)
        {
            // casting all characters into integer for proper indexing
            int index = tolower(ptr_word[i]) - 97;
            // special case if the character is an apostrophe
            if (ptr_word[i] == '\'')
            {
                index = CAPACITY - 1;
            }

            // in this case. traverse is null

            if (traverse) // while traverse is valid
            {
                traverse = traverse->children[index];

                if (traverse == NULL) // if the traverse children at index is NULL
                {
                    return false; // return false
                }

                else if ((i == j - 1) && traverse->is_word == true) //
                {
                    return true;
                }
             }
        }
    return false;
}

// problem lies in when it returns the new node, the index stays same, it needs to reset to 0
bool free_load(node *pointer)
{
    node *traverse = pointer;
    while(traverse != NULL)
    {

        for (int i = 0; i < CAPACITY; i++)
        {
            if (traverse->children[i]) // if children is valid, go there and recursive call to start from new leaf at 0 index
            {
                free_load(traverse->children[i]);
            }
        }
        node *temp = traverse->parent; // save the parent location
        free(traverse); // free current node
        traverse = temp; // go back to previous node
        free_load(traverse); // recursive call all children again, deletion from bottom up
    }
    return true;
}
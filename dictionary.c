// Implements a dictionary's functionality

#include <stdbool.h>
#include "dictionary.h"
#include <stdio.h>




// Returns true if word is in dictionary else false
bool check(const char *word)
{
    if (check_word(word, root) == true)
    {
        return true;
    }

    return false;
}

// Loads dictionary into memory, returning true if successful else false


bool load(const char *dictionary)
{
    FILE *ptr = fopen(dictionary, "r");

    if (ptr == NULL)
    {
        fclose(ptr);
        printf("could not open %p", dictionary);
        return 3;
    }
    else
    {

        char dictionary_word[LENGTH];
        bool results = false;
        root = get_node(root);
        while(fscanf(ptr, "%s", dictionary_word) != EOF)
        {
            results = trie_load(dictionary_word, root);
        }

        if (results == true)
        {
            fclose(ptr);
            return true;
        }
    }
    return false;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    if (word_counter != 0)
    {
        return word_counter;
    }
    return 0;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    // TODO
    if (free_load(root) == true)
    {
        return true;
    }
    return false;
}

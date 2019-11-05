typedef struct node
{
    struct node *children[CAPACITY];
    struct node *parent;
    bool is_word;
}
node;
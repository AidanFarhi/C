#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/* Node Definition */
typedef struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
}
Node;

/* Initialize NULL Root */
Node *root = NULL;

/* Function Prototypes */
void insert(int data); // O(log N)
static void __insert_helper(Node *n, int data);
bool search(int data); // O(log N) best case | O(N) worst case
static bool __search_helper(Node *n, int data);
int tree_height(); // O(log N) best case | O(N) worst case
bool is_empty();
void traverse_in_order(); // O(N)
static void __traverse_helper(Node *n);
void delete_tree();
void cleanup(Node *n);

/* Test Client */
int main(int argc, char *argv[])
{
    // Insert a some nodes into tree
    FILE *test_file = fopen(argv[1], "r");
    if (test_file == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }
    int data;
    while (fscanf(test_file, "%i", &data) != EOF)
    {
        insert(data);
    }
    printf("18 in tree: %s\n", search(18) ? "true" : "false");
    printf("33 in tree: %s\n", search(33) ? "true" : "false");
    printf("100 in tree: %s\n", search(100) ? "true" : "false");
    traverse_in_order();
    delete_tree();
    traverse_in_order();
    fclose(test_file);
}

/* Functions */
bool is_empty()
{
    if (root == NULL)
    {
        return true;
    }
    return false;
}

void insert(int data)
{
    if (is_empty())
    {
        root = malloc(sizeof(Node));
        root->data = data;
        root->left = NULL;
        root->right = NULL;
    }
    else
    {
        __insert_helper(root, data);
    }
}

// Recursively travel through tree
static void __insert_helper(Node *n, int data)
{
    if (n->data < data)
    {
        if (n->right == NULL)
        {
            n->right = malloc(sizeof(Node));
            n->right->data = data;
            n->right->right = NULL;
            n->right->left = NULL;
        }
        else
        {
            __insert_helper(n->right, data);
        }
    }
    else if (n->data > data)
    {
        if (n->left == NULL)
        {
            n->left = malloc(sizeof(Node));
            n->left->data = data;
            n->left->left = NULL;
            n->left->right = NULL;
        }
        else
        {
            __insert_helper(n->left, data);
        }
    }
    else
    {
        printf("Data %i already exists in tree.\n", data);
    }
}

bool search(int data)
{
    if (is_empty())
    {
        return false;
    }
    else
    {
        return __search_helper(root, data);
    }
}

static bool __search_helper(Node *n, int data)
{
    if (n == NULL)
    {
        return false;
    }
    else if (n->data > data)
    {
        return __search_helper(n->right, data);
    }
    else if (n->data < data)
    {
       return __search_helper(n->left, data);
    }
    else
    {
        return true;
    }
}

void traverse_in_order()
{
    if (is_empty())
    {
        printf("Tree is empty.\n");
    }
    else
    {
        printf("HEAD->");
        __traverse_helper(root);
        printf("NULL\n");
    }
}

static void __traverse_helper(Node *n)
{
    if (n->left != NULL)
    {
        __traverse_helper(n->left);
    }
    printf("(%i)->", n->data);
    if (n->right != NULL)
    {
        __traverse_helper(n->right);
    }
}

void delete_tree()
{
    printf("Deleting nodes...\n");
    cleanup(root);
    root = NULL;
    printf("Tree has been cleared of all nodes.\n");
}

// Same as traverse in order, we are just deleting as we go down the tree
void cleanup(Node *n)
{
    if (n->left != NULL)
    {
        cleanup(n->left);
    }
    Node *temp_right = n->right;
    free(n);
    if (temp_right != NULL)
    {
        cleanup(temp_right);
    }
}
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define STRING_MAX 19

struct treeNode {

    char string[STRING_MAX+1];
    int height;
    struct treeNode *left;
    struct treeNode *right;
    int numNodes;

}

struct treeNode *createNode(void);
struct treeNode *insertWord(struct treeNode *root, char string[STRING_MAX+1]);



int main(void)
{
    int numWords, i;
    char word[STRING_MAX+1];

    struct treeNode *root = NULL;

    scanf("%d", &numWords);

    for (i = 0; i < numWords; i++)
    {
        scanf("%s", word);
        insertWord(root, word);
    }

    printf("Height: %d\n", root->height);

    return 0;
}


// Creates Node
struct treeNode *createNode(void)
{
    struct treeNode *temp = malloc(sizeof(struct treeNode));
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}

// Inserts
struct treeNode *insertWord(struct treeNode *root, char string[STRING_MAX+1])
{
    if (root == NULL)
    {
        struct treeNode *temp = createNode();
        strcpy(temp->string, string);
        temp->height = 0;
        return temp;
    }

    if (strcmp(string, string) <= 0)
    {
        root->left = insert(root->left, string);

        if (root->left->height == root->height)
            root->height++;
    }

    else
    {
        root->right = insert(root->right, string);

        if (root->right->height == root->height)
            root->height++;
    }

}

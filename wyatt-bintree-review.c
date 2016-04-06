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

};

struct treeNode *createNode(void);
struct treeNode *insertWord(struct treeNode *root, char string[STRING_MAX+1]);
struct treeNode *findWord(struct treeNode *root, char string[STRING_MAX+1]);
int findNumNodes(struct treeNode *root);

void inorder(struct treeNode* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%s h:%d\n", root->string, root->height);
        inorder(root->right);
    }
}

int main(void)
{
    int numWords, i;
    char word[STRING_MAX+1];

    struct treeNode *root = NULL;

    scanf("%d", &numWords);

    int count = 0;
    for (i = 0; i < numWords; i++)
    {
        scanf("%s", word);
        //printf("Storing %s\n", word);
        if (word[0] == 'S')
            count++;
        root = insertWord(root, word);
    }
    printf("Count: %d\n", count);
    // Prints the Height of the entire tree
    printf("Height: %d\n", root->height);

    char wordToFind[] = "apple";

    struct treeNode *wordsy = findWord(root, wordToFind);
    printf("Found %s\n The height is: %d\n", wordsy->string, wordsy->height);

    wordsy = findWord(root, "computer");
    printf("\nNum Nodes in Computer: %d\n", findNumNodes(wordsy)+1);
    inorder(wordsy);
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

    if (strcmp(root->string, string) <= 0)
    {
        if (strcmp(root->string, string) == 0)
            printf("%s\n", string);
        root->left = insertWord(root->left, string);

        if (root->left->height == root->height)
            root->height++;
    }

    else
    {
        root->right = insertWord(root->right, string);

        if (root->right->height == root->height)
            root->height++;
    }
    return root;
}

struct treeNode *findWord(struct treeNode *root, char string[STRING_MAX+1])
{
    if (root == NULL)
        return NULL;

    if (strcmp(root->string, string) < 0)
        return findWord(root->left, string);
    else if (strcmp(root->string, string) > 0)
        return findWord(root->right, string);
    else if (strcmp(root->string, string) == 0)
        return root;

}

int findNumNodes(struct treeNode *root)
{
    if (root == NULL)
        return 0;

    int total = findNumNodes(root->left) + findNumNodes(root->right);

    if (root->left != NULL && root->right == NULL)
        total++;
    else if (root->left == NULL && root->right != NULL)
        total++;
    else if (root->left != NULL && root->right != NULL)
        total += 2;

    return total;
}

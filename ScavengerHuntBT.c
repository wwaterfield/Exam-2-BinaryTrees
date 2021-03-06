#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 19

struct node {
    char string[MAX_LENGTH+1];
    int height;
    struct node* left;
    struct node* right;
};


struct node* createNode(char string[MAX_LENGTH+1], int k)
{
    struct node* temp = malloc(sizeof(struct node));
    strcpy(temp->string, string);
    temp->height = k;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

struct node* insert(struct node* root, char string[MAX_LENGTH+1], int k)
{
    if(root == NULL)
        root = createNode(string,k);
    else if(strcmp(root->string, string) >= 0)
        root->left = insert(root->left, string, k+1);
    else if(strcmp(root->string, string) < 0)
        root->right = insert(root->right, string, k+1);
    return root;
}

int find(struct node* root, char string[MAX_LENGTH+1], int k)
{
    if(root == NULL)
        return k;
    return find(root->left, string, k+1) + find(root->right, string, k+1);
}

int height(struct node* root, char string[MAX_LENGTH+1])
{
    int k;
    if(strcmp(root->string, string) == 0)
        return root->height;
    else if(strcmp(root->string, string) > 0)
        k = height(root->left, string);
    else if(strcmp(root->string, string) < 0)
        k = height(root->right, string);
    return k;
}

int wheight(struct node* root)
{
    int k, j;
    if(root == NULL)
        return 0;
    if(root->left == NULL && root->right == NULL)
        return root->height;

        j = wheight(root->left);
        k = wheight(root->right);
    if(j > k)
        return j;
    return k;
}


int main(void)
{
    int i, j, insertnum, currentcase, k=0;
    char string[MAX_LENGTH+1];
    struct node* root = NULL;
    scanf("%d", &insertnum);
    for(currentcase = 0;currentcase < insertnum; currentcase++)
    {
        scanf("%s", string);
        root = insert(root, string, k);
    }
    int compfind = height(root, "science");//find(root, "computer", k+1);
    int hlength = wheight(root);
    printf("%d", hlength);

    return 0;
}

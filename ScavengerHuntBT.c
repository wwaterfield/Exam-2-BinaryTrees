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

int evenHeight(struct node *root)
{
    if(root == NULL)
        return 0;
    int x = aheight(root, 0);
	return x + evenHeight(root->left) + evenHeight(root->right);
}


struct node* createNode(char string[MAX_LENGTH+1], int k)
{
    struct node* temp = malloc(sizeof(struct node));
    strcpy(temp->string, string);
    temp->height = k;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

struct node *insertWord(struct node *root, char string[MAX_LENGTH+1])
{
    if (root == NULL)
    {
        struct node *temp = malloc(sizeof(struct node));
        temp->left = NULL;
        temp->right = NULL;
        strcpy(temp->string, string);
        temp->height = 0;
        return temp;
    }

    if (strcmp(root->string, string) >= 0)
    {
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

int aheight(struct node* root) {

    // Height of an empty tree.
    if (root == NULL) return 0;
    // Find out heights of both sides.
    int leftSide = aheight(root->left);
    int rightSide = aheight(root->right);

    return leftSide+rightSide+1;

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
    {
        printf("%d\n", root->height);
        return root->height;
    }


        j = wheight(root->left);
        k = wheight(root->right);
    if(j > k)
        return j;
    return k;
}

int subheight(struct node* root)
{
    if(root == NULL)
        return 0;
    return root->height + subheight(root->left) + subheight(root->right);
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
        root = insertWord(root, string);
    }

    //int compfind = height(root, "science");//find(root, "computer", k+1);
    //int hlength = aheight(root);
    int glength = subheight(root);
    int even = evenHeight(root);
    printf("%d", even);

    return 0;
}

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
void inorder(struct treeNode* root);
int evenHeight(struct treeNode *root);
int sumOfHeights(struct treeNode *root);

// Returns the height of the tree with root root.
int height(struct treeNode* root) {

    // Height of an empty tree.
    if (root == NULL) return -1;

    // Find out heights of both sides.
    int leftSide = height(root->left);
    int rightSide = height(root->right);

    // Choose the bigger one and add one.
    if (leftSide > rightSide)
        return leftSide+1;
    else
        return rightSide+1;

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
        root = insertWord(root, word);
    }
    //printf("Count: %d\n", count);
    // Prints the Height of the entire tree
    printf("Height: %d\n", root->height);

  

    struct treeNode *wordsy;
    inorder(root);
    
    printf("Num Even Nodes: %d\n", evenHeight(root));
    printf("Arup Height: %d\n", height(root));
    printf("Sum of Heights: %d\n", sumOfHeights(root)+root->height);
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

// Inserts a word into the Binary Tree.
struct treeNode *insertWord(struct treeNode *root, char string[STRING_MAX+1])
{
    if (root == NULL)
    {
        struct treeNode *temp = createNode();
        strcpy(temp->string, string);
        temp->height = 0;
        return temp;
    }

    if ((int)strcmp(string, root->string) <= 0)
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

// Finds a word in the tree and returns a pointer to the node.
struct treeNode *findWord(struct treeNode *root, char string[STRING_MAX+1])
{
    if (root == NULL)
        return NULL;

    if (strcmp(string, root->string) < 0)
        findWord(root->left, string);
    else if (strcmp(string, root->string) > 0)
        findWord(root->right, string);
    else if (strcmp(string, root->string) == 0)
        return root;

}

//Finds the total number of nodes in a subtree (not including the root node).
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

// Prints out in ord
void inorder(struct treeNode* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%s h:%d\n", root->string, root->height);
        inorder(root->right);
    }
}

int evenHeight(struct treeNode *root)
{
	if (root == NULL)
		return 0;
	int total = evenHeight(root->left) + evenHeight(root->right);
	
	if (root->left != NULL)
		if (root->left->height % 2 == 0)
			total++;
	if (root->right != NULL)
		if (root->right->height % 2 == 0)
			total++;
	return total;
}

int sumOfHeights(struct treeNode *root)
{
	if (root == NULL) return 0;
	int sum = sumOfHeights(root->left) + sumOfHeights(root->right);
	
	if (root->left != NULL)
		sum += root->left->height;
	if (root->right != NULL)
		sum += root->right->height;
	return sum;
	
}

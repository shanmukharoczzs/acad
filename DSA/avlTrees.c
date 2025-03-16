#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef struct TreeNode {
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
    int height;
}TreeNode;

TreeNode *CreateNode(int key){
    TreeNode *node = (TreeNode*)malloc(sizeof(TreeNode));
    node->data = key;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;
    return node;
}

int Height(TreeNode* root){
    if(root == NULL){
        return 0;
    }
    return root->height;
}

int max(int a, int b){
    return (a>b) ? a : b;
}

int getBalence(TreeNode *root){
    if(root == NULL){
        return 0;
    }
    return Height(root->left) - Height(root->right);
}

TreeNode* LeftR(TreeNode* x){
    TreeNode *y = x->right;
    TreeNode *t1 = y->left;

    y->left = x;
    x->right = t1;
    x->height = max(Height(x->left),Height(x->right)) + 1;
    y->height = max(Height(y->left),Height(y->right)) + 1;
    return y;
}

TreeNode* RightR(TreeNode* x){
    TreeNode *y = x->left;
    TreeNode *t1 = y->right;

    y->right = x;
    x->left = t1;
    x->height = max(Height(x->left),Height(x->right)) + 1;
    y->height = max(Height(y->left),Height(y->right)) + 1;
    return y;
}

TreeNode *Insert(TreeNode* root , int key){
    if(root==NULL){
        return CreateNode(key);
    }
    if(key<root->data){
        root->left = Insert(root->left,key);
    }
    else if(key>root->data){
        root->right = Insert(root->right,key);
    }
    else{
        return root;
    }

    // AVL
    //Find height
    root->height = 1 + max(Height(root->left),Height(root->right));
    //Find the balence factor
    int bf = getBalence(root);
    //cases
    //LL
    if(bf > 1 && key < root->left->data){
        return RightR(root);
    }
    //LR
    if(bf > 1 && key > root->left->data){
        root->left = LeftR(root->left);
        return RightR(root);
    }
    //RR
    if(bf < -1 && key > root->right->data){
        return LeftR(root);
    }
    //RL
    if(bf < -1 && key < root->right->data){
        root->right = RightR(root->right);
        return LeftR(root);
    }
    return root;
}

TreeNode* MinValueNode(TreeNode* root){
    TreeNode* temp = root->right;
    while (temp && temp->left){
        temp = temp->left;
    }
    return temp;
}

TreeNode *Delete(TreeNode* root , int key){
    if(root==NULL) return NULL;
    if(key < root->data){
        root->left = Delete(root->left, key);
    }
    else if(key > root->data){
        root->right = Delete(root->right, key);
    }
    else{
        //if no child or one child
        if(root->left == NULL || root->right == NULL){
            TreeNode* temp = root;
            if(temp->left == NULL) return temp->right;
            if(temp->right == NULL) return temp->left;
        }
        //if two child
        TreeNode* temp = MinValueNode(root->right);
        root->data = temp->data;
        root->right = Delete(root->right, temp->data);
        
        // Check balence and perform rotations
        root->height = 1 + max(Height(root->left),Height(root->right));
        int bf = getBalence(root);
        //cases
        //LL
        if(bf > 1 && getBalence(root->left) >= 0){
            return RightR(root);
        }
        //LR
        if(bf > 1 && getBalence(root->left) < 0){
            root->left = LeftR(root->left);
            return RightR(root);
        }
        //RR
        if(bf < -1 && getBalence(root->right) <= 0){
            return LeftR(root);
        }
        //RL
        if(bf < -1 && getBalence(root->right) > 0){
            root->right = RightR(root->right);
            return LeftR(root);
        }
    }
    return root;
}

void inOrder(TreeNode* root){
    if(root==NULL){
        return;
    }
    inOrder(root->left);
    printf("%d ",root->data);
    inOrder(root->right);
}

int main() {
    int n;
    printf("Enter the number of nodes: ");
    scanf("%d",&n);
    int nodes[n];
    for (int i = 0; i < n; i++){
        scanf("%d",&nodes[i]);
    }
    TreeNode *root = CreateNode(nodes[0]);
    for(int i = 1 ; i < n ; i++){
        root = Insert(root , nodes[i]);
    }
    inOrder(root);

    return 0;
}
#include <stdio.h>
#include <stdlib.h>
 
struct Node
{
int data;
struct Node *left, *right;
};
// ham cap phat bo nho dong cho nut moi
struct Node* createNewNode(int data)
{
struct Node *nnode = (struct Node*)malloc(sizeof(struct Node));
nnode->data = data;
nnode->left=nnode->right=NULL;
return nnode;
}
/* ham them nut moi la con trai/phai cua nut hien tai
root la nut hien tai
nnode la nut moi
Truong type
-1 : la them vao con trai
+1 : la them vao con phai
 
root, nnode phai khac NULL
root chua co con
*/
void addNewChild(struct Node *root, struct Node *nnode, int type)
{
if(type==-1)
root->left = nnode;
else if((type==1))
root->right = nnode;
}
 
/*Ham tim va tra ve nut co gia tri bang gia tri khoa
*/
struct Node *findKey(struct Node *root,int key)
{
if(root==NULL||root->data==key) return root;
struct Node *fleft = findKey(root->left, key);
if(fleft!=NULL) return fleft;
return findKey(root->right, key);
}
/*
Ham in ra cac nut tren cay theo thu tu truoc
*/
void preorderTravel(struct Node *root)
{
if(root==NULL) return;
printf("%d, ",root->data);
preorderTravel(root->left);
preorderTravel(root->right);
}

void postorderTravel(struct Node *root)
{
if(root==NULL) return;
postorderTravel(root->left);
postorderTravel(root->right);
printf("%d, ",root->data);
}

void duyetmuc(struct Node *root)
{
if(root==NULL) return;
duyetmuc(root->left);
printf("%d, ",root->data);
duyetmuc(root->right);
printf("%d, ",root->data);
}
/*
Ham tao ra cay tu doc tu file
*/
struct Node *createTreeFromFile(const char* filename)
{
FILE *pfile;
struct Node *root = NULL, *left, *right, *aNode;
pfile=fopen(filename,"r");
int rootKey, leftKey, rightKey;
do
{
fscanf(pfile,"%d",&rootKey);
if(rootKey==-2)
{
fclose(pfile);
return root;
}
if(root == NULL)
{
root = createNewNode(rootKey);
aNode = root;
}
else
aNode = findKey(root, rootKey);

fscanf(pfile,"%d %d",&leftKey,&rightKey);
if(leftKey!=-1)
{
left = createNewNode(leftKey);
addNewChild(aNode,left, -1);
} 
if(rightKey!=-1)
{
right = createNewNode(rightKey);
addNewChild(aNode,right,1);
}		
}
while(1);
}
 
int main()
{
const char *filename = "C:\\Users\\ADMIN\\Documents\\C programming\\C co ban\\week11\\binarytree.txt";
struct Node *root = createTreeFromFile(filename);
preorderTravel(root);
printf("\n");
postorderTravel(root);
printf("\n");
duyetmuc(root);
return 0;
}


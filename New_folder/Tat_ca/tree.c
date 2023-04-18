/*
name la ten file/thu muc
*/
struct TNode 
{ 
    char name[255]; 
struct TNode *firstChild, *nextSibling;
}


#include<stdio.h>
#include<stdlib.h>
#include<string.h>
/*
name la ten file/thu muc
*/
struct TNode 
{ 
    char name[255]; 
struct TNode *firstChild, *nextSibling;
}; 
// tham so name chi doc --> khai bao la const
struct TNode *makeNewNode(const char *newName)
{
struct TNode *newNode = (struct TNode *)malloc(sizeof(struct TNode));
strcpy(newNode->name, newName);
newNode->firstChild = newNode->nextSibling = NULL;
return newNode;
}
 
/* them newnode la con cua root
root phai khac NULL
*/
void addNewChild(struct TNode *root, struct TNode *newNode)
{
if(root->firstChild==NULL)
{
root->firstChild = newNode;
}
else
{
struct TNode *preChild = root->firstChild;
while(preChild->nextSibling!=NULL)
preChild=preChild->nextSibling;
preChild->nextSibling = newNode;
}
}
 
struct TNode * createaTree()
{
struct TNode *root = makeNewNode("\\");
struct TNode *aNewChild = makeNewNode("Baitap1");
addNewChild(root,aNewChild);

aNewChild = makeNewNode("Baitap1.c");
addNewChild(root->firstChild,aNewChild);
aNewChild = makeNewNode("Baitap1.exe");
addNewChild(root->firstChild,aNewChild);
aNewChild = makeNewNode("input.txt");
addNewChild(root->firstChild,aNewChild);

aNewChild = makeNewNode("Baitap2");
addNewChild(root,aNewChild);
aNewChild = makeNewNode("Baitap2.c");
addNewChild(root->firstChild->nextSibling,aNewChild);

return root;
}
 
void printCurrentDirectory(struct TNode *root, int currentLevel)
{
if(root==NULL) return;
 
if(currentLevel>0)
{
for(int i=0; i<currentLevel-1; i++) printf("   ");
printf("+->");
}

 
printf("%s\n",root->name);
struct TNode *child = root->firstChild;
while(child!=NULL)
{
printCurrentDirectory(child, currentLevel+1);
child = child->nextSibling;
}
}

 /*ham xoa toan bo cay
phai gan root = NULL sau khi xoa
KHONG duoc dung sau khi da goi ham xoa*/
void removeTree(struct TNode *root)
{
if(root==NULL) return;
struct TNode *child = root->firstChild;
while(child!=NULL)
{
child = child->nextSibling;
removeTree(child);
}
free(root);	
}
/*Tim va tra ve nut chua ten nhu xau mau
Neu khong tim thay thi can tra ve NULL*/
struct TNode *findNode(struct TNode *root, const char *searchKey)
{
if(root==NULL) return NULL;

if(strcmp(root->name,searchKey)==0) return root;
 
struct TNode *child = root->firstChild;
struct TNode *retVal;
while(child!=NULL)
{
retVal = findNode(child, searchKey);
if(retVal!=NULL) return retVal;
child = child->nextSibling;
}
}

int main()
{
struct TNode *root = createaTree();
printCurrentDirectory(root,0);

return 0;
}


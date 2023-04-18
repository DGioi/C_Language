#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct Node{
    char dmy[11], seller[50], buyer[50], id[50], key[100];
    float cost;
    int number;
    struct Node* leftChild;
    struct Node* rightChild;
}Node;
Node* root;

Node* makeNode(char* dmy,char* seller, char* buyer, char* id, int number, float cost){
    Node* p = (Node*)malloc(sizeof(Node));
    strcpy(p->dmy, dmy);
    strcpy(p->seller, seller);
    strcpy(p->buyer, buyer);
    strcpy(p->id, id);
    p->number=number;
    p->cost=cost;

    strcpy(p->key,seller);
    strcat(p->key,"_");
    strcat(p->key,buyer);

    p->leftChild = NULL; p->rightChild = NULL;
    return p;
}

/*Node* insert(Node* r, char* dmy, char* seller, char* buyer, char* id, int number, float cost){
    char str[256];
    if(r == NULL) return makeNode(dmy, seller, buyer, id, number, cost);

    strcpy(str,seller);
    strcat(str,"_");
    strcat(str,buyer);

    if(cost == r->cost){
        if (number == r->number){
            int c=strcmp(r->id,id);
            if(c==0){
                c=strcmp(r->dmy,dmy);
                if(c==0){
                    c=strcmp(r->key,str);
                    if(c==0){
                        r->number+=number;
                        r->cost+=cost;
                        return r;
                    }else if(c < 0){
                        r->rightChild = insert(r->rightChild,dmy, seller, buyer, id, number, cost); return r;
                    }else{
                        r->leftChild = insert(r->leftChild,dmy, seller, buyer, id, number, cost); return r;
                    }
                }else if(c < 0){
                    r->rightChild = insert(r->rightChild,dmy, seller, buyer, id, number, cost); return r;
                }else{
                    r->leftChild = insert(r->leftChild,dmy, seller, buyer, id, number, cost); return r;
                }
            }else if(c < 0){
                r->rightChild = insert(r->rightChild,dmy, seller, buyer, id, number, cost); return r;
            }else{
                r->leftChild = insert(r->leftChild,dmy, seller, buyer, id, number, cost); return r;
            }
        }else if(number > r->number){
            r->rightChild = insert(r->rightChild,dmy, seller, buyer, id, number, cost); return r;
        }else{
            r->leftChild = insert(r->leftChild,dmy, seller, buyer, id, number, cost); return r;
        }
        
        return r;
    }else if(cost > r->cost){
        r->rightChild = insert(r->rightChild,dmy, seller, buyer, id, number, cost); return r;
    }else{
        r->leftChild = insert(r->leftChild,dmy, seller, buyer, id, number, cost); return r;
    }
}*/

int checkCost(float cost){
    if(cost<200) return 1;
    return 0;
}

int checkNumber(int number){
    if(number>0 && number<100) return 1;
    return 0;
}

int compare(float a, float b){
    if(a>b) return 1;
    return 0;
}

void enter(){
    Node tmp;
    int lineno=-1 , line, cntcost=0, cntnumber=0, max=0;
    char s[256];
    do
    {
        scanf(" %s", s); 
        if (strcmp(s,"$")==0)
            break;
        else{

        strcpy(tmp.dmy,s);

        scanf("%s %s %s %d %f", tmp.seller, tmp.buyer, tmp.id, &tmp.number, &tmp.cost);
        lineno++;

        if(tmp.cost>max){
            max=tmp.cost;
            line=lineno;
        }

        if(checkCost(tmp.cost)){
            cntcost++;
        }
        if(checkNumber(tmp.number)){
            cntnumber++;
        }

        }
    }while(1);
    
    printf("%d\n",cntcost);
    printf("%d\n",cntnumber);
    printf("%d\n", line);
}


void freeTree(Node* r){
    if(r == NULL) return;
    freeTree(r->leftChild);
    freeTree(r->rightChild);
    free(r);
}

void inOrder(Node* r){
    if(r == NULL) return;
    inOrder(r->leftChild);
    printf("%s %s %s %s %d %f\n",r->dmy, r->seller, r->buyer, r->id, r->number, r->cost);
    inOrder(r->rightChild);
}

void printList(){
    inOrder(root);
    printf("\n");
}

void main(){
    while(1){
        char cmd[256];
        enter();
    }
        freeTree(root);
    return;
}

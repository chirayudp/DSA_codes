#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int size = 0;
typedef struct node
{
    int a,d;
    int cnt;
    struct node* left;
    struct node* right;    
}node;

node arr[200005];
int idx = 0;

node* create(int a, int d){
    node* new = &arr[idx++];    
    new->a=a; new->d=d; new->cnt=1;
    new->left=new->right=NULL;
    return new;
}
int strengthcmp(int a1,int d1,int a2,int d2){
    if(a1+d1 > a2+d2)return 1 ;
    if(a1+d1 < a2+d2)return 2;
    if(a1>a2)return 1;
    if(a1<a2)return 2;
    return 0;
}
node* insertbst(node* root ,int a , int d){
    node* par=NULL;
    node* cur=root;
    while (cur && strengthcmp(cur->a,cur->d,a,d)!=0)
    {
        par=cur;
        if(strengthcmp(cur->a,cur->d,a,d)==2){
            cur=cur->right;
        }
        else cur=cur->left;
    }
    if (cur!=NULL)
    {
        cur->cnt++;
        return root;
    }
    node* new=create(a,d);
        size++;
    if(par==NULL)return new;
    if(strengthcmp(par->a,par->d,a,d)==1)par->left=new;
    else par->right=new;
    return root;
}
void shift(node** root,node* par,node* des,node* cur){
    if(par == NULL){
        *root = cur;
        return;
    } 
    if(par->left == des)
        par->left = cur;
    else par->right = cur;
}
node* deletebst(node* root ,int a , int d){
    node* par=NULL;
    node* cur=root;
    while (cur && strengthcmp(cur->a,cur->d,a,d)!=0)
    {
        par=cur;
        if(strengthcmp(cur->a,cur->d,a,d)==2){
            cur=cur->right;
        }
        else cur=cur->left;
    }
    if(cur == NULL)return root;
    if (cur->cnt>1)
    {
        cur->cnt--;
        return root;
    }

    if(cur->left==NULL) shift(&root,par,cur,cur->right);
    else if(cur->right==NULL) shift(&root,par,cur,cur->left);
    else {
        node* minpar=cur;
        node* min = cur->right;
        while (min->left)
        {
            minpar=min;
            min = min->left;
        }
        if(minpar == cur) minpar->right = min->right;  
        else minpar->left  = min->right;  

        min->left  = cur->left;
        min->right = cur->right; 
        min->left=cur->left;
        shift(&root, par,cur,min);
    }
    size--;
    return root;
}
int search(node* root,int a,int d){
    node* cur=root;
    while (cur && strengthcmp(cur->a,cur->d,a,d)!=0)
    {
        if(strengthcmp(cur->a,cur->d,a,d)==2){
            cur=cur->right;
        }
        else cur=cur->left;
    }
    if (cur!=NULL)
    {
        return cur->cnt;
    }
    
    return -1;
}
void printbst(node* root){
    if (root==NULL)return ;
    printbst(root->right);
    printf("%d %d %d\n",root->a,root->d,root->cnt);    
    printbst(root->left);
    return ;
}

node* searchweaker(node* root,int a,int d){
    node* best=NULL;

    while(root){
        if(strengthcmp(root->a,root->d,a,d)==2){
            best=root;
            root=root->right;
        }
        else{
            root=root->left;
        }
    }

    return best;
}  

node* searchstronger(node* root,int a,int d){
    node* best=NULL;

    while(root){
        if(strengthcmp(root->a,root->d,a,d)==1){
            best=root;
            root=root->left;
        }
        else{
            root=root->right;
        }
    }

    return best;
}

int main(){
int n;
scanf("%d",&n);
node* root = NULL;

for (int i = 0; i < n; i++)
{
    int a,d;scanf("%d %d",&a,&d);
    root = insertbst(root,a,d);
}

int q;
scanf("%d",&q);
for (int i = 0; i < q; i++)
{
    char str[10];
    scanf("%s",str);
    if(strcmp(str,"TRADE")==0){
        int a1,d1,a2,d2;
        scanf("%d %d %d %d",&a1,&d1,&a2,&d2);
        // printf("ip %d %d\n",a1,d1);
        if (a2==-1 && d2==-1)
        {
            root=insertbst(root,a1,d1);
            printf("1\n");
        }
        else if(search(root,a2,d2)<=1){
            printf("0\n");
        }
        else{
            int x = search(root,a1,d1);
            if(x == -1){
                printf("1\n");
                root = deletebst(root,a2,d2);
                root = insertbst(root,a1,d1);
            }
            else{
                if(strengthcmp(a1,d1,a2,d2)==2){
                    printf("0\n");
                }
                else{
                    printf("1\n");
                    root = deletebst(root,a2,d2);
                    root = insertbst(root,a1,d1);
                }
            }
        }
    }
    else if(strcmp(str,"COMPARE")==0){
        int a,d;scanf("%d %d",&a,&d);
        int cnt=search(root,a,d);
        if (cnt==-1) printf("0\n");
        else printf("%d\n",cnt);
        node* tmp=searchweaker(root,a,d);
        if(tmp == NULL) printf("-1\n");
        else printf("%d %d %d\n",tmp->a,tmp->d,tmp->cnt);
        tmp=searchstronger(root,a,d);
        if(tmp == NULL) printf("-1\n");
        else printf("%d %d %d\n",tmp->a,tmp->d,tmp->cnt);
        
    }
    // printf("i:%d s%d\n",i,size);
    // printbst(root);

}
printf("%d\n",size);
printbst(root);
}

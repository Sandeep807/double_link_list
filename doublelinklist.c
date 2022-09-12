#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *root=NULL;

void append();
void addBegin();
void display();
void search();
void deletedBegin();
void deleted();
int length();
int len;
int main(){
    int ch;
    while (1)
    {
        printf("\n1.Append\n");
        printf("2.addatbegin\n");
        printf("3.addafter\n");
        printf("4.length\n");
        printf("5.Display\n");
        printf("6.Search\n");
        printf("7.Delete Begin\n");
        printf("8.Delete\n");
        printf("9.Exit\n");
        printf("Enter your choice : \n");
        scanf("%d",&ch);
        switch (ch)
        {
        case 1:
            append();
            break;
        case 2:
            addBegin();
            break;
        case 4:
            len=length();
            printf("%d",len);
            break;
        case 5:
            display();
            break;
        case 6:
            search();
            break;
        case 7:
            deletedBegin();
            break;
        case 8:
            deleted();
            break;
        case 9:
            exit(0);
            break;
        default:
            break;
        }
    }
    
    
}

void append(){
    struct node *temp;
    temp=(struct node*)malloc(sizeof(struct node));
    printf("Enter data: \n");
    scanf("%d",&temp->data);
    temp->left=NULL;
    temp->right=NULL;
    if (root==NULL)
    {
        root=temp;
    }
    else
    {
        struct node *p;
        p=root;
        while (p->right!= NULL)
        {
            p=p->right;
        }
        p->right=temp;
        temp->left=p;
        
    }
    printf("Inserted data: %d\n",temp->data);
    
}

void addBegin(){
    struct node *temp;
    temp = (struct node*)malloc(sizeof(struct node));
    printf("Enter data: \n");
    scanf("%d",&temp->data);
    temp->left=NULL;
    temp->right=NULL;
    if (root==NULL)
    {
        root=temp;
    }
    else
    {
        temp->right=root;
        root->left=temp;
        root=temp;
    }
    
}

int length()
{
    struct node *temp;
    temp=root;
    int count=0;
    if (root==NULL)
    {
        printf("List is empty");
    }
    else
    {
        while (temp!=NULL)
        {
            count++;
            temp = temp->right;
        }
        return count;
        
    }
    
}



void display(){
    struct node *temp=root;
    if (temp==NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        while (temp!=NULL)
        {
            printf("%d-->",temp->data);
            temp=temp->right;
        }
        
    }
    
}

void search()
{
    struct node *temp=root;
    int n,flag=0;
    if (root==NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        printf("Enter data: \n");
        scanf("%d",&n);
        while (temp!=NULL)
        {
            if(temp->data==n)
            {
                flag=1;
                break;
            }
            temp = temp->right;
        }
        if (flag!=0)
        {
            printf("Found element: %d",temp->data);
        }
        else
        {
            printf("Not found element\n");
        }
        
    }
    
}

void deletedBegin()
{
    struct node *temp;
    if (root==NULL)
    {
        printf("List is empty");
    }
    else
    {
        temp=root;
        root=temp->right;
        temp->left=NULL;
        free(temp);
        
    }
    
}

void deleted()
{
    struct node *temp,*p;
    if (root==NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        int n,flag=0;
        temp = root;
        printf("Enter element for delete: \n");
        scanf("%d",&n);
        while (temp->data!=n)
        {
            if (temp->right==NULL)
            {
                printf("Can not deleted\n");
            }
            else if (temp->right->right==NULL)
            {
                temp->right=NULL;
                printf("Node deleted\n");
            }
            else
            {
                p=temp->right;
                temp->right=p->right;
                p->right->left=temp;
                free(p);
                printf("Node Deleted\n");

            }
            
            
            temp=temp->right;
        }
        
    }
    
}
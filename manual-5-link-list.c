#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<stdbool.h>

struct Node
{
    int data;
    struct Node *next;
} *head=NULL;


void insertAtBeginning( int value)
{
    struct Node *newNode;

    newNode=(struct Node*) malloc(sizeof(struct Node));
    newNode->data=value;

    if(head == NULL)
    {
        newNode->next=NULL;
        head=newNode;
    }
    else
    {
        newNode->next=head;
        head=newNode;
    }

    printf("\n One node inserted at beginning !!\n");
}

void insertAtEnd(int value)
{
    struct Node *newNode;
    newNode=(struct Node*) malloc(sizeof(struct Node));
    newNode->data=value;
    newNode->next=NULL;

    if(head == NULL)
    {
        head=newNode;
    }
    else
    {
        struct Node *temp=head;

        while(temp->next != NULL)
        {
            temp=temp->next;
        }
        temp->next=newNode;
    }

    printf("\n One node inserted at end !!\n");
}

void insertAtAnyPosition(int value, int loc1)
{
    struct Node *newNode;
    newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=value;
    if(head == NULL)
    {
        newNode->next=NULL;
        head=newNode;
    }
    else
    {
        struct Node *temp=head;
        for(int i=0; i<loc1; i++)
        {
            temp=temp->next;

        }
        newNode->next=temp->next;
        temp->next=newNode;
    }
    printf("\n One node inserted at position %d !!\n",loc1);
}

void deleteAtBeginning()
{
    if(head==NULL)
        printf("List is empty! \n");
    else
    {
        struct Node *temp=head;
        head=temp->next;
        free(temp);
        printf(" 1 node deleted! \n");
    }
}

void deleteAtEnd()
{
    if(head==NULL)
        printf("List is empty! \n");
    else if(head->next == NULL)
    {
        head=NULL;
        free(head);
        printf(" 1 node deleted! \n");
    }
    else
    {
        struct Node *temp=head,*temp1;
        while(temp->next != NULL)
        {
            temp1=temp;
            temp=temp->next;
        }
        temp1->next=NULL;
        free(temp);
        printf(" 1 node deleted! \n");
    }
}

void deleteAtAnyPosition(int loc2)
{
    if(head == NULL)
        printf("Can't possible\n");

    struct Node *temp=head,*temp1;

    for(int i=0; i<loc2; i++)
    {
        temp1=temp;
        temp=temp->next;
    }
    temp1->next=temp->next;
    free(temp);
    printf(" 1 node deleted! \n");
}

void display()
{
    if(head == NULL)
    {
        printf("\n List is empty !!");
    }
    else
    {
        struct Node *temp=head;

        printf("\n\nList elements are: \n");

        while(temp->next != NULL)
        {
            printf("%d --->",temp->data);
            temp=temp->next;
        }
        printf("%d --->NULL\n",temp->data);
    }
}

bool search()
{
    int item;
    printf("Enter searching value: ");
    scanf("%d",&item);

    if(head == NULL)
        printf("List is empty\n");
    else
    {
        struct Node *temp=head;
        while(temp != NULL)
        {
            if(temp->data==item)
                return true;
            temp=temp->next;
        }
        return false;
    }
}

int count()
{
    int count=0;

    if(head == NULL)
    {
        return 0;
    }
    else
    {
        struct Node *temp=head;

        while(temp->next != NULL)
        {
            count++;
            temp=temp->next;
        }
    }
    return count+1;
}

int main()
{
    int choice,value,choice1,choice2,loc1,loc2;

    while(1)
    {
        printf("\n ----- MENU ------");
        printf("\n 1. Insert");
        printf("\n 2. Delete");
        printf("\n 3. Display");
        printf("\n 4. Search");
        printf("\n 5. Count");
        printf("\n 6. Exit");

        printf("\nEnter your choice: ");
        scanf("%d",&choice);

        switch(choice)
        {
        case 1:
            printf("Insert value: ");
            scanf("%d",&value);
            while(1)
            {
mainMenu:

                printf("\n -- Where you want to insert --");
                printf("\n 1. Insert at began");
                printf("\n 2. Insert at end");
                printf("\n 3. Insert at any position");

                printf("\n Enter your choice: ");
                scanf("%d",&choice1);

                switch(choice1)
                {
                case 1:
                    insertAtBeginning(value);
                    break;
                case 2:
                    insertAtEnd(value);
                    break;
                case 3:
                    printf("Location which you want to add: ");
                    scanf("%d",&loc1);
                    insertAtAnyPosition(value,loc1);
                    break;
                default:
                    printf("\n Invalid choice");
                    goto mainMenu;
                }
                goto subMenuEnd;
            }
subMenuEnd:
            break;
        case 2:
            while(1)
            {
mainMenu1:

                printf("\n -- Where you want to Delete --");
                printf("\n 1. Delete at began");
                printf("\n 2. Delete at end");
                printf("\n 3. Delete at any position");

                printf("\n Enter your choice: ");
                scanf("%d",&choice2);

                switch(choice2)
                {
                case 1:
                    deleteAtBeginning();
                    break;
                case 2:
                    deleteAtEnd();
                    break;
                case 3:
                    printf("Location which you want to delete: ");
                    scanf("%d",&loc2);
                    deleteAtAnyPosition(loc2);
                    break;
                default:
                    printf("\n Invalid choice");
                    goto mainMenu1;
                }
                goto subMenuEnd1;
            }
subMenuEnd1:
            break;
        case 3:
            display();
            break;
        case 4:
            search()? printf(" Item found \n") : printf(" Item Not found \n");
            break;
        case 5:
            printf("\nTotal nodes= %d\n",count());
            break;
        case 6:
            exit(0);
            break;
        default:
            printf("\n Invalid choice");
            break;
        }
    }


    return 0;
}

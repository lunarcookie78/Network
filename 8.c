#include<stdio.h>
int MAX=4, count;
struct emp
    {
int ssn;
char name[20];
char dept[10];
char desig[15];
int sal;
char phno[10];
struct emp *left;
struct emp *right;
    };
 typedef struct emp NODE;

int countnodes(NODE *head)
    {
         NODE *p;
         count=0;
         p=head;
         while(p!=NULL)
            {
              p=p->right;
              count++;
            }
      return count;
   }

NODE* getnode(NODE *head)
   {
NODE *newnode;
newnode=(NODE*)malloc(sizeof(NODE));
newnode->right=newnode->left=NULL;
printf("\nEnter SSN, Name, Dept, Designation, Sal,Ph.No\n");
scanf("%d",&newnode->ssn);
flushall();
gets(newnode->name);
flushall();
gets(newnode->dept);
flushall();
gets(newnode->desig);
scanf("%d",&newnode->sal);
flushall();
gets(newnode->phno);
head=newnode;
return head;
    }

NODE* display(NODE *head)
    {
        NODE *p;
        if(head==NULL)
        printf("\nNo Employee data\n");
        else
     {
 p=head;
 printf("\n----EMPLOYEE DATA----\n");
 printf("\nSSN\tNAME\tDEPT\tDESINGATION\tSAL\t\tPh.NO.");
 while(p!=NULL)
     { 
            printf("\n%d\t%s\t%s\t%s\t\t%d\t\t%s", p->ssn, p->name, p->dept, p->desig,
            p- >sal, p->phno);
            p = p->right;	//Go to next node...
      }
            printf("\nThe no. of nodes in list is: %d", countnodes(head));
      }
            return head;
      }

NODE* create(NODE *head)	   // creating & inserting at end.
     {
       NODE *p, *newnode;
       p=head;
       if(head==NULL)
    {
       newnode=getnode(head);
       head=newnode;
     }
         else
    {
       newnode=getnode(head);
          while(p->right!=NULL)
    {
          p=p->right;
     }
          p->right=newnode;
          newnode->left=p;
     }
          return head;
    }
NODE* insert_end(NODE *head)
    {
if(countnodes(head)==MAX)
printf("\nList is Full!!");
else
head=create(head);
return head;
    }

NODE* insert_front(NODE *head)
   {
NODE *p, *newnode;
if(countnodes(head)==MAX)
printf("\nList is Full!!");
else
              {
                  if(head==NULL)
                     {
            newnode=getnode(head);
            head=newnode;	//set first node to be head
                     }
                  else
                     {
           newnode=getnode(head);
           newnode->right=head;
           head->left=newnode;
           head=newnode;
                     }
                   }
return head;
   }

NODE* insert(NODE *head)
    {
       int ch;
      do
    {
printf("\n 1.Insert at Front(First) \t 2.Insert at End(Rear/Last)\t3.Exit");
printf("\nEnter your choice: ");
scanf("%d", &ch);
switch(ch)
   {
     case 1: head=insert_front(head); break;
     case 2: head=insert_end(head); break;
     case 3: break;
   }
head=display(head);
   } while(ch!=3);
return head;
    }
NODE* delete_front(NODE *head)
    {
NODE *p;
if(head==NULL)
printf("\nList is Empty (QUEUE)");
else
             {
     p=head;
     head=head->right;
     head->right->left=NULL;
     free(p);
     printf("\nFront(first)node is deleted");
             }
         return head;
    }

NODE* delete_end(NODE *head)
     {
NODE *p, *q;
q=NULL;
p=head;
            while(p->right!=NULL)
                {
        q=p;
        p=p->right;	//Go upto -1 node which you want to delete
                }
q->right=NULL;
free(p);		//Delete last node...
printf("\nLast(end) entry is deleted");
return head;
     }
NODE *del(NODE *head)
 {
    int ch;
   do
 {
   printf("\n1.Delete from Front(First)\t2. Delete from End(Rear/Last))\t3.Exit");
   printf("\nEnter your choice: ");
   scanf("%d", &ch);
   switch(ch)
  {
     case 1: head=delete_front(head); break;
     case 2: head=delete_end(head); break;
     case 3: break;
   }
     head=display(head);
   }while(ch!=3);
        return head;
   }
NODE* dqueue(NODE *head)
     {
 int ch;
do
              {
       printf("\n DLL used as Double Ended Queue");
       printf("\n 1. Insert at Rear \n 
       2. Delete from Front\n 
       3.Insert at Front \n
       4.Delete from Rear\n 
       5.display\n 
       6. exit");
                   printf("\nEnter your choice: ");
                   scanf("%d", &ch);
                   switch(ch)
                     {
             case 1: head=insert_end(head); break;
             case 2: head=delete_front(head); break;
             case 3: head=insert_front(head); break;
             case 4: head=delete_end(head); break;
             case 5: head=display(head);break;
             case 6: break;
                      }
           }while(ch!=6);
             return head;
      }

void main()
    {
int ch, i, n;
NODE *head;
head=NULL;
printf("\n----------Employee Database-----------");
do
             {
    printf("\n1.Create\t2.Display\t3.Insert\t4.Delete\t5.Queue\t6.Exit");
    printf("\nEnter your choice: ");
    scanf("%d",&ch);
    switch(ch)
                   {
            case 1: printf("\nHow many employees data you want to create: ");
            scanf("%d", &n);
            for(i=0;i<n;i++)
            head=create(head);       //Call to Create node...
            break;
            case 2: head=display(head);	//Call to Display...
            break;
            case 3: head=insert(head);	//Call to Insert...
            break;
           case 4: head=del(head);                        //Call to delete
                       break;
           case 5: head=dqueue(head);
                       break;
           case 6: exit(0);	//Exit...
                       break;
                  }
         }while(ch!=6);
}
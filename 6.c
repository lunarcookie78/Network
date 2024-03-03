#include<stdio.h>
#define MAX 4
int ch, front = 0, rear = -1, count=0, q[MAX], item;
void insert(int item, int *rear, int *q, int *count)
           {
if(*count == MAX)
printf("Circular Queue is Full\n");
else
           {
*rear = (*rear + 1) % MAX;
q[*rear]=item;
(*count)++;
            }
        }

void del(int *front, int *q, int *count)
          {
if(*count == 0)
printf("Circular Queue is underflow\n");
else
            {
item=q[*front];
printf("\nDeleted item is: %d",item);
*front = (*front + 1) % MAX;
(*count)--;
           }
        }

void display(int front, int q[], int count)
          {
int i;
if(count == 0)
printf("\nCircular Queue is Empty");
else
           {
printf("\nContents of Circualr Queue is:\n");
for(i=1; i<=count; i++)
          {
printf("%d\t", q[front]);
front = (front + 1) % MAX;
          }
      }
 }

void main()
     {
       do
     {
printf("\n1. Insert\n2. Delete\n3. Display\n4. Exit");
printf("\nEnter the choice: ");
scanf("%d", &ch);
switch(ch)
           {
case 1: printf("\nEnter the item to be inserted: ");
scanf("%d", &item);
insert(item, &rear, q, &count);
break;
case 2: del(&front, q, &count);
break;
case 3: display(front, q, count);
break;
case 4: exit(0);
break;
            }
   }while(ch!=4);
}
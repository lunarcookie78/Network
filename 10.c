#include<stdio.h>
#include<stdlib.h>
 struct node
      {
int info;
struct node *llink;
struct node *rlink;
       };
typedef struct node NODE;
NODE *insert(int item,NODE *root)
     {
NODE *temp,*cur,*prev;
temp=(NODE *)malloc(sizeof(NODE));
temp->info=item;
temp->llink=NULL;
temp->rlink=NULL;
if(root==NULL)
return temp;
prev=NULL;
cur=root;
           while(cur!=NULL)
             {
     prev=cur;
     cur=(item<=cur->info)?cur->llink:cur->rlink;
              }
      if(item<prev->info)
      prev->llink=temp;
      else
      prev->rlink=temp;
      return root;
        }

NODE *construct_BST(NODE *root)
     {
int a,n,i;
printf("Enter the number of elements\n");
scanf("%d",&n);
printf("Enter the elements to be inserted in the tree\n");
for (i=0;i<n;i++)
             {
                 scanf("%d",&a);
                 root=insert(a,root);
             }
                 printf("Tree Constructed Successfully!!!!!!\n");
                 return root;
       }

void preorder(NODE *root)
   {
if(root!=NULL)
            {
    printf("%d\t",root->info);
    preorder(root->llink);
    preorder(root->rlink);
           }
    }

void inorder(NODE *root)
    {
if(root!=NULL)
              {
      inorder(root->llink);
      printf("%d\t",root->info);
      inorder(root->rlink);
               }
      }

void postorder(NODE *root)
      {
           if(root!=NULL)
               {
        postorder(root->llink);
        postorder(root->rlink);
        printf("%d\t",root->info);
                }
         }

int search_element(NODE *root,int key)
     {
NODE *cur;
int n=0;
cur=root;
if (cur!=NULL)
              {
      if (key==cur->info)
      n=1;
      else if (key<cur->info)
      return search_element(cur->llink,key);
      else
      return search_element(cur->rlink,key);
              }
               else
               return n;
       }
void main()
        {
      int item,ch,key,n;
      NODE *root;
      root=NULL;
      while (1)
                    {
                      printf(" 1.Construct BST\n
          2.Preorder\n
          3.Inorder\n
          4.Postorder\n
          5.Search an Element\n
          6:Exit\n");
                      printf("\nEnter the choice\n");
                      scanf("%d",&ch);
                      switch(ch)
                        {
                              case 1: root=construct_BST(root);
                                          break;
                              case 2: preorder(root);
                                          break;
                              case 3: inorder(root);
                                          break;
                               case 4: postorder(root);
                                           break;
                               case 5: if (root==NULL)
                                           printf("List Empty\n");
                                           else
                                              {
                                          printf("Enter the element\n");
                                          scanf("%d",&key);
                                          n=search_element(root,key);
                                          if(n)
                                          printf("Key found\n");
                                          else
                                          printf("Not found\n");
                                               }
                               break;
                             case 6: exit(0);
                 default: printf("Wrong Choice\n");
                                }
                       }
               }
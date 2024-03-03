#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define HASH_SIZE 100

typedef struct employee
         {
	int  id;
	char name[20];
         }EMPLOYEE;

/Create initial hash table/

void initialize_hash_table(EMPLOYEE a[])
     {
	int i;
	for(i=0; i<HASH_SIZE; i++)
              {
	    a[i].id=0;
	  }
     }

/Compute hash value using the function: H(K)=k%m/

int H(int k)
      {
	return k % HASH_SIZE;
      }


/Insert an item into the empty slot using linear probing/

void insert_hash_table(int id, char name[], EMPLOYEE a[])
   {
	int	i,index,h_value;
	h_value= H(id);
	for(i=0; i<HASH_SIZE; i++)
	    {
		index=(h_value+i)% HASH_SIZE;
		if(a[index].id==0)		//empty slot found
		  {
			a[index].id=id;		//insert employee id
			strcpy(a[index].name,name);	//insert employee name
			break;
		}
	}
	if(i==HASH_SIZE) printf("Hash table full\n"); // NO empty slot
}


/Display the hash table/
void display_hash_table(EMPLOYEE a[], int n)
  {
	int 	k,i;
	printf("H_Value\t Emp_id\t Emp_name\n");
	for(i=0; i<n; i++)
	{
		if(a[i].id!=0)
printf("%d\t %d\t %s\n",i,a[i].id,a[i].name);
	}
  }

void main()
 {
	EMPLOYEE a[HASH_SIZE];
	char	name[20];
	int	key,id,choice,flag;
	initialize_hash_table(a);	//Create intial hash table
	while(1)
	   {
		printf("1:Insert 2:Display 3:Exit\n");
		printf("Enter the choice:");
		scanf("%d",&choice);
		switch(choice)
		  {
			case 1:printf("Enter emp id:");
				scanf("%d",&id);
				printf("Enter the name:");
				scanf("%s",name);
				insert_hash_table(id,name,a);
				break;
			case 2: printf("Contents of hash table\n");
				display_hash_table(a,HASH_SIZE);
				printf("\n");
				break;
			case 3: exit(0);
			default: printf("Invalid choice\n");
		}
	}
}
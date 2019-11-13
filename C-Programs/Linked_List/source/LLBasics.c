#include <stdio.h>
#include <stdlib.h>
#include "../headers/struct.h"

//int add(struct node **, int, int, int);
//int delete(struct node **, int, int);
//int display(struct node **, int);

int LLBasics() {
	int count_of_links;
	int choice, position = 0, value;
	struct node *current_link;
	
	printf("Enter the number of links you want to feed.\n");		//taking user input for number of link
	scanf("%d",&count_of_links);
	
	struct node *points[count_of_links];	//array for pointers to point to count_of_links
	struct node *root;						//root link to start off with
	
	for(int i=0;i<count_of_links;i++)					//allocating memory for every link irrespective of whether its being used
	{
		points[i] = (struct node *)malloc(sizeof(struct node));
	}

	for(int i=0;i<=count_of_links-1;i++)
	{
		printf("Enter the value to be stored in link-%d : ", i);
		scanf("%d",&points[i]->data);
		points[i]->link = points[i+1];
	}
	points[count_of_links - 1]->link = NULL;			//pointing the last link to NULL

	current_link = points[0];
	//display(&current_link, count_of_links);
	
	while(current_link->link != NULL)
	{
		printf("Data field has %d\n", current_link->data);
		current_link = current_link->link;
	}
	printf("Data field has %d\n", current_link->data); 			//print the last data field
	
here:	while(1)
	{
		printf("Enter 1 to 'Delete' item.\nEnter 2 to 'Add' item.\nEnter 3 to 'exit'.\n");
		scanf("%d",&choice);
		if(choice==1)
		{
			printf("Enter the position of link to be removed.\n");
			scanf("%d", &position);
			if(position > count_of_links)
			{
				printf("Enter a value within the range of links.\n\n");
				goto here;
			}
			//delete(&points[0], count_of_links, position);
			count_of_links--;
			points[position-1]->link=points[position+1];
			free(points[position]);
		}
		
		else if(choice == 2)
		{			
			printf("Enter the position of link and value to be stored in data.\n");
			scanf("%d %d", &position, &value);
			if(position > count_of_links)
			{
				printf("Enter a value within the range of links.\n");
				goto here;
			}
			//add(&points[0], count_of_links, position, value);
			count_of_links++;
			points[count_of_links]=(struct node *)malloc(sizeof(struct node));
			points[count_of_links]->link = points[position];
			points[position-1]->link=points[count_of_links];
			points[count_of_links]->data=value;
		}
				
		else if(choice == 3)
		{
			return 0;
		}
				
		else
		{
			printf("Invalid Input.\n");
			goto here;	
		}
		current_link = points[0];
		//display(&current_link, count_of_links);
		
		while(current_link->link != NULL)
		{
			printf("Data field has %d\n", current_link->data);
			current_link = current_link->link;
		}
		printf("Data field has %d\n\n", current_link->data); 			//print the last data field
		return 0;
	}
}
/*
int add(struct node *arr, int count_of_links, int pos, int val)
{
	for(int i = 0; i<pos; i++)
	{
		printf("Hello World");
	}
	count_of_links++;
	
	printf("%d",arr->data);
	return 0;
}

int delete(struct node *current_link, int count_of_links, int pos)
{
	current_link[pos-1]->link=current_link[pos+1];
	count_of_links--;
	//display(&arr[0], count_of_links);
	while(current_link->link != NULL)
	{
		printf("Data field has %d\n", current_link->data);
		current_link = current_link->link;
	}
	printf("Data field has %d\n", current_link->data); 			//print the last data field
}

int display(struct node *current_link, int count_of_links)
{
	while(current_link->link != NULL)
	{
		printf("Data field has %d\n", current_link->data);
		current_link = current_link->link;
	}
	printf("Data field has %d\n", current_link->data); 			//print the last data field
}
*/

int main()
{
	LLBasics();
	return 0;
}

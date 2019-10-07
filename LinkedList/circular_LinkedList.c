#include<stdio.h>
#include<stdlib.h>
//base for individual nodes
struct node{
	int data;
	struct node* link;
} *start;
//function to create new node
void addNode(int data){
	struct node* new;
	//creating a new node
	new = malloc(sizeof(struct node));
	//condition for checking the existence of previous linkedlist
	if(start == NULL)
		start = new;
	new -> data = data;
	new -> link = start;
	//creating a dummy for list traversal
	struct node *q = start;
	//traversing the previously stored linked list
	while(q -> link != start)
		q = q -> link;
	//positioning the new node
	q -> link = new;
}

void display(){
	struct node *itr = start;
	if(start != NULL){
		while(itr -> link != start){
			printf("%d ", itr -> data );
			itr = itr -> link;
		}
		printf("%d", itr -> data );
	}else{
		printf("Nothing to DISPLAY !!\n");
	}
	printf("\n");
}
int main(int argc, char const *argv[]){
	start = NULL;
	int n = 0, data = 0;
	printf("Enter the initial number of elements in the linked list:");
	scanf("%d", &n);
	
	for (int i = 0; i < n; ++i){
		printf("Enter the value %d:", i + 1);
		scanf("%d", &data);
		addNode(data);
	}
	display();
	return 0;
}

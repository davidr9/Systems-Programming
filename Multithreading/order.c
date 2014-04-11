#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>

typedef struct qNode{
	char* bookTitle;
	int customerID;
	char* category;
	struct qNode *next;
}qNode, *qNodePtr;

typedef struct Queue{
	qNodePtr head;
	qNodePtr tail;
}Queue, QueuePtr;

qNodePtr enqueue(Queue q, qNodePtr newNode)
{
	if (q->head == NULL){
		q->head = newNode;
		q->tail = newNode;
		return q->head;
	}
	
	q->tail->next = newNode;
	q->tail = newNode;
	return q->head;
}

qNodePtr dequeue(Queue q)
{
	qNodePtr temp = q->head;
	q->head = q->head->next;
	return temp;
}

/*makes a data structure based on the database.txt*/
void createDatabase(char* database){
	FILE* dbase;
	
	dbase = fopen(database, "r");
	int size = 0;
	char* input;
	int lineNum = 0;

	if(dbase == NULL)
	{
		printf("database file does not exist\n");
		exit(-1);
	}

	int c;
	
	if (fgetc(dbase) == EOF){
		printf("database file is empty\n");
		exit(-1);
	}
	rewind(dbase);
	
	/*counts the number of lines in the database.txt*/
	do{
		c = fgetc(dbase);
		if(c == '\n')
		{
			lineNum++;
		}
	}while(c != EOF);
	
	printf("%d\n", lineNum); 	
	
	qNode db[lineNum];

	rewind(dbase);
	char* in;
	char line[1000];	

	while(in = fgets(line, 1000, dbase))
	{
	
	if(in == NULL)
		{
			break;
		}

		printf("%s\n", in);
	}	
		
}

int main(int argc, char** argv)
{

	if(argc < 4)
	{
		printf("Too few arguements\n");
		return 0;
	}

	if(argc > 4)
	{
		printf("Too many arguements\n");
		return 0;
	}

	char* database = argv[1];
	char* order = argv[2];
	char* categories = argv[3];
	
	if(database == NULL || order == NULL || categories == NULL){
		printf("argument is null\n");
		return 0;
	}
	createDatabase(database);	

	return 0;
}


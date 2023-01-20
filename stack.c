
#include <stdio.h>
#include <string.h>

#define MAXPOS 5
#define EMPTY  -1


struct Stack
{
	int stackVect[MAXPOS];
	int pPosition;
};

typedef struct Stack Stack;

void setup(Stack *stck)
{
	stck->pPosition = -1;
}
int isEmpty(int pStck)
{
	if(pStck==EMPTY)
	{
		return 1;
	}else{
		return 0;
	}	
}

int isFull(int pStck)
{
	if(pStck==MAXPOS)
	{
		return 1;
	}else{
		return 0;
	}
}

int popFunc(Stack *stck)
{
	if(!isEmpty(stck->pPosition))
	{
		int data = stck->stackVect[stck->pPosition];
		stck->pPosition--;
		return data;
	}else{
		printf("Stack is Empty!\n");
		return 0;
	}
}

void pushFunc(Stack *stck, int data)
{
	if(!isFull(stck->pPosition))
	{	
		stck->pPosition++;
		stck->stackVect[stck->pPosition]=data;
		printf("%d data was pushed! \n", data);
	}else{
		printf("Stack is Empty!\n");
	}
}

int main(void)
{
	Stack stack;
	Stack *pStack = &stack;

	char  input[] = {'\0','\0','\0','\0','\0','\0'};	
	char  end[]   = "exit";
	char  comand[sizeof(input)];
	int   data;
	
	setup(&stack);
	do{
		scanf("%s", input);
		strcpy(comand, input);
		data = atoi(input[4]);

		if(!strcmp("pop", comand))
		{	
			int aux = popFunc(&stack);
			if(!aux)
			{
				printf("pop: %d\n",aux);
			}
		}
		else if(strcmp("push", comand))
		{
			pushFunc(&stack,data);
		}else
		{
			printf("Comand not found!\nTry: push or pop\n");
		}
	}while(strcmp(end,comand));			
	return 0;
}
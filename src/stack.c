
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXPOS  10
#define EMPTY  -1


struct Stack{
	int stackVect[MAXPOS];
	int position;
};

typedef struct Stack Stack;

void setup(Stack *stack){
	stack->position = EMPTY;
}

int isEmpty(int stackPosition){
	if(stackPosition==EMPTY){
		return 1;
	}else{
		return 0;
	}	
}

void popFunc(Stack *stack){
	if(!isEmpty(stack->position)){
		int data = stack->stackVect[stack->position];
		printf("%d data was poped!\n",data);
		stack->position--;
		
	}else{
		printf("Stack is Empty!\n");
		stack->position=-1;
		
	}
}

int isFull(int stackPosition){
	if(stackPosition<MAXPOS){
		return 0;
	}else{
		return 1;
	}
}

void pushFunc(Stack *stack, int data)
{
	stack->position++;
	if(!isFull(stack->position))
	{	
		stack->stackVect[stack->position]=data;
		printf("%d data was pushed! \n", data);
	}else{
		printf("Stack is Full!\n");
		stack->position=MAXPOS-1;
	}
}

void fShow(Stack *stack){
	printf("Stack top: [ ");
	for(int i=stack->position; i>=0; i--){
		printf("%d ",stack->stackVect[i]);
	}
	printf("] Stack end \n");

}

int main(void)
{
	Stack stack;

	char  input[] = {'\0','\0','\0','\0','\0','\0'};
	char  comand[4] = {'\0','\0','\0','\0'};
	char  end[]   = "exit";
	int   data = 0;
	int  endProgram = 0;

	printf(	"Begin of the Stack \n");
	setup(&stack);
	do{
		input[0] ='\0';
		comand[0] = '\0';
		fscanf(stdin,"%s",input);

		strcpy(comand, input);
		comand[4] = '\0';		
		
		if(!strcmp("pop",comand)){	
			
			printf("Pop comand\n");
			popFunc(&stack);

		}else if(!strcmp("push",comand)){
			
 			printf("Push comand!\n");
			data = -('0' - input[4] );
			pushFunc(&stack,data);
			data = 0;
			
		}else if(!strcmp("show",comand)){
		
			fShow(&stack);
		
		}else if(!strcmp(end,comand)){
		
			printf("Exit comand!\n");
			endProgram = 1;
		
		}else{
			printf("Comand not found!\nTry: push or pop\n");
		}
		
	}while(!endProgram);
	return 0;
}
#include <stdio.h>
#include <stdlib.h>
#define MAX_LENGTH 100
struct node{
	char x;
	struct node* next;
};
typedef struct node node;
char** extractWords(char sentence[], int* wordCount) {
    char** words = NULL;
    int i = 0;
    int wordIndex = 0;

    while (sentence[i] != '\0')
    {
        while (sentence[i] == ' ')
        {
            i++;
        }
        if (sentence[i] == '\0')
        {
            break;
        }
        int start = i;
        while (sentence[i] != ' ' && sentence[i] != '\0')
        {
            i++;
        }
        int wordLength = i - start;
        words = realloc(words, (wordIndex + 1) * sizeof(char*));
        words[wordIndex] = malloc((wordLength + 1) * sizeof(char));

        for (int j = 0; j < wordLength; j++) {
            words[wordIndex][j] = sentence[start + j];
        }
        words[wordIndex][wordLength] = '\0';

        wordIndex++;
    }

    *wordCount = wordIndex;
    return words;
}

node* reverse(node* head)
{
    node* current=head;
    node* back=NULL;
    node* next=NULL;
    while(current!=NULL)
    {
      next=current->next;
      current->next=back;
      back=current;
      current=next;
    }
    head=back;
    return head;
}
void print(node* head)
{
    while(head!=NULL)
	{
		printf("%c",head->x);
		head=head->next;
	}
    printf(" ");
}
/*Use this to create and reverse a doubly linked list
//create_d copies contents from a singly linked list which stores each character of the word as nodes
//hence create_d creates a doubly linked list each of nodes are characters 
node * create_d (NODE* h) 
 { 
 NODE* tmp=h;
node * head = malloc (sizeof (node));
  
node * tmp1 = malloc (sizeof (node));
  
tmp1 = head;
tmp1->prev=NULL;
while(tmp->info!=' ')
	
{
tmp1->info=tmp->info;
tmp=tmp->next;
	  
node * tmp2 = malloc (sizeof (node));

tmp1->next = tmp2;
	  
tmp2->prev = tmp1;
	  
tmp1 = tmp2;
	
} 

return head;

}
//reverse_d reverses the doubly linked list
void reverse_d(node* h)
{
 node* tmp=h;
 while(tmp->next!=NULL)
 tmp=tmp->next;
 while(tmp->prev!=NULL)
 {
 printf("%c",tmp->prev->info);
 tmp=tmp->prev;
 }
 }
 */
int main()
{
    char sentence[MAX_LENGTH];

    printf("Enter a sentence: ");
    fgets(sentence, MAX_LENGTH, stdin);
    int wordCount;
    char* wd;
    char** words = extractWords(sentence, &wordCount);
	for (int i = 0; i < wordCount; i++)
	{
		int j=0;
		node * head = malloc (sizeof (node));
        node * tmp1 = malloc (sizeof (node));
        tmp1 = head;
        while(words[i][j]!='\0')
		{
         
		   tmp1->x=words[i][j];
	       node * tmp2 = malloc (sizeof (node));
	       tmp1->next = tmp2;
	       tmp1 = tmp2;
           j++;
	    }
        node* r=reverse(head);  
		print(r);
        //printf(" ");
		free(head);
	    free(tmp1);
    
    }
}
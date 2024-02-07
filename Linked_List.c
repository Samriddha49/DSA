#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
struct Node 
{
  
int info;
   
struct Node *next;
 
};

typedef struct Node NODE;

struct dNode 
{
  
int info;
   
struct dNode *prev;
   
struct dNode *next;
 
};

typedef struct dNode node;

NODE * create (int n) 
 { 
NODE * head = malloc (sizeof (NODE));
  
NODE * tmp1 = malloc (sizeof (NODE));
  
tmp1 = head;
  
for (int i = 0; i < n; i++)
	
	{
	  
printf ("Enter value of %dth element\n", i);
	  
scanf ("%d", &tmp1->info);
	  
NODE * tmp2 = malloc (sizeof (NODE));
	  
tmp1->next = tmp2;
	  
tmp1 = tmp2;
	
}
  
return head;

}

node * create_d (int n) 
 { 
node * head = malloc (sizeof (node));
  
node * tmp1 = malloc (sizeof (node));
  
tmp1 = head;
  
for (int i = 0; i < n; i++)
	
	{
	  
printf ("Enter value of %dth element\n", i);
	  
scanf ("%d", &tmp1->info);
	  
node * tmp2 = malloc (sizeof (node));
	  
tmp1->prev = head->prev;
	  
tmp1->next = tmp2;
	  
tmp2->prev = tmp1;
	  
tmp1 = tmp2;
	
}
  
return head;

}


void
display (node * head) 
 { 
node * tmp = head;
  
if (head == NULL)
	
	{
	  
printf ("Empty node");
	
}
  
  else if (head->next == NULL)	//means single node is there
	{
	  
 
printf ("%d ", tmp->info);
	  
 
 
printf ("\n");
	
}
  
  else
	
	{
	  
while (tmp->next != NULL)
		
		{
		  
printf ("%d ", tmp->info);
		  
tmp = tmp->next;
		
}
	  
printf ("\n");
	
}

}

node * insert_d (node * head, int ind, int val) 
  { 
node * new = malloc (sizeof (node));
  
node * tmp = head;
  
if (head == NULL)
	
	{
	  
head = malloc (sizeof (NODE));
	  
head->info = val;
	  
head->next = NULL;
	  
head->prev = NULL;
	  
return head;
	
}
  
  else if (ind == 0)
	
	{
	  
new->info = val;
	  
new->prev = NULL;
	  
new->next = head;
	  
return new;
	
}
  
  else
	
	{
	  
int i = 1;
	  
while (i != ind && tmp != NULL)
		
		{
		  
tmp = tmp->next;
		  
i++;
		
}
	  
new->prev = tmp;
	  
new->next = tmp->next;
	  
tmp->next = new;
	  
new->info = val;
	  
return head;
	
}
  
	//   return head;
}

node * delete_d (node * head, int ind) 
 { 
node * tmp = head;
  
if (ind == 0)
	
	{
	  
head = head->next;
	  
head->next->prev = NULL;
	  
return head;
	
}
  
  else
	
	{
	  
int i = 1;
	  
while (i++ != ind && tmp != NULL)
		
		{
		  
tmp = tmp->next;
		
}
	  
tmp->next = tmp->next->next;
	
}
  
return head;

}

 
NODE * insert (NODE * head, int ind, int val) 
  { 
NODE * new = malloc (sizeof (NODE));
  
NODE * tmp1 = head;
  
if (head == NULL)
	
	{
	  
head = malloc (sizeof (NODE));
	  
head->info = val;
	  
head->next = NULL;
	  
return head;
	
}
  
  else if (ind == 0)
	
	{
	  
new->info = val;
	  
new->next = head;
	  
return new;
	
}
  
  else
	
	{
	  
int i = 1;
	  
NODE * tmp2 = head->next;
	  
while (i != ind && tmp1->next != NULL && tmp2 != NULL)
		
		{
		  
tmp1 = tmp1->next;
		  
tmp2 = tmp2->next;
		  
i++;
		
}
	  
tmp1->next = new;
	  
new->info = val;
	  
new->next = tmp2;
	
}
  
return head;

}

 
NODE * delete (NODE * head, int ind) 
 { 
NODE * tmp = head;
  
int i = 0;
  
if (ind == 0)
	
	{
	  
head = head->next;
	  
return head;
	
}
  
  else
	
	{
	  
while (tmp->next != NULL && i != ind - 1)
		
		{
		  
tmp = tmp->next;
		  
i++;
		
}
	  
tmp->next = tmp->next->next;
	  
return head;
	
}

}


 
 
 
void
  print (NODE * t) 
 { 
if (t == NULL)
	  
{
printf ("Empty node");
		
}
		
		else if (t->next == NULL)	//if it is a single node
		{
		
printf ("%d ", t->info); 
 
 
printf ("\n"); 
}
		
		else
		
		{
		
while (t->next != NULL) 
 { 
printf ("%d ", t->info); 
t = t->next; 
}
		
printf ("\n"); 
}
		
 
}
		
 
bool cycle_detection (NODE * head) 
		{ 
NODE * fast = head; 
NODE * slow = head;
		
while (fast && fast->next) 
 { 
slow = slow->next;
		
fast = fast->next->next; 
if (slow == fast) 
 return true; 
}
		
return false; 
}

		
 
void main () 
		{ 
int enter = 1; 
 
while (enter) 
		{
		
printf
		("How many nodes do you want to create in singly linked list?\n");
		
int n1; 
scanf ("%d", &n1);
		
printf
		("How many nodes do you want to create in doubly linked list?\n");
		
int n2; 
scanf ("%d", &n2); 
		//creating singly linked list by inserting i
		printf ("Singly linked list-\n"); 
NODE * tmp1 = NULL; 
NODE * tmp2;
		
for (int i = 0; i <= n1; i++) 
 { 
tmp2 = insert (tmp1, i, i + 1);
		
tmp1 = tmp2; 
} 
print (tmp1); 
		//creating doubly linked list by inserting i
		printf ("Doubly linked list-\n"); 
node * tmp3 = NULL; 
node * tmp4;
		
for (int i = 0; i <= n2; i++) 
 { 
tmp4 = insert_d (tmp3, i, i + 1);
		
tmp3 = tmp4; 
} 
display (tmp3); 
		//or you can create by calling create function
		NODE * h1 = create (n1); 
printf ("Singly linked list-\n");
		
print (h1); 
node * h2 = create_d (n2);
		
printf ("Doubly linked list-\n"); 
display (h2);
		
 
printf
		("What element do you want to insert in singly linked list and where?\n");
		
int v1, p1; 
scanf ("%d %d", &v1, &p1);
		
NODE * hh1 = insert (h1, p1, v1); 
print (hh1);
		
printf
		("What element do you want to insert in doubly linked list and where?\n");
		
int v2, p2; 
scanf ("%d %d", &v2, &p2);
		
node * hh2 = insert_d (h2, p2, v2); 
display (hh2);
		
printf ("What index do you want to delete in singly linked list\n");
		
int d1; 
scanf ("%d", &d1); 
NODE * dd1 = delete (hh1, d1);
		
print (dd1);
		
printf ("What index do you want to delete in doubly linked list\n");
		
int d2; 
scanf ("%d", &d2); 
node * dd2 = delete_d (hh2, d2);
		
display (dd2);
		
 
printf ("Now we create a linked list with a loop and detect it\n");
		
NODE * q1 = malloc (sizeof (NODE)); 
q1->info = 1;
		
NODE * q2 = malloc (sizeof (NODE)); 
q2->info = 2; 
q1->next = q2;
		
NODE * q3 = malloc (sizeof (NODE)); 
q3->info = 3; 
q2->next = q3;
		
q3->next = q1; 
bool t = cycle_detection (q1); 
printf ("%d\n", t);
		
printf ("Press 1 to start playing with linked list and 0 to exit\n");
		
scanf ("%d", &enter); 
} 
}

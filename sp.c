#include<stdio.h>
#include<stdlib.h>
#include<time.h>

struct sparse_matrix *create (struct sparse_matrix *m);	//it creates a 20*20 sparse matrix containing 20 non-zero elements at random locstions
void display (struct sparse_matrix *m);	//it displays the sparse matrix in coordinate form
void add (struct sparse_matrix *s1, struct sparse_matrix *s2);	//adds two sparse matrices if possible
struct sparse_matrix *transpose (struct sparse_matrix *s);	//finds the transpose of given sparse matrix
struct sparse_matrix *multiply (struct sparse_matrix *s1, struct sparse_matrix *s2);	//finds the product of two sparse matrices

//element is a structure representing the constituents of the coordinate form of sparse matrix
struct element
{
  int i;
  int j;
  int val;
};

//sparse_matrix structure is a prototype that holds an 'm' attribute storing the no. of rows, 'n' attribute storing the no. of columns
//and the 'non_zero' attribute storing total no. of non_zero elements. It also holds objects of the type 'element' 
struct sparse_matrix
{
  int m;
  int n;
  int non_zero;
  struct element *e;
};

void
main ()
{
  srand (time (NULL));
  struct sparse_matrix s1;
  create (&s1);
  struct sparse_matrix s2;
  create (&s2);
  struct sparse_matrix *s3 = transpose (&s2);
  printf ("Transpose of second matrix\n");
  display (s3);
  printf ("Product\n");
  display (multiply (&s1, s3));
  add (&s1, &s2);
}

struct sparse_matrix *
create (struct sparse_matrix *m)
{
  int count_non_zero = 20;
  m->m = m->n = count_non_zero;

  int matrix[20][20] = { 0 };
  int num, r, k;
  int count = 0;
  while (count != count_non_zero)
	{
	  num = rand () % (20 - 1 + 1) + 1; //since num is non-zero, lower limit is set to 1
	  r = rand () % (20 - 0 + 1) + 0;
	  k = rand () % (20 - 0 + 1) + 0;
	  if (matrix[r][k] == 0 && num!=0)
		{
		  matrix[r][k] = num;
		  count++;
		}
	}
  printf ("Random sparse matrix generated\n");
  for (int i = 0; i < 20; i++)
	for (int j = 0; j < 20; j++)
	  printf ("%d ", matrix[i][j]);
  printf ("\n");
  m->non_zero = count_non_zero;
  m->e =
	(struct element *) malloc (count_non_zero * (sizeof (struct element)));

  if (m->e == NULL)
	{
	  printf ("error in allocating memory\n");
	  exit (0);
	}

  int c = 0;
  for (int j = 0; j < m->m; j++)
	{
	  for (int k = 0; k < m->n; k++)
		{
		  if (matrix[j][k] != 0)
			{
			  m->e[c].i = j;
			  m->e[c].j = k;
			  m->e[c].val = matrix[j][k];
			  c++;
			}
		}
	}
  printf ("Printing the coordinate list form of sparse matrix\n");
  printf ("%d %d %d\n", m->m, m->n, m->non_zero);
  for (int i = 0; i < count_non_zero; i++)
	{
	  printf ("%d %d %d\n", m->e[i].i, m->e[i].j, m->e[i].val);
	}
  return m;
}

/*if user-entered sparse matrix is needed use this
struct sparse_matrix* create(struct sparse_matrix *m)
{
    printf("Enter dimensions of matrix:: ");
    scanf("%d %d",&m->m,&m->n);
    int matrix[m->m][m->n];
    printf("Enter elements of matrix:\n");
    int count_non_zero=0;
    for(int i=0;i<m->m;i++)
    {
        for(int j=0;j<m->n;j++)
        {
        scanf("%d",&matrix[i][j]);
        if(matrix[i][j]!=0)
        count_non_zero++;
        }
    }
    m->non_zero=count_non_zero;
    m->e=(struct element *)malloc(count_non_zero*(sizeof(struct element)));
    int c=0;
    for(int j=0;j<m->m;j++)
    {
        for(int k=0;k<m->n;k++)
        {
            if(matrix[j][k]!=0)
            {
              m->e[c].i=j;
              m->e[c].j=k;
              m->e[c].val=matrix[j][k];
              c++;
            }
        }
    }
    printf("Printing the crafted sparse matrix\n");
    printf("%d %d %d\n",m->m,m->n,m->non_zero);
    for(int i=0;i<count_non_zero;i++)
    {
        printf("%d %d %d\n",m->e[i].i,m->e[i].j,m->e[i].val);
    }
    return m;
}*/

void
display (struct sparse_matrix *m)
{
  //printf("Printing the crafted sparse matrix\n");
  printf ("%d %d %d\n", m->m, m->n, m->non_zero);
  for (int i = 0; i < m->non_zero; i++)
	{
	  printf ("%d %d %d\n", m->e[i].i, m->e[i].j, m->e[i].val);
	}
}

void
add (struct sparse_matrix *s1, struct sparse_matrix *s2)
{
  if (s1->m != s2->m || s2->n != s2->n)
	{
	  printf ("Addition not possible\n");
	  exit (0);
	}
  struct sparse_matrix *sum;
  sum = (struct sparse_matrix *) malloc (sizeof (struct sparse_matrix));
  if (sum == NULL)
	{
	  printf ("error in allocating memory\n");
	  exit (0);
	}
  sum->m = s1->m;
  sum->n = s1->n;

  sum->e =
	(struct element *) malloc ((s1->non_zero + s2->non_zero) *
							   (sizeof (struct element)));
  if (sum->e == NULL)
	{
	  printf ("error in allocating memory\n");
	  exit (0);
	}
  int c = 0;
  int i, j = 0;
  while (i < s1->non_zero && j < s2->non_zero)
	{
	  if (s1->e[i].i < s2->e[j].i)
		sum->e[c++] = s1->e[i++];
	  else if (s1->e[i].i > s2->e[j].i)
		sum->e[c++] = s2->e[j++];
	  else
		{
		  if (s1->e[i].j < s2->e[j].j)
			sum->e[c++] = s1->e[i++];
		  else if (s1->e[i].j > s2->e[j].j)
			sum->e[c++] = s2->e[j++];
		  else
			{
			  sum->e[c] = s1->e[i];
			  sum->e[c++].val = s1->e[i++].val + s2->e[j++].val;
			}
		}
	}
  for (; i < s1->non_zero; i++)
	sum->e[c++] = s1->e[i];
  for (; j < s2->non_zero; j++)
	sum->e[c++] = s2->e[j];
  sum->non_zero = c;
  printf ("Added matrix\n");
  for (int i = 0; i < c; i++)
	{
	  printf ("%d %d %d\n", sum->e[i].i, sum->e[i].j, sum->e[i].val);
	}
}

void
swap (int *a, int *b)
{
  int t = *a;
  *a = *b;
  *b = t;
}

struct sparse_matrix *
transpose (struct sparse_matrix *s)
{
  int m[s->non_zero][3];

  for (int j = 0; j < 3; j++)
	{
	  for (int i = 0; i < s->non_zero; i++)
		{
		  if (j == 0)
			m[i][j] = s->e[i].i;
		  else if (j == 1)
			m[i][j] = s->e[i].j;
		  else
			m[i][j] = s->e[i].val;
		}
	}

  for (int i = 0; i < s->non_zero; i++)
	{
	  swap (&m[i][0], &m[i][1]);
	}

  for (int i = 0; i < s->non_zero; i++)
	{
	  int min_ind = i;
	  for (int j = i + 1; j < s->non_zero; j++)
		{
		  if (m[j][0] < m[min_ind][0])
			min_ind = j;
		  else if (m[j][0] == m[min_ind][0])
			{
			  if (m[j][1] < m[min_ind][1])
				min_ind = j;
			}
		}
	  for (int k = 0; k < 3; k++)
		swap (&m[i][k], &m[min_ind][k]);
	}

  /*printf("Transpose through matrix\n");
     for(int i=0;i<s->non_zero;i++)
     {
     for(int j=0;j<3;j++)
     printf("%d ",m[i][j]);
     printf("\n");
     } */
  //printf("Transpose through struct\n");
  for (int i = 0; i < s->non_zero; i++)
	{
	  s->e[i].i = m[i][0];
	  s->e[i].j = m[i][1];
	  s->e[i].val = m[i][2];
	}
  return s;
}

struct sparse_matrix *
multiply (struct sparse_matrix *s1, struct sparse_matrix *s2)
{
  //printf("inside multiply displaying calling transpose");
  //display(s2);
  struct sparse_matrix *m =
	(struct sparse_matrix *) malloc (sizeof (struct sparse_matrix));
  if (m == NULL)
	{
	  printf ("error in allocating memory\n");
	  exit (0);
	}
  m->m = s1->m;
  m->n = s2->n;
  m->e =
	(struct element *) malloc ((s1->non_zero * s2->non_zero) *
							   (sizeof (struct element)));
  if (m->e == NULL)
	{
	  printf ("error in allocating memory\n");
	  exit (0);
	}
  int c = 0;
  for (int i = 0; i < s1->non_zero * s2->non_zero; i++)
	m->e[i].val = 0;
  for (int i = 0; i < s1->non_zero; i++)
	{
	  //printf("inside i interation %d\n",i);
	  for (int j = 0; j < s2->non_zero; j++)
		{
		  //printf("inside j iteration %d %d\n",i,j);
		  if ((s1->e[i].j) == (s2->e[j].j))
			{
			  m->e[c].val = (s1->e[i].val) * (s2->e[j].val);
			  m->e[c].i = s1->e[i].i;
			  m->e[c].j = s2->e[j].i;
			  //printf("value at %d %d is %d\n",m->e[c].i,m->e[c].j,m->e[c].val);
			  c++;
			}
		}
	}
  int k = 0;
  for (int i = 0; i < c; i++)
	{
	  int add = 0, point = 0;
	  for (int j = 0; j < c; j++)
		{
		  if (m->e[i].i == m->e[j].i && m->e[i].j == m->e[j].j)
			{
			  point = m->e[i].j;
			  add += m->e[j].val;
			  m->e[j].val = 0;
			}
		}
	  m->e[k].i = m->e[i].i;
	  m->e[k].j = point;
	  m->e[k].val = add;
	  k++;
	}
  struct sparse_matrix *result =
	(struct sparse_matrix *) malloc (sizeof (struct sparse_matrix));
  if (result == NULL)
	{
	  printf ("error in allocating memory\n");
	  exit (0);
	}
  result->m = s1->m;
  result->n = s2->n;
  result->e =
	(struct element *) malloc ((s1->non_zero * s2->non_zero) *
							   (sizeof (struct element)));
  int nz = 0;
  for (int i = 0; i < k; i++)
	{
	  if (m->e[i].val != 0)
		{
		  result->e[nz].val = m->e[i].val;
		  result->e[nz].i = m->e[i].i;
		  result->e[nz].j = m->e[i].j;
		  nz++;
		}
	}
  result->non_zero = nz;
  return result;
}

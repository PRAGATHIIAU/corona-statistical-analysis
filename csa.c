#include <stdio.h>
#include<malloc.h>
#include<conio.h>
#include<string.h>

struct admin
{
  char username[20];
  char password[20];
};
struct admin A;

struct Info
{
  int date;
  int newCases;
  int newDeath;
  int newCure;
  float newCaseRate;
  float deathRate;
  float cureRate;
  int testTaken;
};

struct TamilNadu
{
  struct Info info;
  struct TamilNadu *next;
};
struct TamilNadu *front = NULL;
struct TamilNadu *rear = NULL;

void
initialize ()
{
  FILE *file1 = fopen ("info.txt", "a+");
  FILE *file2 = fopen ("count.txt", "w+");
  FILE *file4 = fopen ("rcount.txt", "w+");
  FILE *file5 = fopen ("review.txt", "w+");
  int x1 = 6;
  int a[7] = {7,6,5,4,3,2,1 };
  int b[7] = {1569,4803,4300,3000,4500,2686,1337};
  int c[7] = {45,34,56,56,41,67,76};
  int d[7] = {1768,1569,1789,2390,1789,1299,2673};
  int e[7] = {11523,18765,12567,11223,19985,12875,21980};
  if (file1 == NULL)
    {
      printf ("error");
      return;
    }
  else
    {
      while (x1 >= 0)
	{
	  fprintf (file1, "%d\t%d\t%d\t%d\t%d\n", a[x1], b[x1], c[x1],
		   d[x1], e[x1]);
	  x1--;
	}
    }
  fprintf (file2, "%d", 7);
  fclose (file1);
  fclose (file2);
  char x[] = "pds";
  char y[] = "1077";
  FILE *file = fopen ("admin.txt", "a+");
  FILE *file3 = fopen ("acount.txt", "w+");
  if (file == NULL)
    {
      printf ("\nerror");
      return;
    }
  else
    {
      fprintf (file, "%s\t%s\n", x, y);
      fprintf (file3, "%d", 1);
    }
    fprintf (file5, "You're daily updates really keeps me updated. Thank you :)\n");
    fprintf (file5, "Good work guys..!\n");
    fprintf (file5, "Expecting more.\n");
    fclose (file5);
  fprintf (file4, "%d", 3);
  fclose (file);
  fclose (file3);
  fclose (file4);
}

void
Admin (int op)
{
  char un[20], pass[20];
  int x = 0, no;
  FILE *file1 = fopen ("acount.txt", "a+");
  fscanf (file1, "%d", &no);
  fclose (file1);
  int no1 = no;
  FILE *file = fopen ("admin.txt", "a+");
  if (file == NULL)
    {
      printf ("\nerror");
      return;
    }
  if (op == 1)
    {
      printf ("\n/*******************************************/\n");
      printf ("                  LOGIN PAGE                 \n");
      printf ("/*******************************************/\n\n");
      printf ("Enter the registered username:");
      scanf ("%s", un);
      printf ("Enter your password:");
      scanf ("%s", pass);
    }
  else if (op == 2)
    {
      printf ("\n/*******************************************/\n");
      printf ("                 SIGN UP PAGE                \n");
      printf ("/*******************************************/\n\n");
      printf ("Enter your username:");
      scanf ("%s", un);
      printf ("Enter your password:");
      scanf ("%s", pass);
    }

  while (x == 0)
    {
      while (no > 0)
	{
	  fscanf (file, "%s\t%s\n", &A.username, &A.password);
	  if (op == 1)
	    {
	      if (!(strcmp (un, A.username) || strcmp (pass, A.password)))
		{
		  printf ("\nHello %s, you successfully logged in.\n", un);
		  x++;
		  fclose (file);
		  return;
		}
	    }
	  no--;
	}
      if (op == 2)
	{
	  fprintf (file, "%s\t%s\n", un, pass);
	  FILE *file1 = fopen ("acount.txt", "w+");
	  fprintf (file1, "%d", no1 + 1);
	  fclose (file1);
	  printf ("\nHello %s, you successfully signed up.\n", un);
	  fclose (file);
	  return;
	}
      if (x == 0)
	{
	  printf ("Please enter the correct password:");
	  scanf ("%s", pass);
	  if (!(strcmp (un, A.username) || strcmp (pass, A.password)))
	    {
	      printf ("\nHello %s,you successfully logged in.\n", un);
	      x++;
	      fclose (file);
	      return;
	    }
	}
    }
}

float
calcRate (int new, int original)
{
  float temp = new - original;
  float r = (temp / original) * 100;
  return r;
}

void
assign ()
{
  FILE *file = fopen ("info.txt", "a+");
  FILE *file1 = fopen ("count.txt", "a+");
  if (file == NULL)
    {
      printf ("\nerror");
      return;
    }
  int x;
  fscanf (file1, "%d", &x);
  while (x > 0)
    {
      struct TamilNadu *new_node =
	(struct TamilNadu *) malloc (sizeof (struct TamilNadu));
      fscanf (file, "%d\t%d\t%d\t%d\t%d\n", &new_node->info.date,
	      &new_node->info.newCases, &new_node->info.newDeath,
	      &new_node->info.newCure, &new_node->info.testTaken);
      if (front != NULL)
	{
	  new_node->info.newCaseRate =
	    calcRate (new_node->info.newCases, rear->info.newCases);
	  new_node->info.deathRate =
	    calcRate (new_node->info.newDeath, rear->info.newDeath);
	  new_node->info.cureRate =
	    calcRate (new_node->info.newCure, rear->info.newCure);
	}
      if (front == NULL && rear == NULL)
	{
	  front = rear = new_node;
	  new_node->next = NULL;
	}
      else
	{
	  new_node->next = NULL;
	  rear->next = new_node;
	  rear = new_node;
	}
      x--;
    }
  fclose (file);
  fclose (file1);
}

void
review ()
{
  char rev[100];
  FILE *file = fopen ("rcount.txt", "a+");
  int c;
  fscanf (file, "%d", &c);
  fclose (file);
  printf ("\n/*******************************************/\n");
  printf ("                   REVIEW                      \n");
  printf ("/*******************************************/\n\n");
  printf ("Please enter your review here:");
  getchar ();
  fgets (rev, 100, stdin);
  printf ("\nTHANK YOU FOR THE REVIEW\n");
  FILE *file2 = fopen ("review.txt", "a+");
  fprintf (file2, "%s\n", rev);
  fclose (file2);
  FILE *file1 = fopen ("rcount.txt", "w+");
  int co = c + 1;
  fprintf (file1, "%d", co);
  fclose (file1);
  return;
}

void graph()
{
    struct TamilNadu *ptr = front;
	  char a[10] = { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' };
	  char b[10] = { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' };
	  char c[10] = { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' };
	  char d[10] = { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' };
	  char e[10] = { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' };
	  float r = 5.0 / 100;
	  int i = 0;
	  while (ptr != NULL)
	    {
	      if (ptr->info.newCaseRate * r > 4)
		{
		  a[i] = '*';
		  b[i] = '*';
		  c[i] = '*';
		  d[i] = '*';
		  e[i] = '*';
		}
	      else if (ptr->info.newCaseRate * r > 3)
		{
		  a[i] = ' ';
		  b[i] = '*';
		  c[i] = '*';
		  d[i] = '*';
		  e[i] = '*';
		}
	      else if (ptr->info.newCaseRate * r > 2)
		{
		  a[i] = ' ';
		  b[i] = ' ';
		  c[i] = '*';
		  d[i] = '*';
		  e[i] = '*';
		}
	      else if (ptr->info.newCaseRate * r > 1)
		{
		  a[i] = ' ';
		  b[i] = ' ';
		  c[i] = ' ';
		  d[i] = '*';
		  e[i] = '*';
		}
	      else if (ptr->info.newCaseRate * r > 0)
		{
		  a[i] = ' ';
		  b[i] = ' ';
		  c[i] = ' ';
		  d[i] = ' ';
		  e[i] = '*';
		}
	      else
		{
		  a[i] = b[i] = c[i] = d[i] = e[i] = ' ';
		}
	      ptr = ptr->next;
	      i++;
	    }
	  i = 0;
	  printf("\nRATE OF NEW CASES Vs DATE\n\n");
	  printf("  ^");
	  while (i < 10)
	    {
	      printf ("%c ", a[i]);
	      i++;
	    }
	  printf ("\n");
	  i = 0;
	  printf("R |");
	  while (i < 10)
	    {
	      printf ("%c ", b[i]);
	      i++;
	    }
	  printf ("\n");
	  printf("A |");
	  i = 0;
	  while (i < 10)
	    {
	      printf ("%c ", c[i]);
	      i++;
	    }
	  printf ("\n");
	  printf("T |");
	  i = 0;
	  while (i < 10)
	    {
	      printf ("%c ", d[i]);
	      i++;
	    }
	  printf ("\n");
	  printf("E |");
	  i = 0;
	  while (i < 10)
	    {
	      printf ("%c ", e[i]);
	      i++;
	    }
	  printf ("\n");
	  printf("  |");
	  i=0;
	  ptr=front;
	  while (i < 10 && ptr!=NULL)
	    {
	      printf ("%d ", ptr->info.date);
	      ptr=ptr->next;
	      i++;
	    }
	    printf ("\n");
	    printf("   ");
	   while(i>=0)
	   {
	       printf("---");
	       i--;
	   }
	   printf(">");
	   printf("\n");
	   printf("         D A T E");
	   printf("\n\n");
	   return;
}

struct TamilNadu *
insert (struct TamilNadu *front)
{
  char ch = 'y';
  FILE *file = fopen ("info.txt", "a+");
  int c;
  printf ("\n/*******************************************/\n");
  printf ("                 INSERT DATA                   \n");
  printf ("/*******************************************/\n\n");
  while (ch == 'y' || ch == 'Y')
    {
      struct TamilNadu *new_node =
	(struct TamilNadu *) malloc (sizeof (struct TamilNadu));
      printf ("Enter today's date:");
      scanf ("%d", &new_node->info.date);
      printf ("Enter today's new cases:");
      scanf ("%d", &new_node->info.newCases);
      printf ("Enter today's no. death due to corona:");
      scanf ("%d", &new_node->info.newDeath);
      printf ("Enter today's no. of cured patients from corona:");
      scanf ("%d", &new_node->info.newCure);
      printf ("Enter number of tests taken today:");
      scanf ("%d", &new_node->info.testTaken);
      fprintf (file, "%d\t%d\t%d\t%d\t%d\n", new_node->info.date,
	       new_node->info.newCases, new_node->info.newDeath,
	       new_node->info.newCure, new_node->info.testTaken);
      FILE *file1 = fopen ("count.txt", "a+");
      fscanf(file1,"%d",&c);
      fclose(file1);
      FILE *file2 = fopen ("count.txt", "w+");
      fprintf (file2, "%d", c + 1);
      fclose(file2);
      if (front != NULL)
	{
	  new_node->info.newCaseRate =
	    calcRate (new_node->info.newCases, rear->info.newCases);
	  new_node->info.deathRate =
	    calcRate (new_node->info.newDeath, rear->info.newDeath);
	  new_node->info.cureRate =
	    calcRate (new_node->info.newCure, rear->info.newCure);
	}
      if (front == NULL && rear == NULL)
	{
	  front = rear = new_node;
	  new_node->next = NULL;
	}
      else
	{
	  new_node->next = NULL;
	  rear->next = new_node;
	  rear = new_node;
	}
      printf ("\nDo you want to insert more data(y/n)?");
      getchar ();
      scanf ("%c", &ch);
      printf ("\n");
    }
  fclose (file);
  return front;
}

struct TamilNadu *
display (struct TamilNadu *front)
{
  struct TamilNadu *ptr;
  int d;
  char ch = 'y';
  printf ("\n/*******************************************/\n");
  printf ("                 DISPLAY DATA                  \n");
  printf ("/*******************************************/\n\n");
  while (ch == 'y' || ch == 'Y')
    {
      printf ("Enter the date  to be searched :");
      scanf ("%d", &d);
      int x = 0;
      ptr = front;
	  printf ("\n");
	  while (ptr != NULL)
	    {
	      if (ptr->info.date == d)
		{
		  printf ("DATE:%d\n", ptr->info.date);
		  printf ("NEW CASES:%d\n", ptr->info.newCases);
		  printf ("NO. DEATH:%d\n", ptr->info.newDeath);
		  printf ("NO. OF CURED PATIENTS:%d\n",
			  ptr->info.newCure);
		  printf ("NEW CASE RATE:%f\%\n", ptr->info.newCaseRate);
		  printf ("NEW DEATH RATE:%f\%\n", ptr->info.deathRate);
		  printf ("NEW CURE RATE:%f\%\n", ptr->info.cureRate);
		  printf ("TEST TAKEN:%d\n", ptr->info.testTaken);
		  x = x + 1;
		}
	      ptr = ptr->next;
	    }
      if (x == 0)
	{
	  printf ("There is no record for the given date!!");
	}
      printf ("\nDo you want to display more data(y/n)?");
      getchar ();
      scanf ("%c", &ch);
      printf ("\n");
    }
    return front;
}

struct TamilNadu *
display_user (struct TamilNadu *front)
{
  struct TamilNadu *ptr = front;
  int d, op, x;
  char ch = 'y';
  char s[20];
  char *si = malloc (20 * sizeof (char));
  void sign (float f)
  {
    if (f > 0.0)
      strcpy (s, "INCREASED");
    else if (f < 0.0)
      strcpy (s, "DECREASED");
    else
      strcpy (s, "REMAINED SAME");
    si = s;
    return;
  }
  printf
    ("\n****************************************************************************************************************\n");
  printf
    ("*          Corona Statistical Report provides an overview of the regional level COVID-19 updates               *\n");
  printf
    ("*          It helps in understanding the transmission dynamics of the infection on a daily basis               *\n");
  printf
    ("* Statistical report also supports us in presenting large amounts of data about COVID-19 in a convenient form  *\n");
  printf
    ("****************************************************************************************************************\n\n");
  FILE *file = fopen ("rcount.txt", "a+");
  FILE *file1 = fopen ("review.txt", "a+");
  int c;
  char r[100];
  int xx;
  int i = 0;
  char cha;
  fscanf (file, "%d", &c);
  xx = c;
  int num1 = (rand () % (c - 0 + 1)) + 0;
  int num2 = (rand () % (c - 0 + 1)) + 0;
  printf("SOME OF OUR VIEWER'S REVIEW:\n\n");
  while (xx > 0)
    {
      if (xx == num1 || xx == num2)
	{
	  fscanf (file1, "%[^\n]\n", r);
	  printf ("*%s\n", r);
	}
      xx--;
    }
  fclose (file);
  fclose (file1);
  printf("\n                           /*******************************************/\n");
  printf("                                           DISPLAY DATA               \n");
  printf("                           /*******************************************/\n\n");
  do
    {
      printf ("1.Display the records for a specific date\n");
      printf ("2.Display the records for all date\n");
      printf ("3.EXIT\n");
      printf ("Enter your option:");
      scanf ("%d", &op);
      if (op == 1)
	{
	  printf ("\nEnter the date to be searched :");
	  scanf ("%d", &d);
	  if (ptr == NULL)
	    {
	      printf ("\nTHE DATA BASE IS EMPTY");
	    }
	  else
	    {
	      printf ("\n");
	      while (ptr != NULL)
		{
		  if (ptr->info.date == d)
		    {
		      printf ("DETAILS FOR DATE:%d\n", ptr->info.date);
		      printf("\nRECORDS:\n");
		      printf ("TODAY'S NUMBER OF NEW CASES:%d\n",
			      ptr->info.newCases);
		      printf ("TODAY'S NUMBER OF DEATHS:%d\n",
			      ptr->info.newDeath);
		      printf ("TODAY'S NUMBER OF CURED PATIENTS:%d\n",
			      ptr->info.newCure);
			  printf ("NO. OF TEST'S TAKEN TODAY:%d\n\n",
			      ptr->info.testTaken);
			  printf("OBSERVATION:\n");
		      sign (ptr->info.newCaseRate);
		      printf ("TODAY'S NUMBER OF CASE HAS %s BY %f%\n", si,
			      ptr->info.newCaseRate);
		      sign (ptr->info.deathRate);
		      printf ("TODAY'S NUMBER OF DEATH HAS %s BY %f%\n", si,
			      ptr->info.deathRate);
		      sign (ptr->info.cureRate);
		      printf
			("TODAY'S NUMBER OF CURED PATIENTS HAS %s BY %f%\n",
			 si, ptr->info.cureRate);
			  printf("%f%\ OF THE TESTS TAKEN TODAY HAS RESULTED POSITIVE\n\n",(ptr->info.newCases*100)/ptr->info.testTaken);
		      x = x + 1;
		    }
		  ptr = ptr->next;
		}
	    }
	  if (x == 0)
	    {
	      printf ("There is no record for the given date!!\n\n");
	    }
	  ptr = front;
	  x = 0;
	}
      else if (op == 2)
	{
	  if (ptr == NULL)
	    {
	      printf ("\nTHE DATABASE IS EMPTY");
	      return;
	    }
	  printf ("\n");
	  while (ptr != NULL)
	    {
	      printf ("DETAILS FOR DATE:%d\n", ptr->info.date);
	      printf ("NUMBER OF NEW CASES TODAY:%d\n", ptr->info.newCases);
	      printf ("NUMBER OF DEATHS TODAY:%d\n", ptr->info.newDeath);
	      printf ("NUMBER OF CURED PATIENTS TODAY:%d\n",
		      ptr->info.newCure);
	      sign (ptr->info.newCaseRate);
	      printf ("TODAY'S NUMBER OF CASE HAS %s BY %f%\n", si,
		      ptr->info.newCaseRate);
	      sign (ptr->info.deathRate);
	      printf ("TODAY'S NUMBER OF DEATH HAS %s BY %f%\n", si,
		      ptr->info.deathRate);
	      sign (ptr->info.cureRate);
	      printf ("TODAY'S NUMBER OF CURED PATIENTS HAS %s BY %f%\n", si,
		      ptr->info.cureRate);
	      printf ("NO. OF TEST'S TAKEN TODAY:%d\n\n",
		      ptr->info.testTaken);
	      ptr = ptr->next;
	    }
	    graph();
	    ptr=front;
	}
    }
  while (op != 3);
  printf ("\n");
  return front;
}

struct TamilNadu *
manage (struct TamilNadu *front)
{
  struct TamilNadu *ptr, *ptr1;
  ptr = ptr1 = front;
  int d, c, de, cu, t, option,del,ret;
  char ch = 'y';
  printf ("\n/*******************************************/\n");
  printf ("                 MANAGE DATA                   \n");
  printf ("/*******************************************/\n");
  while (ch == 'y' || ch == 'Y')
    {
      printf ("\nEnter the date for which you want to manage data:");
      scanf ("%d", &d);
      printf
	("\n1.New cases\n2.New death\n3.New cure\n4.Tests taken\n5.Exit");
      do
	{
	  printf ("\nWhat do you want to manage?");
	  scanf ("%d", &option);
	  switch (option)
	    {
	    case 1:
	      ptr = front;
	      printf ("\nEnter the updated new cases:");
	      scanf ("%d", &c);
	      FILE *file = fopen ("info1.txt", "w+");
	      while (ptr != NULL)
		{
		  if (ptr->info.date == d)
		    ptr->info.newCases = c;
		  fprintf (file, "%d\t%d\t%d\t%d\t%d\n", ptr->info.date,
			   ptr->info.newCases, ptr->info.newDeath,
			   ptr->info.newCure, ptr->info.testTaken);
		  ptr = ptr->next;
		}
		 del = remove ("info.txt");
		   ret = rename ("info1.txt", "info.txt");
		  fclose(file);
	      break;
	    case 2:
	      ptr = front;
	      printf ("\nEnter the updated new death:");
	      scanf ("%d", &de);
	      FILE *file1 = fopen ("info2.txt", "w+");
	      while (ptr != NULL)
		{
		  if (ptr->info.date == d)
		    ptr->info.newDeath = de;
          fprintf (file1, "%d\t%d\t%d\t%d\t%d\n", ptr->info.date,
			   ptr->info.newCases, ptr->info.newDeath,
			   ptr->info.newCure, ptr->info.testTaken);
		  ptr = ptr->next;
		}
		 del = remove("info.txt");
	      ret = rename("info2.txt", "info.txt");
	      fclose(file1);
	      break;
	    case 3:
	      ptr = front;
	      printf ("\nEnter the updated new cure:");
	      scanf ("%d", &cu);
	      FILE *file2 = fopen ("info3.txt", "w+");
	      while (ptr != NULL)
		{
		  if (ptr->info.date == d)
		    ptr->info.newCure = cu;
		  fprintf (file2, "%d\t%d\t%d\t%d\t%d\n", ptr->info.date,
			   ptr->info.newCases, ptr->info.newDeath,
			   ptr->info.newCure, ptr->info.testTaken);
		  ptr = ptr->next;
		}
	     del = remove("info.txt");
	      ret = rename("info3.txt", "info.txt");
	      fclose(file2);
	      break;
	    case 4:
	      ptr = front;
	      printf ("\nEnter the updated tests taken:");
	      scanf ("%d", &t);
	      FILE *file3 = fopen ("info4.txt", "w+");
	      while (ptr != NULL)
		{
		  if (ptr->info.date == d)
		    ptr->info.testTaken = t;
		  fprintf (file3, "%d\t%d\t%d\t%d\t%d\n", ptr->info.date,
			   ptr->info.newCases, ptr->info.newDeath,
			   ptr->info.newCure, ptr->info.testTaken);
		  ptr = ptr->next;
		}
	      del = remove("info.txt");
	      ret = rename("info4.txt", "info.txt");
	      fclose(file3);
	      break;
	    }
	}
      while (option != 5);
      ptr = front->next;
      while (ptr != NULL)
	{
	  ptr->info.newCaseRate =
	    calcRate (ptr->info.newCases, ptr1->info.newCases);
	  ptr->info.deathRate =
	    calcRate (ptr->info.newDeath, ptr1->info.newDeath);
	  ptr->info.cureRate =
	    calcRate (ptr->info.newCure, ptr1->info.newCure);
	  ptr1 = ptr;
	  ptr = ptr->next;
	}
      printf ("\nDo you want to manage for other date(y/n)?");
      getchar ();
      scanf ("%c", &ch);
      printf ("\n");
    }
    return front;
}

struct TamilNadu *
delete_by_date (struct TamilNadu *front)
{
  struct TamilNadu *ptr1, *ptr2;
  char ch = 'y';
  printf ("\n/*******************************************/\n");
  printf ("                 DELETE DATA                   \n");
  printf ("/*******************************************/\n");
  int x = 0;
  if (ptr1 == NULL)
    {
      printf ("\nTHERE IS NO DATA IN THE LIST");
      return;
    }
  int d;
  while (ch == 'y' || ch == 'Y')
    {
      FILE *file3 = fopen ("info1.txt", "w+");
      ptr1=ptr2=front;
      x=0;
      printf ("\nEnter the date for which you want to delete the data:");
      scanf ("%d", &d);
      while (ptr1 != NULL)
	{
	  if (ptr1->info.date == d)
	    {
	      if (ptr1 == front)
		{
		  front = ptr1->next;
		  free (ptr1);
		  ptr1 = ptr2 = front;
		  x += 1;
		  continue;
		}
	      else if (ptr1 == rear)
		{
		  rear = ptr2;
		  free (ptr1);
		  ptr1 = rear;
		  rear->next = NULL;
		}
	      else
		{
		  ptr2->next = ptr1->next;
		  free (ptr1);
		  ptr1 = ptr2;
		}
	      x += 1;
	    }
	  else
	    {
	      fprintf (file3, "%d\t%d\t%d\t%d\t%d\n", ptr1->info.date,
		       ptr1->info.newCases, ptr1->info.newDeath,
		       ptr1->info.newCure, ptr1->info.testTaken);
	    }
	  ptr2 = ptr1;
	  ptr1 = ptr1->next;
	}
      if (x == 0)
	printf ("\nNo data is registered on the given date %d.\n", d);
      else
	{
	  printf("\nData deleted successfully\n");
	  FILE *file1 = fopen ("count.txt", "a+");
	  int c;
	  fscanf (file1, "%d", &c);
	  fclose (file1);
	  c = c - x;
	  FILE *file2 = fopen ("count.txt", "w+");
	  fprintf (file2, "%d", c);
	  fclose (file2);
	}
      int del = remove ("info.txt");
      int ret = rename ("info1.txt", "info.txt");
      fclose (file3);
      printf ("\nDo you want to delete more data(y/n)?");
      getchar ();
      scanf ("%c", &ch);
      printf ("\n");
    }
  return front;
}


int
main ()
{
  int op1, op2, op3, op4 = 0;
  initialize ();
  assign ();
  do
    {
      system("clear");
      printf ("\n/*******************************************/\n");
	  printf ("                  HOME PAGE                    \n");
	  printf ("/*******************************************/\n\n");
	  printf ("1.Iam an admin\n");
      printf ("2.Iam a user\n");
      printf ("3.Exit program\n");
      printf ("Please enter your choice:");
      scanf ("%d", &op1);
      if (op1 == 1)
	{
	  system("clear");
	  printf ("\n/*******************************************/\n");
	  printf ("              LOGIN/SIGN UP                  \n");
	  printf ("/*******************************************/\n\n");
	  printf ("1.Login\n");
	  printf ("2.Sign Up\n");
	  printf ("Please enter your choice:");
	  scanf ("%d", &op2);
	  Admin (op2);
	  do
	    {
	      system("clear");
	      printf ("\n/*******************************************/\n");
	      printf ("               ADMIN PORTAL                    \n");
	      printf ("/*******************************************/\n\n");
	      printf ("1.INSERT\n");
	      printf ("2.DISPLAY\n");
	      printf ("3.MANAGE\n");
	      printf ("4.DELETE\n");
	      printf ("5.GO BACK TO HOME PAGE\n");
	      printf ("\nSelect the action you want to perform:");
	      scanf ("%d", &op3);
	      switch (op3)
		{
		case 1:
		  front=insert (front);
		  break;
		case 2:
		  front=display (front);
		  break;
		case 3:
		  front=manage (front);
		  break;
		case 4:
		  front=delete_by_date (front);
		  break;
		}
	    }
	  while (op3 != 5);
	}
      if (op1 == 2)
	{
	  do
	    {
	      system("clear");
	      printf ("\n/*******************************************/\n");
	      printf ("                 USER PORTAL                   \n");
	      printf ("/*******************************************/\n\n");
	      printf ("1.DISPLAY\n");
	      printf ("2.REVIEW\n");
	      printf ("3.GO BACK TO HOME PAGE\n");
	      printf ("Enter your choice:");
	      scanf ("%d", &op3);
	      switch (op3)
		{
		case 1:
		  system("clear");
		  front=display_user (front);
		  break;
		case 2:
		  review ();
		  break;
		}
	    }
	  while (op3 != 3);
	}
    }
  while (op1 != 3);
  return 0;
}




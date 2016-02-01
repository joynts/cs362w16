/* -----------------------------------------------------------------------
 * Jennifer Mendoza 
 * Quiz 2- Random Tester
 * Due 1/31/16
 * -----------------------------------------------------------------------
 */

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

char inputChar()
{
    // TODO: rewrite this function
	int randomIndex;
	char randomChar;
	char pValues[34]="abcdefghijklmnopqrstuvwxyz[](){} ";
	
	randomIndex= 0+rand()%33;
	randomChar=pValues[randomIndex];
	
	return randomChar;
}

char *inputString()
{
    // TODO: rewrite this function
	int i;
	int randomIndex;
//	int n=6;
	int n=1+rand()%6;
//	char sValues[27]="abcdefghijklmnopqrstuvwxyz"; //This took too long.
	char sValues[7]="restab"; //reduced the characters drastically to get the word reset quickly
	char *randomString=malloc(sizeof(char)*n);
	
	for (i=0;i<n-1;i++)
	{
	//	randomIndex= rand()%27;
		randomIndex= rand()%6;
		randomString[i]=sValues[randomIndex];
	}
	randomString[n]='\0';
    return randomString;
}

void testme()
{
  int tcCount = 0;
  char *s;
  char c;
  int state = 0;
  while (1)
  {
    tcCount++;
    c = inputChar();
    s = inputString();
    printf("Iteration %d: c = %c, s = %s, state = %d\n", tcCount, c, s, state);

    if (c == '[' && state == 0) state = 1;
    if (c == '(' && state == 1) state = 2;
    if (c == '{' && state == 2) state = 3;
    if (c == ' '&& state == 3) state = 4;
    if (c == 'a' && state == 4) state = 5;
    if (c == 'x' && state == 5) state = 6;
    if (c == '}' && state == 6) state = 7;
    if (c == ')' && state == 7) state = 8;
    if (c == ']' && state == 8) state = 9;
    if (s[0] == 'r' && s[1] == 'e'
       && s[2] == 's' && s[3] == 'e'
       && s[4] == 't' && s[5] == '\0'
       && state == 9)
    {
      printf("error ");
      exit(200);
    }
  }
}


int main(int argc, char *argv[])
{
    srand(time(NULL));
    testme();
    return 0;
}
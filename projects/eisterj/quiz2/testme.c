#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

char inputChar()
{
	char randomChar = ((rand() % 76) + 50);
	//Set useless characters to ones we need:
	if (randomChar == 85)
		randomChar = 32;
	else if (randomChar == 86)
		randomChar = 40;
	else if (randomChar == 87)
		randomChar = 41;
	else if (randomChar < 60)
		randomChar = 114;
	else if (randomChar < 70)
		randomChar = 101;
	else if (randomChar < 80)
		randomChar = 115;
	else if (randomChar < 90)
		randomChar = 116;
	return randomChar;
}

char *inputString()
{
	static char randomString[6];
	randomString[5] = '\0';	
	int i;
	for (i = 0; i < 5; i++) {
		randomString[i] = inputChar();
	}
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


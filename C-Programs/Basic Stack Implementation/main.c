#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
char arr[50];    //stack of length 50
void push(char);
void pop(void);
char *ptr;

int main(void)
{
  char c;
  int num;
  ptr = &arr[0]-1;
  while(true)
  {
    printf("Enter a choice:\n1-push to stack.\n2-pop from stack.\n3-exit code.\n");
    scanf("%d", &num);
    switch(num)
    {
      case 1:
        printf("Enter a character: ");
        scanf(" %c", &c);
        push(c);
        break;
      case 2:
        pop();
        break;
      case 3:
        exit(0);
    }
  }
  return 0;
}

void push(char c)
{
  ptr++;
  *ptr = c;
  return;
}

void pop()
{
  printf("%c\n", *ptr);
  ptr--;
  return;
}
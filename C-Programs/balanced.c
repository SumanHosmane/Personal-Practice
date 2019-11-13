#include <stdio.h>
#include <string.h>

char len_of_stack[10];
void push(char);
void pop();
char *ptr;
int len_of_stack_i=0;

int main(void) {
  ptr = &len_of_stack[0];
  char str[] = "[{}])";
  int len = strlen(str);
  printf("%d\n",len);
  for (int i=0;i<len;i++)
  {
    if((str[i] == '{') || (str[i] == '(') || (str [i] == '['))
    {
      push(str[i]);
    }
    else if((str[i] == '}') || (str[i] == ')') || (str [i] == ']'))
    {
      if((str[i] == ')') && (len_of_stack[len_of_stack_i-1] == '('))
      {
        pop();
      }
      else if((str[i] == '}') && (len_of_stack[len_of_stack_i-1] == '{'))
      {
        pop();
      }
      else if((str[i] == ']') && (len_of_stack[len_of_stack_i-1] == '['))
      {
        pop();
      }
	  else
	  {
		break;
	  }  
    }
	else
	{
		continue;
	}
  }

if(ptr == &len_of_stack[0])
{
  printf("Balanced\n");
}

else
  printf("Unbalanced\n");
  return 0;
}

void push(char c)
{
  printf("Pushed - %c\n", c);
  *ptr = c;
  ptr++;
  len_of_stack_i++;
}

void pop()
{
  printf("Popped - %c\n", *(ptr-1));
  ptr--;
  len_of_stack_i--;
}
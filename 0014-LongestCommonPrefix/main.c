#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#define MAX 200

char* longestCommonPrefix(char** strs, size_t str_size) {
  size_t buf = 0;
  bool break_flag = 0;

  for (size_t c = 0; c < MAX && strs[0][c] != '\0'; c++)
  {
    size_t i = 0;
    char current_char = strs[i][c];
    for ( ; i < MAX && i < str_size; i++)
    {
      if (strs[i][c] == '\0' || strs[i][c] != current_char)
      {
        break_flag = 1;
        break;
      }
    }

    if (break_flag)
      break;

    buf++;
  }

  char* result = (char*)malloc(buf+1);

  if (buf != 0)
    strncpy(result, strs[0], buf);

  result[buf] = '\0';

  return result;
}

int main(int argc, char* argv[])
{
  if (argc < 2)
    return 1;

  char* result = longestCommonPrefix(argv+1, argc-1);

  printf("common prefix: \"%s\"\n", result);
  return 0;
}

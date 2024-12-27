#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* convert(char* s, int numRows) {

  if (s == NULL)
    return NULL;

  size_t K = 2 * numRows - 2;
  size_t sLen = strlen(s);

  char* result = (char*)malloc(sLen+1);
  
  if (numRows <= 1)
  {
    memcpy(result, s, sLen+1);
    return result;
  }

  size_t r = 0;
  for (size_t i = 0; i < numRows; i++)
  {
    if (i == 0 || i == numRows - 1)
      for (size_t j = i; j < sLen; j += K)
        result[r++] = s[j];
    else
    {
      for (size_t j = i; j < sLen; j += K)
      {
        result[r++] = s[j];
        if ( j + (K - i * 2) < sLen )
          result[r++] = s[ j + (K - i * 2) ];
      }
    }
  }
  
  result[r] = '\0';

  return result; 
}

int main(int argc, char* argv[])
{
  if (argc < 3)
    return 1;

  char* s = argv[2];
  int numRows = atoi(argv[1]);

  char* result = convert(s, numRows);

  printf("%s\n\n%s\n", s, result);
}

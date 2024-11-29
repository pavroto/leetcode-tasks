#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* longestPalindrome(char* s) {
  if (s[0] == '\0')
    return NULL; 

  if (s[1] == '\0')
  {
    char* result = (char*)malloc (2);
    result[0] = s[0];
    result[1] = '\0';
    return result;
  }

  size_t n = strlen(s);

  char table[n][n];
  memset(table, 0, sizeof(table));

  char* res_l = &s[0];
  char* res_r = &s[0];
  size_t max_len = 1;

  for (size_t i = 0; i < n; i++)
    table[i][i] = 1;

  for (size_t i = 0; i < n - 1; i++)
  {
    if (s[i] == s[i+1])
    {
      table[i][i+1] = 1;
      if (max_len < 2)
      {
        res_l = &s[i];
        res_r = &s[i+1];
        max_len = 2;
      }
    }
  }

  for (size_t k = 3; k <= n; k++)
  {
    for (size_t i = 0; i < n - k + 1; i++)
    {
      size_t j = i + k - 1;

      if (table[i+1][j-1] && s[i] == s[j])
      {
        table[i][j] = 1;
        if (k > max_len)
        {
          res_l = &s[i];
          res_r = &s[j];
          max_len = k;
        }
      }
    }
  }

  char* result = (char*)malloc(max_len + 1); 
  size_t i = 0;
  while (i <= res_r - res_l)
  {
    result[i] = *(res_l + i);
    i++;
  }
  result[i] = '\0';

  return result;
}

int main(int argc, char* argv[])
{
  if (argc < 2)
    return 1;

  char* result = longestPalindrome(argv[1]);

  printf("%s\n", result);

  return 0;
}

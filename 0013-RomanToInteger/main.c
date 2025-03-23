#include <stdio.h>

#define STRING_MAX 16

typedef struct {
  char key;
  int value;
} roman_t;

int romanCharToInt(char c)
{
  static const roman_t roman_dictionary[] = {
    {'C', 100},
    {'D', 500},
    {'I', 1},
    {'L', 50},
    {'M', 1000},
    {'V', 5},
    {'X', 10}
  };
  static const size_t roman_dictionary_len = sizeof(roman_dictionary) / sizeof(roman_t);

  ssize_t left = 0;
  ssize_t right = roman_dictionary_len - 1;
  
  while (left <= right)
  {
    ssize_t middle = (left + right) / 2;

    if (roman_dictionary[middle].key == c)
      return roman_dictionary[middle].value;

    if (roman_dictionary[middle].key > c)
      right = middle - 1;
    else
      left = middle + 1;
  }

  return 0;
}

int romanToInt(char* s) {
  int result = 0;

  for (size_t i = 0; i < STRING_MAX && s[i] != '\0'; i++)
  {
    if (s[i] == 'I')
      if (s[i+1] != '\0' && (s[i+1] == 'V' || s[i+1] == 'X'))
      {
        result += romanCharToInt(s[i+1]) - romanCharToInt(s[i]);
        i++;
        continue;
      }
    
    if (s[i] == 'X')
      if (s[i+1] != '\0' && (s[i+1] == 'L' || s[i+1] == 'C'))
      {
        result += romanCharToInt(s[i+1]) - romanCharToInt(s[i]);
        i++;
        continue;
      }

    if (s[i] == 'C')
      if (s[i+1] != '\0' && (s[i+1] == 'D' || s[i+1] == 'M'))
      {
        result += romanCharToInt(s[i+1]) - romanCharToInt(s[i]);
        i++;
        continue;
      }

    result += romanCharToInt(s[i]);
  }

  return result;
}

int main(int argc, char* argv[])
{
  if (argc < 2)
    return -1;

  printf("result: %d\n", romanToInt(argv[1]));
  return 0;
}

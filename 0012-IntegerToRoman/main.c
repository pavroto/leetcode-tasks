#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#define STRING_MAX 20
#define DIGITS_MAX 4

int divide_to_digits(uint8_t* out, int num)
{
  for (int i = DIGITS_MAX - 1; i >= 0; i--)
  {
    if (num > 0)
    {
      out[i] = num % 10;
      num /= 10;
    }
    else
      out[i] = 0;
  }
  return 0;
}

char* intToRoman(int num) {
  char roman_digits_pool[7] = "MDCLXVI";
  
  char* result = (char*)malloc(STRING_MAX + 1);
  uint8_t* digits = (uint8_t*)malloc(DIGITS_MAX);

  divide_to_digits(digits, num);
  
  int j = 0;
  for (int i = 0, r = 0; i < DIGITS_MAX; i++, r+=2)
  {
    if (digits[i] == 0)
      continue;
    if (digits[i] == 4)
    {
      result[j++] = roman_digits_pool[r];
      result[j++] = roman_digits_pool[r-1];
    }
    else if (digits[i] == 9)
    {
      result[j++] = roman_digits_pool[r];
      result[j++] = roman_digits_pool[r-2];
    }
    else
    {
      if (digits[i] >= 5)
      {
        result[j++] = roman_digits_pool[r-1];
        for (int k = 0; k < digits[i] - 5; k++)
          result[j++] = roman_digits_pool[r];
      }
      else
      {
        for (int k = 0; k < digits[i]; k++)
          result[j++] = roman_digits_pool[r];
      }
    }
  }
  
  result[j] = '\0';
  return result;
}

int main(int argc, char* argv[])
{
  if (argc < 2)
    return 1;

  printf("%s\n", intToRoman(atoi(argv[1])));
  return 0;
}

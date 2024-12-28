#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>

bool will_overflow_multiplication(int32_t x, int32_t y)
{
  if (x == -1 && y == INT32_MIN) return true;
  if (y == -1 && x == INT32_MIN) return true;
  if (x != 0 && y > INT32_MAX / x) return true;
  if (x != 0 && y < INT32_MIN / x) return true;
  return false;
}

bool will_overflow_add(int32_t x, int32_t y)
{
  if (x < 0 && y > INT32_MAX + x) return true;
  if (x > 0 && y < INT32_MIN + x) return true;
  return false;
}

int32_t get_rdigit_rmove(int32_t* number)
{
	int32_t result = *number % 10;
	*number = *number / 10;
	return result;
}

bool set_rdigit(int32_t* dst, int32_t digit, int32_t multiplier)
{
  if (will_overflow_multiplication(*dst, 10))
    return false;

  if (will_overflow_add(*dst*10, digit*multiplier))
    return false;

  *dst = *dst * 10 + digit * multiplier;
  return true;
}

int32_t reverse(int32_t number){
  int32_t result = 0;  
  int32_t multiplier = (number < 0) ? -1 : 1;
  int32_t digit;

  for (int factor = 0; number != 0; factor++)
  {
    digit = get_rdigit_rmove(&number);
    if (!set_rdigit(&result, digit, multiplier))
      return 0;
  }

  result *= multiplier;

  return result; 
}

int main(int argc, char* argv[])
{
  if (argc < 2)
    return 1;
  
  printf("%s\n", argv[1]);
  printf("%d\n", reverse(atoi(argv[1])));  
}

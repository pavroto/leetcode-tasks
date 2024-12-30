#include <stdio.h>
#include <ctype.h>
#include <stdint.h>
#include <stdbool.h>

bool will_overflow_multiplication(int32_t x, int32_t y)
{
	// -3, 10
  if (x == -1 && y == INT32_MIN) return true;
  if (y == -1 && x == INT32_MIN) return true;
	
	if (y != 0 && y > 0 && x > INT32_MAX / y) return true;
  if (y != 0 && y > 0 && x < INT32_MIN / y) return true;
 
	if (x != 0 && x > 0 && y > INT32_MAX / x) return true;
  if (x != 0 && x > 0 && y < INT32_MIN / x) return true;
  return false;
}
bool will_overflow_add(int32_t x, int32_t y)
{
	// 2147483640, 8
  if (x < 0 && y > INT32_MAX + x) return true;
  if (x > 0 && y < INT32_MIN + x) return true; 
  
	if (x > 0 && y > 0 && y > INT32_MAX - x) return true;
  if (x < 0 && y < 0 && y < INT32_MIN - x) return true; 
  return false;
}

bool set_rdigit(int32_t* dst, int32_t digit, int32_t multiplier)
{
  if (will_overflow_multiplication(*dst, 10))
	{
		*dst = (multiplier < 0) ? INT32_MIN : INT32_MAX;
		return false;
	}

	if (will_overflow_multiplication(digit, multiplier))
	{
		*dst = (multiplier < 0) ? INT32_MIN : INT32_MAX;
		return false;
	}
	
	if (will_overflow_add(*dst * 10, digit * multiplier))
	{
		*dst = (multiplier < 0) ? INT32_MIN : INT32_MAX;
		return false;
	}

	*dst = *dst * 10 + digit * multiplier; 
  return true;
}

int32_t myAtoi(char* s) 
{ 
	int ignore = 2;
	int32_t result = 0;
	int32_t multiplier = 1;
	size_t i = 0;
	for (i; s[i] != '\0'; i++)
	{
		if (isalpha(s[i]))
			return result;

		if (s[i] == ' ')
		{
			if (ignore <= 1)
				return result;
			continue;
		}

		if (s[i] == '+')
		{
			if (ignore <= 1)
				return result;

			ignore = 1;
			continue;
		}
			
		if (s[i] == '-')
		{
			if (ignore <= 1)
				return result;

			ignore = 1;
			multiplier = -1;
			continue;
		}

		if (isdigit(s[i]))
		{
			if (s[i] == '0' && result == 0)
			{
				ignore = 1;
				continue;
			}

			ignore = 0;

			if (!set_rdigit(&result, s[i] - '0', multiplier))
				return result;

			continue;
		}

		break;
	}

	return result;
}

int main(int argc, char* argv[])
{	
	if (argc < 2)
		return 1;

	int32_t result = myAtoi(argv[1]);

	printf("%s\n", argv[1]);
	printf("%d\n", result);
	return 0;
}

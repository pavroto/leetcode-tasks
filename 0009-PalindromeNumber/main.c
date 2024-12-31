#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

bool isPalindrome(int x) {
  if (x < 0 || x != 0 && x % 10 == 0)
    return false;

  int reversed = 0;
  for ( ; x > reversed; x /= 10)
    reversed = ( reversed*10 ) + ( x % 10 );

  if (reversed == x || x == reversed/10)
    return true;
	
	return false;
}

int main(int argc, char *argv[]) {
  if (argc < 2)
    return 1;

  printf("%d\n", isPalindrome(atoi(argv[1])));
}

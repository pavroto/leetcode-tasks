#include <stdio.h>

#define MIN(a, b) ((a < b) ? a : b)

int maxArea(int* height, int heightSize) {
  int heightMax = 0;

  int i = 0;
  int j = heightSize - 1;

  while (i < j)
  {
    int current = MIN(height[i], height[j]) * (j - i);
    if (current > heightMax)
      heightMax = current;

    if (height[i] < height[j])
      i++;
    else
      j--; 
  }

  return heightMax;
}

int main(int argc, char* argv[])
{
  int height[] = { 1,8,6,2,5,4,8,3,7 };
  int heightSize = 9;
  printf("%d\n", maxArea(height, heightSize));

  return 0;
}

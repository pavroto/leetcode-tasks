#include <limits.h>
#include <stdio.h>

double findMedianSortedArrays(int *nums1, int nums1Size, int *nums2,
                              int nums2Size) {
  if (nums1Size == 0 && nums2Size == 0)
    return 0;

  if (nums1Size == 1 && nums2Size == 0)
    return nums1[0];

  if (nums1Size == 0 && nums2Size == 1)
    return nums2[0];

  int is_odd = (nums1Size + nums2Size) % 2;

  int cur;
  int buf;

  int n = 0;
  int m = 0;

  int n_break = 0;
  int m_break = 0;

  if (nums1Size == 0)
    n_break = 1;

  if (nums2Size == 0)
    m_break = 1;

  while (n < nums1Size || m < nums2Size) {

    if (n_break) 
      cur = nums2[m++];
    else if (m_break)
      cur = nums1[n++];
    else if (nums1[n] > nums2[m])
      cur = nums2[m++];
    else
      cur = nums1[n++];

    if (n >= nums1Size)
      n_break = 1;
    if (m >= nums2Size)
      m_break = 1;

    if ((n + m) == (int)((nums1Size + nums2Size) / 2 + 1)) {
      if (is_odd) {
        return (double)cur;
      } else {
        return ((double)cur + (double)buf) / 2.0;
      }
    }

    if (n_break && m_break)
      break;

    buf = cur;
  }

  return INT_MIN;
}

int main() {

  int nums1[] = {1, 3};
  int nums2[] = {2};

  double result = findMedianSortedArrays(nums1, sizeof(nums1) / sizeof(int),
                                         nums2, sizeof(nums2) / sizeof(int));

  fprintf(stdout, "result: %f\n", result);

  return 0;
}

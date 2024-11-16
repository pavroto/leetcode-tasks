#include <stdio.h>
#include <string.h>

int lengthOfLongestSubstring(const char* s) {
	int len = strlen(s);
	
	if (len == 0 || len == 1)
		return len;

	int left = 0;
	int right = 0;
	int max_length = 0;

	char visited[128] = { 0 };

	while (right < len)
	{
		while (visited[s[right]] == 1)
		{
			visited[s[left]] = 0;
			left++;
		}

		visited[s[right]] = 1;

		if (max_length < (right - left + 1))
			max_length = right - left + 1;

		right++;
	}
	return max_length;
}

int main()
{
	char* s = "abcba";

	int result = lengthOfLongestSubstring(s);
	
	printf("result = %d\n", result);
}

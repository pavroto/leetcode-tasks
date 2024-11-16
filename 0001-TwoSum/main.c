#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct {
	int key; 		// the number
	int value;	// numbers` index
} HashEntry;

typedef struct {
	HashEntry* table;
	int size; // number of entries
} HashTable;

HashTable* create_hash_table(int size)
{
	HashTable* hash_table = (HashTable*)malloc(sizeof(HashTable));
	hash_table->table = (HashEntry*)malloc(size * sizeof(HashEntry));

	for (int i = 0; i < size; i++)
	{
		hash_table->table[i].key = INT_MIN;
		hash_table->table[i].value = INT_MIN;
	}

	return hash_table;
}

int hash(int key, int size)
{
	return ( ( key % size ) + size ) % size;	
}

void insert(HashTable* hash_table, int key, int value)
{
	int idx = hash(key, hash_table->size);

	if (hash_table->table[idx].key == INT_MIN)
	{
		hash_table->table[idx].key = key;
		hash_table->table[idx].value = value;
	}
}

int search(HashTable* hash_table, int key)
{
	int idx = hash(key, hash_table->size);
	
	if (hash_table->table[idx].key == key)
		return hash_table->table[idx].value;

	return -1;
}

void free_HashTable(HashTable* hash_table)
{
	free(hash_table->table);
	free(hash_table);
}

void print_HashTable_info(HashTable* hash_table)
{
	printf("size = %d\n", hash_table->size);

	for (int i = 0; i < hash_table->size; i++)
	{
		printf("hash_table->table[%d]:\n", i);
		printf("	key=%d\n", hash_table->table[i].key); 
		printf("	value=%d\n", hash_table->table[i].value); 
	}
}

int* twoSum(int* nums, int numsSize, int target, int* returnSize)
{
	HashTable* hash_table = create_hash_table(numsSize);
	hash_table->size = numsSize;

	int* output = (int*)malloc(2 * sizeof(int));
	*returnSize = 2;

	for (int i = 0; i < numsSize; ++i)
	{
		int searched_value = target - nums[i];
		int searched_index = search(hash_table, searched_value);

		if (searched_index != -1)
		{
			output[0] = searched_index;
			output[1] = i;
			
			print_HashTable_info(hash_table);
			free_HashTable(hash_table);
			return output;
		}

		insert(hash_table, nums[i], i);
	}

	free(output);
	free_HashTable(hash_table);
	return NULL;
}


int main()
{
	int nums[] = { -2, -2, -1, 0, 1, 2 };
	int numsSize = 6;
	int target = -4;
	int returnSize;

	int* output = twoSum(nums, numsSize, target, &returnSize);

	if (output == NULL || returnSize != 2)
		return 1;

	printf("nums = { %d", nums[0]);
	for (int i = 1; i < numsSize; i++)
		printf(", %d", nums[i]);
	printf(" }\n");

	printf("target = %d\n", target);
	printf("[ %d, %d ]\n", output[0], output[1]);
	
	free(output);
	return 0;

	

}

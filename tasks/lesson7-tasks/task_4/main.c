#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define LENGTH 10

void *calc_primes(int size);
int is_prime(int num);
void *calc_catalan_nums(int size);


void *calc_primes(int size)
{
	int amount = size;
	int *nums = malloc(sizeof(int) * LENGTH);
	int done = 0;
	int count = 2;

	while (done != amount)
	{
		int ans = is_prime(count);

		if (ans == 1)
		{
			nums[done] = count;
			done += 1;
		}
		count += 1;
	}
	pthread_exit(nums);
}

int is_prime(int num)
{
	for (int i = 2; i < num; i++)
	{
		if (num % i == 0)
			return 0;
	}
	return 1;
}

void *calc_catalan_nums(int size)
{
	int amount = size;
	int *nums = malloc(sizeof(int) * LENGTH);
	nums[0] = 1;
	int i = 1;

	while (i < amount)
	{
		nums[i] = ((2 * (2 * (i - 1) + 1)) * nums[i - 1] / ((i - 1) + 2));
		i += 1;
	}
	pthread_exit(nums);
}

int main()
{
	pthread_t thread1, thread2;

	if (pthread_create(&thread1, NULL, (void *) &calc_catalan_nums, (void *)LENGTH) != 0)
	{
		fprintf(stderr, "Error: Thread 1\n");
		return 1;
	}

	if (pthread_create(&thread2, NULL, (void *) &calc_primes, (void *)LENGTH) != 0)
	{
		fprintf(stderr, "Error: Thread 2\n");
		return 1;
	}

	void *catalan_nums = malloc(sizeof(int) * LENGTH);
	void *primes = malloc(sizeof(int) * LENGTH);

	if (pthread_join(thread1, &catalan_nums) != 0)
	{
		fprintf(stderr, "Join error: Thread 1\n");
		return 1;
	}

	if (pthread_join(thread2, &primes) != 0)
	{
		fprintf(stderr, "Join error: Thread 2\n");
		return 1;
	}

	printf("Catalan nums:\n");
	for (int i = 0; i < LENGTH; i++)
	{
		printf("%d ", ((int*)catalan_nums)[i]);
	}

	printf("\n");
	printf("Primes:\n");

	for (int i = 0; i < LENGTH; i++)
	{
		printf("%d ", ((int*)primes)[i]);
	}
	printf("\n");
	
	return 0;
}
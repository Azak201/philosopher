#include <philo.h>

static int *converting_inputs(char **argv);
/*this is the main function its check for the argument number and 
if its only numbers of not then its atoi it and sort it in arr[]
then send it to create_threads and free the arr at the end*/
int main(int argc, char **argv)
{
	int *arr;
	int i;

	i = 0;
	if (argc == 5 || argc == 6)
	{
		if (check_args(argc, argv) == -1)
			return (1);
		arr = converting_inputs(argv);
		if(!arr)
			return (1);
		if (argc == 6)
			arr[4] = ft_atoi(argv[5]);
		if ((create_threads(arr)) != 0)
		{
			free(arr);
			return (1);
		}
		free(arr);
	}
	else 
		return (1);
	return (0);
}

//just put atoi to the argv elements
int *converting_inputs(char **argv)
{
	int *arr;
	int i;

	i = 0;
	arr = malloc(sizeof(int)*5);
	if(!arr)
		return (NULL);
	while (i<4)
	{
		arr[i] = ft_atoi(argv[i+1]);
		i++;
	}
	arr[4] = 0;
	return(arr);
}


void *rotin(void *thread)
{
	t_philo *ph;

	ph = (t_philo *)thread;
	while (condition)
	{
	// monitoring
	// philo_sleep
	// philo_eat
	// philo_thinking
	}
	return (NULL);
}
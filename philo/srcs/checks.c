#include <philo.h>

/* theis checks that the argument are all numbers*/
int check_args(int argc,char **arg)
{
int i;
int j;

i= 1;
while (i<argc)
{
	j=0;
	while(arg[i][j]!='\0')
	{
		if(arg[i][j] < '0' || arg[i][j] > '9')
		{
			printf("Error: argument not numbers\n");
			return (-1);
		}
		j++;
	}
i++;
}
return (0);
}


int	ft_atoi(const char *nptr)
{
	int	count;
	int	negative;
	int	number;

	count = 0;
	negative = 1;
	number = 0;
	while ((nptr[count] > 8 && nptr[count] < 14) || (nptr[count] == 32))
		count++;
	if (nptr[count] == '-' || nptr[count] == '+')
	{
		if (nptr[count] == '-')
			negative = -1;
		count++;
	}
	while ((nptr[count] != '\0') && (nptr[count] >= 48 && nptr[count] <= 57))
	{
		number = (number * 10) + nptr[count] - 48;
		count++;
	}
	return (number * negative);
}
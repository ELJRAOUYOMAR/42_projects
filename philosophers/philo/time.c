# include "philo.h"

long long get_timestamp()
{
    struct timeval tv;

    if (gettimeofday(&tv, NULL))
        return (-1);
    return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

long long	time_difference(long long past, long long present)
{
	return (present - past);
}

void precise_sleep(long long time_sleep_in_ms)
{
    long long start;
    long long current;

    start = get_timestamp();
    if (start == -1)
        return ;
    while (1)
    {
        current = get_timestamp();
        if (current == -1 || time_difference(start, current) >= time_sleep_in_ms)
            break ;
        usleep(500); // sleep in short for more precision    
    }

}
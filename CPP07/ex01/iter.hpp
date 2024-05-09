#ifndef ITER_HPP
#define ITER_HPP

template <typename T>
void	printValue(T &c)
{
	std::cout << "[" << c << "]";
}

template <typename T, typename Function>
void	iter(T *array, size_t &len, Function f)
{
	for (size_t idx = 0; idx < len; idx++)
	{
		f(array[idx]);
	}
}

template <typename T>
void	multiply2(T &c)
{
	c *= 2;
}


#endif

#include "PmergeMe.hpp"

template <typename T>
static void insertionSort(T& tab, int start, int end)
{
	for (int i = start + 1; i < end; i++)
	{
		int	key = tab[i];
		int	j = i - 1;

		while (j >= start && tab[j] > key)
		{
			tab[j + 1] = tab[j];
			j--;
		}
		tab[j + 1] = key;
	}
}

template <typename T>
static void sort(T& tab)
{
	std::cout << "Calling sort function" << std::endl;

	int arrayLen = tab.size();
	for (int i = 0; i < arrayLen; i += tabsSize)
		insertionSort<T>(tab, i, std::min(i + tabsSize, arrayLen));
};

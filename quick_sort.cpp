#include <iostream>
#include <fstream>
#include <deque>

int mod = 1;

void printArray(std::deque<int> arr, int size, int start)
 {
	int i;

	for (i = start; i < size; i++)
	{
		std:: cout << arr[i] << " ";
	}
	std::cout << std::endl;
 }

 void ft_swap(int* a, int* b)
 {
	 int tmp;
	 tmp = *a;
	 *a = *b;
	 *b = tmp;
 }

 int get_median(int a, int b, int c)
 {
	int tmp_a = a;
	int tmp_b = b;
	int tmp_c = c;
	if (tmp_a > tmp_b)
	{
		ft_swap(&tmp_a, &tmp_b);
	}
	if (tmp_b > tmp_c)
	{
		ft_swap(&tmp_b, &tmp_c);
	}
	if (tmp_a > tmp_b)
	{
		ft_swap(&tmp_a, &tmp_b);
	}
	if (a == tmp_b)
	{
		return (0);
	}
	else if (b == tmp_b)
	{
		return (1);
	}
	else return (2);
	return (b);
 }
 
 void get_pivot_mod(std::deque<int> &arr, int start, int end)
 {
	
	if (mod == 1)
	{
		return ;
	}
	if (mod == 2)
	{
		std::swap(*std::next(arr.begin(), start), *std::next(arr.begin(), end));
	}
	else
	{
		int median_index = 0;
 
		if ((end + 1 - start) % 2 == 1)
			median_index = (end + 1 - start) / 2;
		else
			median_index = ((end + 1 - start) + 1) / 2;
		median_index = start + get_median(arr[start], arr[end], arr[median_index]);
		std::swap(*std::next(arr.begin(), start), *std::next(arr.begin(), median_index));
	}
 }
 int partition(std::deque<int> &arr, int start, int end)
 {
	int j = start + 1;
	int i = start + 1;

	get_pivot_mod(arr, start, end);
	int pivot = arr[start];
	while (j <= end)
	{
		if (arr[j] < pivot)
		{
			std::swap(*std::next(arr.begin(), i), *std::next(arr.begin(), j));
			i++;
		}
		j++;
	}
	std::swap(*std::next(arr.begin(), start), *std::next(arr.begin(), i - 1));
	return (i - 1);
 }

 int quick_sort(std::deque<int> &arr, int start, int end, int sum_step)
 {
	if (start < end)
	{
		int pivot_index = partition(arr, start, end);
		sum_step += quick_sort(arr, start, pivot_index - 1, sum_step);
		sum_step += quick_sort(arr, pivot_index + 1, end, sum_step);
		return (sum_step + (end - start));
	}
	return (0);
 }

int main(int argv, char **argc)
{
	int sum_all = 0;
	char tmp_m;
	std::fstream file;
	std::string word;
	std::deque<int> arr_d;

	file.open("input.txt");
	while (file >> word)
	{
		arr_d.push_back(atoi(word.c_str()));
	}
	file.close();
	std::cout << " please input pivot mod \n" ;
	std::cout << "1 - pivot is first element \n" ;
	std::cout << "2 - pivot is final element \n" ;
	std::cout << "3 - pivot is median element \n" ;
	std::cin.get(tmp_m);
	mod = tmp_m - 48;
	sum_all += quick_sort(arr_d, 0, arr_d.size() - 1, 0);
	std::cout << "Sorted array: \n";
	printArray(arr_d, arr_d.size(), 0);
	std::cout << "sum: "<< sum_all<<" \n";
	return 0;
}
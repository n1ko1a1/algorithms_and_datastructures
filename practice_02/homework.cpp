#include <vector>
#include <iostream>

template<typename T>
void PrintVec(std::vector<T>& vec)
{
    int len = vec.size();
    for (int i = 0; i < len; i++)  //3  0 1 2
    {
        std::cout << vec[i] << " ";
    }
	std::cout << std::endl;
}
template<typename T>
int Partition(std::vector<T>& v, int start, int end) 
{
	int pivot = end;
	int j = start;
	for (int i = start; i < end; ++i) {
		if (v[i] < v[pivot]) {
			std::swap(v[i], v[j]);
			++j;
		}
	}
	std::swap(v[j], v[pivot]);
	return j;
}
template<typename T>
void QuickSort(std::vector<T>& v, int start, int end) {

	if (start < end) {
		int p = Partition<T>(v, start, end);
		QuickSort<T>(v, start, p - 1);
		QuickSort<T>(v, p + 1, end);
	}
}

int main()
{
    std::vector<int> nums = { 2, 3, 1, 6, 5, 12, 4 };
	std::cout << "initial vector: ";
	PrintVec<int>(nums);
	QuickSort<int>(nums, 0, nums.size() - 1);
	std::cout << "sorted vector: ";
	PrintVec<int>(nums);

	std::cout << std::endl;

	std::vector<char> chars = { 'f', 'c', 'a', 'v', 'w', 'e', 'b'};
	std::cout << "initial vector: ";
	PrintVec<char>(chars);
	QuickSort<char>(chars, 0, chars.size() - 1);
	std::cout << "sorted vector: ";
	PrintVec<char>(chars);

    return 0;
}

void PrintVector(std::vector<int>& vctr) {
	for (int i = 0; i < vctr.size(); i++) {
		std::cout << vctr[i] << std::endl;
	}
}

void QSort(std::vector<int>& vctr, int first, int last) {
	if (first < last) {
		int left = first;
		int right = last;
		int middle = vctr[(left + right) / 2];
		do {
			while (vctr[left] < middle)
				left++;
			while (vctr[right] > middle)
				right--;
			if (left <= right) {
				int tmp = vctr[left];
				vctr[left] = vctr[right];
				vctr[right] = tmp;
				left++;
				right--;
			}
		} while (left < right);
		QSort(vctr, first, right);
		QSort(vctr, left, last);
	}
}

int main()
{
	std::vector<int> nums = {50, 3, 1, 2, 12, 5, 6, 4, 0};
	QSort(nums, 0, nums.size() - 1);
	PrintVector(nums);
}

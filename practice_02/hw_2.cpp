#include <vector>
#include <iostream>


template<typename T>
void PrintVector(std::vector<int>& vctr) {
	for (int i = 0; i < vctr.size(); i++) {
		std::cout << vctr[i] << std::endl;
	}
}


template<typename T>
void BubbleSort(std::vector<int>& vctr)
{
    bool swap = true;
    while (swap)
    {
        swap = false;
        for (int i = 0; i < vctr.size() - 1; i++)
        {
            if (vctr[i] > vctr[i + 1])
            {
                std::swap(vctr[i], vctr[i + 1]);
                swap = true;
            }
        }
    }
}

int main()
{
    	std::vector<int> nums = {6, 2, 4, 1, 0, 3, 5, 9, 7, 8};
    	
	   	BubbleSort<int>(nums);
	    
	    PrintVector<int>(nums);
	    
	return 0;
}
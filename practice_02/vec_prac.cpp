#include <iostream>
#include <vector>
using namespace std;

template <typename T>
void sort(vector<T> & vec)
{
	int sizevec = vec.size();
	for (int i = 0; i <= sizevec; i++)
	{
		for (int j = 0; j < sizevec - i - 1; j++)
		{
			if (vec[j] > vec[j + 1])
			{
				int help = vec[j];
				vec[j] = vec[j + 1];
				vec[j + 1] = help;
			}
		}
	}
}

int main()
{
	vector<int> newVector = { 5,3,123,54,7,78,1,8 };
	sort(newVector);
	int helpsize = newVector.size();
	for (int k = 0; k < helpsize; k++)
	{
		cout << newVector[k] << " ";
	}
}

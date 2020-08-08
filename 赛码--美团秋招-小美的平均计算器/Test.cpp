#include<iostream>
#include<vector>
#include<stdlib.h>
using namespace std;

float GetAverageGrade(vector<int> res)
{
	float sum=0.00;
	for (int i = 0; i<5; ++i)
	{
		if (i == 0)
		{
			sum += res[i] * 1;
		}
		else if (i == 1)
		{
			sum += res[i] * 2;
		}
		else if (i == 2)
		{
			sum += res[i] * 3;
		}
		else if (i == 3)
		{
			sum += res[i] * 4;
		}
		else
		{
			sum += res[i] * 5;
		}

	}
	return sum ;
}

int main()
{
	vector<int> res;
	int i;
	int sum = 0;
	double a = 1.0;
	for (int j = 0; j < 5; ++j)
	{
		cin >> i;
		sum += i;
       res.push_back(i);
	}
	if (sum == 0)
	{
		//float average = GetAverageGrade(res) / sum;
		//average = ((float)((int)((average + 0.005) * 10))) / 10;
		cout << a<< endl;
	}
	else
	{
		float average = GetAverageGrade(res) / sum;
		average = ((float)((int)((average + 0.005) * 10))) / 10;
		cout << average << endl;
	}
	system("pause");
	return 0;
}
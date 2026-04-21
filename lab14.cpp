#include <iostream>
#include <iomanip>
#include <algorithm>

using namespace std;

void enterScores(int numScores, double* scores);
void sortScores(double* arr, int size);
double calculateAverageDropLowest(double* arr, int size);
//double displayScores(double* arr, int size);

//Main Driver
int main()
{
	int numScores;
	double* scores = nullptr;

	cout << "Enter the number of scores: ";
	cin >> numScores;

	enterScores(numScores, scores);

	sortScores(scores, numScores);

	cout << endl << "Sorted Scores: ";
	//displayScores(scores, numScores)


	delete[] scores;
	scores = nullptr;

	return 0;
}

//Enter Scores
void enterScores(int numScores, double* scores)
{
	while (numScores <= 0)
	{
		cout << "Please enter a positive Number: ";
		cin >> numScores;
	}

	scores = new double[numScores];

	for (int i = 0; i < numScores; i++)
	{
		do
		{
			cout << "Enter Score #" << (i + 1) << ": ";
			cin >> *(scores + i);
			if (*(scores + i) < 0)
			{
				cout << "Negative scores are not allowed.\n";
			}
		} while (*(scores + i) < 0);
	}
}

//This will sort the scores
void sortScores(double* arr, int size)
{
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = 0; j < size - i - 1; j++)
		{
			if (*(arr + j) > *(arr + j + 1))
			{
				double temp = *(arr + j);
				*(arr + j) = *(arr + j + 1);
				*(arr + j + 1) = temp;
			}
		}
	}
}

// This will calculate the averege and should hopefully drop the lowest one haha
double calculateAverageDropLowest(double* arr, int size)
{
	if (size <= 1) return 0.0;

	double total = 0;
	for (int i = 1; i < size; i++)
	{
		total += *(arr + i);
	}
	return total / (size - 1);
}
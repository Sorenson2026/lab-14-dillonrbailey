#include <iostream>
#include <iomanip>
#include <algorithm>

using namespace std;

void enterScores(int numScores, double* scores);
void sortScores(double* arr, int size);
double calculateAverageDropLowest(double* arr, int size);

//Main Driver
int main()
{
	int numScores;
	double* scores = nullptr;

	cout << "Please enter the number of scores: ";
	cin >> numScores;
	while (numScores <= 0)
	{
		cout << "Please enter a positive Number: ";
		cin >> numScores;
	}

	scores = new double[numScores];

	enterScores(numScores, scores);

	cout << endl;

	sortScores(scores, numScores);

	calculateAverageDropLowest(scores, numScores);


	delete[] scores;
	scores = nullptr;

	return 0;
}

//Enter Scores
void enterScores(int numScores, double* scores)
{

	for (int i = 0; i < numScores; i++)
	{
		cout << "Enter Score #" << (i + 1) << ": ";
			cin >> *(scores + i);
			if (*(scores + i) < 0)
			{
				cout << "Negative scores are not allowed.\n";
			}
	}
}

//sort everything
void sortScores(double* arr, int size)
{
	for (int pass = 0; pass < size - 1; pass++)
	{
		double small = arr[pass];
		int smallindex = pass;

		for (int index = pass + 1; index < size; index++)
		{
			if (arr[index] < small)
			{
				small = arr[index];
				smallindex = index;
			}
		}
		swap(arr[smallindex], arr[pass]);
	}
}

// This will calculate the averege and should hopefully drop the lowest one haha
double calculateAverageDropLowest(double* arr, int size)
{
	cout << "Test scores: ";
	for (int i = 0; i < size; i++)
		cout << arr[i] << " ";

	if (size <= 1) return 0.0;

	double total = 0;
	for (int i = 1; i < size; i++)
	{
		total += *(arr + i);
		
	}
	
	cout << endl << "Your average minus the smallest score is: " << total / (size - 1) << endl << endl;

	cout << "Thanks for your help Garth and Tyler :)" << endl;
}
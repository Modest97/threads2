#include <iostream>
#include <thread>
#include <ctime>

using namespace std;

void summing(int** m1, int** m2, int** res, int from, int to, int n)
{
	for (int i = from;i < to;++i)
	{
		for (int j = 0;j < n;++j)
		{
			res[i][j] = m1[i][j] + m2[i][j];
		}
	}
}

void subtraction(int** m1, int** m2, int** res, int from, int to, int n)
{
	for (int i = from;i < to;++i)
	{
		for (int j = 0;j < n;++j)
		{
			res[i][j] = m1[i][j] - m2[i][j];
		}
	}
}
void main()
{
	srand(time(NULL));
	int n = 5000;
	srand(time(NULL));
	int** arr1 = new int*[n];
	int** arr2 = new int*[n];
	for (int i = 0;i < n;++i)
	{
		arr1[i] = new int[n];
		arr2[i] = new int[n];
	}
	int** res1 = new int*[n];
	int** res2 = new int*[n];
	for (int i = 0;i < n;++i)
	{
		res1[i] = new int[n];
		res2[i] = new int[n];
	}
	for (int i = 0;i < n;++i)
	{
		for (int j = 0;j < n;++j)
		{
			arr1[i][j] = rand() % 100;
			arr2[i][j] = rand() % 100;
		}
	}
	int numberOfThreads = 10;
	thread* arr = new thread[numberOfThreads];
	int from = 0;
	int step = n/numberOfThreads;
	int to = step;
	clock_t start_time = clock();
	for (int i = 0;i < numberOfThreads;++i)
	{
		arr[i] = thread(summing,arr1, arr2, res1, from, to, n);
		arr[i].join();
		from += step ;
		to += step ;
	}
	cout <<"summing time for n=5000  and numberof threads="<<numberOfThreads<<" "<<  (float)clock() - start_time << endl;
	/*for (int i = 0;i < n;++i)
	{
		for (int j = 0;j < n;++j)
		{
			cout << res1[i][j] << " ";
		}
		cout << endl;
	}*/

	/* start_time = clock();
	for (int i = 0;i < numberOfThreads;++i)
	{
		arr[i] = thread(subtraction, arr1, arr2, res1, from, to, n);
		arr[i].join();
		from += step;
		to += step;
	}
	
	

		cout << (float)clock() - start_time << endl;*/



		
	
	system("pause");
}

#include<iostream>
using namespace std;
int red_count = 0;
int sumall(int** map, int N)
{
	int sum = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++) sum += map[i][j];
	}
	return sum;
}
int cutting(int** map, int N)
{
	if (sumall(map, N) == N * N)
	{
		return 1; 
	}
	else if (sumall(map, N) == 0) { red_count++; return 0; }
	else
	{
		int ***newmap = new int**[4];
		for (int dim = 0; dim < 4; dim++)
		{
			newmap[dim] = new int*[N / 2];
			for (int i = 0; i < N / 2; i++)
			{
				newmap[dim][i] = new int[N / 2];
			}
		}
		for (int dim = 0; dim < 4; dim++) {
			for (int i = 0; i < N / 2; i++)
			{
				for (int j = 0; j < N / 2; j++)
				{
					switch (dim)
					{
					case 0:
						newmap[dim][i][j] = map[i][j];
						break;
					case 1:
						newmap[dim][i][j] = map[i+N/2][j];
						break;
					case 2:
						newmap[dim][i][j] = map[i][j+N/2];
						break;
					case 3:
						newmap[dim][i][j] = map[i+N/2][j+N/2];
						break;
					}
				}
			}
		}
		return cutting(newmap[0], N / 2) + cutting(newmap[1], N / 2) + cutting(newmap[2], N / 2) + cutting(newmap[3], N / 2);
	}
}

int main()
{
	int N;
	cin >> N;
	int **map = new int*[N];
	for (int i = 0; i < N; i++)
	{
		map[i] = new int[N];
		for (int j = 0; j < N; j++) cin >> map[i][j];
	}
	int b = cutting(map, N);
	
	cout << red_count << "\n" << b << endl;
	for (int i = 0; i < N; i++)
	{
		delete[] map[i];
	}
	delete[] map;
	return 0;
}

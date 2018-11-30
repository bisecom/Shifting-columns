
// Program / function to shift columns
#include <iostream>
#include <ctime>
using namespace std;

void shift_column(int **arr, int row, int column);

int main()
{
	srand(time(0));
	int row, column;
	cout << "Lets create an array and shift columns..." << endl;
	cout << "Input quantity of row for the array:" << endl;
	cin >> row;
	cout << "Input quantity of columns for the array:" << endl;
	cin >> column;

	int **arr = new int *[column];
	for (int i = 0; i < row; i++)
		arr[i] = new int[column];

	for (int i = 0; i < row; i++)
		for (int j = 0; j < column; j++)
		{
			arr[i][j] = rand() % 10 + 1;
		}

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < column; j++)
		{
			cout << arr[i][j] << "\t";
		}
		cout << endl;
	}

	shift_column(arr, row, column);

	for (int i = 0; i < row; i++)
		delete[]arr[i];
	delete[] arr;

	return 0;
}

void shift_column(int **arr, int row, int column)
{
	char direction;
	int n;
	int **new_arr = new int *[row];
	for (int i = 0; i < row; i++)
		new_arr[i] = new int[column];

	cout << "Lets shift the columns.." << endl;
	cout << "Input number of times you wish to shift the columns:" << endl;
	cin >> n;
	cout << "Input direction of the shift - /r/ - to the right, /l/ - to the left:" << endl;
	for (;;)
	{
		cin >> direction;
		if (direction == 'r' || direction == 'l') break;
		else
			cout << "Pls, choose correct direction to shift.." << endl;
	}
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < column; j++)

			if (direction == 'l')
				//*******Shift to left
			{
				if ((j + n)<column) new_arr[i][j] = arr[i][j + n];
				if ((j + n) >= column) new_arr[i][j] = arr[i][j + n - column];
			}
		//*******
			else
				//*******Shift to right
			{
				if ((j + column - n)<column) new_arr[i][j] = arr[i][j + column - n];
				if ((j + column - n) >= column) new_arr[i][j] = arr[i][j - n];
			}
		//*******
	}
	//print new arr
	cout << "\nResulting array:" << endl;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < column; j++)
		{
			cout << new_arr[i][j] << "\t";
		}
		cout << endl;
	}
	cout << endl;

	for (int i = 0; i < row; i++)
		delete[]new_arr[i];
	delete[] new_arr;
}
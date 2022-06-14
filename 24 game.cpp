#include <iostream>
#include <cmath>
#include <cstdlib>

using namespace std;

const int SUM = 24, BOUND = 1e-3;

int operate(double left, int op, double right);
bool permOperate(double n[], int ops[]);
void swap(double n[], int indexa, int indexb);
void permNum(double n[], int l, int r, int ops[], bool & state);

int main()
{
	bool state = false;
	double n[4] = {0};
	cout << "Enter four integers between 1 and 13: ";
	cin >> n[0] >> n[1] >> n[2] >> n[3];
	int ops[3] = {-1};
	permNum(n, 0, 3, ops, state);
	cout << "Numbers: " << n[0] << ", " << n[1] << ", " << n[2] << ", " << n[3] << endl;
	cout << "Operators: " << ops[0] << ", " << ops[1] << ", " << ops[2];
}

int operate(double left, int op, double right)
{
	if (op == 1)
	{
		return left + right;
	}
	else if (op == 2)
	{
		return left - right;
	}
	else if (op == 3)
	{
		return left * right;
	}
	else
	{
		return (double)left/right;
	}
}

bool permOperate(double n[], int ops[])
{
	for(int i = 1; i <= 4; i++)
	{
		for(int j = 1; j <= 4; j++)
		{
			for(int k = 1; k <= 4; k++)
			{
				if (abs(operate(operate(operate(n[0], i, n[1]), j, n[2]), k, n[3]) - SUM) < BOUND)
				{
					ops[0] = i;
					ops[1] = j;
					ops[2] = k;
					return true;
				}
			}
		}
	}
	return false;
}

void swap(double n[], int indexa, int indexb)
{
	double temp = n[indexa];
	n[indexa] = n[indexb];
	n[indexb] = temp;
}

void permNum(double n[], int l, int r, int ops[], bool & state)
{
	if (l == r)
		state = permOperate(n, ops);
	else
	{
		for(int trans = 0; l+trans <= r && state == false; trans++)
		{
			swap(n, l, l+trans);
			permNum(n, l+1, r, ops, state);
			if (state == false)
				swap(n, l, l+trans);
		}
	}
}
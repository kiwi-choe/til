#include <stdio.h>

typedef unsigned long ULONG;

typedef struct Matrix2X2
{
	ULONG Data[2][2];
} Matrix2X2;

Matrix2X2 Matrix2X2_Multiply(Matrix2X2 A, Matrix2X2 B)
{
	Matrix2X2 C;

	C.Data[0][0] = A.Data[0][0]*B.Data[0][0] + A.Data[0][1]*B.Data[1][0];
	C.Data[0][1] = A.Data[0][0]*B.Data[1][0] + A.Data[0][1]*B.Data[1][1];

	C.Data[1][0] = A.Data[1][0]*B.Data[0][0] + A.Data[1][1]*B.Data[1][0];
	C.Data[1][1] = A.Data[1][0]*B.Data[1][0] + A.Data[1][1]*B.Data[1][1];

	return C;
}

Matrix2X2 Matrix2X2_Power(Matrix2X2 A, int n)
{
	if(n>1)
	{
		A = Matrix2X2_Power(A, n/2);
		A = Matrix2X2_Multiply(A, A);

		if(n & 1)	// if odd, multiply a matrix
		{
			Matrix2X2 B;
			B.Data[0][0] = 1;
			B.Data[0][1] = 1;
			B.Data[1][0] = 1;
			B.Data[1][1] = 0;

			A = Matrix2X2_Multiply(A, B);
		}
	}

	return A;
}

ULONG Fibonacci(int N)
{
	Matrix2X2 A;

	// Initialize Matrix A
	A.Data[0][0] = 1;
	A.Data[0][1] = 1;
	A.Data[1][0] = 1;
	A.Data[1][1] = 0;

	A = Matrix2X2_Power(A, N);

	// return Fn
	return A.Data[0][1];
}

int main()
{
	int N = 46;
	ULONG result = Fibonacci(N);

	printf("Fibonacci(%d) = %lu \n", N, result);

	return 0;
}
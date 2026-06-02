#include <iostream>
#include <vector>
#include "Neuron.h"
#include "Layer.h"
using namespace std;

int main()
{
	//Matrix A = Matrix(2, 2);
	//A.values[0][0] = 1.0;
	//A.values[0][1] = 2.0;
	//A.values[1][0] = 3.0;
	//A.values[1][1] = 4.0;
	//Matrix B = Matrix(2, 2);
	//B.values[0][0] = 5.0;
	//B.values[0][1] = 6.0;
	//B.values[1][0] = 7.0;
	//B.values[1][1] = 8.0;
	//Matrix C = Matrix(2, 2, 0);
	//C.GetFromMultiplication(&A, &B);
	//A.Out();
	//B.Out();
	//C.Out();// 19 22 // 43 50
	Layer(3, 3, 2, 1.0);
}
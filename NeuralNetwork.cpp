#include <iostream>
#include "NeuralNetwork.h"
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
	//Layer(3, 3, 2, 1.0, Neuron::activationFunctionTypes::LogisticSigmoid);

	size_t layers = 2;
	size_t* layersSize = new size_t[layers];
	layersSize[0] = 3;
	layersSize[1] = 1;
	Neuron::activationFunctionTypes* layersActivationFunctions = new Neuron::activationFunctionTypes[layers];
	layersActivationFunctions[0] = Neuron::activationFunctionTypes::Identity;
	layersActivationFunctions[1] = Neuron::activationFunctionTypes::Softsign;
	double* weightsDefaultValues = new double[layers];
	weightsDefaultValues[0] = 1.0;
	weightsDefaultValues[1] = 1.0;//Рандомить, если будет передано -1?

	NeuralNetwork nn = NeuralNetwork(layers, layersSize, layersActivationFunctions, weightsDefaultValues);
	nn.ProcessLayers();
	
	size_t teachIterations = 1000;
	for (size_t i = 0; i < teachIterations; i++)
	{
		nn.Input();
		nn.ProcessLayers();
		nn.Teach();
	}
	nn.Out();

	delete[]layersSize;
	delete[]layersActivationFunctions;
	delete[]weightsDefaultValues;
	return 0;
}
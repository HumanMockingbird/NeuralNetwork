#pragma once
#include "Neuron.h"
#include "Matrix.h"

class Layer
{
public:
	Layer(size_t neuronsAmount, size_t weightsMatrixRows, size_t weightsMatrixCols, double weightsDefaultValue)
	{
		this->neuronsAmount = neuronsAmount;
		neuronsVector = new Neuron[neuronsAmount];
		for (size_t i = 0; i < neuronsAmount; i++)
		{
			neuronsVector[i] = Neuron(0.0, Neuron::activationFunctionTypes::Identity);
		}

		this->weightsMatrix = Matrix(weightsMatrixRows, weightsMatrixCols, weightsDefaultValue);
		this->weightsMatrix.Out();
	}
	~Layer()
	{
		delete[] neuronsVector;
	}

	size_t neuronsAmount;

	Neuron* neuronsVector;
	Matrix* weightsMatrix;
};
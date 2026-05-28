#pragma once
#include "Neuron.h"
#include "Matrix.h"

class Layer
{
public:
	Neuron* neuronsVector;
	Matrix* weigthsMatrix;
};
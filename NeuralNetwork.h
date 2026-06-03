#pragma once
#include "Layer.h"
class NeuralNetwork
{
public:
	NeuralNetwork()
	{
		std::cout << "Called standard NN constructor!" << std::endl;
	}
	NeuralNetwork(size_t layers, size_t* layersNeuronsAmount, Neuron::activationFunctionTypes* layersActivationFunctionTypes, double* weightsDefaultValue)
	{
		std::cout << "Created NN:" << std::endl;
		for (size_t layerIndex = 0; layerIndex < layers; layerIndex++)
		{
			std::cout << "layer " << layerIndex << ": n(" << layersNeuronsAmount[layerIndex] << "), f(" << layersActivationFunctionTypes[layerIndex] << "), w[" << "_" << "x" << layersNeuronsAmount[layerIndex] << "]" << std::endl;
		}
	}
	~NeuralNetwork()
	{
		std::cout << "Deleted NN!" << std::endl;
	}

	Layer *NeuronLayers;

	void ProcessLayers()
	{
		//TODO
	}

	void Teach(double* target, double weightDelta = 0.01)
	{
		//TODO
	}
};


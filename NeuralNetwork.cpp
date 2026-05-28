#include <iostream>
#include <vector>
#include "Neuron.h"
using namespace std;

int main()
{
	Neuron n;
	cin >> n.value;
	n.activationFunction(Neuron::activationFunctionTypes::HyperbolicTangent, 1);
	cout << n.actValue;
}
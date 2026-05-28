#pragma once
#include <cmath>
#include <iostream>

class Neuron
{
public:

	double value, actValue;
	enum activationFunctionTypes
	{
		Identity = 0,
		BinaryStep = 1,
		LogisticSigmoid = 2,
		HyperbolicTangent = 3,
		SobolevaModifiedHyperbolicTangent = 4,
		Softsign = 5,
		ReLU = 6,
		GELU = 7,
		Softplus = 8,
		ELU = 9,
		SELU = 10,
		LeakyReLU = 11,
		PReLU = 12,
		xxx = 13,
		SiLU = 14,
		ELiSH = 15,
		Gaussian = 16,
		Sinusoid = 17
	};
	void activationFunction(activationFunctionTypes type = LogisticSigmoid, double alpha = 1)
	{
		double v = this->value;
		switch (type)
		{
		case Identity:
			this->actValue = v;
			break;

		case BinaryStep:
			if (v < 0)
				this->actValue = 0;
			else
				this->actValue = 1;
			break;

		case LogisticSigmoid:
			this->actValue = 1 / (1 + exp(-v));
			break;

		case HyperbolicTangent:
			this->actValue = (exp(v) - exp(-v)) / (exp(v) + exp(-v));
			break;

			/*case SobolevaModifiedHyperbolicTangent:
				return 0;*/

		case Softsign:
			this->actValue = v / (1 + abs(v));
			break;

		case ReLU:
			if (v <= 0)
				this->actValue = 0;
			else
				this->actValue = v;
			break;

			/*case GELU:
				return 0;*/

		case Softplus:
			this->actValue = log(1 + exp(v));
			break;

		case ELU:
			if (v <= 0)
				this->actValue = alpha * (exp(v) - 1);
			else
				this->actValue = v;
			break;

			/*
			case SELU:
				if (v < 0)
					return alpha*(exp(v)-1);
				else
					return v;
			*/

		case LeakyReLU:
			if (v <= 0)
				this->actValue = 0.01 * v;
			else
				this->actValue = v;
			break;

		case PReLU:
			if (v < 0)
				this->actValue = alpha * v;
			else
				this->actValue = v;
			break;

			//case 13:// Rectified Parametric Sigmoid Units (flexible, 5 parameters)
			//	return 0;

		case SiLU:
			this->actValue = 1 + exp(-v);
			break;

		case ELiSH:
			if (v < 0)
				this->actValue = (exp(v) - 1) / (1 + exp(-v));
			else
				this->actValue = v / (1 + exp(-v));
			break;

		case Gaussian:
			this->actValue = exp(-pow(v, 2.0));
			break;

		case Sinusoid:
			this->actValue = sin(v);
			break;

		default:
			std::cout << "[ERROR] Не найдена указанная функция активации!" << std::endl;
		}
	}
};
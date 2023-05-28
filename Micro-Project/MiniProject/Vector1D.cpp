#include "Vector1D.h"

Vector1D::Vector1D()
{
	size = 0;
	data = new int[size];
}

Vector1D::Vector1D(size_t size) : size(size)
{
	data = new int[size];
}

Vector1D::Vector1D(const Vector1D& other) : size(other.size)
{
	data = new int[size];
	std::copy_n(other.data, size, data);
}

Vector1D::~Vector1D()
{
	delete[] data;
}

void Vector1D::SetIndexValue(int index, int value)
{
	if (index > size - 1)
		return;
	data[index] = value;
}

int Vector1D::GetIndexValue(int index)
{
	if (index > size - 1)
	{	
		std::cout << "Out of vector range" << std::endl;
		exit(0);
	}

	std::cout << "Value:  " << data[index] << " under index " << index << std::endl;
	return data[index];
}

int Vector1D::Norm()
{
	if(size <= 0)
	{	
		std::cout << "Vector without content" << std::endl;
		exit(0);
	}

	int norm = 0;

	for (size_t i = 0; i < size; i++)
	{
		norm += data[i] * data[i];
	}

	std::cout << "Normalised value is: " << norm << std::endl;
	return norm;
}

int Vector1D::Average()
{
	if (size <= 0)
	{
		std::cout << "Vector without content" << std::endl;
		exit(0);
	}

	int avg = 0;
	int divider = size;

	for (size_t i = 0; i < size; i++)
	{
		avg += data[i];
	}

	avg /= divider;
	std::cout << "Average value is: " << avg << std::endl;
	return avg;
}

int Vector1D::Min()
{
	if (size <= 0)
	{
		std::cout << "Vector without content" << std::endl;
		exit(0);
	}

	int min = data[0];

	for (size_t i = 0; i < size; i++) 
	{
		if (data[i] < min) {
			min = data[i];
		}
	}

	std::cout << "Min value is: " << min << std::endl;
	return min;
}

int Vector1D::Max()
{
	if (size <= 0)
	{
		std::cout << "Vector without content" << std::endl;
		exit(0);
	}

	int max = data[0];

	for (size_t i = 0; i < size; i++) 
	{
		if (data[i] > max) {
			max = data[i];
		}
	}

	std::cout << "Max value is: " << max << std::endl;
	return max;
}

Vector1D& Vector1D::Sort()
{
	Vector1D temp(size);
	std::sort(data, data + size);
	temp = *this;
	return temp;
}

bool Vector1D::LinearSearch(int wanted)
{
	for (size_t i = 0; i < size; i++)
		if (data[i] == wanted)
			return true;
}

bool Vector1D::HalfPartSearch(int wanted)
{
	this->Sort();

	int left = 0;
	int right = size - 1;
	int middle;
	while (true)
	{
		if (left > right)
		{
			std::cout << "Not element found" << std::endl;
			break;
		}
		middle = (left + right) / 2;
		if (data[middle] == wanted)
		{
			std::cout << "Value found " << wanted << " under index " << middle + 1 << std::endl;
			return true;
		}
		else if (data[middle] < wanted)
			left = middle + 1;
		else
			right = middle - 1;
	}
}
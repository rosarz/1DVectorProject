#pragma once
#include <iostream>
#include <algorithm>

class Vector1D
{
public:
	Vector1D();
	Vector1D(size_t size);
	Vector1D(const Vector1D& other);
	~Vector1D();

	void SetIndexValue(int index, int value);
	int GetIndexValue(int index);

	int Norm();
	int Average();
	int Min();
	int Max();
	Vector1D& Sort();
	bool LinearSearch(int wanted);
	bool HalfPartSearch(int wanted);

	Vector1D operator+(const Vector1D& other)
	{
		if (this->size != other.size)
		{
			std::cout << "Two various vector sizes" << std::endl;
			exit(0);
		}

		Vector1D temp(size);

		for (size_t i = 0; i < size; i++)
		{
			temp.data[i] = this->data[i] + other.data[i];
		}
		return temp;
	}

	Vector1D operator-(const Vector1D& other)
	{
		if (this->size != other.size)
		{
			std::cout << "Two various vector sizes" << std::endl;
			exit(0);
		}

		Vector1D temp(size);

		for (size_t i = 0; i < size; i++)
		{
			temp.data[i] = this->data[i] - other.data[i];
		}
		return temp;
	}

	Vector1D operator*(const Vector1D& other)
	{
		if (this->size != other.size)
		{
			std::cout << "Two various vector sizes" << std::endl;
			exit(0);
		}

		Vector1D temp(size);

		for (size_t i = 0; i < size; i++)
		{
			temp.data[i] = this->data[i] * other.data[i];
		}
		return temp;
	}

	Vector1D operator*(const int number)
	{
		Vector1D temp(size);

		for (size_t i = 0; i < size; i++)
		{
			temp.data[i] = this->data[i] * number;
		}
		return temp;
	} 
	
	Vector1D& operator=(const Vector1D& other)
	{
		if (this->size != other.size)
		{
			std::cout << "Two various vector sizes" << std::endl;
			exit(0);
		}

		for (size_t i = 0; i < size; i++)
		{
			data[i] = other.data[i];
		}
		return *this;
	}

	inline Vector1D& operator+=(const Vector1D& other)
	{
		*this = *this + other;
		return *this;
	}

	inline Vector1D& operator-=(const Vector1D& other)
	{
		*this = *this - other;
		return *this;
	}

	inline Vector1D& operator*=(const Vector1D& other)
	{
		*this = *this * other;
		return *this;
	}

private:
	int* data;
	size_t size;
};
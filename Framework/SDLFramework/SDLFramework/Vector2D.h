#pragma once
#include <io.h>
#include <iostream>
class Vector2D
{

private:
	float x;
	float y;
public:
	Vector2D(){};
	~Vector2D(){};



	Vector2D(float x, float y){ this->x = x; this->y = y; };

	float getX(){ return x; }
	float getY(){ return y; }

	bool operator < (const Vector2D* vector) const
	{
		return (x < vector->x);
	}

	bool operator >(const Vector2D* vector) const
	{
		return (x > vector->x);
	}

	Vector2D operator +(const Vector2D& vector) const
	{
		Vector2D vec;
		vec.x = x + vector.x;
		vec.y = y + vector.y;
		return vec;
	}
	Vector2D operator -(const Vector2D& vector) const
	{
		Vector2D vec;
		vec.x = x - vector.x;
		vec.y = y - vector.y;
		return vec;
	}

	Vector2D operator *(const Vector2D& vector) const{
		Vector2D vec;
		vec.x = x * vector.x + x * vector.y;
		vec.y = y * vector.x + y * vector.y;
		return vec;
	}


	void print()
	{
		std::cout << "vector x: " << x << " vector y: " << y << std::endl;
	}
};


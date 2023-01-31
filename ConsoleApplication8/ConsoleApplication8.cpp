#define _USE_MATH_DEFINES
#include <math.h>
#include <iostream>
#include<cstdlib>
using namespace std;


class Solid {
public:
	virtual double GetVolume() = 0;
	virtual double GetSurface() = 0;
};

class Box :public Solid {
private:
	double width;
	double height;
	double depth;

public:
	Box(
		double width,   
		double height,  
		double depth    
	) :Solid() {
		this->width = width;
		this->height = height;
		this->depth = depth;
	}
	double GetVolume() {
		return width * height * depth;
	}
	double GetSurface() {
		return (width * height + height * depth + depth * width) * 2;
	}
	double GetWidth() {
		return this->width;
	}
	double GetHeight() {
		return this->height;
	}
	double GetDepth() {
		return this->depth;
	}
};

class Cylinder :public Solid {
private:
	double radius;
	double height;
public:
	Cylinder(
		double radius,  
		double height   
	) :Solid() {
		this->radius = radius;
		this->height = height;
	}
	double GetVolume() {
		return radius * radius * M_PI * height;
	}
	double GetSurface() {
		return radius * M_PI * 2 * (radius + height);
	}
	double GetRadius() {
		return this->radius;
	}
	double GetHeight() {
		return this->height;
	}
};

class Cone :public Solid {
private:
	double radius;
	double height;
public:
	Cone(
		double radius,  
		double height   
	) :Solid() {
		this->radius = radius;
		this->height = height;
	}
	double GetVolume() {
		return radius * radius * M_PI * height / 3.0;
	}
	double GetSurface() {
		return M_PI * radius * (radius + sqrt(radius * radius + height * height));
	}
	double GetRadius() {
		return this->radius;
	}
	double GetHeight() {
		return this->height;
	}
};

class Sphere :public Solid {
private:
	double radius;
public:
	Sphere(
		double radius  
	) :Solid() {
		this->radius = radius;
	}
	double GetVolume() {
		return  M_PI * radius * radius * radius * 4 / 3;
	}
	double GetSurface() {
		return M_PI * radius * radius * 4;
	}
	double GetRadius() {
		return this->radius;
	}
};

void DisplayVolumeSurface(Solid* solid) {
	cout << "体積=" << solid->GetVolume() << endl;
	cout << "表面積=" << solid->GetSurface() << endl;
}
int main()
{
	Box box{ 80.0, 120, 0.1 };
	Cylinder cylinder{ 30, 10 };
	Cone cone{ 30, 10 };
	Sphere sphere{ 20 };
	const int N_TABLE = 4;
	Solid* solid[N_TABLE] = { &box, &cylinder,&cone,&sphere };
	for (int i = 0; i < N_TABLE; i++) {
		DisplayVolumeSurface(solid[i]);
	}
	int kuronekoSize[] = { 60,80,100,120,140,160,180,200 };
	int i;
	double length;

	length = box.GetWidth() + box.GetHeight() + box.GetDepth();

	for (i = 0; i < _countof(kuronekoSize); i++) {
		if (length <= kuronekoSize[i]) {
			break;
		}
	}
	if (i < _countof(kuronekoSize)) {
		cout << "箱のサイズは" << kuronekoSize[i] << "サイズです" << endl;
	}
	else {
		cout << "この箱は宅急便では送れません" << endl;
	}

	length = cylinder.GetRadius() * 4 + cylinder.GetHeight();
	for (i = 0; i < _countof(kuronekoSize); i++) {
		if (length <= kuronekoSize[i]) {
			break;
		}
	}
	if (i < _countof(kuronekoSize)) {
		cout << "円柱のサイズは" << kuronekoSize[i] << "サイズです" << endl;
	}
	else {
		cout << "この円柱は宅急便では送れません" << endl;
	}

	length = cone.GetRadius() * 4 + cone.GetHeight();
	for (i = 0; i < _countof(kuronekoSize); i++) {
		if (length <= kuronekoSize[i]) {
			break;
		}
	}
	if (i < _countof(kuronekoSize)) {
		cout << "円錐のサイズは" << kuronekoSize[i] << "サイズです" << endl;
	}
	else {
		cout << "この円錐は宅急便では送れません" << endl;
	}

	length = sphere.GetRadius() * 6;
	for (i = 0; i < _countof(kuronekoSize); i++) {
		if (length <= kuronekoSize[i]) {
			break;
		}
	}
	if (i < _countof(kuronekoSize)) {
		cout << "球のサイズは" << kuronekoSize[i] << "サイズです" << endl;
	}
	else {
		cout << "この球は宅急便では送れません" << endl;
	}
}
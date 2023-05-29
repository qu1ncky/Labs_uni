#include "TVector.h"
#include <iostream>

TVector::TVector(int size): size(size) {
    data = new double[size];
}

TVector::TVector(const TVector& other): size(other.size) {
    data = new double[size];
    for (int i = 0; i < size; i++) {
        data[i] = other.data[i];
    }
}

TVector::TVector(int n, double* p)
{
    size = n;
    data = new double[size];
    for (int i = 0; i < size; ++i) {
        data[i] = p[i];
    }
}

TVector::~TVector() {
    delete[] data;
}

void TVector::input() {
    std::cout << "Enter vector values:\n";
    for (int i = 0; i < size; i++) {
        std::cin >> data[i];
    }
}

void TVector::output() const {
    std::cout << "(";
    for (int i = 0; i < size-1; i++) {
        std::cout << data[i] << ", ";
    }
    std::cout << data[size-1] << ")\n";
}

TVector TVector::operator+(const TVector& other) const {
    if (size != other.size) {
        throw "Vectors should have the same size!";
    }
    TVector result(size);
    for (int i = 0; i < size; i++) {
        result.data[i] = data[i] + other.data[i];
    }
    return result;
}

TVector TVector::operator*(double num) const {
    TVector result(size);
    for (int i = 0; i < size; i++) {
        result.data[i] = data[i] * num;
    }
    return result;
}

double operator*(const TVector& v1, const TVector& v2) {
    if (v1.size != v2.size) {
        throw "Vectors should have the same size!";
    }
    double result = 0;
    for (int i = 0; i < v1.size; i++) {
        result += v1.data[i] * v2.data[i];
    }
    return result;
}

TVector operator*(double num, const TVector& vec) {
    return vec*num;
}

TVector& TVector::operator++() {
    for (int i = 0; i < size; i++) {
        data[i]++;
    }
    return *this;
}

TVector TVector::operator++(int) {
    TVector temp(*this);
    ++(*this);
    return temp;
}

TVector& TVector::operator--() {
    for (int i = 0; i < size; i++) {
        data[i]--;
    }
    return *this;
}

TVector TVector::operator--(int) {
    TVector temp(*this);
    --(*this);
    return temp;
}

bool TVector::operator==(const TVector& other) const {
    if (size != other.size) {
        return false;
    }
    for (int i = 0; i < size; i++) {
        if (data[i] != other.data[i]) {
            return false;
        }
    }
    return true;
}

bool TVector::operator!=(const TVector& other) const {
    return !(*this == other);
}

double& TVector::operator[](int index) {
    if (index < 0 || index >= size) {
        throw "Index is out of range!";
    }
    return data[index];
}

const double& TVector::operator[](int index) const {
    if (index < 0 || index >= size) {
        throw "Index is out of range!";
    }
    return data[index];
}
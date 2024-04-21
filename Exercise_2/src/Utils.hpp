#pragma once
#include <iostream>

using namespace std;

bool ImportValues(const string& inputFile, double& S, size_t& n, double*& w, double*& r);

double RateOfReturn(size_t& n, double*& w, double*& r);

double finalValue(double& S, double& rateOfReturn);

bool ExportResult(const string& outputFile, double& S, const size_t& n, double*& w, double*& r, double& rateOfReturn, double& V);

string ArrayToString(const size_t& n, const double* const& v);

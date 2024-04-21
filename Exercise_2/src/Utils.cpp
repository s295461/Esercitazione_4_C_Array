#include "Utils.hpp"

#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>

using namespace std;

bool ImportValues(const string& inputFile, double& S, size_t& n, double*& w, double*& r)
{
    ifstream file;
    file.open(inputFile);

    if(file.fail())
    {
        cerr << "Error opening the file" << endl;
        return false;
    }

    string line;
    getline(file, line, ';'); // Leggo ciò che c'è prima del ";" e lo ignoro
    getline(file, line); // Leggo ciò che c'è dopo il ";"

    istringstream convertS;
    convertS.str(line);
    convertS >> S;


    getline(file, line, ';'); // Leggo ciò che c'è prima del ";" e lo ignoro
    getline(file, line); // Leggo ciò che c'è dopo il ";"

    istringstream convertN;
    convertN.str(line);
    convertN >> n;


    getline(file, line); // Ignoro la terza riga del file


    w = new double[n];
    r = new double[n];


    for(unsigned int i = 0; i<n; i++)
    {
        getline(file, line, ';'); // Leggo ciò che c'è prima di ";" e lo salvo in w
        istringstream convertW;
        convertW.str(line);
        convertW >> w[i];

        getline(file, line); // Leggo ciò che c'è dopo il ";" e lo salvo in r
        istringstream convertR;
        convertR.str(line);
        convertR >> r[i];
    }

    file.close();

    return true;
}


double RateOfReturn(size_t& n, double*& w, double*& r)
{
    double rateOfReturn = 0;
    for(unsigned int i = 0; i<n; i++)
    {
        rateOfReturn += w[i] * r[i];
    }
    return rateOfReturn;
}


double finalValue(double& S, double& rateOfReturn)
{
    double V = (1 + rateOfReturn) * S;
    return V;
}


bool ExportResult(const string& outputFile, double& S, const size_t& n, double*& w, double*& r, double& rateOfReturn, double& V)
{
    ofstream file;
    file.open(outputFile);

    if(file.fail())
    {
        cerr << "Error opening the file" << endl;
        return false;
    }

    file << "S = " << fixed << setprecision(2) << S;
    file << ", n = " << n << endl;

    file << "w = [ ";
    for(unsigned int i = 0; i<n; i++)
        file << defaultfloat << w[i] << " ";
    file << "]"  << endl;

    file << "r = [ ";
    for(unsigned int i = 0; i<n; i++)
        file << defaultfloat << r[i] << " ";
    file << "]"  << endl;

    file << "Rate of return of the portfolio: " << setprecision(4) << rateOfReturn << endl;

    file << "V: " << fixed << setprecision(2) << V << endl;

    file.close();

    return true;
}


string ArrayToString(const size_t& n, const double* const& v)
{
    string str;
    ostringstream toString;
    toString << "[";
    for (unsigned int i = 0; i<n; i++)
        toString << v[i] << " ";
    toString << "]";

    return toString.str();
}

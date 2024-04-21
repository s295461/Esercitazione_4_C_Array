#include <iostream>
#include <fstream>
#include <sstream>
#include "Utils.hpp"
#include <iomanip>

using namespace std;


int main()
{
    string inputFileName = "data.csv";
    double S = 0;
    size_t n  = 0;
    double* w = nullptr;
    double* r = nullptr;

    if(!ImportValues(inputFileName, S, n, w,r))
    {
        cerr << "Something wrong with import" << endl;
        return -1;
    }
    else
        cout << "Import successful: S = " << fixed << setprecision(2) << S << " n= " << n << " w= " << ArrayToString(n,w) << " r= " << ArrayToString(n, r) << endl;


    double rateOfReturn = RateOfReturn(n, w, r);
    cout << "Rate of return of the portfolio= " << setprecision(4) << rateOfReturn << endl;


    double V = finalValue(S, rateOfReturn);
    cout << "V= " << fixed << setprecision(2) << V << endl;


    string outputFileName = "result.txt";
    if(!ExportResult(outputFileName, S, n, w, r, rateOfReturn, V))
    {
        cerr << "Something wrong with export" << endl;
        return -1;
    }
    else
        cout << "Export successful" << endl;


    delete [] w;
    delete [] r;

    return 0;
}


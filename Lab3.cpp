#include "TestPoly.h"
#include <iostream>
using namespace std;

int main()
{

    
	int max_degree = 1000;
	double max_coeff = 100;
	int max_eval_degree = 20;
	double max_eval_coeff = 10;
	int max_run = 5;
	vector<int> max_size_array = { 1, 5, 10 };

    double fullMark = 0;
    double totalMark = 0;

	TestPoly tp(max_degree, max_coeff, max_eval_degree, max_eval_coeff, max_run, max_size_array);

    tp.testConstructorDefault(totalMark, fullMark);       // working
    tp.testConstructorParameters(totalMark, fullMark);    // working
    tp.testAddMono(totalMark, fullMark);                  // working
    tp.testAddPoly(totalMark, fullMark);                  // working
    tp.testMultiplyMono(totalMark, fullMark);             // working
    tp.testMultiplyPoly(totalMark, fullMark);             // working
    tp.testDuplicate(totalMark, fullMark);                // working
    tp.testEvaluate(totalMark, fullMark);                 // working

    cout << "********************************" << endl;
    cout << "*** FINAL TOTAL MARK IS " << totalMark << "/" << fullMark << " ***" << endl;
    cout << "********************************" << endl;

    
}

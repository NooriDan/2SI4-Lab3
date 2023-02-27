#include "TestPoly.h"
#include <iostream>
using namespace std;

int main()
{

    /*
    cout << "started the custom test" << endl;
    vector<int> deg1;
    vector<double> cof1;

    deg1.push_back(300);
    cof1.push_back(1);

    deg1.push_back(1);
    cof1.push_back(2);  

    deg1.push_back(0);
    cof1.push_back(-2);
    cout << "deg1 and coef set" << endl;

    Poly p1(deg1, cof1);

    cout << "size = " << p1.getTermsNo() << " Deg = " << p1.getDegree() << endl;
    cout << "poly1 =\n" << p1.toString() << endl;

    cout << "******\nevaluating poly1:\n" << endl;

    int x = 1;
    cout << "x=" << x << " p(x) = " << p1.evaluate(x) << endl;

    x = 2;
    cout << "x=" << x << " p(x) = " << p1.evaluate(x) << endl;

    x = 0;
    cout << "x=" << x << " p(x) = " << p1.evaluate(x) << endl;

    x = 5;
    cout << "x=" << x << " p(x) = " << p1.evaluate(x) << endl;
    */
    

    
	int max_degree = 1000;
	double max_coeff = 100;
	int max_eval_degree = 20;
	double max_eval_coeff = 10;
	int max_run = 50;
	vector<int> max_size_array = { 1, 5, 10 };

    double fullMark = 0;
    double totalMark = 0;

	TestPoly tp(max_degree, max_coeff, max_eval_degree, max_eval_coeff, max_run, max_size_array);

    //tp.testConstructorDefault(totalMark, fullMark);       // working
    //tp.testConstructorParameters(totalMark, fullMark);    // working
    //tp.testAddMono(totalMark, fullMark);                  // working
    //tp.testAddPoly(totalMark, fullMark);                  // debugging
    //tp.testMultiplyMono(totalMark, fullMark);             // working
    //tp.testMultiplyPoly(totalMark, fullMark);             // debugging
    //tp.testDuplicate(totalMark, fullMark);                // working
    //tp.testEvaluate(totalMark, fullMark);                 // working

    cout << "********************************" << endl;
    cout << "*** FINAL TOTAL MARK IS " << totalMark << "/" << fullMark << " ***" << endl;
    cout << "********************************" << endl;

    
}

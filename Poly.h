#ifndef POLY_H_
#define POLY_H_

#include "PolyNode.h"
#include <vector>
#include <string>

class Poly
{
private:
	// must contain this private field, and you can define other private fields
	PolyNode* head = NULL;
	int polyDegree;
	int numOfterms;

	//private methods;
	void insertAfter(PolyNode* nodeBefore, PolyNode* target);
	void removeAfter(PolyNode* n);
	int hasDeg(int degree);


public:
	Poly();
	Poly(int i, double c);
	Poly(const std::vector<int>& deg, const std::vector<double>& coeff);
	~Poly();

	void addMono(int i, double c);
	void addPoly(const Poly& p);
	void multiplyMono(int i, double c);
	void multiplyPoly(const Poly& p);
	void duplicate(Poly& outputPoly);
	int getDegree();
	int getTermsNo();
	double evaluate(double x);
	std::string toString();

	// used for testing
	PolyNode* getHead() {
		return head;
	};
};

#endif /* POLY_H_ */

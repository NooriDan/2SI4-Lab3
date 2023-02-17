#include "Poly.h"
using namespace std;

Poly::Poly()
{
	head = new PolyNode(-1, 0, NULL); // intiate the dummy header
	numOfterms = 0;
	polyDegree = -1;
}

Poly::Poly(const std::vector<int>& deg, const std::vector<double>& coeff)
{
	head = new PolyNode(-1, 0, NULL); // intiate the dummy header
	PolyNode* reader = head;

	if (deg.size() != coeff.size()) throw _invalid_parameter;

	for (int i = 0; i < deg.size(); i++)
	{
		reader->next = new PolyNode(deg[i], coeff[i], NULL);
		reader = reader->next;
	}
	polyDegree = deg.at(0);
	numOfterms = deg.size();

}

Poly::~Poly()
{
	/*
	PolyNode* reader = head;
	PolyNode* next = head->next;

	while (next != NULL) {
		next = reader->next;
		delete reader;
		reader = next;
	}
	delete head;
	*/
}

void Poly::addMono(int i, double c)
{
	// TODO
}

void Poly::addPoly(const Poly& p)
{
	// TODO
}

void Poly::multiplyMono(int i, double c)
{
	// TODO
}

void Poly::multiplyPoly(const Poly& p)
{
	// TODO
}

void Poly::duplicate(Poly& outputPoly)
{
	// TODO
}

int Poly::getDegree()
{
	// changed
	return polyDegree;
}

int Poly::getTermsNo()
{
	// changed
	return numOfterms;
}

double Poly::evaluate(double x)
{
	// TODO
	int result = 0;
	int currTerm = 0;
	PolyNode* reader = head->next;
	
	while (reader != NULL) {

		currTerm = reader->coeff;
		for (int i = 0; i < reader->deg; i++) // raising to the power of deg
		{
			currTerm *= x;
		}
		result += currTerm;
		reader = reader->next;
	}
	return result;//change this after completing this function
}

std::string Poly::toString()
{
	// sample: degree=3; a(3)=4.0; a(1)=5.0; a(0)=2.0
	string output = "degree=";
	output.append(to_string(polyDegree));
	output.append("; "); // output = "degree=polyDegree; "

	PolyNode* reader = head->next;

	while (reader->next != NULL) {
		output.append("a(");
		output.append(to_string(head->deg));
		output.append(")=");
		output.append(to_string(head->coeff));
		output.append("; ");
	}

	output.append("a(");
	output.append(to_string(head->deg));
	output.append(")=");
	output.append(to_string(head->coeff));
	output.append(";");

	return output;//change this after completing this function
}

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
	PolyNode* target = new PolyNode(i, c, NULL);
	PolyNode* reader = head;


	if (head->next->deg > i) {
		insertAfter(head, target);
		polyDegree = i;
		numOfterms++;
		return;
	}

	while (reader->next != NULL) {
		if (reader->next->deg == i) {
			reader->next->coeff += c;
			if (reader->next->coeff == 0) {
				numOfterms--;
				removeAfter(reader);
			}
			return;
		}
		if (reader->next->deg < i) {
			insertAfter(reader, target);
			numOfterms++;
			return;
		}
		reader = reader->next;
	}

	insertAfter(reader, target);
	numOfterms++;
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

	outputPoly.numOfterms = numOfterms;
	outputPoly.polyDegree = polyDegree;

	if (polyDegree == -1) {
		outputPoly.head->next = NULL;
		return;
	}
	PolyNode* reader = head->next;
	PolyNode* target = outputPoly.head;

	while (reader != NULL) {
		target->next = new PolyNode(reader->deg, reader->coeff, NULL);
		target = target->next;
		reader = reader->next;
	}

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


//private methods;
void Poly::insertAfter(PolyNode* nodeBefore, PolyNode* target) {

	PolyNode* oldNext = nodeBefore->next;
	nodeBefore->next = target;
	target->next = oldNext;
}

void Poly::removeAfter(PolyNode* n) {

	if (n->next != NULL) {
		PolyNode* oldAfter = n->next;
		n->next = n->next->next;
		delete oldAfter;
	}

}

int Poly::hasDeg(int degree){
	int counter = 0;
	PolyNode* reader = head->next;

	for (int i = 0; i < numOfterms; i++)
	{
		if (reader->deg == degree) {
			return counter;
		}
		counter++;
		reader = reader->next;
	}
}



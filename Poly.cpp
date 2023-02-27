#include "Poly.h"
#include <iostream>
using namespace std;

Poly::Poly()
{
	head = new PolyNode(-1, 0, NULL); // intiate the dummy header
	numOfterms = 0;
	polyDegree = -1;
}

Poly::Poly(int i, double c)
{
	if (c == 0) { // sanity check
		Poly();
		return;
	}

	head = new PolyNode(-1, 0, NULL); // intiate the dummy header
	head->next = new PolyNode(i, c, NULL); // insert the Mono

	numOfterms = 1;
	polyDegree = i;
}

Poly::Poly(const std::vector<int>& deg, const std::vector<double>& coeff)
{
	numOfterms = deg.size();

	head = new PolyNode(-1, 0, NULL); // intiate the dummy header
	PolyNode* reader = head;

	if (deg.size() == 0) return;

	for (int i = 0; i < deg.size(); i++)
	{

		reader->next = new PolyNode(deg[i], coeff[i], NULL);
		reader = reader->next;
	}
	polyDegree = deg.at(0);
}

Poly::~Poly()
{
	
	PolyNode* reader = head;
	PolyNode* next = head->next;

	while (next != NULL) {
		next = reader->next;
		delete reader;
		reader = next;
	}
	
}

void Poly::addMono(int i, double c)
{
	// TODO
	PolyNode* reader = head;
	PolyNode* target; reader->next;


	while (reader->next != NULL) {

		target = reader->next; 
		// stores the node after reader node. it is used to compare the degrees

		if (target->deg > i) reader = reader->next; 
		// skip as long as the current deg is greater than the input degree

		else if (target->deg == i) { 
			// handles already existing degrees
			target->coeff += c;

			if (target->coeff == 0) { // handles zero sum
				removeAfter(reader);
				if (reader == head)   // update polyDegree only if the first node was zero sum
					polyDegree = (reader->next != NULL) > 0 ? reader->next->deg : -1;
				numOfterms--;
			}
			return;
		}

		else { // handles the insersion of new node (executes when the target degree falls below the input degree)
			insertAfter(reader, new PolyNode(i, c, NULL));
			numOfterms++;
			polyDegree = reader == head ? i : polyDegree;
			return;
		}
		
	}

	insertAfter(reader, new PolyNode(i, c, NULL));
	numOfterms++;
}

void Poly::addPoly(const Poly& p)
{
	for (PolyNode* pNode = p.head->next; pNode!= NULL; pNode = pNode->next) {
		addMono(pNode->deg, pNode->coeff);
	}
}

void Poly::multiplyMono(int i, double c)
{
	if (c == 0) {

		numOfterms = 0;
		polyDegree = -1;

		// deleting all the elements in the poly
		PolyNode* reader = head->next, *prev;

		while (reader != NULL) {  // needs revision
			prev = reader;
			reader = reader->next;
			delete prev;
		}

		head->next = NULL;
		return;
	}

	for (PolyNode* pNode = head->next; pNode != NULL; pNode = pNode->next) {
		pNode->coeff *= c;
		pNode->deg += i;
	}

	polyDegree += i;
}

void Poly::multiplyPoly(const Poly& p)
{
	// sanity check
	if (numOfterms == 0) return;

	if (p.numOfterms == 0) {
		numOfterms = 0;
		polyDegree = -1;
		return; 
	}

	
	for (PolyNode* pNode = p.head->next; pNode != NULL; pNode = pNode->next) {

		Poly* results = new Poly(0, 1); // intiate a variable to store the multipication result
		results->multiplyMono(pNode->deg, pNode->coeff);

		addPoly(*results);

		//delete results;
	}
	


}

void Poly::duplicate(Poly& outputPoly)
{
	outputPoly.numOfterms = numOfterms;
	outputPoly.polyDegree = polyDegree;

	if (polyDegree == -1) {
		outputPoly.head = new PolyNode(-1, 0, NULL);
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
	//cout << "\n\nsize = " << getTermsNo() << " Deg = " << getDegree() << endl;
	//cout << "poly1 =\n" << toString() << endl;
	//cout << "x = " << x << endl;

	double currTerm = 0, result =0;
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

	//cout << "p(" << x << ") = " << result << endl;
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
		output.append(to_string(reader->deg));
		output.append(")=");
		output.append(to_string(reader->coeff));
		output.append("; ");
		reader = reader->next;
	}

	output.append("a(");
	output.append(to_string(reader->deg));
	output.append(")=");
	output.append(to_string(reader->coeff));
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



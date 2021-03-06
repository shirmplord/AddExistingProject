// Lab 9.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include "counter.h"
#include <iostream>

class LimitedCounter : public Counter {
public:
	LimitedCounter(const Counter &c0, const int lim0) :Counter(c0), limit(lim0) {};
	LimitedCounter(const int x, const int lim0) : Counter(x), limit(lim0) {};
	LimitedCounter(const LimitedCounter& lc) :Counter(lc), limit(lc.limit) {};
	LimitedCounter operator++(int);
	LimitedCounter& operator++();
private:
	int limit;
};
class RoundupCounter : public Counter {
public:
	RoundupCounter(const Counter &c0, const int lim0) : Counter(c0), limit(lim0) {};
	RoundupCounter(const int x, const int lim0) : Counter(x), limit(lim0) {};
	RoundupCounter(const RoundupCounter& rc) : Counter(rc), limit(rc.limit) {};
	RoundupCounter operator++(int);
	RoundupCounter& operator++();
private:
	int limit;
};
void UseCounter(Counter* c, const int n) {
	for (int i = 0; i < n; i++) c->operator++();
								//++(*c)
}
int main()
{
	LimitedCounter counterA(0, 5);
	RoundupCounter counterB(0, 5);
	UseCounter(&counterA, 8); UseCounter(&counterB, 8);
	cout << "Counter A: " << counterA << endl; // output should be 5
	cout << "Counter B: " << counterB << endl; // output should be 2
	return 0;
}
//postfix
LimitedCounter LimitedCounter::operator++(int) {
	LimitedCounter res(*this);
	int temp = this->getCount();
	if (temp < limit) Counter::operator++();
	return res;
}
//prefix
LimitedCounter& LimitedCounter::operator++() {
	int temp = this->getCount();
	if (temp < limit) Counter::operator++();
	return *this;
}
//postfix
RoundupCounter RoundupCounter::operator++(int) {
	RoundupCounter res(*this);
	int temp = this->getCount();
	if (temp < limit) Counter::operator++();
	else this->reset();
	return res;
}
//prefix
RoundupCounter& RoundupCounter::operator++() {
	int temp = this->getCount();
	if (temp < limit) Counter::operator++();
	else this->reset();
	return *this;
}
// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

#include "Receipt.h"

Receipt::Receipt(String v, Receipt* n): val(v), next(n){}

String Receipt::getValue() const
{
	return val;
}

void Receipt::setValue(String v)
{
	val = v;
}

Receipt* Receipt::getNext() const
{
	return next;
}

void Receipt::setNext(Receipt* n)
{
	next = n;
}

void Receipt::Show() const
{
	val.Show_Str();
	cout << " | ";
}
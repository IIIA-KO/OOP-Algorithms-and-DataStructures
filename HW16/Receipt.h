#pragma once
#include "String.h"
class Receipt
{
private:
	String val;

	Receipt* next;
public:
	Receipt(String v, Receipt* n = nullptr);

	String getValue() const;

	void setValue(String v);

	Receipt* getNext() const;

	void setNext(Receipt* n);

	void Show() const;
};
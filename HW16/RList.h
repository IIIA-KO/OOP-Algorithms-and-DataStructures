#pragma once
#include "Receipt.h"
class RList
{
private:
	Receipt* head;

	Receipt* tail;
public:
	RList();


	void push_front(String v);

	void del_front();

	void Clear();

	bool isEmpty() const;

	Receipt* FindPos(int pos);

	void Show() const;
};


#include "RList.h"

RList::RList(): head(nullptr), tail(nullptr){}

void RList::push_front(String v)
{
	Receipt* tmp = new Receipt(v, head);
	if (!head) tail = tmp;
	head = tmp;
}

void RList::del_front()
{
	if (isEmpty()) return;
	Receipt* tmp = head;
	head = tmp->getNext();
	delete tmp;
}

void RList::Clear()
{
	while (head) {
		this->del_front();
	}
}

bool RList::isEmpty() const
{
	return head == 0;
}

Receipt* RList::FindPos(int pos)
{
	Receipt* tmp = head;
	int i = 0;
	while (tmp)
	{
		if (i == pos) break;
		i++;
		tmp = tmp->getNext();
	}
	return tmp;
}

void RList::Show() const
{
	Receipt* temp = head;
	if (!isEmpty()) {
		while (temp) {
			temp->Show();
			temp = temp->getNext();
		}
	}
	else cout << "Array is empty" << endl;
}

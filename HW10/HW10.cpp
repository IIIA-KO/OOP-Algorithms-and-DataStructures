#include <iostream>
using namespace std;

template<class F>
class Array {
	F* arr;
	int size;
	int count;
	int grow;
public:
	~Array();
	Array();
	explicit Array(int n);
	Array(const Array& a);
	Array(Array&& a);

	void Show_arr() const;
	int GetSize() const;
	void SetSize(unsigned int _size, int _grow = 1);
	int GetUpperBound() const;
	bool IsEmpty() const;
	void FreeExtra();
	void RemoveAll();
	F GetAt(size_t i) const;
	void SetAt(size_t i, F elem);
	int operator[](int i) const;
	void Add(F elem);
	Array<F> Append(const Array<F>& a);

	Array& operator=(const Array& a);
	Array& operator=(Array&& a);
	template<class F> friend ostream& operator << (ostream& out, const Array<F>& a);
	int& operator[](int i);

	F** GetData();
	void InsertAt(size_t i, F elem);
	void RemoveAt(size_t index);

};

template<class F>
Array<F>::~Array() {
	if (arr) {
		delete[] arr;
		arr = NULL;
	}
}
template< class F>
Array<F>::Array(int n) {
	this->size = (n > 0 ? n : 1);
	arr = new int[this->size];
}
template< class F>
Array<F>::Array(const Array& a) :Array(a.size) {
	memcpy(arr, a.arr, size * sizeof(*arr));
}
template< class F>
Array<F>::Array(Array&& a) {
	arr = a.arr;
	a.arr = NULL;
	this->size = a.size;
}
template< class F>
Array<F>::Array() {
	count = 0;
	size = 0;
	arr = NULL;
}

template< class F>
int Array<F>::GetSize() const {
	return size;
}
template< class F>
void Array<F>::SetSize(unsigned int _size, int _grow) {
	grow = _grow;
	if (_size == size)
		return;
	size = _size;
	if (size > 0)
	{
		if (size % grow != 0)
			arr = (F*)realloc(arr, sizeof(F) * (size + (grow - size % grow)));
		else if (size % grow == 0)
			arr = (F*)realloc(arr, sizeof(F) * size);
	}
	if (count > size)
		count = size;
}
template<class F>
int Array<F>::GetUpperBound() const {
	return count;
}
template< class F>
bool Array<F>::IsEmpty() const {
	return count == 0;
}
template<class F>
void Array<F>::FreeExtra() {
	if (size % grow != 0)
	{
		arr = (F*)realloc(arr, sizeof(F) * (count + (grow - count % grow)));;
		size = count + (grow - count % grow);
	}
	else if (size % grow == 0)
	{
		arr = (F*)realloc(arr, sizeof(F) * count);
		size = count;
	}
}
template < class F>
void Array<F>::RemoveAll() {
	delete[] arr;
	size = 0;
	count = 0;
	arr = NULL;
}
template<class F>
F Array<F>::GetAt(size_t i) const {
	if (i >= 0 && i < size) return arr[i];
	else exit(-1);
}
template<class F>
void Array<F>::SetAt(size_t i, F elem) {
	if (i >= 0 && i < size) {
		arr[i] = elem;
		count = i + 1;
	}
	else exit(-1);
}
template<class F>
void Array<F>::Add(F elem) {
	if (count < size) {
		arr[count++] = elem;
	}
	else if (count >= size) {
		SetSize(size + 1);
		arr[size - 1] = elem;
		count++;
	}
}
template< class F>
void Array<F>::Show_arr() const {
	for (int i = 0; i < size; i++) cout << arr[i] << " ";
	cout << endl;
}
template <class F>
F** Array<F>::GetData() {
	return &arr;
}
template <class F>
Array<F> Array<F>::Append(const Array<F>& a) {
	//int size = this->size + a.size;
	int count = this->count + a.count;
	Array tmp(size + a.size);
	for (int i = 0; i < size; i++) {
		tmp.arr[i] = arr[i];
	}
	for (int i = 0; i < a.size; i++) {
		tmp.arr[i + size] = a.arr[i];
	}
	return tmp;
}
template <class F>
void Array<F>::InsertAt(size_t index, F elem) {
	if (index < 0 || index > size) {
		cout << "ERROR: Wrong index" << endl;
		exit(-1);
	}
	if (count >= size)
	{
		SetSize(size + 1);
	}
	for (int i = count; i >= index; i--)
	{
		arr[i] = arr[i - 1];
	}
	arr[index] = elem;
	count++;
}
template<class F>
void Array<F>::RemoveAt(size_t index) {
	if (index < 0 || index > size) {
		cout << "ERROR: Wrong index" << endl;
		exit(-1);
	}
	for (int i = index; i < count; i++)
	{
		arr[i] = arr[i + 1];
	}
	count--;
}

template< class F>
ostream& operator << (ostream& out, const Array<F>& a) {
	for (int i = 0; i < a.size; i++) cout << a.arr[i] << " ";
	cout << endl;
	return out;
}
template< class F>
Array<F>& Array<F>::operator=(const Array<F>& a) {
	if (this != &a) {
		size = a.size;
		count = a.count;
		delete[] arr;
		arr = new int[this->size];
		memcpy(arr, a.arr, size * sizeof(*arr));
	}
	return *this;
}
template<class F>
int Array<F>::operator[](int i) const {
	if (i >= size || i < 0)
		exit(-1);
	return arr[i];
}
template<class F>
int& Array<F>::operator[](int i) {
	if (i >= size || i < 0)
		exit(-1);
	return arr[i];
}

int main()
{
	Array<int> a;
	cout << "+===================================================================+" << endl;
	int array_size = 1, array_grow = 1;
	cout << "Enter size for Array A (size > 0): "; cin >> array_size;
	cout << "Enter grow for Array A (grow > 0): "; cin >> array_grow;
	if (array_size <= 0 || array_grow <= 0) {
		cout << "ERROR: Wrong entered size or grow" << endl;
		exit(-1);
	}
	a.SetSize(array_size, array_grow);
	cout << "A:" << a << endl;
	cout << "+===================================================================+" << endl << endl << endl;

	cout << "+===================================================================+" << endl;
	int count = 1, elem;
	cout << "Enter how many numbers you want to add to array (more than 0): "; cin >> count;
	if (count <= 0) {
		cout << "ERROR: Wrong entered amount of numbers for array: " << endl;
		exit(-1);
	}
	for (int i = 0; i < count; i++) {
		cout << "Enter " << i + 1 << " elemnt: "; cin >> elem;
		a.Add(elem);
	}
	cout << "A:" << a << endl;
	cout << "+===================================================================+" << endl << endl << endl;

	cout << "+===================================================================+" << endl;
	cout << "Size A: " << a.GetSize() << endl;
	cout << "+===================================================================+" << endl << endl << endl;

	cout << "+===================================================================+" << endl;
	cout << "Is A empty: " << a.IsEmpty() << endl;
	cout << "+===================================================================+" << endl << endl << endl;

	cout << "+===================================================================+" << endl;
	unsigned int i;
	cout << "Enter index (more than 0): "; cin >> i;
	cout << "Get At function: " << a[i] << endl;
	cout << "+===================================================================+" << endl << endl << endl;

	cout << "+===================================================================+" << endl;
	cout << "Enter element: "; cin >> elem;
	a[i] = elem;
	cout << "Set At function: " << a << endl;
	cout << "+===================================================================+" << endl << endl << endl;

	cout << "+===================================================================+" << endl;
	cout << "B = A" << endl;
	Array<int> b = a;
	cout << "A: " << a << endl;
	cout << "B: " << b << endl;
	cout << "+===================================================================+" << endl << endl << endl;

	cout << "+===================================================================+" << endl;
	cout << "A adress: " << a.GetData() << endl;
	cout << "+===================================================================+" << endl << endl << endl;

	cout << "+===================================================================+" << endl;
	cout << "C = A append B" << endl;
	Array<int> c = a.Append(b);
	cout << "A: " << c << endl;
	cout << "+===================================================================+" << endl << endl << endl;

	cout << "+===================================================================+" << endl;
	cout << "Insert At A" << endl;
	cout << "Enter index (more than 0): "; cin >> i;
	cout << "Enter element: "; cin >> elem;
	a.InsertAt(i, elem);
	cout << "A: " << a << endl;
	cout << "+===================================================================+" << endl << endl << endl;

	cout << "+===================================================================+" << endl;
	cout << "Remove At A" << endl;
	cout << "Enter index (more than 0): "; cin >> i;
	a.RemoveAt(i);
	cout << "A: " << a << endl;
	cout << "+===================================================================+" << endl << endl << endl;

	cout << "+===================================================================+" << endl;
	cout << "Get Upper Bound A: " << a.GetUpperBound() << endl;
	cout << "+===================================================================+" << endl << endl << endl;

	cout << "+===================================================================+" << endl;
	cout << "Free Extra A" << endl;
	a.FreeExtra();
	cout << "A: " << a << endl;
	cout << "+===================================================================+" << endl << endl << endl;

	cout << "+===================================================================+" << endl;
	cout << "Remove all A: " << endl;
	a.RemoveAll();
	cout << "A: " << a << endl;
	cout << "+===================================================================+" << endl;
	return 0;
}
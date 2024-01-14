#include <iostream>
using namespace std;

template<class t>
class my_unique_ptr {
	t* ptr;
public:
	my_unique_ptr() : ptr(nullptr) {}
	my_unique_ptr(const my_unique_ptr& up) = delete;
	my_unique_ptr(t* p) {
		ptr = p;
	}
	my_unique_ptr(my_unique_ptr&& up) {
		ptr = move(up.ptr);
		up.ptr = NULL;
	}
	~my_unique_ptr() {
		if (ptr)
			delete ptr;
		ptr = NULL;
	}

	my_unique_ptr& operator=(const my_unique_ptr& up) = delete;
	my_unique_ptr& operator=(my_unique_ptr&& up) {
		ptr = move(up.ptr);
		up.ptr = NULL;
		return (*this);
	}
	t& operator*() {
		return (*ptr);
	}
	t* operator->() {
		return ptr;
	}

	t* get() {
		return ptr;
	}
	void reset() {
		delete ptr;
		ptr = nullptr;
	}
	void realese() {
		ptr = nullptr;
	}
	void swap(my_unique_ptr<t>& up) {
		std::swap(ptr, up.ptr);
	}
};


class my_shared_count {
	size_t count;
public:
	my_shared_count() : count(0) {};
	my_shared_count(const my_shared_count&) = delete;
	my_shared_count& operator=(const my_shared_count&) = delete;
	~my_shared_count() {}
	void reset() {
		count = 0;
	}
	size_t get() {
		return count;
	}
	void operator++() {
		count++;
	}
	void operator++(int) {
		++count;
	}
	void operator--() {
		count--;
	}
	void operator--(int){
		++count;
	}
};
template<class t>
class my_shared_ptr {
	t* ptr = nullptr;
	my_shared_count* count;
public:
	explicit my_shared_ptr(t* _ptr = nullptr) {
		ptr = _ptr;
		count = new my_shared_count();
		if (_ptr) {
			(*count)++;
		}
	}
	my_shared_ptr(my_shared_ptr<t>& sp) {
		ptr = sp.ptr;
		count = sp.count;
		(*count)++;
	}
	~my_shared_ptr() {
		if (count->get() > 1) {
			(*count)--;
			return;
		}
		delete ptr;
		delete count;
	}

	t* get(){
		return ptr;
	}
	t& operator*(){
		return *ptr;
	}
	t* operator->(){
		return ptr;
	}
	void operator= (my_shared_ptr<t>& up) {
		up.ptr = ptr;
		(*up.count)++;
		(*count)++;
	}

	size_t use_count(){
		return count->get();
	}
	void reset() {
		delete ptr;
		ptr = nullptr;
	}
	void swap(my_shared_ptr<t>& up) {
		std::swap(ptr, up.ptr);
	}
};


int main()
{
	cout << "+===================================================================================================+" << endl;
	cout << "MY_UNIQUE_PTR: " << endl << endl;
	my_unique_ptr<int> mup1(new int(5));
	my_unique_ptr<int> mup2(new int(10));

	cout << "The MUP1 <<" << mup1.get() << ">> unique_pointer was created" << " with value <<" << *mup1 << ">>" << endl;
	cout << "The MUP2 <<" << mup2.get() << ">> unique_pointer was created" << " with value <<" << *mup2 << ">>" << endl << endl;


	cout << "Swap unique_pointers: " << endl;
	mup1.swap(mup2);
	cout << "MUP1 <<" << mup1.get() << ">> unique_pointer" << " with value <<" << *mup1 << ">>" << endl;
	cout << "MUP2 <<" << mup2.get() << ">> unique_pointer" << " with value <<" << *mup2 << ">>" << endl << endl;

	cout << "MUP1 = MOVE(MUP2)" << endl;
	mup1 = move(mup2);
	cout << "MUP1 <<" << mup1.get() << ">> unique_pointer" << " with value <<" << *mup1 << ">>" << endl;
	cout << "MUP2 <<" << mup2.get() << ">> unique_pointer" << " with value << [no value] >>" << endl << endl;

	cout << "MUP1.REALESE()" << endl;
	mup1.realese();
	cout << "MUP1 <<" << mup1.get() << ">> unique_pointer" << " with value <<[no value] >>" << endl << endl;

	my_unique_ptr<int> mup3(new int(15));
	cout << "The MUP3 <<" << mup3.get() << ">> unique_pointer was created" << " with value <<" << *mup3 << ">>" << endl;
	cout << "MUP3.RESET()" << endl;
	mup3.reset();
	cout << "MUP3 <<" << mup3.get() << ">> unique_pointer" << " with value <<[no value] >>" << endl << endl;
	cout << "+===================================================================================================+" << endl << endl << endl;


	cout << "+===================================================================================================+" << endl;
	cout << "MY_SHARED_PTR: " << endl << endl;
	my_shared_ptr<int> msp1(new int(5));
	my_shared_ptr<int> msp2 = msp1;
	my_shared_ptr<int> msp3(new int(10));

	cout << "The MSP1 <<" << msp1.get() << ">> shared_pointer was created" << " with value <<" << *msp1 << ">>" << endl;
	cout << "The MSP2 <<" << msp2.get() << ">> shared_pointer was created" << " with value <<" << *msp2 << ">>" << endl;
	cout << "The MSP3 <<" << msp3.get() << ">> shared_pointer was created" << " with value <<" << *msp3 << ">>" << endl << endl;


	cout << "USE_COUNT: " << endl;
	cout << "msp1.use_count(): " << msp1.use_count() << endl;
	cout << "msp2.use_count(): " << msp2.use_count() << endl;
	cout << "msp3.use_count(): " << msp3.use_count() << endl << endl;

	cout << "Swap shared_pointers\nMSP1.SWAP(MSP3)" << endl;
	msp1.swap(msp3);
	cout << "MSP1 <<" << msp1.get() << ">> shared_pointer with value <<" << *msp1 << ">>" << endl;
	cout << "MSP3 <<" << msp3.get() << ">> shared_pointer with value <<" << *msp3 << ">>" << endl << endl;

	cout << "MSP3.RESET()" << endl;
	msp3.reset();
	cout << "MSP3 <<" << msp3.get() << ">> shared_pointer with value << [no value] >>" << endl << endl;

	cout << "+===================================================================================================+" << endl << endl << endl;


	return 0;
}
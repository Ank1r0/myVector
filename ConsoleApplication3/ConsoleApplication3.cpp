#include <iostream>
#include <vector>

using namespace std;

template <typename T>
class Vector
{
	T* ptr = nullptr;
	size_t	size = 0,
		capacity = 0;

	void checkCap()
	{
		if (size == capacity)
		{
			ptr = (T*)realloc(ptr, (size + 5) * sizeof(T*));
			capacity += 5;
		}
	}

public:

	Vector(size_t capacity)
	{
		ptr = new T[capacity];
		this->capacity = capacity;
	}

	size_t getSize() { return size; }

	void push_back(T data)
	{
		checkCap();
		ptr[size++] = data;
	}

	void print()
	{
		cout << '[';
		for (int i = 0; i < size; ++i)
		{
			cout << ptr[i] << (i < size - 1 ? ", " : "");
		}
		cout << "]\n";
	}

	void erase(T index)
	{
		for (int i = index; i < (int)size - 1; ++i)
		{
			ptr[i] = ptr[i + 1];
		}
		size--;
	}

	void clear()
	{
		free(ptr);
		ptr = nullptr;
		size = capacity = 0;
	}

	void push_front(T data)
	{
		checkCap();
		for (int i = size; i > 0; --i)
		{
			ptr[i] = ptr[i - 1];
		}
		size++;
		ptr[0] = data;
	}

	void insert(int index, T data)
	{
		if (index > size || index < 0) throw exception("Out of bounds");
		checkCap();
		for (int i = size; i > index; --i)
		{
			ptr[i] = ptr[i - 1];
		}
		size++;
		ptr[index] = data;
	}

	T at(int index)
	{
		if (index < 0 || index > size - 1) throw exception("Out of bounds");
		return ptr[index];
	}

	T& operator[](int index)
	{
		return ptr[index];
	}

	T pop_back()
	{
		if (size == 0) throw exception("Out of bounds.");
		size--;
		return ptr[size];
	}

	T pop_front()
	{
		T temp = ptr[0];
		erase(0);
		return temp;
	}

	T* data()
	{
		return ptr;
	}

};

double func(int x)
{
	if (x <= 0) throw exception("Invalid parammetr");
	return x * 25 - 876.0 / x + sqrt(x * x * x);
}


int main()
{
	// int x;
	// while(1)
	// {
	// 	try
	// 	{
	// 		cout << "Enter param: ";
	// 		cin >> x;
	// 		cout << func(x) << '\n';
	// 		cout << "OK\n";
	// 		break;
	// 	}
	// 	catch (exception ex)
	// 	{
	// 		cout << "Error: " << ex.what() << '\n';
	// 	}
	// }

	vector<int> a, b;

	a.push_back(100);
	a.push_back(200);
	a.push_back(300);
	a.insert(a.begin() + 1, 55);
	auto it = a.end();
	b.emplace_back(88);


	a[2] = 222;
	try
	{
		cout << a.at(20) << '\n';
	}
	catch (exception ex)
	{
		cout << ex.what() << '\n';
	}

	for (int i = 0; i < a.size(); ++i)
	{
		cout << a[i] << '\n';
	}

	Vector<int> vc(5);
	vc.push_back(0);
	vc.push_back(88);
	vc.push_back(2);
	vc.push_back(3);
	vc.push_back(4);
	vc[1] = 44;
	cout << vc[1] << '\n';
	vc.print();
	vc.insert(1, 100);
	vc.print();



	vc.clear();

	try
	{
		vc.pop_back();
	}
	catch (...) {}




	system("pause");
	return 0;
}
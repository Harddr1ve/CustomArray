#ifndef CARRAY_H
#define CARRAY_H

#include <iostream>
#include <new>
#include <string>

using namespace std;

template <typename TData>
class CArray
{
public: // Interface

	// ����������� �� ���������
	CArray();
	// ���������� �����������
	CArray(const CArray& _array);
	// ����������
	~CArray();

	// �������� ������� � ����� �������
	void push_back(
		const TData& _value
	);
	// �������� ������� � ������ �� ��������� �������
	void insert(
		unsigned int _index,
		const TData& _value
	);
	// ������� ������� ������� �� ��������� �������
	void erase(
		unsigned int _index
	);
	// �������� ������
	void clear();
	//�������� ������ �������
	unsigned int size() const;
	// ���� �������
	void print();

	// �������� ������� ������� �� ��������� �������
	TData & operator[] (
		unsigned int _index
		);
	// ����������� �������
	CArray& operator= (
		const CArray& _array
		) 
	{			
		if (count > 0)
		{
			delete[] _A;
		}
		try
		{
			_A = new TData[_array.count];
			this->count = _array.count;

			for (size_t i = 0; i < count; i++)
			{
				_A[i] = _array._A[i];
			}
		}
		catch (bad_alloc e)
		{
			cout << e.what();
		}
		return* this;		
	}

protected:
	int count;
	TData* _A; 

	bool check_index(int _index)
	{
		if ((_index < 0) || (_index >= count))
			return false;
		return true;
	}

	TData* Alloc(int _count)
	{
		TData* _A2 = nullptr;

		try {
			_A2 = new TData[_count];
		}
		catch (bad_alloc e)
		{
			cout << e.what() << endl;
			return nullptr;
		}
		return _A2;
	}
};

#include "CArray.inl"
#endif CARRAY_H

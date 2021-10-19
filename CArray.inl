#ifndef CARRAY_INL
#define CARRAY_INL
#include "CArray.h"

template<typename TData>
inline CArray<TData>::CArray()
{
	this->count = 0;
}

template<typename TData>
inline CArray<TData>::CArray(const CArray& _array)
{
	try 
	{
		_A = new TData[_array.count];
		count = _array.count;

		for (int i = 0; i < count; i++)
			_A[i] = _A._array[i];
	}
	catch (bad_alloc e)
	{
		count = 0;
		cout << e.what() << endl;
	}
}

template<typename TData>
inline CArray<TData>::~CArray()
{
	if (count > 0)
		delete[] _A;
}

template<typename TData>
inline void CArray<TData>::push_back(const TData& _value)
{
    try {
		this->count++;
		TData* tmp_array = Alloc(count);
		for (int i = 0; i < this->count - 1; i++)
		{
			tmp_array[i] = _A[i];
		}
		
        tmp_array[this->count - 1] = _value;
		if ((this->count - 1) > 0)
		{
			delete[] _A;
		}
        _A = tmp_array;
    }
    catch (bad_alloc e)
    {
        cout << e.what() << endl;
    }
}

template<typename TData>
inline void CArray<TData>::insert(unsigned int _index, const TData& _value)
{
	if (!check_index(_index))
	{
		cout << "WARNING: Wrong index ";
		return;
	}
	try
	{
		this->count++;
		TData* tmp_array = Alloc(count);
		for (size_t i = 0; i < this->count; i++)
		{
			if (i == _index)
			{
				tmp_array[i] = _value;
			} 
			else if (i > _index)
			{
				tmp_array[i] = _A[i - 1];
			}
			else if (i < _index)
			{
				tmp_array[i] = _A[i];
			}
		}
		delete[] _A;
		_A = tmp_array;
	}
	catch (bad_alloc e)
	{
		cout << e.what();
	}
}

template<typename TData>
inline void CArray<TData>::erase(unsigned int _index)
{
	if (!check_index(_index))
	{
		cout << "WARNING: Wrong index";
		return;
	}
	try
	{
		this->count--;
		TData* tmp_array = Alloc(count);
		for (size_t i = 0; i < this->count; i++)
		{
			if (i >= _index)
			{
				tmp_array[i] = _A[i + 1];
			}
			else if (i < _index)
			{
				tmp_array[i] = _A[i];
			}
		}
		delete[] _A;
		_A = tmp_array;
	}
	catch (bad_alloc e)
	{
		cout << e.what();
	}
}

template<typename TData>
inline void CArray<TData>::clear()
{
	if (this->count > 0)
	{
		delete[] _A;
		this->count = 0;
	}
}

template<typename TData>
inline unsigned int CArray<TData>::size() const
{
	return this->count;
}

template<typename TData>
inline void CArray<TData>::print()
{
	for (size_t i = 0; i < count; i++)
	{
		cout << _A[i] << " ";
	}

	cout << endl;
}

template<typename TData>
inline TData& CArray<TData>::operator[](unsigned int _index)
{
	if (check_index(_index))
		return _A[_index];
	else
	{
		TData value = 0;
		cout << "WARNING: Wrong index" << endl;
		return value;
	}
}

#endif //!CARRAY_INL


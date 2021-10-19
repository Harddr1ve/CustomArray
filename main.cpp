#include <iostream>
#include <string>
#include <cstdlib>
#include "CArray.h"

using namespace std;

void test_int_1(CArray<int>& custom_int_array)
{
	cout << " Add 20 randm nums from 0 to 100 in array " << endl;

	srand(time(NULL));

	for (size_t i = 0; i < 20; i++)
	{
		custom_int_array.push_back(rand() % 100);
	}
}

void test_int_2(CArray<int>& custom_int_array)
{
	int i, j, t;

	cout << endl << "Grater sort" << endl;

	for (i = 0; i < custom_int_array.size() - 1; i++)
	{
		for (j = i; j >= 0; j--)
		{
			if (custom_int_array[j] > custom_int_array[j + 1])
			{
				t = custom_int_array[j];
				custom_int_array[j] = custom_int_array[j + 1];
				custom_int_array[j + 1] = t;
			}
		}
	}
}

void test_int_3(CArray<int>& custom_int_array)
{
	cout << endl << "Remove every second element" << endl;

	CArray<int> tmp_array;
	tmp_array.clear();

	for (size_t i = 0; i < custom_int_array.size(); i++)
	{
		if (!(i & 1))
		{
			tmp_array.push_back(custom_int_array[i]);
		}
	}
	custom_int_array = tmp_array;
}
void test_int_4(CArray<int>& custom_int_array)
{
	cout << endl << "Insert 10 random nums from 0 to 100 on random positions" << endl;

	srand(time(NULL));

	for (size_t i = 0; i < 10; i++)
	{
		custom_int_array.insert(rand() % custom_int_array.size(), rand() % 100);
	}
}
void test_int_5(CArray<int>& custom_int_array)
{
	cout << endl << "Clear array" << endl;

	custom_int_array.clear();
}

void tests_int()
{
	CArray<int> custom_int_array;

	test_int_1(custom_int_array);
	custom_int_array.print();

	test_int_2(custom_int_array);
	custom_int_array.print();

	test_int_3(custom_int_array);
	custom_int_array.print();

	test_int_4(custom_int_array);
	custom_int_array.print();

	test_int_5(custom_int_array);
	custom_int_array.print();
}

void test_string_1(CArray<string>& custom_string_array)
{
	int word_len;
	string word;
	char symbol;

	cout << endl << "Add 15 random words" << endl;

	srand(time(NULL));

	for (size_t i = 0; i < 15; i++)
	{
		word_len = rand() % 10;
		word = "";
		for (size_t j = 0; j < word_len; j++)
		{
			symbol = 'a' + rand() % ((int)'z' - (int)'a' + 1);
			word += symbol;
		}
		custom_string_array.push_back(word);
	}
}

void test_string_2(CArray<string>& custom_string_array)
{
	cout << endl << "Grater sort" << endl;
	int i, j;
	string s;

	for (i = 0; i < custom_string_array.size() - 1; i++)
	{
		for (j = i; j >= 0; j--)
		{
			if (custom_string_array[j] > custom_string_array[j + 1])
			{
				s = custom_string_array[j];
				custom_string_array[j] = custom_string_array[j + 1];
				custom_string_array[j + 1] = s;
			}
		}
	}
}

void test_string_3(CArray<string>& custom_string_array)
{
	int i, j;
	string word;
	CArray<string> tmp_array;
	bool f_delete;

	cout << endl << "Delete every word with a,b,c,d,e " << endl;

	for (i = 0; i < custom_string_array.size(); i++)
	{
		word = custom_string_array[i];
		f_delete = false;

		for (j = 0; j < word.length(); j++)
		{
			if (('a' <= word[j]) && (word[j] <= 'e'))
			{
				f_delete = true;
				break;
			}
		}
		if (!f_delete)
		{
			tmp_array.push_back(word);
		}
	}
	custom_string_array = tmp_array;
}

void test_string_4(CArray<string>& custom_string_array)
{
	int i, j;
	int len;
	string word;
	char symbol; 
	int position; 
	int t; 

	cout << endl << "Insert 3 random words in random positions" << endl;

	srand(time(NULL));

	for (i = 0, t = 0; i < 3; i++, t++)
	{
		position = rand() % (custom_string_array.size() + t);
		len = rand() % 6 + 1;
		word = "";

		for (j = 0; j < len; j++)
		{
			symbol = 'a' + rand() % ((int)'z' - (int)'a' + 1);
			word += symbol;
		}
		custom_string_array.insert(position, word);
	}
}

void string_test()
{
	CArray<string> custom_string_array;

	test_string_1(custom_string_array);
	custom_string_array.print();

	test_string_2(custom_string_array);
	custom_string_array.print();

	test_string_3(custom_string_array);
	custom_string_array.print();

	test_string_4(custom_string_array);
	custom_string_array.print();

}

int main()
{
	tests_int();
	string_test();

	return 0;
}
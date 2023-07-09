#pragma once
#include <cstring>
#include <assert.h>
namespace bit
{
	class string
	{
		friend ostream& operator<<(ostream& out, const string& s);
		friend istream& operator>>(istream& in, string& s);
	public:

		string(const char* str = "")
		{
			size_t len = strlen(str);
			_size = len;
			_capacity = len;
			_str = new char[len + 1];
			strcpy(_str, str);
		}
		string(const string& s)
		{
			_str = new char[s._capacity + 1];
			_size = s._size;
			_capacity = s._capacity;
			strcpy(_str, s._str);
		}
		~string()
		{
			delete[] _str;
			_str = nullptr;
			_size = 0;
			_capacity = 0;
		}

		size_t size() const
		{
			return _size;
		}
		size_t capacity() const
		{
			return _capacity;
		}
		const char* c_str()const//只负责打印，不可以对他修改
		{
			return _str;
		}

		typedef char* iterator;
		typedef const char* const_iterator;

		iterator begin()
		{
			return _str;
		}
		iterator end()
		{
			return _str + _size;
		}
		const_iterator begin() const
		{
			return _str;
		}
		const_iterator end() const
		{
			return _str + _size;
		}
		const char& operator[](size_t pos) const
		{
			assert(pos < _size);
			return _str[pos];
		}
		char& operator[](size_t pos)
		{
			assert(pos < _size);
			return _str[pos];
		}
		void reserve(size_t n)
		{
			if (n > _capacity)
			{
				char* tmp = new char[n + 1];
				strcpy(tmp, _str);
				delete[] _str;
				_str = tmp;
				_capacity = n;
			}
		}
		void push_back(const char ch) 
		{
			if (_size == _capacity)
			{
				reserve(_capacity == 0 ? 4 : _capacity * 2);
			}
			_str[_size++] = ch;
			_str[_size] = '\0';
		}
		void append(const char* s)
		{
			const size_t len = strlen(s);
			if (_size + len > _capacity)
			{
				reserve(_size + len);
			}
			strcpy(_str + _size, s);
			_size += len;
		}
		string& operator+=(char ch)
		{
			push_back(ch);
			return *this;
		}
		string& operator+=(const char* s)
		{
			append(s);
			return *this;
		}
		void insert(size_t pos, size_t n, char ch)
		{
			assert(pos <= _size);
			if (_size + n > _capacity)
			{
				reserve(_size + n);
			}
			size_t end = _size;
			while (end >= pos && end != npos)//当pos == 0是， i == 0; i - 1 不等于 -1， 因为是size_t类型，会强转成npos
			{
				_str[end + n] = _str[end];
				--end;
			}
			for (size_t i = pos; i < pos + n; i++)
			{
				_str[i] = ch;
			}
			_size += n;
		}
		void insert(size_t pos, const char* str)
		{
			assert(pos < _size);
			int len = strlen(str);
			assert(pos <= _size);
			if (_size + len > _capacity)
			{
				reserve(_size + len);
			}
			size_t end = _size;
			while (end >= pos && end != npos)//当pos == 0是， i == 0; i - 1 不等于 -1， 因为是size_t类型，会强转成npos
			{
				_str[end + len] = _str[end];
				--end;
			}
			for (size_t i = pos; i < pos + len; i++)
			{
				_str[i] = str[i - pos];
			}
			_size += len;
		}
		void erase(size_t pos, size_t len = npos)
		{
			assert(pos < _size);
			if (len == npos || pos + len >= _size)
			{
				_str[pos] = '\0';
				_size = pos;
			}
			else
			{
				/*for (size_t i = pos + len; i <= _size; i++)
				{
					_str[i - len] = _str[i];
				}*/
				size_t end = pos + len;
				while (end <= _size)
				{
					_str[pos++] = _str[end++];
				}
				_size -= len;
			}
		}
		size_t find(char ch, size_t pos = 0) const
		{
			assert(pos < _size);
			for (size_t i = 0; i < _size; i++)
			{
				if (_str[i] == ch)return i;
			}
			return npos;
		}
		size_t find(const char* s, size_t pos = 0) const
		{
			assert(pos < _size);
			const char* str = strstr(_str, s);
			if (str)
			{
				return str - _str;
			}
			else
			{
				return npos;
			}
		}
		string substr(size_t pos = 0, size_t len = npos)const
		{
			assert(pos < _size);

			size_t n = len;
			if (len == npos || pos + len > _size)
			{
				n = _size - len;
			}
			string tmp;
			tmp.reserve(n);
			/*for (size_t i = pos; i < pos + n; i++)
			{
				tmp._str[i - pos] = _str[i];
			}
			tmp._size = n;*/
			for (size_t i = pos; i < pos + n; i++)
			{
				tmp += _str[i];
			}
			return tmp;
		}

	private:
		size_t _size;
		size_t _capacity;
		char* _str;
	public:
		//const static size_t npos = -1; //虽然可以但不建议;
		//const static double npos = 1.1;//因为出来int类型，其他的类型都不可以
		//const static int npos = 1;//
		const static size_t npos;
	};
	const size_t string::npos = -1;
	ostream& operator<<(ostream& out, const string& s)
	{
		out << s._str;
		return out;
	}
	//istream& operator>>(istream& in, string& s)
	//{
	//	char* str = " ";
	//	cin >> str;
	//	int len = strlen(str);
	//	char* tmp = new char[len + 1];
	//	delete[] s._str;
	//	strcpy(tmp, str);
	//	s._str = tmp;
	//	return cin;
	//}
}

//ostream& operator<<(ostream& out, const bit::string& s)
//{
//	out << s._str;
//}
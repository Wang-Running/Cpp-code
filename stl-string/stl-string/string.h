#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include <string>
#include <assert.h>

namespace bit
{
	//简单string，只考虑深浅拷贝
	class mystring
	{
	public:
		//无参的默认构造
		/*mystring()
			:_size(0)
			,_capacity(0)
		{
			_str = new char[1];
			_str[0] = '\0';
		}*/

		//修改为全缺省
		// "\0":有两个\0  "":最好的写法  '\0':字符不推荐，字符\0为空指针
		mystring(const char* str="")
			/*:_str(new char[strlen(str)+1])*/
			//增删查改
			:_size(strlen(str))
			, _capacity(_size)
		{
			_str = new char[_capacity+1];
			//会拷贝'\0'
			strcpy(_str, str);
		}

		//构造拷贝s2(s1)
		//系统默认为浅拷贝，会存在连续析构问题，这里要完成深拷贝
		mystring(const mystring& s)
			:_size(strlen(s._str))
			, _capacity(_size)
		{
			_str = new char[strlen(s._str) + 1];
			strcpy(_str, s._str);
		}

		//重载赋值运算符s1=s3
		//直接拷贝存在内存过大或太小，不判断相等的话会被释放掉
		/*mystring& operator=(const mystring s)
		{
			if (_str != s._str)
			{
				delete[] _str;
				_str = new char[strlen(s._str) + 1];
				strcpy(_str, s._str);
			}
			return *this;
		}*/

		//因为开空间失败后会抛异常，上述写法还已经释放了s1--改进如下
		mystring& operator=(const mystring s)
		{
			if (_str != s._str)
			{
				                    // s._capacity + 1
				char* tmp = new char[strlen(s._str) + 1];
				strcpy(tmp, s._str);
				delete[] _str;
				_str = tmp;
				_size = s._size;
				_capacity = s._capacity;
			}
			return *this;
		}

		//析构函数
		~mystring()
		{
			if (_str)
			{
				delete[] _str;
				_str = nullptr;
				_size = _capacity = 0;
			}
		}

		//获取c形式的字符串
		const char* c_str() const
		{
			return _str;
		}

		//重载[]
		char& operator[](size_t pos)
		{
			assert(pos < strlen(_str));
			return _str[pos];
		}

		//长度size
		size_t size() const
		{
			return  strlen(_str);
			//return _size;
		}

		//容量
		size_t capacity() const
		{
			return _capacity;
		}


		//+=重载
		mystring& operator+=(const char* str)
		{
			append(str);
			return *this;
		}

		mystring& operator+=(char ch)
		{
			push_back(ch);
			return *this;
		}

		//reverse扩容
		void reserve(size_t n)
		{
			if (n>_capacity)
			{
				char* tmp = new char[n + 1];
				strcpy(tmp, _str);
				delete[] _str;
				_str = tmp;
				_capacity = n;
			}
		}

		//resize--扩空间+初始化、删除部分数据，保留前n个
		//3种情况：容量不够,扩容填数据、容量够，填数据、小于size，删数据
		void resize(size_t n, char ch = '\0')
		{
			//容量小，删数据
			if (n<_size)
			{
				_size = n;
				_str[_size] = '\0';
			}
			else
			{
				//扩容--填数据
				if (n>_capacity)
				{
					reserve(n);
				}
				for (size_t i = _size; i < n; i++)
				{
					_str[i] = ch;
				}
				_size = n;
				_str[_size] = '\0';
			}
		
		}

		//插入数据
		void push_back(char ch)
		{
			//扩容
			if (_size==_capacity)
			{
				/*char* tmp = new char[_capacity * 2 + 1];
				strcpy(tmp, _str);
				delete[] _str;
				_str = tmp;
				_capacity *= 2;*/

				//复用reverse
				reserve(_capacity == 0 ? 4 : _capacity * 2);
			}
			_str[_size] = ch;
			_size++;
			_str[_size] = '\0';
		}

		void append(const char* str)
		{
			size_t len = _size + strlen(str);
			if (len > _capacity)
			{
				reserve(len);
			}
			strcpy(_str + _size, str);
			_size = len;
		}

	private:
		char* _str;
		//增删查改
		size_t _size;
		size_t _capacity;
	};

	//运算符重载--实现两个，其他进行复用
	bool operator<(const mystring& s1, const mystring& s2)
	{
		return strcmp(s1.c_str(), s2.c_str()) < 0;
	}

	bool operator==(const mystring& s1, const mystring& s2)
	{
		return strcmp(s1.c_str(), s2.c_str()) == 0;
	}

	bool operator<=(const mystring& s1, const mystring& s2)
	{
		return s1 < s2 || s1 == s2;
	}

	bool operator>(const mystring& s1, const mystring& s2)
	{
		return !(s1 <= s2);
	}

	bool operator>=(const mystring& s1, const mystring& s2)
	{
		return !(s1 < s2);
	}

	bool operator!=(const mystring& s1, const mystring& s2)
	{
		return !(s1 == s2);
	}
}

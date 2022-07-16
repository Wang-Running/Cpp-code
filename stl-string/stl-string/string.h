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

		//迭代器
		typedef char* iterator;
		typedef const char* const_iterator;

		iterator begin()
		{
			return _str;
		}
		const_iterator begin() const
		{
			return _str;
		}
		iterator end()
		{
			return _str + _size;
		}
		const_iterator end() const
		{
			return _str + _size;
		}

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

		//重载[],两个版本
		char& operator[](size_t pos)
		{
			assert(pos < strlen(_str));
			return _str[pos];
		}
		const char& operator[](size_t pos) const
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
			//if (_size==_capacity)
			//{
			//	/*char* tmp = new char[_capacity * 2 + 1];
			//	strcpy(tmp, _str);
			//	delete[] _str;
			//	_str = tmp;
			//	_capacity *= 2;*/

			//	//复用reverse
			//	reserve(_capacity == 0 ? 4 : _capacity * 2);
			//}
			//_str[_size] = ch;
			//_size++;
			//_str[_size] = '\0';
			insert(_size, ch);
		}

		void append(const char* str)
		{
			/*size_t len = _size + strlen(str);
			if (len > _capacity)
			{
				reserve(len);
			}
			strcpy(_str + _size, str);
			_size = len;*/
			insert(_size, str);
		}

		//插入字符
		mystring& insert(size_t pos,char ch)
		{
			assert(pos <= _size);
			if (_size==_capacity)
			{
				reserve(_capacity == 0 ? 4 : _capacity * 2);
			}
			size_t end = _size+1;
			while (end>pos)
			{
				_str[end] = _str[end-1];
				end--;
			}
			_str[pos] = ch;
			_size++;
			return *this;
		}
		//插入字符串
		mystring& insert(size_t pos, const char* str)
		{
			assert(pos <= _size);
			size_t len = strlen(str);
			if (_size+len>_capacity)
			{
				reserve(_size + len);
			}
			size_t end = len+_size;
			while (end>pos+len-1)
			{
				_str[end] = _str[end-len];
				end--;
			}
			strncpy(_str + pos, str, len);
			_size += len;
			return *this;
		}
		//删除
		mystring& earse(size_t pos, size_t len = npos) 
		{
			assert(pos < _size);
			//删完的情况
			if (len == npos || pos + len >= _size)
			{
				_str[pos] = '\0';
				_size = pos;
			}
			else
			{
				size_t begin = pos + len;
				while (begin<=_size)
				{
					_str[begin-len] = _str[begin];
					begin++;
				}
				_size -= len;
			}
			return *this;
		}

		//查找
		size_t find(char ch,size_t pos=0)
		{
			for (;pos<_size;pos++)
			{
				if (_str[pos]==ch)
				{
					return pos;
				}
			}
			return npos;
		}

		size_t find(const char* str, size_t pos = 0)
		{
			const char*p = strstr(_str+pos,str);
			if (p==nullptr)
			{
				return npos;
			}
			else
			{
				return p - _str;
			}
		}

	private:
		char* _str;
		//增删查改
		size_t _size;
		size_t _capacity;

		//静态声明不能直接给缺省值
		static size_t npos;
		//const static size_t npos=-1;
	};
	size_t mystring::npos = -1;
	 
	//输出流
	ostream& operator<<(ostream& out, const mystring& s)
	{
		//out << s.c_str();
		//可以打印出‘\0’
		for (auto ch : s)
		{
			out << ch;
		}
		return out;
	}
	//输入流
	istream& operator>>(istream& in, mystring& s)
	{
		char ch;
		//in >> ch;  //直接获取不到空格和换行，使用get
		ch = in.get();
		//每次都扩容消耗大
		char buff[128] = { '\0' };
		size_t i = 0;
		while (ch!=' '&& ch!='\n')
		{
			buff[i++]= ch;
			if (i==127)
			{
				s += buff;
				memset(buff, '\0', 128);
				i = 0;
			}
			ch=in.get();
		}
		s += buff;
		return in;
	}

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

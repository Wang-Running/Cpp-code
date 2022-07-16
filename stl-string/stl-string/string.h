#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include <string>
#include <assert.h>

namespace bit
{
	//��string��ֻ������ǳ����
	class mystring
	{
	public:

		//������
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

		//�޲ε�Ĭ�Ϲ���
		/*mystring()
			:_size(0)
			,_capacity(0)
		{
			_str = new char[1];
			_str[0] = '\0';
		}*/

		//�޸�Ϊȫȱʡ
		// "\0":������\0  "":��õ�д��  '\0':�ַ����Ƽ����ַ�\0Ϊ��ָ��
		mystring(const char* str="")
			/*:_str(new char[strlen(str)+1])*/
			//��ɾ���
			:_size(strlen(str))
			, _capacity(_size)
		{
			_str = new char[_capacity+1];
			//�´��'\0'
			strcpy(_str, str);
		}

		//���쿽��s2(s1)
		//ϵͳĬ��Ϊǳ����������������������⣬����Ҫ������
		mystring(const mystring& s)
			:_size(strlen(s._str))
			, _capacity(_size)
		{
			_str = new char[strlen(s._str) + 1];
			strcpy(_str, s._str);
		}

		//���ظ�ֵ�����s1=s3
		//ֱ�ӿ��������ڴ�����̫С�����ж���ȵĻ��ᱻ�ͷŵ�
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

		//��Ϊ���ռ�ʧ�ܺ�����쳣������д�����Ѿ��ͷ���s1--�Ľ�����
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

		//��������
		~mystring()
		{
			if (_str)
			{
				delete[] _str;
				_str = nullptr;
				_size = _capacity = 0;
			}
		}

		//��ȡc��ʽ���ַ���
		const char* c_str() const
		{
			return _str;
		}

		//����[],�����汾
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

		//����size
		size_t size() const
		{
			return  strlen(_str);
			//return _size;
		}

		//����
		size_t capacity() const
		{
			return _capacity;
		}


		//+=����
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

		//reverse����
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

		//resize--���ռ�+��ʼ����ɾ���������ݣ�����ǰn��
		//3���������������,���������ݡ��������������ݡ�С��size��ɾ����
		void resize(size_t n, char ch = '\0')
		{
			//����С��ɾ����
			if (n<_size)
			{
				_size = n;
				_str[_size] = '\0';
			}
			else
			{
				//����--������
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

		//��������
		void push_back(char ch)
		{
			//����
			//if (_size==_capacity)
			//{
			//	/*char* tmp = new char[_capacity * 2 + 1];
			//	strcpy(tmp, _str);
			//	delete[] _str;
			//	_str = tmp;
			//	_capacity *= 2;*/

			//	//����reverse
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

		//�����ַ�
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
		//�����ַ���
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
		//ɾ��
		mystring& earse(size_t pos, size_t len = npos) 
		{
			assert(pos < _size);
			//ɾ������
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

		//����
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
		//��ɾ���
		size_t _size;
		size_t _capacity;

		//��̬��������ֱ�Ӹ�ȱʡֵ
		static size_t npos;
		//const static size_t npos=-1;
	};
	size_t mystring::npos = -1;
	 
	//�����
	ostream& operator<<(ostream& out, const mystring& s)
	{
		//out << s.c_str();
		//���Դ�ӡ����\0��
		for (auto ch : s)
		{
			out << ch;
		}
		return out;
	}
	//������
	istream& operator>>(istream& in, mystring& s)
	{
		char ch;
		//in >> ch;  //ֱ�ӻ�ȡ�����ո�ͻ��У�ʹ��get
		ch = in.get();
		//ÿ�ζ��������Ĵ�
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

	//���������--ʵ���������������и���
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

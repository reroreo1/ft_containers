#ifndef VECTOR_HPP
#define VECTOR_HPP

#include "rev_iterator.hpp"
#include "iterator.hpp"
#include "Utils.hpp"
#include <memory>
#include <iostream>
namespace ft
{
	template <class T, class Allocator = std::allocator<T> >
	class vector
	{
	public:
		// types:
		typedef typename Allocator::reference reference;
		typedef typename Allocator::const_reference const_reference;
		typedef typename Allocator::pointer pointer;
		typedef typename Allocator::const_pointer const_pointer;
		// typedef pointer iterator;
		typedef T value_type;
		typedef iterator<const value_type> const_iterator;
		typedef iterator<value_type> iterator;
		// typedef const_pointer const_iterator;
		typedef size_t size_type;
		typedef ptrdiff_t difference_type;
		typedef Allocator allocator_type;
		typedef reverse_iterator<const_iterator> const_reverse_iterator;
		typedef reverse_iterator<iterator> reverse_iterator;
		// typedef ft::reverse_iterator<iterator> reverse_iterator;


		
		vector(const Allocator &a = Allocator()) :_data(NULL), _alloc(a), _size(0), _capacity(0){

			// _alloc = a;
		}
		explicit vector(size_type n, const T &value = T(),
						const Allocator &a = Allocator())
		{
			_alloc = a;
			_data = _alloc.allocate(n);
			for (size_type i = 0; i < n; i++)
			{
				_alloc.construct(&_data[i], value);
			}
			_size = n;
			_capacity = n;
		};
		template <class InputIterator>
		vector(InputIterator first, InputIterator last,
			   const Allocator &a = Allocator(),typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::value* = NULL)
		{

			construct1(first, last, a);
		}

		vector(const vector<T, Allocator> &x)
		{
			construct1(x.begin(), x.end(), x._alloc);
		};
		~vector()
		{
			if (_data)
			{
				clear();
				_alloc.deallocate(_data, _capacity);
			}
		}
		vector<T, Allocator> &operator=(const vector<T, Allocator> &x)
		{
			clear();
			if (_data)
				_alloc.deallocate(_data, _capacity);
			_data = _alloc.allocate(x._capacity);
			for (size_type i = 0; i < x._size; i++)
			{
				_alloc.construct(&_data[i], x[i]);
			}
			_size = x._size;
			_capacity = x._capacity;
			return (*this);
		}
		template <class InputIterator>
		void assign(InputIterator first, InputIterator last)
		{
			clear();
			if (first == last)
				return ;
			for (; first != last; ++first)
				this->push_back(*first);
		}
		void assign(size_type n, const T &u)
		{
			clear();
			reserve(n);
			for (size_type i = 0; i < n; i++)
				_alloc.construct(&_data[i], u);
			_size = n;
		}
		allocator_type get_allocator() const
		{
			return (_alloc);
		}
		// iterators:
		iterator begin()
		{
			return iterator(_data);
		}
		const_iterator begin() const
		{
			return const_iterator(_data);
		}
		iterator end()
		{
			return iterator(_data + _size);
		}
		const_iterator end() const
		{
			return const_iterator(_data + _size);
		}
		reverse_iterator rbegin()
		{
			return reverse_iterator(end());
		}
		const_reverse_iterator rbegin() const {
			return const_reverse_iterator(end());
		};
		reverse_iterator rend()
		{
			return (reverse_iterator(begin()));
		}
		const_reverse_iterator rend() const
		{
			return const_reverse_iterator(begin());
		}
		size_type size() const
		{
			return (_size);
		}
		size_type max_size() const
		{
			if (sizeof(T) == 1)
				return _alloc.max_size() / 2;
			return _alloc.max_size();
		}
		void resize(size_type sz, T c = T())
		{
			if (sz < 0)
				return ;
			if (sz > max_size())
				throw std::length_error("Bad reserve");
			if (sz < _size)
			{
				for (size_type i = sz; i < _size; i++)
					_alloc.destroy(&_data[i]);
			}
			if (sz > _size)
			{
				for (size_type i = _size; i < sz; i++)
					this->push_back(c);
			}
			_size = sz;
		}
		size_type capacity() const
		{
			return (_capacity);
		}
		bool empty() const
		{
			if (size() == 0)
				return true;
			return false;
		}
		void reserve(size_type n)
		{
			if (n < 0)
				return ;
			T *newData;
			if (n == 0)
				n = 1;
			if (n > max_size())
				throw std::length_error("Bad reserve");
			if (_capacity < n)
			{
				newData = _alloc.allocate(n);
				for (size_type i = 0; i < _size; i++)
				{
					_alloc.construct(&newData[i], _data[i]);
					_alloc.destroy(&_data[i]);
				}
				if (_data)
					_alloc.deallocate(_data, _capacity);
				_data = newData;
				_capacity = n;
			}
		}
		// element access:
		reference operator[](size_type n)
		{
			return (_data[n]);
		}
		const_reference operator[](size_type n) const
		{
			return (_data[n]);
		}
		const_reference at(size_type n) const
		{
			if (n >= _size)
				throw std::out_of_range("out of range");
			return (_data[n]);
		}
		reference at(size_type n)
		{
			if (n >= _size)
				throw std::out_of_range("out of range");
			return (_data[n]);
		}
		reference front()
		{
			return (*begin());
		}
		const_reference front() const
		{
			return (*begin());
		}
		reference back()
		{
			return (*(end() - 1));
		}
		const_reference back() const
		{
			return (*(end() - 1));
		}
		// 23.2.4.3 modifiers:
		void push_back(const T &x)
		{
			if (_size + 1 > _capacity)
			{
				this->reserve(2 * _capacity);
			}
			_alloc.construct((_data + _size), x);
			_size++;
		}
		void pop_back()
		{
			if (_size > 0)
				this->resize(_size - 1);
		};
		iterator insert(iterator position, const T &x)
		{
			int i = 0;
			T *_newData = NULL;
			_newData = _alloc.allocate(_size + 1);  //  check capacity
			for (iterator it = begin(); it != position; it++)
				_alloc.construct(&_newData[i++], *it);
			_alloc.construct(&_newData[i++], x);
			iterator t(_newData + i - 1);
			for (iterator it = position; it != end(); it++)
				_alloc.construct(&_newData[i++], *it);
			for (size_type i = 0; i < _size; i++)
				_alloc.destroy(&_data[i]);
			if (_data)
				_alloc.deallocate(_data, _capacity);
			_data = _newData;
			_size++;
			_capacity = _size;
			return (t);
		}
		void insert(iterator position, size_type n, const T &x)
		{
			int i = 0;
			T *_newData;
			_newData = _alloc.allocate(_size + n);
			for (iterator it = begin(); it != position; it++)
				_alloc.construct(&_newData[i++],*it);
			for (size_type j = 0; j < n; j++)
				_alloc.construct(&_newData[i++],x);
			for (iterator it = position; it != end(); it++)
				_alloc.construct(&_newData[i++],*it);
			for (size_type i = 0; i < _size; i++)
				_alloc.destroy(&_data[i]);
			if (_data)
				_alloc.deallocate(_data, _capacity);
			_data = _newData;
			_capacity = _size + n;
			_size += n;
		}
		template <class InputIterator>
		void insert(iterator position, InputIterator first, InputIterator last , typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::value* = NULL)
		{
			vector<T> tmp;
			for (;first != last; first++)
				tmp.push_back(*first);
			int i = 0;
			T *_newData;
			size_type a = tmp.size();
			_newData = _alloc.allocate(_size + a);
			for (iterator it = begin(); it != position; it++)
				_alloc.construct(&_newData[i++],*it);
			for (iterator it = tmp.begin(); it != tmp.end(); it++)
				_alloc.construct(&_newData[i++],*it);
			for (iterator it = position; it != end(); it++)
				_alloc.construct(&_newData[i++],*it);
			for (size_type i = 0; i < _size; i++)
				_alloc.destroy(&_data[i]);
			if (_data)
				_alloc.deallocate(_data, _capacity);
			_data = _newData;
			_capacity = _size + a;
			_size += a;
		}
		iterator erase(iterator position)
		{
			for (iterator it = position; it < end() - 1; it++)
				*it = *(it + 1);
			pop_back();
			return (iterator(position));
		}

		iterator erase(iterator first, iterator last)
		{
			difference_type diff = first - begin();
            difference_type range = last - first;
            for(size_t i = diff; i < _size - 1; i++){
				// std::cout << "i == " << i << std::endl;
				iterator it = iterator(&_data[i]);
                if(i + range < _size)
                	it = erase(it);
			}
			for(size_type i = _size; i < _size + range; i++)
				_alloc.destroy(&_data[i]);
			_size -= range;
            return (begin() + diff);
		}

		void swap(vector<T, Allocator> &y)
		{
			std::swap(this->_data, y._data);
			std::swap(this->_size, y._size);
			std::swap(this->_capacity, y._capacity);
			std::swap(this->_alloc, y._alloc);
		}
		void clear()
		{
			for (size_type i = 0; i < _size; i++)
			{
				_alloc.destroy(&_data[i]);
			}
			_size = 0;
		}

	private:
		// posize_typeer to the underlying array allocated by the allocator
		T *_data;
		 Allocator _alloc;
		size_t _size;
		size_t _capacity;
		template <typename InputIterator>
		void construct1(InputIterator first, InputIterator last, const Allocator &a = Allocator()) 
		{
			_alloc = a;
			_size = 0;
			_capacity = 0;
			_data = _alloc.allocate(_size);
			for (; first != last; first++)
				this->push_back(*first);
		}

	};
	template <class T, class Allocator>
	bool operator==(const vector<T, Allocator> &x, const vector<T, Allocator> &y)
	{
		if (x.size() != y.size())
			return (false);
		for (size_t i = 0; i < x.size(); i++)
			if (x[i] != y[i])
				return (false);
		return (true);
	}
	template <class T, class Allocator>
	bool operator<(const vector<T, Allocator> &x,
				   const vector<T, Allocator> &y)
	{
		return (ft::lexicographical_compare(x.begin(), x.end(), y.begin(), y.end()));
	}
	template <class T, class Allocator>
	bool operator!=(const vector<T, Allocator> &x,
					const vector<T, Allocator> &y)
	{
		return (!(x == y));
	}
	template <class T, class Allocator>
	bool operator>(const vector<T, Allocator> &x,
				   const vector<T, Allocator> &y)
	{
		return (y < x && x != y);
	}
	template <class T, class Allocator>
	bool operator>=(const vector<T, Allocator> &x,
					const vector<T, Allocator> &y)
	{
		return (!(x < y));
	}
	template <class T, class Allocator>
	bool operator<=(const vector<T, Allocator> &x,
					const vector<T, Allocator> &y)
	{
		return (!(x > y));
	}
	template <class TT, class Allocator__>
	void swap(vector<TT, Allocator__> &x, vector<TT, Allocator__> &y)
	{
		x.swap(y);
	}
};

#endif
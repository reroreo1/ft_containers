#ifndef VECTOR_HPP
#define VECTOR_HPP

#include "rev_iterator.hpp"
#include "iterator.hpp"
#include "Utils.hpp"
#include <memory>

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
		//typedef pointer iterator;
		typedef T value_type;
		typedef  iterator<const value_type>			const_iterator;
		typedef iterator<value_type>		iterator;
		// typedef const_pointer const_iterator;
		typedef size_t size_type;
		typedef ptrdiff_t difference_type;
		typedef Allocator allocator_type;
		typedef reverse_iterator<const_iterator> const_reverse_iterator;
		typedef reverse_iterator<iterator> reverse_iterator;
		// typedef ft::reverse_iterator<iterator> reverse_iterator;
	
		explicit vector(const Allocator &a = Allocator()) : _data(NULL)	, _alloc(a), _size(0), _capacity(0){
	
																				};
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
			   const Allocator &a = Allocator())
		{
			construct(first,last,a);
		}

		vector(const vector<T, Allocator> &x){
			construct(x.begin(),x.end(),x.get_allocator());
		};
		~vector(){
			clear();
			_alloc.deallocate(_data,_capacity);
		}
		//not working >> 
		vector<T, Allocator> &operator=(const vector<T, Allocator> &x){
			clear();
			if (!_data)
				_alloc.deallocate(_data,_capacity);
			_data = _alloc.allocate(x._capacity);
			for(size_type i = 0; i < x._size; i++){
				_alloc.construct(&_data[i],x[i]);
			}
			_size = x._size;
			_capacity = x._capacity;
			return (*this);
		}
		template <class InputIterator>
		void assign(InputIterator first, InputIterator last){
				
		}
		void assign(size_type n, const T &u){

		}
		allocator_type get_allocator() const{
			return (_alloc);
		}
		// iterators:
		iterator begin(){
			// printf("%p\n", _data + _size );
			return iterator(_data);
		}
		const_iterator begin() const
		{
			return const_iterator(_data);
		}
		iterator end(){
			return iterator(_data + _size);
		}
		const_iterator end() const
		{
			return const_iterator(_data + _size);
		}
		reverse_iterator rbegin(){
			return reverse_iterator(end());
		}
		const_reverse_iterator rbegin() const{};
		reverse_iterator rend(){
			return(reverse_iterator(begin()));
		}
		const_reverse_iterator rend() const{
			return const_reverse_iterator(begin());
		}
		size_type size() const{
			return (_size);
		}
		size_type max_size() const{
			return _alloc.max_size();
		}
		void resize(size_type sz, T c = T()){
			if (sz < _size){
				for (size_type i = sz; i < _size; i++)
					_alloc.destroy(&_data[i]);
			}
			else if (sz > _size)
			{
				for (size_type i = _size; i < sz; i++)
					this->push_back(c);
			}
			_size = sz;
		}
		size_type capacity() const{
			return (_capacity);
		}
		bool empty() const{
			if (!_size)
				return true;
			return false;
		}
		void reserve(size_type n){
			if (n == 0)
				n = 1;
			if (_capacity < n){
				T* newData = _alloc.allocate(n);
				for (size_type i = 0; i < _size; i++){
					_alloc.construct(&(newData[i]),_data[i]);
					_alloc.destroy(&_data[i]);
				}
				_alloc.deallocate(_data,_capacity);
				_data = newData;
				_capacity = n;
			}
		}
		// element access:
		reference operator[](size_type n);
		const_reference operator[](size_type n) const;
		const_reference at(size_type n) const;
		reference at(size_type n);
		reference front();
		const_reference front() const;
		reference back();
		const_reference back() const;
		// 23.2.4.3 modifiers:
		void push_back(const T &x){
			if (_size + 1 > _capacity){
				this->reserve(2 * _capacity);
				_capacity *= 2; 
			}
			_alloc.construct(&(_data[_size]) , x);
			_size++;
		}
		void pop_back(){
			if (_size > 0)
				this->resize(_size - 1);
		};
		iterator insert(iterator position, const T &x);
		void insert(iterator position, size_type n, const T &x);
		template <class InputIterator>
		void insert(iterator position, InputIterator first, InputIterator last);
		iterator erase(iterator position);
		iterator erase(iterator first, iterator last);
		void swap(vector<T, Allocator> &);
		void clear(){
			for (size_type i = 0; i < _size;i++)
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
		void construct(InputIterator first, InputIterator last,
			   const Allocator &a = Allocator()){
			_alloc = a;
			_size = 0;
			_capacity = 0;
			_data = a.allocate(_size);
			for (; first != last; first++)
				this->push_back(*first);
		}
};
	template <class T, class Allocator>
	bool operator==(const vector<T, Allocator> &x, const vector<T, Allocator> &y);
	template <class T, class Allocator>
	bool operator<(const vector<T, Allocator> &x,
				   const vector<T, Allocator> &y);
	template <class T, class Allocator>
	bool operator!=(const vector<T, Allocator> &x,
					const vector<T, Allocator> &y);
	template <class T, class Allocator>
	bool operator>(const vector<T, Allocator> &x,
				   const vector<T, Allocator> &y);
	template <class T, class Allocator>
	bool operator>=(const vector<T, Allocator> &x,
					const vector<T, Allocator> &y);
	template <class T, class Allocator>
	bool operator<=(const vector<T, Allocator> &x,
					const vector<T, Allocator> &y);
	// specialized algorithms:
	template <class T, class Allocator>
	void swap(vector<T, Allocator> &x, vector<T, Allocator> &y);
}

#endif
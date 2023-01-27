#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <memory>
namespace ft
{
	template <class T, class Allocator = std::allocator<T>>
	class vector
	{
	public:
		// types:
		typedef typename Allocator::reference reference;
		typedef typename Allocator::const_reference const_reference;
		typedef typename Allocator::pointer pointer;
		typedef typename Allocator::const_pointer const_pointer;
		typedef pointer iterator;
		typedef const_pointer const_iterator;
		typedef size_t size_type;
		typedef ptrdiff_t difference_type;
		typedef T value_type;
		typedef Allocator allocator_type;
		typedef std::reverse_iterator<iterator> reverse_iterator;
		typedef std::reverse_iterator<const_iterator> const_reverse_iterator;

		explicit vector(const Allocator &a = Allocator()) : _alloc(a), _size(0), _capacity(0){

																				};
		explicit vector(size_type n, const T &value = T(),
						const Allocator & = Allocator())
		{
			_data = _alloc.allocate(n);
			for (int i = 0; i < n; i++)
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
			construct(x.begin(),x,end(),_alloc);
		};
		~vector(){
			for (int i = 0; i < _capacity;i++)
			{
				_alloc.destroy(&data[i]);
			}
			_alloc.deallocate(_data,_capacity);
		}
		//not working >> 
		vector<T, Allocator> &operator=(const vector<T, Allocator> &x){
			_alloc = x.get_allocator();
			construct(x.begin(),x.end(),_alloc);
			return (*this);
		}
		template <class InputIterator>
		void assign(InputIterator first, InputIterator last){

		}
		void assign(size_type n, const T &u){

		}
		allocator_type get_allocator() const{
			return (_alloc);
		};
		// iterators:
		iterator begin();
		const_iterator begin() const;
		iterator end();
		const_iterator end() const;
		reverse_iterator rbegin();
		const_reverse_iterator rbegin() const;
		reverse_iterator rend();
		const_reverse_iterator rend() const;
		// 23.2.4.2 capacity:
		size_type size() const{
			return (_size);
		}
		size_type max_size() const{
			return _alloc.max_size();
		}
		void resize(size_type sz, T c = T()){
			if (sz < _size){
				for (int i = sz; i < size; i++)
					_alloc.destroy(&_data[i]);
			}
			else if (sz > size)
			{
				for (int i = size; i < sz; i++)
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
			if (_capacity < n){
				T* newData = _alloc.allocate(n);
				for (int i = 0; i < _size; i){
					_alloc.construct(newData[i],_data[i]);
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
				this->reserve(2 * capacity);
				_capacity *= 2; 
			}
			_alloc.construct(_data[_size] , x);
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
		void clear();
	private:
// pointer to the underlying array allocated by the allocator
		T *_data;
		Allocator _alloc;
		size_t _size;
		size_t _capacity;
		void construct(InputIterator first, InputIterator last,
			   const Allocator &a = Allocator()){
			_alloc = a;
			_size = 0;
			_capacity = 0;
			_data = a.allocate(size);
			for (; first != last; first++)
				_this.push_back(*first);
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
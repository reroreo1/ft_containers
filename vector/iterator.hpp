#pragma once

#include "Utils.hpp"
namespace ft
{
	template <class T>
	class iterator : public std::iterator<std::random_access_iterator_tag, T>
	{
	protected:
		T *current;

	public:
		typedef   T    value_type ;
        typedef  std::ptrdiff_t  difference_type ;
        typedef T*  pointer ;
        typedef  T&  reference ;
        typedef std::random_access_iterator_tag iterator_category;
			// pointer;
		operator iterator<const T> ()
		{
			return iterator<const T>(this->base());
		}

		operator iterator< const T> () const
		{
			return iterator<const T>(this->base());
		}


		//    template <typename   U> operator const U () {return current;}

		explicit iterator(pointer x)
		{
			current = x;
		}


		 iterator()
		{
			this->current = NULL;
		}


		iterator operator=(const  iterator &lh  ) 
		{
 			this->current = lh.base();
			return (*this);
		}

		template <class U>
		iterator(const iterator<U> &u)
		{
			current = u.base();
		}
		pointer base() const
		{
			return (current);
		} // explicit
		reference operator*() const
		{
			pointer tmp = current;
			return *tmp;
		}
		pointer operator->() const
		{
			return &(operator*());
		}
		iterator &operator++()
		{
			++current;
			return (*this);
		}
		iterator operator++(int)
		{
			iterator tmp = *this;
			++current;
			return tmp;
		}
		iterator &operator--()
		{
			--current;
			return (*this);
		}
		iterator operator--(int)
		{
			iterator tmp = *this;
			--current;
			return tmp;
		}
		iterator operator+(difference_type n) const
		{
			iterator(current + n);
			return (*this);
		}
		iterator &operator+=(difference_type n)
		{
			current += n;
			return *this;
		}
		iterator operator-(difference_type n) const
		{
			iterator(current - n);
			return (*this);
		}
		iterator &operator-=(difference_type n)
		{
			current -= n;
			return (*this);
		}
		reference operator[](difference_type n) const
		{
			return (current[n]);
		}
	};
	template <class T>
	bool operator==(
		const iterator<T> &x,
		const iterator<T> &y)
	{
				printf("[%p] [%p]\n",x.base(), y.base() );

		return (x.base() == y.base());
	}
	template <class L, class R>
	bool operator<(
		const iterator<L> &x, // when you will get error while comparing const iterator and iterator plase add another type to template class Iterator1 Iterator2 so all type can work
		const iterator<R> &y)
	{
		return (x.base() < y.base());
	}

	template <class L, class R>
	bool operator!=(
		const iterator<L> &x,
		const iterator<R> &y)
	{
		return (x.base() != y.base());
	}
	template <class L, class R>
	bool operator>(
		const iterator<L> &x,
		const iterator<R> &y)
	{
		return (x.base() > y.base());
	}
	template <class L, class R>
	bool operator>=(const iterator<L> &x, const iterator<R> &y)
	{
		return (x.base() >= y.base());
	}
	template <class L, class R>
	bool operator<=(
		const iterator<L> &x,
		const iterator<R> &y)
	{
		return (x.base() <= y.base());
	}
	template <class T>
	typename iterator<T>::difference_type operator-(
		const iterator<T> &x,
		const iterator<T> &y)
	{
		return y.base() - x.base();
	}
	template <class T>
	iterator<T> operator+(
		typename iterator<T>::difference_type n,
		const iterator<T> &x)
	{
		return iterator<T>(x.base() + n);
	}
}

// 'ft::vector<char>::const_iterator' (aka 'iterator<const char>') and 'ft::vector<char, std::__1::allocator<char> >::iterator' (aka 'iterator<char>'))
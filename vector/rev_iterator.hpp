#pragma once
#include "iterator.hpp"
#include "Utils.hpp"
namespace ft
{
	template <class T>
	class reverse_iterator
	{
	protected:
		T current;

	public:
		typedef   T    value_type ;
        typedef  std::ptrdiff_t  difference_type ;
        typedef typename T::pointer  pointer ;
        typedef typename  T::reference  reference ;
        typedef std::random_access_iterator_tag iterator_category;

		// operator reverse_iterator<const T> ()
		// {
		// 	return reverse_iterator<const T>(this->base());
		// }

		// operator reverse_iterator< const T> () const
		// {
		// 	return reverse_iterator<const T>(this->base());
		// }
		reverse_iterator() 
		{
			this->current = T();
		}
		explicit reverse_iterator(T x)
		{
			current = x;
		}

		reverse_iterator operator=(const  reverse_iterator &lh  ) 
		{
 			this->current = lh.base();
			return (*this);
		}

		template <class U>
		reverse_iterator(const reverse_iterator<U> &u)
		{
			current = u.base();
		}
		T base() const
		{
			return (current);
		} // explicit
		reference operator*() const
		{
			T tmp = current;
			return (*--tmp);
		}
		pointer operator->() const
		{
			return (pointer)&(operator*());
		}
		reverse_iterator &operator++()
		{
			--current;
			return (*this);
		}
		reverse_iterator operator++(int)
		{
			reverse_iterator tmp = *this;
			--current;
			return (tmp);
		}
		reverse_iterator &operator--()
		{
			++current;
			return (*this);
		}
		reverse_iterator operator--(int)
		{
			reverse_iterator tmp = *this;
			++current;
			return (tmp);
		}
		reverse_iterator operator+(difference_type n) const
		{
			return reverse_iterator(current - n);
		}
		reverse_iterator &operator+=(difference_type n)
		{
			current -= n;
			return (*this);
		}
		reverse_iterator operator-(difference_type n) const
		{
			return reverse_iterator(current + n);
		}
		reverse_iterator &operator-=(difference_type n)
		{
			current += n;
			return (*this);
		}
		reference operator[](difference_type n) const
		{
			return (current[-n - 1]);
		}
	};
	template <class L, class R>
	bool operator==(
		const reverse_iterator<L> &x,
		const reverse_iterator<R> &y)
	{
		return (x.base() == y.base());
	}
	template <class L, class R>
	bool operator<(
		const reverse_iterator<L> &x,
		const reverse_iterator<R> &y)
	{
		return (x.base() > y.base());
	}

	template <class L, class R>
	bool operator>(
		const reverse_iterator<L> &x,
		const reverse_iterator<R> &y)
	{
		return (x.base() < y.base());
	}

	template <class L, class R>
	bool operator>=(const reverse_iterator<L> &x, const reverse_iterator<R> &y)
	{
		return (x.base() <= y.base());
	}

	template <class L, class R>
	bool operator<=(
		const reverse_iterator<L> &x,
		const reverse_iterator<R> &y)
	{
		return (x.base() >= y.base());
	}
	template <class T>
	typename reverse_iterator<T>::difference_type operator-(
		const reverse_iterator<T> &x,
		const reverse_iterator<T> &y)
	{
		return (y.base() - x.base());
	}
	template <class T>
	reverse_iterator<T> operator+(
		typename reverse_iterator<T>::difference_type n,
		const reverse_iterator<T> &x)
	{
		return  reverse_iterator<T>(x.base() - n);
	}


	template <class L, class R>
	bool operator!=(
		const reverse_iterator<L> &x,
		const reverse_iterator<R> &y)
	{
		return (x.base() != y.base());
	}
};
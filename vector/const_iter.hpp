#pragma once

#include "Utils.hpp"
namespace ft
{
	template <class Iterator>
	class iterator
	{
	protected:
		Iterator current;

	public:
		typedef Iterator
			iterator_type;
		typedef typename iterator_traits<Iterator>::difference_type
			difference_type;
		typedef typename iterator_traits<Iterator>::reference
			reference;
		typedef typename iterator_traits<Iterator>::pointer
			pointer;
		iterator() {}
		explicit iterator(Iterator x)
		{
			current = x;
		}
		template <class U>
		iterator(const iterator<U> &u)
		{
			current = u.current;
		}
		Iterator base() const
		{
			return (current);
		} // explicit
		reference operator*() const
		{
			Iterator tmp = current;
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
	template <class Iterator>
	bool operator==(
		const iterator<Iterator> &x,
		const iterator<Iterator> &y)
	{
		return (x.base() == y.base());
	}
	template <class Iterator>
	bool operator<(
		const iterator<Iterator> &x, // when you will get error while comparing const iterator and iterator plase add another type to template class Iterator1 Iterator2 so all type can work
		const iterator<Iterator> &y)
	{
		return (x.base() < y.base());
	}
	template <class Iterator>
	bool operator!=(
		const iterator<Iterator> &x,
		const iterator<Iterator> &y)
	{
		return (x.base() != y.base());
	}
	template <class Iterator>
	bool operator>(
		const iterator<Iterator> &x,
		const iterator<Iterator> &y)
	{
		return (x.base() > y.base());
	}
	template <class Iterator>
	bool operator>=(const iterator<Iterator> &x, const iterator<Iterator> &y)
	{
		return (x.base() >= y.base());
	}
	template <class Iterator>
	bool operator<=(
		const iterator<Iterator> &x,
		const iterator<Iterator> &y)
	{
		return (x.base() <= y.base());
	}
	template <class Iterator>
	typename iterator<Iterator>::difference_type operator-(
		const iterator<Iterator> &x,
		const iterator<Iterator> &y)
	{
		return y.base() - x.base();
	}
	template <class Iterator>
	iterator<Iterator> operator+(
		typename iterator<Iterator>::difference_type n,
		const iterator<Iterator> &x)
	{
		return iterator<Iterator>(x.base() + n);
	}
}
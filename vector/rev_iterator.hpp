#pragma once
#include "iterator.hpp"
#include "Utils.hpp"
namespace ft
{
	template <class Iterator>
	class reverse_iterator
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
		reverse_iterator() 
		{
			this->current = Iterator();
		}
		explicit reverse_iterator(Iterator x)
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
			current = u.current;
		}
		Iterator base() const
		{
			return (current);
		} // explicit
		reference operator*() const
		{
			Iterator tmp = current;
			return (*--tmp);
		}
		pointer operator->() const
		{
			return &(operator*());
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
	template <class Iterator>
	bool operator==(
		const reverse_iterator<Iterator> &x,
		const reverse_iterator<Iterator> &y)
	{
		return (x.base() == x.base());
	}
	template <class Iterator>
	bool operator<(
		const reverse_iterator<Iterator> &x,
		const reverse_iterator<Iterator> &y)
	{
		return (x.base() > y.base());
	}
	template <class Iterator>
	bool operator!=(
		const reverse_iterator<Iterator> &x,
		const reverse_iterator<Iterator> &y)
	{
		return (x.base() != y.base());
	}
	template <class Iterator>
	bool operator>(
		const reverse_iterator<Iterator> &x,
		const reverse_iterator<Iterator> &y)
	{
		return (x.current < y.current);
	}
	template <class Iterator>
	bool operator>=(const reverse_iterator<Iterator> &x, const reverse_iterator<Iterator> &y)
	{
		return (x.current <= y.current);
	}
	template <class Iterator>
	bool operator<=(
		const reverse_iterator<Iterator> &x,
		const reverse_iterator<Iterator> &y)
	{
		return (x.current >= y.current);
	}
	template <class Iterator>
	typename reverse_iterator<Iterator>::difference_type operator-(
		const reverse_iterator<Iterator> &x,
		const reverse_iterator<Iterator> &y)
	{
		return (y.current - x.current);
	}
	template <class Iterator>
	reverse_iterator<Iterator> operator+(
		typename reverse_iterator<Iterator>::difference_type n,
		const reverse_iterator<Iterator> &x)
	{
		return  reverse_iterator<Iterator>(x.current - n);
	}
};
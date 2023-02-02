#ifndef UTILS_HPP
#define UTILS_HPP

#include <iterator>

template <class T>
struct is_integral
{
};
template <class T>
struct iterator_traits
{
   typedef typename T::value_type value_type;
   typedef typename T::difference_type difference_type;
   typedef typename T::pointer pointer;
   typedef typename T::reference reference;
   typedef typename T::iterator_category iterator_category;
};

// Specialization
template <class T>

struct iterator_traits<T *>
{
   typedef T value_type;
   typedef ptrdiff_t difference_type;
   typedef T *pointer;
   typedef T &reference;
   typedef std::random_access_iterator_tag iterator_category;
};

template <class T>

struct iterator_traits<const T *>
{
   typedef T value_type;
   typedef const ptrdiff_t difference_type;
   typedef const T *pointer;
   typedef T &reference;
   typedef std::random_access_iterator_tag iterator_category;
};

namespace ft
{
   template <class InputIt1, class InputIt2>
   bool lexicographical_compare(InputIt1 first1, InputIt1 last1,
                                InputIt2 first2, InputIt2 last2)
   {
      for (; (first1 != last1) && (first2 != last2); ++first1, (void)++first2)
      {
         if (*first1 < *first2)
            return true;
         if (*first2 < *first1)
            return false;
      }

      return (first1 == last1) && (first2 != last2);
   }
   template<bool B, class T = void>
   struct enable_if {};
   
   template<class T>
   struct enable_if<true, T> { typedef T type; };


   template <typename T>
   struct is_integral
   {
      static const bool value = false;
   };

   template <>
   struct is_integral<bool>
   {
      static const bool value = true;
   };

   template <>
   struct is_integral<char>
   {
      static const bool value = true;
   };

   template <>
   struct is_integral<signed char>
   {
      static const bool value = true;
   };

   template <>
   struct is_integral<char16_t>
   {
      static const bool value = true;
   };
   template <>
   struct is_integral<char32_t>
   {
      static const bool value = true;
   };
   template <>
   struct is_integral<wchar_t>
   {
      static const bool value = true;
   };
   template <>
   struct is_integral<short int>
   {
      static const bool value = true;
   };
   template <>
   struct is_integral<int>
   {
      static const bool value = true;
   };
   template <>
   struct is_integral<long int>
   {
      static const bool value = true;
   };
   template <>
   struct is_integral<long long int>
   {
      static const bool value = true;
   };
   template <>
   struct is_integral<unsigned short int>
   {
      static const bool value = true;
   };
   template <>
   struct is_integral<unsigned int>
   {
      static const bool value = true;
   };
   template <>
   struct is_integral<unsigned long int>
   {
      static const bool value = true;
   };
   template <>
   struct is_integral<unsigned long long int>
   {
      static const bool value = true;
   };
   template <>
   struct is_integral<unsigned char>
   {
      static const bool value = true;
   };

}

#endif
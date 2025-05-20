
#ifndef  __REQUIREMENTS_HPP__
# define __REQUIREMENTS_HPP__

# include <limits>
# include <typeinfo>
# include "declaration/iterator_tags.hpp"

# define static_assert(expr) struct static_assertion { char assertion_on_line_##__LINE__[(expr) ? 1 : -1]; }

# ifdef REQUIRE_STRICT
#  define REQUIRE_ATTR __attribute__((used))
# else
#  define REQUIRE_ATTR 
# endif

namespace ft {
	template<typename T> struct non_const {};
	template<typename T> struct non_const<const T>;

	template<typename T> struct non_reference {};
	template<typename T> struct non_reference<T &>;

	template<typename T> struct remove_const { typedef T type; };
	template<typename T> struct remove_const<const T> { typedef T type; };

	template<typename T> struct is {
		template<typename U>
		static void test(U)
		{ bool is<T>::* _same(& is<U>::_); (void)_same; };

		template<typename U>
		static void test()
		{ bool is<T>::* _same(& is<U>::_); (void)_same; };
		bool _;
	};

	template<typename T> struct is<T&> {
		template<typename U>
		static void test(U &)
		{ bool is<T&>::* _same(& is<U&>::_); (void)_same; };

		template<typename U>
		static void test()
		{ bool is<T&>::* _same(& is<U>::_); (void)_same; };
		bool _;
	};

	template<typename T, typename U>
	void is_same(T,U u)
	{ is<T>::template test<U>(u); }
	template<typename T, typename U>
	void is_same()
	{ is<T>::template test<U>(); }

	template<typename T>
	struct convertible_to {
		template<typename U>
		static void test(U u)
		{ (void)T(u); };
	};

	template<typename T,typename U>
	class is_convertible {
		__attribute__((used)) static void _require(U u)
		{ (void)T(u); };
	};

	template<typename T>
	class is_copy_assignable {
		__attribute__((used)) static void _require(T t1, T t2)
		{ is<T>::test(t1=t2); };
	};

	template<typename T>
	class is_copy_constructible {
		__attribute__((used)) static void _require(const T & t)
		{ is<const T*>::test(&t); (void)T(t); };
	};

	template<typename T>
	class is_destructible {
		__attribute__((used)) static void _require(T t)
		{ t.~T(); };
	};

	template<typename T>
	class is_swappable {
		__attribute__((used)) static void _require(T t1, T t2)
		{ using std::swap; swap(t1,t2); };
	};

	template<typename T>
	class is_equality_comparable {
		__attribute__((used)) static void _require(T t1, T t2)
		{
			is<bool>::test(t1 == t2);
			is<bool>::test(t1 != t2);
		};
	};

	template<typename It, typename T>
	class is_iterator :
		private is_copy_constructible<It>,
		private is_copy_assignable<It>,
		private is_destructible<It>,
		private is_swappable<It>
	{
		__attribute__((used)) static void _require(It & it)
		{
			is_same<typename It::reference, 	T &>();
			is_same<typename It::pointer,   	T *>();
			(void)convertible_to<T>::test(*it);
			is<It&>::test(++it);
		};
	};

	template<typename It, typename T>
	class is_input_iterator :
		private is_iterator<It, T>,
		private is_equality_comparable<It>
	{
		__attribute__((used)) static void _require(It & it)
		{
			convertible_to<typename It::value_type>::test(*it);
			convertible_to<typename It::value_type>::test(*it++);
		};
	};

	template<typename A, typename T>
	class is_allocator :
		private non_const<T>,
		private non_reference<T>
   	{
		__attribute__((used)) static void _require()
		{
			is_same<typename A::value_type,    	T>();
		};
	};

	template<typename C, typename T>
	class is_container {
		__attribute__((used)) static void _require(C &, T &)
		{
			is_same<typename C::value_type,      	T>();
			is_same<typename C::reference,       	T&>();
			is_same<typename C::const_reference, 	const T&>();

			is_allocator<typename C::allocator_type, 	T>();
			is_iterator<typename C::const_iterator,  	const T>();
			is_iterator<typename C::iterator,        	T>();

			is_convertible<typename C::const_iterator, typename C::iterator>();

			is<typename C::difference_type>::template test<typename C::iterator::difference_type>();
			is<typename C::difference_type>::template test<typename C::const_iterator::difference_type>();
		};
	};
}

#endif


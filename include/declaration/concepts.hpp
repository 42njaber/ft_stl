
#ifndef  __STATIC_ASSERT_HPP__
# define __STATIC_ASSERT_HPP__

# include <typeinfo>

# define static_assert(expr) struct static_assertion { char assertion_on_line_##__LINE__[(expr) ? 1 : -1]; }

namespace ft {
	template<typename T> struct _ {};
	template<typename T1, typename T2>
	void is_same(T1,T2) {
		_<T1> v1; _<T2> v2 = v1;
		(void)v2;
	}

	template<typename T>
	class copy_assignable {
		__attribute__((used))
		static void require(T t1, T t2) {
			is_same(t1,(t2 = t1));
		};
	};
}

#endif


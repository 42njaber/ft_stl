
#ifndef  __REQUIREMENTS_HPP__
# define __REQUIREMENTS_HPP__

# include <typeinfo>

# define static_assert(expr) struct static_assertion { char assertion_on_line_##__LINE__[(expr) ? 1 : -1]; }

# ifdef REQUIRE_STRICT
#  define requires struct _requires;
# else
#  define REQUIRE_DEF 
# endif

namespace ft {
	namespace {
		template<typename T> class is {
			const char sig;
			const char * is<T>::*test;
			public: template<typename U> is(U): sig(), test(& is<U>::sig) {};
		};
	}
	template<typename T, typename U> void is_same(T,U u) {
		is<T> _(u);
	}

	template<typename T>
	class copy_assignable {
		__attribute__((used))
		static void _require(T t1, T t2) {
			is<T>(t1=t2);
		};
	};
}

#endif


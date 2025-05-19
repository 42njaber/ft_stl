
#ifndef  __COMMON_HPP__
# define __COMMON_HPP__

# include <cstddef>

namespace ft {
	template<typename T, typename A>
	struct _Container {
		typedef T                  	value_type;
		typedef size_t             	size_type;
		typedef ptrdiff_t          	difference_type;
		typedef value_type &       	reference;
		typedef const value_type & 	const_reference;

		typedef A                         	allocator_type;
		typedef typename A::pointer       	pointer;
		typedef typename A::const_pointer 	const_pointer;
	};
}

#endif


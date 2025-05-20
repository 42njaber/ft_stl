
#ifndef  __VECTOR_HPP__
# define __VECTOR_HPP__

# include "declaration/common.hpp"
# include "declaration/requirements.hpp"
# include "declaration/iterator.hpp"

# include <memory>

namespace ft {

	template< typename T, typename A=std::allocator<T> >
	class vector :
		public _Container<T,A>,
		public iterator::_IterableContainer<contiguous_iterator_tag,vector<T,A> >,
		private is_copy_assignable<T>,
		private is_copy_constructible<T>,
		private is_allocator<A,T>
	{
		REQUIRE_ATTR static void _require(is_container<vector, T>) {};

	public:
		// explicit vector( const Allocator& alloc = Allocator() );
		// explicit vector( size_type count, const T& value = T(), const Allocator& alloc = Allocator() );
		// template< class InputIt >
		// vector( InputIt first, InputIt last, const Allocator& alloc = Allocator() );
		// vector( const vector& other );
	};
}

#endif

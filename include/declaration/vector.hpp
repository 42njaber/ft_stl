
#ifndef  __VECTOR_HPP__
# define __VECTOR_HPP__

# include "declaration/common.hpp"
# include "declaration/requirements.hpp"
# include "declaration/iterators.hpp"

# include <memory>

namespace ft {

	template< typename T, typename Allocator=std::allocator<T> >
	class vector :
		public _Container<T,Allocator>,
		private copy_assignable< T >
	{
		// explicit vector( const Allocator& alloc = Allocator() );
		// explicit vector( size_type count, const T& value = T(), const Allocator& alloc = Allocator() );
		// template< class InputIt >
		// vector( InputIt first, InputIt last, const Allocator& alloc = Allocator() );
		// vector( const vector& other );
	};
}

#endif

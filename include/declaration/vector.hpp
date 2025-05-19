
#ifndef  __VECTOR_HPP__
# define __VECTOR_HPP__

# include "declaration/types.hpp"
# include "declaration/concepts.hpp"
# include "declaration/iterators.hpp"

# include <memory>

namespace ft {

	template< typename T, typename Allocator=std::allocator<T> >
	class vector {
	private:
		static copy_assignable< T > value_type_copy_assignable;
	public:
		typedef T         	value_type;
		typedef Allocator 	allocator_type;
		typedef size_t    	size_type;
		typedef ptrdiff_t 	difference_type;

		typedef value_type&                       	reference;
		typedef const reference                   	const_reference;
		typedef typename Allocator::pointer       	pointer;
		typedef typename Allocator::const_pointer 	const_pointer;

		typedef iterators::random_access< vector<T> >       	iterator;
		typedef iterators::random_access< const vector<T> > 	const_iterator;
		typedef iterators::reverse< iterator >              	reverse_iterator;
		typedef iterators::reverse< const_iterator >        	const_reverse_iterator;

		// explicit vector( const Allocator& alloc = Allocator() );
		// explicit vector( size_type count, const T& value = T(), const Allocator& alloc = Allocator() );
		// template< class InputIt >
		// vector( InputIt first, InputIt last, const Allocator& alloc = Allocator() );
		// vector( const vector& other );
	};
}

#endif

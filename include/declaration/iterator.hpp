
#ifndef  __ITERATORS_HPP__
# define __ITERATORS_HPP__

# include "declaration/iterator_tags.hpp"

namespace ft {

	namespace iterator {
		template<typename C> struct _Iterator {
			typedef typename C::difference_type 	difference_type;
			typedef typename C::value_type      	value_type;
			typedef typename C::reference       	reference;
			typedef typename C::pointer         	pointer;
		};

		template<typename C> struct _Iterator<const C> {
			typedef typename C::difference_type 	difference_type;
			typedef typename C::value_type      	value_type;
			typedef typename C::const_reference 	reference;
			typedef typename C::const_pointer   	pointer;
		};

		template<typename C>
		struct contiguous : public _Iterator<C> {
			typedef contiguous_iterator_tag iterator_category;

			contiguous( const contiguous<typename remove_const<C>::type> & );

			typename _Iterator<C>::value_type & operator*() const;
			contiguous & operator++();
		};

		template<typename Iterator>
		class reverse {
		};

		template<typename Tag, typename C> struct _IterableContainer;
		template<typename C>
		struct _IterableContainer<contiguous_iterator_tag, C> {
			typedef contiguous<const C> 	const_iterator;
			typedef contiguous<C>       	iterator;
		};
	}
}

#endif


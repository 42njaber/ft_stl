
#ifndef  __ITERATOR_TAGS_HPP__
# define __ITERATOR_TAGS_HPP__

# include <iterator>

namespace ft
{
	typedef std::input_iterator_tag         	input_iterator_tag;
	typedef std::output_iterator_tag        	output_iterator_tag;
	typedef std::forward_iterator_tag       	forward_iterator_tag;
	typedef std::bidirectional_iterator_tag 	bidirectional_iterator_tag;
	typedef std::random_access_iterator_tag 	random_access_iterator_tag;
	struct contiguous_iterator_tag : public random_access_iterator_tag {};
}

#endif


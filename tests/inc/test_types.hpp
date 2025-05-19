
#ifndef  __TEST_TYPES_HPP__
# define __TEST_TYPES_HPP__

#include <iostream>
#include <typeinfo>
#include <cxxabi.h>
#include <cstring>

template<typename T>
std::string demangle() { return abi::__cxa_demangle(typeid(T).name(),0,0,NULL); }

#define PRINT_MEMBER_TYPE(MEMBER) std::cout << demangle<T>() << "::" #MEMBER " = " << demangle<typename T::MEMBER >() << std::endl
template<typename T>
void test_member_types() {
	PRINT_MEMBER_TYPE(value_type      	);
	PRINT_MEMBER_TYPE(allocator_type  	);
	PRINT_MEMBER_TYPE(size_type       	);
	PRINT_MEMBER_TYPE(difference_type 	);

	PRINT_MEMBER_TYPE(reference       	);
	PRINT_MEMBER_TYPE(const_reference 	);
	PRINT_MEMBER_TYPE(pointer         	);
	PRINT_MEMBER_TYPE(const_pointer   	);

	//PRINT_MEMBER_TYPE(iterator               	);
	//PRINT_MEMBER_TYPE(const_iterator         	);
	//PRINT_MEMBER_TYPE(reverse_iterator       	);
	//PRINT_MEMBER_TYPE(const_reverse_iterator 	);
}


#endif


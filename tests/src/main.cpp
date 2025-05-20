
#ifdef USE_STD
# include <vector>
namespace test = std;
#else
# include "vector.hpp"
namespace test = ft;
#endif

#include "test_types.hpp"

class nocopy {
public:
	nocopy(): dummy() {};
private:
	nocopy& operator=(const nocopy &);
	int dummy;
};

int main(int argc, char* argv[]) {
	(void)argc;
	(void)argv;

	//test_member_types<test::vector< nocopy >      	>();
	//test_member_types<test::vector< char[] >            	>();
	test::vector< bool > v_bool; (void) v_bool;
	test::vector< int >  v_int; (void) v_int;
	//test_member_types<test::vector< test::vector<int> > 	>();
}

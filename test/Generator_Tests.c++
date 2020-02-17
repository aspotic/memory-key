#include "testify/testify.hpp"

using namespace Testify;

class Gen_Prototype_Tests :
	public TestCase
{

public:
	Gen_Prototype_Tests ():
		TestCase ("MyTestCase")
        {
        	// Add/bind tests here
        	addTest( bind( &Gen_Prototype_Tests::example, this ), "Example" );
        }


        /**
         * example: Will always pass. Just here to show how to create a test
         */
        void example (void) {
            TESTIFY_ASSERT (1);
        }

};

static TestHook hook( new Gen_Prototype_Tests() );

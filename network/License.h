/**
 * Connects to the licensing server and checks if
 * the program is still allowed to operate.
 * @author Adam Knox
 */

#ifndef LICENSE_H
#define LICENSE_H


#include <MAUtil/Moblet.h>

class License {
public:
	/**
	 * Constructor
	 * @author Adam Knox
	 */
	License();

	/**
	 * Destructor
	 * @author Adam Knox
	 */
	virtual ~License();

	/**
	 * Checks if the program has a valid license
	 * @return true if allowed to run program, false otherwise
	 * @author Adam Knox
	 */
	bool License::isValid();

private:
};

#endif

/**
 * An interface for working with data stored
 * locally on the device.
 * @author Adam Knox
 */

#include <MAUtil/List.h>

#include "../model/Password.h"


class LocalStorage {
public:
	/**
	 * Constructor
	 * @author Adam Knox
	 */
	LocalStorage();

	/**
	 * Destructor
	 * @author Adam Knox
	 */
	virtual ~LocalStorage();

	/**
	 * Saves the given password to local storage
	 * @author Adam Knox
	 * @param password
	 * @return true if successful, false if failed
	 */
	bool Save(Password* password);

	/**
	 * Gets a list containing all the locally stored passwords
	 * @author Adam Knox
	 * @return A list containing all the password objects stored locally
	 */
	MAUtil::List<Password*>* Read();

	/**
	 * Removes the given password from local storage
	 * @author Adam Knox
	 * @param name The name of the password to remove
	 * @return true if successful, false if failed
	 */
	bool Delete(MAUtil::String name);

	/**
	 * Updates the password object with the given name to be the given password object
	 * @author Adam Knox
	 * @param name the name of the password to update
	 * @param password the updated password object
	 * @return true if successful, false if failed
	 */
	bool Update(MAUtil::String name, Password* password);

private:
};

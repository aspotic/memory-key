#include "Password.h"

using namespace MAUtil;

/**
 * Constructor. Creates a new password object and sets all the parameters
 */
Password::Password(String t_name, String t_description, int t_idInputMethod, int t_idAlgorithm, int t_numRequiredSpecialCharacters, int t_numRequiredNumbers, int t_numRequirdUpperCase, int t_numRequiredLowerCase, int t_maxPasswordLength, int t_minPasswordLength) {
	name = t_name;
	description = t_description;
	idInputMethod = t_idInputMethod;
	idAlgorithm = t_idAlgorithm;
	numRequiredSpecialCharacters = t_numRequiredSpecialCharacters;
	numRequiredNumbers = t_numRequiredNumbers;
	numRequirdUpperCase = t_numRequirdUpperCase;
	numRequiredLowerCase = t_numRequiredLowerCase;
	maxPasswordLength = t_maxPasswordLength;
	minPasswordLength = t_minPasswordLength;
}

/**
 * Destructor. Destroys the password object and its sub objects
 */
Password::~Password () {

}

MAUtil::String Password::getName() {
	return name;
}

int Password::getIdInputMethod () {
	return idInputMethod;
}

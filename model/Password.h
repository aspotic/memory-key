#ifndef PASSWORD_H
#define PASSWORD_H

#include <MAUtil\String.h>

class Password {
public:
	Password(MAUtil::String t_name, MAUtil::String t_description,
			int t_idInputMethod, int t_idAlgorithm, int t_numRequiredSpecialCharacters, int t_numRequiredNumbers,
			int t_numRequirdUpperCase, int t_numRequiredLowerCase, int t_maxPasswordLength, int t_minPasswordLength);
	virtual ~Password();
	MAUtil::String getName();
	int getIdInputMethod();

protected:


private:
	MAUtil::String name;		//The name that appears in the password list
	MAUtil::String description;	//A description or hint for this password
	int idInputMethod;			//The ID number of the password generator algorithm being used
	int idAlgorithm;			//The ID number of the password generator algorithm being used

	//Fields dictating how the password must be formatted
	int numRequiredSpecialCharacters;
	int numRequiredNumbers;
	int numRequirdUpperCase;
	int numRequiredLowerCase;
	int maxPasswordLength;
	int minPasswordLength;
};

#endif

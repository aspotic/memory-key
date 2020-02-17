#ifndef PASSWORD_LIST_H
#define PASSWORD_LIST_H

#include <MAUtil/String.h>
#include <../model/Password.h>
#include <../model/Sequence.h>

class Generator {
	Generator ();
	virtual ~Generator ();
	MAUtil::String generatePassword();//Password password, Sequence sequence);
};

#endif

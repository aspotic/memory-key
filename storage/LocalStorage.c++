/**
 * An interface for working with data stored
 * locally on the device.
 * @author Adam Knox
 */

#include "LocalStorage.h";





/**
 * Constructor
 * @author Adam Knox
 */
LocalStorage::LocalStorage() {}





/**
 * Destructor
 * @author Adam Knox
 */
LocalStorage::~LocalStorage() {}





/**
 * Saves the given password to local storage
 * @author Adam Knox
 * @param password
 * @return true if successful, false if failed
 */
bool LocalStorage::Save(Password* password){
	//Todo: Implement local file saving
	return true;
}





/**
 * Gets a list containing all the locally stored passwords
 * @author Adam Knox
 * @return A list containing all the password objects stored locally
 */
MAUtil::List<Password*>* LocalStorage::Read(){
	//Todo: Implement local file reading

	//Create the list to hold the existing passwords to return
	MAUtil::List<Password*>* passwordStore = new MAUtil::List<Password*>();

	//FILL THE LIST WITH DUMMY PASSWORDS
	//Dummy 1
	passwordStore->addFirst(new Password("Work Desktop","Windows login @ workstation",0,0,0,0,0,0,20,10));
	//Dummy 2
	passwordStore->addFirst(new Password("Work E-mail","work exchange email",0,0,2,2,2,2,20,8));
	//Dummy 3
	passwordStore->addFirst(new Password("Home Login","Windows login @ home",0,0,1,2,3,4,15,10));
	//Dummy 4
	passwordStore->addFirst(new Password("Home Login 2","Windows login @ home",0,2,1,2,3,4,15,10));
	//Dummy 5
	passwordStore->addFirst(new Password("Home Login 3","Windows login @ home",0,2,1,2,3,4,15,10));
	//Dummy 6
	passwordStore->addFirst(new Password("Home Login 4","Windows login @ home",0,2,1,2,3,4,15,10));
	//Dummy 7
	passwordStore->addFirst(new Password("Home Login 5","Windows login @ home",0,2,1,2,3,4,15,10));
	//Dummy 8
	passwordStore->addFirst(new Password("Home Login 6","Windows login @ home",0,2,1,2,3,4,15,10));
	//Dummy 9
	passwordStore->addFirst(new Password("Home Login 7","Windows login @ home",0,2,1,2,3,4,15,10));
	//Dummy 10
	passwordStore->addFirst(new Password("Home Login 8","Windows login @ home",0,2,1,2,3,4,15,10));

	return passwordStore;
}





/**
 * Removes the given password from local storage
 * @author Adam Knox
 * @param name The name of the password to remove
 * @return true if successful, false if failed
 */
bool LocalStorage::Delete(MAUtil::String name){
	//Todo: Implement local file removal
	return true;
}





/**
 * Updates the password object with the given name to be the given password object
 * @author Adam Knox
 * @param name the name of the password to update
 * @param password the updated password object
 * @return true if successful, false if failed
 */
bool LocalStorage::Update(MAUtil::String name, Password* password){
	//Todo: Implement local file updating
	return true;
}

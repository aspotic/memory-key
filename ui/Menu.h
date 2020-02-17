/**
 * description: Builds a screen that shows all the passwords the
 * 				user has created and allows them to modify the list.
 * 				Also holds the list of existing passwords.
 * @author Adam Knox
 */

#ifndef MENU_H
#define MENU_H


#include <MAUI/Screen.h>
#include <MAUI/Label.h>
#include <MAUI/ListBox.h>
#include <MAUI/Layout.h>
#include <MAUI/EditBox.h>
#include <MAUI/Font.h>
#include <MAUtil/List.h>

#include "../storage/LocalStorage.h"
#include "../model/Password.h"
#include "../model/Sequence.h"
#include "inputs/Input.h"
#include "CreatePassword.h"

//Need to include MA Headers if anything is pulled from the resources folder
#include "MAHeaders.h"



class Menu :
	public MAUI::Screen
{
public:
	/**
	 * Constructor
	 * @author Adam Knox
	 */
	Menu();

	/**
	 * Destructor
	 * @author Adam Knox
	 */
	virtual ~Menu();

	/**
	 * Pulls the database of password objects from
	 * memory into the program and is stored in Menu.
	 * @author Adam Knox
	 */
	void createStore();

	/**
	 * Creates the graphical user interface
	 * @author Adam Knox
	 */
	void createUI();

	/**
	 * Checks which button is selected, and runs the action
	 * associated with the selected button.
	 * @author Adam Knox
	 * @return Outcome
	 */
	int runWidgetAction();

	/**
	 * Listens for any key presses and does the associated action
	 * @author Adam Knox
	 * @param keyCode The code for the key pressed
	 */
	void keyPressEvent(int keyCode);

	/**
	 * Listens for a press on the screen and runs proper action for the press
	 * @author Adam Knox
	 * @param point The position on the screen that is being pressed
	 */
	void pointerPressEvent(MAPoint2d point);

	/**
	 * Listens for the release of a point on the screen and runs proper action for the release
	 * @author Adam Knox
	 * @param point The position on the screen that is being released
	 */
	void pointerReleaseEvent(MAPoint2d point);


private:
	// The interface for accessing locally stored data
	LocalStorage* iLocalStorage;

	// The main layout that holds the other widgets
	MAUI::Layout* wMainLayout;

	// A text label that displays screen's name/title
	MAUI::Label* wTitle;

	// Scrolling area containing the password buttons
	MAUI::ListBox* wBody;

	// The New Password button
	MAUI::Label* wNewPassword;

	// List of the Password Buttons displayed on the screen
	MAUtil::List<MAUI::Label*>* passwordWidgetList;

	// List of the Password Objects behind each button
	MAUtil::List<Password*>* passwordStore;


	//SCREENS
	//New Password Screen
	CreatePassword* sCreatePassword;
};

#endif

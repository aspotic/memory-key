/**
 * The screen used for setting up a new password
 * @author Adam Knox
 */

#include "CreatePassword.h"


/**
 * Constructor
 * @author Adam Knox
 * @param previous The screen that called this one
 */
CreatePassword::CreatePassword(Screen *previous) : previous(previous) {
	//Build user interface
	createUI();
};





/**
 * Destructor
 * @author Adam Knox
 */
CreatePassword::~CreatePassword() {
	delete wMainLayout;
}





/**
 * Builds the interface for inputing password data
 * @author Adam Knox
 */
void CreatePassword::createUI() {
	//Figure out screen dimensions
	int displayWidth = EXTENT_X(maGetScrSize());
	int displayHeight = EXTENT_Y(maGetScrSize());


	//Set Screen's Child Objects Dimensions'
	int padding = 5;
	int titleHeight = 30;
	int titleWidth = displayWidth;
	int databoxHeight = 25;
	int databoxWidth = displayWidth;
	int labelHeight = 18 + databoxHeight + padding;
	int labelWidth = displayWidth;
	int bodyWidth = displayWidth;
	int bodyHeight = displayHeight-titleHeight;
	int editBoxYOffset = labelHeight - padding - databoxHeight;


	//Set up the screen's fonts
	MAUI::Font* fontText;
	MAUI::Font* fontHeader;
	MAUI::Font* fontButton;
	fontText = new MAUI::Font(TEXT);
	fontHeader = new MAUI::Font(HEADER);
	fontButton = new MAUI::Font(BUTTON);


	//Set up the screen's skins
	MAUI::WidgetSkin* buttonSkin = new MAUI::WidgetSkin(
		RES_MENU_BUTTON_DOWN,   // Image for selected state.
		RES_MENU_BUTTON_UP, 	// Image for unselected state.
		25, 					// X coordinate for start of center patch.
		26, 					// X coordinate for end of center patch.
		0, 						// Y coordinate for start of center patch.
		30, 					// Y coordinate for end of center patch.
		true,  					// Is selected image transparent?
		true); 					// Is unselected image transparent?


	//Build the UI's Layout
	wMainLayout = new MAUI::Layout(0, 0, displayWidth, displayHeight, NULL, 1, 2);
	wMainLayout->setBackgroundColor(0);
	wMainLayout->setDrawBackground(true);
	setMain(wMainLayout);

	//Setup the screen's title label
	wTitle = new MAUI::Label(0, 0,	titleWidth, titleHeight, wMainLayout, "Create Password", 0x000000, fontHeader);
	wTitle->setHorizontalAlignment(MAUI::Label::HA_CENTER);
	wTitle->setVerticalAlignment(MAUI::Label::VA_CENTER);

	//Setup the scrolling window
	wBody = new MAUI::ListBox(0, 0, bodyWidth, bodyHeight, wMainLayout, MAUI::ListBox::LBO_VERTICAL, MAUI::ListBox::LBA_LINEAR, true);

	//SETUP THE EDIT BOXES
	//Create the labels to house the edit boxes
	MAUI::Label* wLabel = new MAUI::Label(0, 0,	labelWidth, labelHeight, wBody, "Name", 0x000000, fontText);
	MAUI::Label* wlDescription = new MAUI::Label(0, 0,	labelWidth, labelHeight, wBody, "Description", 0x000000, fontText);
	MAUI::Label* wlIdInputMethod = new MAUI::Label(0, 0,	labelWidth, labelHeight, wBody, "Input Method", 0x000000, fontText);
	MAUI::Label* wlNumRequiredSpecialCharacters = new MAUI::Label(0, 0,	labelWidth, labelHeight, wBody, "Min # Special Chars", 0x000000, fontText);
	MAUI::Label* wlNumRequiredNumbers = new MAUI::Label(0, 0,	labelWidth, labelHeight, wBody, "Min # Numbers", 0x000000, fontText);
	MAUI::Label* wlNumRequirdUpperCase = new MAUI::Label(0, 0,	labelWidth, labelHeight, wBody, "Min # Upper Case Characters", 0x000000, fontText);
	MAUI::Label* wlNumRequiredLowerCase = new MAUI::Label(0, 0,	labelWidth, labelHeight, wBody, "Min # Lower Case Characters", 0x000000, fontText);
	MAUI::Label* wlMaxPasswordLength = new MAUI::Label(0, 0, labelWidth, labelHeight, wBody, "Max Password Length", 0x000000, fontText);
	MAUI::Label* wlMinPasswordLength = new MAUI::Label(0, 0, labelWidth, labelHeight, wBody, "Min Password Length", 0x000000, fontText);

	//Create the actual edit boxes
	wName = new MAUI::EditBox(0, editBoxYOffset, databoxWidth, databoxHeight, wLabel, "", 0x555555, fontText, true, false, 60);
	wDescription = new MAUI::EditBox(0, editBoxYOffset, databoxWidth, databoxHeight, wlDescription, "", 0x555555, fontText, true, false, 60);
	wIdInputMethod = new MAUI::EditBox(0, editBoxYOffset, databoxWidth, databoxHeight, wlIdInputMethod, "", 0x555555, fontText, true, false, 60);
	wIdInputMethod = new MAUI::EditBox(0, editBoxYOffset, databoxWidth, databoxHeight, wlIdInputMethod, "", 0x555555, fontText, true, false, 60);
	wNumRequiredNumbers = new MAUI::EditBox(0, editBoxYOffset, databoxWidth, databoxHeight, wlNumRequiredNumbers, "", 0x555555, fontText, true, false, 60);
	wNumRequirdUpperCase = new MAUI::EditBox(0, editBoxYOffset, databoxWidth, databoxHeight, wlNumRequirdUpperCase, "", 0x555555, fontText, true, false, 60);
	wNumRequiredLowerCase = new MAUI::EditBox(0, editBoxYOffset, databoxWidth, databoxHeight, wlNumRequiredLowerCase, "", 0x555555, fontText, true, false, 60);
	wMaxPasswordLength = new MAUI::EditBox(0, editBoxYOffset, databoxWidth, databoxHeight, wlMaxPasswordLength, "", 0x555555, fontText, true, false, 60);
	wMinPasswordLength = new MAUI::EditBox(0, editBoxYOffset, databoxWidth, databoxHeight, wlMinPasswordLength, "", 0x555555, fontText, true, false, 60);
	wNewPassword = new MAUI::Label(0, 0, databoxWidth, databoxHeight, wBody, "Create Password", 0, fontButton);

	//Activate the edit boxes
	wName->activate();
	wDescription->activate();
	wIdInputMethod->activate();
	wNumRequiredSpecialCharacters->activate();
	wNumRequiredNumbers->activate();
	wNumRequirdUpperCase->activate();
	wNumRequiredLowerCase->activate();
	wMaxPasswordLength->activate();
	wMinPasswordLength->activate();

	//Select the first edit box
	wName->setSelected(true);
	wDescription->setSelected(false);
	wIdInputMethod->setSelected(false);
	wNumRequiredSpecialCharacters->setSelected(false);
	wNumRequiredNumbers->setSelected(false);
	wNumRequirdUpperCase->setSelected(false);
	wNumRequiredLowerCase->setSelected(false);
	wMaxPasswordLength->setSelected(false);
	wMinPasswordLength->setSelected(false);

	//Add the labels to the widget listener so selection switches to their first child widget
	wLabel->addWidgetListener(this);
	wlDescription->addWidgetListener(this);
	wlIdInputMethod->addWidgetListener(this);
	wlIdInputMethod->addWidgetListener(this);
	wlNumRequiredNumbers->addWidgetListener(this);
	wlNumRequirdUpperCase->addWidgetListener(this);
	wlNumRequiredLowerCase->addWidgetListener(this);
	wlMaxPasswordLength->addWidgetListener(this);
	wlMinPasswordLength->addWidgetListener(this);

	// Build the create password button
	wNewPassword->setSkin(buttonSkin);
	wNewPassword->setHorizontalAlignment(MAUI::Label::HA_CENTER);
	wNewPassword->setVerticalAlignment(MAUI::Label::VA_CENTER);
}





/**
 * Runs the action for the selected widget
 * @author Adam Knox
 * @return Completion Status
 */
int CreatePassword::runWidgetAction() {
	if (wNewPassword->isSelected()) {
		// Create the password in the model

		// Save the password to disk

		// Go back to the password menu list
		this->hide();
		previous->show();
	}
}





/**
 * Listens for any key presses and does the associated action
 * @author Adam Knox
 * @param keyCode The code for the key pressed
 */
void CreatePassword::keyPressEvent(int keyCode) {

	switch (keyCode) {
		case MAK_BACK:
		case MAK_0:
		case MAK_SOFTLEFT:
			// Hide this screen and go back to the one that called it
			hide();
			previous->show();
			break;

		case MAK_UP:
			// Move selection up one edit box
			wBody->selectPreviousItem();
			break;

		case MAK_DOWN:
			// Move selection down one edit box
			wBody->selectNextItem();
			break;

		case MAK_FIRE:
			// Run the selected widget
			runWidgetAction();
			break;
	}
}





/**
 * Listens for change in selection status of widgets on screen to
 * make sure the editboxes are selected instead of the labels
 * @author Adam Knox
 * @param widget The widget that had its status chaged
 * @param selected the status of the widget
 */
void CreatePassword::selectionChanged(MAUI::Widget *widget, bool selected) {
	// If the widget is selected, then switch the selection to its first child
	if(selected) {
		widget->getChildren()[0]->setSelected(true);
	}

	// Deselect the child if the widget is deselected
	else {
		widget->getChildren()[0]->setSelected(false);
	}
}

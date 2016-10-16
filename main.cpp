#include "Polycode.h"
#include "PolycodeView.h"
#include "HelloPolycodeApp.h"

int main(int argc, char *argv[]) {

	//Create window for the app to utilize. 
	PolycodeView *view = new PolycodeView("Block Tower GA");

	//Create new instance of app, using the created PolycodeView.  
	HelloPolycodeApp *app = new HelloPolycodeApp(view);

	//Run the app until exit. 
	while(app->Update()) {}

	return 0;
}

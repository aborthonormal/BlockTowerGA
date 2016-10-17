#include "Polycode.h"
#include "PolycodeView.h"
#include "BlockTowerApp.h"

int main(int argc, char *argv[]) {

	//Create window for the app to utilize. 
	PolycodeView *view = new PolycodeView("Block Tower GA");

	//Create new instance of app, using the created PolycodeView.  
	BlockTowerApp *app = new BlockTowerApp(view);

	


	//Build the tower, based upon the genome.  
	//app->buildTower(g);

	//Run the app until exit. 
	while(app->update()) {}

	return 0;
}

#include <Polycode.h>
#include "PolycodeView.h"
#include "Polycode2DPhysics.h"

#include <ga/GASimpleGA.h>
#include <ga/GA2DBinStrGenome.h>

using namespace Polycode;

class BlockTowerApp {
public:
    BlockTowerApp(PolycodeView *view);
    ~BlockTowerApp();
    bool update();
   	
   	void buildTower(GAGenome &g);
   	
   	float objectiveFunction(GAGenome &);
   	
   	bool allBlocksAsleep();
    
    
private:
	Core *core;
	PhysicsScene2D *scene;
	Logger *logger;
	
	//Entities for tower's blocks which are added to scene
	PhysicsScene2DEntity **blockEntities;
	
	int numBlocks;
};

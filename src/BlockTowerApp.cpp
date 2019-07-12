#include "BlockTowerApp.h"

BlockTowerApp::BlockTowerApp(PolycodeView *view) {

	core = new POLYCODE_CORE(view, 640,480,false,true,0,0,90, 0, true);
	scene = new PhysicsScene2D(0.1, 60, 60);

	//random seed
	srand(time(0));

	//Foundation rectangle
	ScenePrimitive *shape = new ScenePrimitive(ScenePrimitive::TYPE_VPLANE, 1.0,0.05);
	shape->setColor(0.0,0.0,0.1,1.0);
	shape->setPosition(0, -0.3);
	scene->addPhysicsChild(shape, PhysicsScene2DEntity::ENTITY_RECT, true);	
	
	blockEntities = NULL;
	numBlocks = 0;
	
	/*
	shape = new ScenePrimitive(ScenePrimitive::TYPE_VPLANE, 0.08,0.02);
	shape->setRoll(rand() % 360);
    shape->setColor(RANDOM_NUMBER, RANDOM_NUMBER, RANDOM_NUMBER, 1.0);
	shape->setPosition(-0.3 + (RANDOM_NUMBER*0.6), RANDOM_NUMBER);
	
	
	PhysicsScene2DEntity * sceneEntity = scene->addPhysicsChild(shape, PhysicsScene2DEntity::ENTITY_RECT, false);
	*/
	
	//Set logger to output to file.  
	logger = core->getServices()->getLogger();
	logger->setLogToFile(true);
	
	
	GA2DBinaryStringGenome genome(17, 10, this->objectiveFunction);
}

BlockTowerApp::~BlockTowerApp() {

	delete[] blockEntities;
}

bool BlockTowerApp::update() {
	
    return core->updateAndRender();
}

//Construct the tower based on the genome provided.  This clears out the previous Entities from the scene and adds new ones.  
void BlockTowerApp::buildTower(GAGenome &g) {

	GA2DBinaryStringGenome & genome = (GA2DBinaryStringGenome &)g;

	//Clear the current block entities from the scene.  
	if(blockEntities != NULL) {
	
		for(int i=0; i<numBlocks; i++) {
			
			scene->removePhysicsChild(blockEntities[i]->getEntity());
		}
		
		delete[] blockEntities;
	}
	
	numBlocks = genome.height();
		
	blockEntities = new PhysicsScene2DEntity* [numBlocks];

	//Each row of the genome represents a block definition.  
	for(int i=0; i<numBlocks; i++) {
	
		ScenePrimitive *shape = new ScenePrimitive(ScenePrimitive::TYPE_VPLANE, 0.08,0.02);
		
		if(genome.gene(i,0) == 1) {
			//Rotate 90 degrees
			shape->setRoll(90);
		}
		
		//random color, for funzies
		shape->setColor(RANDOM_NUMBER, RANDOM_NUMBER, RANDOM_NUMBER, 1.0);
		
		int xBinary = 0; 
		int yBinary = 0;
		
		//Number of bits used to represent the x and y position values in the genome.  
		int numBits = genome.width()/2 - 1;
		
		for(int j=1; j<numBits; j++) {
		
			//Build up the integer numerators for the position values.  
			xBinary += (int)pow(2.0, (float)genome.gene(i,j));
			yBinary += (int)pow(2.0, (float)genome.gene(i,j+numBits));
		}
		
		//Shape variables range from -0.5 to 0.5, with center at (0,0).  
		float xPosition = xBinary/((int)pow(2.0, numBits)-1);
		xPosition += -0.5;
		
		float yPosition = yBinary/((int)pow(2.0, numBits)-1);
		yPosition += -0.5;
		
		
		shape->setPosition(xPosition, yPosition);
	
		//Add block to scene, save reference to physics entity.  
		blockEntities[i] = scene->addPhysicsChild(shape, PhysicsScene2DEntity::ENTITY_RECT, false);
	}
}

//Evaluate each tower based on the height after all blocks are at rest.  
float BlockTowerApp::objectiveFunction(GAGenome &g) {

	//Build the tower.  
	buildTower(g);
	
	//Run simulation until all blocks are not awake.  
	while(update() && !allBlocksAsleep()) {}
	
	//Find the y-position of the highest block.  
	float highest = 0;
	
	for(int i=0; i<numBlocks; i++) {
	
		float currentHeight = blockEntities[i]->getEntity()->getAnchorPoint().y;
		
		if(currentHeight > highest) {
			highest = currentHeight;
		}
	}
	
	return highest;
}

//Check the sleep status of each block in the simulation. 
bool BlockTowerApp::allBlocksAsleep() {

	for(int i=0; i<numBlocks; i++) {
	
		b2Body * body = blockEntities[i]->getFixture()->GetBody();
		
		if(body->IsAwake()) {
			return false;
		}
	}

	return true;
}

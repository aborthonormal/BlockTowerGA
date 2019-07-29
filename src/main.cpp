#include <iostream>

#include <Box2D/Box2D.h>
#include "SDL.h"

// OpenGL / glew Headers
#define GL3_PROTOTYPES 1
#include <GL/glew.h>

#define PTM_RATIO 32.0

SDL_Window *mainWindow;
SDL_GLContext mainContext;

bool SetOpenGLAttributes();
void PrintSDL_GL_Attributes();
void CheckSDLError(int line);
void RunGame();
void Cleanup();

bool initWindow() {

    if(SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("Failed to init SDL\n");
        return false;
    } 

    // Create an application window with the following settings:
    mainWindow = SDL_CreateWindow(
        "BlockTowerGA",          // window title
        SDL_WINDOWPOS_UNDEFINED, // initial x position
        SDL_WINDOWPOS_UNDEFINED, // initial y position
        800,                     // width, in pixels
        600,                     // height, in pixels
        SDL_WINDOW_OPENGL        // flags - see below
    );

    // Check that everything worked out okay
	if (!mainWindow)
	{
		std::cout << "Unable to create window\n";
		CheckSDLError(__LINE__);
		return false;
	}

    // Create our opengl context and attach it to our window
	mainContext = SDL_GL_CreateContext(mainWindow);
	
    glewExperimental = GL_TRUE;
    glewInit();

	SetOpenGLAttributes();

	// This makes our buffer swap syncronized with the monitor's vertical refresh
	SDL_GL_SetSwapInterval(1);

    return true;
}

bool SetOpenGLAttributes() {
	// Set our OpenGL version.
	// SDL_GL_CONTEXT_CORE gives us only the newer version, deprecated functions are disabled
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);

	// 3.2 is part of the modern versions of OpenGL, but most video cards whould be able to run it
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 2);

	// Turn on double buffering with a 24bit Z buffer.
	// You may need to change this to 16 or 32 for your system
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

	return true;
}

void closeWindow() {
    // Delete our OpengL context
	SDL_GL_DeleteContext(mainContext);

	// Destroy our window
	SDL_DestroyWindow(mainWindow);

	// Shutdown SDL 2
	SDL_Quit();
}

void CheckSDLError(int line = -1)
{
	std::string error = SDL_GetError();

	if (error != "")
	{
		std::cout << "SLD Error : " << error << std::endl;

		if (line != -1)
			std::cout << "\nLine : " << line << std::endl;

		SDL_ClearError();
	}
}

void PrintSDL_GL_Attributes()
{
	int major = 0;
	int minor = 0;
	SDL_GL_GetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, &major);
	SDL_GL_GetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, &minor);

	std::cout << "OpenGL Version: " << major << "." << minor << std::endl;
}

int main(int argc, char *argv[])
{
	if (!initWindow()) {
		return -1;
    }

    PrintSDL_GL_Attributes();

	glClearColor(0.0, 0.0, 0.0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT);
	SDL_GL_SwapWindow(mainWindow);

	RunGame();

	closeWindow();

	return 0;
}

void RunGame() {

    SDL_Rect box = {0, 0, 10, 10};
    SDL_Rect ground = {0, 540, 800, 560};

    b2Vec2 gravity(0.0f, 9.8f);

    bool doSleep = true;

    b2World *world;
    world = new b2World(gravity);
    world->SetGravity(gravity);

    b2Body *groundBody;
    b2BodyDef groundBodyDef;
    groundBodyDef.type = b2_staticBody;
    groundBodyDef.position.Set(0, 540);
    groundBody = world->CreateBody(&groundBodyDef);

    b2Body *Body;
    b2BodyDef ballBodyDef;
    ballBodyDef.type = b2_dynamicBody;
    b2Vec2 ballvector;
    ballvector.Set(10, 10);
    ballBodyDef.angularVelocity = 0.0f;
    ballBodyDef.linearVelocity = ballvector;

    ballBodyDef.position.Set(0, 0);
    ballBodyDef.awake = true;
    Body = world->CreateBody(&ballBodyDef);

    b2EdgeShape groundEdge;
    groundEdge.Set( b2Vec2(0,0), b2Vec2(800,0) );
    b2FixtureDef boxShapeDef;
    boxShapeDef.shape = &groundEdge;
    boxShapeDef.density = 2.0f;
    boxShapeDef.restitution = 0.5f;

    groundBody->CreateFixture(&groundEdge, 0);

    b2PolygonShape dynamicBox;

    dynamicBox.SetAsBox(10.0f, 10.0f);

    b2FixtureDef fixtureDef;

    fixtureDef.shape = &dynamicBox;
    fixtureDef.density = 2.0f;
    fixtureDef.friction = 1.0f;
    fixtureDef.restitution = 0.5f;

    // b2MassData data;
    // data.mass = 10;
    // Body->SetMassData(&data);
    Body->CreateFixture(&fixtureDef);

    float timeStep = 1.0f / 300.0f;

    int velIter = 1.0;
    int posIter = 1.0;
    world->Step(timeStep, velIter, posIter);

    b2Vec2 pos = Body->GetPosition();
    float an = Body->GetAngle();

    //set box position and angle
    // box.SetPosition(pos.x, pos.y);
    // box.SetRotation(an);

    box.x = pos.x;
    box.y = pos.y;

    // A basic main loop to prevent blocking
    bool is_running = true;
    SDL_Event event;
    while (is_running)
    {
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
            {
                is_running = false;
            }
        }

        world->Step(timeStep, velIter, posIter);

        b2Vec2 pos = Body->GetPosition();
        float angle = Body->GetAngle();

        // box.SetPosition(pos.x, pos.y);
        // box.SetRotation(angle);
        box.x = pos.x;
        box.y = pos.y;

        //Clear window to white
        glClearColor(1.0, 1.0, 1.0, 1.0);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        glColor3f(1.0, 0.0, 0.0);
        // glRecti(0, 540, 800, 560);
        glRecti(0, 0, 1, 1);

        // //draw box
        // SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0xFF, 0xFF );
        // SDL_RenderFillRect(renderer, &box);

        // //draw ground
        // SDL_SetRenderDrawColor(renderer, 0xFF, 0x00, 0x00, 0xFF );
        // SDL_RenderFillRect(renderer, &ground);

        // //update screen
        // SDL_RenderPresent(renderer);

        SDL_GL_SwapWindow(mainWindow);

        SDL_Delay(16);
    }
}
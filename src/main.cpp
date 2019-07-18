#include <iostream>

#include <Box2D/Box2D.h>
#include "SDL.h"

#define PTM_RATIO 32.0

int main()
{

    SDL_Window *window; //display window
    SDL_Renderer *renderer; //window renderer

    SDL_Init(SDL_INIT_VIDEO); // Initialize SDL2

    // Create an application window with the following settings:
    window = SDL_CreateWindow(
        "BlockTowerGA",          // window title
        SDL_WINDOWPOS_UNDEFINED, // initial x position
        SDL_WINDOWPOS_UNDEFINED, // initial y position
        800,                     // width, in pixels
        600,                     // height, in pixels
        SDL_WINDOW_OPENGL        // flags - see below
    );

    // Check that the window was successfully created
    if (window == NULL)
    {
        // In the case that the window could not be made...
        printf("Could not create window: %s\n", SDL_GetError());
        return 1;
    }

    //initialize renderer
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    // sf::RenderWindow game(sf::VideoMode(800, 600, 32), "game");
    // sf::Shape box = sf::Shape::Rectangle(0, 0, 10, 10, sf::Color(255,0,0));
    // sf::Shape ground = sf::Shape::Rectangle(0,540,800,560,sf::Color(0,0,255));

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

    b2MassData data;
    data.mass = 10;
    Body->SetMassData(&data);
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

        //Clear the window
        SDL_SetRenderDrawColor( renderer, 0xFF, 0xFF, 0xFF, 0xFF );
        SDL_RenderClear(renderer);

        //draw box
        SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0xFF, 0xFF );
        SDL_RenderFillRect(renderer, &box);

        //draw ground
        SDL_SetRenderDrawColor(renderer, 0xFF, 0x00, 0x00, 0xFF );
        SDL_RenderFillRect(renderer, &ground);

        //update screen
        SDL_RenderPresent(renderer);

        SDL_Delay(16);
    }

    //destroy window
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    renderer = NULL;
    window = NULL;
    SDL_Quit();

    return EXIT_SUCCESS;
}

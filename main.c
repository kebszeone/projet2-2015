#include <SDL/SDL.h>

#include <GL/gl.h>

#include <GL/glu.h>

#include <stdlib.h>

#include <SDL/SDL_image.h>

void Dessiner();

void wait_for_keypressed(void);

double angleZ = 0;

double angleX = 0;

int main()

{

//
SDL_Surface *ecran = NULL, *logo =  NULL;

    SDL_Rect position;

    position.x = 0;

    position.y = 0;

    SDL_Init(SDL_INIT_VIDEO);

    SDL_WM_SetIcon(IMG_Load("apistyle.jpg"), NULL);

 	ecran = SDL_SetVideoMode(700, 500, 32, SDL_HWSURFACE);

    SDL_WM_SetCaption("***API's Style***", NULL);

 	logo = IMG_Load("apistyle.jpg");

    SDL_BlitSurface(logo, NULL, ecran, &position);

	SDL_Flip(ecran);

	wait_for_keypressed();
 
//

    SDL_Event event;

    SDL_Init(SDL_INIT_VIDEO);

    atexit(SDL_Quit);

    SDL_WM_SetCaption("***API's Style***", NULL);

    SDL_SetVideoMode(640, 480, 32, SDL_OPENGL);

    glMatrixMode( GL_PROJECTION );

    glLoadIdentity();

    gluPerspective(70,(double)640/480,1,1000);

    glEnable(GL_DEPTH_TEST);
	

    Dessiner();

    Uint32 last_time = SDL_GetTicks();

    Uint32 current_time,ellapsed_time;

    Uint32 start_time;

    for (;;)

    {

        start_time = SDL_GetTicks();

        while (SDL_PollEvent(&event))

        {

            switch(event.type)

            {

                case SDL_QUIT:

                exit(0);

                break;

            }

        }

        current_time = SDL_GetTicks();

        ellapsed_time = current_time - last_time;

        last_time = current_time;
		
		if(event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_UP){

        	angleZ = 0.05 * ellapsed_time;

        	angleX += 0.05 * ellapsed_time;
		}
		if(event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_LEFT){

        	angleZ -= 0.05 * ellapsed_time;

        	angleX = 0.05 * ellapsed_time;
		}
		if(event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_RIGHT){

        	angleZ += 0.05 * ellapsed_time;

        	angleX = 0.05 * ellapsed_time;
		}
		if(event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_DOWN){

        	angleZ = 0.05 * ellapsed_time;

        	angleX -= 0.05 * ellapsed_time;
		}


	

        Dessiner();

        ellapsed_time = SDL_GetTicks() - start_time;

        if (ellapsed_time < 10)

        {

            SDL_Delay(10 - ellapsed_time);

        }

    }

    return 0;

}

void Dessiner()

{

    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

    glMatrixMode( GL_MODELVIEW );

    glLoadIdentity( );

    gluLookAt(3,4,2,0,0,0,0,0,1);

    glRotated(angleZ,0,0,1);

    glRotated(angleX,1,0,0);

    glBegin(GL_QUADS);

    glColor3ub(255,255,0); //jaune

    glVertex3d(1,1,1);

    glVertex3d(1,1,-1);

    glVertex3d(-1,1,-1);

    glVertex3d(-1,1,1);

    glColor3ub(255,255,0);

    glVertex3d(1,-1,1);

    glVertex3d(1,-1,-1);

    glVertex3d(1,1,-1);

    glVertex3d(1,1,1);

    glColor3ub(255,255,0);

    glVertex3d(-1,-1,1);

    glVertex3d(-1,-1,-1);

    glVertex3d(1,-1,-1);

    glVertex3d(1,-1,1);

    glColor3ub(255,255,0);

    glVertex3d(-1,1,1);

    glVertex3d(-1,1,-1);

    glVertex3d(-1,-1,-1);

    glVertex3d(-1,-1,1);

    glColor3ub(255,255,0);

    glVertex3d(1,1,-1);

    glVertex3d(1,-1,-1);

    glVertex3d(-1,-1,-1);

    glVertex3d(-1,1,-1);

    glColor3ub(255,255,0);

    glVertex3d(1,-1,1);

    glVertex3d(1,1,1);

    glVertex3d(-1,1,1);

    glVertex3d(-1,-1,1);

    glEnd();

    glFlush();

    SDL_GL_SwapBuffers();

}

void wait_for_keypressed(void) {
  SDL_Event             event;
  // Infinite loop, waiting for event
  for (;;) {
    // Take an event
    SDL_PollEvent( &event );
    // Switch on event type
    switch (event.type) {
    // Someone pressed a key -> leave the function
    case SDL_KEYDOWN: return;
    default: break;
    }
  // Loop until we got the expected event
  }
}

#include <time.h>
#include "physics.h"

float GetCurrentTime() {
    return time(0);
}

void start() {

}

void update(float deltatime) {

    /*
    mario.position += mario.velocity * deltatime;
    mario.velocity += mario.gravity * deltatime;
    */
}

void ddraw() {

}

void Main() {

    start();
    
    /*
    mario.position = Point();
    mario.velocity = Vector(2, 2);
    mario.gravity = Vector(0, -2);
    */

    float currentTime = GetCurrentTime();
    float previousTime = 0;

    int isGameRunning = 1;
    while (isGameRunning)
    {
        previousTime = currentTime;
        currentTime = GetCurrentTime();

        float deltatime = currentTime - previousTime;

        if(deltatime > .15)
            deltatime = .15;

        update(deltatime);
        ddraw();
    }
    

}


/*
 * File:   main.c
 * Author: abilbro
 *
 * Created on March 26, 2026, 11:22 AM
 */

#include <xc.h>
#include "../inc/picgps_setup.h"
#include "../inc/pic_pins.h"
#include "../inc/xc8_lcd.h"

int contrast = 0;

void main(void) {
    pic_setup();
    init_all();

    LCD_Setup();
    LCD_Clear(0x0000); // Clear the screen to black

    #ifndef ANIMATION
    #define N_BODIES   3      // Number of bodies in the simulation
    #define G          12.0f  // Gravitational constant
    #define DT         0.01f  // Simulation time step
    #define SOFTENING  5.0f   // Prevents extreme forces at close range

    // Make things easier to keep track of for each "body".
    typedef struct {
        float x, y, vx, vy, mass;
        u16 color;
    } Body;

    // Clear everything so we start from scratch
    LCD_Clear(BLACK);

    // Initialize all bodies in a compact list
    Body bodies[N_BODIES] = {
        { .x=120.0f, .y=100.0f, .vx= 1.2f, .vy= 0.5f, .mass=20.0f, .color=RED  },
        { .x=180.0f, .y=250.0f, .vx=-0.8f, .vy=-1.0f, .mass=25.0f, .color=LIME },
        { .x= 60.0f, .y=250.0f, .vx= 0.5f, .vy= 0.9f, .mass=30.0f, .color=BLUE }
    };

    // Infinite Animation Loop
    while(1) {
        // Calculate accelerations and update velocities
        for (int i = 0; i < N_BODIES; i++) {
            float total_accel_x = 0.0f;
            float total_accel_y = 0.0f;

            for (int j = 0; j < N_BODIES; j++) {
                if (i == j) continue;

                float dx = bodies[j].x - bodies[i].x;
                float dy = bodies[j].y - bodies[i].y;
                // d^2 = dx^2 + dy^2 (+ a fake softening factor to avoid collisions)
                float dist_sq = dx * dx + dy * dy + SOFTENING;
                // Newton's law of gravitation: F = G * m1 * m2 / d^2
                float inv_dist_cubed = 1.0f / (dist_sq * sqrt[dist_sq]);
                
                // Acceleration = Force / mass, but we multiply by mass to get the force directly
                // so we can use it to update velocity directly.
                total_accel_x += dx * inv_dist_cubed * bodies[j].mass * G;
                total_accel_y += dy * inv_dist_cubed * bodies[j].mass * G;
            }
            bodies[i].vx += total_accel_x * DT;
            bodies[i].vy += total_accel_y * DT;
        }
        
        // Update positions and draw each body
        for (int i = 0; i < N_BODIES; i++) {
            // new position = old position + velocity * time step
            bodies[i].x += bodies[i].vx * DT;
            bodies[i].y += bodies[i].vy * DT;

            // Wrap around screen edges
            if (bodies[i].x < 0)    bodies[i].x += 240;
            if (bodies[i].x >= 240) bodies[i].x -= 240;
            if (bodies[i].y < 0)    bodies[i].y += 320;
            if (bodies[i].y >= 320) bodies[i].y -= 320;

            LCD_DrawPoint((u16)bodies[i].x, (u16)bodies[i].y, bodies[i].color);
        }

        // Slow it WAY down so we can see the planets interact with each other!
        __delay_ms(1);
    }
    return;
}

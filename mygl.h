#ifndef _MYGL_H_
#define _MYGL_H_

#include "definitions.h"
#include <cmath>



void PutPixel(int x, int y, int red, int green, int blue, int alpha){
    
    FBptr[4*x + 4*y*IMAGE_WIDTH + 0] = red;
    FBptr[4*x + 4*y*IMAGE_WIDTH + 1] = green;
    FBptr[4*x + 4*y*IMAGE_WIDTH + 2] = blue;
    FBptr[4*x + 4*y*IMAGE_WIDTH + 3] = alpha;
       
}

void DrawLine(int x0, int y0, int x1, int y1, int red, int green, int blue, int alpha){
    
    int dx = x1 - x0;
    int dy = y1 - y0;
    int delta;
    int east;
    int northeast;
    int x = x0;
    int y = y0;
        
    /* First quadrant (between 0 and 90 degrees) */
    if(dx > 0 && dy > 0){
        
        /*First octet*/
        if(abs(dx) > abs(dy)){
           delta = 2*dy - dx;
           east = 2*dy;
           northeast = 2*(dy-dx); 

           while(x < x1){    
               if(delta <= 0){
                   delta += east;
                   x++;
               } else {
                   delta += northeast;
                   x++;
                   y++;
               }
               PutPixel(x, y, red, green, blue, alpha);
           }

        } 
        /* Second octet */
        else {
            delta = dy - 2*dx;
            east = 2*(dy-dx);
            northeast = -2*dx;

            while(abs(y) < abs(y1)){
                if(delta <= 0){
                    delta = delta + east;
                    x++;
                    y++;
                } else {
                    delta = delta + northeast;
                    y++;
                }

                PutPixel(x, y, red, green, blue, alpha);
            }
        }
    }
    /* Second quadrant (between 90 and 180 degrees) */
    else if(dx < 0 && dy > 0) {
        
        /* Third octet */
        if(abs(dx) < abs(dy)){
            delta = dy + 2*dx;
            east = 2*dx;
            northeast = 2*(dy+dx);

            while(abs(y) < abs(y1)){
                if(delta <= 0){
                    delta += northeast;
                    y1--;
                } else {
                    delta += east;
                    y1--;
                    x1++;
                }
                PutPixel(x1, y1, red, green, blue, alpha);
            }
        } 
        /* Fourth octet */
        else {
            delta = 2*dy + dx;
            east = 2*(dy+dx);
            northeast = 2*dy;

            while(abs(x) > abs(x1)){
                if(delta <= 0){
                    delta += northeast;
                    x1++;
                } else {
                    delta += east;
                    x1++;
                    y1--;
                }
                PutPixel(x1, y1, red, green, blue, alpha);
            }
        }
    }
    /* Third quadrant (between 180 and 270 degrees) */
    else if (dx < 0 && dy < 0) {
        
        /* Fifth and Sixth Octets */
        DrawLine(y1, x1, y0, x0, red, green, blue, alpha);
    } 
    /* Fourth quadrant (between 270 and 360 degrees) */
    else if(dx > 0 && dy < 0){
        
        /* Seventh and Eighth Octets*/
        DrawLine(x1, y1, x0, y0, red, green, blue, alpha);

    }
}

void DrawTriangle(int xa, int xb, int xc, int ya, int yb, int yc, int red, int green, int blue, int alpha){
    
}

#endif // _MYGL_H_


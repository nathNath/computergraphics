# computergraphics
Repository that stores all of my Computer Graphics' class assignments. I am currently attending to this class at the Federal University of Paraíba (UFPB) with the PhD Christian Pagot.

# rasterizing

What does it mean? So, basically, rasterizing is the technique used to draw stuff on computer screens. But how do we ~magically~ draw stuff on a computer screen? Well, the computer has a memory, where we can store info about which pixels should be turned on/off and we can define its colors. Formally speaking, Foley defined rasterizing as:

> Approximation of mathematical primitives, described in terms of vertices on a Cartesian grid, by sets of pixels of the appropriate intensity of gray or color.

We have a memory full of info about our pixels, but how does the video card **really** gets that info stored on memory and knows which pixels should be turned on or off? Imagine our memory video working as a giant array. For this example, I will consider a screen that has 512 pixels through its x-axis or w (width) and 512 pixels through its y-axis or h (height). If I want to turn on a red pixel in the center of the screen, I should specify its coordinate as (255,255) and its color as (255,0,0,255). You'll have to keep in mind that the (0,0) starts on the superior leftmost point of your screen. 

## pixels

The following function is able to draw pixels on a computer screen:

```
void PutPixel(int x, int y, int red, int green, int blue, int alpha){
    
    FBptr[4*x + 4*y*IMAGE_WIDTH + 0] = red;
    FBptr[4*x + 4*y*IMAGE_WIDTH + 1] = green;
    FBptr[4*x + 4*y*IMAGE_WIDTH + 2] = blue;
    FBptr[4*x + 4*y*IMAGE_WIDTH + 3] = alpha;
       
}
```

<p align="center">
	<br>
	<img src="./printscreens/PutPixel.png"/ width=512px height=512px>
	<h5 align="center">Figure 1 - Result of PutPixel()</h5>
	<br>
</p>

## lines

In order to draw lines, Bresenham's algorithm should be used to complete this task. Its main advantage, compared to DDA (Differential Digital Analyzer), is that we handle integer values and the operations involved are SUM and SUB, instructions which are not considered expensive to Assembly. 


# references
http://www.codebind.com/linux-tutorials/install-opengl-ubuntu-linux/
https://jansebp.wordpress.com/2012/12/16/icg-t1-rasterizacao/
https://github.com/ThiagoLuizNunes/CG-Assignments/tree/master/cg_framework

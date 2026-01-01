/*
 * donut.c — the famous obfuscated ASCII donut (a1k0n)
 *Originally created by Andy Sloane
 * Compile:
 *   gcc -O2 -std=c99 -lm -o donut donut.c
 *
 * Run:
 *   ./donut
 *
 * Exit with Ctrl-C. Output uses only ASCII characters.
 */

#include <stdio.h>
#include <string.h>
#include <math.h>

int main() {
    float A = 0, B = 0;
    float i, j;
    float z[1760];
    char b[1760];
    printf("\x1b[2J");
    for (;;) {
        memset(b, 32, 1760);
        memset(z, 0, 1760 * sizeof(float));
        for (j = 0; j < 6.28; j += 0.07)
            for (i = 0; i < 6.28; i += 0.02) {
                float c = sin(i), d = cos(j), e = sin(A), f = sin(j), g = cos(A);
                float h = d + 2;
                float D = 1 / (c * h * e + f * g + 5);
                float l = cos(i), m = cos(B), n = sin(B);
                float t = c * h * g - f * e;
                int x = (int)(40 + 30 * D * (l * h * m - t * n));
                int y = (int)(12 + 15 * D * (l * h * n + t * m));
                int o = x + 80 * y;
                int N = (int)(8 * ((f * e - c * d * g) * m - c * d * e - f * g - l * d * n));
                if (y >= 0 && y < 24 && x >= 0 && x < 80 && D > z[o]) {
                    z[o] = D;
                    b[o] = ".,-~:;=!*#$@"[N > 0 ? N : 0];
                }
            }
        printf("\x1b[H");
        for (int k = 0; k < 1760; ++k)
            putchar(k % 80 ? b[k] : 10);
        A += 0.04;
        B += 0.02;
    }
    return 0;
}

/* EXPLANATION :

*This code is a famous piece of "obfuscated" C code known as Donut.c, originally created by Andy Sloane.
*It uses mathematical principles to render a rotating 3D donut (torus) using only ASCII characters in a terminal window.
*Here is a breakdown of how this mathematical magic works:
*1. The Geometry (The "Donut")The code uses a Torus equation parameterized by two angles:
*$i$ (the inner circle): 
*Rotates around the cross-section of the donut.
*$j$ (the outer circle): 
*Rotates around the central axis of the donut.The variables c, d, e, f, g are pre-calculated sine and cosine values of these angles.
*By looping through these angles (the nested for loops from 0 to 6.28, or $2\pi$), the code calculates the $x, y, z$ coordinates of points on the surface of the donut.
*2. Projection and Animation3D to 2D:
*The variable D represents the depth (projection). The code calculates where a 3D point should appear on your flat 2D screen based on its distance from the "camera."
*Rotation: The variables A and B are incremented at the bottom of the loop (A += 0.00004; B += 0.00002;). 
*These represent the rotation angles of the donut over time, making it appear to spin.
*Z-Buffering: The array z[1760] is a Z-buffer. It stores the depth of each pixel so that when the donut rotates, the "front" parts correctly hide the "back" parts.
*3. Rendering with TextLuminance ($N$): The variable N calculates the surface normal (the direction the surface is facing) relative to a light source.
*ASCII Shading: Based on the value of $N$, the code picks a character from the string ".-~:;=!*#$@" to represent brightness. A . is a dimly lit area, while an @ is a brightly lit highlight.
*Terminal Control: The command printf("\x1b[H") (line 34) sends an escape code to the terminal to move the cursor back to the top-left corner. 
*This allows the code to "redraw" the donut in the same spot, creating the illusion of smooth animation.
*To understand this code in detail, we have to look at it through three lenses:
*Trigonometry, Linear Algebra, and Computer Graphics.
*1. Defining the Shape (The Math)The code creates a donut shape (a torus) by rotating a small circle around a larger axis.
*The Coordinates: It starts with a circle of radius $R_1$ centered at $(R_2, 0, 0)$.
*The Rotation: The nested loops (lines 11–12) iterate through two angles:
*$\theta$ (variable i): The angle spinning around the cross-section of the donut.
*$\phi$ (variable j): The angle spinning around the center of the donut's hole.The 3D coordinates $(x, y, z)$ of any point on the donut before it starts spinning are calculated using these sine and cosine values.
*2. Rotation in 3D SpaceTo make the donut spin, the code uses Rotation Matrices.Lines 13–23 perform the math to rotate the donut around the X-axis (angle A) and the Z-axis (angle B).
*$A$ controls the pitch (tilting forward/backward).$B$ controls the yaw (spinning like a top).
*The complex-looking lines for x and y (lines 24–25) are the result of multiplying the point's coordinates by these rotation matrices and then projecting them onto a 2D screen.
*3. The "Z-Buffer" (Depth Control)One of the hardest parts of 3D graphics is making sure the "back" of the object doesn't draw over the "front."z[1760]:
*This is a one-dimensional array representing the screen.D = 1 / (c * h * e + f * g + 5): This calculates the depth ($1/z$).The Comparison (Line 28): if(... D > z[o]).
*If the current point being calculated is closer to the "camera" than whatever was previously drawn at that pixel, it updates the screen buffer.
*4. Lighting and Shading (The ASCII)The donut isn't just a flat shape; it looks 3D because of the "lighting.
*"The Normal: The code calculates the "surface normal" (the direction a specific point is facing).
*Luminance (N): Line 27 calculates the dot product between the surface normal and a fixed light source (pointing toward the viewer).
*The Character Map: * If the surface is facing the light, N is high, and it picks a character like @ or #.
*If the surface is angled away, it picks . or ~.This is why the donut has highlights and shadows.
*5. The Terminal "Hack"Finally, the code manages the display:memset(b, 32, 1760): Clears the frame by filling the character buffer with spaces (ASCII 32).printf("\x1b[H"): This is an ANSI escape code.
*Instead of clearing the whole screen (which causes flickering), it tells the terminal to move the cursor back to the "Home" position (0,0) and overwrite the old frame with the new one.
*Variable Map for ReferenceVariableRepresentsA, BThe rotation angles (over time).i, jThe "sweep" angles to draw the torus surface.z[ ]The depth buffer (keeps track of what's in front).b[ ]The character buffer (the actual pixels)
*.NThe brightness value for a specific point.
*
*/


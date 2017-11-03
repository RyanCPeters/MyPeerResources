#Eli Countrywood
#Section 3

#  Required import statement for Gui tools
import Gui3
import random
import math

# Named Constants
CANVAS_WIDTH = 1200
CANVAS_HEIGHT = 900


def draw_Riceberg(bx, by):
    ix = 1
    iy = .25
    if by < 0:
        xdiv = ix*(abs(by) / 1 + 5)
    else:
        xdiv = ix*((by / 7) + 1)

    if by < 0:
        ydiv = iy*(abs(by) / 1 + 5)
    else:
        ydiv = iy*((by / 7) + 2)

    icebergCoordinatesR = [[bx, by],
                           [bx + 2 * xdiv, by + 5 * ydiv],
                           [bx + 8 * xdiv, by + 8 * ydiv],
                           [bx + 12 * xdiv, by + 4 * ydiv],
                           [bx + 19 * xdiv, by + 2 * ydiv],
                           [bx + 20 * xdiv, by + 0 * ydiv], ]

    canvas.polygon(icebergCoordinatesR, fill='blue', width=0, outline="cyan")

def draw_Liceberg(bx, by):
    ix = 1
    iy = .25
    if by < 0:
        xdiv = ix*(abs(by) / 1 + 5)
    else:
        xdiv = ix*((by / 10) + 1)

    if by < 0:
        ydiv = iy*(abs(by) / 1 + 5)
    else:
        ydiv = iy*((by / 10) + 4)

    icebergCoordinatesL = [[bx, by],
                           [bx - 2 * xdiv, by + 5 * ydiv],
                           [bx - 8 * xdiv, by + 8 * ydiv],
                           [bx - 12 * xdiv, by + 4 * ydiv],
                           [bx - 19 * xdiv, by + 2 * ydiv],
                           [bx - 20 * xdiv, by + 0 * ydiv], ]


    canvas.polygon(icebergCoordinatesL, fill='cyan', width=0, outline="blue")

def draw_penguin(bx, by):
#draw one penguin. Scale height by orientation in scene to simulate depth of field.
#works ok but depth scaling is incomplete
    if by < 0:
        div = (abs(by)/50) + 2
    else:
        div = (by/-1000)+1


    # feet
    canvas.polygon([[bx - 5 * div, by ],
                    [bx - 1 * div, by + 4 * div],
                    [bx, by],
                    [bx + 1 * div, by + 4 * div],
                    [bx + 5 * div, by]],
                fill='yellow', outline = 'black')
    # L wing
    canvas.polygon([[bx - 10 * div, by + 6 * div],
                    [bx - 4 * div, by + 18 * div],
                    [bx - 4 * div, by + 13 * div]],
                fill='grey',outline = 'black')
    # R wing
    canvas.polygon([[bx + 12 * div, by + 8 * div],
                    [bx + 4 * div, by + 18 * div],
                    [bx + 4 * div, by + 13 * div]],
                fill='grey',outline = 'black')
    #body
    canvas.oval([[bx-6*div,by+2*div],
                 [bx+6*div,by+21*div]],
                fill = 'black',outline = 'black')
    #chest
    canvas.oval([[bx - 4 * div, by + 3 * div],
                 [bx + 4 * div, by + 16 * div]],
                fill='white')
    #head
    canvas.oval(
        [[bx-5*div,by+18*div],[bx+5*div,by+26*div]],
                fill = 'black',
                outline = 'black')
    #eyes
    canvas.circle([bx-2 * div, by+22 * div], 2*div, fill='white')
    canvas.circle([bx+2 * div, by+22 * div], 2*div, fill='white')
    canvas.circle([bx - 2 * div, by+21 * div], 1 * div, fill='black')
    canvas.circle([bx + 2 * div, by+21 * div], 1 * div, fill='black')

    #beak
    canvas.polygon([[bx-1*div,by+19*div],
                    [bx,by+20*div],
                    [bx+1*div,by+19*div]],
                   fill='yellow', outline = 'black')

def random_xlist(j):
    lx = []
    for i in range(0, j):
        lx.append(random.randrange(-650, 650, 1))
    return lx

def ascending_random_ylist(j):
    ly = []
    for i in range(0, j):
        ly.append(random.randrange(-450, 375, 1))
    list.sort(ly, reverse = 1)
    return ly

def poplulate_icefield(k):
    bx = random_xlist(k)
    by = ascending_random_ylist(k)
    for x, y in zip(bx, by):

        draw_Riceberg(x,y)
        draw_Liceberg(x, y)

def populate_penguins(p):
    bx = random_xlist(p)
    by = ascending_random_ylist(p)
    for x,y in zip(bx,by):
        draw_penguin(x,y)

def main():
    poplulate_icefield(300)
    populate_penguins(250)


    #
    # draw_Riceberg(-350,-300)
    # draw_Liceberg(0,0)
    # draw_Riceberg(100,100)


# #####################################################################

# Setup the canvas -- canvas is the drawing area
# Note that 'win' and 'canvas' are GLOBAL VARIABLES in this program
win = Gui3.Gui()
win.title('Playing around with Gui')
canvas = win.ca(width = CANVAS_WIDTH, height = CANVAS_HEIGHT)

# run the main function
main()

# show the window
win.mainloop()

# Here are some colors you can use: 'white', 'gray', 'black', 'red',
# 'green', 'blue', 'cyan', 'yellow', 'magenta', 'brown', 'darkgreen'
# Hundreds of colors here: http://tmml.sourceforge.net/doc/tk/colors.html
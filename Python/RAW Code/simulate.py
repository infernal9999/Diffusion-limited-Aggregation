import numpy as np
from random import randint
from graphics import *
from PIL import Image

"""
# For Windows Console Title Changing -

from os import system
ConsoleTitle="『DLA Simulator 2.0』"
system("title "+ConsoleTitle)
"""

while True:
    n=int(input('* Enter Grid Value: '))
    
    if (n<3):
        print('\n\t-> Enter a Greater Number!\n')
    elif n % 2 == 0:
        print('\n\t-> Even Number Entered!\n')
    else:
        break

global x, y, x_new, y_new, conditional_break, array
array=np.zeros(shape=(n,n))

def surround_check(x1,y1):
    global conditional_break
    conditional_break=0
    
    if ((array[int(x1)-1][int(y1)]==1) or (array[int(x1)+1][int(y1)]==1) or (array[int(x1)][int(y1)-1]==1) or (array[int(x1)][int(y1)+1]==1)):
        conditional_break=1

def CreateObject(n):
    global x, y, x_new, y_new, array
    
    x=(n-1)/2
    y=x
    
    x_new=x
    y_new=y
    
    array[int(x)][int(y)]=1
    
    surround_check(x,y)

def move(n):
    global x, y, x_new, y_new, array

    while True:
        flag=int(randint(0,1))
        selection=(int(randint(-10,10)))
        
        if (flag==0):
            if (selection<0):
                x_new=x-1
               
            if (selection>0):
                x_new=x+1
        
        else:
            if (selection<0):
                y_new=y-1
            
            if (selection>0):
                y_new=y+1
		
        if ((x_new==0) or (x_new==(n-1)) or (y_new==0) or (y_new==(n-1))):
            array[int(x_new)][int(y_new)]=1
            array[int(x)][int(y)]=0
            
            
            CreateObject(n)
        
        else:
            array[int(x)][int(y)]=0
            array[int(x_new)][int(y_new)]=1
            
            surround_check(x_new, y_new)
            
            if (conditional_break==1):
                CreateObject(n)
            else:
                x=x_new
                y=y_new
        
        if (conditional_break==1):
            break

def imageDraw(size):
    imgData=np.zeros((size, size, 3), dtype=np.uint8)
    
    for i in range(0,size):
        for j in range(0,size):
            if (array[i][j]==1):
                imgData[i][j]=[255,0,0]
            else:
                imgData[i][j]=[0,255,0]
    
    while True:
        name=input("\n* Enter a Name to Save the Output: ")
        
        if (name==""):
            print("\n\t-> Enter at least One Character!")
        else:
            break
    
    name+=".png"
    
    Image.fromarray(imgData).save(name)

    print("\n(The Output has been Saved as an PNG Image)\n")

def graphicsDraw(n):
    new_Hight=(disply_height-26)
    offset=(new_Hight%n)
    winSize=(new_Hight-offset)
    scl=int(winSize/n)
    if (scl<2):
        imageDraw(n)
    else:
        print("\n(Click Inside The Result Window To Exit)\n")
        
        win=GraphWin("SIMULATION RESULT ~ by infernal9999", "icon.ico", winSize+1, winSize+1)
        
        #win.setBackground(color_rgb(0,0,0))
        
        for i in range(0,n):
            for j in range(0,n):
                rect=Rectangle(Point((j*scl),(i*scl)), Point(((j+1)*scl),((i+1)*scl)))
                
                if (array[i][j]==1):
                    rect.setFill(color_rgb(255,0,0))
                else:
                    rect.setFill(color_rgb(0,255,0))
                
                rect.draw(win)

        '''print()
        print(array)'''
        
        win.getMouse()
        win.close()

def main():

    print("\n\t-> Please Wait....\n")
    
    CreateObject(n)
    move(n)

    print("    -> Done....")

    graphicsDraw(n)

main()

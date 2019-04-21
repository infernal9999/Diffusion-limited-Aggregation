var n, scl, random_Range, x, y, x_new, y_new, conditional_break, array=[], img=0, canvas;

function setup() {
   while (true) {
      n=prompt("*Please Enter no. of Cells-");
      
      if (n<3) {
         alert("Enter a Greater Number!");
      }
      else if (n%2===0) {
         alert("Even Number Entered!");
      }
      else
         break;
   }
   
   var default_scl=((windowHeight-(windowHeight%n))/n);
   var flag=0;

   if (default_scl>1) {
        while (true) {
      		flag=0;
      		scl=prompt("*Please Enter Cell Size-\t\tdefault: "+default_scl);
      		
      		if (scl !== "") {
        		if (scl<2) {
        			alert("Enter a Greater Number!");
        		}
        		else {
        			flag=1;
        		}
      		}
      		else {
         		scl=default_scl;
         		flag=1;
      		}
      		
      		if (flag==1)
         		break;
   		}

   		flag=0;
   }
   else {
   		flag=1;
   }
   
   if (flag!=1) {
        if ((n*scl)+1<=windowHeight) {
      		canvas=createCanvas((n*scl)+1, (n*scl)+1);
      		background(0);
   		}
   		else {
   			flag=1;
   		}
   }
   
   if (flag==1) {
      alert(":Converting Cell Size to 1 Pixels:")
      img=1;
   }
   
   for (var i=0; i<n; i++) {
      array[i]=[];
      for (var j=0; j<n; j++) {
         array[i][j]=0;
      }
   }
   
   while (true) {
      flag=0;
      random_Range=prompt("*Please Enter an Integer for Random Range-\tdefault: 10");
      
      if (random_Range !== "") {
         if (random_Range<2) {
            alert("Enter a Greater Number!");
         }
         else {
            flag=1;
         }
      }
      else {
         random_Range=10;
         flag=1;
      }
      
      if (flag==1)
         break;
   }
}

function surround_check(x1, y1) {
    conditional_break=0;
    
    if ((array[x1-1][y1]==1) || (array[x1+1][y1]==1) || (array[x1][y1-1]==1) || (array[x1][y1+1]==1))
        conditional_break=1;
}

function CreateObject() {
    x=(n-1)/2;
    y=x;
    
    x_new=x;
    y_new=y;
    
    array[x][y]=1;
    
    surround_check(x, y);
}

function draw_box() {
   var i, j
   
   if(img != 1) {
      for (i=0; i<n; i++) {
         for (j=0; j<n; j++) {
            if (array[i][j]==1) {
               fill(255, 0, 0);
            }
            else {
               fill(0, 255, 0);
            }
            rect(i*scl, j*scl, scl, scl);
         }
      }
      saveCanvas(canvas, 'Output.jpg');
   }
   else {
      var Output=createImage((n), (n));
      Output.loadPixels();
      
      var index
      
      for (i=0; i<n; i++) {
         for (j=0; j<n; j++) {
            index=(j+(i*n))*4;
            if (array[i][j]==1) {
               Output.pixels[index+0]=255;   // Red
               Output.pixels[index+1]=255;     // Green
               Output.pixels[index+2]=255;     // Blue
               Output.pixels[index+3]=255;   // Alpha
            }
            else {
               Output.pixels[index+0]=0;     // Red
               Output.pixels[index+1]=0;   // Green
               Output.pixels[index+2]=255;     // Blue
               Output.pixels[index+3]=255;   // Alpha
            }
         }
      }
      Output.updatePixels();
      Output.save('Output.png');
   }
}

function move() {
   while (true) {
      var flag=int(random(0,2))
      selection=int(random(-random_Range, random_Range))
      
      if (flag===0) {
         if (selection<0) {
            x_new=x-1;
         }
         if (selection>0) {
            x_new=x+1;
         }
      }
      else {
         if (selection<0) {
            y_new=y-1;
         }
         if (selection>0) {
            y_new=y+1;
         }
      }
      if ((x_new===0) || (x_new==(n-1)) || (y_new===0) || (y_new==(n-1))) {
         array[x_new][y_new]=1;
         array[x][y]=0;
         
         CreateObject(n);
      }
      else {
         array[x][y]=0;
         array[x_new][y_new]=1;
         
         surround_check(x_new, y_new);
         
         if (conditional_break==1) {
            CreateObject(n);
         }
         else {
            x=x_new;
            y=y_new;
         }
      }
      
      if (conditional_break==1)
         break;
   }
}

function draw() {
   CreateObject();
   move();
   
   draw_box();
   noLoop();
}
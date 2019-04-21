var cell=prompt("Please Enter Cell Value", "11");
var frameSkip=prompt("Please Enter Frame Skip Value", "1");
var random_Limit=prompt("Please Enter Random Limit", "10");

var scl=16;

var x, y, check, list=[], DeActive=0;

function setup() {
   createCanvas((cell*scl)+1, (cell*scl)+1);
   
   //frameRate(30);
   x=((width-1)/2)-(scl/2);
   y=((height-1)/2)-(scl/2);
}

function draw() {
   //background(0);
   for (m=0; m<frameSkip; m++) {
      var x1, y1, flag=int(random(2)), flag1=0, flag2=0;
      
      if (flag===0) {
         x1=int(random(-random_Limit, random_Limit));
      }
      else {
         y1=int(random(-random_Limit, random_Limit));
      }
      if (x1<0) {
         x-=scl;
      }
      if (x1>0) {
         x+=scl;
      }
      if (y1<0) {
         y-=scl;
      }
      if (y1>0) {
         y+=scl;
      }
      
      check_limit(x, y);
      
      if (check==1) {
         flag1=1;
      }
      
      if ((x==(width-scl-1)) || (x===0)) {
         flag1=1;
      }
      if ((y==(height-scl-1)) || (y===0)) {
         flag2=1;
      }
      //print('x='+x);
      //print('y='+y);
      
      //draw_box(x, y);
      
      if ((flag1==1) || (flag2==1)) {
         insertObject(x, y);
      }
      if (DeActive==1)
         break;
   }
   
   draw_box(x, y);
   
   if (DeActive==1)
      noLoop();
}

function draw_box(x4, y4) {
   for (var i=0; i<height; i+=scl) {
      for (var j=0; j<width; j+=scl) {
         if (list.length>0) {
            fill(0, 255, 0);
            for (var k=0; k<list.length; k++) {
               rect(list[k].x, list[k].y, scl, scl);
            }
         }
         if ((j==y4) && (i==x4)) {
            fill(0);
         }
         else {
            fill(255, 255, 0);
         }
         rect(i, j, scl, scl);
      }
   }
}

function check_limit(x3, y3) {
   var flag3=0, flag4=0;
   
   check=0;
   
   for (var l=0; l<list.length; l++) {
      if ((x3==list[l].x) && (((y3==(list[l].y-scl))) || ((y3==(list[l].y+scl))))) {
         flag3=1;
      }
      if ((y3==list[l].y) && (((x3==(list[l].x-scl))) || ((x3==(list[l].x+scl))))) {
         flag4=1;
      }
      if ((flag3==1) || (flag4==1))
         break;
   }
   
   if ((flag3==1) || (flag4==1))
   {
      check=1;
   }
}

function insertObject(x2, y2) {
   var pos = createVector(x2, y2);
   list.push(pos);
   createObject();
}
function createObject() {
   x=((width-1)/2)-(scl/2);
   y=((height-1)/2)-(scl/2);
   
   draw_box(x, y);
   
   check_limit(x, y);
   
   if (check==1) {
      DeActive=1;
   }
}
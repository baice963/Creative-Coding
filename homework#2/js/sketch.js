var ptA = 100;
var ptB = 1000;
var ptC = 300;
var y = 200;
var moveX = ptA;
var moveY = ptC;
var t = 0;
var dir = 1;
var value = 0;
var ellipseSize = 10;

function setup(){
  var cnv = createCanvas(window.innerWidth, window.innerHeight);
  background(255,0,0);
 
}

function draw(){
  background(7, 0, 9);

 
//   ZENO mouse follower
 
  t+=.01 * dir;
  if(t<=0 || t>=1) dir*=-1;
  
  var pct = pow(t,5.5);
  noStroke();
  fill(30,40,255);
  pct = (t == 1) ? 0 : Math.pow(3, 10 * (t - 1));
  drawMotion(120,pct);
  
  fill(255,10,10);
  pct = (-t) * t * t + 1;
  drawMotion1(200,pct);

  fill(55,210,10);
  pct = t * t * t * t;
  drawMotion(270,pct);

  
  fill(55,210,210);
  pct =  1 - (t) * t * t * t;
  drawMotion(300,pct);
 
  fill(5,20,210);
  pct = t*t;
  drawMotion1(580,pct);
  
}

function drawMotion(yOffset,pct){
  moveX = (1-pct)*ptA+pct*ptB;
  // line(ptA,yOffset,ptB,yOffset);
  ellipse(moveX,yOffset,ellipseSize,ellipseSize);
  if ( t>=0.9){
  ellipseSize = 80;
  } else {
    ellipseSize = 40;
  }
}

function drawMotion1(yOffset,pct){
  moveX = (1-pct)*ptA+pct*ptB;
  // line(ptA,yOffset,ptB,yOffset);
  ellipse(moveY,yOffset,moveX,moveX);
  // if ( t>=0.9){
  // ellipseSize = 80;
  // } else {
  //   ellipseSize = 40;
  // }
}



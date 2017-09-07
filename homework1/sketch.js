var ptA = 100;
var ptB = 400;
var y = 200;
var moveX = ptA;
var t = 0;
var dir = 1;
var value = 0;

var smoothPos = {x: 0, y: 0};

function setup(){
  var cnv = createCanvas(window.innerWidth, window.innerHeight);
  background(255,0,0);
 
}

function draw(){
  background(207, 178, 229);

 
//   ZENO mouse follower
  ellipse(smoothPos.x, smoothPos.y,30,30);
  var sPct = .9;
  smoothPos.x = sPct*smoothPos.x+(1-sPct)*mouseX;
  smoothPos.y = sPct*smoothPos.y+(1-sPct)*mouseY;
  
  //(1-pct) *A + pct * B
  t+=.01 * dir;
  if(t<=0 || t>=1) dir*=-1;
  
  var pct = pow(t,5.5);
  
  pct = (t == 1) ? 0 : Math.pow(3, 10 * (t - 1));
  drawMotion(120,pct);
  text("inExpo",ptB+5, y-80);
  
  pct = (-t) * t * t + 1;
  drawMotion(160,pct);
  text("outCubic_",ptB+5, y-40);
  
  pct = t * t * t * t;
  drawMotion(200,pct);
  text("inCirc",ptB+5, y);
  
  pct =  1 - (t) * t * t * t;
  drawMotion(240,pct);
  text("outQuart_",ptB+5, y+40);
  
  pct = t*t;
  drawMotion(280,pct);
  text("inQuad_",ptB+5, y+80);
  
}

function drawMotion(yOffset,pct){
  moveX = (1-pct)*ptA+pct*ptB;
  line(ptA,yOffset,ptB,yOffset);
  ellipse(moveX,yOffset,10,10);
}



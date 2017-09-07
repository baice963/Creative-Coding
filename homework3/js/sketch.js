var img;
var offset = 0;
var easing = 0.05;

function setup() {
  createCanvas(720, 400);
  img = loadImage("klimt.jpg");  // Load an image into the program
}

function draw() {
  image(img, 0, 0);  // Display at full opacity
  var dx = (mouseX-img.width/2) - offset;
  offset += dx * easing;
  tint(255, 127);  // Display at half opacity
  image(img, offset, 0);
}
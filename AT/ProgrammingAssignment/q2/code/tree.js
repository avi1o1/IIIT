// Roll Number : 2023111023 [ r = 023 ]
// (r mod 30)−15 + 10*(−1)[15−(r mod 30)]
// (23-15) + 10*(-1)**(15-23) = 18

var system = document.getElementById('sys');
system.innerHTML = "Tree";

var canvas = document.getElementById('canvas');
var ctx = canvas.getContext("2d");
ctx.translate(canvas.width / 2, 0);
ctx.strokeStyle = 'rgb(4, 2, 0)';

const tree = new LSystem({
  axiom: 'X',
  productions: {
    'F': "FF",
    'X': "F[-X]X[+X][+X]F-[-X]+X[-X]"
  },
  finals: {
    '+': () => { ctx.rotate((Math.PI / 180) * 18); },
    '-': () => { ctx.rotate((Math.PI / 180) * -18); },
    'F': () => {
      ctx.beginPath();
      ctx.moveTo(0, 0);
      ctx.lineTo(0, 5 / (tree.iterations + 1));
      ctx.stroke();
      ctx.translate(0, 5 / (tree.iterations + 1));
    },
    '[': () => { ctx.save(); },
    ']': () => { ctx.restore(); }
  }
});

let currentIteration = 0;
const maxIterations = 5;
function drawWithDelay() {
  if (currentIteration < maxIterations) {
    tree.iterate(1);
    ctx.clearRect(0, 0, canvas.width, canvas.height);
    ctx.setTransform(1, 0, 0, 1, 0, 0);
    ctx.translate(canvas.width / 2, 0);
    tree.final();

    currentIteration++;
    var d = document.getElementById('iCount');
    d.innerHTML = "Iteration : " + currentIteration;
    setTimeout(drawWithDelay, 420);
  }
}

drawWithDelay();

var system = document.getElementById('sys');
system.innerHTML = "Mirrorball";

var canvas = document.getElementById('canvas');
var ctx = canvas.getContext("2d");
ctx.translate(690, 570);
ctx.strokeStyle = 'rgb(4, 2, 0)';

const mirrorball = new LSystem({
  axiom: 'G',
  productions: {
    'G': "X-G-X",
    'X': "G+Y+G",
    'Y': "[+F]F[-F]"
  },
  finals: {
    '+': () => { ctx.rotate((Math.PI / 180) * 30); },
    '-': () => { ctx.rotate((Math.PI / 180) * -30); },
    'F': () => {
      ctx.beginPath();
      ctx.moveTo(0, 0);
      ctx.lineTo(0, 3 / (mirrorball.iterations + 1));
      ctx.stroke();
      ctx.translate(0, 3 / (mirrorball.iterations + 1));
    },
    'G': () => {
      ctx.translate(0, 3 / (mirrorball.iterations + 1));
    },
    '[': () => { ctx.save(); },
    ']': () => { ctx.restore(); }
  }
});

let currentIteration = 0;
const maxIterations = 15;
function drawWithDelay() {
  if (currentIteration < maxIterations) {
    mirrorball.iterate(1);
    ctx.clearRect(-canvas.width, -canvas.height, 2*canvas.width, 2*canvas.height);
    mirrorball.final();

    currentIteration++;
    var d = document.getElementById('iCount');
    d.innerHTML = "Iteration : " + currentIteration;
    setTimeout(drawWithDelay, 370);
  }
}

drawWithDelay();

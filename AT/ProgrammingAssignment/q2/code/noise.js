var system = document.getElementById('sys');
system.innerHTML = "Noise";

var canvas = document.getElementById('canvas');
var ctx = canvas.getContext("2d");
ctx.strokeStyle = 'rgb(4, 2, 0)';

function clearCanvas() {
    ctx.save();
    ctx.setTransform(1, 0, 0, 1, 0, 0);
    ctx.clearRect(0, 0, canvas.width, canvas.height);
    ctx.restore();
}

const noise = new LSystem({
  axiom: 'F+F',
  productions: {
    'F': 'F-F++F-F',
    'F<F>-F': 'F-+F+F',
  },
  finals: {
    '+': () => { ctx.rotate((Math.PI / 180) * 90); },
    '-': () => { ctx.rotate((Math.PI / 180) * -90); },
    'F': () => {
      ctx.beginPath();
      ctx.moveTo(0, 0);
      ctx.lineTo(0, 17 / (noise.iterations + 1));
      ctx.stroke();
      ctx.translate(0, 17 / (noise.iterations + 1));
    }
  }
});

let currentIteration = 0;
const maxIterations = 11;
function drawWithDelay() {
  if (currentIteration < maxIterations) {
    noise.iterate(1);
    clearCanvas();
    ctx.setTransform(1, 0, 0, 1, 0, 0);
    ctx.translate(canvas.width / 2, 0);
    noise.final();

    currentIteration++;
    var d = document.getElementById('iCount');
    d.innerHTML = "Iteration : " + currentIteration;
    setTimeout(drawWithDelay, 370);
  }
}

clearCanvas();
drawWithDelay();
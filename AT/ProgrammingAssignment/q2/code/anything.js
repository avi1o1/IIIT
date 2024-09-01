var system = document.getElementById('sys');
system.innerHTML = "Anything";

var canvas = document.getElementById('canvas');
var ctx = canvas.getContext("2d");
ctx.translate(canvas.width / 2, 200);
ctx.strokeStyle = 'rgb(4, 2, 0)';

function clearCanvas() {
    ctx.save();
    ctx.setTransform(1, 0, 0, 1, 0, 0);
    ctx.clearRect(0, 0, canvas.width, canvas.height);
    ctx.restore();
}

const productions = {
  'X': ["F-[[-X]+X]+F[+FX]-X", "F+[[+X]-]-[-X]+X[X]"],
  'F': ["F[F]F", "F[+]F", "F[FF]F"]
};

const weightedProductions = {};
for (const [key, value] of Object.entries(productions)) {
  weightedProductions[key] = () => value[Math.floor(Math.random() * value.length)];
}

console.log(weightedProductions);

const tree = new LSystem({
  axiom: 'X',
  productions: weightedProductions,
  finals: {
    '+': () => { ctx.rotate((Math.PI / 180) * 12.5); },
    '-': () => { ctx.rotate((Math.PI / 180) * -12.5); },
    'F': () => {
      ctx.beginPath();
      ctx.moveTo(0, 0);
      ctx.lineTo(0, 11 / (tree.iterations + 1));
      ctx.stroke();
      ctx.translate(0, 11 / (tree.iterations + 1));
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
    clearCanvas();
    tree.final();

    currentIteration++;
    var d = document.getElementById('iCount');
    d.innerHTML = "Iteration : " + currentIteration;
    setTimeout(drawWithDelay, 370);
  }
}

clearCanvas();
drawWithDelay();

let canvas = document.getElementById("gameCanvas");
let ctx = canvas.getContext("2d");

canvas.width = 600;
canvas.height = 800;

Module().then(module => {
    let updateGame = module.cwrap("updateGame", null, []);
    let movePaddle = module.cwrap("movePaddle", null, ["number"]);
    let getBallX = module.cwrap("getBallX", "number");
    let getBallY = module.cwrap("getBallY", "number");
    let getPaddle1Y = module.cwrap("getPaddle1Y", "number");
    let getPaddle2Y = module.cwrap("getPaddle2Y", "number");

    function drawGame() {
        ctx.clearRect(0, 0, canvas.width, canvas.height);

        let ballX = getBallX();
        let ballY = getBallY();
        let paddle1Y = getPaddle1Y();
        let paddle2Y = getPaddle2Y();

        ctx.fillStyle = "white";
        ctx.fillRect(0, paddle1Y, 40, 225); 
        ctx.fillRect(canvas.width - 40, paddle2Y, 40, 225); 

        ctx.beginPath();
        ctx.arc(ballX, ballY, 10, 0, Math.PI * 2);
        ctx.fill();

        requestAnimationFrame(drawGame);
    }

    function gameLoop() {
        updateGame(); 
        setTimeout(gameLoop, 16);
    }

    document.addEventListener("keydown", event => {
        if (event.key === "ArrowUp") {
            movePaddle(-1); 
        } else if (event.key === "ArrowDown") {
            movePaddle(1); 
        }
    });

    document.addEventListener("keyup", () => {
        movePaddle(0); 
    });

    drawGame();
    gameLoop();
});

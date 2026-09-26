let btn = document.getElementById("myBtn") as HTMLElement;
let resetBtn = document.getElementById("resetBtn") as HTMLElement;
let title = document.getElementById("title") as HTMLElement;

let count: number = 0;

btn.addEventListener("click", () => {
    count++;
    title.innerText = "Clicked " + count + " Times!";
});
resetBtn.addEventListener("click", () => {
    count = 0;
    title.innerText = "Resetted to zero";
});

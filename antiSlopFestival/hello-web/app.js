"use strict";
let btn = document.getElementById("myBtn");
let resetBtn = document.getElementById("resetBtn");
let title = document.getElementById("title");
let count = 0;
btn.addEventListener("click", () => {
    count++;
    title.innerText = "Clicked " + count + " Times!";
});
resetBtn.addEventListener("click", () => {
    count = 0;
    title.innerText = "Resetted to zero";
});

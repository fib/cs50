function welcome_message() {
    var welcome = document.getElementById("welcome");
    var name = document.getElementById("name").value;

    welcome.innerHTML = `Welcome, ${name}!`
    welcome.style.opacity = 100;
}

function gen_number() {
    var output = document.getElementById("numbers");

    var number = Math.floor(Math.random() * 100000);

    output.innerHTML = `<li class="list-group-item">${number}</li>${output.innerHTML}`;
}
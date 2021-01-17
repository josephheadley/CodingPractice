// console.log(window)

// Single element
const form = document.getElementById('my-form');
// console.log(form);

// console.log(document.querySelector('.container')); //use this method

// console.log(document.querySelector('h1'));

// Multiple element
// console.log(document.querySelectorAll('.item')); //cool method. basically an array. use this method
// console.log(document.getElementsByClassName('item')); //lame method
// console.log(document.getElementsByTagName('li')); //another lame method


// Loop through objects
const items = document.querySelectorAll('.item');

// items.forEach((item) => console.log(item));

const ul = document.querySelector('.items');

// ul.remove(); //Removes all the unordered list items on the html page

// ul.lastElementChild.remove(); //Removes last item from the unordered list on the html page
/* ul.firstElementChild.textContent = 'Hello';
ul.children[1].innerText = 'Brad';
ul.lastElementChild.innerHTML = '<h1>Hello</h1>'; */

const btn = document.querySelector('.btn');
// btn.style.background = 'red';

/* btn.addEventListener('click', (e) => {
    e.preventDefault();
    // console.log(e.target);
    // console.log(e.target.className);
    document.querySelector('#my-form').style.background = '#ccc';
    document.querySelector('body').classList.add('bg-dark');
    document.querySelector('.items').lastElementChild.innerHTML = '<h1>Hello</h1>';
}); */

const myForm = document.querySelector('#my-form');
const nameInput = document.querySelector('#name');
const emailInput = document.querySelector('#email');
const msg = document.querySelector('.msg');
const userList = document.querySelector('#users');

myForm.addEventListener('submit', onSubmit);

function onSubmit(e) {
    e.preventDefault();

    // console.log(nameInput.value);

    if(nameInput.value === '' || emailInput.value === '') {
        msg.classList.add('error');
        msg.innerHTML = 'Please enter all fields';

        setTimeout(() => msg.remove(), 3000);
    }
    else {
        const li = document.createElement('li');
        li.appendChild(document.createTextNode(`${nameInput.value} : ${emailInput.value}`));

        userList.appendChild(li);

        // Clear fields
        nameInput.value = '';
        emailInput.value = '';
    }
}


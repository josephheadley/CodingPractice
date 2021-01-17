// console.log("Hello World");
// console.error("This is an error");
// console.warn("This is a warning");


// Variables
// v̶a̶r̶, let, const 
// Don't use var keyword cuz var is globally defined which can lead conflicts

let age = 30;
age = 31;

console.log(age);

const month = 7;
// month = 9;

console.log(month)

// Tip: Always use const keywords, unless you know you will have to reassign variable value.


// Primitive Data Types
// String, Numbers, Boolean, null, undefined

const name = 'John';
const num = 30;
const rating = 4.5;
const isCool = true;
const a = null;
const b = undefined;
let c;

// console.log(typeof x);


// Concatenation
console.log('My name is ' + name + ' and I am ' + age);

// Template String
const hello = `My name is ${name} and I am ${age}`;
console.log(hello);

// String Methods
const s = 'Hello World!';
const t = 'technology, computers, it, code';

console.log(s.length);
console.log(s.toUpperCase());
console.log(s.toLowerCase());
console.log(s.substring(0,5));
console.log(s.substring(0,5).toUpperCase());
console.log(s.split(''));

console.log(t.split(', '));


// Arrays
const numbers = new Array(1,2,3,4,5); //Array Creation by Constructor
console.log(numbers);

const fruits = ['apples', 'oranges', 'pears']; //Array Creation by Definition
console.log(fruits);
console.log(fruits[1]);

fruits[3] = 'grapes'; //Even though we used the keyword const, we can still add values to the array. We just can't reassign the array.
console.log(fruits);

fruits.push('mangos');
console.log(fruits);

fruits.unshift('strawberries');
console.log(fruits);

fruits.pop();
console.log(fruits);

console.log(Array.isArray(fruits));
console.log(Array.isArray("Hello"));

console.log(fruits.indexOf('oranges'));
console.log(fruits.indexOf('bananas'));


// Object Literals (Key-Value Pairs)

const person = {
    firstName: 'John',
    lastName: 'Doe',
    age: 30,
    hobbies: ['music', 'movies', 'sports'],
    address: {
        street: '50 main st',
        city: 'Boston',
        state: 'MA'
    }
};

console.log(person);
console.log(person.firstName, person.lastName);
console.log(person.hobbies[1]);
console.log(person.address.city);

// Destructuring
const { firstName, lastName, address: { city } } = person;
console.log(firstName);
console.log(city);

person.email = 'john@gmail.com';
console.log(person);


// Array of Objects
const todos = [
    {
        id: 1,
        text: "Take out trash",
        isCompleted: true
    },
    {
        id: 2,
        text: "Meeting with boss",
        isCompleted: true
    },
    {
        id: 3,
        text: "Dentist appt",
        isCompleted: false
    },
];

console.log(todos);
console.log(todos[1].text);

const todoJSON = JSON.stringify(todos);
console.log(todoJSON);


// For Loops
for(let i = 0; i < 10; i++) {
    console.log(`For Loop Number: ${i}`);
}

// While Loops
let i = 0;
while(i < 10) {
    console.log(`While Loop Number: ${i}`);
    i++;
}

// Iterating through an Array
for(let i = 0; i < todos.length; i++) {
    console.log(todos[i].text);
}

for(let todo of todos) {
    console.log(todo.isCompleted);
}

// High Order Array Methods
// forEach, map, filter
todos.forEach(function(todo) {
    console.log(todo.text);
});

// map function returns an array and thus must be assigned to a variable
const todoText = todos.map(function(todo) {
    return todo.text;
});

console.log(todoText);

const todoCompleted = todos.filter(function(todo) {
    return todo.isCompleted === true;
}).map(function(todo) {
    return todo.text;
})

console.log(todoCompleted);


// Conditionals
const x = 7;
const y = 11;

/* if(x == 10) { // == Matches only values
    console.log('x is string 10');
};

if(x === 10) { // === Matches values and data types
    console.log('x is number 10');
}

else if (x > 10) {
    console.log('x is greater than 10')
}

else {
    console.log('x is less than 10');
}; */

if (x > 5 || y > 10) {
    console.log('x is more than 5 OR y is more than 10')
}

if (x > 5 && y > 10) {
    console.log('x is more than 5 AND y is more than 10')
}

// Ternary Operator
const TO = 11;

const color = TO > 10 ? 'red' : 'blue';
// TO > 10 == if TO > 10
// ? 'red' == then color = 'red'
// : 'blue == else color = 'blue'

console.log(color)

// Switches
switch (color) {
    case 'red':
        console.log('color is red');
        break;
    case 'blue':
        console.log('color is blue');
        break;
    default:
        console.log('color is NOT red or blue');
        break;
}


// Functions
function addNums(num1 = 1, num2 = 1) {
    return num1 + num2;
}

console.log(addNums());
console.log(addNums(4,5));

// Arrow Functions
const multNums = (num1 = 1, num2 = 1) => num1 * num2;

console.log(multNums());
console.log(multNums(4,5));

// Works well with forEach loops
todos.forEach((todo) => console.log(`ID Number: ${todo.id}`));


// OOP

// Constructor function
/* function Person(firstName, lastName, dob) {
    this.firstName = firstName;
    this.lastName = lastName;
    this.dob = new Date(dob);
    /* this.getBirthYear = function() {
        return this.dob.getFullYear();
    } */
    /* this.getFullName = function() {
        return `${this.firstName} ${this.lastName}`;
    }
} */

// Prototypes
/* Person.prototype.getBirthYear = function() {
    return this.dob.getFullYear();
}

Person.prototype.getFullName = function() {
    return `${this.firstName} ${this.lastName}`;
} */

// Class
class Person {
    constructor(firstName,lastName,dob) {
        this.firstName = firstName;
        this.lastName = lastName;
        this.dob = new Date(dob);
    }

    getBirthYear() {
        return this.dob.getFullYear();
    }

    getFullName() {
        return `${this.firstName} ${this.lastName}`;
    }
}

// Instantiate object
const person1 = new Person('John', 'Doe', '4-3-1980');
const person2 = new Person('Mary', 'Smith', '3-6-1970');

console.log(person1);
console.log(person2.dob.getFullYear());

console.log(person1.getBirthYear());
console.log(person2.getFullName());







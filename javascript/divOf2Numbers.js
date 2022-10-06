const x = 1;
const y = 2;

const div = x / y;
console.log(div);

const z = [1,2,3,4,5];
const divA = z.reduce((ac, add) => ac / add, 0);
console.log(divA);
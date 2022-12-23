const fs = require('fs');

const expected = fs.readFileSync('output3.txt').toString();
const actual = fs.readFileSync('out3.txt').toString();

let maxLen = Math.max(expected.length, actual.length);

let line = 1;
for (let i = 0; i < maxLen; i++) {
  if(expected[i] !== actual[i]) {
    console.log(`Line ${line} is different`);
    break;
  }
  if(expected[i] === '\n') {
    line++;
  }
}
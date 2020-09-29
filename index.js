// index.js
const Mustache = require('mustache');
const fs = require('fs');
const { exit } = require('process');
const MUSTACHE_MAIN_DIR = './main.mustache';


let rawdata = fs.readFileSync('contributers.json');
let student = JSON.parse(rawdata);
let contribs = student['contribs']
let length = contribs.length
let Data
if(length<1){
  Data = {"Data":[]}
}else{
  let arr = []
  for(var i=0;i<length;i+=3){
    arr.push(contribs.splice(0,3))
  }
  Data = {
    "Data":arr
  }
  console.log(Data);
}
/**
  * A - We open 'main.mustache'
  * B - We ask Mustache to render our file with the data
  * C - We create a README.md file with the generated output
  */
function generateReadMe() {
  fs.readFile(MUSTACHE_MAIN_DIR, (err, data) =>  {
    if (err) throw err;
    const output = Mustache.render(data.toString(), Data);
    fs.writeFileSync('README.md', output);
  });
}
generateReadMe();
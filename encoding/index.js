const encoding = require("encoding");

const buffer = encoding.convert("http你", "gbk", "utf-8");

console.log(buffer);

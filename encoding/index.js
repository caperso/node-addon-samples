const encoding = require("encoding");

const buffer = encoding.convert("http://你hao.com", "gbk", "utf-8");

console.log(buffer);

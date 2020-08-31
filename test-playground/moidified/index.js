
var addon = require('bindings')('addon.node')

console.log('This should be eight:', addon.Test_string("in this real world"))
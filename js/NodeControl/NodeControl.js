const tty = require('tty');
const SerialPort = require("serialport");
const ReadLine = require('@serialport/parser-readline');
const dev = "/dev/ttyACM0";
const arduino = new SerialPort(dev, { baudRate: 57600 });
const parser = new ReadLine();

parser.on('data', function(line) {
    console.log(`> ${line}`)
    setTimeout(r, 1000);
});
arduino.pipe(parser);
console.log('Running...');
arduino.write('r');
console.log('Done');

function r() {
    arduino.write('r');
    setTimeout(b, 1000);

}

function b() {
    arduino.write('b');
    setTimeout(g, 1000);

}

function g() {
    arduino.write('g');
    setTimeout(r, 1000);
}

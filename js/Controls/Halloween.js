const tty = require('tty');
const SerialPort = require("serialport");
const Ready = require('@serialport/parser-ready');
const dev = "/dev/ttyACM0";
const arduino = new SerialPort(dev, { baudRate: 57600 });
const soundsPath = './sounds/';
const fs = require('fs');
const Sound = require('node-aplay');

let files = [];

fs.readdirSync(soundsPath).forEach( file => {
    if (file.endsWith('.wav')) {
        files.push(file);
    }
});

const parser = arduino.pipe(new Ready({ delimiter: 'Starting' }));
parser.on('ready', playSound);
parser.on('data', function(line) {
    console.log(`> ${line}`)
});
console.log('Running...');

function red() {
    arduino.write('r');

}

function blue() {
    arduino.write('b');

}

function green() {
    arduino.write('g');
}

function color(r,g,b) {
    arduino.write()
}

function white() {
    arduino.write('w');
}

function off() {
    arduino.write('o');
}

function playSound()
{
    var pick = (Math.floor(Math.random() * 5) + 1);
    if (pick == 1) {
        red();
    } else if (pick == 2) {
        green();
    } else if (pick == 3) {
        blue();
    } else if (pick == 4) {
        white();
    }
    var file = files[Math.floor(Math.random() * files.length)];
    console.log(file)
    var sound = new Sound(soundsPath+file);
    var timeout = Math.random() * 10000;
    sound.on('complete', function() {
        off();
        setTimeout(playSound, timeout);
    });
    sound.play();
}

const soundsPath = './sounds/';
const fs = require('fs');
const Sound = require('node-aplay');

var files = [];
var sounds = [];

fs.readdirSync(soundsPath).forEach( file => {
    if (file.endsWith('.wav')) {
        files.push(file);
    }
});

playSound(soundsPath, files);

function playSound(soundsPath, files)
{
    var file = files[Math.floor(Math.random() * files.length)];
    console.log(file)
    var sound = new Sound(soundsPath+file);
    var timeout = Math.random() * 20000;
    sound.on('complete', function() {
        setTimeout(function() {
            playSound(soundsPath, files);
        }, timeout);
    });
    sound.play();
}

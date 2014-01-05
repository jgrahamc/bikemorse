bikemorse
=========

Bicycle headlamp that flashes a message in Morse Code.

Details
-------

This project started when a cheap bicycle lamp broke. The old light used
an actual lamp (not LEDs) and was pretty large. I decided to turn it into 
a flashing bike lamp, but instead of flashing a simple sequence it would
flash a sentence of my choosing in Morse Code.

Here's the original lamp:

![lamp](img/2.jpg?raw=true)

There was space inside the lamp body for a 4 AA battery holder and I was
able to make the battery holder touch against the lamp's original switch 
to turn the lamp on and off.

The microcontroller used for the morse is a 5V [Adafruit
Trinket](http://www.adafruit.com/products/1501). It will accept the 6V
from the batteries. The output of one GPIO pin is fed into a
transistor (a 2N3904) which switches four high-brightness white LEDs
on and off.

The transistor base is fed through a resistor from GPIO pin #1 and
each of the four LEDs has a 220 ohm resistor in series to restrict the
current flowing. A similar circuit can be found
[here](http://www.ecs.umass.edu/ece/m5/tutorials/multiple_LEDs_tutorial.html).

The breadboarded transistor/LED circuit looks like this:

![lamp](img/1.jpg?raw=true)

When put together the insides of the lamp consist of the following:

![inside](img/3.jpg?raw=true)

The breadboarded circuit was transferred to some strip board and all that's
needed in addition are a few wires to connect things up. The code contains
a fixed string; it is flashed repeatedly.

And here it is in action. It's a little hard to see the Morse Code because of the
response of my digital camera to the very bright light.

![movie](img/movie.gif?raw=true)





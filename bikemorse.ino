// bikemorse: small program that flashes LEDs attached to a GPIO
// pin via a transistor. The LEDs are flashed in Morse Code. The 
// message flashed is set in the program.
//
// Copyright (c) 2014 John Graham-Cumming
//
// This assumes that an Adafruit Trinket at 16Mhz/5V is used

// This is the message to be flashed. It must be in upper case, 
// no punctuation is allowed (only spaces)

const char message[] = "HELLO WORLD";

// The LEDs (and transistor) are attached to pin 1

const int ledPin = 1;

void setup() {
  pinMode(ledPin, OUTPUT);  
}

void loop() {
  morseString(message);
}

// Morse timings are all based on the length of a dit. Here a dit
// is set at 40ms (quite fast so that the bicycle lamp flashes fairly
// fast).
//
// dit = length of .
// dah = length of -
// symbol_gap = length of time between dit/dah
// letter_gap = length of time between letters
// word_gap = length of time between words
//
// Note that the letter_gap and word_gap are less than expected because
// each symbol/letter is always followed by the appropriate delay so to
// get the correct gap it's necessary to subtract any previous delay.

const int dit = 40;
const int dah = 3 * dit;
const int symbol_gap = dit;
const int letter_gap = 3 * dit - symbol_gap;
const int word_gap = 7 * dit - letter_gap;

// The Morse Code for the 26 letters of the alphabet. Each has four symbols here to
// fit nicely into a C array, but for those that have less than four actual symbols
// spaces are used for padding and are ignored by morseChar below.

char morse[26][5] = {".-  ", "-...", "-.-.", "-.. ", ".   ", "..-.", "--. ", "....",
  "..  ", ".---", "-.- ", ".-..", "--  ", "-.  ", "--- ", ".--.", "--.-", ".-. ",
  "... ", "-   ", "..- ", "...-", ".-- ", "-..-", "-.--", "--.."};

// morseChar: flash a single upper-case character on the LEDs with the appropriate
// timing (ends with a letter_gap)
void morseChar(char c) {
  char *m = morse[c-65];
  
  while (*m && *m != ' ') {
    digitalWrite(ledPin, HIGH);
    if (*m == '.') {
      delay(dit);
    } else {
      delay(dah);
    }
    digitalWrite(ledPin, LOW);
    delay(symbol_gap);
    
    m += 1;
  }
  
  delay(letter_gap);
}

// morseString: flash an entire string on the LEDs interpreting
// spaces as gaps between words.
void morseString(const char * s) {
  while (*s) {
    if (*s == ' ') {
      delay(word_gap);
    } else {
      morseChar(*s);
    }
    
    s += 1;
  }

  delay(word_gap);
}


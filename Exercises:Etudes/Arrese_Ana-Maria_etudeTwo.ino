/**********************ETUDE 2 CART 360 2017*******************************
 * WELCOME! 
 * THE PURPOSE OF THIS EXERCISE IS TO DESIGN A VERY SIMPLE KEYBOARD (5 KEYS)
 * WHICH ALLOWS YOU TO PLAY LIVE, RECORD, AND PLAYBACK. 
 * THERE WILL BE A BUTTON WHICH WHEN PRESSED WILL TAKE THE USER TO THE NEXT MODE:
 * THERE ARE 5 POSSIBLE MODES
 * 0 ==  reset    ==   led off == also resets
 * 1 ==  live     ==   led BLUE
 * 2 ==  record   ==   led RED
 * 3 ==  play     ==   led GREEN
 * 4 ==  loopMODE ==   led PURPLE
 * 
 * ADDITIONALLY - WHEN THE USER CHANGES MODE, 
 * THE RGB LED WILL CHANGE COLOR (ACCORDING TO THE SPECIFICATIONS)

 * PLEASE FOLLOW THE INSTRUCTIONS IN THE COMMENTS:
 * DO NOT ADD ANY MORE FUNCTION DEFINITIONS 
 * ONLY IMPLEMENT THE FUNCTION DEFINITIONS SUPPLIED
 * THERE IS NO NEED TO ADD ANY NEW VARIABLES OR CONSTANTS
 * PROVIDE COMMENTS FOR ANY OF THE CODE IMPLEMENTED
 * GOOD LUCK!
 */

/* ANALYSIS OF THE BEHAVIOR OF THE RESISTOR LADDER:
 * I chose to use resistors with a low Ohm value in order to have my speaker output a clearer, more concise sound
 * for every note being pressed. At first I had started by putting 3 100 Ohm resistors and then 2 10K Ohm resistors
 * and I noticed that the two last notes had a very low sound output. It was very hard to hear. Therefore, I ended
 * up switching my resistors and putting the first 3 as 100 Ohm resistors and the last two as 300 Ohm resistors. 
 * Essentially, what happens in the Arduino is that since my resistors have a smaller Ohm value, there is less resistance
 * on each circuit, especially on the last one that accumulates all the resistance, and thus more voltage flows and there is 
 * a higher frequency. With a higher frequency, the sound output becomes easier to hear and a bit louder as well.
 * This way, the user can hear better what he/she is playing. 
 * With my high Ohm value resistors, my last note button had a frequency of 8. Now that I changed the last two to 300 Ohm 
 * resistors, my last note button has a frequency of 111 (more frequency)!
 */
 
/**** CONSTANTS ********************************************************/

#define BUTTON_MODE_PIN 2 // Button to change the mode

// constants for RGB LED
#define LED_PIN_R 9 // R PIN
#define LED_PIN_G 6 // G PIN
#define LED_PIN_B 5 // B PIN

// constant for note in (button-resistor ladder on breadboard)
# define NOTE_IN_PIN A0

//constant for max number of notes in array
#define MAX_NOTES 16

// a constant for duration
const int duration =200;

// constant for pin to output for buzzer 
#define BUZZER_PIN 3 // PWM

/******** VARIABLES *****************************************************/
// counter for how many notes we have
int countNotes =0;
// array to hold the notes played (for record/play mode)
int notes [MAX_NOTES]; 
int mode =0; // start at off

/*************************************************************************/


/**********************SETUP() DO NOT CHANGE*******************************/
// Declare pin mode for the single digital input
void setup()
{
  pinMode(BUTTON_MODE_PIN, INPUT);
  //IMPLEMENT

  //use pinMode for digital output of RGB colors
   pinMode(LED_PIN_R, OUTPUT);
   pinMode(LED_PIN_G, OUTPUT);
   pinMode(LED_PIN_B, OUTPUT);

   //use pinMode for digital output of buzzer 
   pinMode(BUZZER_PIN, OUTPUT);

   //to output some println statements int the serial monitor
   Serial.begin(9600);
}

/**********************LOOP() DO NOT CHANGE *******************************
 * INSTRUCTIONS: 
 * There is NO NEED to change the loop - it establishes the flow of the program
 * We call here 3 functions repeatedly:
 * 1: chooseMode(): this function will determine the mode that your program is in 
 * based on if the button (linked to the BUTTON_MODE_PIN) was pressed
 * 2: setRGB(): will set the color of the RGB LED based on the value of the mode variable
 * 3: selectMode(): will determine which function to call based on the value of the mode variable

**************************************************************************/
void loop()
{
  chooseMode();
  setRGB();
  selectMode();
}
/******************CHOOSEMODE(): IMPLEMENT *********************************
 * INSTRUCTIONS:
 * Read the value from the Button (linked to the BUTTON_MODE_PIN) and 
 * if is being pressed then change the mode variable.
 * REMEMBER:
 * mode == 0 is reset 
 * mode == 1 is live
 * mode == 2 is record
 * mode == 3 is play
 * mode == 4 is loopMode
 * Every time the user presses the button, the program will go to the next mode,
 * once it reaches 4, it should go back to mode == 0. 
 * (i.e. if mode ==2 and we press, then mode ==3) ...
**************************************************************************/
void chooseMode(){
  // IMPLEMENT

  //digitalRead() will read if the mode button is being pressed and will give that value to buttonState variable
  int buttonState = digitalRead(BUTTON_MODE_PIN);

  //check mode (just for reference)
  Serial.println(mode);

  //if statement checking if the BUTTON_MODE_PIN (mode button) is being pressed
  if(buttonState == HIGH){

    //if mode button is pressed, we enter the if statement and check which mode we are in
    
    //nested if statement that checks which mode and then changes the mode value for the next mode
    //if mode button is pressed & is equal to 0, change it to 1
    if(mode == 0){
      mode = 1;
    }
    
    //if mode button is pressed & is equal to 1, change it to 2
    else if(mode == 1){
      mode = 2;
    }
    
    //if mode button is pressed & is equal to 2, change it to 3
    else if(mode == 2){
      mode = 3;
    }
    
    //if mode button is pressed & is equal to 3, change it to 4
    else if(mode == 3){
      mode = 4;
    }
    
    //if mode button is pressed & is equal to 4, change it to 0
    else if(mode == 4){
      mode = 0;
    }

    //put a delay so that it gives the user time to press the button without it switching too fast
    delay(200);
  }
}

/******************SETRGB(): IMPLEMENT *********************************
 * INSTRUCTIONS:
 * Depending on the value of the mode variable:
 * if the mode is 0 - RGB LED IS OFF
 * if the mode is 1 - RGB LED IS BLUE
 * if mode is 2 - RGB LED IS RED
 * if mode is 3 - RGB LED IS GREEN
 * if mode is 4 - RGB LED iS PURPLE
 * YOU MUST USE A SWITCH CASE CONSTRUCT (NOT A SERIES OF IF / ELSE STATEMENTS
**************************************************************************/
void setRGB()
{
  
  //Using switch case, check which mode we are in and depending on the mode, set the RGB light to a particular color
  switch (mode){

    //digitalWrite will output the color to the LED light for each RGB color
    
    //If mode equals 0, set light to nothing (off)
    case 0:
    digitalWrite(LED_PIN_R, LOW);
    digitalWrite(LED_PIN_G, LOW);
    digitalWrite(LED_PIN_B, LOW);
   
    break;

    //If mode equals 1, set light to blue 
    case 1:
    digitalWrite(LED_PIN_R, LOW);
    digitalWrite(LED_PIN_G, LOW);
    digitalWrite(LED_PIN_B, HIGH);
    break;

    //If mode equals 2, set light to red 
    case 2:
    digitalWrite(LED_PIN_R, HIGH);
    digitalWrite(LED_PIN_G, LOW);
    digitalWrite(LED_PIN_B, LOW);
   
    break;

    //If mode equals 3, set light to green 
    case 3:
    digitalWrite(LED_PIN_R, LOW);
    digitalWrite(LED_PIN_G, HIGH);
    digitalWrite(LED_PIN_B, LOW);
    
    break;

    //If mode equals 4, set light to purple 
    case 4:
    //use analogWrite instead of digitalWrite to value in numbers and not only with HIGH or LOW
    analogWrite(LED_PIN_R, 50);
    digitalWrite(LED_PIN_G, LOW);
    analogWrite(LED_PIN_B, HIGH);
   
    break;
  }
}
/**********************SELECTMODE() DO NOT CHANGE *******************************
 * INSTRUCTIONS: 
 * There is NO NEED to change this function - it selects WHICH function should run based on the mode variable
 * There are 4 possibilities
 * 1: reset(): this function will reset any arrays etc, and will do nothing else
 * 2: live(): this function will play the corresponding notes 
 * to the user pressing the respective buttons. 
 * NOTE:: the notes played are NOT stored
 * 3: record(): this function will play the corresponding notes 
 * to the user pressing the respective buttons
 * AND will STORE up to 16 consecutive notes in an array.
 * 4: play(): this function will playback any notes stored in the array that were recorded
 * in the previous mode
 * 5: loopMode(): this function will playback any notes stored in the array that were recorded, 
 * BUT unlike the previous mode, you can choose in which sequence the notes are played.
 * REQUIRED: only play notes from the array (no live stuff)

******************************************************************************/
void selectMode()
{
  if(mode ==0) { 
    reset();
  }
  else if(mode ==1) {
    live();
  }
  else if(mode ==2) {
    record();
  }
  
  else if(mode ==3) {
    play();
  }
   
   else if(mode ==4) {
    loopMode();
  }
}
/******************RESET(): IMPLEMENT **************************************
 * INSTRUCTIONS:
 * this function should ensure that any notes recorded are no longer available
**************************************************************************/
void reset()
{
  // IMPLEMENT
  //Set countNotes back to zero as it is associated with MAX_NOTES
  countNotes = 0;
  
  //(optional) Empty the whole array using a for loop going through each element of the array and setting it to 0
  for( int i = 0; i < sizeof(notes)/sizeof(int);  ++i ){
   notes[i] = 0;
   }
  
}
/******************LIVE(): IMPLEMENT **************************************
 * INSTRUCTIONS:
 * this function will play the corresponding notes 
 * to the user pressing the respective buttons
 * NOTE:: the notes played are NOT stored
 * SO: you need read in the input from the analog input (linked to the button-resistor ladder combo)
 * THEN - output the note to the buzzer using the tone() function
**************************************************************************/
void live()
{
    //IMPLEMENT

    //create int variable called buzzValue that will store the button input the user has played.
    int buzzValue;

    //read note input from user and store into buzzValue
    buzzValue = analogRead(NOTE_IN_PIN);

    //check buzzValue in serial monitor (just for reference)
    Serial.println(buzzValue);

    //output sound using tone() function with the BUZZER_PIN constant (buzzer) and the frequency (buzzValue)
    tone(BUZZER_PIN, buzzValue, duration);
}
/******************RECORD(): IMPLEMENT **********************************
 * INSTRUCTIONS:
 * this function will play the corresponding notes 
 * to the user pressing the respective buttons
 * AND will STORE up to 16 consecutive notes in an array.
 * SO:you need read in the input from the analog input (linked to the button-resistor ladder combo)
 * AND - output the note to the buzzer using the tone() function
 * THEN store that note in the array  - BE CAREFUL - you can only allow for up to MAX_NOTES to be stored
**************************************************************************/
void record()
{
  // IMPLEMENT
  //create int variable called buzzValue that will store the button input the user has played.
   int buzzValue;
   
   //read note input from user and store into buzzValue
  buzzValue = analogRead(NOTE_IN_PIN);

  //If statement that checks if we have reached less than or equal to 16 stored notes, and the checks 
  //that the note input's frequency is greater or equal to the last push button's frequency on the breadboard (to make sure it outputs sound)
  if (countNotes < MAX_NOTES && buzzValue >= 111 ){ 
    
    //print statement just for reference 
    Serial.println(buzzValue);

    //Once we enter the if statement, store each note input to an element in the notes array
    notes[countNotes] = buzzValue;

    //increment the countNotes variable to make sure we will never surpass 16 notes
    countNotes++;
    
    //output sound using tone() function with the BUZZER_PIN constant (buzzer) and the frequency (buzzValue) 
    tone(BUZZER_PIN, buzzValue, duration);

    //put a delay to let sound be heard for a good amount of time
    delay(duration);
  }
}
/******************PLAY(): IMPLEMENT ************************************
 * INSTRUCTIONS:
 * this function will playback any notes stored in the array that were recorded
 * in the previous mode
 * SO: you need to go through the array of values (be careful - the user may not have put in MAX_NOTES)
 * READ each value IN ORDER
 * AND output each note to the buzzer using the tone() function
 * ALSO: as long as we are in this mode, the notes are played over and over again
 * BE CAREFUL: make sure you allow for the user to get to another mode from the mode button...
**************************************************************************/
void play()
{
  // IMPLEMENT

  //create a boolean variable for the while loop
  boolean  playTune = true;

  //Create a while loop that won't stop unless the boolean variable playTune is false (used to always repeat tune
  //recorded in previous mode)
  while (playTune){

    //for loop to go through each element (non-empty) in the array
    for(int i = 0; i <= countNotes; i++){

      //for each element on the array, output that note using tone() function
      tone(BUZZER_PIN, notes[i], duration);
      
      //use a delay to let sound flow and not go too fast
      delay(duration);
      
      //if statement that will stop the for loop once the user presses the mode button to go to next mode
       if (digitalRead(BUTTON_MODE_PIN) == HIGH){
        
        //set playTune boolean to false to get out of while loop (to go to next mode)
       playTune = false;
       
       //break to get out of for loop
       break;
       }
    }
    
  }
  
}
/******************LOOPMODE(): IMPLEMENT *********************************
 * INSTRUCTIONS:
 * this function will playback any notes stored in the array that were recorded
 * in the previous mode
 * SO: you need to go through the array of values (be careful - the user may not have put in MAX_NOTES)
 * READ values IN ANY ORDERING (You MUST use the array - but you can determine your own sequence)
 * AND output each note to the buzzer using the tone() function
 * ALSO: as long as we are in this mode, the notes are played over and over again
 * BE CAREFUL: make sure you allow for the user to get to another mode from the mode button...
**************************************************************************/
void loopMode()
{
  //IMPLEMENT

  //create a boolean variable for the while loop
   boolean  playTune = true;

   //Create a while loop that won't stop unless the boolean variable playTune is false (used to always repeat tune
  //recorded in previous mode)
   while (playTune){

    //for loop to go through each element (non-empty) in the array
    for(int i = 0; i <= countNotes; i++){

      //for each element on the array, output that note using tone() function and use the random() function to select a random element 
      //between 0 and i, this way the elements in the notes array will be outputted randomly!
      tone(BUZZER_PIN, notes[random(0,i)], duration);

      //use a delay to let sound flow and not go too fast
      delay(duration);

      //if statement that will stop the for loop once the user presses the mode button to go to next mode
       if (digitalRead(BUTTON_MODE_PIN) == HIGH){

       //set playTune boolean to false to get out of while loop (to go to next mode)
       playTune = false;

       //break to get out of for loop
       break;
       }
    }
  }
}

/**************************************************************************/





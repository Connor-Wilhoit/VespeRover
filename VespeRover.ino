/*   Possible future-use libraries   */
/*   TODO: 
 *    2) Implement the Calculus calculations for getting Vesper's
 *       position in space, as well as where she's been, and where
 *       she wants to go.
 *    
 *    4) Create a Neural Network, and via machine learning (possibly 
 *       using a recurrent neural network) train the rover (Vesper) to
 *       go to positions in space (traverse the house) that she hasn't
 *       been to (unvisited), NOT re-visit positions already visited,
 *       AND to not run into things (walls, objects, etc..)
 */

static const int state0 = 0;
static const int state1 = 1;
static const int state2 = 2;
static const int state3 = 3;
 
long max_distance = 30.00;
long min_distance = 10.00; 

/*   Ultrasonic Distance       */
/*   Front Device         */
const int trig1 = 26;
const int echo1 = 28;

/*   Rear Device     */
const int trig2 = 35;
const int echo2 = 33;

/*   Built-in LED              */
const int led = 13;

/*   Directional Control Pins  */
const int dir_ch1 = 22;
const int dir_ch2 = 23;
const int dir_ch3 = 24;
const int dir_ch4 = 25;

/*   Speed Control Pins (PWM)  */
const int speed_ch1 = 2;
const int speed_ch2 = 3;
const int speed_ch3 = 4;
const int speed_ch4 = 5;

/*   Current/Encoder Pins      */
const int cur_ch1 = A2;
const int cur_ch2 = A3;
const int cur_ch3 = A4;
const int cur_ch4 = A5;


void setup()
{
    delay(250);
    Serial.begin(115200);

    // Ultrasonic
    pinMode(trig1, OUTPUT);
    pinMode(trig2, OUTPUT);
    pinMode(echo1, INPUT);
    pinMode(echo2, INPUT);
    delay(250);

    // LED
    pinMode(led, OUTPUT);

    // Directional
    pinMode(dir_ch1, OUTPUT);
    pinMode(dir_ch2, OUTPUT);
    pinMode(dir_ch3, OUTPUT);
    pinMode(dir_ch4, OUTPUT);
    delay(250);

    // Speed
    pinMode(speed_ch1, OUTPUT);
    pinMode(speed_ch2, OUTPUT);
    pinMode(speed_ch3, OUTPUT);
    pinMode(speed_ch4, OUTPUT);
    delay(250);

    pinMode(cur_ch1, INPUT);
    pinMode(cur_ch2, INPUT);
    pinMode(cur_ch3, INPUT);
    pinMode(cur_ch4, INPUT);
    delay(250);
}

void loop()
{
    long front_distance = measure_distance(trig1, echo1);
    long rear_distance  = measure_distance(trig2, echo2);
    int current_state   = state0;
    delayMicroseconds(15);

    while (current_state == state0)
    {
        Serial.println("Onward! - state0");
        inf_forward();
        front_distance = measure_distance(trig1, echo1);
        rear_distance  = measure_distance(trig2, echo2);
        if ( (front_distance < max_distance) || (rear_distance < max_distance) )
        {
            current_state = state1;
            Serial.println("Errr! - state1");
            stop_rover();
        }
    }
    Serial.println("To the right to the right!");
    rotate_right(1500);
    current_state = state2;

    while (current_state == state2)
    {
        Serial.println("Reverse-Reverse! - state2");
        inf_reverse();
        front_distance = measure_distance(trig1, echo1);
        rear_distance  = measure_distance(trig2, echo2);
        if ( (front_distance < max_distance) || (rear_distance < max_distance) )
        {
            current_state = state3;
            stop_rover();
        }
    }
    Serial.println("To the left to the left, everything you own in a box to the left! - state3");
    rotate_left(1500);
    current_state = state0;

    delayMicroseconds(15);
    Serial.println("That's all folks!");
    delayMicroseconds(15);
}

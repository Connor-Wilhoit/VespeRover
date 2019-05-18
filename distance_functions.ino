/*   Functions for the Ultrasonic Distance Sensors   */

/*   Conversion Functions                            */
long micros_to_inches(long microseconds)
{
  return microseconds / 74 / 2;
}

long micros_to_centimeters(long microseconds)
{
  return microseconds / 29 /2;
}


/*   Measurement/Data Gathering Functions            */
void output_distance(int trigger_pin, int echo_pin)
{
  digitalWrite(trigger_pin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigger_pin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigger_pin, LOW);
  long duration = pulseIn(echo_pin, HIGH);	// microseconds
  Serial.print("Ultrasonic 'duration':\t ");
  Serial.print(duration);
  Serial.print("us");
  long distance = (duration/2) / 29.1;		// converted to centimeters
  Serial.print(" \t ");
  Serial.print("Ultrasonic 'distance': \t ");
  Serial.print(distance);
  Serial.println("cm\n\n");
}

long measure_distance(int trigger_pin, int echo_pin)
{
  digitalWrite(trigger_pin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigger_pin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigger_pin, LOW);
  long duration = pulseIn(echo_pin, HIGH);	// microseconds
  long distance = (duration/2) / 29.1;
  return distance;
}

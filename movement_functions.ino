/*  Shouts out to Saloka - going to tryout his usage of `states` for the program.  */

/*   Start of Foundational Movement Functions   */
void stop_rover()
{
    analogWrite(speed_ch1, 0);
    analogWrite(speed_ch2, 0);
    analogWrite(speed_ch3, 0);
    analogWrite(speed_ch4, 0);
}

void go_rover_go()
{
    analogWrite(speed_ch1, 200);
    analogWrite(speed_ch2, 200);
    analogWrite(speed_ch3, 200);
    analogWrite(speed_ch4, 200);
}

/*  Duration-Forward Function  */
void forward(int duration)
{
    unsigned long movement_time = millis() + duration;
    /*  Directional Control  */
    digitalWrite(dir_ch1, HIGH);
    digitalWrite(dir_ch2, HIGH);
    digitalWrite(dir_ch3, LOW);
    digitalWrite(dir_ch4, LOW);

    /*  Velocity Control  */
    while (movement_time >= millis())
        go_rover_go();

    stop_rover();
}

/*  Duration-Reversing Function  */
void reverse(int duration)
{
    unsigned long movement_time = millis() + duration;
    /*  Directional Control  */
    digitalWrite(dir_ch1, LOW);
    digitalWrite(dir_ch2, LOW);
    digitalWrite(dir_ch3, HIGH);
    digitalWrite(dir_ch4, HIGH);

    /*  Velocity Control  */
    while (movement_time >= millis())
        go_rover_go();

    stop_rover();
}

void inf_forward()
{
    /*  Directional Control  */
    digitalWrite(dir_ch1, HIGH);
    digitalWrite(dir_ch2, HIGH);
    digitalWrite(dir_ch3, LOW);
    digitalWrite(dir_ch4, LOW);
    go_rover_go();
}

void inf_reverse()
{
    /*  Directional Control  */
    digitalWrite(dir_ch1, LOW);
    digitalWrite(dir_ch2, LOW);
    digitalWrite(dir_ch3, HIGH);
    digitalWrite(dir_ch4, HIGH);
    go_rover_go();
}

void inf_rotate_left()
{
    /*  Directional Control  */
    digitalWrite(dir_ch1, HIGH);
    digitalWrite(dir_ch2, LOW);
    digitalWrite(dir_ch3, LOW);
    digitalWrite(dir_ch4, HIGH);

    /*  Velocity Control  */
    go_rover_go();
}

void inf_rotate_right()
{
    /*  Directional Control  */
    digitalWrite(dir_ch1, LOW);
    digitalWrite(dir_ch2, HIGH);
    digitalWrite(dir_ch3, HIGH);
    digitalWrite(dir_ch4, LOW);

    /*  Velocity Control  */
    go_rover_go();
}


/*  Duration-Left-Rotation Function  */
void rotate_left(int duration)
{
    unsigned long movement_time = millis() + duration;
    digitalWrite(dir_ch1, HIGH);
    digitalWrite(dir_ch2, LOW);
    digitalWrite(dir_ch3, LOW);
    digitalWrite(dir_ch4, HIGH);

    while (movement_time >= millis())
        go_rover_go();

    stop_rover();
}

/*  Duration-Right-Rotation Function  */
void rotate_right(int duration)
{
    unsigned long movement_time = millis() + duration;
    digitalWrite(dir_ch1, LOW);
    digitalWrite(dir_ch2, HIGH);
    digitalWrite(dir_ch3, HIGH);
    digitalWrite(dir_ch4, LOW);

    while (movement_time >= millis())
        go_rover_go();

    stop_rover();
}

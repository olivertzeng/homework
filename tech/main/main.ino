/***************************************************
 HUSKYLENS An Easy-to-use AI Machine Vision Sensor
 <https://www.dfrobot.com/product-1922.html>

 ***************************************************
 This example shows how to play with line tracking.

 Created 2020-03-13
 By [Angelo qiao](Angelo.qiao@dfrobot.com)

 GNU Lesser General Public License.
 See <http://www.gnu.org/licenses/> for details.
 All above must be included in any redistribution
 ****************************************************/

/***********Notice and Trouble shooting***************
 1.Connection and Diagram can be found here
 <https://wiki.dfrobot.com/HUSKYLENS_V1.0_SKU_SEN0305_SEN0336#target_23>
 2.This code is tested on Arduino Uno, Leonardo, Mega boards.
 ****************************************************/

#include "DFMobile.h"
#include "HUSKYLENS.h"
// #include "NewPing.h"
#include "PIDLoop.h"
// #include "Servo.h"
#include "SoftwareSerial.h"

#define ZUMO_FAST 255 // speed
// int trigPin = 13;	  // TRIG pin
// int echoPin = 12;	  // ECHO pin
// float duration_us, distance_cm;
DFMobile Robot(6, 7, 4, 5); // initiate the Motor pin
PIDLoop headingLoop(2000, 0, 0, false);
// NewPing sonar(512, 13); // sonar pin
// Servo seperator;
HUSKYLENS huskylens;
// HUSKYLENS green line >> SDA; blue line >> SCL
int ID1 = 1;
void printResult(HUSKYLENSResult result);

void setup() {
	Serial.begin(115200);
	Robot.Direction(LOW, HIGH); // initiate the positive direction
								// configure the trigger pin to output mode
	// pinMode(trigPin, OUTPUT);
	// // configure the echo pin to input mode
	// pinMode(echoPin, INPUT);
	// seperator.attach(9); // Servo pin
	// seperator.write(0);
	Wire.begin();
	while (!huskylens.begin(Wire)) {
		Serial.println(F("Begin failed!"));
		Serial.println(F("1.Please recheck the \"Protocol Type\" in HUSKYLENS "
						 "(General Settings>>Protol Type>>I2C)"));
		Serial.println(F("2.Please recheck the connection."));
		delay(100);
	}
	huskylens.writeAlgorithm(
		ALGORITHM_LINE_TRACKING); // Switch the algorithm to line tracking.
}
int left = 0, right = 0;

void loop() {
	int32_t error;
	HUSKYLENSResult result = huskylens.read();
	printResult(result);
	if (!huskylens.request(ID1)) {
		Serial.println(
			F("Fail to request data from HUSKYLENS, recheck the connection!"));
		left = 0;
		right = 0;
	} else if (!huskylens.isLearned()) {
		Serial.println(F(
			"Nothing learned, press learn button on HUSKYLENS to learn one!"));
		left = 0;
		right = 0;
	} else if (!huskylens.available())
		Serial.println(F("No block or arrow appears on the screen!"));
	else {
		HUSKYLENSResult result = huskylens.read();
		printResult(result);

		// Calculate the error:
		error = (int32_t)result.xTarget - (int32_t)160;

		// Perform PID algorithm.
		headingLoop.update(error);

		// separate heading into left and right wheel velocities.
		left = headingLoop.m_command;
		right = -headingLoop.m_command;

		left += ZUMO_FAST;
		right += ZUMO_FAST;
	}
	// generate 10-microsecond pulse to TRIG pin
	// digitalWrite(trigPin, HIGH);
	// delayMicroseconds(10);
	// digitalWrite(trigPin, LOW);
	// calculate the distance
	// distance_cm = 0.017 * pulseIn(echoPin, HIGH);
	// if (distance_cm < long(2)) {
	// 	Serial.println("Sonar Detected");
	// 	seperator.write(90);
	// 	delay(1000);
	// 	seperator.write(0);
	// }
	Serial.println(String() + left + "," + right);
	Robot.Speed(left, right);
}

void printResult(HUSKYLENSResult result) {
	if (result.command == COMMAND_RETURN_BLOCK) {
		Serial.println(String() + F("Block:xCenter=") + result.xCenter +
					   F(",yCenter=") + result.yCenter + F(",width=") +
					   result.width + F(",height=") + result.height +
					   F(",ID=") + result.ID);
	} else if (result.command == COMMAND_RETURN_ARROW) {
		Serial.println(String() + F("Arrow:xOrigin=") + result.xOrigin +
					   F(",yOrigin=") + result.yOrigin + F(",xTarget=") +
					   result.xTarget + F(",yTarget=") + result.yTarget +
					   F(",ID=") + result.ID);
	} else {
		Serial.println("Object unknown!");
	}
}

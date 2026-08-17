const int metalSensor = 2;

const int trigPin = 10;
const int echoPin = 11;

const int ledPin = 9;
const int buzzerPin = 8;

long duration;
float distance;

void setup() {

  pinMode(metalSensor, INPUT);

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  pinMode(ledPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);

  Serial.begin(9600);

  Serial.println("بدأ النظام");
}

void loop() {

  
  int metalDetected = digitalRead(metalSensor);

 
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);

  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH, 30000);

  distance = duration * 0.034 / 2;

  if (metalDetected == LOW) {

    digitalWrite(ledPin, HIGH);
    digitalWrite(buzzerPin, HIGH);

    Serial.println("تم كشف معدن");

    
    if (duration == 0) {

      Serial.println("تعذر قياس المسافة");

    }
    else {

      Serial.print("المسافة عن المعدن: ");
      Serial.print(distance);
      Serial.println(" cm");

    }

  }

  
  else {

    digitalWrite(ledPin, LOW);
    digitalWrite(buzzerPin, LOW);

    Serial.println("لا يوجد معدن");
  }

  Serial.println("----------------------");

  delay(500);
}
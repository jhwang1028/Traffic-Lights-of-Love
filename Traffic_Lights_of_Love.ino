// LED 핀 번호 설정
const int redLED = 11;
const int greenLED = 10;
const int yellowLED = 9;

void setup() {
  // 핀 모드를 출력으로 설정
  pinMode(redLED, OUTPUT);
  pinMode(greenLED, OUTPUT);
  pinMode(yellowLED, OUTPUT);
  
  // 시리얼 통신 시작 (9600bps)
  Serial.begin(9600);
}

void loop() {

  if (Serial.available() > 0) {  // 시리얼 포트로 데이터가 들어오면
    char received = Serial.read(); // 데이터 읽기
    // 빨간색 LED 제어
    if (received == 'R') {
      digitalWrite(greenLED, LOW);
      digitalWrite(yellowLED, LOW);
      digitalWrite(redLED, HIGH);
    }

    // 녹색 LED 제어
    else if (received == 'G') {
      digitalWrite(redLED, LOW);
      digitalWrite(yellowLED, LOW);
      digitalWrite(greenLED, HIGH);
    }

    // 노란색 LED 제어
    else if (received == 'Y') {
      digitalWrite(greenLED, LOW);
      digitalWrite(redLED, LOW);
      digitalWrite(yellowLED, HIGH);
    }
  }
}

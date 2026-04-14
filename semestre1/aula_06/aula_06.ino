// 16MHz
// LINGUAGEM WIRING -------> C++ ADAPTADO PARA MICROCONTROLADOR  

// Diretiva.    Direticvas não precisam de ;
#define LED_1 12 // pino do LED
#define LED_2 9
#define LED_3 4
// Opções 
//int LED_1 = 12;
//const int LED_1 = 12;

void setup() {
  
  Serial.begin(9600); //Baude rate (9600 bist/s)
  //Configuração do pino como saída (OUTPUT)
  //pinMode(12, OUTPUT);    Melhor deixar o pinMode como está abaixo para quando tiver mais LEDs não ficar procurando a porta o tempo todo. 
  pinMode(LED_1, OUTPUT);
  pinMode(LED_2, OUTPUT);
  pinMode(LED_3, OUTPUT);
  
  Serial.println("1CCPH: Inicializacao conclida");
  Serial.println("-----------------------------");
  delay(2000);
}

void loop() {
  seq1();
  delay(1000);
  Serial.println("Sequencia 1 finalizada");
  Serial.println("----------------------");

  seq2();
  delay(1000);
  Serial.println("Sequencia 2 finalizada");
  Serial.println("----------------------");
}


void seq2() {
  // Ciclo de instrução -----> tempo entre instruções sem delay
  // 16MHz -----> T = 1 / 10.000.000 -----> t = 0.000000065s 
  digitalWrite(LED_1, HIHG);
  delay(500); // Delay em ms, 500ms = .05s
  digitalWrite(LED_2, HIGH);
  digitalWrite(LED_1, LOW);
  delay(500);
  digitalWrite(LED_3, HIGH);
  digitalWrite(LED_2, LOW);
  delay(500);
}

void seq1() {
  delay(1000);
  digitalWrite(LED_1, HIHG);
  delay(1000);
  digitalWrite(LED_2, HIGH);
  delay(1000);
  digitalWrite(LED_3, HIGH);
  delay(1000);
  ledsOFF();
  delay(100);
}

void ledsOFF(){
  digitalWrite(LED_1, LOW);
  digitalWrite(LED_2, LOW);
  digitalWrire(LED_3, LOW);
}

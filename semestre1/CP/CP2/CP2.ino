#define LED_GREEN 6
#define LED_YELLOW 4
#define LED_RED 2

int V1;
int V2;
float tensao_36V1;
float tensao_36V2;
int A = 8;
float P1;
float P2;
int estado = 0; 

void setup(){
  Serial.begin(9600);
  pinMode(LED_GREEN, OUTPUT);
  pinMode(LED_YELLOW, OUTPUT);
  pinMode(LED_RED, OUTPUT);
  Serial.println("MEDIDOR DE TENSAO");
  Serial.print("");
}

// Mapeie os pinos a partir da analise do diagrama no Tinkercad
// Declare aqui suas constantes de pinos e quaisquer variaveis globais

void loop() {
  //ex1();
  //ex2();
  //ex3();
  ex4();
  // ex5();
}

void ex1() {
  print_medidor();
  if (tensao_36V1 > tensao_36V2){
    digitalWrite(LED_GREEN, LOW);
    digitalWrite(LED_YELLOW, HIGH);
  }
  else if (tensao_36V1 < tensao_36V2){
    digitalWrite(LED_YELLOW, LOW);
    digitalWrite(LED_GREEN, HIGH);
  }
  else{
    digitalWrite(LED_YELLOW, HIGH);
    digitalWrite(LED_GREEN, HIGH);
    }
}

void ex2() {
  medidor();
  if(tensao_36V1 < 10){
    Serial.print("FALHA S1: ");
    Serial.println(tensao_36V1);
    digitalWrite(LED_GREEN, LOW);
    digitalWrite(LED_YELLOW, LOW);
    digitalWrite(LED_RED, HIGH);
  }
  else if(tensao_36V2 < 10){
    Serial.print("FALHA S2: ");
    Serial.println(tensao_36V2);
    digitalWrite(LED_GREEN, LOW);
    digitalWrite(LED_YELLOW, LOW);
    digitalWrite(LED_RED, HIGH);
  }
  else if (tensao_36V1 < 20){
    Serial.print("ATENCAO S1: ");
    Serial.println(tensao_36V1);
    digitalWrite(LED_GREEN, LOW);
    digitalWrite(LED_YELLOW, HIGH);
  }
  else if(tensao_36V2 < 20){
    Serial.print("ATENCAO S2: ");
    Serial.println(tensao_36V2);
    digitalWrite(LED_GREEN, LOW);
    digitalWrite(LED_YELLOW, HIGH);
  }
  else{
    Serial.println("Sistema OK ");
    digitalWrite(LED_YELLOW, LOW);
    digitalWrite(LED_RED, LOW);
    digitalWrite(LED_GREEN, HIGH);
  }
}

void ex3() {
  medidor();
  P1 = tensao_36V1 * A;
  P2 = tensao_36V2 * A;
  float menor = min(P1, P2);
  float maior = max(P1, P2);
  float ef = (menor/maior)*100;
  Serial.print("POTENCIA 1: ");
  Serial.print(P1);
  Serial.println("W");
  Serial.print("POTENCIA 2: ");
  Serial.print(P2);
  Serial.println("W");
  if (ef > 70 && ef <90){
    digitalWrite(LED_RED, LOW);
    digitalWrite(LED_GREEN, LOW);
    digitalWrite(LED_YELLOW, HIGH);
    Serial.println("ATENCAO! EFICIENCIA ABAIXO DO ESPERADO");
  }
  else if(ef <= 70){
    digitalWrite(LED_YELLOW, LOW);
    digitalWrite(LED_GREEN, LOW);
    digitalWrite(LED_RED, HIGH);
    Serial.println("DESBALANCEAMENTO CRITICO");
  }
  else{
    digitalWrite(LED_YELLOW, LOW);
    digitalWrite(LED_RED, LOW);
    digitalWrite(LED_GREEN, HIGH);
    Serial.println("SISTEMA OK");
  }
  Serial.println(ef);
  delay(1000);
}

void ex4() {
  medidor();
  if (tensao_36V1 < 15 || tensao_36V2 < 15){
      if (tensao_36V1 < tensao_36V2){
        Serial.println("S1: CRITICO | S2: NORMAL");
        Serial.print("S1: Normal -> Critico ");
        Serial.print("(");
        Serial.print(tensao_36V1);
        Serial.print("V");  
        Serial.println(")");
      }
      else if(tensao_36V1 > tensao_36V2){
        Serial.println("S1: NORMAL | S2: CRITICO");
        Serial.print("S2: Normal -> Critico ");
        Serial.print("(");
        Serial.print(tensao_36V2);
        Serial.print("V");  
        Serial.println(")");
      }
      digitalWrite(LED_GREEN, LOW);
      digitalWrite(LED_YELLOW, LOW);
      digitalWrite(LED_RED, HIGH);
  }
  else if ((tensao_36V1 >= 15 && tensao_36V1 <25) || (tensao_36V2 >= 15 && tensao_36V2 < 25)){
    if(tensao_36V1 < tensao_36V2){
      Serial.println("S1: ALERTA | S2: NORMAL");
      Serial.print("S1: Normal -> Alerta ");
      Serial.print("(");
      Serial.print(tensao_36V1);
      Serial.print("V");  
      Serial.println(")");
    }
    else if(tensao_36V1 > tensao_36V2){
      Serial.println("S1: NORMAL | S2: ALERTA");
      Serial.print("S2: Normal -> Alerta ");
      Serial.print("(");
      Serial.print(tensao_36V2);
      Serial.print("V");  
      Serial.println(")");
    }
    digitalWrite(LED_GREEN, LOW);
    digitalWrite(LED_RED, LOW);
    digitalWrite(LED_YELLOW, HIGH);
  }

  
  else{
    Serial.println("S1: NORMAL | S2: NORMAL");
    digitalWrite(LED_YELLOW, LOW);
    digitalWrite(LED_RED, LOW);
    digitalWrite(LED_GREEN, HIGH);
  }
  
}

void ex5() {
  medidor();
  int estado_anterior = estado;
  float Vm = (tensao_36V1 + tensao_36V2)/2;
  if (estado_anterior == 0){
    if(Vm < 22) estado = 0;
    else if (Vm < 30) estado = 1;
    else estado = 2;
  }
  else {
    if (Vm < 20) estado = 0;
    else if (Vm >= 20 && Vm < 30) estado = 1;
    else estado = 2; 
  }
  switch(estado){
    case 0:
    Serial.print("Carga: OFF | ");
    Serial.print(Vm);
    Serial.println("V");
    digitalWrite(LED_GREEN, LOW);
    digitalWrite(LED_YELLOW, LOW);
    digitalWrite(LED_RED, HIGH);
    break;

    case 1:
    Serial.print("Standby | ");
    Serial.print(Vm);
    Serial.println("V");
    digitalWrite(LED_RED, LOW);
    digitalWrite(LED_GREEN, LOW);
    digitalWrite(LED_YELLOW, HIGH);
    break;

    case 2:
    Serial.print("Carga: ON | ");
    Serial.print(Vm);
    Serial.println("V");
    digitalWrite(LED_RED, LOW);
    digitalWrite(LED_YELLOW, LOW);
    digitalWrite(LED_GREEN, HIGH);
    break;
  } 
  if (estado != estado_anterior){
    if (estado_anterior == 0 && estado == 1){
      Serial.print("Transicao: OFF -> Standby | ");
      Serial.print(Vm);
      Serial.println("V");
    }
    else if (estado_anterior == 0 && estado == 2){
      Serial.print("Transicao: OFF -> ON | ");
      Serial.print(Vm);
      Serial.println("V");
    }
    else if (estado_anterior == 1 && estado == 0){
      Serial.print("Transicao: Standby -> OFF | ");
      Serial.print(Vm);
      Serial.println("V");
    }
    else if (estado_anterior == 1 && estado == 2){
      Serial.print("Transicao: Standby -> ON | ");
      Serial.print(Vm);
      Serial.println("V");
    }
    else if (estado_anterior == 2 && estado == 1){
      Serial.print("Transicao: ON -> Standby | ");
      Serial.print(Vm);
      Serial.println("V");
    }
    else {
      Serial.print("Transicao: ON -> OFF | ");
      Serial.print(Vm);
      Serial.println("V");
    }
  }
}

void medidor(){
  V1 = analogRead(A2);
  V2 = analogRead(A3);
  tensao_36V1 = map(V1, 0, 1022, 0, 3600)/100.0;
  tensao_36V2 = map(V2, 0, 1022, 0, 3600)/100.0;
  delay(1000);

}

void print_medidor(){
  medidor();
  Serial.print("S1: ");
  Serial.print(tensao_36V1);
  Serial.println("V");
  Serial.print("S2: ");
  Serial.print(tensao_36V2);
  Serial.println("V");
}






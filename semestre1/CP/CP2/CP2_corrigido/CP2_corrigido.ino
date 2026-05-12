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

  /*void ex2() { //Original do CP
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
  }*/

  void ex2(){ //Corrigido 
    if(tensao_36V1 < 10 || tensao_36V2 < 10){
      if (tensao_36V1 < 10) {
      Serial.print("FALHA S1: ");
      Serial.println(tensao_36V1);
    }
    if (tensao_36V2 < 10) {
      Serial.print("FALHA S2: ");
      Serial.println(tensao_36V2);
    }
    digitalWrite(LED_GREEN, LOW);
    digitalWrite(LED_YELLOW, LOW);
    digitalWrite(LED_RED, HIGH);
  }
  else if (tensao_36V1 < 20 || tensao_36V2 < 20) {
    if (tensao_36V1 < 20) {
      Serial.print("ATENCAO S1: ");
      Serial.println(tensao_36V1);
    }
    if (tensao_36V2 < 20) {
      Serial.print("ATENCAO S2: ");
      Serial.println(tensao_36V2);
    }
    digitalWrite(LED_RED, LOW);
    digitalWrite(LED_GREEN, LOW);
    digitalWrite(LED_YELLOW, HIGH);
  }
  else {
    Serial.println("Sistema OK");
    digitalWrite(LED_YELLOW, LOW);
    digitalWrite(LED_RED, LOW);
    digitalWrite(LED_GREEN, HIGH);
    }
  }
  

  /*void ex3() {
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
  }*/

  void ex3(){ //Corrigido 
    medidor();
    P1 = tensao_36V1 * A;
    P2 = tensao_36V2 * A;
    float menor = min(P1, P2);
    float maior = max(P1, P2);

    float ef = 0;
    if (maior > 0) {
       ef = (menor / maior) * 100;
    }

      Serial.print("P1: ");
      Serial.print(P1);
      Serial.println("W");

      Serial.print("P2: ");
      Serial.print(P2);
      Serial.println("W");

      Serial.print("Total: ");
      Serial.print(P1 + P2);
      Serial.println("W");

      Serial.print("Eficiencia: ");
      Serial.print(ef);
      Serial.println("%");

      if (ef >= 90) {
        digitalWrite(LED_YELLOW, LOW);
        digitalWrite(LED_RED, LOW);
        digitalWrite(LED_GREEN, HIGH);
        Serial.println("SISTEMA OK");
      }
      else if (ef > 70 && ef < 90) {
        digitalWrite(LED_RED, LOW);
        digitalWrite(LED_GREEN, LOW);
        digitalWrite(LED_YELLOW, HIGH);
        Serial.println("ATENCAO! EFICIENCIA ABAIXO DO ESPERADO");
      }
      else {
        digitalWrite(LED_YELLOW, LOW);
        digitalWrite(LED_GREEN, LOW);
        digitalWrite(LED_RED, HIGH);
        Serial.println("DESBALANCEAMENTO CRITICO");
      }

      delay(1000);
     }
  }

  /*void ex4() { //Original do CP
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
    
  }*/

  int estado_s1 = -1;
  int estado_s2 = -1;

  void ex4() { //Corrigido
    medidor();
    String nomes[] = {"Critico", "Alerta", "Normal"};
    int novo_s1 = (tensao_36V1 < 15) ? 0 : (tensao_36V1 < 25) ? 1 : 2;
    int novo_s2 = (tensao_36V2 < 15) ? 0 : (tensao_36V2 < 25) ? 1 : 2;

    if (novo_s1 != estado_s1 && estado_s1 != -1) {
      Serial.print("S1: "); Serial.print(nomes[estado_s1]);
      Serial.print(" -> "); Serial.print(nomes[novo_s1]);
      Serial.print(" ("); Serial.print(tensao_36V1); Serial.println("V)");
    }
    if (novo_s2 != estado_s2 && estado_s2 != -1) {
      Serial.print("S2: "); Serial.print(nomes[estado_s2]);
      Serial.print(" -> "); Serial.print(nomes[novo_s2]);
      Serial.print(" ("); Serial.print(tensao_36V2); Serial.println("V)");
    }

    String label_s1[] = {"CRITICO", "ALERTA", "NORMAL"};
    String label_s2[] = {"CRITICO", "ALERTA", "NORMAL"};
    Serial.print("S1: "); Serial.print(label_s1[novo_s1]);
    Serial.print(" | S2: "); Serial.println(label_s2[novo_s2]);

    int estado_grave = min(novo_s1, novo_s2);
    if (estado_grave == 0) {
      digitalWrite(LED_GREEN, LOW); digitalWrite(LED_YELLOW, LOW); digitalWrite(LED_RED, HIGH);
    } else if (estado_grave == 1) {
      digitalWrite(LED_GREEN, LOW); digitalWrite(LED_RED, LOW); digitalWrite(LED_YELLOW, HIGH);
    } else {
      digitalWrite(LED_YELLOW, LOW); digitalWrite(LED_RED, LOW); digitalWrite(LED_GREEN, HIGH);
    }

    estado_s1 = novo_s1;
    estado_s2 = novo_s2;
  }
    

  /*void ex5() { //Original do CP
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
  }*/

  int estado = -1; // era 0

  void ex5() {
    medidor();
    int estado_anterior = estado;
    float Vm = (tensao_36V1 + tensao_36V2) / 2;

    int novo_estado;
    if (estado_anterior == 0) {
      if (Vm < 22) novo_estado = 0;
      else if (Vm < 30) novo_estado = 1;
      else novo_estado = 2;
    } else {
      if (Vm < 20) novo_estado = 0;
      else if (Vm < 30) novo_estado = 1;
      else novo_estado = 2;
    }
    estado = (estado_anterior == -1) ? novo_estado : estado;
    // primeiro ciclo: só inicializa, não registra transição
    if (estado_anterior == -1) { estado = novo_estado; return; }
    estado = novo_estado;

    // transição ANTES do estado atual
    if (estado != estado_anterior) {
      String trans[] = {"OFF","Standby","ON"};
      Serial.print("Transicao: "); Serial.print(trans[estado_anterior]);
      Serial.print(" -> "); Serial.print(trans[estado]);
      Serial.print(" | "); Serial.print(Vm); Serial.println("V");
    }

    switch (estado) {
      case 0:
        Serial.print("Carga: OFF | "); Serial.print(Vm); Serial.println("V");
        digitalWrite(LED_GREEN, LOW); digitalWrite(LED_YELLOW, LOW); digitalWrite(LED_RED, HIGH);
        break;
      case 1:
        Serial.print("Standby | "); Serial.print(Vm); Serial.println("V");
        digitalWrite(LED_RED, LOW); digitalWrite(LED_GREEN, LOW); digitalWrite(LED_YELLOW, HIGH);
        break;
      case 2:
        Serial.print("Carga: ON | "); Serial.print(Vm); Serial.println("V");
        digitalWrite(LED_RED, LOW); digitalWrite(LED_YELLOW, LOW); digitalWrite(LED_GREEN, HIGH);
        break;
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

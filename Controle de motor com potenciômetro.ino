//Declaração de variáveis
volatile int cont = 0

int motor1pin1 = 18; //Define um dos pinos do motor para a porta GPIO18 do ESP
int motor1pin2 = 19; //Define um dos pinos do motor para a porta GPIO19 do ESP
int potPin = 35; //Define um dos pinos do motor para a porta GPIO35 do ESP
int valor_pot; //Variável para verificação do valor atual do potenciômetro
int vel_motor; //Variável para verificação da velocidade atual do motor

void setup() {
 
  pinMode(motor1pin1, OUTPUT); //Declara a variável como uma saída
  pinMode(motor1pin2, OUTPUT); //Declara a variável como uma saída
  pinMode(22, OUTPUT); // Declara o pino PWN que determina a velocidade de rotação

//A linha abaixo foi utilizada para testes com o ESP ainda conectado no PC
  Serial.begin(115200); //Inicia o monitor serial

}

void loop() {  
  
  valor_pot = analogRead(potPin); // Lê o valor do potenciômetro
  vel_motor = map(valor_pot, 0, 4095, 0, 255); // Mapeia o valor lido do potenciômetro de 0 a 4095 para uma velocidade de 0 a 255
  digitalWrite(motor1pin1, LOW); //Definição do sentido de rotação do motor
  digitalWrite(motor1pin2, HIGH); //Definição do sentido de rotação do motor
  analogWrite(22, vel_motor); //Manda o sinal PWM do motor 1 para a PonteH

  //A linha foi usada para testes com o ESP ainda conectado no PC
  Serial.println(vel_motor); //Mostra os valores de velocidade do motor no monitor serial
  
}

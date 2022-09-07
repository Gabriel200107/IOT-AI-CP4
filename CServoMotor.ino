/*   Código do Servo Motor Arduino que faz conexão direta com o arduino e com node-red que a partir de um dashboard criado por nós apertamos o botão 180 ele faz uma 
rotação no servo motor e apertamos o de 0 graus ele volta.
*/

Servo meuservo; 

const int TAMANHO = 200;
void setup() {
  Serial.begin(9600);
  meuservo.attach(9);
}
void loop() {
  if (Serial.available() > 0) {
    StaticJsonDocument<TAMANHO> json;
    deserializeJson(json, Serial);
    if(json.containsKey("grau")) {
      int valor = json["grau"];
      meuservo.write(valor); 
    }
  } 
  
}

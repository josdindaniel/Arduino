byte PIN_SENSOR = A0;
int dato_serial = 0; // para los datos de entrada serie
float miliVolts;
int temperatura;

void setup() {
Serial.begin(9600); // abre el puerto serie, establece la velocidad a 9600 bps
}
 
void loop() {
  
  // Calcula la temperatura en grados centigrados
  miliVolts = ((analogRead(PIN_SENSOR) * 5000L) / 1023) / 10;
  temperatura = miliVolts;

  // Imprime en pantalla
  /*
  Serial.print("Temperatura: ");
  Serial.print(temperatura);
  Serial.println(" grados centigrados");
  delay(2000);
  */
  // Esta funcion es para integrarlo con JAVA
  // envía datos solo cuando recibe datos:
  if (Serial.available() > 0) {   // si ha llegado un dato serial
    lectura_dato();               // realiza una operacion
    comparacion_dato();           // llama a la funcion de comparar el dato
  }
  
}
 
void lectura_dato (void){
  dato_serial = Serial.read();    // lee el byte de entrada:
}
 
void comparacion_dato (void){
  if (dato_serial == 'T') {       // si el dato serial es la T envía la temperatura a java
    Serial.write(temperatura);
  }
}

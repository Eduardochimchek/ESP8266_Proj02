// Defina os pinos dos LEDs RGB
#define RED_PIN D8
#define GREEN_PIN D9
#define BLUE_PIN D10

// Defina os pinos dos botões
#define BUTTON_UP D3
#define BUTTON_DOWN D4

// Defina o pino PWM
#define PWM_PIN D6

// Defina a intensidade inicial
int intensity = 0;

void setup() {
  // Inicialize os pinos como saídas
  pinMode(RED_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);
  pinMode(BLUE_PIN, OUTPUT);
  
  // Inicialize os pinos dos botões como entradas com resistência de pull-up interna
  pinMode(BUTTON_UP, INPUT_PULLUP);
  pinMode(BUTTON_DOWN, INPUT_PULLUP);
  
  // Inicialize o pino PWM
  analogWrite(PWM_PIN, intensity);
}

void loop() {
  // Verifique se o botão UP foi pressionado
  if (digitalRead(BUTTON_UP) == LOW) {
    if (intensity < 255) {
      intensity++;
      analogWrite(PWM_PIN, intensity);
      delay(100); // Delay para evitar múltiplas leituras
    }
  }
  
  // Verifique se o botão DOWN foi pressionado
  if (digitalRead(BUTTON_DOWN) == LOW) {
    if (intensity > 0) {
      intensity--;
      analogWrite(PWM_PIN, intensity);
      delay(100); // Delay para evitar múltiplas leituras
    }
  }
}

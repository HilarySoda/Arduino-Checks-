const byte RED_PIN   = 9;
const byte GREEN_PIN = 10;
const byte BLUE_PIN  = 11;

String comando = "";

void setup()
{
  Serial.begin(115200);

  pinMode(RED_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);
  pinMode(BLUE_PIN, OUTPUT);

  analogWrite(RED_PIN, 0);
  analogWrite(GREEN_PIN, 0);
  analogWrite(BLUE_PIN, 0);

  Serial.println("--------------------------------");
  Serial.println("CONTROL RGB");
  Serial.println("Ejemplos:");
  Serial.println("R255");
  Serial.println("G050");
  Serial.println("B120");
  Serial.println("--------------------------------");
}

void loop()
{
  while (Serial.available())
  {
    char c = Serial.read();

    if (c == '\n' || c == '\r')
    {
      if (comando.length() > 0)
      {
        procesarComando(comando);
        comando = "";
      }
    }
    else
    {
      comando += c;
    }
  }
}

void procesarComando(String texto)
{
  texto.trim();

  if (texto.length() < 2)
  {
    Serial.println("Comando invalido.");
    return;
  }

  char canal = toupper(texto.charAt(0));

  int valor = texto.substring(1).toInt();

  valor = constrain(valor, 0, 255);

  switch (canal)
  {
    case 'R':
      analogWrite(RED_PIN, valor);
      Serial.print("Rojo = ");
      Serial.println(valor);
      break;

    case 'G':
      analogWrite(GREEN_PIN, valor);
      Serial.print("Verde = ");
      Serial.println(valor);
      break;

    case 'B':
      analogWrite(BLUE_PIN, valor);
      Serial.print("Azul = ");
      Serial.println(valor);
      break;

    default:
      Serial.println("Canal invalido.");
      break;
  }
}

/**  
	**....0000..0000....**
	**...0CODIGO-POR0...**
	**...000HILARI000...**
	**....0Z.CHAVEZ0....**
	**......000000......**
	**........00........**
	**....IA.CHATGPT....**
**/

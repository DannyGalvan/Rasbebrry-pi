# Proyecto de Medición de Temperatura con NTC y LCD

Este proyecto utiliza un **termistor NTC** para medir la temperatura en un circuito conectado a un **Rasberry Pi** y mostrar el **voltaje** y la **temperatura** en un **display LCD**. El termistor NTC cambia su resistencia en función de la temperatura, y el Arduino lo lee a través de un pin analógico. El valor leído se convierte en una temperatura en grados Celsius y se muestra en el LCD.

## Componentes Necesarios

1. **Arduino (o compatible)**: Controlador principal.
2. **Termistor NTC**: Sensor para medir la temperatura.
3. **Pantalla LCD 16x2**: Para mostrar la temperatura y el voltaje.
4. **Resistencia de referencia**: Usada en conjunto con el termistor para formar un divisor de voltaje.
5. **Cables de conexión**: Para realizar las conexiones necesarias.
6. **Raspberry Pi (opcional)**: Si deseas integrar con Raspberry Pi para otras tareas.

## Conexiones

1. **Termistor NTC (NTC_PIN 26)**:
   - Conecta un extremo del termistor NTC al pin analógico **A0** (o cualquier pin de entrada analógica de tu Arduino).
   - El otro extremo debe conectarse a una **resistencia de referencia** y luego a **GND**.
2. **Pantalla LCD**:
   - Conecta los pines **RS**, **E**, **D4**, **D5**, **D6**, **D7** del LCD a los pines correspondientes de tu Arduino (**pines 12, 11, 10, 9, 8, 7**).

## Descripción del Proyecto

### Objetivo:
El proyecto mide la temperatura utilizando un **termistor NTC**, que cambia su resistencia a medida que cambia la temperatura. La resistencia se convierte en un valor de voltaje utilizando un divisor de voltaje. Este voltaje se convierte a temperatura usando la ecuación de Steinhart-Hart, y los resultados son mostrados en un **LCD 16x2**.

### Funcionamiento:
1. **Lectura analógica**: El Arduino lee el valor de voltaje en el pin analógico conectado al termistor.
2. **Cálculo de temperatura**: La resistencia del termistor es convertida a temperatura utilizando la fórmula de Steinhart-Hart. El valor de temperatura en Kelvin es ajustado a grados Celsius.
3. **Visualización**: El voltaje y la temperatura calculada se muestran en la pantalla LCD.

### Fórmulas:

- **Cálculo de voltaje**:
  \[
  \text{Voltaje} = \text{ntcValue} \times \left( \frac{3.3}{\text{RESOLUTION}} \right)
  \]

- **Cálculo de temperatura** (usando la ecuación de Steinhart-Hart):
  \[
  T = \frac{1}{\left( \frac{\log\left( \frac{1}{R} \right)}{\text{BETA}} + \frac{1}{298.15} \right)} - 273.15
  \]
  Donde:
  - \( \text{BETA} \) es una constante del termistor (usualmente proporcionada por el fabricante).
  - \( R \) es la resistencia del termistor calculada a partir del valor de lectura del ADC.

# Media Player

**Autor:** Daniel Ramírez Concepción

## Antes de empezar

**Debemos tener ciertos elementos antes de poder utilizar el reproductor.**

* QT Creator con almenos la versión 5.7
* Codecs para los formatos que queramos reproducir.
* Es posible que se necesite instalar la librería gŕafica dependiendo del SO.

## Instrucciones de uso

1. Realizar un clone del repositorio https://github.com/DzThor/soa-media-player
2. Abrir el proyecto *videoplayer.pro*.
3. Pulsar el botón *Build* o reaizar la combinación de teclas *Ctrl+B*.
4. Pulsar el botón *Run* o realizar la combinación de teclas *Ctrl+R*.
5. Disfrutar.

## Características del reproductor

- **Play / Pause**, para iniciar o pausar la reproducción de una película. Cuando no se está reproduciendo nada o se está viendo la webcam, al pulsar este control se abrirá un cuadro de diálogo para seleccionar el archivo de vídeo y después comenzar la reproducción. Si se estaba reproduciendo un archivo, esta se pondrá en pausa.

- **Webcam**, para iniciar la captura de la webcam.

- **Stop**, para detener la reproducción del archivo o la captura de la webcam.

- **Rewind**, para desplazar la película hacia atrás un 10%, o si se mantiene pulsado, un 3.33%.

- **Forward**, para desplazar la película hacia adelante un 10%, o si se mantiene pulsado, un 3.33%.

- **Mute**, para silenciar el vídeo.

- **FullScreen**, para poner el video en pantalla completa, funciona usando el click derecho, tanto para activarlo como para desactivarlo.

La interfaz del programa se reajusta al tamaño de la ventana.

## Opcional

 He añadido una serie de funcionalidades extra:

  * La posibilidad de pausar y reanudar el video pulsando en la pantalla con el click izquierdo.
  * Los botones de Rewind y Forward poseen dos funcionalidades distintas dependiendo del modo de uso. Si se hace click en ellos estos avanzan o retroceden el video en el 10% de su duración, mientras que si se mantienen pulsados hacen un efecto continuado que va haciendo avanzar o retroceder el video en un 3.3%.
  * Una vez que se activa la webcam el resto de botones y widgets que no se usan, son desactivados, pero aún puede ir al mení Inicio ->Iniciar Webcam para cargar la webcam, y quitar el video en reproducción.
  * El reproductor tiene un Slider que va sincronizado con el progreso del video y avanza automaticamente. En caso de moverlo, el video pasa al momento que le corresponde proporcional al lugar en que se deje el Slider. El Slider esta sincronizado con los botones Rewind y Forward.
  * En el menú de inicio, disponemos de una opción para cargar un vídeo, para activar la webcam o para cerrar el programa.
  * Modo FullScreen, al utilizar el click derecho, para activar la pantalla completa y para desactivarlo denuevo con el mismo.

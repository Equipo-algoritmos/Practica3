# Buscador de personas — Práctica 3

Proyecto académico de Algoritmos y Estructuras de Datos que implementa una **búsqueda indexada por letra**, seguida de una **búsqueda binaria** para localizar personas por su clave.

Incluye una versión de consola en C++ y una interfaz gráfica para Windows desarrollada con C++/CLI y Windows Forms.

## Funcionalidades

- Seleccionar un archivo `.txt` desde el diálogo de archivos de Windows.
- Cargar registros con clave, nombre y edad.
- Buscar una persona por su clave exacta.
- Mostrar las personas encontradas en una tabla con columnas de clave, nombre y edad.
- Realizar búsquedas con el botón **Buscar** o con la tecla **Enter**.
- Mostrar un aviso cuando no se encuentra la persona o aún no se ha seleccionado un archivo.

La tabla acumula los resultados de las búsquedas exitosas. Al seleccionar otro archivo, se limpia la tabla y se reemplaza el registro cargado.

## Cómo funciona la búsqueda

1. Se cargan las personas en un `vector<Persona>`, conservando el orden del archivo.
2. Se construye un índice con 27 posiciones: 26 para los inicios de los bloques de las letras `A` a `Z`, y una adicional con el total de registros.
3. La primera letra de la clave determina el bloque donde buscar.
4. Se aplica búsqueda binaria únicamente dentro de ese bloque.
5. Si se encuentra la clave, se recuperan los datos de la persona. Si no existe, la búsqueda devuelve `-1`.

Cuando una letra no tiene registros, su inicio y su límite final coinciden, representando un bloque vacío.

Para `n` registros, construir el índice requiere O(n). Una búsqueda dentro de un bloque de `b` registros requiere O(log b) comparaciones. El índice ocupa un espacio fijo de 27 enteros; el almacenamiento de las personas crece con la cantidad de registros.

## Formato del archivo

Un registro por línea, con campos separados por punto y coma y sin encabezado:

```text
clave;nombre;edad
```

Ejemplo de contenido válido:

```text
A00001;Alberto Castillo Diaz;18
A00003;Teresa Rojas Aguilar;55
A00005;Maria Ramirez Moreno;67
```

Condiciones de los datos:

- Claves únicas de seis caracteres: una letra mayúscula de `A` a `Z` y cinco dígitos.
- Registros ordenados ascendentemente por clave. El programa no los ordena automáticamente.
- Nombres sin acentos, sin `ñ` y sin punto y coma; se permiten espacios.
- Edad expresada como un número entero válido.
- Sin líneas vacías ni campos faltantes.

El archivo [personas.txt](personas.txt) incluye **300 000 personas ficticias** para practicar, con claves desde `A00001` hasta `Z35999`.

## Ejecutar la interfaz gráfica

### Requisitos

- Windows.
- Visual Studio 2026: el proyecto está configurado con el conjunto de herramientas **v145**.
- Herramientas de desarrollo de escritorio con C++, incluido el soporte **C++/CLI**.
- Herramientas de desarrollo y destino de **.NET Framework 4.7.2** y Windows SDK.

### Pasos

1. Abrir [BuscadorPersonasGUI.slnx](interfaz/BuscadorPersonasGUI/BuscadorPersonasGUI.slnx) en Visual Studio.
2. Seleccionar la configuración **Debug** y la plataforma **x64**.
3. Compilar y ejecutar con **F5**.
4. Pulsar **Seleccionar archivo** y elegir `personas.txt` en la carpeta raíz del repositorio.
5. Escribir una clave, por ejemplo `A00001`, y pulsar **Buscar** o **Enter**.

No es necesario copiar el archivo de datos junto al ejecutable: se selecciona desde la interfaz.

## Ejecutar la versión de consola

Con un compilador como GCC/MinGW, desde la carpeta raíz del repositorio:

```powershell
g++ -std=c++17 BusquedaIndexada.cpp -o BusquedaIndexada.exe
.\BusquedaIndexada.exe
```

Esta versión busca `personas.txt` en el directorio desde el que se ejecuta. Introducir `-1` termina el programa.

## Organización del código

| Archivo | Responsabilidad |
|---|---|
| `BusquedaIndexada.cpp` | Versión independiente de consola. |
| `interfaz/BuscadorPersonasGUI/Persona.h` y `Persona.cpp` | Representación de una persona y consulta de sus atributos. |
| `interfaz/BuscadorPersonasGUI/RegistroPersonas.h` y `RegistroPersonas.cpp` | Carga del archivo, almacenamiento, construcción del índice y búsqueda. |
| `interfaz/BuscadorPersonasGUI/VentanaPrincipal.h` | Formulario, controles y eventos de la interfaz. |
| `interfaz/BuscadorPersonasGUI/VentanaPrincipal.cpp` | Punto de entrada de la aplicación gráfica. |
| `personas.txt` | Datos ficticios de ejemplo. |
| `.gitignore` | Exclusión de archivos temporales y de compilación. |

## Casos de prueba sugeridos

Con el archivo de ejemplo:

| Clave | Resultado esperado |
|---|---|
| `A00001` | Alberto Castillo Diaz, 18 años. |
| `A00003` | Teresa Rojas Aguilar, 55 años. |
| `Z35999` | Última persona del archivo. |
| `A00002` | Persona no encontrada. |

## Alcance actual

El proyecto trabaja con archivos controlados que cumplen el formato anterior. La carga todavía no valida exhaustivamente los registros ni maneja todos los errores de conversión; un archivo mal formado puede interrumpir la ejecución. La carga se realiza en el hilo de la interfaz, por lo que la ventana puede dejar de responder brevemente mientras se lee un archivo grande.

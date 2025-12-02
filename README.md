# 📄 get_next_line (42 Project)

Implementación de la función `get_next_line`, capaz de leer un archivo **línea a línea** de forma eficiente, preservando el estado entre llamadas.  
Este proyecto incluye **funcionalidad obligatoria y bonus**.

---

## 🚀 Descripción

`get_next_line` devuelve **una línea completa por cada llamada**, leyendo de un descriptor de archivo mediante un buffer dinámico.  
Gestiona correctamente:
- Archivos grandes  
- Lecturas parciales  
- Múltiples llamadas consecutivas  
- Manejadores múltiples de forma simultánea (**bonus**)  

Además, cumple con las restricciones de Norminette y la filosofía de 42.

---

## 🧠 Características

### ✔️ Parte obligatoria
- Lectura eficiente mediante `read()`
- Acumulación de texto pendiente entre llamadas
- Manejo correcto de saltos de línea
- Gestión de memoria sin fugas
- Compatible con cualquier tamaño de archivo

### ⭐ Bonus
- Manejo de **múltiples file descriptors a la vez**
- Implementado utilizando estructuras separadas por FD

---

## 📁 Archivos del proyecto

```
get_next_line.c  
get_next_line.h  
get_next_line_utils.c  
get_next_line_bonus.c  
get_next_line_bonus.h  
get_next_line_utils_bonus.c  
```

---

## 🧩 Funciones implementadas

### Obligatorias
```c
char    *get_next_line(int fd);
```

### Bonus
```c
char    *get_next_line(int fd);     // versión compatible con varios FD
```

### Utils
- Funciones propias de manejo de strings y memoria  
- Implementación sin usar funciones prohibidas

---

## 🔧 Uso

Incluye el header en tu programa:

```c
#include "get_next_line.h"
```

Llama a la función:

```c
char *line;

while ((line = get_next_line(fd)) != NULL)
{
    printf("%s", line);
    free(line);
}
```

---

## 💻 Compilación

### Obligatorio
```bash
cc -Wall -Wextra -Werror get_next_line.c get_next_line_utils.c main.c
```

### Bonus
```bash
cc -Wall -Wextra -Werror \
    get_next_line_bonus.c get_next_line_utils_bonus.c main.c
```

---

## 📝 Ejemplo de uso

```c
int fd = open("archivo.txt", O_RDONLY);
char *line;

while ((line = get_next_line(fd)))
{
    printf("%s", line);
    free(line);
}
close(fd);
```

---

## 👩‍💻 Autor

**maria-bada**  
[GitHub](https://github.com/maria-bada)

---

## 📚 Notas

- `BUFFER_SIZE` puede modificarse en la compilación:  
  ```bash
  cc -D BUFFER_SIZE=42 ...
  ```
- Compatible con Linux y macOS.

---


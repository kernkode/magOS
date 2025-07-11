### IDE y Herramientas
---
- **IDE Principal**: Visual Studio 2022
- **Sistema de Construcción**: xmake
    - [xmake.io](https://xmake.io/)

### Compilador y Arquitectura
---
- **Compilador**: MSVC 2022 (v143)

## Comandos de Compilación
---

```bash
# Configurar proyecto para debug x64
xmake config --mode=debug --arch=x64 --plat=windows --toolchain=msvc

# Generar archivos de proyecto para Visual Studio (Opcional)
xmake project -k vsxmake2022
```

### Compilación
---

```bash
# Compilar proyecto
xmake build
```

## Estructura de Proyecto
---

```
magOS/
├── bin/                # Archivos generados & list.csv
├── src/                # Código fuente
```

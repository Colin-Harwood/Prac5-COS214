# Prac5-COS214
# Practical 5 for COS214

## Building Campus Guard
Campus guard is an emergency-response coordination platform for universities.

## Team Members:
  - Gary Mull
  - Kadin Raju
  - Colin Harwood


## Build & Run with Docker Compose

### Build the app

```bash
docker compose run --rm campusguard
```

### Clean rebuild

```bash
docker compose down --rmi local
docker compose build --no-cache
docker compose run --rm campusguard
```

### Run with Valgrind

```bash
docker compose --profile debug run --rm valgrind
```

### Run with GDB

```bash
docker compose run --rm --entrypoint gdb campusguard ./campusguard
```

### Stop / clean up

```bash
docker compose down                         
docker compose down --rmi local             
docker compose down --rmi local --volumes    
```

### Build locally (no Docker)

```bash
make          
make run      
make valgrind
make gdb
```
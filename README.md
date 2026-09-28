# Prac5-COS214
# Practical 5 for COS214

## Building Campus Guard
Campus guard is an emergency-response coordination platform for universities.

## Team Members:
  - Gary Mull
  - Kadin Raju
  - Colin Harwood


## Build & Run with Docker Compose

### Quick start

```bash
docker compose up --build
```

### Clean rebuild

```bash
docker compose down --rmi local
docker compose up --build
```

### Run with Valgrind

```bash
docker compose --profile debug up --build
```

### Run with GDB

```bash
docker compose run --rm --entrypoint gdb campusguard ./campusguard
```

Then inside GDB:

```gdb
run
bt
info locals
```

### Build locally (no Docker)

```bash
make          # produces build/campusguard
make run      # runs it
make valgrind # runs it under valgrind
make gdb
```
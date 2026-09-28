FROM gcc:13 AS builder

WORKDIR /app

COPY Makefile ./

COPY *.cpp *.h ./

RUN make

FROM debian:bookworm-slim

RUN apt-get update && \
    apt-get install -y --no-install-recommends \
        libstdc++6 \
        valgrind \
        gdb \
    && rm -rf /var/lib/apt/lists/*

WORKDIR /app

COPY --from=builder /app/build/campusguard ./campusguard

ENTRYPOINT ["./campusguard"]
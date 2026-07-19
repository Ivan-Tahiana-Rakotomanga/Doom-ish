FROM ubuntu:22.04

ENV DEBIAN_FRONTEND=noninteractive

RUN apt-get update && apt-get install -y --no-install-recommends \
    build-essential \
    ca-certificates \
    libbsd-dev \
    libx11-dev \
    libxext-dev \
 && rm -rf /var/lib/apt/lists/*

WORKDIR /app

COPY . /app

RUN make -C libft \
 && make -C minilibx-linux CFLAGS='-O3 -std=gnu11 -I/usr/include' \
 && make CFLAGS='-Wall -Wextra -Werror -std=gnu11'

CMD ["./doomISH", "files/garden.cub"]

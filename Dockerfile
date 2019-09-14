FROM archlinux/base

RUN pacman -Syu base-devel git --noconfirm

# Esto debería crear el usuario docker y añadirlo al grupo sudo
RUN useradd -m docker

# sudo para docker sin password
RUN echo "docker ALL=(ALL) NOPASSWD: ALL" >> /etc/sudoers

USER docker

RUN mkdir /home/docker/build

#ADD PKGBUILD /home/docker/build

WORKDIR /home/docker/build

ENTRYPOINT [ "/bin/bash" ]

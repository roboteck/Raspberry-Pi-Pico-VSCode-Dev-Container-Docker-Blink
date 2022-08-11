# [Choice] Debian / Ubuntu version: debian-10, debian-9, ubuntu-20.04, ubuntu-18.04
ARG VARIANT="ubuntu-20.04"
FROM mcr.microsoft.com/vscode/devcontainers/cpp:0-${VARIANT}

RUN apt-get update && export DEBIAN_FRONTEND=noninteractive \
    && apt-get -y install --no-install-recommends cmake build-essential wget ca-certificates \
    gdb-multiarch automake autoconf libtool libftdi-dev libusb-1.0-0-dev pkg-config clang-format

WORKDIR /apps

RUN wget https://developer.arm.com/-/media/Files/downloads/gnu/11.3.rel1/binrel/arm-gnu-toolchain-11.3.rel1-x86_64-arm-none-eabi.tar.xz && \
    tar xvf arm-gnu-toolchain-11.3.rel1-x86_64-arm-none-eabi.tar.xz

RUN mv arm-gnu-toolchain-11.3.rel1-x86_64-arm-none-eabi gcc-arm-none && \
    rm arm-gnu-toolchain-11.3.rel1-x86_64-arm-none-eabi.tar.xz

ENV PATH=$PATH:/apps/gcc-arm-none/bin
RUN git clone -b master https://github.com/raspberrypi/pico-sdk.git --depth=1 && cd pico-sdk && git submodule update --init 
ENV PICO_SDK_PATH=/apps/pico-sdk
# RUN git clone https://github.com/raspberrypi/openocd.git -b picoprobe --depth=1 \
#     && cd openocd && ./bootstrap && ./configure --enable-ftdi --enable-sysfsgpio --enable-picoprobe && make -j 8 install \
#     && cd /apps && git clone https://github.com/raspberrypi/picotool.git --depth=1 \
#     && cd picotool && mkdir build && cd build && cmake ../ && make -j 8 && cp picotool /usr/local/bin \
RUN cd /apps && git clone https://github.com/wtarreau/bootterm.git --depth=1 \
    && cd bootterm && make -j 8 install 

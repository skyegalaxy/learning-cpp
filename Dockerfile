FROM ubuntu:24.04
LABEL Description="C++ build environment for the class"

ENV HOME /root

SHELL ["/bin/bash", "-c"]

RUN apt update && apt -y --no-install-recommends install \
    build-essential \
    clang \
    cmake \
    gdb \
    wget \
    tree


# learning-cpp
This repo contains everything needed to build the learning-cpp docker container and code examples for C++ coursework.

# Setup

Install docker: https://docs.docker.com/engine/install/ 

Optional - Configure docker to run without sudo (needed for the convenience scripts): https://docs.docker.com/engine/install/linux-postinstall/

# Building and launching the container

Unless you want to add new system dependencies, you should only need to build the container on your host machine once. 

If you're on linux, you can use the included convenience scripts. \
From the root of this repo:

```bash

docker/build

```

All code in this course will be built and run inside the container. To build code examples, you will need to build and run the container. 

To launch the container entrypoint:

```bash

docker/run

```

# Building and running the hello-world example

From inside the container:

```bash

cd code-examples/W1-intro/
mkdir build && cmake -B build && cmake --build build
./build/hello-world

```

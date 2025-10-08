FROM ubuntu:16.04
COPY . /usr/src/DockerTest
WORKDIR /usr/src/DockerTest
RUN apt update
RUN apt install -y g++ nano
RUN g++ -o Test Test.cpp
CMD ["./Test"]
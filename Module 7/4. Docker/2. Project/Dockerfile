FROM ubuntu:16.04
COPY . /usr/src/DockerTest
WORKDIR /usr/src/DockerTest
RUN apt update
RUN apt install -y g++ clang nano
RUN g++ -o Test_gcc main.cpp
RUN clang++ main.cpp -o Test_clang
CMD ["./Test_gcc", "./Test_clang"]
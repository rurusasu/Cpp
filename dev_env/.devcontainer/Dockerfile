FROM ubuntu:22.04

# Install required packagers
RUN apt-get update -y && \
    apt-get upgrade -y && \
    apt-get install -y --no-install-recommends \
        build-essential

WORKDIR /work
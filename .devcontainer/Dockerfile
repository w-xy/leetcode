# See here for image contents: https://github.com/microsoft/vscode-dev-containers/tree/v0.158.0/containers/cpp/.devcontainer/base.Dockerfile

# [Choice] Debian / Ubuntu version: debian-10, debian-9, ubuntu-20.04, ubuntu-18.04
ARG VARIANT="buster"
FROM mcr.microsoft.com/vscode/devcontainers/cpp:0-${VARIANT}

# [Optional] Uncomment this section to install additional packages.
RUN apt-get update && export DEBIAN_FRONTEND=noninteractive \
    && apt-get -y install --no-install-recommends nodejs

# ARG KEY
# ARG PUB_KEY

# RUN apk add --no-cache openssh-client git
# RUN mkdir -p -m 0600 ~/.ssh && ssh-keyscan github.com >> ~/.ssh/known_hosts

# RUN mkdir /home/vscode/.ssh/
# RUN chmod 700 /home/vscode/.ssh/
# RUN ssh-keyscan github.com >> /home/vscode/.ssh/known_hosts
# ADD $KEY /home/vscode/.ssh/id_rsa
# ADD $PUB_KEY /home/vscode/.ssh/id_rsa.pub
# COPY /home/linuxer/.ssh/id_rsa /home/vscode/.ssh/id_rsa
# COPY /home/linuxer/.ssh/id_rsa.pub /home/vscode/.ssh/id_rsa.pub
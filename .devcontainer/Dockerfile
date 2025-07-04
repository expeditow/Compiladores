# .devcontainer/Dockerfile
# Usa a imagem oficial do Debian como base
FROM debian:stable-slim

# Define o diretório de trabalho principal dentro do container.
# Sua pasta raiz do projeto local (a pasta que você abriu no VS Code, ex: "meu_compilador_rj")
# será montada dentro deste WORKDIR no container.
WORKDIR /workspaces/compilador 

# Atualiza a lista de pacotes e instala as ferramentas necessárias:
# git: para versionamento de código
# flex: para gerar o analisador léxico
# bison: para gerar o analisador sintático (GNU Yacc)
# make: para automatizar a compilação (usando seu Makefile)
# g++: o compilador C++ para seu código intermediário
# ca-certificates: para resolver problemas de verificação de certificado SSL (como o do Git)
# libfl-dev: a biblioteca de desenvolvimento do Flex, necessária para linkar o executável
RUN apt-get update && \
    apt-get install -y \
    git \
    flex \
    bison \
    make \
    g++ \
    ca-certificates \
    libfl-dev \
    --no-install-recommends && \
    rm -rf /var/lib/apt/lists/*

# Comando padrão para quando o container for executado, pode ser um shell ou nada.
# "bash" é útil para entrar no terminal do container automaticamente.
CMD ["bash"]
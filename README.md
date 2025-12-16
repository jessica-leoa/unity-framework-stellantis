# unity-framework-stellantis

## Passo a passo:

### 1° - Baixar a extensão C no VScode
    - C/C++
    - C/C++ Extension Pack
### 2° - Installar um compilador C (GCC)
    https://gcc.gnu.org/install/download.html
### 3° - checar se o GCC instalou 
    gcc --version
### 4° - Checar se o compilador está instalado e rodando corretamente seguindo os seguintes passos:
    - Criar um arquivo 'teste.c':

        #include <stdio.h>
        int main() {
            printf("GCC funcionando!\n");
            return 0;
        }

    - Compile o código usando este comando:
        gcc teste.c -o teste.exe

    - Execute usando este comando:
        ./teste.exe

### 5° - Caso não rode, checar as VARIÁVEIS DE AMBIENTE, adicionando o caminho do arquivo baixado no PATH

## CONFIGURANDO AMBIENTE UNITY
### 6° - Entrar no repositório oficial: https://github.com/ThrowTheSwitch/Unity
    - unity.c -> A lógica do framework
    - unity.h -> As definições/cabeçalhos
    - unity_internals.h -> Coisas internas que o unity.h precisa

### 7° - Escrever uma funcionalidade e em seguida seus testes
    - Clona este repositório: https://github.com/jessica-leoa/unity-framework-stellantis.git 
### 8° - Roda comando para compilar o codigo e gerar o executável
    - gcc test_controle.c unity.c -o teste_sistema
### 9° - E depois rode:
    Windows: teste_sistema.exe
    Linux/Mac: ./teste_sistema
### Alternativa de terminal colorido: 
    gcc -D UNITY_OUTPUT_COLOR test_controle.c unity.c -o teste_sistema

### Desfecho:
Neste tutorial, abordamos 5 ferramentas principais do Unity:
    Igualdade simples
    Igualdade com mensagem de erro
    Ignorar testes pendentes
    Validação de faixas para sensores
    Comparação de Arrays para dados complexos

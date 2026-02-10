# Compilador C-Like (Gerador de Código Intermediário)

Este projeto consiste em um compilador robusto que traduz uma linguagem de alto nível com sintaxe customizada para código C funcional. O sistema realiza as etapas de análise léxica, sintática e semântica, integrando um gerador de código que lida com gerenciamento dinâmico de memória e controle de fluxo complexo.



## Funcionalidades Técnicas

### 1. Sistema de Tipagem e Semântica
* **Inferência de Tipos:** O compilador realiza a promoção automática de tipos (ex: `int` para `float`) em operações aritméticas mistas para garantir a precisão.
* **Casting Explícito:** Suporte à conversão manual de tipos via sintaxe `(tipo) valor`.
* **Validação de Funções:** Verificação rigorosa da assinatura de funções, validando se a quantidade e os tipos de argumentos em uma chamada correspondem exatamente à declaração.
* **Operadores de Incremento/Decremento:** Implementação fiel do comportamento de pré e pós-fixados (incremento e decremento), utilizando variáveis temporárias para garantir a ordem correta de avaliação e retorno.

### 2. Gestão de Memória e Strings
Diferente de implementações simplificadas, este projeto trata strings com alocação dinâmica:
* **Alocação Automática:** Uso de `malloc` para inicialização de strings e armazenamento de resultados de concatenação.
* **Prevenção de Memory Leaks:** Implementa um rastreador de variáveis alocadas que insere chamadas `free()` automaticamente ao final do escopo `main` ou antes de reatribuições de ponteiros.
* **Operações Nativas:** Implementação de concatenação via operador `+` e inclusão automática de funções auxiliares internas como `meu_strlen`.

### 3. Estruturas de Dados e Fluxo de Controle
* **Matrizes e Vetores (1D e 2D):** Suporte a arrays multidimensionais com cálculo de endereçamento linear para mapeamento em memória C:
  $$indice\_final = (i \times total\_colunas) + j$$
* **Controle de Laços:** Uso de pilhas de rótulos para gerenciar corretamente os comandos `break` e `continue` em contextos de laços aninhados (`while`, `do-while`, `for`).
* **Potenciação:** Operador `**` com associatividade à direita e integração com uma função `potencia_helper` gerada no código de saída.



## Estrutura do Projeto

* **`parser.y`**: Gramática Bison contendo as regras de tradução, definições de precedência e ações semânticas em C++.
* **`y.tab.h`**: Cabeçalho gerado pelo Bison com as definições de tokens (kinds) e constantes para integração com o analisador léxico.
* **Tabela de Símbolos**: Implementada através de uma pilha de mapas (`std::map`), permitindo suporte a múltiplos escopos e *variable shadowing*.

## Como Compilar e Executar

1. **Gerar os componentes do compilador (Flex e Bison):**
   ```bash
   flex scanner.l
   bison -d parser.y

## Compilar o binário final utilizando G++:

### Bash

g++ lex.yy.c parser.tab.c -o compilador
Executar a tradução de um arquivo fonte:

### Bash

./compilador < programa_fonte.txt

#### Exemplo de Tradução
Código de Entrada (Linguagem Customizada):

### Na linguagem "Cria"
```
nmr x = 2 ** 3

se (x > 5) {

  print("Valor alto")

}
```

### Código C Intermediário Gerado:
```
T1 = 2;
T2 = 3;
T3 =  T1*T2;
x = T3;
T4 = x > 5;
if (!T4) goto L0;
printf("Valor alto\n");
L0:
```

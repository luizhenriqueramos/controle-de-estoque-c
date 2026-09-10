<div align="center">

# 📦 Controle de Estoque em C

<img src="https://img.shields.io/badge/C-Programming-00599C?style=for-the-badge&logo=c&logoColor=white" />
<img src="https://img.shields.io/badge/Projeto-Pr%C3%A1tico-2563EB?style=for-the-badge" />
<img src="https://img.shields.io/badge/IDE-Dev--C%2B%2B-A81D33?style=for-the-badge" />

Projeto simples de controle de estoque desenvolvido para praticar fundamentos de programação em **C**.

</div>

---

## 📋 Funcionalidades

- Cadastro de produtos
- Listagem de produtos
- Busca por código
- Entrada de estoque
- Saída de estoque
- Validação de estoque disponível
- Cálculo do valor total do estoque

## 🧠 Conceitos praticados

- `struct`
- Vetores
- Funções
- Laços de repetição
- Estruturas condicionais
- `switch`
- Busca em vetor
- Manipulação de dados em memória
- Organização do código em funções

## 🧱 Estrutura do produto

Cada produto possui:

```c
typedef struct
{
    int codigo;
    char nome[50];
    int quantidade;
    float preco;
} Produto;
```

O programa mantém até **100 produtos** em memória durante a execução.

## ▶️ Como executar

O projeto foi desenvolvido utilizando **Dev-C++**.

Também pode ser compilado com um compilador C compatível com C99 ou superior:

```bash
gcc main.c -o estoque
```

Depois:

```bash
./estoque
```

No Windows:

```bash
estoque.exe
```

## 📚 Contexto

Projeto desenvolvido durante meus estudos de **Análise e Desenvolvimento de Sistemas**, com o objetivo de aplicar conceitos básicos de C em um problema prático.

> Este é um projeto de aprendizado e será aprimorado conforme avanço nos estudos.

---

<div align="center">

**Luiz Henrique Ramos de Souza**

</div>

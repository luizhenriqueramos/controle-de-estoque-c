#include <stdio.h>
#include <locale.h>

#define MAX_PRODUTOS 100

typedef struct 
{
    int codigo;
    char nome[50];
    int quantidade;
    float preco;
} Produto;

Produto produtos[MAX_PRODUTOS];
int totalProdutos = 0;

void exibirMenu();
void cadastrarProduto();
void listarProdutos();
void buscarProduto();
void entradaEstoque();
void saidaEstoque();
float calcularValorTotal();


int main()
{
    setlocale(LC_ALL, "Portuguese");
    int opcao;

    do
    {
        exibirMenu();

        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
            case 1:
                cadastrarProduto();
                break;

            case 2:
                listarProdutos();
                break;

            case 3:
                buscarProduto();
                break;

            case 4:
                entradaEstoque();
                break;

            case 5:
                saidaEstoque();
                break;

            case 6:
                printf("Valor total do estoque: R$ %.2f\n", calcularValorTotal());
                break;

            case 0:
                printf("Encerrando o programa...\n");
                break;

            default:
                printf("Opção inválida.\n");
        }

    } while (opcao != 0);

    return 0;
}


void exibirMenu()
{
    printf("\n=== CONTROLE DE ESTOQUE ===\n");
    printf("1 - Cadastrar produto\n");
    printf("2 - Listar produtos\n");
    printf("3 - Buscar produto\n");
    printf("4 - Entrada de estoque\n");
    printf("5 - Saida de estoque\n");
    printf("6 - Valor total do estoque\n");
    printf("0 - Sair\n\n");
}


void cadastrarProduto()
{
    if (totalProdutos >= MAX_PRODUTOS)
    {
        printf("Estoque cheio! Não é possível cadastrar mais produtos.\n");
        return;
    }

    Produto novo;

    printf("Código: ");
    scanf("%d", &novo.codigo);

    printf("Nome: ");
    scanf(" %49[^\n]", novo.nome);

    printf("Quantidade: ");
    scanf("%d", &novo.quantidade);

    printf("Preço: ");
    scanf("%f", &novo.preco);

    produtos[totalProdutos] = novo;
    totalProdutos++;

    printf("Produto cadastrado com sucesso!\n");
}


void listarProdutos()
{
    if (totalProdutos == 0)
    {
        printf("Nenhum produto cadastrado.\n");
        return;
    }

    printf("\n%-8s %-20s %-12s %-10s\n", "Código", "Nome", "Qtd", "Preço");
    for (int i = 0; i < totalProdutos; i++)
    {
        printf("%-8d %-20s %-12d R$ %f\n",
               produtos[i].codigo, produtos[i].nome,
               produtos[i].quantidade, produtos[i].preco);
    }
}


void buscarProduto()
{
    int codigo;
    printf("Digite o código do produto: ");
    scanf("%d", &codigo);

    for (int i = 0; i < totalProdutos; i++)
    {
        if (produtos[i].codigo == codigo)
        {
            printf("\nEncontrado: %s | Qtd: %d | Preço: R$ %f\n",
                   produtos[i].nome, produtos[i].quantidade, produtos[i].preco);
            return;
        }
    }
    printf("Produto não encontrado.\n");
}


void entradaEstoque()
{
    int codigo, quantidade;
    printf("Código do produto: ");
    scanf("%d", &codigo);

    for (int i = 0; i < totalProdutos; i++)
    {
        if (produtos[i].codigo == codigo)
        {
            printf("Quantidade a adicionar: ");
            scanf("%d", &quantidade);
            produtos[i].quantidade += quantidade;
            printf("Nova quantidade: %d\n", produtos[i].quantidade);
            return;
        }
    }
    printf("Produto não encontrado.\n");
}


void saidaEstoque()
{
    int codigo, quantidade;
    printf("Código do produto: ");
    scanf("%d", &codigo);

    for (int i = 0; i < totalProdutos; i++)
    {
        if (produtos[i].codigo == codigo)
        {
            printf("Quantidade a retirar: ");
            scanf("%d", &quantidade);

            if (quantidade > produtos[i].quantidade)
            {
                printf("Estoque insuficiente! Disponível: %d\n", produtos[i].quantidade);
                return;
            }

            produtos[i].quantidade -= quantidade;
            printf("Nova quantidade: %d\n", produtos[i].quantidade);
            return;
        }
    }
    printf("Produto não encontrado.\n");
}


float calcularValorTotal()
{
    float total = 0;
    for (int i = 0; i < totalProdutos; i++)
        total += produtos[i].quantidade * produtos[i].preco;
    return total;
}

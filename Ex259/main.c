#include <stdio.h>
#include <stdlib.h>
#define hashKey int //Chave hash
#define amountHashKeys int //Quantidade de chaves que serão tratadas pela tabela hash
#define hashSize (2 * amountHashKeys) //Bom tamanho definido para tabela hash, onde pegamos o valor primo mais próximo
#define hashFunction(key) (key % hashSize) //Função espalhamento/hash
#define factor (amountHashKeys / hashSize) //Diz respeito a porcentagem de preenchimento da tabela hash, quaõ mais próximo de 1/2 melhor
#define maxColisions int //É importante definir o máximo de colisões de inserção e busca na tabela hash

/*Exercício 259: Tabela Hash

Uma tabela hash tem a mesma funcionalidade das estruturas de dados
convencionais, armazenar dados, entretanto a principal finalidade
de uma tabela hash é proporcionar uma busca de forma eficiente.

Os conjunto de dados analisados por uma tabela hash tendem a não sofrer
muitas alterações (inserções remoções) pois é necessário definir um tamanho
para a table hash que é "complicado" de se obter.

As chave hashs são únicas, ou seja, não pode haver chaves hashs repetidas,
exceto para tabelas hash implementadas com listas encadeadas.

CONCEITOS IMPORTANTES:

CHAVE HASH-> Possui o indentificador a ser tratado pela tabela hash.

FUNCAO HASH/ESPALHAMENTO ->  Critério de organização das chaves na tabela hash,
gera também o índice de acesso de uma chave na tabela.

TABELA HASH -> Array que armazena as chaves dispostas de acorco com o critério
da função hash, pode ser dos tipos: ENDEREÇAMENTO ABERTO/LINEAR, DOUBLE HASHING
ou ARRARY DE LISTAS ENCADEADAS

TAMANHO DA TABELA HASH -> Quantidade máxima de elementos na tabela, dada pela
formula 2*quantidadeElementos, aproximando-se do número primo mais próximo.

FATOR DE CARGA -> Definido pela quantidadeChaves/tamanhoTabela, define a
porcentagem de preenchimento da tabela, é um valor entre 0 e 1, sendo que
quanto mais proximo de 0.5, mais eficiente será a tabela, conceito importante
principalmente para implementação utilizando ENDEREÇAMENTO ABERTO.

COLISOES -> Ocorre quando há mais de um resultado apos a aplicacao da funcao hash.

TRATAMENTO DE COLISOES

ENDEREÇAMENTO ABERTO/LINEAR-> A chave será guardada na próxima posição vazia
do array, importante a utilização de um número máximo de colisões.

DOUBLE HASHING->

TABELA HASH COM ARRAY DE LISTA ENCADEADA -> As posições do array apontam
para as chaves, sendo que cada chave, se houver colisão em dada posição, apontará
para outra chave.

*/

//TABELA HASH SOMENTE COM ARRAY ESTÁTICO


int main()
{
    printf(":)\n");
    return 0;
}
